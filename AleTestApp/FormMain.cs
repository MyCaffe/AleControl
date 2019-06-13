using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using AleControlLib;

namespace AleTestApp
{
    public partial class FormMain : Form
    {
        Task m_taskProcess = null;
        COLORTYPE m_ct = COLORTYPE.CT_COLOR;
        AutoResetEvent m_evtAbort = new AutoResetEvent(false);
        AutoResetEvent m_evtDone = new AutoResetEvent(false);
        ACTION m_action = ACTION.ACT_PLAYER_A_NOOP;
        bool m_bShowDisplay = false;
        bool m_bTerminateOnRallyEnd = false;
        bool m_bAllowNegativeRewards = false;
        string m_strError = null;

        delegate void fnUpdate(COLORTYPE ct, byte[] rg, int nWid, int nHt, float fTotalReward);

        public FormMain()
        {
            InitializeComponent();
        }

        private void FormMain_Load(object sender, EventArgs e)
        {
            edtGameRomPath.Text = Properties.Settings.Default.RomPath;
        }

        private void FormMain_FormClosing(object sender, FormClosingEventArgs e)
        {
            m_evtAbort.Set();

            if (m_taskProcess != null)
            {
                while (!m_evtDone.WaitOne(0))
                {
                    Application.DoEvents();
                }
            }

            if (edtGameRomPath.Text.Length > 0)
                Properties.Settings.Default.RomPath = edtGameRomPath.Text;

            Properties.Settings.Default.Save();
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            btnStart.Enabled = false;
            m_bShowDisplay = chkShowDisplay.Checked;
            m_bTerminateOnRallyEnd = chkTerminateOnRallyEnd.Checked;
            m_bAllowNegativeRewards = chkAllowNegativeRewards.Checked;
            m_strError = "";
            m_taskProcess = Task.Factory.StartNew(new Action<object>(process), edtGameRomPath.Text);
        }

        private void process(object arg)
        {
            string strRom = (string)arg;
            IALE ale = new ALE();

            try
            {
                ale.Initialize();
                ale.EnableDisplayScreen = m_bShowDisplay;
                ale.EnableSound = m_bShowDisplay;
                ale.EnableColorData = true;
                ale.EnableRestrictedActionSet = true;
                ale.EnableColorAveraging = true;
                ale.EnableTerminateOnRallyEnd = m_bTerminateOnRallyEnd;
                ale.AllowNegativeRewards = m_bAllowNegativeRewards;
                ale.RandomSeed = 123;
                ale.RepeatActionProbability = 0.25f;
                ale.Load(strRom);
                ACTION[] rgActions = ale.ActionSpace;
                Random rand = new Random();
                int nEpisode = 0;
                float fWid;
                float fHt;
                float fTotalReward = 0;

                ale.GetScreenDimensions(out fWid, out fHt);

                while (nEpisode < 10 && !m_evtAbort.WaitOne(0))
                {
                    if (m_action == ACTION.ACT_RESET)
                    {
                        ale.ResetGame();
                        fTotalReward = 0;
                    }
                    else
                    {
                        ACTION action = ACTION.ACT_PLAYER_A_NOOP;

                        if (rgActions.Contains(m_action))
                            action = m_action;

                        float fReward = ale.Act(action);
                        fTotalReward += fReward;

                        byte[] rgScreen = ale.GetScreenData(m_ct);

                        Invoke(new fnUpdate(update), m_ct, rgScreen, (int)fWid, (int)fHt, fTotalReward);

                        if (ale.GameOver)
                        {
                            ale.ResetGame();
                            nEpisode++;
                            fTotalReward = 0;
                        }
                    }
                }
            }
            catch (Exception excpt)
            {
                m_strError = "ERROR: " + excpt.Message;
            }

            ale.Shutdown();
            m_evtDone.Set();
        }

        private void update(COLORTYPE ct, byte[] rg, int nWid, int nHt, float fTotalReward)
        {
            Bitmap bmp = new Bitmap(nWid, nHt);

            for (int y = 0; y < nHt; y++)
            {
                for (int x = 0; x < nWid; x++)
                {
                    int nIdx = (y * nWid) + x;
                    int nR = rg[nIdx];
                    int nG = nR;
                    int nB = nR;

                    if (ct == COLORTYPE.CT_COLOR)
                    {
                        nG = rg[nIdx + (nWid * nHt * 1)];
                        nB = rg[nIdx + (nWid * nHt * 2)];
                    }

                    Color clr = Color.FromArgb(nR, nG, nB);
                    bmp.SetPixel(x, y, clr);
                }
            }

            pbGame.Image = bmp;
            tsReward.Text = "Total reward = " + fTotalReward.ToString("N2");
        }

        private void timerUI_Tick(object sender, EventArgs e)
        {
            bool bRomExists = File.Exists(edtGameRomPath.Text);

            if ((m_taskProcess == null || m_taskProcess.IsCompleted) && bRomExists)
                btnStart.Enabled = true;
            else
                btnStart.Enabled = false;

            bool bRunning = false;

            if (m_taskProcess != null && !m_taskProcess.IsCompleted)
                bRunning = true;

            btnQuit.Enabled = bRunning;
            btnReset.Enabled = bRunning;
            btnLeft.Enabled = bRunning;
            btnRight.Enabled = bRunning;
            btnUp.Enabled = bRunning;
            btnDown.Enabled = bRunning;
            btnFire.Enabled = bRunning;
            grpControls.Enabled = bRunning;
            chkShowDisplay.Enabled = !bRunning;
            chkTerminateOnRallyEnd.Enabled = !bRunning;
            chkAllowNegativeRewards.Enabled = !bRunning;
            radColor.Enabled = !bRunning;
            radGray.Enabled = !bRunning;

            tsStatus.Text = m_strError;
        }

        private void btnBrowseRom_Click(object sender, EventArgs e)
        {
            openFileDialogRom.FileName = edtGameRomPath.Text;

            if (openFileDialogRom.ShowDialog() == DialogResult.OK)
                edtGameRomPath.Text = openFileDialogRom.FileName;
        }

        private void radColor_CheckedChanged(object sender, EventArgs e)
        {
            m_ct = COLORTYPE.CT_COLOR;
        }

        private void radGray_CheckedChanged(object sender, EventArgs e)
        {
            m_ct = COLORTYPE.CT_GRAYSCALE;
        }

        private void btnQuit_Click(object sender, EventArgs e)
        {
            m_evtAbort.Set();
        }

        private void btnAction_Click(object sender, EventArgs e)
        {
            if (sender == btnReset)
                m_action = ACTION.ACT_RESET;
            else if (sender == btnLeft)
                m_action = ACTION.ACT_PLAYER_A_LEFT;
            else if (sender == btnRight)
                m_action = ACTION.ACT_PLAYER_A_RIGHT;
            else if (sender == btnUp)
                m_action = ACTION.ACT_PLAYER_A_UP;
            else if (sender == btnDown)
                m_action = ACTION.ACT_PLAYER_A_DOWN;
            else if (sender == btnFire)
                m_action = ACTION.ACT_PLAYER_A_FIRE;
            else
                m_action = ACTION.ACT_PLAYER_A_NOOP;
        }

        private void chkShowDisplay_CheckedChanged(object sender, EventArgs e)
        {

        }
    }
}

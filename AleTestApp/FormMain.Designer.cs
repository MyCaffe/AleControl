namespace AleTestApp
{
    partial class FormMain
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.lblGameRom = new System.Windows.Forms.Label();
            this.edtGameRomPath = new System.Windows.Forms.TextBox();
            this.btnBrowseRom = new System.Windows.Forms.Button();
            this.openFileDialogExe = new System.Windows.Forms.OpenFileDialog();
            this.openFileDialogRom = new System.Windows.Forms.OpenFileDialog();
            this.btnStart = new System.Windows.Forms.Button();
            this.btnUp = new System.Windows.Forms.Button();
            this.btnLeft = new System.Windows.Forms.Button();
            this.btnDown = new System.Windows.Forms.Button();
            this.btnRight = new System.Windows.Forms.Button();
            this.btnReset = new System.Windows.Forms.Button();
            this.grpControls = new System.Windows.Forms.GroupBox();
            this.btnFire = new System.Windows.Forms.Button();
            this.timerUI = new System.Windows.Forms.Timer(this.components);
            this.pbGame = new System.Windows.Forms.PictureBox();
            this.radColor = new System.Windows.Forms.RadioButton();
            this.radGray = new System.Windows.Forms.RadioButton();
            this.btnQuit = new System.Windows.Forms.Button();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.tsReward = new System.Windows.Forms.ToolStripStatusLabel();
            this.chkShowDisplay = new System.Windows.Forms.CheckBox();
            this.chkTerminateOnRallyEnd = new System.Windows.Forms.CheckBox();
            this.tsStatus = new System.Windows.Forms.ToolStripStatusLabel();
            this.chkAllowNegativeRewards = new System.Windows.Forms.CheckBox();
            this.grpControls.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pbGame)).BeginInit();
            this.statusStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // lblGameRom
            // 
            this.lblGameRom.AutoSize = true;
            this.lblGameRom.Location = new System.Drawing.Point(15, 15);
            this.lblGameRom.Name = "lblGameRom";
            this.lblGameRom.Size = new System.Drawing.Size(91, 13);
            this.lblGameRom.TabIndex = 0;
            this.lblGameRom.Text = "Game ROM Path:";
            // 
            // edtGameRomPath
            // 
            this.edtGameRomPath.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.edtGameRomPath.Location = new System.Drawing.Point(112, 12);
            this.edtGameRomPath.Name = "edtGameRomPath";
            this.edtGameRomPath.Size = new System.Drawing.Size(361, 20);
            this.edtGameRomPath.TabIndex = 1;
            // 
            // btnBrowseRom
            // 
            this.btnBrowseRom.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnBrowseRom.Location = new System.Drawing.Point(479, 10);
            this.btnBrowseRom.Name = "btnBrowseRom";
            this.btnBrowseRom.Size = new System.Drawing.Size(27, 23);
            this.btnBrowseRom.TabIndex = 2;
            this.btnBrowseRom.Text = "...";
            this.btnBrowseRom.UseVisualStyleBackColor = true;
            this.btnBrowseRom.Click += new System.EventHandler(this.btnBrowseRom_Click);
            // 
            // openFileDialogExe
            // 
            this.openFileDialogExe.DefaultExt = "exe";
            this.openFileDialogExe.Filter = "Executable Files (*.exe)|*.exe||";
            this.openFileDialogExe.Title = "Select the ALE Executable";
            // 
            // openFileDialogRom
            // 
            this.openFileDialogRom.DefaultExt = "bin";
            this.openFileDialogRom.Filter = "Game Rom Files (*.bin)|*.bin||";
            this.openFileDialogRom.Title = "Select the Game ROM file";
            // 
            // btnStart
            // 
            this.btnStart.Location = new System.Drawing.Point(116, 202);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(66, 23);
            this.btnStart.TabIndex = 3;
            this.btnStart.Text = "Start";
            this.btnStart.UseVisualStyleBackColor = true;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // btnUp
            // 
            this.btnUp.Location = new System.Drawing.Point(78, 22);
            this.btnUp.Name = "btnUp";
            this.btnUp.Size = new System.Drawing.Size(83, 23);
            this.btnUp.TabIndex = 1;
            this.btnUp.Text = "UP";
            this.btnUp.UseVisualStyleBackColor = true;
            this.btnUp.Click += new System.EventHandler(this.btnAction_Click);
            // 
            // btnLeft
            // 
            this.btnLeft.Location = new System.Drawing.Point(8, 46);
            this.btnLeft.Name = "btnLeft";
            this.btnLeft.Size = new System.Drawing.Size(83, 23);
            this.btnLeft.TabIndex = 0;
            this.btnLeft.Text = "LEFT";
            this.btnLeft.UseVisualStyleBackColor = true;
            this.btnLeft.Click += new System.EventHandler(this.btnAction_Click);
            // 
            // btnDown
            // 
            this.btnDown.Location = new System.Drawing.Point(78, 70);
            this.btnDown.Name = "btnDown";
            this.btnDown.Size = new System.Drawing.Size(83, 23);
            this.btnDown.TabIndex = 3;
            this.btnDown.Text = "DOWN";
            this.btnDown.UseVisualStyleBackColor = true;
            this.btnDown.Click += new System.EventHandler(this.btnAction_Click);
            // 
            // btnRight
            // 
            this.btnRight.Location = new System.Drawing.Point(148, 46);
            this.btnRight.Name = "btnRight";
            this.btnRight.Size = new System.Drawing.Size(73, 23);
            this.btnRight.TabIndex = 2;
            this.btnRight.Text = "RIGHT";
            this.btnRight.UseVisualStyleBackColor = true;
            this.btnRight.Click += new System.EventHandler(this.btnAction_Click);
            // 
            // btnReset
            // 
            this.btnReset.Enabled = false;
            this.btnReset.Location = new System.Drawing.Point(260, 202);
            this.btnReset.Name = "btnReset";
            this.btnReset.Size = new System.Drawing.Size(83, 23);
            this.btnReset.TabIndex = 4;
            this.btnReset.Text = "Reset";
            this.btnReset.UseVisualStyleBackColor = true;
            this.btnReset.Click += new System.EventHandler(this.btnAction_Click);
            // 
            // grpControls
            // 
            this.grpControls.Controls.Add(this.btnUp);
            this.grpControls.Controls.Add(this.btnRight);
            this.grpControls.Controls.Add(this.btnFire);
            this.grpControls.Controls.Add(this.btnLeft);
            this.grpControls.Controls.Add(this.btnDown);
            this.grpControls.Enabled = false;
            this.grpControls.Location = new System.Drawing.Point(112, 67);
            this.grpControls.Name = "grpControls";
            this.grpControls.Size = new System.Drawing.Size(227, 105);
            this.grpControls.TabIndex = 5;
            this.grpControls.TabStop = false;
            this.grpControls.Text = "Game Control";
            // 
            // btnFire
            // 
            this.btnFire.Location = new System.Drawing.Point(97, 46);
            this.btnFire.Name = "btnFire";
            this.btnFire.Size = new System.Drawing.Size(45, 23);
            this.btnFire.TabIndex = 0;
            this.btnFire.Text = "FIRE";
            this.btnFire.UseVisualStyleBackColor = true;
            this.btnFire.Click += new System.EventHandler(this.btnAction_Click);
            // 
            // timerUI
            // 
            this.timerUI.Enabled = true;
            this.timerUI.Interval = 250;
            this.timerUI.Tick += new System.EventHandler(this.timerUI_Tick);
            // 
            // pbGame
            // 
            this.pbGame.Location = new System.Drawing.Point(345, 38);
            this.pbGame.Name = "pbGame";
            this.pbGame.Size = new System.Drawing.Size(160, 210);
            this.pbGame.TabIndex = 6;
            this.pbGame.TabStop = false;
            // 
            // radColor
            // 
            this.radColor.AutoSize = true;
            this.radColor.Checked = true;
            this.radColor.Location = new System.Drawing.Point(231, 231);
            this.radColor.Name = "radColor";
            this.radColor.Size = new System.Drawing.Size(49, 17);
            this.radColor.TabIndex = 6;
            this.radColor.TabStop = true;
            this.radColor.Text = "Color";
            this.radColor.UseVisualStyleBackColor = true;
            this.radColor.CheckedChanged += new System.EventHandler(this.radColor_CheckedChanged);
            // 
            // radGray
            // 
            this.radGray.AutoSize = true;
            this.radGray.Location = new System.Drawing.Point(286, 231);
            this.radGray.Name = "radGray";
            this.radGray.Size = new System.Drawing.Size(47, 17);
            this.radGray.TabIndex = 7;
            this.radGray.Text = "Gray";
            this.radGray.UseVisualStyleBackColor = true;
            this.radGray.CheckedChanged += new System.EventHandler(this.radGray_CheckedChanged);
            // 
            // btnQuit
            // 
            this.btnQuit.Location = new System.Drawing.Point(188, 202);
            this.btnQuit.Name = "btnQuit";
            this.btnQuit.Size = new System.Drawing.Size(66, 23);
            this.btnQuit.TabIndex = 3;
            this.btnQuit.Text = "Quit";
            this.btnQuit.UseVisualStyleBackColor = true;
            this.btnQuit.Click += new System.EventHandler(this.btnQuit_Click);
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsReward,
            this.tsStatus});
            this.statusStrip1.Location = new System.Drawing.Point(0, 304);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(515, 22);
            this.statusStrip1.TabIndex = 8;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // tsReward
            // 
            this.tsReward.Font = new System.Drawing.Font("Century Gothic", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tsReward.Name = "tsReward";
            this.tsReward.Size = new System.Drawing.Size(0, 17);
            // 
            // chkShowDisplay
            // 
            this.chkShowDisplay.AutoSize = true;
            this.chkShowDisplay.Location = new System.Drawing.Point(120, 232);
            this.chkShowDisplay.Name = "chkShowDisplay";
            this.chkShowDisplay.Size = new System.Drawing.Size(90, 17);
            this.chkShowDisplay.TabIndex = 9;
            this.chkShowDisplay.Text = "Show Display";
            this.chkShowDisplay.UseVisualStyleBackColor = true;
            this.chkShowDisplay.CheckedChanged += new System.EventHandler(this.chkShowDisplay_CheckedChanged);
            // 
            // chkTerminateOnRallyEnd
            // 
            this.chkTerminateOnRallyEnd.AutoSize = true;
            this.chkTerminateOnRallyEnd.Location = new System.Drawing.Point(120, 255);
            this.chkTerminateOnRallyEnd.Name = "chkTerminateOnRallyEnd";
            this.chkTerminateOnRallyEnd.Size = new System.Drawing.Size(136, 17);
            this.chkTerminateOnRallyEnd.TabIndex = 9;
            this.chkTerminateOnRallyEnd.Text = "Terminate on Rally End";
            this.chkTerminateOnRallyEnd.UseVisualStyleBackColor = true;
            this.chkTerminateOnRallyEnd.CheckedChanged += new System.EventHandler(this.chkShowDisplay_CheckedChanged);
            // 
            // tsStatus
            // 
            this.tsStatus.Name = "tsStatus";
            this.tsStatus.Size = new System.Drawing.Size(0, 17);
            // 
            // chkAllowNegativeRewards
            // 
            this.chkAllowNegativeRewards.AutoSize = true;
            this.chkAllowNegativeRewards.Location = new System.Drawing.Point(120, 278);
            this.chkAllowNegativeRewards.Name = "chkAllowNegativeRewards";
            this.chkAllowNegativeRewards.Size = new System.Drawing.Size(129, 17);
            this.chkAllowNegativeRewards.TabIndex = 9;
            this.chkAllowNegativeRewards.Text = "Allow negtive rewards";
            this.chkAllowNegativeRewards.UseVisualStyleBackColor = true;
            this.chkAllowNegativeRewards.CheckedChanged += new System.EventHandler(this.chkShowDisplay_CheckedChanged);
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(515, 326);
            this.Controls.Add(this.chkAllowNegativeRewards);
            this.Controls.Add(this.chkTerminateOnRallyEnd);
            this.Controls.Add(this.chkShowDisplay);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.radGray);
            this.Controls.Add(this.radColor);
            this.Controls.Add(this.pbGame);
            this.Controls.Add(this.grpControls);
            this.Controls.Add(this.btnReset);
            this.Controls.Add(this.btnQuit);
            this.Controls.Add(this.btnStart);
            this.Controls.Add(this.btnBrowseRom);
            this.Controls.Add(this.edtGameRomPath);
            this.Controls.Add(this.lblGameRom);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "FormMain";
            this.Text = "Test Application";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.FormMain_FormClosing);
            this.Load += new System.EventHandler(this.FormMain_Load);
            this.grpControls.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pbGame)).EndInit();
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label lblGameRom;
        private System.Windows.Forms.TextBox edtGameRomPath;
        private System.Windows.Forms.Button btnBrowseRom;
        private System.Windows.Forms.OpenFileDialog openFileDialogExe;
        private System.Windows.Forms.OpenFileDialog openFileDialogRom;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.Button btnUp;
        private System.Windows.Forms.Button btnLeft;
        private System.Windows.Forms.Button btnDown;
        private System.Windows.Forms.Button btnRight;
        private System.Windows.Forms.Button btnReset;
        private System.Windows.Forms.GroupBox grpControls;
        private System.Windows.Forms.Timer timerUI;
        private System.Windows.Forms.PictureBox pbGame;
        private System.Windows.Forms.RadioButton radColor;
        private System.Windows.Forms.RadioButton radGray;
        private System.Windows.Forms.Button btnQuit;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel tsReward;
        private System.Windows.Forms.Button btnFire;
        private System.Windows.Forms.CheckBox chkShowDisplay;
        private System.Windows.Forms.CheckBox chkTerminateOnRallyEnd;
        private System.Windows.Forms.ToolStripStatusLabel tsStatus;
        private System.Windows.Forms.CheckBox chkAllowNegativeRewards;
    }
}


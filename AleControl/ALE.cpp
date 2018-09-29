// ALE.cpp : Implementation of CALE

#include "stdafx.h"
#include "ALE.h"
#include <winerror.h>
#include <float.h>
#include <comutil.h>

#define MAX_OUTPUT 16

std::string ConvertWCSToMBS(const wchar_t* pstr, long wslen)
{
	int len = ::WideCharToMultiByte(CP_ACP, 0, pstr, wslen, NULL, 0, NULL, NULL);

	std::string dblstr(len, '\0');
	len = ::WideCharToMultiByte(CP_ACP, 0 /* no flags */,
		pstr, wslen /* not necessary NULL-terminated */,
		&dblstr[0], len,
		NULL, NULL /* no default char */);

	return dblstr;
}

BSTR ConvertMBSToBSTR(const std::string& str)
{
	int wslen = ::MultiByteToWideChar(CP_ACP, 0 /* no flags */,
		str.data(), str.length(),
		NULL, 0);

	BSTR wsdata = ::SysAllocStringLen(NULL, wslen);
	::MultiByteToWideChar(CP_ACP, 0 /* no flags */,
		str.data(), str.length(),
		wsdata, wslen);
	return wsdata;
}

std::string ConvertBSTRToMBS(BSTR bstr)
{
	int wslen = ::SysStringLen(bstr);
	return ConvertWCSToMBS((wchar_t*)bstr, wslen);
}


HRESULT CALE::FinalConstruct()
{
	return S_OK;
}

void CALE::FinalRelease()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	float fFinalRelease = 1.0;
	double dfFinalRelease = 1.0;
}


// CALE

STDMETHODIMP CALE::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IALE
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CALE::Load(BSTR bstrGameROM)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	TRY
	{
		if (m_pale == NULL)
			AfxThrowOleDispatchException(0, _T("You must call Initialize first!"));

		m_pale->setBool("disable_exit", true);
		std::string strROM = ConvertBSTRToMBS(bstrGameROM);
		m_pale->loadROM(strROM);
	}
	CATCH(COleDispatchException, e)
	{
		return Error(e->m_strDescription, IID_IALE, e->m_scError);
	}
	CATCH_ALL(e)
	{
		CComBSTR str;

		str = "Failed to load '";
		str += bstrGameROM;
		str += "'!";

		return Error(str, IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CALE::get_EnableSound(VARIANT_BOOL* pbEnable)
{
	TRY
	{
		if (m_pale == NULL)
			AfxThrowOleDispatchException(0, _T("You must call Initialize first!"));

		bool bVal = m_pale->getBool("sound");
		*pbEnable = (bVal) ? VARIANT_TRUE : VARIANT_FALSE;
	}
	CATCH(COleDispatchException, e)
	{
		return Error(e->m_strDescription, IID_IALE, e->m_scError);
	}
	CATCH_ALL(e)
	{
		CComBSTR str;
		str = "Failed to get EnableSound!";
		return Error(str, IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CALE::put_EnableSound(VARIANT_BOOL bEnable)
{
	TRY
	{
		if (m_pale == NULL)
			AfxThrowOleDispatchException(0, _T("You must call Initialize first!"));

		bool bVal = (bEnable == VARIANT_TRUE) ? true : false;
		m_pale->setBool("sound", bVal);
	}
	CATCH(COleDispatchException, e)
	{
		return Error(e->m_strDescription, IID_IALE, e->m_scError);
	}
	CATCH_ALL(e)
	{
		CComBSTR str;
		str = "Failed to set EnableSound!";
		return Error(str, IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CALE::get_EnableDisplayScreen(VARIANT_BOOL* pbEnable)
{
	TRY
	{
		if (m_pale == NULL)
			AfxThrowOleDispatchException(0, _T("You must call Initialize first!"));

		bool bVal = m_pale->getBool("display_screen");
		*pbEnable = (bVal) ? VARIANT_TRUE : VARIANT_FALSE;
	}
	CATCH(COleDispatchException, e)
	{
		return Error(e->m_strDescription, IID_IALE, e->m_scError);
	}
	CATCH_ALL(e)
	{
		CComBSTR str;
		str = "Failed to get EnableDisplayScreen!";
		return Error(str, IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CALE::put_EnableDisplayScreen(VARIANT_BOOL bEnable)
{
	TRY
	{
		if (m_pale == NULL)
			AfxThrowOleDispatchException(0, _T("You must call Initialize first!"));

		bool bVal = (bEnable == VARIANT_TRUE) ? true : false;
		m_pale->setBool("display_screen", bVal);
	}
	CATCH(COleDispatchException, e)
	{
		return Error(e->m_strDescription, IID_IALE, e->m_scError);
	}
	CATCH_ALL(e)
	{
		CComBSTR str;
		str = "Failed to set EnableDisplayScreen!";
		return Error(str, IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CALE::get_RandomSeed(int* pnSeed)
{
	TRY
	{
		if (m_pale == NULL)
			AfxThrowOleDispatchException(0, _T("You must call Initialize first!"));

		*pnSeed = m_pale->getInt("random_seed");
	}
	CATCH(COleDispatchException, e)
	{
		return Error(e->m_strDescription, IID_IALE, e->m_scError);
	}
	CATCH_ALL(e)
	{
		CComBSTR str;
		str = "Failed to get RandomSeed!";
		return Error(str, IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CALE::put_RandomSeed(int nSeed)
{
	TRY
	{
		if (m_pale == NULL)
			AfxThrowOleDispatchException(0, _T("You must call Initialize first!"));

		m_pale->setInt("random_seed", nSeed);
	}
	CATCH(COleDispatchException, e)
	{
		return Error(e->m_strDescription, IID_IALE, e->m_scError);
	}
	CATCH_ALL(e)
	{
		CComBSTR str;
		str = "Failed to set RandomSeed!";
		return Error(str, IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CALE::get_RepeatActionProbability(float* pfProb)
{
	TRY
	{
		if (m_pale == NULL)
			AfxThrowOleDispatchException(0, _T("You must call Initialize first!"));

		*pfProb = m_pale->getFloat("repeat_action_probability");
	}
	CATCH(COleDispatchException, e)
	{
		return Error(e->m_strDescription, IID_IALE, e->m_scError);
	}
	CATCH_ALL(e)
	{
		CComBSTR str;
		str = "Failed to get RepeatActionProbability!";
		return Error(str, IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL
	
	return S_OK;
}

STDMETHODIMP CALE::put_RepeatActionProbability(float fProb)
{
	TRY
	{
		if (m_pale == NULL)
			AfxThrowOleDispatchException(0, _T("You must call Initialize first!"));

		m_pale->setFloat("repeat_action_probability", fProb);
	}
	CATCH(COleDispatchException, e)
	{
		return Error(e->m_strDescription, IID_IALE, e->m_scError);
	}
	CATCH_ALL(e)
	{
		CComBSTR str;
		str = "Failed to set RepeatActionProbability!";
		return Error(str, IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CALE::get_ActionSpace(SAFEARRAY** rgActions)
{
	return get_MinimalActionSpace(rgActions);
}

STDMETHODIMP CALE::get_GameOver(VARIANT_BOOL* pbGameOver)
{
	TRY
	{
		if (m_pale == NULL)
			AfxThrowOleDispatchException(0, _T("You must call Initialize first!"));

		bool bVal = m_pale->game_over();
		*pbGameOver = (bVal) ? VARIANT_TRUE : VARIANT_FALSE;
	}
	CATCH(COleDispatchException, e)
	{
		return Error(e->m_strDescription, IID_IALE, e->m_scError);
	}
	CATCH_ALL(e)
	{
		CComBSTR str;
		str = "Failed to get GameOver!";
		return Error(str, IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL
		
	return S_OK;
}

STDMETHODIMP CALE::Act(ACTION action, float* pfReward)
{
	TRY
	{
		if (m_pale == NULL)
			AfxThrowOleDispatchException(0, _T("You must call Initialize first!"));

		*pfReward = m_pale->act((Action)action);
	}
	CATCH(COleDispatchException, e)
	{
		return Error(e->m_strDescription, IID_IALE, e->m_scError);
	}
	CATCH_ALL(e)
	{
		CComBSTR str;
		str = "Failed to Act!";
		return Error(str, IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL
		
	return S_OK;
}

STDMETHODIMP CALE::ResetGame()
{
	TRY
	{
		if (m_pale == NULL)
			AfxThrowOleDispatchException(0, _T("You must call Initialize first!"));

		m_pale->reset_game();
	}
	CATCH(COleDispatchException, e)
	{
		return Error(e->m_strDescription, IID_IALE, e->m_scError);
	}
	CATCH_ALL(e)
	{
		CComBSTR str;
		str = "Failed to ResetGame!";
		return Error(str, IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CALE::get_MaxNumFrames(int* pnMax)
{
	TRY
	{
		if (m_pale == NULL)
			AfxThrowOleDispatchException(0, _T("You must call Initialize first!"));

		*pnMax = m_pale->max_num_frames;
	}
	CATCH(COleDispatchException, e)
	{
		return Error(e->m_strDescription, IID_IALE, e->m_scError);
	}
	CATCH_ALL(e)
	{
		CComBSTR str;
		str = "Failed to get max_num_frames!";
		return Error(str, IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CALE::put_MaxNumFrames(int nMax)
{
	TRY
	{
		if (m_pale == NULL)
			AfxThrowOleDispatchException(0, _T("You must call Initialize first!"));

		m_pale->max_num_frames = nMax;
	}
	CATCH(COleDispatchException, e)
	{
		return Error(e->m_strDescription, IID_IALE, e->m_scError);
	}
	CATCH_ALL(e)
	{
		CComBSTR str;
		str = "Failed to set MaxNumFrames!";
		return Error(str, IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CALE::GetScreenData(COLORTYPE clrType, SAFEARRAY** rgScreenData)
{
	HRESULT hr;
	SAFEARRAY* rgOutput = NULL;

	TRY
	{
		if (m_pale == NULL)
			AfxThrowOleDispatchException(0, _T("You must call Initialize first!"));

		ALEScreen screen = m_pale->getScreen();
		int nChannels = (clrType == CT_COLOR) ? 3 : 1;
		int nWid = (int)screen.width();
		int nHt = (int)screen.height();
	    int nSize = nWid * nHt * nChannels;
		ColourPalette pal = m_pale->theOSystem.get()->colourPalette();

		rgOutput = SafeArrayCreateVector(VT_UI1, 0, nSize);
		if (rgOutput == NULL)
			AfxThrowMemoryException();

		byte* rgRawData;
		hr = SafeArrayAccessData(rgOutput, (void**)&rgRawData);
		if (FAILED(hr))
			AfxThrowOleException(hr);

		int nGOffset = nHt * nWid;
		int nBOffset = nHt * nWid * 2;

		for (int y = 0; y < nHt; y++)
		{
			for (int x = 0; x < nWid; x++)
			{
				LONG lIdx = (y * nWid) + x;
				pixel_t px = screen.get(y, x);
				uInt8 uR;
				uInt8 uG;
				uInt8 uB;

				if (clrType == CT_COLOR)
				{
					pal.applyPaletteRGB(px, &uR, &uG, &uB);
					rgRawData[lIdx] = (byte)uR;
					rgRawData[lIdx + nGOffset] = (byte)uG;
					rgRawData[lIdx + nBOffset] = (byte)uB;
				}
				else
				{
					pal.applyPaletteGrayscale(px, &uR);
					rgRawData[lIdx] = (byte)uR;
				}
			}
		}

		hr = SafeArrayUnaccessData(rgOutput);
		if (FAILED(hr))
			AfxThrowOleException(hr);

		*rgScreenData = rgOutput;
		rgOutput = NULL;
	}
	CATCH(COleDispatchException, e)
	{
		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error(e->m_strDescription, IID_IALE, e->m_scError);
	}
	CATCH_ALL(e)
	{
		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error("Failed to call GetScreenData", IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CALE::GetScreenDimensions(float* pfWid, float* pfHt)
{
	TRY
	{
		if (m_pale == NULL)
			AfxThrowOleDispatchException(0, _T("You must call Initialize first!"));

		ALEScreen screen = m_pale->getScreen();
		*pfWid = screen.width();
		*pfHt = screen.height();
	}
    CATCH(COleDispatchException, e)
	{
		return Error(e->m_strDescription, IID_IALE, e->m_scError);
	}
	CATCH_ALL(e)
	{
		return Error("Failed to call GetScreenDimensions", IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CALE::get_EnableRestrictedActionSet(VARIANT_BOOL* pbEnable)
{
	TRY
	{
		if (m_pale == NULL)
			AfxThrowOleDispatchException(0, _T("You must call Initialize first!"));

		bool bVal = m_pale->getBool("restricted_action_set");
		*pbEnable = (bVal) ? VARIANT_TRUE : VARIANT_FALSE;
	}
	CATCH(COleDispatchException, e)
	{
		return Error(e->m_strDescription, IID_IALE, e->m_scError);
	}
	CATCH_ALL(e)
	{
		CComBSTR str;
		str = "Failed to get EnableRestrictedActionSet!";
		return Error(str, IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CALE::put_EnableRestrictedActionSet(VARIANT_BOOL bEnable)
{
	TRY
	{
		if (m_pale == NULL)
			AfxThrowOleDispatchException(0, _T("You must call Initialize first!"));

		bool bVal = (bEnable == VARIANT_TRUE) ? true : false;
		m_pale->setBool("restricted_action_set", bVal);
	}
	CATCH(COleDispatchException, e)
	{
		return Error(e->m_strDescription, IID_IALE, e->m_scError);
	}
	CATCH_ALL(e)
	{
		CComBSTR str;
		str = "Failed to set EnableRestrictedActionSet!";
		return Error(str, IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CALE::get_EnableColorData(VARIANT_BOOL* pbEnable)
{
	TRY
	{
		if (m_pale == NULL)
			AfxThrowOleDispatchException(0, _T("You must call Initialize first!"));

		bool bVal = m_pale->getBool("send_rgb");
		*pbEnable = (bVal) ? VARIANT_TRUE : VARIANT_FALSE;
	}
	CATCH(COleDispatchException, e)
	{
		return Error(e->m_strDescription, IID_IALE, e->m_scError);
	}
	CATCH_ALL(e)
	{
		CComBSTR str;
		str = "Failed to get EnableColorData!";
		return Error(str, IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CALE::put_EnableColorData(VARIANT_BOOL bEnable)
{
	TRY
	{
		if (m_pale == NULL)
			AfxThrowOleDispatchException(0, _T("You must call Initialize first!"));

		bool bVal = (bEnable == VARIANT_TRUE) ? true : false;
		m_pale->setBool("send_rgb", bVal);
	}
	CATCH(COleDispatchException, e)
	{
		return Error(e->m_strDescription, IID_IALE, e->m_scError);
	}
	CATCH_ALL(e)
	{
		CComBSTR str;
		str = "Failed to set EnableColorData!";
		return Error(str, IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CALE::get_EnableColorAveraging(VARIANT_BOOL* pbEnable)
{
	TRY
	{
		if (m_pale == NULL)
			AfxThrowOleDispatchException(0, _T("You must call Initialize first!"));

		bool bVal = m_pale->getBool("color_averaging");
		*pbEnable = (bVal) ? VARIANT_TRUE : VARIANT_FALSE;
	}
	CATCH(COleDispatchException, e)
	{
		return Error(e->m_strDescription, IID_IALE, e->m_scError);
	}
	CATCH_ALL(e)
	{
		CComBSTR str;
		str = "Failed to get EnableColorAveraging!";
		return Error(str, IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CALE::put_EnableColorAveraging(VARIANT_BOOL bEnable)
{
	TRY
	{
		if (m_pale == NULL)
			AfxThrowOleDispatchException(0, _T("You must call Initialize first!"));

		bool bVal = (bEnable == VARIANT_TRUE) ? true : false;
		m_pale->setBool("color_averaging", bVal);
	}
	CATCH(COleDispatchException, e)
	{
		return Error(e->m_strDescription, IID_IALE, e->m_scError);
	}
	CATCH_ALL(e)
	{
		CComBSTR str;
		str = "Failed to set EnableColorAveraging!";
		return Error(str, IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CALE::Shutdown()
{
	TRY
	{
		if (m_pale != NULL)
		{
			m_pale->theOSystem->quit();
			delete m_pale;
			m_pale = NULL;
		}
	}
	CATCH_ALL(e)
	{
		CComBSTR str;
		str = "Failed to Shutdown!";
		return Error(str, IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CALE::Initialize()
{
	TRY
	{
		m_pale = new ALEInterface();
	}
	CATCH_ALL(e)
	{
		CComBSTR str;
		str = "Failed to Initialize!";
		return Error(str, IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}

STDMETHODIMP CALE::get_LegalActionSpace(SAFEARRAY** rgActions)
{
	HRESULT hr;
	SAFEARRAY* rgOutput = NULL;

	TRY
	{
		if (m_pale == NULL)
			AfxThrowOleDispatchException(0, _T("You must call Initialize first!"));

		ActionVect legal_actions = m_pale->getLegalActionSet();

		rgOutput = SafeArrayCreateVector(VT_I4, 0, legal_actions.size());
		if (rgOutput == NULL)
			AfxThrowMemoryException();

		for (LONG lIdx = 0; lIdx < legal_actions.size(); lIdx++)
		{
			int nAction = (int)legal_actions[lIdx];

			hr = SafeArrayPutElement(rgOutput, &lIdx, &nAction);
			if (FAILED(hr))
				AfxThrowOleException(hr);
		}

		*rgActions = rgOutput;
		rgOutput = NULL;
	}
	CATCH(COleDispatchException, e)
	{
		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error(e->m_strDescription, IID_IALE, e->m_scError);
	}
	CATCH_ALL(e)
	{
		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error("Failed to get LegalActionSpace", IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL

		return S_OK;
}

STDMETHODIMP CALE::get_MinimalActionSpace(SAFEARRAY** rgActions)
{
	HRESULT hr;
	SAFEARRAY* rgOutput = NULL;

	TRY
	{
		if (m_pale == NULL)
			AfxThrowOleDispatchException(0, _T("You must call Initialize first!"));

		ActionVect legal_actions = m_pale->getMinimalActionSet();

		rgOutput = SafeArrayCreateVector(VT_I4, 0, legal_actions.size());
		if (rgOutput == NULL)
			AfxThrowMemoryException();

		for (LONG lIdx = 0; lIdx < legal_actions.size(); lIdx++)
		{
			int nAction = (int)legal_actions[lIdx];

			hr = SafeArrayPutElement(rgOutput, &lIdx, &nAction);
			if (FAILED(hr))
				AfxThrowOleException(hr);
		}

		*rgActions = rgOutput;
		rgOutput = NULL;
	}
	CATCH(COleDispatchException, e)
	{
		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error(e->m_strDescription, IID_IALE, e->m_scError);
	}
	CATCH_ALL(e)
	{
		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error("Failed to get MinimalActionSpace", IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL

		return S_OK;
}

STDMETHODIMP CALE::GetRAMData(SAFEARRAY** rgData)
{
	HRESULT hr;
	SAFEARRAY* rgOutput = NULL;

	TRY
	{
		if (m_pale == NULL)
			AfxThrowOleDispatchException(0, _T("You must call Initialize first!"));

		ALERAM ram = m_pale->getRAM();
		int nSize = ram.size();

		rgOutput = SafeArrayCreateVector(VT_UI1, 0, nSize);
		if (rgOutput == NULL)
			AfxThrowMemoryException();

		byte* rgRawData;
		hr = SafeArrayAccessData(rgOutput, (void**)&rgRawData);
		if (FAILED(hr))
			AfxThrowOleException(hr);

		for (int i = 0; i < nSize; i++)
		{
			rgRawData[i] = (byte)ram.byte((unsigned int)i);
		}

		hr = SafeArrayUnaccessData(rgOutput);
		if (FAILED(hr))
			AfxThrowOleException(hr);

		*rgData = rgOutput;
		rgOutput = NULL;
	}
	CATCH(COleDispatchException, e)
	{
		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error(e->m_strDescription, IID_IALE, e->m_scError);
	}
	CATCH_ALL(e)
	{
		if (rgOutput != NULL)
		{
			SafeArrayDestroy(rgOutput);
			rgOutput = NULL;
		}

		return Error("Failed to call GetRAMData", IID_IALE, COleException::Process(e));
	}
	END_CATCH_ALL

	return S_OK;
}



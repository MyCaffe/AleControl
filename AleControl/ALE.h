// ALE.h : Declaration of the CALE

#pragma once
#include "resource.h"       // main symbols

#include "AleControl_i.h"
#include "_IALEEvents_CP.h"
#include "ale_interface.hpp"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif


const DWORD MAX_ERROR = 1023;

// CALE

class ATL_NO_VTABLE CALE :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CALE, &CLSID_ALE>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CALE>,
	public CProxy_IALEEvents<CALE>,
	public IDispatchImpl<IALE, &IID_IALE, &LIBID_AleControlLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
	ALEInterface* m_pale;


public:
	CALE()
	{
		m_pale = NULL;
	}

	~CALE()
	{
		if (m_pale != NULL)
		{
			delete m_pale;
			m_pale = NULL;
		}
	}

DECLARE_REGISTRY_RESOURCEID(IDR_ALE)


BEGIN_COM_MAP(CALE)
	COM_INTERFACE_ENTRY(IALE)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CALE)
	CONNECTION_POINT_ENTRY(__uuidof(_IALEEvents))
END_CONNECTION_POINT_MAP()
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()
	DECLARE_GET_CONTROLLING_UNKNOWN()

	HRESULT FinalConstruct();
	void FinalRelease();

public:

	STDMETHOD(Load)(BSTR bstrGameROM);
	STDMETHOD(get_EnableSound)(VARIANT_BOOL* pbEnable);
	STDMETHOD(put_EnableSound)(VARIANT_BOOL bEnable);
	STDMETHOD(get_EnableDisplayScreen)(VARIANT_BOOL* pbEnable);
	STDMETHOD(put_EnableDisplayScreen)(VARIANT_BOOL bEnable);
	STDMETHOD(get_RandomSeed)(int* pnSeed);
	STDMETHOD(put_RandomSeed)(int nSeed);
	STDMETHOD(get_RepeatActionProbability)(float* pfProb);
	STDMETHOD(put_RepeatActionProbability)(float fProb);
	STDMETHOD(get_ActionSpace)(SAFEARRAY** rgActions);
	STDMETHOD(get_GameOver)(VARIANT_BOOL* pbGameOver);
	STDMETHOD(Act)(ACTION action, float* pfReward);
	STDMETHOD(ResetGame)();
	STDMETHOD(get_MaxNumFrames)(int* pnMax);
	STDMETHOD(put_MaxNumFrames)(int nMax);
	STDMETHOD(GetScreenData)(COLORTYPE clrType, SAFEARRAY** rgScreenData);
	STDMETHOD(GetScreenDimensions)(float* pfWid, float* pfHt);
	STDMETHOD(get_EnableRestrictedActionSet)(VARIANT_BOOL* pbEnable);
	STDMETHOD(put_EnableRestrictedActionSet)(VARIANT_BOOL bEnable);
	STDMETHOD(get_EnableColorData)(VARIANT_BOOL* pbEnable);
	STDMETHOD(put_EnableColorData)(VARIANT_BOOL bEnable);
	STDMETHOD(get_EnableColorAveraging)(VARIANT_BOOL* pbEnable);
	STDMETHOD(put_EnableColorAveraging)(VARIANT_BOOL bEnable);
	STDMETHOD(Shutdown)();
	STDMETHOD(Initialize)();
	STDMETHOD(get_LegalActionSpace)(SAFEARRAY** rgActions);
	STDMETHOD(get_MinimalActionSpace)(SAFEARRAY** rgActions);
};

OBJECT_ENTRY_AUTO(__uuidof(ALE), CALE)

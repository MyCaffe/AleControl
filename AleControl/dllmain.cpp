// dllmain.cpp : Implementation of DllMain.

#include "stdafx.h"
#include "resource.h"
#include "AleControl_i.h"
#include "dllmain.h"
#include "dlldatax.h"

CAleControlModule _AtlModule;

class CAleControlApp : public CWinApp
{
public:

// Overrides
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CAleControlApp, CWinApp)
END_MESSAGE_MAP()

CAleControlApp theApp;

BOOL CAleControlApp::InitInstance()
{
#ifdef _MERGE_PROXYSTUB
	if (!PrxDllMain(m_hInstance, DLL_PROCESS_ATTACH, NULL))
		return FALSE;
#endif
	return CWinApp::InitInstance();
}

int CAleControlApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}

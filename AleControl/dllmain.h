// dllmain.h : Declaration of module class.

class CAleControlModule : public CAtlDllModuleT< CAleControlModule >
{
public :
	DECLARE_LIBID(LIBID_AleControlLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ALECONTROL, "{2E8042E1-1DB0-4FB7-BF4F-2B7658F5889D}")
};

extern class CAleControlModule _AtlModule;

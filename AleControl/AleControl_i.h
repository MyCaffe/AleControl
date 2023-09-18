

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for AleControl.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0628 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __AleControl_i_h__
#define __AleControl_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if defined(_CONTROL_FLOW_GUARD_XFG)
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __IALE_FWD_DEFINED__
#define __IALE_FWD_DEFINED__
typedef interface IALE IALE;

#endif 	/* __IALE_FWD_DEFINED__ */


#ifndef ___IALEEvents_FWD_DEFINED__
#define ___IALEEvents_FWD_DEFINED__
typedef interface _IALEEvents _IALEEvents;

#endif 	/* ___IALEEvents_FWD_DEFINED__ */


#ifndef __ALE_FWD_DEFINED__
#define __ALE_FWD_DEFINED__

#ifdef __cplusplus
typedef class ALE ALE;
#else
typedef struct ALE ALE;
#endif /* __cplusplus */

#endif 	/* __ALE_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_AleControl_0000_0000 */
/* [local] */ 

typedef /* [uuid] */  DECLSPEC_UUID("88E91CB1-F70C-49B5-8D10-88F23C9919C2") 
enum _COLORTYPE
    {
        CT_COLOR	= 0,
        CT_GRAYSCALE	= ( CT_COLOR + 1 ) 
    } 	COLORTYPE;

typedef /* [uuid] */  DECLSPEC_UUID("F60C1878-6C17-4C31-B4E7-8BD6365E6171") 
enum _ACTION
    {
        ACT_PLAYER_A_NOOP	= 0,
        ACT_PLAYER_A_FIRE	= 1,
        ACT_PLAYER_A_UP	= 2,
        ACT_PLAYER_A_RIGHT	= 3,
        ACT_PLAYER_A_LEFT	= 4,
        ACT_PLAYER_A_DOWN	= 5,
        ACT_PLAYER_A_UPRIGHT	= 6,
        ACT_PLAYER_A_UPLEFT	= 7,
        ACT_PLAYER_A_DOWNRIGHT	= 8,
        ACT_PLAYER_A_DOWNLEFT	= 9,
        ACT_PLAYER_A_UPFIRE	= 10,
        ACT_PLAYER_A_RIGHTFIRE	= 11,
        ACT_PLAYER_A_LEFTFIRE	= 12,
        ACT_PLAYER_A_DOWNFIRE	= 13,
        ACT_PLAYER_A_UPRIGHTFIRE	= 14,
        ACT_PLAYER_A_UPLEFTFIRE	= 15,
        ACT_PLAYER_A_DOWNRIGHTFIRE	= 16,
        ACT_PLAYER_A_DOWNLEFTFIRE	= 17,
        ACT_PLAYER_B_NOOP	= 18,
        ACT_PLAYER_B_FIRE	= 19,
        ACT_PLAYER_B_UP	= 20,
        ACT_PLAYER_B_RIGHT	= 21,
        ACT_PLAYER_B_LEFT	= 22,
        ACT_PLAYER_B_DOWN	= 23,
        ACT_PLAYER_B_UPRIGHT	= 24,
        ACT_PLAYER_B_UPLEFT	= 25,
        ACT_PLAYER_B_DOWNRIGHT	= 26,
        ACT_PLAYER_B_DOWNLEFT	= 27,
        ACT_PLAYER_B_UPFIRE	= 28,
        ACT_PLAYER_B_RIGHTFIRE	= 29,
        ACT_PLAYER_B_LEFTFIRE	= 30,
        ACT_PLAYER_B_DOWNFIRE	= 31,
        ACT_PLAYER_B_UPRIGHTFIRE	= 32,
        ACT_PLAYER_B_UPLEFTFIRE	= 33,
        ACT_PLAYER_B_DOWNRIGHTFIRE	= 34,
        ACT_PLAYER_B_DOWNLEFTFIRE	= 35,
        ACT_RESET	= 40,
        ACT_UNDEFINED	= 41,
        ACT_RANDOM	= 42,
        ACT_SAVE_STATE	= 43,
        ACT_LOAD_STATE	= 44,
        ACT_SYSTEM_RESET	= 45,
        ACT_LAST_ACTION_INDEX	= 50
    } 	ACTION;



extern RPC_IF_HANDLE __MIDL_itf_AleControl_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_AleControl_0000_0000_v0_0_s_ifspec;

#ifndef __IALE_INTERFACE_DEFINED__
#define __IALE_INTERFACE_DEFINED__

/* interface IALE */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IALE;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("03B057C8-7980-433D-B088-23D4C2179306")
    IALE : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ BSTR bstrGameROM) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_EnableSound( 
            /* [in] */ VARIANT_BOOL bEnable) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_EnableSound( 
            /* [retval][out] */ VARIANT_BOOL *pbEnable) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_EnableDisplayScreen( 
            /* [in] */ VARIANT_BOOL bEnable) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_EnableDisplayScreen( 
            /* [retval][out] */ VARIANT_BOOL *pbEnable) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_RandomSeed( 
            /* [in] */ int nSeed) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_RandomSeed( 
            /* [retval][out] */ int *pnSeed) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_RepeatActionProbability( 
            /* [in] */ float fProb) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_RepeatActionProbability( 
            /* [retval][out] */ float *pfProb) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActionSpace( 
            /* [retval][out] */ SAFEARRAY * *rgActions) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_GameOver( 
            /* [retval][out] */ VARIANT_BOOL *pbGameOver) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Act( 
            /* [in] */ ACTION action,
            /* [retval][out] */ float *pfReward) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetGame( void) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_MaxNumFrames( 
            /* [in] */ int nMax) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_MaxNumFrames( 
            /* [retval][out] */ int *pnMax) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetScreenData( 
            /* [in] */ COLORTYPE clrType,
            /* [retval][out] */ SAFEARRAY * *rgData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetScreenDimensions( 
            /* [out] */ float *pfWidth,
            /* [out] */ float *pfHeight) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_EnableRestrictedActionSet( 
            /* [in] */ VARIANT_BOOL bEnable) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_EnableRestrictedActionSet( 
            /* [retval][out] */ VARIANT_BOOL *pbEnable) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_EnableColorData( 
            /* [in] */ VARIANT_BOOL bEnable) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_EnableColorData( 
            /* [retval][out] */ VARIANT_BOOL *pbEnable) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_EnableColorAveraging( 
            /* [in] */ VARIANT_BOOL bEnable) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_EnableColorAveraging( 
            /* [retval][out] */ VARIANT_BOOL *pbEnable) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Shutdown( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Initialize( void) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LegalActionSpace( 
            /* [retval][out] */ SAFEARRAY * *rgActions) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_MinimalActionSpace( 
            /* [retval][out] */ SAFEARRAY * *rgActions) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRAMData( 
            /* [retval][out] */ SAFEARRAY * *rgData) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_EnableTerminateOnRallyEnd( 
            /* [in] */ VARIANT_BOOL bEnable) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_EnableTerminateOnRallyEnd( 
            /* [retval][out] */ VARIANT_BOOL *pbEnable) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AllowNegativeRewards( 
            /* [in] */ VARIANT_BOOL bEnable) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AllowNegativeRewards( 
            /* [retval][out] */ VARIANT_BOOL *pbEnable) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IALEVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IALE * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IALE * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IALE * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IALE * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IALE * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IALE * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IALE * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IALE, Load)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            IALE * This,
            /* [in] */ BSTR bstrGameROM);
        
        DECLSPEC_XFGVIRT(IALE, put_EnableSound)
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EnableSound )( 
            IALE * This,
            /* [in] */ VARIANT_BOOL bEnable);
        
        DECLSPEC_XFGVIRT(IALE, get_EnableSound)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EnableSound )( 
            IALE * This,
            /* [retval][out] */ VARIANT_BOOL *pbEnable);
        
        DECLSPEC_XFGVIRT(IALE, put_EnableDisplayScreen)
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EnableDisplayScreen )( 
            IALE * This,
            /* [in] */ VARIANT_BOOL bEnable);
        
        DECLSPEC_XFGVIRT(IALE, get_EnableDisplayScreen)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EnableDisplayScreen )( 
            IALE * This,
            /* [retval][out] */ VARIANT_BOOL *pbEnable);
        
        DECLSPEC_XFGVIRT(IALE, put_RandomSeed)
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_RandomSeed )( 
            IALE * This,
            /* [in] */ int nSeed);
        
        DECLSPEC_XFGVIRT(IALE, get_RandomSeed)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_RandomSeed )( 
            IALE * This,
            /* [retval][out] */ int *pnSeed);
        
        DECLSPEC_XFGVIRT(IALE, put_RepeatActionProbability)
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_RepeatActionProbability )( 
            IALE * This,
            /* [in] */ float fProb);
        
        DECLSPEC_XFGVIRT(IALE, get_RepeatActionProbability)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_RepeatActionProbability )( 
            IALE * This,
            /* [retval][out] */ float *pfProb);
        
        DECLSPEC_XFGVIRT(IALE, get_ActionSpace)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActionSpace )( 
            IALE * This,
            /* [retval][out] */ SAFEARRAY * *rgActions);
        
        DECLSPEC_XFGVIRT(IALE, get_GameOver)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_GameOver )( 
            IALE * This,
            /* [retval][out] */ VARIANT_BOOL *pbGameOver);
        
        DECLSPEC_XFGVIRT(IALE, Act)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Act )( 
            IALE * This,
            /* [in] */ ACTION action,
            /* [retval][out] */ float *pfReward);
        
        DECLSPEC_XFGVIRT(IALE, ResetGame)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetGame )( 
            IALE * This);
        
        DECLSPEC_XFGVIRT(IALE, put_MaxNumFrames)
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_MaxNumFrames )( 
            IALE * This,
            /* [in] */ int nMax);
        
        DECLSPEC_XFGVIRT(IALE, get_MaxNumFrames)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MaxNumFrames )( 
            IALE * This,
            /* [retval][out] */ int *pnMax);
        
        DECLSPEC_XFGVIRT(IALE, GetScreenData)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetScreenData )( 
            IALE * This,
            /* [in] */ COLORTYPE clrType,
            /* [retval][out] */ SAFEARRAY * *rgData);
        
        DECLSPEC_XFGVIRT(IALE, GetScreenDimensions)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetScreenDimensions )( 
            IALE * This,
            /* [out] */ float *pfWidth,
            /* [out] */ float *pfHeight);
        
        DECLSPEC_XFGVIRT(IALE, put_EnableRestrictedActionSet)
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EnableRestrictedActionSet )( 
            IALE * This,
            /* [in] */ VARIANT_BOOL bEnable);
        
        DECLSPEC_XFGVIRT(IALE, get_EnableRestrictedActionSet)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EnableRestrictedActionSet )( 
            IALE * This,
            /* [retval][out] */ VARIANT_BOOL *pbEnable);
        
        DECLSPEC_XFGVIRT(IALE, put_EnableColorData)
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EnableColorData )( 
            IALE * This,
            /* [in] */ VARIANT_BOOL bEnable);
        
        DECLSPEC_XFGVIRT(IALE, get_EnableColorData)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EnableColorData )( 
            IALE * This,
            /* [retval][out] */ VARIANT_BOOL *pbEnable);
        
        DECLSPEC_XFGVIRT(IALE, put_EnableColorAveraging)
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EnableColorAveraging )( 
            IALE * This,
            /* [in] */ VARIANT_BOOL bEnable);
        
        DECLSPEC_XFGVIRT(IALE, get_EnableColorAveraging)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EnableColorAveraging )( 
            IALE * This,
            /* [retval][out] */ VARIANT_BOOL *pbEnable);
        
        DECLSPEC_XFGVIRT(IALE, Shutdown)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Shutdown )( 
            IALE * This);
        
        DECLSPEC_XFGVIRT(IALE, Initialize)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IALE * This);
        
        DECLSPEC_XFGVIRT(IALE, get_LegalActionSpace)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LegalActionSpace )( 
            IALE * This,
            /* [retval][out] */ SAFEARRAY * *rgActions);
        
        DECLSPEC_XFGVIRT(IALE, get_MinimalActionSpace)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MinimalActionSpace )( 
            IALE * This,
            /* [retval][out] */ SAFEARRAY * *rgActions);
        
        DECLSPEC_XFGVIRT(IALE, GetRAMData)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetRAMData )( 
            IALE * This,
            /* [retval][out] */ SAFEARRAY * *rgData);
        
        DECLSPEC_XFGVIRT(IALE, put_EnableTerminateOnRallyEnd)
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EnableTerminateOnRallyEnd )( 
            IALE * This,
            /* [in] */ VARIANT_BOOL bEnable);
        
        DECLSPEC_XFGVIRT(IALE, get_EnableTerminateOnRallyEnd)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EnableTerminateOnRallyEnd )( 
            IALE * This,
            /* [retval][out] */ VARIANT_BOOL *pbEnable);
        
        DECLSPEC_XFGVIRT(IALE, put_AllowNegativeRewards)
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AllowNegativeRewards )( 
            IALE * This,
            /* [in] */ VARIANT_BOOL bEnable);
        
        DECLSPEC_XFGVIRT(IALE, get_AllowNegativeRewards)
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AllowNegativeRewards )( 
            IALE * This,
            /* [retval][out] */ VARIANT_BOOL *pbEnable);
        
        END_INTERFACE
    } IALEVtbl;

    interface IALE
    {
        CONST_VTBL struct IALEVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IALE_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IALE_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IALE_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IALE_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IALE_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IALE_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IALE_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IALE_Load(This,bstrGameROM)	\
    ( (This)->lpVtbl -> Load(This,bstrGameROM) ) 

#define IALE_put_EnableSound(This,bEnable)	\
    ( (This)->lpVtbl -> put_EnableSound(This,bEnable) ) 

#define IALE_get_EnableSound(This,pbEnable)	\
    ( (This)->lpVtbl -> get_EnableSound(This,pbEnable) ) 

#define IALE_put_EnableDisplayScreen(This,bEnable)	\
    ( (This)->lpVtbl -> put_EnableDisplayScreen(This,bEnable) ) 

#define IALE_get_EnableDisplayScreen(This,pbEnable)	\
    ( (This)->lpVtbl -> get_EnableDisplayScreen(This,pbEnable) ) 

#define IALE_put_RandomSeed(This,nSeed)	\
    ( (This)->lpVtbl -> put_RandomSeed(This,nSeed) ) 

#define IALE_get_RandomSeed(This,pnSeed)	\
    ( (This)->lpVtbl -> get_RandomSeed(This,pnSeed) ) 

#define IALE_put_RepeatActionProbability(This,fProb)	\
    ( (This)->lpVtbl -> put_RepeatActionProbability(This,fProb) ) 

#define IALE_get_RepeatActionProbability(This,pfProb)	\
    ( (This)->lpVtbl -> get_RepeatActionProbability(This,pfProb) ) 

#define IALE_get_ActionSpace(This,rgActions)	\
    ( (This)->lpVtbl -> get_ActionSpace(This,rgActions) ) 

#define IALE_get_GameOver(This,pbGameOver)	\
    ( (This)->lpVtbl -> get_GameOver(This,pbGameOver) ) 

#define IALE_Act(This,action,pfReward)	\
    ( (This)->lpVtbl -> Act(This,action,pfReward) ) 

#define IALE_ResetGame(This)	\
    ( (This)->lpVtbl -> ResetGame(This) ) 

#define IALE_put_MaxNumFrames(This,nMax)	\
    ( (This)->lpVtbl -> put_MaxNumFrames(This,nMax) ) 

#define IALE_get_MaxNumFrames(This,pnMax)	\
    ( (This)->lpVtbl -> get_MaxNumFrames(This,pnMax) ) 

#define IALE_GetScreenData(This,clrType,rgData)	\
    ( (This)->lpVtbl -> GetScreenData(This,clrType,rgData) ) 

#define IALE_GetScreenDimensions(This,pfWidth,pfHeight)	\
    ( (This)->lpVtbl -> GetScreenDimensions(This,pfWidth,pfHeight) ) 

#define IALE_put_EnableRestrictedActionSet(This,bEnable)	\
    ( (This)->lpVtbl -> put_EnableRestrictedActionSet(This,bEnable) ) 

#define IALE_get_EnableRestrictedActionSet(This,pbEnable)	\
    ( (This)->lpVtbl -> get_EnableRestrictedActionSet(This,pbEnable) ) 

#define IALE_put_EnableColorData(This,bEnable)	\
    ( (This)->lpVtbl -> put_EnableColorData(This,bEnable) ) 

#define IALE_get_EnableColorData(This,pbEnable)	\
    ( (This)->lpVtbl -> get_EnableColorData(This,pbEnable) ) 

#define IALE_put_EnableColorAveraging(This,bEnable)	\
    ( (This)->lpVtbl -> put_EnableColorAveraging(This,bEnable) ) 

#define IALE_get_EnableColorAveraging(This,pbEnable)	\
    ( (This)->lpVtbl -> get_EnableColorAveraging(This,pbEnable) ) 

#define IALE_Shutdown(This)	\
    ( (This)->lpVtbl -> Shutdown(This) ) 

#define IALE_Initialize(This)	\
    ( (This)->lpVtbl -> Initialize(This) ) 

#define IALE_get_LegalActionSpace(This,rgActions)	\
    ( (This)->lpVtbl -> get_LegalActionSpace(This,rgActions) ) 

#define IALE_get_MinimalActionSpace(This,rgActions)	\
    ( (This)->lpVtbl -> get_MinimalActionSpace(This,rgActions) ) 

#define IALE_GetRAMData(This,rgData)	\
    ( (This)->lpVtbl -> GetRAMData(This,rgData) ) 

#define IALE_put_EnableTerminateOnRallyEnd(This,bEnable)	\
    ( (This)->lpVtbl -> put_EnableTerminateOnRallyEnd(This,bEnable) ) 

#define IALE_get_EnableTerminateOnRallyEnd(This,pbEnable)	\
    ( (This)->lpVtbl -> get_EnableTerminateOnRallyEnd(This,pbEnable) ) 

#define IALE_put_AllowNegativeRewards(This,bEnable)	\
    ( (This)->lpVtbl -> put_AllowNegativeRewards(This,bEnable) ) 

#define IALE_get_AllowNegativeRewards(This,pbEnable)	\
    ( (This)->lpVtbl -> get_AllowNegativeRewards(This,pbEnable) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IALE_INTERFACE_DEFINED__ */



#ifndef __AleControlLib_LIBRARY_DEFINED__
#define __AleControlLib_LIBRARY_DEFINED__

/* library AleControlLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_AleControlLib;

#ifndef ___IALEEvents_DISPINTERFACE_DEFINED__
#define ___IALEEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IALEEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IALEEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("E3B7A4A8-724E-4343-9F6E-3FC54653D480")
    _IALEEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IALEEventsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IALEEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IALEEvents * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IALEEvents * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IALEEvents * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IALEEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IALEEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IALEEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _IALEEventsVtbl;

    interface _IALEEvents
    {
        CONST_VTBL struct _IALEEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IALEEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IALEEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IALEEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IALEEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IALEEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IALEEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IALEEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IALEEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ALE;

#ifdef __cplusplus

class DECLSPEC_UUID("BEF72533-C14E-409A-886C-E73FC55A1969")
ALE;
#endif
#endif /* __AleControlLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize64(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal64(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal64(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree64(     unsigned long *, LPSAFEARRAY * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



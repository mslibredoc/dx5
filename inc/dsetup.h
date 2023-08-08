/*==========================================================================
 *
 *  Copyright (C) 1995-1997 Microsoft Corporation.  All Rights Reserved.
 *
 *  File:       dsetup.h
 *  Content:    DirectXSetup, error codes and flags
 ***************************************************************************/

#ifndef __DSETUP_H__
#define __DSETUP_H__

#include <windows.h>      // windows stuff

#ifdef _WIN32
#define COM_NO_WINDOWS_H
#include <objbase.h>
#else
#endif


#ifdef __cplusplus
extern "C" {
#endif

/** @name DirectX Setup Error Codes*/
//!@{
#define DSETUPERR_SUCCESS_RESTART        1
#define DSETUPERR_SUCCESS                0
#define DSETUPERR_BADWINDOWSVERSION     -1
#define DSETUPERR_SOURCEFILENOTFOUND    -2
#define DSETUPERR_BADSOURCESIZE         -3
#define DSETUPERR_BADSOURCETIME         -4
#define DSETUPERR_NOCOPY                -5
#define DSETUPERR_OUTOFDISKSPACE        -6
#define DSETUPERR_CANTFINDINF           -7
#define DSETUPERR_CANTFINDDIR           -8
#define DSETUPERR_INTERNAL              -9
#define DSETUPERR_NTWITHNO3D            -10  /*!< REM: obsolete, you'll never see this */
#define DSETUPERR_UNKNOWNOS             -11
#define DSETUPERR_USERHITCANCEL         -12
#define DSETUPERR_NOTPREINSTALLEDONNT   -13
//!@}

// DSETUP flags. DirectX 5.0 apps should use these flags only.
#define DSETUP_DDRAWDRV         0x00000008      /*!< install DirectDraw Drivers           */
#define DSETUP_DSOUNDDRV        0x00000010      /*!< install DirectSound Drivers          */
#define DSETUP_DXCORE           0x00010000	/*!< install DirectX runtime              */
#define DSETUP_DIRECTX  (DSETUP_DXCORE|DSETUP_DDRAWDRV|DSETUP_DSOUNDDRV)
#define DSETUP_TESTINSTALL      0x00020000      /*!< just test install, don't do anything */

// These OBSOLETE flags are here for compatibility with pre-DX5 apps only.
// They are present to allow DX3 apps to be recompiled with DX5 and still work.
// DO NOT USE THEM for DX5. They will go away in future DX releases.
#define DSETUP_DDRAW            0x00000001      /*!< OBSOLETE. install DirectDraw           */
#define DSETUP_DSOUND           0x00000002      /*!< OBSOLETE. install DirectSound          */
#define DSETUP_DPLAY            0x00000004      /*!< OBSOLETE. install DirectPlay           */
#define DSETUP_DPLAYSP          0x00000020      /*!< OBSOLETE. install DirectPlay Providers */
#define DSETUP_DVIDEO           0x00000040      /*!< OBSOLETE. install DirectVideo          */
#define DSETUP_D3D              0x00000200      /*!< OBSOLETE. install Direct3D             */
#define DSETUP_DINPUT           0x00000800      /*!< OBSOLETE. install DirectInput          */
#define DSETUP_DIRECTXSETUP     0x00001000      /*!< OBSOLETE. install DirectXSetup DLL's   */
#define DSETUP_NOUI             0x00002000      /*!< OBSOLETE. install DirectX with NO UI   */
#define DSETUP_PROMPTFORDRIVERS 0x10000000      /*!< OBSOLETE. prompt when replacing display/audio drivers */
#define DSETUP_RESTOREDRIVERS   0x20000000      /*!< OBSOLETE. restore display/audio drivers */



//******************************************************************
// DirectX Setup Callback mechanism
//******************************************************************

// DSETUP Message Info Codes, passed to callback as Reason parameter.
#define DSETUP_CB_MSG_NOMESSAGE                     0
#define DSETUP_CB_MSG_CANTINSTALL_UNKNOWNOS         1
#define DSETUP_CB_MSG_CANTINSTALL_NT                2
#define DSETUP_CB_MSG_CANTINSTALL_BETA              3
#define DSETUP_CB_MSG_CANTINSTALL_NOTWIN32          4
#define DSETUP_CB_MSG_CANTINSTALL_WRONGLANGUAGE     5
#define DSETUP_CB_MSG_CANTINSTALL_WRONGPLATFORM     6
#define DSETUP_CB_MSG_PREINSTALL_NT                 7
#define DSETUP_CB_MSG_NOTPREINSTALLEDONNT           8
#define DSETUP_CB_MSG_SETUP_INIT_FAILED             9
#define DSETUP_CB_MSG_INTERNAL_ERROR                10
#define DSETUP_CB_MSG_CHECK_DRIVER_UPGRADE          11
#define DSETUP_CB_MSG_OUTOFDISKSPACE                12
#define DSETUP_CB_MSG_BEGIN_INSTALL                 13
#define DSETUP_CB_MSG_BEGIN_INSTALL_RUNTIME         14
#define DSETUP_CB_MSG_BEGIN_INSTALL_DRIVERS         15
#define DSETUP_CB_MSG_BEGIN_RESTORE_DRIVERS         16
#define DSETUP_CB_MSG_FILECOPYERROR                 17


#define DSETUP_CB_UPGRADE_TYPE_MASK             0x000F
#define DSETUP_CB_UPGRADE_KEEP                  0x0001
#define DSETUP_CB_UPGRADE_SAFE                  0x0002
#define DSETUP_CB_UPGRADE_FORCE                 0x0004
#define DSETUP_CB_UPGRADE_UNKNOWN               0x0008

#define DSETUP_CB_UPGRADE_HASWARNINGS           0x0100
#define DSETUP_CB_UPGRADE_CANTBACKUP            0x0200

#define DSETUP_CB_UPGRADE_DEVICE_ACTIVE         0x0800

#define DSETUP_CB_UPGRADE_DEVICE_DISPLAY        0x1000
#define DSETUP_CB_UPGRADE_DEVICE_MEDIA          0x2000


typedef struct _DSETUP_CB_UPGRADEINFO
{
    DWORD UpgradeFlags;
} DSETUP_CB_UPGRADEINFO;

typedef struct _DSETUP_CB_FILECOPYERROR
{
    DWORD dwError;
} DSETUP_CB_FILECOPYERROR;


//
// Data Structures
//
//! @brief Contains the registry entries needed for applications designed to work with DirectPlayLobby. (ANSI only)
typedef struct _DIRECTXREGISTERAPPA {
    DWORD    dwSize; //!< Size of the structure. Must be initialized to the size of the DirectXRegisterAppA structure.
    DWORD    dwFlags; //!< Reserved for future use.
    LPSTR    lpszApplicationName; //!< Name of the application.
    LPGUID   lpGUID; //!< Globally unique identifier (GUID) of the application.
    LPSTR    lpszFilename; //!< Name of the executable file to be called.
    LPSTR    lpszCommandLine; //!< Command-line arguments for the executable file.
    LPSTR    lpszPath; //!< Path of the executable file.
    LPSTR    lpszCurrentDirectory; //!< Current directory. This is typically the same as lpszPath.
} DIRECTXREGISTERAPPA, *PDIRECTXREGISTERAPPA, *LPDIRECTXREGISTERAPPA;

//! @brief Contains the registry entries needed for applications designed to work with DirectPlayLobby. (Unicode only)
typedef struct _DIRECTXREGISTERAPPW {
    DWORD    dwSize; //!< Size of the structure. Must be initialized to the size of the DirectXRegisterAppW structure.
    DWORD    dwFlags; //!< Reserved for future use.
    LPWSTR    lpszApplicationName; //!< Name of the application.
    LPGUID   lpGUID; //!< Globally unique identifier (GUID) of the application.
    LPWSTR    lpszFilename; //!< Name of the executable file to be called.
    LPWSTR    lpszCommandLine; //!< Command-line arguments for the executable file.
    LPWSTR    lpszPath; //!< Path of the executable file.
    LPWSTR    lpszCurrentDirectory; //!< Current directory. This is typically the same as lpszPath.
} DIRECTXREGISTERAPPW, *PDIRECTXREGISTERAPPW, *LPDIRECTXREGISTERAPPW;

typedef DIRECTXREGISTERAPPW DIRECTXREGISTERAPP;
typedef PDIRECTXREGISTERAPPW PDIRECTXREGISTERAPP;
typedef LPDIRECTXREGISTERAPPW LPDIRECTXREGISTERAPP;
typedef DIRECTXREGISTERAPPA DIRECTXREGISTERAPP;
typedef PDIRECTXREGISTERAPPA PDIRECTXREGISTERAPP;
typedef LPDIRECTXREGISTERAPPA LPDIRECTXREGISTERAPP;
#endif // UNICODE


//
// API
//
INT
WINAPI
DirectXSetupA(
    HWND  hWnd,
    LPSTR lpszRootPath,
    DWORD dwFlags
    );
INT
WINAPI
DirectXSetupW(
    HWND   hWnd,
    LPWSTR lpszRootPath,
    DWORD  dwFlags
    );
#define DirectXSetup  DirectXSetupW
#define DirectXSetup  DirectXSetupA

INT
WINAPI
DirectXDeviceDriverSetupA(
    HWND  hWnd,
    LPSTR lpszDriverClass,
    LPSTR lpszDriverPath,
    DWORD dwFlags
    );

INT
WINAPI
DirectXDeviceDriverSetupW(
    HWND   hWnd,
    LPWSTR lpszDriverClass,
    LPWSTR lpszDriverPath,
    DWORD  dwFlags
    );

#define DirectXDeviceDriverSetup  DirectXDeviceDriverSetupW
#define DirectXDeviceDriverSetup  DirectXDeviceDriverSetupA


//! @brief Registers an application as one designed to work with DirectPlayLobby. (ANSI only)
INT
WINAPI
DirectXRegisterApplicationA(
    HWND                  hWnd, //!< Handle to the parent window. If this parameter is set to NULL, the desktop is the parent window.
    LPDIRECTXREGISTERAPPA lpDXRegApp //!< Address of the DIRECTXREGISTERAPP structure that contains the registry entries that are required for the application to function properly with DirectPlayLobby
    //! @returns If the function succeeds, the return value is TRUE meaning that the registration is successfully deleted.
    //! @returns If the function fails, the return value is FALSE.
    //! @remark The DirectXRegisterApplication function inserts the registry entries needed for an application to operate with DirectPlayLobby. If these registry entries are added with DirectXRegisterApplication, they should be removed with DirectXUnRegisterApplication when the application is uninstalled. 
    //! @remark Many commercial install programs will remove registry entries automatically when a program in uninstalled. However, such a program will only do so if it added the registry entries itself. If the DirectPlayLobby registry entries are added by DirectXRegisterApplication, commercial install programs will not delete the registry entries when the application is uninstalled. Therefore, DirectPlayLobby registry entries that are created by DirectXRegisterApplication should be deleted by DirectXUnRegisterApplication.
    //! @remark Registry entries needed for DirectPlayLobby access can be created without the use of the DirectXRegisterApplication function. This, however, is not generally recommended. See Registering Lobby-able Applications in the DirectPlay® documentation.
    //! @see DirectXUnRegisterApplication
    );
//! @brief Registers an application as one designed to work with DirectPlayLobby. (Unicode only)
INT
WINAPI
DirectXRegisterApplicationW(
    HWND                  hWnd, //!< Handle to the parent window. If this parameter is set to NULL, the desktop is the parent window.
    LPDIRECTXREGISTERAPPA lpDXRegApp //!< Address of the DIRECTXREGISTERAPP structure that contains the registry entries that are required for the application to function properly with DirectPlayLobby
    //! @returns If the function succeeds, the return value is TRUE meaning that the registration is successfully deleted.
    //! @returns If the function fails, the return value is FALSE.
    //! @remark The DirectXRegisterApplication function inserts the registry entries needed for an application to operate with DirectPlayLobby. If these registry entries are added with DirectXRegisterApplication, they should be removed with DirectXUnRegisterApplication when the application is uninstalled. 
    //! @remark Many commercial install programs will remove registry entries automatically when a program in uninstalled. However, such a program will only do so if it added the registry entries itself. If the DirectPlayLobby registry entries are added by DirectXRegisterApplication, commercial install programs will not delete the registry entries when the application is uninstalled. Therefore, DirectPlayLobby registry entries that are created by DirectXRegisterApplication should be deleted by DirectXUnRegisterApplication.
    //! @remark Registry entries needed for DirectPlayLobby access can be created without the use of the DirectXRegisterApplication function. This, however, is not generally recommended. See Registering Lobby-able Applications in the DirectPlay® documentation.
    //! @see DirectXUnRegisterApplication
    );

#define DirectXRegisterApplication  DirectXRegisterApplicationW
#define DirectXRegisterApplication  DirectXRegisterApplicationA

//! @brief Deletes the registration of an application designed to work with DirectPlayLobby.
INT
WINAPI
DirectXUnRegisterApplication(
    HWND     hWnd, //!< Handle to the parent window. Set this to NULL if the desktop is the parent window.
    LPGUID   lpGUID //!< Pointer to a GUID that represents the DirectPlay application to be unregistered.
    //! @returns If the function succeeds, the return value is TRUE meaning that the registration is successfully deleted.
    //! @returns If the function fails, the return value is FALSE.
    //! @remark The DirectXUnRegisterApplication function removes registry the entries needed for an application to work with DirectPlayLobby. An uninstall program should only use DirectXUnRegisterApplication if it used DirectXRegisterApplication when the application was installed.
    //! @see DirectXRegisterApplication
    );

//
// Function Pointers
//
typedef INT (WINAPI * LPDIRECTXSETUP)(HWND, LPWSTR, DWORD);
typedef INT (WINAPI * LPDIRECTXDEVICEDRIVERSETUP)(HWND, LPWSTR, LPSTR, DWORD);
typedef INT (WINAPI * LPDIRECTXREGISTERAPPLICATION)(HWND, LPDIRECTXREGISTERAPPW);
typedef INT (WINAPI * LPDIRECTXSETUP)(HWND, LPSTR, DWORD);
typedef INT (WINAPI * LPDIRECTXDEVICEDRIVERSETUP)(HWND, LPSTR, LPSTR, DWORD);
typedef INT (WINAPI * LPDIRECTXREGISTERAPPLICATION)(HWND, LPDIRECTXREGISTERAPPA);
#endif

typedef DWORD (FAR PASCAL * DSETUP_CALLBACK)(DWORD Reason,
                                  DWORD MsgType,       /*! Same as flags to MessageBox */
                                  LPSTR szMessage,
                                  LPSTR szName,
                                  void *pInfo);

INT WINAPI DirectXSetupSetCallback(DSETUP_CALLBACK Callback);
INT WINAPI DirectXSetupGetVersion(DWORD *lpdwVersion, DWORD *lpdwMinorVersion);


#ifdef __cplusplus
};
#endif

#endif

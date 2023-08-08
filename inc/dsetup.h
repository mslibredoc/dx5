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

/** @defgroup dxsetuperrcodes DirectX Setup Error Codes
 * Apparently "must remain compatible with previous setup."
 */
//!@{
#define DSETUPERR_SUCCESS_RESTART        1 //!< Setup was successful and a restart is required.
#define DSETUPERR_SUCCESS                0 //!< Setup was successful and no restart is required. 
#define DSETUPERR_BADWINDOWSVERSION     -1 //!< DirectX does not support the Windows version on the system.
#define DSETUPERR_SOURCEFILENOTFOUND    -2 //!< One of the required source files could not be found.
#define DSETUPERR_BADSOURCESIZE         -3 //!< A file's size could not be verified or was incorrect. 
#define DSETUPERR_BADSOURCETIME         -4 //!< A file's date and time could not be verified or were incorrect. 
#define DSETUPERR_NOCOPY                -5 //!< A file's version could not be verified or was incorrect. 
#define DSETUPERR_OUTOFDISKSPACE        -6 //!< The setup program ran out of disk space during installation. 
#define DSETUPERR_CANTFINDINF           -7 //!< A required .inf file could not be found. 
#define DSETUPERR_CANTFINDDIR           -8 //!< The setup program could not find the working directory. 
#define DSETUPERR_INTERNAL              -9 //!< An internal error occurred.
//! @remarks According to the header comments, this is "obsolete, you'll never see this".
#define DSETUPERR_NTWITHNO3D            -10 //!< Undocumented flag, but it's in the header file.
#define DSETUPERR_UNKNOWNOS             -11 //!< The operating system on your system is not currently supported. 
#define DSETUPERR_USERHITCANCEL         -12 //!< The Cancel button was pressed before the application was fully installed.
#define DSETUPERR_NOTPREINSTALLEDONNT   -13 //!< The version of Windows NT on the system does not contain the current version of DirectX. An older version of DirectX may be present, or DirectX may be absent altogether.
//!@}

/** @defgroup dxsetupflags DirectX Setup Flags
 * DirectX 5.0 apps should use these flags only.
 */
//!@{
#define DSETUP_DDRAWDRV         0x00000008      //!< Installs display drivers provided by Microsoft.
#define DSETUP_DSOUNDDRV        0x00000010      //!< Installs audio drivers provided by Microsoft.
#define DSETUP_DXCORE           0x00010000	//!< Installs DirectX runtime components. Does not install DirectX-compatible display and audio drivers.
#define DSETUP_DIRECTX  (DSETUP_DXCORE|DSETUP_DDRAWDRV|DSETUP_DSOUNDDRV) //!< Installs DirectX runtime components as well as DirectX-compatible display and audio drivers.
#define DSETUP_TESTINSTALL      0x00020000      //!< Performs a test installation. Does not actually install new components.
//!@}

// These OBSOLETE flags are here for compatibility with pre-DX5 apps only.
// They are present to allow DX3 apps to be recompiled with DX5 and still work.
// DO NOT USE THEM for DX5. They will go away in future DX releases.
// TODO: In the official doc, all of these say DX3 programs that use this will install all DX components. Does this mean doing one of these will necessitate installing all DX components?
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


//! @brief Structure passed as a parameter to the DirectXSetupCallbackFunction.
//! @details It only contains valid information when the Reason parameter is DSETUP_CB_MSG_CHECK_DRIVER_UPGRADE. Callback functions can use it to get status information on the upgrade that is about to be done.
typedef struct _DSETUP_CB_UPGRADEINFO
{
    DWORD UpgradeFlags; //!< A flag indicating the status of the upgrade. See the pInfo parameter of the DirectXSetupCallbackFunction function for details.
    //! @see DirectXSetupCallbackFunction
} DSETUP_CB_UPGRADEINFO;

//! @brief Undocumented, but in the headerfile. Probably a structure passed as a callback to the DirectXSetupCallbackFunction as a 'failed to copy file' error.
//! @remarks This is undocumented. What we know is a guess.
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
//! @brief Installs one or more DirectX components. (ANSI only)
INT
WINAPI
DirectXSetupA(
    HWND  hWnd, //!< Handle to the parent window for the setup dialog boxes.
    LPSTR lpszRootPath, //!< Pointer to a string that contains the root path of the DirectX component files. This string must specify a full path to the directory that contains the files Dsetup.dll, Dsetup16.dll, and Dsetup.dll32. This directory is typically Redist. If you are certain the current directory contains Dsetup.dll and the Directx directory, this parameter can be NULL.
    DWORD dwFlags //!< One or more flags indicating which DirectX components should be installed. A full installation (DSETUP_DIRECTX) is recommended. See @ref dxsetupflags .
    //! @returns If this function is successful, it returns SUCCESS. 
    //! @returns If it is not successful, it returns an error code. For a list of possible return codes, see @ref dxsetuperrcodes .
    //! @remarks According to official docs, "Before you use the DirectXSetup function in your setup program, you should ensure that there is at least 15 MB of available disk space on the user's system. This is the maximum space required for DirectX to set up the appropriate files. If the user's system already contains the DirectX files, this space is not needed."
    );
//! @brief Installs one or more DirectX components. (Unicode only)
INT
WINAPI
DirectXSetupW(
    HWND   hWnd, //!< Handle to the parent window for the setup dialog boxes.
    LPWSTR lpszRootPath, //!< Pointer to a string that contains the root path of the DirectX component files. This string must specify a full path to the directory that contains the files Dsetup.dll, Dsetup16.dll, and Dsetup.dll32. This directory is typically Redist. If you are certain the current directory contains Dsetup.dll and the Directx directory, this parameter can be NULL.
    DWORD  dwFlags  //!< One or more flags indicating which DirectX components should be installed. A full installation (DSETUP_DIRECTX) is recommended. See @ref dxsetupflags .
    //! @returns If this function is successful, it returns SUCCESS. 
    //! @returns If it is not successful, it returns an error code. For a list of possible return codes, see @ref dxsetuperrcodes .
    //! @remarks According to official docs, "Before you use the DirectXSetup function in your setup program, you should ensure that there is at least 15 MB of available disk space on the user's system. This is the maximum space required for DirectX to set up the appropriate files. If the user's system already contains the DirectX files, this space is not needed."
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

//! @brief Sets a pointer to a callback function that is periodically called by DirectXSetup.
//! @details The callback function can be used for setup progress notification and to implement a custom user interface for an application’s setup program. For information on the callback function, see DirectXSetupCallbackFunction. If a setup program does not provide a callback function, the DirectXSetupSetCallback function should not be invoked.
//! @param Callback Pointer to a callback function.
//! @returns The documentation says, "Currently returns zero."
//! @remarks To set a callback function, DirectXSetupSetCallback must be called before the DirectXSetup function is called.
//! @remarks The name of the callback function passed to DirectXSetupSetCallback is supplied by the setup program. However, it must match the prototype given in DirectXSetupCallbackFunction
//! @see DirectXSetupCallbackFunction DirectXSetup
INT WINAPI DirectXSetupSetCallback(DSETUP_CALLBACK Callback);

//! @brief Retrieves the version number of the DirectX components that are currently installed.
//! @param lpdwVersion Receives the version number. Pointer to a DWORD. The DirectXSetupGetVersion function will fill the DWORD with the version number. If this parameter is NULL, it is ignored.
//! @param lpdwMinorVersion Receives the revision number. Pointer to a DWORD. The DirectXSetupGetVersion function will fill the DWORD with the revision number. If this parameter is NULL, it is ignored.
//! @returns If this function is successful, it returns non-zero.
//! @returns If it is not successful, it returns zero.
//! @remarks The DirectXSetupGetVersion function can be used to retrieve the version and revision numbers before or after the DirectXSetup function is called. If it is called before the DirectXSetup function is invoked, it gives the version and revision numbers of the DirectX components that are currently installed. If it is called after the DirectXSetup function is called, but before the computer has been rebooted, it will give the version and revision numbers of the DirectX components that will take effect after the computer is restarted.
//! @remarks The version number in the pdwVersion parameter is composed of the major version number and the minor version number. The major version number will be in the 16 most significant bits of the DWORD when this function returns. The minor version number will be in the 16 least significant bits of the DWORD when this function returns. The version numbers can be interpreted as 0x0x0004000(DirectX version number), so DirectX 1 would be 0x00040001 and so forth.
//! @remarks The version number in the pdwRevision parameter is composed of the release number and the build number. The release number will be in the 16 most significant bits of the DWORD when this function returns. The build number will be in the 16 least significant bits of the DWORD when this function returns.
//! @remarks Version and revision numbers can concatenated into a 64 bit quantity for comparison. The version number should be in the 32 most significant bits and the revision number should be in the 32 least significant bits.
//! @see DirectXSetup
INT WINAPI DirectXSetupGetVersion(DWORD *lpdwVersion, DWORD *lpdwMinorVersion);


#ifdef __cplusplus
};
#endif

#endif

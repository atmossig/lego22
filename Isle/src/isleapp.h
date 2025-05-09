#ifndef ISLEAPP_H
#define ISLEAPP_H

#include "mxtypes.h"
#include "mxvideoparam.h"

// Moved from cpp
#include "3dmanager/lego3dmanager.h"
#include "decomp.h"
#include "legoanimationmanager.h"
#include "legobuildingmanager.h"
#include "legogamestate.h"
#include "legoinputmanager.h"
#include "legomain.h"
#include "legomodelpresenter.h"
#include "legopartpresenter.h"
#include "legoutils.h"
#include "legovideomanager.h"
#include "legoworldpresenter.h"
#include "misc.h"
#include "mxbackgroundaudiomanager.h"
#include "mxdirectx/mxdirect3d.h"
#include "mxdsaction.h"
#include "mxmisc.h"
#include "mxomnicreateflags.h"
#include "mxomnicreateparam.h"
#include "mxstreamer.h"
#include "mxticklemanager.h"
#include "mxtimer.h"
#include "mxtransitionmanager.h"
#include "mxvariabletable.h"
#include "res/resource.h"
#include "roi/legoroi.h"
#include "viewmanager/viewmanager.h"
#include <dsound.h>

#include <windows.h>

// SIZE 0x8c
class IsleApp {
public:
	IsleApp();
	~IsleApp();

	void Close();

	BOOL SetupLegoOmni();
	void SetupVideoFlags(
		BOOL fullScreen,
		BOOL flipSurfaces,
		BOOL backBuffers,
		BOOL using8bit,
		BOOL using16bit,
		BOOL param_6,
		BOOL param_7,
		BOOL wideViewAngle,
		char* deviceId
	);
	MxResult SetupWindow(HINSTANCE hInstance, LPSTR lpCmdLine);

	BOOL ReadReg(LPCSTR name, LPSTR outValue, DWORD outSize);
	BOOL ReadRegBool(LPCSTR name, BOOL* out);
	BOOL ReadRegInt(LPCSTR name, int* out);

	void LoadConfig();
	void Tick(BOOL sleepIfNotNextFrame);
	void SetupCursor(WPARAM wParam);

	HWND GetWindowHandle() { return m_windowHandle; }
	MxLong GetFrameDelta() { return m_frameDelta; }
	BOOL GetFullScreen() { return m_fullScreen; }
	HCURSOR GetCursorCurrent() { return m_cursorCurrent; }
	HCURSOR GetCursorBusy() { return m_cursorBusy; }
	HCURSOR GetCursorNo() { return m_cursorNo; }
	BOOL GetDrawCursor() { return m_drawCursor; }

	void SetWindowActive(BOOL p_windowActive) { m_windowActive = p_windowActive; }

private:
	LPSTR m_hdPath;            // 0x00
	LPSTR m_cdPath;            // 0x04
	LPSTR m_deviceId;          // 0x08
	LPSTR m_savePath;          // 0x0c
	BOOL m_fullScreen;         // 0x10
	BOOL m_flipSurfaces;       // 0x14
	BOOL m_backBuffersInVram;  // 0x18
	BOOL m_using8bit;          // 0x1c
	BOOL m_using16bit;         // 0x20
	int m_unk0x24;             // 0x24
	BOOL m_use3dSound;         // 0x28
	BOOL m_useMusic;           // 0x2c
	BOOL m_useJoystick;        // 0x30
	int m_joystickIndex;       // 0x34
	BOOL m_wideViewAngle;      // 0x38
	int m_islandQuality;       // 0x3c
	int m_islandTexture;       // 0x40
	BOOL m_gameStarted;        // 0x44
	MxLong m_frameDelta;       // 0x48
	MxVideoParam m_videoParam; // 0x4c
	BOOL m_windowActive;       // 0x70
	HWND m_windowHandle;       // 0x74
	BOOL m_drawCursor;         // 0x78
	HCURSOR m_cursorArrow;     // 0x7c
	HCURSOR m_cursorBusy;      // 0x80
	HCURSOR m_cursorNo;        // 0x84
	HCURSOR m_cursorCurrent;   // 0x88
};

#endif // ISLEAPP_H

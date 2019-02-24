#ifndef _KBYS_H_
#define _KBYS_H_
#pragma once
#include <windows.h>
#include <commctrl.h>
#include "resource.h"

#pragma comment (linker, "/subsystem:windows")
#pragma comment (lib, "comctl32")

extern HWND		hWnd;
extern HICON		hIcon;
extern HINSTANCE	hInst;
extern BOOL		bChinese;
extern char		szMessage[32];

///////////////////////////////////////////////////////////////
extern char		szFileName[MAX_PATH];             //�ӿǵ��ļ���
extern LPBYTE		MapOfFile;                        //�����ļ�
extern LPBYTE		MapOfOverlay;                     //��������
extern DWORD		SizeOfOverlay;                    //�������ݴ�С
///////////////////////////////////////////////////////////////
extern BOOL		bDLL;                             //�Ƿ���dll

#endif //_KBYS_H_


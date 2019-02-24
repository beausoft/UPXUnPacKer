#pragma once
#include "KByS.h"
#include "erika.h"
///////////////////////////////////////////////////////////////
HWND		hWnd;
HICON		hIcon;
HINSTANCE	hInst;
BOOL		bChinese;
char		szMessage[32];

///////////////////////////////////////////////////////////////
char		szFileName[MAX_PATH];             //�ӿǵ��ļ���
LPBYTE		MapOfFile;                        //�����ļ�
LPBYTE		MapOfOverlay;                     //��������
DWORD		SizeOfOverlay;                    //�������ݴ�С
///////////////////////////////////////////////////////////////
IMAGE_NT_HEADERS32*		PE;                   //PEͷ
IMAGE_SECTION_HEADER*	SH;                   //������Ϣָ��
BOOL		bDLL;                             //�Ƿ���dll

void SetMainText(BOOL bChs)
{
	if (bChs)
	{
		SetDlgItemText(hWnd, IDC_INFO, "\r\n\r\n ���԰汾! ��Ŀ���Ͻ�������, ��ӭ�������.");
		SendMessage(hWnd, WM_SETTEXT, (WPARAM)0, (LPARAM)"Upx��̬�ѿǻ� ver0.3");
	}
	else
	{
		SetDlgItemText(hWnd, IDC_INFO, "\r\n\r\nTesting Version! drag file here, bug report is welcome.");
		SendMessage(hWnd, WM_SETTEXT, (WPARAM)0, (LPARAM)"Upx Unpacker");
	}
	bChinese = bChs;
}

int CALLBACK DlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break ;
		
	case WM_INITDIALOG:
		hWnd = hDlg;
		hIcon = LoadIcon(hInst, MAKEINTRESOURCE(102));
		SendMessage(hWnd, WM_SETICON, (WPARAM)TRUE, (LPARAM)hIcon);	
		SendMessage(GetDlgItem(hWnd, IDC_CHINESE), BM_SETCHECK, BST_CHECKED, 0);
		
		SetMainText(TRUE);
		break ;

	case WM_DROPFILES:
		if (DragQueryFile((HDROP)wParam, 0, szFileName, MAX_PATH))
		{
			KByS();
			SetDlgItemText(hWnd, IDC_KBYS, szMessage);
		}
		break;
		/*
	case WM_LBUTTONDOWN:
		if (bChinese)
		{
			SetDlgItemText(hWnd, IDC_INFO, "           ܥ��ѹ��\r\n\r\n1. ѹ����Դ\r\n2. ����ض�λ��\r\n3. ������������\r\n4. ֧�ֿ��Ͽ�\r\n5. ���ļ�ק��������");
			bChinese = FALSE;
		}
		else
		{
			SetDlgItemText(hWnd, IDC_INFO, "        KByS Packer\r\n\r\n1. compress RSRC\r\n2. clear relocations\r\n3. reserve extra data\r\n4. support pack repeat\r\n5. drag file here");
			bChinese = TRUE;
		}
		break ;
		*/
	case WM_COMMAND:
		switch (wParam)
		{
		case IDC_CHINESE:
			SetMainText(TRUE);
			break ;
		case IDC_ENGLISH:
			SetMainText(FALSE);
			break ;
		default:
			break ;
		}


	default:
		break;
	}

	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	InitCommonControls();
	hInst = hInstance;
	DialogBox(hInst, MAKEINTRESOURCE(IDD_KBYS), NULL, (DLGPROC)DlgProc);

	return 0;
}


// WindowsProject1.cpp : Definiuje punkt wejścia dla aplikacji.
//

#include "framework.h"
#include "WindowsProject1.h"
#include "ctime"
#include "string"

#define MAX_LOADSTRING 100

// Zmienne globalne:
HINSTANCE hInst;                                // bieżące wystąpienie
WCHAR szTitle[MAX_LOADSTRING];                  // Tekst paska tytułu
WCHAR szWindowClass[MAX_LOADSTRING];            // nazwa klasy okna głównego

HWND hwndButton;

// Przekaż dalej deklaracje funkcji dołączone w tym module kodu:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int AktualnaPozycja = 1;
int osoby[4][10];
int liczbaMasy = 0;

LPCTSTR masa[12] = { L"000", L"070",L"140", L"210", L"280", L"350", L"420", L"490", L"560", L"630", L"700", L"MAX" };

void PrzydzielanieOsob(int osoby[4][10]) {
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 10; y++) {
			osoby[x][y] = rand() % 4;

			if (x == osoby[x][y]) {
				y = y-1;
			}

		}
	}
}

void WyborMasy(int a) {
	if (a == 1) liczbaMasy = liczbaMasy + 1;
	else liczbaMasy = 0;
}

void ktoPojechal(int osoby[4][10], int y1, int y2){
	for (int i = 0; i < 10; i++) {
		if (osoby[y1 - 1][i] == -2) 
				osoby[y1 - 1][i] = -1;
	}
	WyborMasy(0);
}

void ktoJedzie(int osoby[4][10], int y1, int y2) {
	for (int i = 0; i < 10; i++) {
		if (osoby[y1 - 1][i] != -1)
			if (osoby[y1 - 1][i] == y2 - 1) {
				osoby[y1 - 1][i] = -2;
				WyborMasy(1);
			}
	}

}

void rysowanie(HWND hWnd, HDC& hdc, PAINTSTRUCT& ps, int y1, int y2, int osoby[4][10], bool CzyBracOsoby) {

	if (y2 > y1) {
		for (int i = y1 * 100; i < y2 * 100; i++) {
			InvalidateRect(hWnd, NULL, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			HPEN hLinePen;
			COLORREF qLineColor;
			HPEN hPenOld;
			qLineColor = RGB(0, 0, 0);
			hLinePen = CreatePen(PS_SOLID, 2, qLineColor);
			hPenOld = (HPEN)SelectObject(hdc, hLinePen);
			LPCWSTR text = L"masa:";

			//masa text
			TextOut(hdc, 10, 10, text, 5);
			TextOut(hdc, 10, 30, masa[liczbaMasy], 3);

			//platforma
			MoveToEx(hdc, 410, i + 100, NULL);
			LineTo(hdc, 590, i + 100);
			MoveToEx(hdc, 410, i - 10, NULL);
			LineTo(hdc, 590, i - 10);
			MoveToEx(hdc, 410, i + 100, NULL);
			LineTo(hdc, 410, i - 10);
			MoveToEx(hdc, 590, i + 100, NULL);
			LineTo(hdc, 590, i - 10);

			//pierwsze
			MoveToEx(hdc, 100, 200, NULL);
			LineTo(hdc, 400, 200);
			//drugie
			MoveToEx(hdc, 600, 300, NULL);
			LineTo(hdc, 900, 300);
			//trzecie
			MoveToEx(hdc, 100, 400, NULL);
			LineTo(hdc, 400, 400);
			//czwarte
			MoveToEx(hdc, 600, 500, NULL);
			LineTo(hdc, 900, 500);


			//osoby z 1
			for (int j = 0; j < 10; j++) {
				if (osoby[0][j] > -1) {
					MoveToEx(hdc, 200 + j * 15, 175, NULL);
					LineTo(hdc, 200 + j * 15, 120);
				}
			}
			//przejazd winda z 1
			if (y1 == 1 && CzyBracOsoby==1) {
				for (int j = 0; j < 10;j++) {
					if (osoby[0][j] == -2) {
						MoveToEx(hdc, 420 + j * 15, 75+i, NULL);
						LineTo(hdc, 420 + j * 15, 20+i);
					}
				}
			}


			//osoby z 2
			for (int j = 0; j < 10; j++) {
				if (osoby[1][j] > -1) {
					MoveToEx(hdc, 660 + j * 15, 275, NULL);
					LineTo(hdc, 660 + j * 15, 220);
				}
			}
			//przejazd winda z 2
			if (y1 == 2 && CzyBracOsoby == 1) {
				for (int j = 0; j < 10; j++) {
					if (osoby[1][j] == -2) {
						MoveToEx(hdc, 420 + j * 15, 75 + i, NULL);
						LineTo(hdc, 420 + j * 15, 20 + i);
					}
				}
			}
			//osoby z 3
			for (int j = 0; j < 10; j++) {
				if (osoby[2][j] > -1) {
					MoveToEx(hdc, 200 + j * 15, 375, NULL);
					LineTo(hdc, 200 + j * 15, 320);
				}
			}
			//przejazd winda z 3
			if (y1 == 3 && CzyBracOsoby == 1) {
				for (int j = 0; j < 10; j++) {
					if (osoby[2][j] == -2) {
						MoveToEx(hdc, 420 + j * 15, 75 + i, NULL);
						LineTo(hdc, 420 + j * 15, 20 + i);
					}
				}
			}
			//osoby z 4       
			for (int j = 0; j < 10; j++) {
				if (osoby[3][j] > -1) {
					MoveToEx(hdc, 660 + j * 15, 475, NULL);
					LineTo(hdc, 660 + j * 15, 420);
				}
			}
			//przejazd winda z 4
			if (y1 == 4 && CzyBracOsoby == 1) {
				for (int j = 0; j < 10; j++) {
					if (osoby[3][j] == -2) {
						MoveToEx(hdc, 420 + j * 15, 75 + i, NULL);
						LineTo(hdc, 420 + j * 15, 20 + i);
					}
				}
			}
			SelectObject(hdc, hPenOld);
			DeleteObject(hLinePen);

			EndPaint(hWnd, &ps);
			Sleep(1);
		}
	}
	else {
		for (int i = y1 * 100; i > y2 * 100; i--) {
			InvalidateRect(hWnd, NULL, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			HPEN hLinePen;
			COLORREF qLineColor;
			HPEN hPenOld;
			qLineColor = RGB(0, 0, 0);
			hLinePen = CreatePen(PS_SOLID, 2, qLineColor);
			hPenOld = (HPEN)SelectObject(hdc, hLinePen);
			LPCWSTR text = L"masa:";

			//masa text
			TextOut(hdc, 10, 10, text, 5);
			TextOut(hdc, 10, 30, masa[liczbaMasy], 3);

			//platforma
			MoveToEx(hdc, 410, i + 100, NULL);
			LineTo(hdc, 590, i + 100);
			MoveToEx(hdc, 410, i - 10, NULL);
			LineTo(hdc, 590, i - 10);
			MoveToEx(hdc, 410, i + 100, NULL);
			LineTo(hdc, 410, i - 10);
			MoveToEx(hdc, 590, i + 100, NULL);
			LineTo(hdc, 590, i - 10);

			//pierwsze
			MoveToEx(hdc, 100, 200, NULL);
			LineTo(hdc, 400, 200);
			//drugie
			MoveToEx(hdc, 600, 300, NULL);
			LineTo(hdc, 900, 300);
			//trzecie
			MoveToEx(hdc, 100, 400, NULL);
			LineTo(hdc, 400, 400);
			//czwarte
			MoveToEx(hdc, 600, 500, NULL);
			LineTo(hdc, 900, 500);


			//osoby z 1
			for (int j = 0; j < 10; j++) {
				if (osoby[0][j] > -1) {
					MoveToEx(hdc, 200 + j * 15, 175, NULL);
					LineTo(hdc, 200 + j * 15, 120);
				}
			}
			//przejazd winda z 1
			if (y1 == 1 && CzyBracOsoby == 1) {
				for (int j = 0; j < 10; j++) {
					if (osoby[0][j] == -2) {
						MoveToEx(hdc, 420 + j * 15, 75 + i, NULL);
						LineTo(hdc, 420 + j * 15, 20 + i);
					}
				}
			}


			//osoby z 2
			for (int j = 0; j < 10; j++) {
				if (osoby[1][j] > -1) {
					MoveToEx(hdc, 660 + j * 15, 275, NULL);
					LineTo(hdc, 660 + j * 15, 220);
				}
			}
			//przejazd winda z 2
			if (y1 == 2 && CzyBracOsoby == 1) {
				for (int j = 0; j < 10; j++) {
					if (osoby[1][j] == -2) {
						MoveToEx(hdc, 420 + j * 15, 75 + i, NULL);
						LineTo(hdc, 420 + j * 15, 20 + i);
					}
				}
			}
			//osoby z 3
			for (int j = 0; j < 10; j++) {
				if (osoby[2][j] > -1) {
					MoveToEx(hdc, 200 + j * 15, 375, NULL);
					LineTo(hdc, 200 + j * 15, 320);
				}
			}
			//przejazd winda z 3
			if (y1 == 3 && CzyBracOsoby == 1) {
				for (int j = 0; j < 10; j++) {
					if (osoby[2][j] == -2) {
						MoveToEx(hdc, 420 + j * 15, 75 + i, NULL);
						LineTo(hdc, 420 + j * 15, 20 + i);
					}
				}
			}
			//osoby z 4       
			for (int j = 0; j < 10; j++) {
				if (osoby[3][j] > -1) {
					MoveToEx(hdc, 660 + j * 15, 475, NULL);
					LineTo(hdc, 660 + j * 15, 420);
				}
			}
			//przejazd winda z 4
			if (y1 == 4 && CzyBracOsoby == 1) {
				for (int j = 0; j < 10; j++) {
					if (osoby[3][j] == -2) {
						MoveToEx(hdc, 420 + j * 15, 75 + i, NULL);
						LineTo(hdc, 420 + j * 15, 20 + i);
					}
				}
			}
			SelectObject(hdc, hPenOld);
			DeleteObject(hLinePen);

			EndPaint(hWnd, &ps);
			Sleep(1);
		}
	}
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: W tym miejscu umieść kod.

	srand(time(0));
	PrzydzielanieOsob(osoby);
	WyborMasy(0);

	// Inicjuj ciągi globalne
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Wykonaj inicjowanie aplikacji:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));

	MSG msg;

	// Główna pętla komunikatów:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  FUNKCJA: MyRegisterClass()
//
//  PRZEZNACZENIE: Rejestruje klasę okna.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   FUNKCJA: InitInstance(HINSTANCE, int)
//
//   PRZEZNACZENIE: Zapisuje dojście wystąpienia i tworzy okno główne
//
//   KOMENTARZE:
//
//        W tej funkcji dojście wystąpienia jest zapisywane w zmiennej globalnej i
//        jest tworzone i wyświetlane okno główne programu.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;


	hInst = hInstance; // Store instance handle (of exe) in our global variable

	// main window
	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	// create button and store the handle                                                       

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("2"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		100, 50,                                  // the left and top co-ordinates
		30, 30,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON12,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("1"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		100, 85,                                  // the left and top co-ordinates
		30, 30,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON13,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("0"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		100, 120,                                  // the left and top co-ordinates
		30, 30,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON14,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);



	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("3"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		850, 120,                                  // the left and top co-ordinates
		30, 30,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON21,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("1"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		850, 190,                                  // the left and top co-ordinates
		30, 30,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON23,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("0"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		850, 225,                                  // the left and top co-ordinates
		30, 30,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON24,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);


	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("3"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		100, 240,                                  // the left and top co-ordinates
		30, 30,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON31,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("2"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		100, 275,                                  // the left and top co-ordinates
		30, 30,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON32,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("0"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		100, 345,                                  // the left and top co-ordinates
		30, 30,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON34,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);



	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("3"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		850, 340,                                  // the left and top co-ordinates
		30, 30,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON41,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("2"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		850, 375,                                  // the left and top co-ordinates
		30, 30,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON42,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("1"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		850, 410,                                  // the left and top co-ordinates
		30, 30,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON43,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNKCJA: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PRZEZNACZENIE: Przetwarza komunikaty dla okna głównego.
//
//  WM_COMMAND  - przetwarzaj menu aplikacji
//  WM_PAINT    - Maluj okno główne
//  WM_DESTROY  - opublikuj komunikat o wyjściu i wróć
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc, kon;

	LPCWSTR text = L"masa:";

	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Analizuj zaznaczenia menu:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case ID_BUTTON12:
			rysowanie(hWnd, hdc, ps, AktualnaPozycja, 1, osoby,0);
			AktualnaPozycja = 2;
			Sleep(200);
			ktoJedzie(osoby, 1, 2);
			rysowanie(hWnd, hdc, ps, 1, 2, osoby,1);
			ktoPojechal(osoby, 1, 2);
			break;
		case ID_BUTTON13:
			rysowanie(hWnd, hdc, ps, AktualnaPozycja, 1, osoby,0);
			AktualnaPozycja = 3;
			Sleep(200);
			ktoJedzie(osoby, 1, 3);
			rysowanie(hWnd, hdc, ps, 1, 3, osoby,1);
			ktoPojechal(osoby, 1, 3);
			break;
		case ID_BUTTON14:
			rysowanie(hWnd, hdc, ps, AktualnaPozycja, 1, osoby,0);
			AktualnaPozycja = 4;
			Sleep(200);
			ktoJedzie(osoby, 1, 4);
			rysowanie(hWnd, hdc, ps, 1, 4, osoby,1);
			ktoPojechal(osoby, 1, 4);
			break;
		case ID_BUTTON21:
			rysowanie(hWnd, hdc, ps, AktualnaPozycja, 2, osoby,0);
			AktualnaPozycja = 1;
			Sleep(200);
			ktoJedzie(osoby, 2, 1);
			rysowanie(hWnd, hdc, ps, 2, 1, osoby,1);
			ktoPojechal(osoby, 2, 1);
			break;
		case ID_BUTTON23:
			rysowanie(hWnd, hdc, ps, AktualnaPozycja, 2, osoby,0);
			AktualnaPozycja = 3;
			Sleep(200);
			ktoJedzie(osoby, 2, 3);
			rysowanie(hWnd, hdc, ps, 2, 3, osoby,1);
			ktoPojechal(osoby, 2, 3);
			break;
		case ID_BUTTON24:
			rysowanie(hWnd, hdc, ps, AktualnaPozycja, 2, osoby,0);
			AktualnaPozycja = 4;
			Sleep(200);
			ktoJedzie(osoby, 2, 4);
			rysowanie(hWnd, hdc, ps, 2, 4, osoby,1);
			ktoPojechal(osoby, 2, 4);
			break;
		case ID_BUTTON31:
			rysowanie(hWnd, hdc, ps, AktualnaPozycja, 3, osoby,0);
			AktualnaPozycja = 1;
			Sleep(200);
			ktoJedzie(osoby, 3, 1);
			rysowanie(hWnd, hdc, ps, 3, 1, osoby,1);
			ktoPojechal(osoby, 3, 1);
			break;
		case ID_BUTTON32:
			rysowanie(hWnd, hdc, ps, AktualnaPozycja, 3, osoby,0);
			AktualnaPozycja = 2;
			Sleep(200);
			ktoJedzie(osoby, 3, 2);
			rysowanie(hWnd, hdc, ps, 3, 2, osoby,1);
			ktoPojechal(osoby, 3, 2);
			break;
		case ID_BUTTON34:
			rysowanie(hWnd, hdc, ps, AktualnaPozycja, 3, osoby,0);
			AktualnaPozycja = 4;
			Sleep(200);
			ktoJedzie(osoby, 3, 4);
			rysowanie(hWnd, hdc, ps, 3, 4, osoby,1);
			ktoPojechal(osoby, 3, 4);
			break;
		case ID_BUTTON41:
			rysowanie(hWnd, hdc, ps, AktualnaPozycja, 4, osoby,0);
			AktualnaPozycja = 1;
			Sleep(200);
			ktoJedzie(osoby, 4, 1);
			rysowanie(hWnd, hdc, ps, 4, 1, osoby,1);
			ktoPojechal(osoby, 4, 1);
			break;
		case ID_BUTTON42:
			rysowanie(hWnd, hdc, ps, AktualnaPozycja, 4, osoby,0);
			AktualnaPozycja = 2;
			Sleep(200);
			ktoJedzie(osoby, 4, 2);
			rysowanie(hWnd, hdc, ps, 4, 2, osoby,1);
			ktoPojechal(osoby, 4, 2);
			break;
		case ID_BUTTON43:
			rysowanie(hWnd, hdc, ps, AktualnaPozycja, 4, osoby,0);
			AktualnaPozycja = 3;
			Sleep(200);
			ktoJedzie(osoby, 4, 3);
			rysowanie(hWnd, hdc, ps, 4, 3, osoby,1);
			ktoPojechal(osoby, 4, 3);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		HPEN hPenOld;

		TextOut(hdc, 10, 10, text, 5);
		TextOut(hdc, 10, 30, masa[liczbaMasy], 3);

		// 1. pietro
		HPEN pietra;
		COLORREF Color1;
		Color1 = RGB(0, 0, 0);
		pietra = CreatePen(PS_SOLID, 2, Color1);
		hPenOld = (HPEN)SelectObject(hdc, pietra);

		MoveToEx(hdc, 100, 200, NULL);
		LineTo(hdc, 400, 200);

		//platforma
		MoveToEx(hdc, 410, 100 + 100, NULL);
		LineTo(hdc, 590, 100 + 100);
		MoveToEx(hdc, 410, 100 - 10, NULL);
		LineTo(hdc, 590, 100 - 10);
		MoveToEx(hdc, 410, 100 + 100, NULL);
		LineTo(hdc, 410, 100 - 10);
		MoveToEx(hdc, 590, 100 + 100, NULL);
		LineTo(hdc, 590, 100 - 10);
		MoveToEx(hdc, 600, 300, NULL);
		LineTo(hdc, 900, 300);
		MoveToEx(hdc, 100, 400, NULL);
		LineTo(hdc, 400, 400);
		MoveToEx(hdc, 600, 500, NULL);
		LineTo(hdc, 900, 500);


		//osoby z 1
		for (int j = 0; j < 10; j++) {
			if (osoby[0][j] > -1) {
				MoveToEx(hdc, 200 + j * 15, 175, NULL);
				LineTo(hdc, 200 + j * 15, 120);
			}
		}
		//osoby z 2
		for (int j = 0; j < 10; j++) {
			if (osoby[1][j] > -1) {
				MoveToEx(hdc, 660 + j * 15, 275, NULL);
				LineTo(hdc, 660 + j * 15, 220);
			}
		}
		for (int j = 0; j < 10; j++) {
			if (osoby[2][j] > -1) {
				MoveToEx(hdc, 200 + j * 15, 375, NULL);
				LineTo(hdc, 200 + j * 15, 320);
			}
		}
		//osoby z 4       
		for (int j = 0; j < 10; j++) {
			if (osoby[3][j] > -1) {
				MoveToEx(hdc, 660 + j * 15, 475, NULL);
				LineTo(hdc, 660 + j * 15, 420);
			}
		}

		SelectObject(hdc, hPenOld);
		DeleteObject(pietra);

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Procedura obsługi komunikatów dla okna informacji o programie.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

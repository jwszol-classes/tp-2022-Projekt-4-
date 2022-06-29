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
int dokadjedzie[4] = { -1,-1,-1,-1 };

LPCTSTR masa[70] = { L"0", L"31",L"32", L"33", L"34", L"35", L"36", L"37", L"38", L"39",
L"40", L"41",L"42", L"43", L"44", L"45", L"46", L"47", L"48", L"49",
L"50", L"51",L"52", L"53", L"54", L"55", L"56", L"57", L"58", L"59",
L"60", L"61",L"62", L"63", L"64", L"65", L"66", L"67", L"68", L"69",
L"70", L"71",L"72", L"73", L"74", L"75", L"76", L"77", L"78", L"79",
L"80", L"81",L"82", L"83", L"84", L"85", L"86", L"87", L"88", L"89",
L"90", L"91",L"92", L"93", L"94", L"95", L"96", L"97", L"98", L"99", };

int liczbaMasy = 0;

void losowanieMasy() {
    srand(time(NULL));
    liczbaMasy = rand() % 70;
}

void rysowanie(HWND hWnd, HDC& hdc, PAINTSTRUCT& ps, int y1, int y2, int dokadjedzie[4]) {
    int ktoryPojechal = -1;

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

            //masa text
            TextOut(hdc, 10, 10, text, 5);
            TextOut(hdc, 10, 30, masa[liczbaMasy], 2);


            //osoby z 1
            hLinePen = CreatePen(PS_SOLID, 2, qLineColor);
            hPenOld = (HPEN)SelectObject(hdc, hLinePen);
            if (dokadjedzie[0] != -1) {
                if (dokadjedzie[0] == y2 && y1 == 1) {
                    //glowa
                    Ellipse(hdc, 490, 0 + i, 510, 20 + i); // left top right bottom 
                    //tulow 
                    MoveToEx(hdc, 500, i + 75, NULL); // x y 
                    LineTo(hdc, 500, i + 20);
                    //nogi
                    MoveToEx(hdc, 500, i + 75, NULL); // x y 
                    LineTo(hdc, 520, i + 100);
                    MoveToEx(hdc, 500, i + 75, NULL); // x y 
                    LineTo(hdc, 480, i + 100);
                    //rece
                    MoveToEx(hdc, 500, i + 35, NULL); // x y 
                    LineTo(hdc, 520, i + 50);
                    MoveToEx(hdc, 500, i + 35, NULL); // x y 
                    LineTo(hdc, 480, i + 50);
                    ktoryPojechal = 0;
                }
                else {
                    //tulow
                    MoveToEx(hdc, 200, 120, NULL);
                    LineTo(hdc, 200, 120 + 55);
                    //nogi
                    MoveToEx(hdc, 200, 120 + 55, NULL); // x y 
                    LineTo(hdc, 200 + 20, 120 + 80);
                    MoveToEx(hdc, 200, 120 + 55, NULL); // x y 
                    LineTo(hdc, 200 - 20, 120 + 80);
                    //glowa
                    Ellipse(hdc, 200 - 10, 120 - 20, 120 + 10, 120);
                    //rece
                    MoveToEx(hdc, 200, 120 + 15, NULL); // x y 
                    LineTo(hdc, 200 + 20, 120 + 30);
                    MoveToEx(hdc, 200, 120 + 15, NULL); // x y 
                    LineTo(hdc, 200 - 20, 120 + 30);
                }
            }

            //osoby z 2
            if (dokadjedzie[1] != -1) {
                if (dokadjedzie[1] == y2 && y1 == 2) {
                    //glowa
                    Ellipse(hdc, 490, 0 + i, 510, 20 + i); // left top right bottom 
                    //tulow 
                    MoveToEx(hdc, 500, i + 75, NULL); // x y 
                    LineTo(hdc, 500, i + 20);
                    //nogi
                    MoveToEx(hdc, 500, i + 75, NULL); // x y 
                    LineTo(hdc, 520, i + 100);
                    MoveToEx(hdc, 500, i + 75, NULL); // x y 
                    LineTo(hdc, 480, i + 100);
                    //rece
                    MoveToEx(hdc, 500, i + 35, NULL); // x y 
                    LineTo(hdc, 520, i + 50);
                    MoveToEx(hdc, 500, i + 35, NULL); // x y
                    LineTo(hdc, 480, i + 50);
                    ktoryPojechal = 1;
                }
                else {
                    //tulow
                    MoveToEx(hdc, 750, 220, NULL);
                    LineTo(hdc, 750, 220 + 55);
                    //nogi
                    MoveToEx(hdc, 750, 220 + 55, NULL); // x y 
                    LineTo(hdc, 750 + 20, 220 + 80);
                    MoveToEx(hdc, 750, 220 + 55, NULL); // x y 
                    LineTo(hdc, 750 - 20, 220 + 80);
                    //glowa
                    Ellipse(hdc, 750 - 10, 220 - 20, 750 + 10, 220);
                    //rece
                    MoveToEx(hdc, 750, 220 + 15, NULL); // x y 
                    LineTo(hdc, 750 + 20, 220 + 30);
                    MoveToEx(hdc, 750, 220 + 15, NULL); // x y 
                    LineTo(hdc, 750 - 20, 220 + 30);
                }
            }

            //osoby z 3
            if (dokadjedzie[2] != -1) {
                if (dokadjedzie[2] == y2 && y1 == 3) {
                    //glowa
                    Ellipse(hdc, 490, 0 + i, 510, 20 + i); // left top right bottom 
                    //tulow 
                    MoveToEx(hdc, 500, i + 75, NULL); // x y 
                    LineTo(hdc, 500, i + 20);
                    //nogi
                    MoveToEx(hdc, 500, i + 75, NULL); // x y 
                    LineTo(hdc, 520, i + 100);
                    MoveToEx(hdc, 500, i + 75, NULL); // x y 
                    LineTo(hdc, 480, i + 100);
                    //rece
                    MoveToEx(hdc, 500, i + 35, NULL); // x y 
                    LineTo(hdc, 520, i + 50);
                    MoveToEx(hdc, 500, i + 35, NULL); // x y 
                    LineTo(hdc, 480, i + 50);
                    ktoryPojechal = 2;
                }
                else {
                    //tulow
                    MoveToEx(hdc, 200, 320, NULL);
                    LineTo(hdc, 200, 320 + 55);
                    //nogi
                    MoveToEx(hdc, 200, 320 + 55, NULL); // x y 
                    LineTo(hdc, 220, 400);
                    MoveToEx(hdc, 200, 320 + 55, NULL); // x y 
                    LineTo(hdc, 180, 400);
                    //glowa
                    Ellipse(hdc, 190, 300, 210, 320);
                    //rece
                    MoveToEx(hdc, 200, 320 + 15, NULL); // x y 
                    LineTo(hdc, 220, 320 + 30);
                    MoveToEx(hdc, 200, 320 + 15, NULL); // x y 
                    LineTo(hdc, 180, 320 + 30);
                }
            }

            //osoby z 4
            if (dokadjedzie[3] != -1) {
                if (dokadjedzie[3] == y2 && y1 == 4) {
                    //glowa
                    Ellipse(hdc, 490, 0 + i, 510, 20 + i); // left top right bottom 
                    //tulow 
                    MoveToEx(hdc, 500, i + 75, NULL); // x y 
                    LineTo(hdc, 500, i + 20);
                    //nogi
                    MoveToEx(hdc, 500, i + 75, NULL); // x y 
                    LineTo(hdc, 520, i + 100);
                    MoveToEx(hdc, 500, i + 75, NULL); // x y 
                    LineTo(hdc, 480, i + 100);
                    //rece
                    MoveToEx(hdc, 500, i + 35, NULL); // x y 
                    LineTo(hdc, 520, i + 50);
                    MoveToEx(hdc, 500, i + 35, NULL); // x y 
                    LineTo(hdc, 480, i + 50);
                    ktoryPojechal = 3;
                }
                else {
                    //tulow
                    MoveToEx(hdc, 750, 420, NULL);
                    LineTo(hdc, 750, 420 + 55);
                    //nogi
                    MoveToEx(hdc, 750, 420 + 55, NULL); // x y 
                    LineTo(hdc, 750 + 20, 420 + 80);
                    MoveToEx(hdc, 750, 420 + 55, NULL); // x y 
                    LineTo(hdc, 750 - 20, 420 + 80);
                    //glowa
                    Ellipse(hdc, 750 - 10, 420 - 20, 750 + 10, 420);
                    //rece
                    MoveToEx(hdc, 750, 420 + 15, NULL); // x y 
                    LineTo(hdc, 750 + 20, 420 + 30);
                    MoveToEx(hdc, 750, 420 + 15, NULL); // x y 
                    LineTo(hdc, 750 - 20, 420 + 30);
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
            COLORREF qLineColor, qLineColor2, qLineColor3, qLineColor4;
            HPEN hPenOld;
            qLineColor = RGB(0, 0, 0);
            qLineColor2 = RGB(255, 0, 0);
            qLineColor3 = RGB(0, 255, 0);
            qLineColor4 = RGB(0, 0, 255);
            hLinePen = CreatePen(PS_SOLID, 2, qLineColor);
            hPenOld = (HPEN)SelectObject(hdc, hLinePen);
            LPCTSTR text = L"masa:";

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


            //masa text
            TextOut(hdc, 10, 10, text, 5);
            TextOut(hdc, 10, 30, masa[liczbaMasy], 2);


            //osoby z 1
            hLinePen = CreatePen(PS_SOLID, 2, qLineColor);
            hPenOld = (HPEN)SelectObject(hdc, hLinePen);
            if (dokadjedzie[0] != -1) {
                if (dokadjedzie[0] == y2 && y1 == 1) {
                    //glowa
                    Ellipse(hdc, 490, 0 + i, 510, 20 + i); // left top right bottom 
                    //tulow 
                    MoveToEx(hdc, 500, i + 75, NULL); // x y 
                    LineTo(hdc, 500, i + 20);
                    //nogi
                    MoveToEx(hdc, 500, i + 75, NULL); // x y 
                    LineTo(hdc, 520, i + 100);
                    MoveToEx(hdc, 500, i + 75, NULL); // x y 
                    LineTo(hdc, 480, i + 100);
                    //rece
                    MoveToEx(hdc, 500, i + 35, NULL); // x y 
                    LineTo(hdc, 520, i + 50);
                    MoveToEx(hdc, 500, i + 35, NULL); // x y 
                    LineTo(hdc, 480, i + 50);
                    ktoryPojechal = 0;
                }
                else {
                    //tulow
                    MoveToEx(hdc, 200, 120, NULL);
                    LineTo(hdc, 200, 120 + 55);
                    //nogi
                    MoveToEx(hdc, 200, 120 + 55, NULL); // x y 
                    LineTo(hdc, 200 + 20, 120 + 80);
                    MoveToEx(hdc, 200, 120 + 55, NULL); // x y 
                    LineTo(hdc, 200 - 20, 120 + 80);
                    //glowa
                    Ellipse(hdc, 200 - 10, 120 - 20, 200 + 10, 120);
                    //rece
                    MoveToEx(hdc, 200, 120 + 15, NULL); // x y 
                    LineTo(hdc, 200 + 20, 120 + 30);
                    MoveToEx(hdc, 200, 120 + 15, NULL); // x y 
                    LineTo(hdc, 200 - 20, 120 + 30);
                }
            }

            //osoby z 2
            if (dokadjedzie[1] != -1) {
                if (dokadjedzie[1] == y2 && y1 == 2) {
                    //glowa
                    Ellipse(hdc, 490, 0 + i, 510, 20 + i); // left top right bottom 
                    //tulow 
                    MoveToEx(hdc, 500, i + 75, NULL); // x y 
                    LineTo(hdc, 500, i + 20);
                    //nogi
                    MoveToEx(hdc, 500, i + 75, NULL); // x y 
                    LineTo(hdc, 520, i + 100);
                    MoveToEx(hdc, 500, i + 75, NULL); // x y 
                    LineTo(hdc, 480, i + 100);
                    //rece
                    MoveToEx(hdc, 500, i + 35, NULL); // x y 
                    LineTo(hdc, 520, i + 50);
                    MoveToEx(hdc, 500, i + 35, NULL); // x y 
                    LineTo(hdc, 480, i + 50);
                    ktoryPojechal = 1;
                }
                else {
                    //tulow
                    MoveToEx(hdc, 750, 220, NULL);
                    LineTo(hdc, 750, 220 + 55);
                    //nogi
                    MoveToEx(hdc, 750, 220 + 55, NULL); // x y 
                    LineTo(hdc, 750 + 20, 220 + 80);
                    MoveToEx(hdc, 750, 220 + 55, NULL); // x y 
                    LineTo(hdc, 750 - 20, 220 + 80);
                    //glowa
                    Ellipse(hdc, 750 - 10, 220 - 20, 750 + 10, 220);
                    //rece
                    MoveToEx(hdc, 750, 220 + 15, NULL); // x y 
                    LineTo(hdc, 750 + 20, 220 + 30);
                    MoveToEx(hdc, 750, 220 + 15, NULL); // x y 
                    LineTo(hdc, 750 - 20, 220 + 30);
                }
            }

            //osoby z 3
            if (dokadjedzie[2] != -1) {
                if (dokadjedzie[2] == y2 && y1 == 3) {
                    //glowa
                    Ellipse(hdc, 490, 0 + i, 510, 20 + i); // left top right bottom 
                    //tulow 
                    MoveToEx(hdc, 500, i + 75, NULL); // x y 
                    LineTo(hdc, 500, i + 20);
                    //nogi
                    MoveToEx(hdc, 500, i + 75, NULL); // x y 
                    LineTo(hdc, 520, i + 100);
                    MoveToEx(hdc, 500, i + 75, NULL); // x y 
                    LineTo(hdc, 480, i + 100);
                    //rece
                    MoveToEx(hdc, 500, i + 35, NULL); // x y 
                    LineTo(hdc, 520, i + 50);
                    MoveToEx(hdc, 500, i + 35, NULL); // x y 
                    LineTo(hdc, 480, i + 50);
                    ktoryPojechal = 2;
                }
                else {
                    //tulow
                    MoveToEx(hdc, 200, 320, NULL);
                    LineTo(hdc, 200, 320 + 55);
                    //nogi
                    MoveToEx(hdc, 200, 320 + 55, NULL); // x y 
                    LineTo(hdc, 220, 400);
                    MoveToEx(hdc, 200, 320 + 55, NULL); // x y 
                    LineTo(hdc, 180, 400);
                    //glowa
                    Ellipse(hdc, 190, 300, 210, 320);
                    //rece
                    MoveToEx(hdc, 200, 320 + 15, NULL); // x y 
                    LineTo(hdc, 220, 320 + 30);
                    MoveToEx(hdc, 200, 320 + 15, NULL); // x y 
                    LineTo(hdc, 180, 320 + 30);
                }
            }

            //osoby z 4
            if (dokadjedzie[3] != -1) {
                if (dokadjedzie[3] == y2 && y1 == 4) {
                    //glowa
                    Ellipse(hdc, 490, 0 + i, 510, 20 + i); // left top right bottom 
                    //tulow 
                    MoveToEx(hdc, 500, i + 75, NULL); // x y 
                    LineTo(hdc, 500, i + 20);
                    //nogi
                    MoveToEx(hdc, 500, i + 75, NULL); // x y 
                    LineTo(hdc, 520, i + 100);
                    MoveToEx(hdc, 500, i + 75, NULL); // x y 
                    LineTo(hdc, 480, i + 100);
                    //rece
                    MoveToEx(hdc, 500, i + 35, NULL); // x y 
                    LineTo(hdc, 520, i + 50);
                    MoveToEx(hdc, 500, i + 35, NULL); // x y 
                    LineTo(hdc, 480, i + 50);
                    ktoryPojechal = 3;
                }
                else {
                    //tulow
                    MoveToEx(hdc, 750, 420, NULL);
                    LineTo(hdc, 750, 420 + 55);
                    //nogi
                    MoveToEx(hdc, 750, 420 + 55, NULL); // x y 
                    LineTo(hdc, 750 + 20, 420 + 80);
                    MoveToEx(hdc, 750, 420 + 55, NULL); // x y 
                    LineTo(hdc, 750 - 20, 420 + 80);
                    //glowa
                    Ellipse(hdc, 750 - 10, 420 - 20, 750 + 10, 420);
                    //rece
                    MoveToEx(hdc, 750, 420 + 15, NULL); // x y 
                    LineTo(hdc, 750 + 20, 420 + 30);
                    MoveToEx(hdc, 750, 420 + 15, NULL); // x y 
                    LineTo(hdc, 750 - 20, 420 + 30);
                }
            }

            SelectObject(hdc, hPenOld);
            DeleteObject(hLinePen);

            EndPaint(hWnd, &ps);
            Sleep(1);
        }
    }

    dokadjedzie[ktoryPojechal] = -1;
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
            losowanieMasy();
            dokadjedzie[0] = 2;
            rysowanie(hWnd, hdc, ps, AktualnaPozycja, 1, dokadjedzie);
            AktualnaPozycja = 2;
            Sleep(200);
            rysowanie(hWnd, hdc, ps, 1, 2, dokadjedzie);
            break;
        case ID_BUTTON13:
            losowanieMasy();
            dokadjedzie[0] = 3;
            rysowanie(hWnd, hdc, ps, AktualnaPozycja, 1, dokadjedzie);
            AktualnaPozycja = 3;
            Sleep(200);
            rysowanie(hWnd, hdc, ps, 1, 3, dokadjedzie);
            break;
        case ID_BUTTON14:
            losowanieMasy();
            dokadjedzie[0] = 4;
            rysowanie(hWnd, hdc, ps, AktualnaPozycja, 1, dokadjedzie);
            AktualnaPozycja = 4;
            Sleep(200);
            rysowanie(hWnd, hdc, ps, 1, 4, dokadjedzie);
            break;
        case ID_BUTTON21:
            losowanieMasy();
            dokadjedzie[1] = 1;
            rysowanie(hWnd, hdc, ps, AktualnaPozycja, 2, dokadjedzie);
            AktualnaPozycja = 1;
            Sleep(200);
            rysowanie(hWnd, hdc, ps, 2, 1, dokadjedzie);
            break;
        case ID_BUTTON23:
            losowanieMasy();
            dokadjedzie[1] = 3;
            rysowanie(hWnd, hdc, ps, AktualnaPozycja, 2, dokadjedzie);
            AktualnaPozycja = 3;
            Sleep(200);
            rysowanie(hWnd, hdc, ps, 2, 3, dokadjedzie);
            break;
        case ID_BUTTON24:
            losowanieMasy();
            dokadjedzie[1] = 4;
            rysowanie(hWnd, hdc, ps, AktualnaPozycja, 2, dokadjedzie);
            AktualnaPozycja = 4;
            Sleep(200);
            rysowanie(hWnd, hdc, ps, 2, 4, dokadjedzie);
            break;
        case ID_BUTTON31:
            losowanieMasy();
            dokadjedzie[2] = 1;
            rysowanie(hWnd, hdc, ps, AktualnaPozycja, 3, dokadjedzie);
            AktualnaPozycja = 1;
            Sleep(200);
            rysowanie(hWnd, hdc, ps, 3, 1, dokadjedzie);
            break;
        case ID_BUTTON32:
            losowanieMasy();
            dokadjedzie[2] = 2;
            rysowanie(hWnd, hdc, ps, AktualnaPozycja, 3, dokadjedzie);
            AktualnaPozycja = 2;
            Sleep(200);
            rysowanie(hWnd, hdc, ps, 3, 2, dokadjedzie);
            break;
        case ID_BUTTON34:
            losowanieMasy();
            dokadjedzie[2] = 4;
            rysowanie(hWnd, hdc, ps, AktualnaPozycja, 3, dokadjedzie);
            AktualnaPozycja = 4;
            Sleep(200);
            rysowanie(hWnd, hdc, ps, 3, 4, dokadjedzie);
            break;
        case ID_BUTTON41:
            losowanieMasy();
            dokadjedzie[3] = 1;
            rysowanie(hWnd, hdc, ps, AktualnaPozycja, 4, dokadjedzie);
            AktualnaPozycja = 1;
            Sleep(200);
            rysowanie(hWnd, hdc, ps, 4, 1, dokadjedzie);
            break;
        case ID_BUTTON42:
            losowanieMasy();
            dokadjedzie[3] = 2;
            rysowanie(hWnd, hdc, ps, AktualnaPozycja, 4, dokadjedzie);
            AktualnaPozycja = 2;
            Sleep(200);
            rysowanie(hWnd, hdc, ps, 4, 2, dokadjedzie);
            break;
        case ID_BUTTON43:
            losowanieMasy();
            dokadjedzie[3] = 3;
            rysowanie(hWnd, hdc, ps, AktualnaPozycja, 4, dokadjedzie);
            AktualnaPozycja = 3;
            Sleep(200);
            rysowanie(hWnd, hdc, ps, 4, 3, dokadjedzie);
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
        TextOut(hdc, 10, 30, masa[liczbaMasy], 2);

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

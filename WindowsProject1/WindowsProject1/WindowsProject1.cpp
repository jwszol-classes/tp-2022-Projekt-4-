// WindowsProject1.cpp : Definiuje punkt wejścia dla aplikacji.
//

#include "framework.h"
#include "WindowsProject1.h"

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

void rysowanie(HWND hWnd, HDC& hdc, PAINTSTRUCT& ps, int y1, int y2) {

    for (int i = y1 * 100; i < y2 * 100; i++) {
        InvalidateRect(hWnd, NULL, TRUE);
        hdc = BeginPaint(hWnd, &ps);
        HPEN hLinePen;
        COLORREF qLineColor;
        HPEN hPenOld;
        qLineColor = RGB(0, 0, 0);
        hLinePen = CreatePen(PS_SOLID, 5, qLineColor);
        hPenOld = (HPEN)SelectObject(hdc, hLinePen);

        //platforma
        MoveToEx(hdc, 410, i + 100 , NULL);
        LineTo(hdc, 590, i + 100);

        MoveToEx(hdc, 410, i-10 , NULL);
        LineTo(hdc, 590, i-10);

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

        SelectObject(hdc, hPenOld);
        DeleteObject(hLinePen);


        EndPaint(hWnd, &ps);
        Sleep(1);
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

    // Inicjuj ciągi globalne
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Wykonaj inicjowanie aplikacji:
    if (!InitInstance (hInstance, nCmdShow))
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

    return (int) msg.wParam;
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

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
        TEXT("3"),                  // the caption of the button
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
        100, 85,                                  // the left and top co-ordinates
        30, 30,                              // width and height
        hWnd,                                 // parent window handle
        (HMENU)ID_BUTTON13,                   // the ID of your button
        hInstance,                            // the instance of your application
        NULL);

    hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
        TEXT("4"),                  // the caption of the button
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
        100, 120,                                  // the left and top co-ordinates
        30, 30,                              // width and height
        hWnd,                                 // parent window handle
        (HMENU)ID_BUTTON14,                   // the ID of your button
        hInstance,                            // the instance of your application
        NULL);



    hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
        TEXT("1"),                  // the caption of the button
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
        850, 120,                                  // the left and top co-ordinates
        30, 30,                              // width and height
        hWnd,                                 // parent window handle
        (HMENU)ID_BUTTON21,                   // the ID of your button
        hInstance,                            // the instance of your application
        NULL);

    hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
        TEXT("3"),                  // the caption of the button
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
        850, 190,                                  // the left and top co-ordinates
        30, 30,                              // width and height
        hWnd,                                 // parent window handle
        (HMENU)ID_BUTTON23,                   // the ID of your button
        hInstance,                            // the instance of your application
        NULL);

    hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
        TEXT("4"),                  // the caption of the button
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
        850, 225,                                  // the left and top co-ordinates
        30, 30,                              // width and height
        hWnd,                                 // parent window handle
        (HMENU)ID_BUTTON24,                   // the ID of your button
        hInstance,                            // the instance of your application
        NULL);


    hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
        TEXT("1"),                  // the caption of the button
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
        TEXT("4"),                  // the caption of the button
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
        100, 345,                                  // the left and top co-ordinates
        30, 30,                              // width and height
        hWnd,                                 // parent window handle
        (HMENU)ID_BUTTON34,                   // the ID of your button
        hInstance,                            // the instance of your application
        NULL);



    hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
        TEXT("1"),                  // the caption of the button
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
        TEXT("3"),                  // the caption of the button
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
    HDC hdc;

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
                rysowanie(hWnd, hdc, ps,1,2);
                break;
            case ID_BUTTON13:
                rysowanie(hWnd, hdc, ps, 1, 3);
                break;
            case ID_BUTTON14:
                rysowanie(hWnd, hdc, ps, 1, 4);
                break;
            case ID_BUTTON21:
                rysowanie(hWnd, hdc, ps, 2, 1);
                break;
            case ID_BUTTON23:
                rysowanie(hWnd, hdc, ps, 2, 3);
                break;
            case ID_BUTTON24:
                rysowanie(hWnd, hdc, ps, 2, 4);
                break;
            case ID_BUTTON31:
                rysowanie(hWnd, hdc, ps, 3, 1);
                break;
            case ID_BUTTON32:
                rysowanie(hWnd, hdc, ps, 3, 2);
                break;
            case ID_BUTTON34:
                rysowanie(hWnd, hdc, ps, 3, 4);
                break;
            case ID_BUTTON41:
                rysowanie(hWnd, hdc, ps, 4, 1);
                break;
            case ID_BUTTON42:
                rysowanie(hWnd, hdc, ps, 4, 2);
                break;
            case ID_BUTTON43:
                rysowanie(hWnd, hdc, ps, 4, 3);
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

            // 1. pietro
            HPEN pierwsze;
            COLORREF Color1;
            Color1 = RGB(0, 0, 0);
            pierwsze = CreatePen(PS_SOLID, 7, Color1);
            hPenOld = (HPEN)SelectObject(hdc, pierwsze);

            MoveToEx(hdc, 100, 200, NULL);
            LineTo(hdc, 400, 200);

            SelectObject(hdc, hPenOld);
            DeleteObject(pierwsze);

            // 2. pietro
            HPEN drugie;
            Color1 = RGB(0, 0, 0);
            drugie = CreatePen(PS_SOLID, 7, Color1);
            hPenOld = (HPEN)SelectObject(hdc, drugie);

            MoveToEx(hdc, 600, 300, NULL);
            LineTo(hdc, 900, 300);

            SelectObject(hdc, hPenOld);
            DeleteObject(drugie);

            // 3. pietro
            HPEN trzecie;
            Color1 = RGB(0, 0, 0);
            trzecie = CreatePen(PS_SOLID, 7, Color1);
            hPenOld = (HPEN)SelectObject(hdc, trzecie);

            MoveToEx(hdc, 100, 400, NULL);
            LineTo(hdc, 400, 400);

            SelectObject(hdc, hPenOld);
            DeleteObject(trzecie);

            // 4. pietro
            HPEN hLinePen;
            Color1 = RGB(0, 0, 0);
            hLinePen = CreatePen(PS_SOLID, 7, Color1);
            hPenOld = (HPEN)SelectObject(hdc, hLinePen);

            MoveToEx(hdc, 600, 500, NULL);
            LineTo(hdc, 900, 500);

            SelectObject(hdc, hPenOld);
            DeleteObject(hLinePen);

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

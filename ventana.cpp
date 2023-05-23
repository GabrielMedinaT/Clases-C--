#include <Windows.h>

// Declaración del procedimiento de ventana
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // Registrar la clase de ventana
    const char *CLASS_NAME = "MiVentana";

    WNDCLASS wc = {};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Crear la ventana
    HWND hwnd = CreateWindow(
        CLASS_NAME,
        "Mi Ventana",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL,
        NULL,
        hInstance,
        NULL);

    if (hwnd == NULL)
    {
        return 0;
    }

    // Crear el botón
    HWND button = CreateWindow(
        "BUTTON",
        "Cerrar",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        10, 10, 100, 30,
        hwnd,
        NULL,
        hInstance,
        NULL);

    if (button == NULL)
    {
        return 0;
    }

    // Mostrar la ventana
    ShowWindow(hwnd, nCmdShow);

    // Bucle de mensajes
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

// Procedimiento de ventana
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_COMMAND:
        if (HIWORD(wParam) == BN_CLICKED)
        {
            HWND button = reinterpret_cast<HWND>(lParam);
            if (button != NULL)
            {
                if (GetParent(button) == hwnd)
                {
                    // El botón ha sido pulsado
                    SendMessage(hwnd, WM_CLOSE, 0, 0);
                }
            }
        }
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

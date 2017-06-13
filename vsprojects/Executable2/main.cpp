#include <string>
#include <Windows.h>
#define IPCDISPLAY1 1
// global variables
struct MyMessage
{
	UINT msg;
	UINT key;
	UINT mouseX;
	UINT mouseY;
	char text[100];
};
// global variables
MyMessage message;
PCOPYDATASTRUCT PCDS;

LRESULT CALLBACK WindowProc(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		break;
	}
	case WM_PAINT:
	{
		// calculate string
		std::string str;
		str = std::string(message.text) + " :: [ ";
		str += (message.msg == NULL ? "NULL" : std::to_string(message.msg)) + ", ";
		str += (message.key == NULL ? "NULL" : std::to_string(message.key)) + ", ";
		str += (message.mouseX == NULL ? "NULL" : std::to_string(message.mouseX)) + ", ";
		str += (message.mouseY == NULL ? "NULL" : std::to_string(message.mouseY)) + " ]";
		// paint text on screen
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 10, 10, str.c_str(), (int)str.size());
		EndPaint(hwnd, &ps);
        break;
	}
	case WM_COPYDATA:
	{
		// get copy data
		PCDS = (PCOPYDATASTRUCT)lParam;
		// check if empty
		if (PCDS == nullptr) break;
		// check word data
		if (PCDS->dwData != IPCDISPLAY1) break;
		// check byte size
		if (PCDS->cbData != sizeof(MyMessage)) break;
		// save current message
		message.key = ((MyMessage*)PCDS->lpData)->key;
        message.msg = ((MyMessage*)PCDS->lpData)->msg;
        message.mouseX = ((MyMessage*)PCDS->lpData)->mouseX;
        message.mouseY = ((MyMessage*)PCDS->lpData)->mouseY;
        for (int i = 0; i < 100; i++) message.text[i] = ((MyMessage*)PCDS->lpData)->text[i];
		// repaint the window
		RECT rect;
		GetClientRect(hwnd, &rect);
		InvalidateRect(hwnd, &rect, TRUE);
		UpdateWindow(hwnd);
        break;
	}
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	//------------------------------------------------
	// required variables
	MSG msg;
	HWND hwnd;
	BOOL running = TRUE;
	WNDCLASSEX wndcex = { sizeof(WNDCLASSEX) };
	//------------------------------------------------
	// construct window class
	wndcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndcex.style = CS_HREDRAW | CS_VREDRAW;
	wndcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndcex.hInstance = GetModuleHandle(NULL);
	wndcex.cbClsExtra = 0;
	wndcex.cbWndExtra = 16;
	wndcex.lpfnWndProc = WindowProc;
	wndcex.lpszMenuName = NULL;
	wndcex.lpszClassName = "ReceiveWin32Class";
	wndcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	// register the window class
	if (!RegisterClassEx(&wndcex)) return 1;
	//------------------------------------------------
	// create window
	hwnd = CreateWindow(
		"ReceiveWin32Class",
		"IPC_ReceiveWindow",
		WS_POPUP | WS_CAPTION | WS_SYSMENU,
		0, 0, 500, 500,
		NULL,
		NULL,
		GetModuleHandle(NULL),
		NULL
	);
	if (hwnd == NULL) return 1;
	// update the window
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);
	//------------------------------------------------
	// message pump loop
	while (running == TRUE)
	{
		// check for message
		while (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			// check if running
			if (msg.message == WM_QUIT)
			{
				running = FALSE;
				break;
			}
			// message dispatch
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	// return
	return 0;
}
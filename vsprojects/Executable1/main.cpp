#include <string>
#include <Windows.h>
#define IPCDISPLAY1 1
struct MyMessage
{
	UINT msg;
	UINT key;
	UINT mouseX;
	UINT mouseY;
	char text[100];
};
// global variables
char * result = "???UNKNOWN???";
MyMessage message = { NULL, NULL, NULL, NULL, "???UNKNOWN???" };
COPYDATASTRUCT CDS;

void MyMessageSend(HWND hwnd, UINT msg, UINT key, UINT mouseX, UINT mouseY, char text[100])
{
	// store defaults
	message.msg = msg;
	message.key = key;
	message.mouseX = mouseX;
	message.mouseY = mouseY;
	for (int i = 0; i < 100; i++) message.text[i] = text[i];
	// encode message in CPS
	CDS.lpData = &message;
	CDS.dwData = IPCDISPLAY1;
	CDS.cbData = sizeof(MyMessage);
	// get the window receiver
	HWND receiver = FindWindow("ReceiveWin32Class", "IPC_ReceiveWindow");
	// check if window receiver exists
	if (receiver != NULL)
	{
		// send message to window receiver
		SendMessage(receiver, WM_COPYDATA, (WPARAM)(HWND)hwnd, (LPARAM)(LPVOID)&CDS);
		result = "Message Sent...";
	}
	else result = "Receiver Window Not Found!";
	// repaint the window
	RECT rect;
	GetClientRect(hwnd, &rect);
	InvalidateRect(hwnd, &rect, TRUE);
	UpdateWindow(hwnd);
}

LRESULT CALLBACK WindowProc(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
	switch (uMsg)
	{
		// default events
		case WM_PAINT:
		{
			// paint text on screen
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hwnd, &ps);
			std::string str = result;
			TextOut(hdc, 10, 10, str.c_str(), (int)str.size());
			EndPaint(hwnd, &ps);
			break;
		}
		case WM_CREATE:
		{
			MyMessageSend(hwnd, uMsg, NULL, NULL, NULL, "WM_CREATE");
			break;
		}
		case WM_DESTROY:
		{
			MyMessageSend(hwnd, uMsg, NULL, NULL, NULL, "WM_DESTROY");
			PostQuitMessage(0);
			break;
		}
		// window mouse events
		case WM_MOUSEMOVE:
		{
			MyMessageSend(hwnd, uMsg, (UINT)wParam, LOWORD(lParam), HIWORD(lParam), "WM_MOUSEMOVE");
			break;
		}
		case WM_LBUTTONUP:
		{
			MyMessageSend(hwnd, uMsg, (UINT)wParam, LOWORD(lParam), HIWORD(lParam), "WM_LBUTTONUP");
			break;
		}
		case WM_RBUTTONUP:
		{
			MyMessageSend(hwnd, uMsg, (UINT)wParam, LOWORD(lParam), HIWORD(lParam), "WM_RBUTTONUP");
			break;
		}
		case WM_LBUTTONDOWN:
		{
			MyMessageSend(hwnd, uMsg, (UINT)wParam, LOWORD(lParam), HIWORD(lParam), "WM_LBUTTONDOWN");
			break;
		}
		case WM_RBUTTONDOWN:
		{
			MyMessageSend(hwnd, uMsg, (UINT)wParam, LOWORD(lParam), HIWORD(lParam), "WM_RBUTTONDOWN");
			break;
		}
		// window keyboard events
		case WM_KEYUP:
		{
			MyMessageSend(hwnd, uMsg, (UINT)wParam, NULL, NULL, "WM_KEYUP");
			break;
		}
		case WM_KEYDOWN:
		{
			MyMessageSend(hwnd, uMsg, (UINT)wParam, NULL, NULL, "WM_KEYDOWN");
			break;
		}
	}
	// return default window procedure
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
	wndcex.lpszClassName = "DispatchWin32Class";
	wndcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	// register the window class
	if (!RegisterClassEx(&wndcex)) return 1;
	//------------------------------------------------
	// create window
	hwnd = CreateWindow(
		"DispatchWin32Class",
		"IPC_DispatchWindow",
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
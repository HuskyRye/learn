#include <Windows.h>

int main()
{
	Sleep(3000);
	//给指定的句柄发送消息,发送一个鼠标左键按下消息，用vs spy检测句柄
	SendMessage((HWND)0x000607B2, WM_LBUTTONDOWN, 0, 0);
	SendMessage((HWND)0x000607B2, WM_LBUTTONUP, 0, 0);
	return 0;
}

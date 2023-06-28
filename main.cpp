#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0500

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>


int SCREEN_WIDTH;
int SCREEN_HEIGHT;


void MouseSetup(INPUT *buffer){
    buffer->type = INPUT_MOUSE;
    buffer->mi.dx = (0 * (0xFFFF / SCREEN_WIDTH));
    buffer->mi.dy = (0 * (0xFFFF / SCREEN_HEIGHT));
    buffer->mi.mouseData = 0;
    buffer->mi.dwFlags = MOUSEEVENTF_ABSOLUTE;
    buffer->mi.time = 0;
    buffer->mi.dwExtraInfo = 0;
}


void MouseMoveAbsolute(INPUT *buffer, int x, int y){
    buffer->mi.dx = (x * (0xFFFF / SCREEN_WIDTH));
    buffer->mi.dy = (y * (0xFFFF / SCREEN_HEIGHT));
    buffer->mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE);

    SendInput(1, buffer, sizeof(INPUT));
}


void Stealth(){
 HWND Stealth;
 AllocConsole();
 Stealth = FindWindowA("ConsoleWindowClass", NULL);
 ShowWindow(Stealth,0);
}

int main(int argc, char *argv[]){
	SCREEN_WIDTH = GetSystemMetrics(SM_CXFULLSCREEN);
	SCREEN_HEIGHT = GetSystemMetrics(SM_CYFULLSCREEN);
	
	Stealth();
	
    INPUT buffer[1];

    MouseSetup(&buffer[0]);

	while(true){
		MouseMoveAbsolute(&buffer[0], 100, 500);
		Sleep(300);
		MouseMoveAbsolute(&buffer[0], 400, 500);
		Sleep(5000);
	}

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "event_screen.h"


int main(void) {
	SetConsoleTitle("AME: 2253 | 안드로이드 미로 탈출: 2253번째 실험");
	system("mode con cols=67 lines=20");
	start_screen();
	return 0;
}

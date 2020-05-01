#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "map.h"
#include "event_screen.h"
#include "inventory.h"
#include "mc.h"

extern int x;
extern int y;
 
int move(char dir, int id){ //이동 함수 방향과 맵 id를 인자로 받음  
		switch(dir){ //좌표 이동과 이동 후 좌표에 있는 값 반환  
			case 'w': //상  
				x--;
				if(map(id, 0, 0)[x][y] != 0 && x<21 && x>-1){
					return map(id, 0, 0)[x][y];
				}  else{
					x+=1;
					//printf("%d %d\n", x, y); 
					puts("벽입니다 왜 벽으로 가려 하시는 거죠?");	
					return 0;
				}
			case 'a': //좌  
				y--;
				if(map(id, 0, 0)[x][y] != 0 && x<21 && x>-1){
					return map(id, 0, 0)[x][y];
				}  else {
					y++;
					puts("벽입니다 왜 벽으로 가려 하시는 거죠?");	
					return 0;
				}
			case 's': //하  
				x++;
				if(map(id, 0, 0)[x][y] != 0 && x<21 && x>-1){
					return map(id, 0, 0)[x][y];
				}  else {
					x--;
					puts("벽입니다 왜 벽으로 가려 하시는 거죠?");	
					return 0;
				}
			case 'd': //우  
				y++;
				if(map(id, 0, 0)[x][y] != 0 && x<21 && x>-1){
					return map(id, 0, 0)[x][y];
				} else {
					y--;
					puts("벽입니다 왜 벽으로 가려 하시는 거죠?");	
					return 0;
				}
			default:
				printf("제대로된 입력이 아닙니다 다시 입력하세요\n");
				break;
		}
}

void time_spent(int id){
	static int num=0;
	if(id == -1){
		num = 0;
		return ;
	}
	clock_t beg;
	if(num == 0){
		beg = clock();
		num++;
	} 
	double timeS = (double)(clock()-beg) / CLOCKS_PER_SEC;
	if(timeS > 3600) fail(id);
}

void game_start(int id, int mode){ //게임 시작 함수 id는 맵 판별  
	idRT(id);
	char cmd, ecmd;
	int code, i;
	if(mode == 1) time_spent(id);
	printf(">> "); scanf("%c", &cmd); while ((getchar()) != '\n');  //커맨드 입력 / w,a,s,d,e,p,v 
	switch(cmd){
		case 'w':
		case 'a':
		case 's':
		case 'd':
			code = move(cmd, id);
		//	printf("%d %d %d %d\n", id, x, y, code);
			if(code != 0) map_interact(code, id);
			break;
		case 'e':
			inventory(2, 0, 0);
			break;
		case 'v':
			printf("  -------------------------Android: 2253의 상태창-------------------------\n");
			printf("\t\t-체력: %4d -공격속도: %4d -힘: %4d\n\t\t-속성(불): %4d -속성(전기): %4d\n", MC(0,0,0,0,0,0).hp, MC(0,0,0,0,0,0).speed, MC(0,0,0,0,0,0).str, MC(0,0,0,0,0,0).fire, MC(0,0,0,0,0,0).elect);
			printf("  ------------------------------------------------------------------------\n");
			break; 
		case 'p':
			stop('m');
			break;
	}
	Sleep(400);
	game_start(id, mode);
}


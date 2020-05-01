#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "game_function.h"
#include "mc.h" 
#include "map.h"
#include "item.h"

extern x, y; 

void tutorial(){
	puts("이동하려면 w,a,s,d를 눌러주세요");
	puts("상태창을 출력하려면 v를 눌러주세요");
	puts("인벤토리를 출력하려면 e를 눌러주세요");
	puts("멈추려면 p를 눌러주세요"); 
	puts("아, 그리고 계속 왔다갔다 하고 싶으실텐데, \n그러면 자신에게만 안좋을 수가 있어요(멘탈에)\n");
	return ;
}

void start_screen(){
	srand(time(NULL));
	int i = 1;
	while(i){
		if(kbhit()) break;
		printf("*******************************\n");
		printf("*  Android Maze Escape: 2253  *\n");
		printf("*                  -AME: 2253 *\n");
		printf("* (개발자도 포기한 미친 게임) *\n");
		if(i%2 == 1){
			printf("*   Enter를 눌러 시작하세요   *\n");
		}else{
			printf("*                             *\n");
		}
		if(i%2 == 0){
			printf("*      혈압, 샷건 주의!!!     *\n");
		}else{
			printf("*                             *\n");
		}
		printf("*******************************\n");
		Sleep(500);
		system("cls");
		i++;
	}
	while ((getchar()) != '\n');
	system("cls");
	tutorial();
	int id = rand()%6+1;
	map(id, -2, 0);
	MC(0,0,0,0,0,0);
	game_start(id, 0);
}

void stop(char type){
	system("cls");
	switch(type){
		case 'n':
			puts("AME를 플레이 해주셔서 감사합니다");
			Sleep(400);
			puts("제작자의 말:");
			puts("그래도 깨긴 깨셨네요?");
			puts("개인적으로 어렵게 했다고 느껴지지는 않았는데");
			puts("나중에 기회가 된다면 더 어렵게 만들어보겠습니다.");
			puts("(개발자2-전 이 게임 플레이 포기했습니다)"); 
			Sleep(400);
			break;
		case 'm':
			puts("저흰 저장 없으니까 지금까진 한것들 다시해야 한다는 거 알아두시고");
			Sleep(400);
			puts("잘가세요");
			Sleep(1000);
			puts("아 맞다 다음에 시작할때 이번 맵이 아닐수도 있어요ㅋㅋ");
			Sleep(3000);
			break;
		default:
			puts("error: 개발자가 바보라 코딩 제대로 못함 쨌든 ㅂㅇ");
			break; 
	}
	exit(0);
}

void reset(int id){
	x = 10; y = 10;
	int i;
	inventory(5, 0, 0);
	map(id, 2, 0);
	money(4,0);
	resting_area(0, 1);
	map_interact(101, id);
	MC(6,0,0,0,0,0);
	time_spent(-1);
}

void map_clear(int prev){
	reset(prev);
	system("cls");
	srand(time(NULL));
	puts("축하합니다! 탈출성공!\n");
	Sleep(400);
	puts("이제 뭐할거야?\n"); 
	Sleep(400);
	printf("옵션 1: 랜덤 맵 클리어하기(왜 굳이 다시 갖히겠는지는 모르겠지만)\n");
	Sleep(400);
	printf("옵션 2: 방금 깬 맵 하드모드 클리어하기 (시간제한 있음)\n");
	Sleep(400);
	printf("옵션 3: 못해먹겠다 (개발자: ㅇㅈ)\n");
	Sleep(200);
	int input=0;
	while(input!= 1 && input != 2 && input != 3){  
		printf(">> "); scanf("%d", &input); while ((getchar()) != '\n');
		if(input == 1){
			int i = rand() % 4;
			while(i == prev){
				i = rand() % 4;
			}
			system("cls");
			game_start(i, 0);
		}else if(input == 2){
			system("cls");
			game_start(prev, 1);
		}else if(input == 3){
			system("cls");
			stop('n');
		}else{
			printf("이상한거 치지 말고 제대로 치세요: ");
			continue;
		}
	}
}

void fail(int prev){
	reset(prev);
	srand(time(NULL)); 
	system("cls");
	printf("실패했군요...뭐 20분만에 클리어는 좀 힘드려나요?\n");
	Sleep(750);
	printf("어쩔 수 없죠, 선택하세요\n");
	Sleep(750);
	puts("1: 다시 도전 한다 \n2: 일반이나 해야겠다 \n3:다른거 하드모드 해볼래 \n4: 그냥 안할래 이딴 게임");
	int input=0;
	printf(">> "); scanf("%d", &input); while ((getchar()) != '\n');
	while(input != 1 && input != 2 && input != 3 && input != 4){  
		printf(">> "); scanf("%s", input);
		if(input == 1){
			int i = rand() % 4;
			while(i == prev){
				i = rand() % 4;
			}
			game_start(i, 0);
		}else if(input == 2){
			game_start(prev, 1);
		}else if(input == 3){
			int i = rand() % 4;
			while(i == prev){
				i = rand() % 4;
			}
			game_start(i, 1);
		}else if(input == 4){
			stop('n');
		}else{
			printf("이상한거 치지 말고 제대로 치세요: ");
			continue;
		}
	}
}


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>

void start_screen(){
	int i = 1;
	while(i){
		if(kbhit()) break;
		printf("*******************************\n");
		printf("*  Android Maze Escape: 2253  *\n");
		printf("*                  -AME: 2253 *\n");
		printf("* (개발자도 포기한 미친 게임) *\n");
		if(i%2 == 1){
			printf("*  아무 키나 눌러 시작하세요  *\n");
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
	//game_start(0);
}

void stop(char type){
	system("cls");
	switch(type){
		case 'n':
			puts("AME를 플레이 해주셔서 감사합니다~");
			Sleep(400);
			puts("제작자의 말:");
			Sleep(400);
			puts("coder38611-제가 랜덤으로 다 하자고 한 사람이고 일부러 난이도 높인 사람입니다.");
			Sleep(400);
			puts("");
			break;
		case 'm':
			puts("저흰 저장 없으니까 지금까진 한것들 다시해야 한다는 거 알아두시고");
			Sleep(400);
			puts("잘가세요");
			Sleep(1000);
			puts("아 맞다 다음에 시작할때 이번 맵이 아닐수도 있어요ㅋㅋ");
			break;
		default:
			puts("error: 개발자가 바보라 코딩 제대로 못함 쨌든 ㅂㅇ");
			break; 
	}
}

void map_clear(int prev){
	system("cls");
	srand(time(NULL));
	puts("축하합니다! 탈출성공!");
	Sleep(400);
	puts("이제 뭐할거야?"); 
	Sleep(400);
	printf("옵션 1: 새로운 맵 클리어하기(왜 굳이 다시 갖히겠는지는 모르겠지만 커맨드: new)\n");
	Sleep(400);
	printf("옵션 2: 방금 깬 맵 하드모드 클리어하기 (시간제한 있으니까 열심히 해보셈 커맨드: again)\n");
	Sleep(400);
	printf("옵션 3: 못해먹겠다 (개발자: ㅇㅈ 커맨드: fk)\n");
	Sleep(200);
	char input[6];
	while(strcmp(input, "new") != 0 && strcmp(input, "again") != 0 && strcmp(input, "fk") != 0){ 
		scanf("%s", &input);
		printf("%s\n", &input);
		if(strcmp(input, "new") == 0){
			int i = rand() % 4;
			while(i == prev){
				i = rand() % 4;
			}
			//game_start(i);
		}else if(strcmp(input, "again") == 0){
			//game_start(prev, 1);
		}else if(strcmp(input, "fk") == 0){
			stop('n');
		}else{
			printf("이상한거 치지 말고 제대로 치세요: ");
			continue;
		}
	}
}



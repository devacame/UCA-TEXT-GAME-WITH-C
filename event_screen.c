#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

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

void map_clear(int prev){
	srand(time(NULL));
	puts("축하합니다! 탈출성공!");
	puts("이제 뭐할거야?"); 
	printf("옵션 1: 새로운 맵 클리어하기(왜 굳이 다시 갖히겠는지는 모르겠지만 커맨드: new)");
	Sleep(400);
	printf("옵션 2: 방금 깬 맵 하드모드 클리어하기 (시간제한 있으니까 열심히 해보셈 커맨드: again)");
	Sleep(400);
	printf("옵션 3: 못해먹겠다 (개발자: ㅇㅈ 커맨드: fk)");
	Sleep(200);
	char* input;
	scanf("%s", )
	if(input == "new"){
		int i = rand() % 4;
		while(i == prev){
			i = rand() % 4;
		}
		//game_start(i);
	}else if(input == "again"){
		game_start_hardcore(prev);
	}else if(input == "fk"){
		stop();
	}else{
		printf("이상한거 치지 말고 제대로 치세요: "); scanf("%s", input); 
	}
	
}

int main() {
	start_screen();
}

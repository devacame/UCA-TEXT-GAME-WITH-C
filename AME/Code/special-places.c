#include <stdio.h>
#include <windows.h>

char* pName(char p){
	switch(p){
		case 'e':
			return "탈출구";
		case 'v':
			return "자판기";
		case 'r':
			return "잊힌자들의 안식처";
	}
}

void resting_area(int p){
	static int remainder[4] = {6, 6, 6, 6};
	if(remainder[p-2] == 0){
		//deny access to SP
	}
	//screen
	//healing();
	//NPCs1();
}

void vending_machine(/*item array*/){
	//screen
	//아이템 출력
	for(;;){
		//상점 커맨드 반복  
	}
}


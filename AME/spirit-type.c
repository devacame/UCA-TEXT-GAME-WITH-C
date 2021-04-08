#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "mc.h"
#include "inventory.h"

typedef struct Spirit{  //정령 구조체  
	char* name; //이름 캐릭터형 포인터 
	int stat; //증가될 스탯량 
}Spirit;

Spirit Ifrit(){
	Spirit Ifrit;
	Ifrit.name = "이프리트(화염)";
	Ifrit.stat = 100;
	return Ifrit;
}

Spirit Electron(){
	Spirit Electron;
	Electron.name = "일렉트론(전기)";
	Electron.stat = 100;
	return Electron;
}
	
Spirit Aegis(){
	Spirit Aegis;
	Aegis.name = "아이기스(노멀)";
	Aegis.stat = 70;
	return Aegis;
}
	
int spi_chk[3] = {0,}; //index 0 = ifrit 1 = electron 2 = aegis  특정 정령 소환 가능 여부 확인

void spirit_open(){ 
	srand(time(NULL));
	Sleep(1500);  
	if(rand()%100 == 15){  //1%의 확률로 정령알에서 정령 부화  
		int temp = rand() % 3; //어떤 정령인지 결정  
		for(;;){
			if(spi_chk[temp] == 0){ //아직 소환하지 않은 정령인지 확인  
				spi_chk[temp] = 1; //소환한 것으로 전환  
				switch(temp){  //해당 정령 관련 화면 출력 및 스탯 증가  
					case 0:
						MC(1,0,0,0,Ifrit().stat,0);
						printf("축하합니다! 무려 1%의 확률을 뚫고 %s와 계약했습니다!", Ifrit().name); 
						break;
					case 1:
						MC(1,0,0,0,0,Electron().stat);
						printf("축하합니다! 무려 1%의 확률을 뚫고 %s와 계약했습니다!", Electron().name);
						break;
					case 2:
						MC(1,0,Aegis().stat,0,0,0);
						printf("축하합니다! 무려 1%의 확률을 뚫고 %s와 계약했습니다!", Aegis().name);
						break;
				}
				inventory(1, 22, -1);
				break;
			}else{
				continue; //이미 소환한 정령이라면 다시 소환  
			}	
		}
	}else{ //부화 실패 후 해당 화면 출력  
		puts("쯧 뭐 당연히 실패했습니다. 1% 확률이라고요?");
		inventory(1,22,-1);
	}
}

void print_cSpirit(){
	if(spi_chk[0] != 0) printf("\n\t%s", Ifrit().name);
	if(spi_chk[1] != 0) printf("\n\t%s", Electron().name);
	if(spi_chk[2] != 0) printf("\n\t%s", Aegis().name);
}

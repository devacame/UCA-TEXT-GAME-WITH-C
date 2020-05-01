#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "inventory.h"
#include "mc.h"
#include "spirit-type.h"

extern int x,y; 		//mc좌표 

void assist_i(int code){		//아이템 이름 출력 도움 함수(code=코드 입력)
	char* kind[26]={"검","창","도끼","물양동이","버프(힘 7)","버프(힘 10)","버프(속도 7)","버프(속도 10)","디버프(힘 7)","디버프(힘 10)","디버프(속도 7)","디버프(속도 10)","수리도구(힘)","수리도구(체력)","수리도구(속도)","수리도구(인벤토리 3증가)","수리도구(인벤토리 5증가)","철판","전선","전구","cpu","냉각기","정령알","IBuf","패널티무시권"};
	printf("%s",kind[code]); 	
} 

int money(int mode,int give){	//골드입출금(mode 0=현재소지금,1=골드 입출,2=사망시 수리비 출금 give=골드양) 
	static int gold=0;
	if(mode==0){			//현재소지금 출력 
		printf("현재 소지금 : %03d\n",gold);
	}else if(mode==1){		//골드 지급
		gold+=give;
		if(give>0){
			printf("%d골드를 얻었다!\n",give);
		}else if(give<0){
			printf("%d골드를 사용했다.\n", give);
		}
	}else if(mode==2){		//사망시 수리비 출금 
		gold=gold/2;
	}else if(mode==3){
		return gold;
	}else if(mode == 4){
		gold = 0;
	}
}
int de_buff(int mode, int kind){	//버프 디버프 아이템(mode 0=버프, 1=디버프,2=물양동이 ,kind 0=힘7, 1=힘10, 2속도7, 3=속도10)
	int code[4]={4,5,6,7};			//버프디버프 코드 
	char* name[4]={"버프(힘 7)","버프(힘 10)","버프(속도 7)","버프(속도 10)"};	//파밍 출력요소 
	int n;
	if(mode==0){
		printf("%s!\n",name[kind]);
		n = inventory(1,code[kind],1); 
	}else if(mode==1){
		printf("디%s!\n",name[kind]);
		n = inventory(1,code[kind]+4,1); 
	}else if(mode==2){
		printf("물양동이!\n");
		n = inventory(1,3,1);	
	}
	return n;
}
int weapon(int mode,int number){		//무기함수(mode 0=무기 파밍,1=무기 착용,2=무기 착용해제, number 0=검,1=창,2=도끼)
	int stat[3]={15,20,30};		//무기당 오를 스텟 
	int code[3]={0,1,2};		//무기 코드 
	char* kind[3]={"검","창","도끼"};
	int n;
	if(mode==0){
		printf("%s!\n",kind[number]);
		n = inventory(1,code[number],1);
		return n;
	}else if(mode==1){
		MC(4,0,stat[number],0,0,0);
		printf("%s을(를) 착용하였습니다.\n",kind[number]);
		inventory(1,code[number],-1);
		inventory(4,code[number],0); 
	}else if(mode==2){
		MC(4,0,-stat[number],0,0,0);
		printf("%s을(를) 착용해제하였습니다.\n",kind[number]);
		inventory(1,code[number],1);
	}
}
void statopen(int number){		//상점에서 구입시 즉시 스텟 증가(number 0=전기 충격기,1=레이저) 
	srand(time(NULL));
	int stat=10;
	char* kind[2]={"전기","화염"};
	static int num[2]={0,0};
	if(num[number]==0){
		printf("%s스텟이 개방되었습니다.\n",kind[number]);
		if(number==0){
			printf("전기스텟은 전투시 일정확률로 적을 공격시 적이 마비 상태에 빠지는 스텟입니다.\n");
		}else{
			printf("화염스텟은 전투시 스텟만큼 추가데미지가 들어가는 스텟입니다.\n");
		}
		num[number]++;
	}
	Sleep(1000);
	printf("%s스텟 %d 만큼 증가하였습니다.\n",kind[number],stat);
	if(number==0){
		MC(1,0,0,0,0,stat);
	}else if(number==1){
		MC(1,0,0,0,stat,0);
	}
}
int repair(int mode,int number){		//최대스텟 증가(mode 0=파밍,1=사용, number 0=힘,1=체력,2=공속) , 스텟 증가 정도는 언제든지 말해서바꿔도 됨 
	int code[3]={12,13,14};
	int stat[3]={5,10,7};
	char* kind[3]={"힘","체력","속도"};
	int n;
	if(mode==0){
		printf("수리도구(%s)!\n",kind[number]);
		n = inventory(1,code[number],1);
		return n;
	}else if(mode==1){
		printf("해당 최대 스텟이 %d만큼 증가 하였습니다.\n",stat[number]);
		inventory(1,code[number],-1);
		if(number==0){
			MC(1,5,0,0,0,0);	
		}else if(number==1){
			MC(1,0,10,0,0,0); 
		}else{
			MC(1,0,0,7,0,0);
		}	
	}
}
void bag(int number){		//가방수리 아이템 획득 표시(number 0=3증가,1=5증가) 
	int code[4]={3,5};
	printf("인벤토리 %d증가!\n",code[number]);
	inventory(0,0,code[number]);
}
int quest(int number){		//퀘스트아이템 획득 (number 0=철판,1=전선,2=전구,3=cpu,4=냉각기)
	int code[5]={17,18,19,20,21};
	char* kind[5]={"철판","전선","전구","cpu","냉각기"};
	printf("%s!\n",kind[number]);
	int n = inventory(1,code[number],1);
	return n;
}
void spirit(){ 		//정령알 구입시 함수 
	printf("정령알을 구입했다! 대단한데?\n");
	inventory(1,22,1); 
}
void NB(int mode){		//아이나비 함수 (mode 1=map1 2=map2 . . . 5=map5)
	int epx,epy;		//탈출좌표 함수 
	if(mode==1){		//각 맵마다의 탈출좌표 
		epx=13;
		epy=20;
	}else if(mode==2){
		epx=20;
		epy=17;
	}else if(mode==3){
		epx=8;
		epy=7;
	}else if(mode==4){
		epx=2;
		epy=0;
	}else if(mode==5){
		epx=20;
		epy=13;
	}
	printf("탈출구는 당신의 위치에서 X=%2d, X=%2d 차이가 납니다.\n", epx-x,epy-y); 
}
int dp(){		//패널티 무시권 획득 
	printf("패널티 무시권!\n");
	int n = inventory(1,24,1);
	return n;
}
void itemuse(int code,int mode){			//code 아이템 코드 mode 1=아이템 사용 (code가 0,1,2일때 2=무기 착용해제 , 23일때 맵순서)
	if(code==0||code==1||code==2){
		weapon(mode,code);
	}else if(code==12||code==13||code==14){
		repair(mode,code-12); 
	}else if(code==22){
		if(inventory(3, 22, 0) > 0)
			spirit_open(); 
	}else if(code==23){
		if(inventory(3, 23, 0) > 0)
			NB(mode); 
	}
}

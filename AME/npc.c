#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "item.h"
#include "inventory.h"

typedef struct NQ{			//NPC 
	int name;				//이름 
	char quest[100];			//퀘스트 관련 말 
	char talk[100];			//말걸면 나오는 첫번째 말 
	char endt[100];			//퀘스트를 거절했을때 나오는 말
	char sc[100];			//퀘스트 성공 
	int item;				//퀘스트 아이템 
}NQ;
void assist_c(int mode,int code){	//mode 0=npc이름 1=주인공 대사code=코드 
	if(mode==0){
		char* namekind[16]={"AND","Sari","VSV","ATM","IWC","DNA","RNA","WIN","DOW","PIZ","PIE","CIC","AIA","APP","COK","ILY"};
		printf("%s : ",namekind[code]);
	}else if(mode==1){
		char* talk[8]={"쉬러 온거야?\n","여길 계속 와도 괜찮겠어?\n","계속 방문해주는건 고맙지만 너무 시간낭비는 하지마. 별로 구경할것도 없거든\n","이제 거의 할말이 없는데..\n","음.. 반가워?\n","얼른가서 할일을 해야하지 않아?\n","과학자들은 여전히 정신이 나가있어?\n","아마 이 미로가 끝난다해도 끝난게 아닐꺼야\n"};
		printf("%s",talk[code]);
	}
}

int NPCsp(int mode,int who){
	static NQ need[2];
	static int number[2]={0,0},tem1,tem2;
	if(mode == -1){
		number[0] = 0;
		number[1] = 0;
		return ;
	}
	if(number[who]==0){
		srand(time(NULL));
		tem1=rand()%10;
		tem2=rand()%5;
		if(tem1==0){
			strcpy(need[who].endt,"그렇게 볼시간에 다른거라도 하러가지 그래?");
			need[who].name=tem2;
			strcpy(need[who].quest,"을 1개 사다줘.");
			need[who].item=22; 
			strcpy(need[who].sc,"비쌀텐데 잘 가져왔네?");
		}else{
			strcpy(need[who].endt,"어쩌라는 거야");
			need[who].name=tem2+5;
			strcat(need[who].quest," 1개 가져다줘.");
			need[who].item=tem2+17;
			strcpy(need[who].sc,"널리고 널린 아이템 가지고 오느라 수고했다.");
		}
		number[who]++;
		Sleep(1000);
	}
	assist_c(0,need[who].name);
	if(mode==0){			//시작 인사 
		printf("왜그렇게 쳐다보는거야?\n");
	}else if(mode==1){		//퀘스트 출력 및 아이템코드 반환
		assist_i(need[who].item);
		printf("%s\n",need[who].quest);
		return need[who].item;
	}else if(mode==2){		//끝인사 
		printf("%s\n",need[who].endt); 
	}else if(mode==3){		//퀘스트 완료 
		printf("%s\n",need[who].sc);
		number[who]=0;
	}
}
void NPCs(int who){		//npc출력(who 0=1번째 npc,1=2번째 npc)
	static int gq[2]={0,0},code[2];			//NPC의 퀘스트를 받았는가 확인
	if(who == -1){
		gq[0] = 0;
		gq[1] = 0;
		return ;
	}
	int answer,num;
	char ans;
	NPCsp(0,who);
	if(gq[who]==0){
		Sleep(500);
		printf("\n이야기를 할까?- 1    그냥튀자 제정신이 아닌것같다- 2\n\n");
		do{
			printf(">>> "); scanf("%c",&ans); if(ans == 10) continue; while ((getchar()) != '\n');
			answer = ans - '0';	
		}while(!(answer==2||answer==1));
		if(answer==1){
			code[who]=NPCsp(1,who);
			gq[who]++;
		}else if(answer==2){
			NPCsp(2,who);
		}
	}else{
		num=inventory(3,code[who],0);
		if(num>0){
			printf("퀘스트 아이템을 건네주었다.\n");
			NPCsp(3,who);
			inventory(1,code[who],-1);
			if(code[who]==22){
				money(1,1000);			//정령알 퀘스트 
			}else{
				money(1,200);				//나머지 퀘스트 
			}
			gq[who]=0; 
		}
	}
}
int NPCfp(int mode,int who){			//페어 퀘스트 npc구현1
	static NQ need[2];
	static int number=0,tem1,tem2;
	if(mode == -1){
		number = 0;
		return ;
	}
	if(number==0){
		srand(time(NULL));
		tem1=rand()%3;
		tem2=rand()%5;
		strcpy(need[0].talk,"왜?");
		need[0].item=tem2+17;
		need[0].name=tem1+10;
		strcpy(need[1].talk,"대체 언제 오는거야..");
		need[1].name=tem1+13;
		Sleep(1000);
		number++;
	}
	assist_c(0,need[who].name);
	if(mode==0){			//who의 첫인사 
		printf("%s\n",need[who].talk);
	}else if(mode==1){		//주는쪽의 끝말 
		printf("볼시간이 있으면 내 의뢰나 도와주지?\n");
	}else if(mode==2){		//주는쪽의 퀘스트 
		assist_i(need[who].item);
		printf(" 1개 의뢰자에게 전해줘. 위치는 알아서 찾아봐.\n");
		return need[0].item; 
	}else if(mode==3){		//받는쪽의 퀘스트 완료 
		printf("늦었잖아. 이런거 하나 들고오는데 얼마나 걸리는거야.\n");
		number=0;
	}
}
void NPCf(int who){	//페어퀘스트를 주는 npc 구현
	static int number=0,gq=0,code;
	if(who = -1){
		number = 0;
		gq = 0;
		return ;
	}
	int answer,num;
	char ans;
	NPCfp(0,who);
	if(who==0&&gq==0){
		Sleep(500);
		printf("\n이야기를 할까?- 1\t그냥튀자- 2\n\n");
		do{
			scanf("%c",&ans);	while ((getchar()) != '\n');
			answer = ans - '0';
		}while(!(answer==2||answer==1));
		if(answer==1){
			code=NPCfp(2,0);
			gq++;
		}else if(answer==2){
			NPCfp(1,0);
		}
	}else if(who==1&&gq==1){
		num=inventory(3,code,0);
		if(num>0){
			printf("퀘스트 아이템을 건네주었다.\n");
			NPCfp(3,0);
			inventory(1,code,-1);
			money(1,350);
			gq=0;
		}
	}
}
int trashMC(int i){			//부서진 주인공(탈출구 알려주는 npc) 
	static int gq=0,tem1;
	if(i==-1){
		gq = 0;
		return ;
	}
	int num;
	if(gq==0){
		printf("부서진 '당신' : 안녕.\n\n");
		printf("이야기를 합니다\n\n");
		printf("부서진 '당신' : 갑자기 이런 부탁을 해서 미안하지만 정령알을 하나 사와줄수 있을까?\n");
		gq++;
	}else{
		srand(time(NULL));
		tem1=rand()%8;
		printf("부서진 '당신' : ");
		assist_c(1,tem1);
		num=inventory(3,22,0);
		Sleep(1000);
		if(num>0){
			printf("퀘스트 아이템을 건네주었다.\n");
			printf("부서진 '당신' : 고마워 보수로 이걸줄게 아마 탈출구로 갈 수 있을거야.\n");
			inventory(1,22,-1);
			Sleep(1000);
			printf("IBuf를 얻었다! 탈출구의 위치를 알게되었습니다.\n");
			inventory(1,23,1); 
			money(1,625);
			printf("부서진 '당신' : 잘가\n"); 
			return 1;
		}
	}	
}

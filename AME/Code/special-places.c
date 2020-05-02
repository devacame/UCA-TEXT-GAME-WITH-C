#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include "mc.h"
#include "item.h"
#include "npc.h"

char* pName(char p){  //장소 이름 출력용 함수 (지울 가능성 다) 
	switch(p){
		case 'e':
			return "탈출구";
		default:
			return "쉼터/자판기";
	}
}
 
void resting_area(int p, int mode){ //쉼터 함수  
	static int remainder[4] = {6, 6, 6, 6}; //쉼터 입장제한
	if(mode == 1){
		remainder[0] = 6;
		remainder[1] = 6;
		remainder[2] = 6;
		remainder[3] = 6;
		return ;
	}
	srand(time(NULL)); 
	if(remainder[p-2] == 0){ //p-2인 이유는 쉼터의 id가 2부터 시작함 만일 횟수가 0이면 입장불가  
		printf("%d번 회귀자의 쉼터는 더이상 들어갈 수 없습니다. 경고는 충분히 드렸을텐데요.\n");
		return ;
	}
	--remainder[p-2]; //입장횟수 감소
	printf("%d번 회귀자의 쉼터에 도착하셨습니다.\n");
	MC(3, 0, 0, 0, 0, 0); //힐링 
	NPCs(rand()%2); //퀘스트  
	int temp=0, tem = 0;
	if(rand()%1000000 == 153427 || temp > 0){
		tem = trashMC(0);
		temp++;
		if(tem == 1){
			temp = 0;
		}
	} 
}

void vending_machine(){ 
	puts("-------------자판기-------------");
	printf("\t1: 물양동이-750G 2: 힘 버프(7증가) -175G 3: 힘 버프(10증가) -250G \n4: 속도 버프(7증가) -175G 5: 속도 버프(10증가) -250G 6: 힘 디버프(7감소) -225G \n\t7: 힘 디버프(10감소) -300G 8: 속도 디버프(7감소) -225G 9: 속도 디버프(10감소) -300G \n10: 수리도구(체력10영구증가) -500G 11: 수리도구(힘10영구증가) -500G 12: 수리도구(속도10영구증가) -500G \n\t13: 인벤토리 3칸증가 -300G 14: 인벤토리 5칸 증가 -450G 15: 전기충격기 -1800G \n16: 레이져 -1800G 17: 정령알 -5000G 18: 패널티 무시권 -소지금의 1/4(소지금이 4000G이상일경우)\n");
	puts("--------------------------------");
	puts("아이템 번호를 입력하세요. 나가려면 0을 입력하세요");
	int cmd=-1; 
	for(;cmd!=0;){
		money(0,0);
		printf(">> "); scanf("%d", &cmd);
		if(cmd == 0) return ;
		switch(cmd){
			case 1:
				if(money(3,0) >= 750){
					de_buff(2,0);
					money(1,-750);	
				}else{
					puts("돈, 없으면서 뭘 사려고?");
				}
				break;
			case 2:
				if(money(3,0) >= 175) {
					de_buff(0,0);
					money(1,-175);
				}else{
					puts("돈, 없으면서 뭘 사려고?");
				}
				break;
			case 3:
				if(money(3,0) >= 250){
					de_buff(0,1);
					money(1,-250);	
				}else{
					puts("돈, 없으면서 뭘 사려고?");
				}
				break;
			case 4:
				if(money(3,0) >= 175) {
					de_buff(0,2);
					money(1,-175);
				}else{
					puts("돈, 없으면서 뭘 사려고?");
				}
				break;
			case 5:
				if(money(3,0) >= 250){
					de_buff(0,3);
					money(1,-250);	
				}else{
					puts("돈, 없으면서 뭘 사려고?");
				}
				break;
			case 6:
				if(money(3,0) >= 175) {
					de_buff(1,0);
					money(1,-175);
				}else{
					puts("돈, 없으면서 뭘 사려고?");
				}
				break;
			case 7:
				if(money(3,0) >= 250){
					de_buff(1,1);
					money(1,-250);	
				}else{
					puts("돈, 없으면서 뭘 사려고?");
				}	
				break;
			case 8:
				if(money(3,0) >= 175) {
					de_buff(1,2);
					money(1,-175);
				}else{
					puts("돈, 없으면서 뭘 사려고?");
				}
				break;
			case 9:
				if(money(3,0) >= 250){
					de_buff(1,3);
					money(1,-250);	
				}else{
					puts("돈, 없으면서 뭘 사려고?");
				}
				break;
			case 10:
				if(money(3,0) >= 500){
					repair(0, 1);
					money(1,-500);	
				}else{
					puts("돈, 없으면서 뭘 사려고?");
				}			
				break;
			case 11:
				if(money(3,0) >= 500){
					repair(0, 0);
					money(1,-500);	
				}else{
					puts("돈, 없으면서 뭘 사려고?");
				}	
				break;
			case 12:
				if(money(3,0) >= 500){
					repair(0, 2);
					money(1,-500);	
				}else{
					puts("돈, 없으면서 뭘 사려고?");
				}
				break;
			case 13: 
				if(money(3,0) >= 300){
					bag(0, 0);
					money(1,-300);	
				}else{
					puts("돈, 없으면서 뭘 사려고?");
				}					 
				break;
			case 14: 
				if(money(3,0) >= 450){
					bag(0,1);
					money(1,-450);	
				}else{
					puts("돈, 없으면서 뭘 사려고?");
				}					
				break;
			case 15:
				if(money(3,0) >= 1800){
					statopen(0);
					money(1,-1800);	
				}else{
					puts("돈, 없으면서 뭘 사려고?");
				}					
				break;
			case 16:
				if(money(3,0) >= 1800){
					statopen(1);
					money(1,-1800);	
				}else{
					puts("돈, 없으면서 뭘 사려고?");
				}					
				break;
			case 17:
				if(money(3,0) >= 5000){
					spirit();
					money(1,-5000);	
				}else{
					puts("돈, 없으면서 뭘 사려고?");
				}
				break;
			case 18:
				if(money(3,0) >= 4000){
					dp();
					money(1, -(money(3,0)/4));
				}else{
					puts("돈, 없으면서 뭘 사려고?");
				}
				break;
		}
	}
}


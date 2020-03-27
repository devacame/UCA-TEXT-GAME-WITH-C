#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "special-places.h"
//#include "custom header"

int fight(/*charset enemy, charstat player,*/ char p){
	srand(time(NULL));
//	int enestat[5] = [enemy.hp, enemy.speed, enemy.str, enemy.fire, enemy.elect];
//	int playstat[5] = [player.hp, player.speed, player.str, player.fire, player.elect];
//	char* eRoar[] = {"참격!", "월광참!", "슈퍼울트라어쩌구저쩌구공격!", "걍 공격!", "개발자 말 떨어졌다 공격!"};
//	char* pRoar[] = {"명월참격!", "별빛조각술!", "투명룡공격!", "(중2병 공격)", "(대충 공격하는 말)"}
//	char* pInput; 
//	int efireDmg = 0, pfireDmg = 0, eParal = 0, pParal = 0;
//	for(;;){
//		if(enestat[0] < 0 && playstat[0] > 0){
//			printf("축하합니다! %s를 처치하고 \"%s 출입권한(1회용)\"을 획득했습니다!", enemy.name, pName(p));
//			MC(playstat[0], playstat[2], playstat[1]);
//			return 0;
//		} else if(enestat[0] > 0 && playstat[0] < 0){
//			printf("와 어떻게 %s같은 약체한테 지냐...다시해라", enemy.name);
//			death();
//			return 1;
//		}
//		if(enestat[1] >= platstat[1]){
//			if(eParal > 0){
//				eParal--;
//				continue;
//			}
//			printf("%s가 너보다 빠름\n", enemy.name);
//			if(enestat[3] > playstat[3]){
//				efireDmg = enestat[3] - playstat[3];
//			}else{
//				efireDmg = 0;
//			}
//			if(enestat[4] > playstat[4]){
//				if(rand()%5 == 3){
//					eParal = (enestat[4] - playstat[4])%7+1;
//				}
//			}
//			printf("%s의 %s\n", enemy.name, eRoar[rand()%5]);
//			playstat[0] -= enestat[2] + efireDmg;
//		}else{
//			if(pParal > 0){
//				pParal--;
//				continue;
//			}
//			puts("지금은 님이 더 빠름");
//			printf("그럼 이제 뭐할거임? 공격-"atk", 아이템 사용-"inven"  : ");
//			while(1){
//				scanf("%s", pInput);
//				if(strcmp(pInput, "atk") !=0 || strcmp(pInput, "inven") !=0){
//					printf("\n뭐하는거냐 제대로 입력안해? : ");
//					continue; 
//				}else{
//					if(strcmp(pInput, "atk")==0){
//						if(enestat[3] < playstat[3]){
//							pfireDmg = -enestat[3] + playstat[3];
//						}else{
//							pfireDmg = 0;
//						}
//						if(enestat[4] < playstat[4]){
//							if(rand()%5 == 3){
//								pParal = (playstat[4] - enestat[4])%7+1;
//							}
//						}
//						printf("%s의 %s\n", player.name, pRoar[rand()%5]);
//						enestat[0] -= playstat[2] + pfireDmg;
//					}else{
//						//inventory
//					}
//				}
//			}
//		}
//	}
}

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include "special-places.h"
#include "mc.h"
#include "item.h"
#include "deathevent.h"
#include "inventory.h" 

void fight(char p, int id){
	srand(time(NULL));
	charset player = MC(0, 0, 0, 0, 0, 0);
	charset enemy = pawn();
	if(id == 6){
		charset enemy = pawn();
	}else{
		charset enemy = king();
	}
	Sleep(1500);
	puts("싸움이 곧 시작됩니다. 뭐 건투를 빌도록 하죠");
	int enestat[5] = {enemy.hp, enemy.speed, enemy.str, enemy.fire, enemy.elect};
	int playstat[5] = {player.hp, player.speed, player.str, player.fire, player.elect};
	char* eRoar[5] = {"참격!", "월광참!", "슈퍼울트라어쩌구저쩌구공격!", "걍 공격!", "개발자 말 떨어졌다 공격!"};
	char* pRoar[5] = {"명월참격!", "별빛조각술!", "투명룡공격!", "(중2병 공격)", "(대충 공격하는 말)"};
	char pInput, cmdC;
	int cmd; 
	int efireDmg = 0, pfireDmg = 0, eParal = 0, pParal = 0;
	while(1){
		Sleep(100);
		if(enestat[0] < 0 && playstat[0] > 0){ //승리시  
			printf("축하합니다! %s를 처치하고 [%s 출입권한(1회용)]을 획득했습니다!", enemy.name); //적 처리 및 출력  
			MC(2, playstat[0], playstat[2], playstat[1], 0, 0); //스탯 업데이트  
			return;
		} else if(enestat[0] > 0 && playstat[0] < 0){ //패배시  
			printf("와 어떻게 %s같은 약체한테 지냐...다시해라", enemy.name);
			Sleep(500);
			death(); //죽었을때 실행하는 함수 
			return;
		}
		if(enestat[1] >= playstat[1]){ //적이 공격 우선도를 가질때  
			if(eParal > 0){ //마비 여부 판단  
				eParal--;
				continue;
			}
			printf("%s가 너보다 빠름\n", enemy.name);
			if(enestat[3] > playstat[3]){
				efireDmg = enestat[3] - playstat[3]; //화염 데미지 측정  
			}else{
				efireDmg = 0;
			}
			if(enestat[4] > playstat[4]){
				if(rand()%5 == 3){
					eParal = (enestat[4] - playstat[4])%7; //마비 여부 측정  
				}
			}
			printf("%s의 %s\n", enemy.name, eRoar[rand()%5]);
			playstat[0] -= (enestat[2] + efireDmg); //공격  
		}else{ //플레이어 공격 우선시 
			if(pParal > 0){
				pParal--;
				continue;
			}
			puts("지금은 님이 더 빠름");
			printf("그럼 이제 뭐할거임? 공격-0, 아이템 사용-1  : ");
			while(1){
				printf(">>> "); scanf("%c", &cmd); while ((getchar()) != '\n');  //커맨드 입력  
				if(pInput-'0' != 0 && pInput-'0' != 1){ //입력이 제대로 되지 않을때 다시 하기  
					printf("\n뭐하는거냐 제대로 입력안해? : ");
					continue; 
				}else{
					if(pInput==0){ //공격 실행되는 것들은 적 코드와 동일  
						if(enestat[3] < playstat[3]){
							pfireDmg = -enestat[3] + playstat[3];
						}else{
							pfireDmg = 0;
						}
						if(enestat[4] < playstat[4]){
							if(rand()%5 == 3){
								pParal = (playstat[4] - enestat[4])%7;
							}
						}
						printf("%s  a\n", &player.name);
						printf("%s의 %s\n", &player.name, pRoar[rand()%5]);
						enestat[0] -= (playstat[2] + pfireDmg);
						break;
					}else{ 
						puts("----------배틀에 사용할 수 있는 아이템들(1턴에 1개|번호입력)----------");
						printf("1: 힘버프(7)     -%4d개   2: 힘버프(10) -%4d개   	 3: 속도버프(7) -%4d개 \n4: 속도버프(10)  -%4d개   5: 힘디버프(7) -%4d개      6: 힘디버프(10) -%4d개 \n7: 속도디버프(7) -%4d개   8: 속도디버프(10) -%4d개   9: 물양동이 -%4d개\n", inventory(3,4,0),inventory(3,5,0),inventory(3,6,0),inventory(3,7,0),inventory(3,8,0),inventory(3,9,0),inventory(3,10,0),inventory(3,11,0),inventory(3,3,0));
						int cmd, t = 0;
						while(1){
							printf(">>>> "); scanf("%c", &cmdC); while ((getchar()) != '\n'); 
							cmd = cmdC - '0';
							if(cmd<1 || cmd>9){
								puts("숫자 잘못 넣었네? 제대로 넣자");
								continue; 
							}
							else if(cmd>=1 && cmd<=9){
								t++;
								cmd += 3;
								if(cmd==4){
									if(inventory(3, cmd, 0) <=0) {
										puts("번호 제대로 눌렀어야지 쯧쯧 기회 끝?");
										break; 
									}
									inventory(1,4,-1);
									playstat[2] += 7;
									puts("힘이 7만큼 증가했습니다.");
									break;
								}else if(cmd==5){
									if(inventory(3, cmd, 0) <=0) {
										puts("번호 제대로 눌렀어야지 쯧쯧 기회 끝?");
										break; 
									}
									inventory(1,5,-1);
									playstat[2] += 10;
									puts("힘이 10만큼 증가했습니다.");
									break;
								}else if(cmd==6){
									if(inventory(3, cmd, 0) <=0)  {
										puts("번호 제대로 눌렀어야지 쯧쯧 기회 끝?");
										break; 
									}
									inventory(1,6,-1);
									playstat[1] += 7;
									puts("속도가 7만큼 증가했습니다.");
									break;
								}else if(cmd==7){
									if(inventory(3, cmd, 0) <=0)  {
										puts("번호 제대로 눌렀어야지 쯧쯧 기회 끝?");
										break; 
									}
									inventory(1,7,-1);
									playstat[1] += 10;
									puts("속도가 10만큼 증가했습니다.");
									break;
								}else if(cmd==8){
									if(inventory(3, cmd, 0) <=0)  {
										puts("번호 제대로 눌렀어야지 쯧쯧 기회 끝?");
										break; 
									}
									inventory(1,8,-1);
									enestat[2] -= 7;
									puts("적의 힘이 7만큼 줄었습니다.");
									break;
								}else if(cmd==9){
									if(inventory(3, cmd, 0) <=0)  {
										puts("번호 제대로 눌렀어야지 쯧쯧 기회 끝?");
										break; 
									}
									inventory(1,9,-1);
									enestat[2] -= 10;
									puts("적의 힘이 10만큼 줄었습니다.");
									break;
								}else if(cmd==10){
									if(inventory(3, cmd, 0) <=0)  {
										puts("번호 제대로 눌렀어야지 쯧쯧 기회 끝?");
										break; 
									}
									inventory(1,10,-1);
									enestat[1] -= 7;
									puts("적의 속도가 7만큼 줄었습니다.");
									break;
								}else if(cmd==11){
									if(inventory(3, cmd, 0) <=0)  {
										puts("번호 제대로 눌렀어야지 쯧쯧 기회 끝?");
										break; 
									}
									inventory(1,11,-1);
									enestat[1] -= 10;
									puts("적의 속도가 10만큼 줄었습니다."); 
									break;
								}else if(cmd==12){
									if(inventory(3, 3, 0) <=0)  {
										puts("번호 제대로 눌렀어야지 쯧쯧 기회 끝?");
										break; 
									}
									inventory(1,3,-1);
									eParal+=5;
									puts("적이 5턴간 스턴됩니다.");
									break;
								}
							} 
						}
						if(t!=0)continue;
					}
				}
			}
		}
	}
}

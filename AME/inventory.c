#include <stdio.h>
#include "spirit-type.h"
#include "item.h"
#include "mc.h"
#include "map.h"

extern int itemList[];

int inventory(int mode,int item,int size){		//인벤토리(mode 0=인벤토리 증가,1=파밍또는 아이템 소모,2=인벤토리출력,3=아이템 갯수 item=선택할 아이템 코드, size=인벤토리 증가량 또는 아이템증가감소량) 
	static int ivsize=6,inven[25]={0,},pocket[25]={0,},weaponC=3;
	if(mode==0){			//인벤토리 증가 
		printf("인벤토리의 공간이 %d만큼 늘었다.\n",size);
		ivsize+=size;
		if(ivsize>25){
			printf("이곳의 소유할 수 있는 아이템 종류들을 모두 모아도 25개야. 뭘 그렇게 욕심내는거야? 더이상 늘릴수없어.\n");
			ivsize=25;
		}
	}else if(mode==1){		//아이템(item) 증가 및 감소(size) 인벤토리 구성 
		int tem0=0,use=-1;
		for(;tem0<ivsize;tem0++){
			if(inven[tem0]==0){
				use=tem0;
				break;
			}	
		}
		if(!(pocket[item]==0)){
			pocket[item]+=size; 
		}else if(use==-1){
			printf("하지만 인벤토리가 이미 차있다고요 될리가 있나.\n");
			return -1; 
		}else if(pocket[item]==0&&inven[use]==0&&size>0){		
			inven[use]=item+1;			//inven에 아이템코드+1을 넣음 
			pocket[item]=size;
		}
		if(pocket[item]==0){
			int tem1=0;
			for(;tem1<ivsize;tem1++){
				if(inven[tem1]==item+1){
					inven[tem1]=0;	
				}
			}
		}else if(pocket[3]==2){
			printf("하지만 이미 물양동이를 가진 채로 들고가려 했기때문에 물을 엎질렀습니다. 과유불급도 몰라요?\n");
			itemList[4]++;
			pocket[3]--; 
		}
	}else if(mode==2){		//인벤토리 출력 
		int tem2=0,answer=0;
		//charset p = MC(0,0,0,0,0,0);
		printf("%s의 인벤토리\n", MC(0,0,0,0,0,0).name);
		printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
		for(;tem2<ivsize;tem2++){
			if(inven[tem2]==0){
				printf("---\n");
			}else{
				assist_i(inven[tem2]-1);
				printf(" : %03d",pocket[inven[tem2]-1]);
				if(inven[tem2]==1||inven[tem2]==2||inven[tem2]==3||inven[tem2]==13||inven[tem2]==14||inven[tem2]==15||inven[tem2]==16||inven[tem2]==17||inven[tem2]==23||inven[tem2]==24){
					printf(" - %d",tem2+1);
				}
				printf("\n");
			}	 
		}
		printf("\n장비 : ");
		if(weaponC==3){
			printf("없음");
		}else{
			 assist_i(weaponC);
		}
		printf("\n정령 : "); 
		print_cSpirit();
		printf("\n");
		money(0,0);
		printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n아이템을 사용하려면 해당 위치의 번호를 입력하세요.(사용가능한 아이템만 번호가 뜹니다.)\n장비를 해제하려면 -1를, 나가려면 0을 누르시오.\n");
		char cm;
		do{ 
			printf(">>> "); scanf("%d",&answer); while ((getchar()) != '\n');
		}while(!(answer<=ivsize&&answer>=-1));
		if(answer==-1&&!(weaponC==3)){		//무기 해제 
			int tem3=0,num=0,stat[3]={15,25,45};
			for(;tem3<ivsize;tem3++){		//인벤토리 공간 체크 
				if(inven[tem3]==0){
					num++;
					break;
				}
			}
			if(num==0){			//인벤토리에 공간이 없을시
				printf("인벤토리에 공간이 없어요. 다시 비우고 오시던가\n");
			}else if(num>=1){				//무기 장착해제 
				itemuse(weaponC,2);
				weaponC=3;
				num=0;
			} 
		}else if(answer>0){
			if(inven[answer-1]==0){
				printf("해당 칸에는 아이템이 존재하지 않아요.\n");
			}else if(inven[answer-1]==24){
				int map = idRT(0);//여기다가 맵 번호 넣어야함 전역변수로 넣으면 될것같은데 
				itemuse(23, map);
			}else{
				itemuse(inven[answer-1]-1,1);
			}
		}
	}else if(mode==3){			//인벤토리 item의 갯수 반환 
		return	pocket[item];
	}else if(mode==4){			//무기 장착 item 0=검,1=창,2=도끼
		int stat[3]={15,25,45}; 
		if(weaponC != 3){
			puts("어라? 무기가 있었네?");
			itemuse(weaponC, 2);
			MC(4,0,-stat[weaponC], 0, 0, 0);
		}
		weaponC = item;
	}else if(mode == 5){
		int i;
		for(i=0;i<24;i++){
			inven[i] = 0;
			pocket[i] = 0;
		}
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct charset{		//캐릭터와 적 설정 
	char* name;			    	//이름 
	int hp;						//체력 
	int speed;					//공속 
	int str;					//힘 
	int fire;					//속성(불) 
	int elect; 					//속성(전기) 
}charset;

charset MC(int mode, int hp, int str, int speed, int fire, int elect){	//주인공 스텟 관련 함수(mode 0=현재 스텟 리턴,1=최대스텟 증가,2=배틀스텟계승,3=스텟회복,4=무기스텟,나머지 인자는 증가나 계승시킬 스텟 수) 
	static charset player,maxMC,basic;
	static int istat;
	static int num=0;
	srand(time(NULL));
	if(num==0){
		player.name = "Android-2253";
		player.speed=(rand()%11+10);
		player.hp=100;
		player.str=(rand()%11+10);
		player.elect=0;
		player.fire=0;
		maxMC=player;
		basic=player;
		num++;
	}
	if(mode==0){				//현재 mc의 스텟을 리턴
		return player;
	}else if(mode==1){			//최대 스텟 증가 
		maxMC.hp+=hp;
		maxMC.str+=str;
		maxMC.speed+=speed;
		player.fire+=fire;
		player.elect+=elect;
	}else if(mode==2){			//배틀후 현재 스텟 계승 
		player.hp=hp;
		player.speed=speed;
		player.str=str;
	}else if(mode==3){			//스텟 회복 
		player.hp=maxMC.hp;
		player.speed=maxMC.speed;
		player.str=maxMC.str;
		player.str+=istat;
		printf("모든 스텟이 원상태로 돌아왔다.\n");
	}else if(mode==4){         //무기장착로 인한 힘스텟 상승또는 하락 
        if(str>0){
       		istat=str;
        	player.str+=istat;
        }else{
        	player.str+=str;
        	istat=0;
    	}
	}else if(mode==5){			//사망시 패널티 적용 
		basic.elect/=2;
		basic.fire/=2;
		basic.hp/=2;
		basic.speed/=2;
		basic.str/=2;
		maxMC.hp-=basic.hp;
		maxMC.str-=basic.str;
		maxMC.speed-=basic.speed;
		player.fire-=basic.fire;
		player.elect-=basic.elect;
	}else if(mode==6) num=0;
}
charset pawn(){					//쫄병랜덤스텟 한꺼번에 만들어버림 	
	srand(time(NULL));
	charset pn;
	pn.name = "P-2023";
	pn.hp=(rand()%201+300);
	pn.speed=(rand()%26+35);
	pn.str=(rand()%26+35);
	pn.elect=(rand()%26+35);
	pn.fire=(rand()%26+35);
	return pn;
} 
charset king(){					//고렙문지기 스텟 고정	 +)맵만들면서 놓기 
	charset kg;
	kg.name = "K-3605";
	kg.hp=1000;
	kg.speed=100;
	kg.str=100;
	kg.fire=70;
	kg.elect=70;
	return kg;
} 

#ifndef MC_H
#define MC_H

typedef struct charset{		//캐릭터와 적 설정 
	char* name;			    	//이름 
	int hp;						//체력 
	int speed;					//공속 
	int str;					//힘 
	int fire;					//속성(불) 
	int elect; 					//속성(전기) 
}charset;

charset MC(int mode, int hp, int str, int speed, int fire, int elect);

charset pawn();

charset king();

#endif

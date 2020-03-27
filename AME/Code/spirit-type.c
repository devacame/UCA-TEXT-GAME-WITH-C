#include <stdio.h>
#include <time.h>

typedef struct Spirit{
	char* name;
	int stat;
}Spirit;

Spirit Ifrit(){
	Spirit Ifrit;
	Ifrit.name = "이프리트";
	Ifrit.stat = 100;
	return Ifrit;
}

Spirit Electron(){
	Spirit Electron;
	Electron.name = "일렉트론";
	Electron.stat = 100;
	return Electron;
}
	
Spirit Aegis(){
	Spirit Aegis;
	Aegis.name = "아이기스";
	Aegis.stat = 50;
	return Aegis;
}
	


void spirit_open(){
	static int arr[3] = {0,}; //index 0 = ifrit 1 = electron 2 = aegis
	(unsigned)srand(time(NULL));
	//화면  
	if(rand()%100 == 15){
		int temp = rand() % 3;
		for(;;){
			if(arr[temp] == 0){
				arr[temp] = 1;
				//screen
				switch(temp){
					case 0:
						//update_stat(fire = Ifrit().stat);
						//screen
						break;
					case 1:
						//update_stat(fire = Electron().stat);
						//screen
						break;
					case 2:
						//update_stat(fire = Aegis().stat);
						//screen
						break;
				}
				break;
			}else{
				continue;
			}	
		}
	}else{
		//screen
	}
}


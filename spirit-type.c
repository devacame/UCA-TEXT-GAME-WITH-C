#include <stdio.h>

typedef struct Types{
	char* name;
	int stat;
}Type;

typedef struct Spirits{
	char* name;
	Type type;
}Spirit;

int main(void){
	Spirit Ifrit;
	Ifrit.name = "이프리트";
	Ifrit.type.name = "fire";
	Ifrit.type.stat = 100;
	
	Spirit Electron;
	Electron.name = "일렉트론";
	Electron.type.name = "electric";
	Electron.type.stat = 100;
	
	Spirit Aegis;
	Aegis.name = "아이기스";
	Aegis.type.name = "normal";
	Aegis.type.stat = 100;
}



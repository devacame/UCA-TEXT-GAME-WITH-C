typedef struct Types{
	char* name;
	int stat;
}Type;

typedef struct Spirits{
	char* name;
	Type type;
}Spirit;

Spirit Ifrit();
Spirit Electron();
Spirit Aegis();
Spirit spirit(char type);


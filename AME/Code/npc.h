typedef struct NQ{			//NPC 
	int name;				//이름 
	char* quest;			//퀘스트 관련 말 
	char* talk;			//말걸면 나오는 첫번째 말 
	char* endt;			//퀘스트를 거절했을때 나오는 말
	char* sc;			//퀘스트 성공 
	int item;				//퀘스트 아이템 
}NQ;
void assist_c(int mode,int code);
int NPCsp(int mode,int who);
void NPCs(int who);
int NPCfp(int mode,int who);
void NPCf(int who);
void trashMC();

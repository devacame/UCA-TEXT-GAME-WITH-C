#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include "inventory.h"
#include "mc.h"

extern x;
extern y;
extern spi_chk[];

void death(){			//죽음 이벤트&패널티 무시권 사용 
	printf("사망하셨습니다.\n걱정하지 마세요. 당신의 돈의 절반을 가져가서 고칠꺼니까.\n그정도면 다시 시작하는것보단 이득이지 않나?\n\n\n");
	money(2,0);
	Sleep(700);
	printf("수리는 끝났습니다. 근데 문제가 있어요.\n\n여기에서 제대로 수리는 못하는 환경이거든요. 그래서 아마 처음에 줬던 스텟있죠? 그게 반정도 깎일거에요.\n");
	Sleep(50);
	printf("그런 상황을 피하고 싶다면 좀더 수리비용을 줘야해요.\n수리하시겠어요?\n\n");
	int an,dp=inventory(3,24,0),num=0;
	char answer;
	Sleep(100);
	printf("수리해줘-1 싫어 차라리 깎이고 말지-2\n");
	do{
		scanf("%c",&answer);
		an=answer-'0';
		num++;
	}while(an!=1 && an!=2 && num<5);
	if(dp>0){
		printf("잠깐만 그러고보니 패널티무시권이 있었잖아? 세상에 그냥 패널티 맞을뻔했네.\n그냥가요 이제 보충수리는 공짜니까 스텟걱정은 말고.\n");
		inventory(1,24,-1); 
	}else if(an==1){
		printf("오 좋아요. 그러면 보충수리를 시작하도록하죠.\n\n\n");
		Sleep(700);
		printf("예 끝났어요 그럼 시작지점에서 다시 시작하세요.\n돈은 얼마나 가져갔나고요? 다시가서 확인해봐요~\n");
		money(2,0);
	}else if(an==2){
		printf("거절하다니 아이템이 빵빵하다는건가?\n어쩔수없죠 그럼 그냥 가요. 맞다, 아까 말하지 못했는데 혹시몰라요? 인벤토리에 구멍이 나서 정령이 사라졌을지도~\n에이 긴장풀어요 설마 그런일이 있을까\n");
		MC(5,0,0,0,0,0);
		srand(time(NULL));
		if(rand()%1000 == 728) spi_chk[rand()%3] = 0;
	}else if(num==5){
		printf("뭐해요? 계속 장난칠 시간이 있으면 가서 노가다나 더하시죠?\n\n");
		Sleep(700);
		printf("좋아요 그 별볼일 없는 스텟 더 깎아드렸어요. 뭘깎았냐고요?\n노가다하라고 전체스텟좀 깎았어요 ㅊㅎㅊㅎ\n이제가서 노가다나 하세요\n");
		MC(5,0,0,0,0,0);
		MC(5,0,0,0,0,0);
	}
	num=0;
	MC(3,0,0,0,0,0);
	x = 10; y = 10;//여기다가 다시 시작지점으로 mc좌표 옮기는 코드 필요 
}

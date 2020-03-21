#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <conio.h>
#include "event_screen.h"
#include "spirit-type.h"

int main(void) {
	start_screen();
	
	printf("%s", spirit('f').name);
	return 0;
}

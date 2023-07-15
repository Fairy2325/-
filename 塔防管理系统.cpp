#include"Game.h"

int main(void)
{
	initgraph(1280, 960);
	PlaySound(TEXT("res\\bgm.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	for (;;) {
		cleardevice();
		Menu();
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

typedef struct tabuleiro {
	char tab[100][100];
	int lins;
	int cols;
} tabuleiro;
typedef char bool;

bool e_seg(char c) {
	return c != '~' && c != '.';
}

int contar_segs(tabuleiro t, bool lin, int num) {
	int i;
	int x = 0, y = 0, dx = 0, dy = 0, tam = 0;
	int count = 0;

	if(lin) {
		y = num - 1;
		dx = 1;
		tam = t.lins;
	} else {
		x = num - 1;
		dy = 1;
		tam = t.cols;
	}

	for(i = 0; i < tam; i++) {
		if(e_seg(t.tab[y][x]))
			count++;
		x += dx;
		y += dy;
	}

	return count;
}

int main() {
	tabuleiro tab;
	tab.lins = 10;
	tab.cols = 10;
	strcpy(tab.tab[0], "~~~~~~~~~~");
	strcpy(tab.tab[1], "~~~~^~~~~~");
	strcpy(tab.tab[2], "~~O~#~~<#>");
	strcpy(tab.tab[3], "~~~~#~~~~~");
	strcpy(tab.tab[4], "~~~~v~~~~^");
	strcpy(tab.tab[5], "~~~~~~~~~v");
	strcpy(tab.tab[6], "~~~<>~~~~~");
	strcpy(tab.tab[7], "<>~~~~~O~O");
	strcpy(tab.tab[8], "~~~~~O~~~~");
	strcpy(tab.tab[9], "~<#>~~~~~~");

	int i;
	for(i = 1; i <= 10; i++)
		printf(" %d", contar_segs(tab, 1, i));
	putchar('\n');
	for(i = 1; i <= 10; i++)
		printf(" %d", contar_segs(tab, 0, i));
	putchar('\n');
	return 0;
}

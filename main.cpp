#include <iostream>
#include <stdlib.h>
#include <memory.h>
#include <time.h>


using namespace std;


extern void encode(char QRC[100][100], char SRC[100]);
extern void decode(char GRY[100][100], char DST[100]);


static char QRC[1000][100][100];
	static char dummy1[12];  // the size will be changed
static char IMG[1000][200][200];
	static char dummy2[34];  // the size will be changed
static char GRY[1000][100][100];
	static char dummy3[56];  // the size will be changed
static char SRC[1000][100];
	static char dummy4[78];  // the size will be changed
static char DST[1000][100];
	static char dummy5[90];  // the size will be changed


void img2gray(int i)
{
	for (register int y = 0; y < 100; y++)
		for (register int x = 0; x < 100; x++)
		{
			GRY[i][y][x] = 0;
			GRY[i][y][x] += IMG[i][y * 2 + 0][x * 2 + 0];
			GRY[i][y][x] += IMG[i][y * 2 + 0][x * 2 + 1];
			GRY[i][y][x] += IMG[i][y * 2 + 1][x * 2 + 0];
			GRY[i][y][x] += IMG[i][y * 2 + 1][x * 2 + 1];
		}
}


int main(void)
{
	srand(3);  // the seed will be changed

	cout << "---------------" << endl;

	for (register int c = 0; c < 1000; c++)
		for (register int l = 0; l < 100; l++)
			SRC[c][l] = 'A' + (rand() % 26);

	char TMP[100];
	for (register int c = 0; c < 1000; c++)
	{
		memcpy(TMP, SRC[c], sizeof(SRC[0]));
		encode(QRC[c], TMP);
	}

	for (register int c = 0; c < 1000; c++)
		for (register int y = 0; y < 200; y++)
			for (register int x = 0; x < 200; x++)
				IMG[c][y][x] = rand() % 2 == 0 ? 0 : 1;

	for (register int c = 0; c < 1000; c++)
	{
		register int offsetx = rand() % 101;
		register int offsety = rand() % 101;

		for (register int y = 0; y < 100; y++)
			for (register int x = 0; x < 100; x++)
				IMG[c][offsety + y][offsetx + x] = QRC[c][y][x] == 0 ? 0 : 1;
	}

	for (register int c = 0; c < 1000; c++)
	{
		for (register int l = 0; l < 13000; l++)
			IMG[c][rand() % 200][rand() % 200] = 1;

		img2gray(c);
	}

	clock_t TIME = clock();

	for (register int c = 0; c < 1000; c++)
		decode(GRY[c], DST[c]);

	TIME = (clock() - TIME) / (CLOCKS_PER_SEC / 1000);

	int FAIL = 0;

	for (register int c = 0; c < 1000; c++)
		FAIL += memcmp(SRC[c], DST[c], 100) == 0 ? 0 : 1;

	cout << "RESULT : " << (FAIL * 10000 + TIME) << endl;

	return 0;
}
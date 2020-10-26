//-------------------------------------------------------------------------------
//	Write String With Char Using Array
//-------------------------------------------------------------------------------
//
//	Author: Bayu Rukmana Jati
//	Version: 3.0.0
//	Last Edited: 26 Oktober 2020
//
//-------------------------------------------------------------------------------
//	> Changelog:
//	
//	3.0.0
//		- Fixed bug where the dot points displayed do not match the desired position.
//	2.1.0 					
//		- Changes process to search dot points.
//	2.0.0 	
//		- Makes array to the dot pointer, now you can add more dot points to the grid.
// 	1.1.0 					
//		- Changes the script structure.
//	1.0.0 					
//		- Script finish and released.
//
//-------------------------------------------------------------------------------
//	# Known Bugs:
//	- Dot points do not match the desired position. (fixed, yay!)
//-------------------------------------------------------------------------------
//	> Library used
//-------------------------------------------------------------------------------
	#include <stdio.h>
	#include <windows.h> 	// for delay
//-------------------------------------------------------------------------------
//	& Main Program
//-------------------------------------------------------------------------------
int u;

struct titik{
	int koordinat[];		// array ganjil untuk x, array genap untuk y
};

struct grid{
	double x;
	double y;
	char z;
	char t;
};

void input_titik(titik& titik1, int m){		
	for(int a = 1; a <= m*2; a++)
	{
		if(a % 2 == 0){
			printf("masukkan titik y %d: ", a/2); scanf("%d", &titik1.koordinat[a]);
		}
		else{
			printf("masukkan titik x %d: ", (a+1)/2); scanf("%d", &titik1.koordinat[a]);
		}	
	}
	
}

void print_titik(titik& titik1, int o){
	for(int a = 1; a <= o*2; a++){
		if(a % 2 == 0){
			printf("Koordinat titik y %d: %d\n", a/2, titik1.koordinat[a]);
		}
		else{
			printf("Koordinat titik x %d: %d\n", (a+1)/2, titik1.koordinat[a]);
		}
	}
}

void grid_style(grid& grid1, double x1, double y1, char z1, char t1){
	grid1.x = x1;
	grid1.y = y1;
	grid1.z = z1;
	grid1.t= t1;
}

int cetak_grid(grid& grid1, titik& titik1){
	int err;
	for(int j = 1; j <= grid1.y; j++)
	{
		for(int i = 1; i <= grid1.x; i++)
		{
				Sleep(20);
				for(int b = 2; b <= u*2; b = b + 2)
				{
						if(i == titik1.koordinat[b-1] && j == titik1.koordinat[b])
						{
							printf("%c", grid1.t);
							err = 1;
							goto bjk;
						}
						else
						{
							err = 0;
							//printf("%c", grid1.z);
						}
				}
				bjk:
				if (err == 1){}
				else
				{
					printf("%c", grid1.z);
				}
			printf(" ");
			err = 0;
		}
		printf("\n");
	}
return 0;
}

//void cetak_angka(char angkaSolo){
//	titik dotPoint;
//	grid gridMatrix;
//	u = ;
//	
//}


int main()
{
	titik bujank;
	grid  bujank1;
	printf("masukkan jumlah titik: "); scanf("%d", &u);
	input_titik(bujank, u);
	//print_titik(bujank, u);
	grid_style(bujank1, 40, 30, '-', 'A');
	cetak_grid(bujank1, bujank);
}
//-------------------------------------------------------------------------------
//	& END OF FILE
//-------------------------------------------------------------------------------

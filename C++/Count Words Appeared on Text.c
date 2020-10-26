//------------------------------------------------------------------------------
//	Finding word in a file module
//-------------------------------------------------------------------------------
//
//	Author: Bayu Rukmana Jati
//	Version: 2.02 Rev 3
//	Language: C++ (Dev Cpp 5.11)
//	Last Edited: 26 Oktober 2020
//
//------------------------------------------------------------------------------
// Changelog
//------------------------------------------------------------------------------
//	Version 2.02 Rev 3
//		- Change the script title.
//		- Fixing the bugs where the file is not found.
//	Version 2.02 Rev 2
//		- Print the counted words to console (ex: or or or or if if if if).
//		- Fix minor bugs in variables declaration.
//	Version 2.02 Rev 1
//		- Fix fatal typos in counting words.
//	Version 2.02
//		- Adds the new words to count (total 5 words can be count).
//	Version 2.01
//		- Change in the formatting console.
//		- Print the whole text/paragraph into the console.
//	Version 2.00
//		- Adds changeable variable and source like a *.txt file.
//	Version 1.00
//		- Script finished and released.
//------------------------------------------------------------------------------
// About This Script
//------------------------------------------------------------------------------
//		This script is used to count some word(s) appearing in a paragraph or a 
//	storylike writing. It's simple as using find command.
//------------------------------------------------------------------------------
// Library yang digunakan
//------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
//------------------------------------------------------------------------------
// Variabel yang boleh diedit 
// (note: awas memasukkan nilai terlalu besar, resiko tanggung sendiri)
//------------------------------------------------------------------------------
long a = 100000; 	//char kata[a] 		asali: 100000
long b = 120;  		//char kata1[b] 	asali: 120
long c = 120; 		//char kata2[c] 	asali: 120
long d = 120;		//char kata3[d] 	asali: 120
long e = 120; 		//char kata4[e] 	asali: 120
long f = 120; 		//char kata5[f] 	asali: 120
long g = 120;		//char kalimat[g] 	asali: 120
long h = 50; 		//char namafile[h]	asali: 50

char fullpath[340] = "C:\\Users\\Asus\\Desktop\\";  //lokasi file txt berada (tolong ganti 'Asus' dengan username sendiri  asali: dekstop
//-----------------------------------------------------------------------------
// & Mulai Program
//-----------------------------------------------------------------------------
FILE *datafile;
int main(){
    int cacah1, cacah2, cacah3, cacah4, cacah5, kalimat, panjang, i;
    char namafile[h], kata1[b], kata2[c],kata3[d], kata4[e],kata5[f], kalimat1[g];
    char kata[a];
    
    printf("Masukkan Kata pertama: ");
    gets(kata1);
    printf("Masukkan Kata kedua: ");
    gets(kata2);
    printf("Masukkan Kata ketiga: ");
    gets(kata3);
    printf("Masukkan Kata keempat: ");
    gets(kata4);
    printf("Masukkan Kata kelima: ");
    gets(kata5);
    printf("Masukkan nama file \n([i.e. bayu.txt]Nama file berformat text, jika belum ada silakan buat terlebih dahulu di desktop): ");
    gets(namafile);
	strcat(fullpath, namafile);
    datafile = fopen(fullpath, "r");
    if(datafile == NULL) {
        printf("Error number #21, tidak bisa membuka file %s", namafile);
        return 1;
    }
    printf("\n");
    printf("Isi teks berita: \n");
	while (fscanf(datafile, "%s", kata) == 1) 
	{
		printf("%s", kata);
		printf(" ");
	}
	printf("\n");
	printf("\n");
	cacah1 = 0;
	cacah2 = 0;
	cacah3 = 0;
	cacah4 = 0;
	cacah5 = 0;
    panjang = 0;
    kalimat = 0;
	datafile = fopen(fullpath, "r");
    while (fscanf(datafile, "%s", kata) == 1) 
	{
        ++panjang;

        if (strcmp(kata,kata1)== 0)
            cacah1++;
            
        if (strcmp(kata,kata2)== 0)
        	cacah2++;
        	
        if (strcmp(kata,kata3)== 0)
            cacah3++;
            
        if (strcmp(kata,kata4)== 0)
        	cacah4++;
        	
        if (strcmp(kata,kata5)== 0)
            cacah5++;
            
        if (strchr(kata,'.') != NULL)
            ++kalimat;
    }

    printf("Disini total ada %d kata\n", panjang);
    printf("Kata %s muncul %d kali\n", kata1, cacah1);
    printf("Kata %s muncul %d kali\n", kata2, cacah2);
    printf("Kata %s muncul %d kali\n", kata3, cacah3);
    printf("Kata %s muncul %d kali\n", kata4, cacah4);
    printf("Kata %s muncul %d kali\n", kata5, cacah5);
   	printf("Disini ada %d kalimat\n", kalimat);
   	
   	printf("Hasil print kata-kata: ");
   	//print kata tidak jelas
   	if(cacah1 > 0)
   	{
   		for(i = 0; i < cacah1; i++)
   		{
   			printf("%s", kata1);
   			printf(" ");
		}
	}
	if(cacah2 > 0)
   	{
   		for(i = 0; i < cacah2; i++)
   		{
   			printf("%s", kata2);
   			printf(" ");
		}
	}
	if(cacah3 > 0)
   	{
   		for(i = 0; i < cacah3; i++)
   		{
   			printf("%s", kata3);
   			printf(" ");
		}
	}
	if(cacah4 > 0)
   	{
   		for(i = 0; i < cacah4; i++)
   		{
   			printf("%s", kata4);
   			printf(" ");
		}
	}
	if(cacah5 > 0)
   	{
   		for(i = 0; i < cacah5; i++)
   		{
   			printf("%s", kata5);
   			printf(" ");
		}
	}
    return 0;
}
//---------------------------------------------------------------------
// Akhir dari File
//---------------------------------------------------------------------

#================================================================
# Manual Square Root with Heron's Method.
#
# Author: Bayu R. J. (remove this lol)
# Version: 1.0.0 *initial release
# Level: Easy
# C++ : Dev Cpp 5.11 (GNU C++ 11 Language with compiler TDM-GCC 4.9.2 64-bit Release)
#================================================================
# Introduction
# 
# This script purpose is simple, calculate the square root of a number.
# The differences is, it's not using sqrt() function. Also, it will show you the calculation if you say so.
#-----------------------------------------------------------------
# Updates
#
# 14/09/2020 (1.0.0) - Script finished and released.
#-----------------------------------------------------------------
# Compatibility
#
# *Class can be use independently (remove the windows.h import and sleep() function if causes problem)
#-----------------------------------------------------------------
# Known Bugs
#
# *None (In Windows, of course)
#-----------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <iostream>

using namespace std;

class Akar{
	public:
		Akar(double num, bool show_calc);			// constructor
		Akar();										// default (this should be 1)
	private:
		int j;
		double n, p;
		double x[];
};

Akar::Akar(){
	cout << "Akar dari 1 adalah: 1";
	exit;
}

Akar::Akar(double num, bool show_calc){
	cout << endl << endl;
	if (show_calc == false){
		x[0] = 1;
		for (int i = 1; i < 999; i++){
			x[i] = 0.5 * (x[(i-1)] + (num/x[(i-1)]));
			if (x[i] == x[(i-1)]){
				j = i;
				i = 999;
			}
		}
		cout << "Akar dari " << num << " adalah: " << x[j];
	}
	else {
		x[0] = 1;
		cout << "A1 = " << x[0] << endl << endl;
		Sleep(200);
		for (int i = 1; i < 999; i++){
			x[i] = 0.5 * (x[(i-1)] + (num/x[(i-1)]));
			cout << "A" << i+1 << " = 1/2 x (" << x[(i-1)] << " + (" << num << "/" << x[(i-1)] << "))" << endl;
			Sleep(200);
			cout << "A" << i+1 << " = " << x[i] << endl << endl;
			Sleep(200);
			if (x[i] == x[(i-1)]){
				j = i;
				i = 999;
			}
		}
		Sleep (200);
		cout << "Akar dari " << num << " adalah: " << x[j];
	}
	exit;
}

int main(){
	double numer;
	char yesno;
	cout << "Ketikkan angka yang ingin dicari akarnya: "; cin >> numer;
	cout << "Apakah perhitungan ingin ditampilkan? (y/n): "; cin >> yesno;
	if ((yesno == 'y') || (yesno == 'Y')){
		Akar rooten(numer, true);
	}
	else if ((yesno == 'n') || (yesno == 'N')){
		Akar rooten(numer, false);
	}
	else{
		cout << "Aplikasi rusak, pulang sana!" << endl;
	}
	return 0;
}


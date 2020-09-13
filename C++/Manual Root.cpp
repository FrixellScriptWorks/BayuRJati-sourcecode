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


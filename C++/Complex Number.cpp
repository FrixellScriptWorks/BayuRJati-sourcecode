//------------------------------------------------------------------------------
//	Complex Number Class Script
//-------------------------------------------------------------------------------
//
//	Author: Bayu Rukmana Jati
//	Version: 2.00
//	Language: C++ (Dev Cpp 5.11)
//	Last Edited: 26 Oktober 2020
//
//------------------------------------------------------------------------------
// Changelog
//------------------------------------------------------------------------------
//	Version 2.00
//		- Change the format of adding and substracting complex number.
//		- Change int to double.
//	Version 1.00
//		- Script finished and released.
//------------------------------------------------------------------------------
// About This Script
//------------------------------------------------------------------------------
//		This script is for writing and calculating complex number. However, this
//	simple program only know to Add(+), Substract(-), Conjugate, and Scalar the 
//	complex number. Also, it can print the complex number. Just saying XD.
//------------------------------------------------------------------------------
// Instruction
//------------------------------------------------------------------------------
// This script is basically a class script. So it can be a whole source or a library.
// If you want to make a whole source, then: 
//	- Edit at int main(){}
// If you want to make a library, then:
//	- Delete the int main(){}
//	- make a new Cpp source
//	- adds #include complex_number.cpp in your new source
//------------------------------------------------------------------------------
// Library Used
//------------------------------------------------------------------------------
#include <stdio.h>
#include <iostream>
#include <math.h>
//------------------------------------------------------------------------------
// & Start of the script
//------------------------------------------------------------------------------
using namespace std;


class kompleks{
	public:
		kompleks(double ii, double jj);
		kompleks();				
		show_all();
		double real();
		double imajiner();
		double tambah_real(double iii);
		double tambah_imajiner(double jjj);
		double konjugasi();
	private:
		double i, j;
		double i1, j1;
};
	
kompleks::kompleks(){
	i = 0;
	j = 0;
}	

kompleks::kompleks(double ii, double jj){
	i = ii;
	j = jj;
}

double kompleks::real(){
	return i;
}

double kompleks::imajiner(){
	return j;
}

kompleks::show_all(){
	if (imajiner() >= 0)
		cout << real() << " +" << imajiner() << "i" << endl;
	else if (imajiner() < 0)
		cout << real() << " " << imajiner() << "i" << endl;
}

double kompleks::tambah_real(double iii){
	i = real() + iii;
	return i;
}

double kompleks::tambah_imajiner(double jjj){
	j = imajiner() + jjj;
	return j;
}

kompleks add_kompleks (kompleks& kompleks1, kompleks& kompleks2){
	double i2, j2;
	i2 = kompleks1.real() + kompleks2.real();
	j2 = kompleks1.imajiner() + kompleks2.imajiner();
	kompleks adding(i2, j2);
	return adding;
	//adding.show_all();
}

kompleks sub_kompleks (kompleks& kompleks1, kompleks& kompleks2){
	double i2, j2;
	i2 = kompleks1.real() - kompleks2.real();
	j2 = kompleks1.imajiner() - kompleks2.imajiner();
	kompleks substract(i2, j2);
	return substract;
	//substract.show_all();
}

void konjugasi(kompleks& kompleks1){
	kompleks kompleks2(kompleks1.real(), (kompleks1.imajiner() - (2 * kompleks1.imajiner())));
	kompleks2.show_all();
}

double skalar(kompleks& kompleks1){
	double i3, j3;
	double s;
	i3 = kompleks1.real();
	j3 = kompleks1.imajiner();
	s = sqrt(pow(i3, 2) + pow(j3, 2));
	return s;
}

int main(){
	kompleks sukar(2.3, -24.3), lebih(2.5, -32.8);
	sukar.show_all();
	cout << endl;
	lebih.show_all();
	cout << endl;
	kompleks scaaad = add_kompleks(sukar, lebih);
	cout << skalar(scaaad);
	cout << endl;
	cout << endl;
	add_kompleks(sukar, lebih).show_all();
	return 0;
}
//---------------------------------------------------------------------
// Akhir dari File
//---------------------------------------------------------------------

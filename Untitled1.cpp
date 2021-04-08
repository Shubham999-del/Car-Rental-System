#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dos.h>
#include <iomanip>

using namespace std;

int main(){
//  	cout << "\t\t\t\t\t\t******Car Details*******\n\n";
//  	cout << "\t\t\t\t  CAR   " <<"\t\t\t    "<< "Rent (per day)" << endl;
//  	cout << "\t\t\t\t" <<"1."<<"Maruti WagonR"<<"\t\t\t\t"<<"Rs. 1,800"<<endl;
//	cout << "\t\t\t\t" << "2."<<"Maruti Swift"<<"\t\t\t\t"<<"Rs. 1,900"<<endl;
//	cout << "\t\t\t\t" << "3."<<"Maruti Swift Dzire"<<"\t\t\t"<<"Rs. 2,200"<<endl; 
//	cout << "\t\t\t\t" << "4." << "Hyundai Verna"<<"\t\t\t"<<"\tRs. 2,400"<<endl;
//	cout <<"\t\t\t\t"<<"5.Toyota Etios"<<"\t\t\t"<<"\tRs. 2,400"<<endl;
//	cout <<"\t\t\t\t"<<"6.Honda Amaze"<<"\t\t\t"<<"\tRs. 2,500"<<endl;
//	cout <<"\t\t\t\t"<<"7.Mahindra Bolero"<<"\t\t\t"<<"Rs. 2,700"<<endl;
//	cout <<"\t\t\t\t"<<"8.Toyota Innova"<<"\t\t\t\t"<<"Rs. 3,000"<<endl;
//	cout <<"\t\t\t\t"<<"9.Mahindra Thar"<<"\t\t\t\t"<<"Rs. 3,000"<<endl;
//	cout <<"\t\t\t\t"<<"10.Jeep Wrangler"<<"\t\t\t"<<"Rs. 4,000"<<endl;
	ofstream outf;
	outf.open("cardetails.txt");
	outf << 1800 << setw(20) << 0 <<endl;
	outf << 1900 << setw(20) << 0 <<endl;
	outf << 2000 << setw(20) << 0 <<endl;
	outf << 2200 << setw(20) << 0 <<endl;
	outf << 1400 << setw(20) << 0 <<endl;
	outf << 1000 << setw(20) << 0 <<endl;
	outf << 1110 << setw(20) << 0 <<endl;
	outf << 2100 << setw(20) << 0 <<endl;
	outf << 2020 << setw(20) << 0 <<endl;
	outf << 1120 << setw(20) << 0 <<endl;
	outf.close();


}



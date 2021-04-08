#include<iostream>
#include<iomanip>
#include<fstream>
#define N 10
#define max 100
using namespace std;

int main(){
	ofstream outf;
	outf.open("carsdata.txt");
	//outf << "occupied" << setw(20) << "Number Of Days" << setw(20) << "Owner_id" << setw(20) << "Renter_name" << endl;
	for(int i=0;i<N*max;i++){
		if(i%100<=9)
		outf << 0 << setw(20) << 0 << setw(20) << 0 << setw(20) << "None" << endl;
		else
		outf << -1 << setw(20) << 0 << setw(20) << -1 << setw(20) << "None" << endl;
	}
	outf.close();
}

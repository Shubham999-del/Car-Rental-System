#include<iostream>
#include<iomanip>
#include<fstream>
#define N 100
using namespace std;
int main(){
	ofstream outf;
	outf.open("ownersdata.txt");
	//outf << "Balance" << setw(20) << "Owner name" << setw(20) << "Car Model" << setw(20) << "Car Number" << endl;
	for(int i=0;i<N;i++){
		outf << 0 << setw(20) << "None" << setw(20) << -1 << setw(20) << -1 << endl;
 	} 
 	outf.close();

	
}

#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dos.h>
#include <iomanip>

using namespace std;

int main(){
	int n =5;
	int k=n;
	for(int i=0;i<k;i++){
		sleep(1);
		n--;
		cout << n << endl;
	}
}

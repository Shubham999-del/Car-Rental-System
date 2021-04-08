#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <sstream>
#include <unistd.h>
#include <dos.h>
#include <iomanip> 
#include<string>
using namespace std;

std::string trim(const std::string& line)
{
    const char* WhiteSpace = " \t\v\r\n";
    std::size_t start = line.find_first_not_of(WhiteSpace);
    std::size_t end = line.find_last_not_of(WhiteSpace);
    return start == end ? std::string() : line.substr(start, end - start + 1);
}

int main(){
	ifstream fin;
	int occ;
	int n;
	int id;
	string name;
	string word;
	string line;
	fin.open("carsdata.txt");
//	for(int i=1;fin.eof()==0;i++){
//		fin.seekg(0,ios::beg);
//		fin.read(occ,1);
//		fin.seekg(21,ios::beg);
//		fin.read(n,1);
//		fin.seekg(42,ios::beg);
//		fin.read(id,1);
//		fin.seekg(63,ios::beg);
//		fin.read(name,20);
//		cout << occ << " "<<n<<" "<<id<<" "<<name<<endl;
//	}
	int i=0;

	while(fin>>occ>>n>>id>>name){
		cout << occ << " "<<n<<" "<<id<<" "<<name<<endl;;
//		if(i>3){
//			i=i%4;
//			cout << endl;
//		}
//		if(i==0){
//			string answer=trim(word);
//			stringstream geek(answer);
//			geek >> occ;
//			cout << occ;
//		}
//		else if(i==1){
//			string answer=trim(word);
//			stringstream geek(answer);
//			geek >> n;
//			cout << n;
//		}
//		else if(i==2){
//			string answer=trim(word);
//			stringstream geek(answer);
//			geek >> id;
//			cout << id;
//		}else if(i==3){
//			name=word;
//			cout << name;
//			cout<<word;
//		}
//		i++;
	}
	return 0;
}

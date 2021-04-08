#include<iostream>
#include<fstream>
#define MAX 100
using namespace std;

class garage;
class admin;
class car{        //car class to trace the car and have the information about the owner and the state of car
	public:
		int occupied;
		int number_of_days;
		int owner_id;	
		string renter_name;
		void init(int owner,int occ){
			owner_id = owner;
			occupied = occ;
			number_of_days=0;
		}
};

class userII{
	private:
		int balance;        //how much user-II has earned till now            
		string owner_name;  //owner name
		int car_model;   // car_model
		int car_number;     // car number (unique for each car of each model) .Note -1 shows that the user does not own any car
	public:
		userII(){
			
		}
		void init(){    //to inisialize the variables
			cout << "\n\t\t\t\tEnter car-owner name" << endl;
			cout << "\t\t\t\t";
			cin >> owner_name;
			cout << "\t\t\t\tEnter car model" << endl;
			cout << "\t\t\t\t";
			cin >> car_model;
			car_model--;
		}
		void number(int n){   //to initialize the car number
			this->car_number=n;
		}
		int car_number_(){  //to return the car number for that owner
			return car_number;
		}
		void account(int credit){
			balance+=credit;
		}
		int balance_(){  //to return balance 
			return balance;
		}
		string owner_name_(){
			return owner_name;
		}
		int car_model_(){
			return car_model;
		}
		friend void status(userII &);
		friend void car_owner();
		friend void owners_init();
};
userII *owners = new userII[100];  //just declaring the array of objects of class user-II .Note user-II not yet assigned
void owners_init(){
	ifstream fin;
	fin.open("ownersdata.txt");
	int b,m,n;
	string name;
	int i=0;
	while(fin >> b >> name >> m >> n){
		owners[i].balance=b;
		owners[i].owner_name=name;
		owners[i].car_model = m;
		owners[i].car_number = n;
		i++;
	}
}

class userI{
	private:
		string name;
		int number_of_days;
		string email_Id;
		string contact_no;
		int model;
		int car_number;
	public:
		void init_name(string s){
			name=s;
		}
		void car_granted(int number){   //assigns the car number given to this user for his preferred car model
			this->car_number=number;
		}
		int model_(){
			return model;
		}
		int car_number_(){
			return car_number;
		}
		int number_of_days_(){
			return number_of_days;
		}
		string name_(){
			return name;
		}
		friend void car_renting(userI &, admin &);
};





class garage:public car{   //data warehouse to store the array of pointers to cars
	public:
		car** arrofcars = new car*[N];  //array of pointers to array of objects of class cars just initializing the garage
		
		garage(){
			ifstream in("carsdata.txt");
			for(int i=0;i<N;i++){
			arrofcars[i] = new car[MAX];
			}
			int occ;
			int n;
			int id;
			string name;
			int i=0;
			while(in>>occ>>n>>id>>name){
				arrofcars[i/100][i%100].occupied=occ;
				arrofcars[i/100][i%100].number_of_days=n;
				arrofcars[i/100][i%100].owner_id=id;
				arrofcars[i/100][i%100].renter_name=name;
				i++;
			}
			
		}
		
		bool validate(int model){
			for(int i=0;i<MAX;i++){
				if(arrofcars[model][i].owner_id!=-1){
					return true;
					break;
				}
			}
			return false;
		}
		
		int car_taken(int model,int n,string s){   //rents out the car to user-I and returns the car number to the user
			for(int j=0;j<MAX;j++){
				if(arrofcars[model][j].occupied==0 && arrofcars[model][j].owner_id!=-1){
					arrofcars[model][j].renter_name = s;
					arrofcars[model][j].number_of_days = n;
					arrofcars[model][j].occupied=1;
					return j;
					break;
				}
			}	
		}
		
		bool is_OFS(int model){   ///to check whether a particular car model is out of stock or not
			for(int j=0;j<MAX;j++){
				if(arrofcars[model][j].occupied==0){
					return false;
					break;
				}
			}
			return true;
		}
		
		int owner(int model,int car_number){   //returns the owner_id for a particular car
			return arrofcars[model][car_number].owner_id;
		}
		
		friend void status(userII &); //connects garage with user-II
		
		friend void car_renting(userI &,admin &);
		
		friend void car_owner();
		friend void display();
};




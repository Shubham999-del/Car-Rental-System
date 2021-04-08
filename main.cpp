#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dos.h>
#include <iomanip> 
#include<pthread.h>
#define MAX 100
#define N 10
#include"classes.h"


//all the friend function which follow to communicate data from one class to another
void car_owner();
void car_renting(userI &,admin &);
void display();

//global variables//
garage g;
int model_price[N][3];  //2-D array to store the prices for each model

void populate(){ //populating the model_price array with some initiale values . 
	int p;
	for(int i=0;i<N;i++){
		//p = 75+rand()%25;
		model_price[i][0]=i;  //model number
	}
	ifstream fin;
	fin.open("cardetails.txt");
	int i=0,price,count;
	while(fin>>price>>count){
		model_price[i][1]=price;
		model_price[i][2]=count;
		i++;
	}
	fin.close();
}
string model_names[10] = {"Maruti WagonR","Maruti Swift","Maruti Swift Dzire","Hyundai Verna","Toyota Etios","Honda Amaze","Mahindra Bolero","Toyota Innova","Mahindra Thar","Jeep Wrangler"};


void display(){  ///to display the car models along with their prices/day.
  	cout << "\t\t\t\t\t\t******Car Details*******\n\n";
  	cout << "\t\t\t\t  CAR   " <<"\t\t\t    "<< "Rent (per day)" << endl;
  	cout << "\t\t\t\t" <<"1."<<"Maruti WagonR"<<"\t\t\t\t"<<"Rs. "<<model_price[0][1]<<endl;
	cout << "\t\t\t\t" << "2."<<"Maruti Swift"<<"\t\t\t\t"<<"Rs. "<<model_price[1][1]<<endl;
	cout << "\t\t\t\t" << "3."<<"Maruti Swift Dzire"<<"\t\t\t"<<"Rs. "<<model_price[2][1]<<endl; 
	cout << "\t\t\t\t" << "4." << "Hyundai Verna"<<"\t\t\t"<<"\tRs. "<<model_price[3][1]<<endl;
	cout <<"\t\t\t\t"<<"5.Toyota Etios"<<"\t\t\t"<<"\tRs. "<<model_price[4][1]<<endl;
	cout <<"\t\t\t\t"<<"6.Honda Amaze"<<"\t\t\t"<<"\tRs. "<<model_price[5][1]<<endl;
	cout <<"\t\t\t\t"<<"7.Mahindra Bolero"<<"\t\t\t"<<"Rs. "<<model_price[6][1]<<endl;
	cout <<"\t\t\t\t"<<"8.Toyota Innova"<<"\t\t\t\t"<<"Rs. "<<model_price[7][1]<<endl;
	cout <<"\t\t\t\t"<<"9.Mahindra Thar"<<"\t\t\t\t"<<"Rs. "<<model_price[8][1]<<endl;
	cout <<"\t\t\t\t"<<"10.Jeep Wrangler"<<"\t\t\t"<<"Rs. "<<model_price[9][1]<<endl;
}



void showrent(string customername, int carmodel, int carnumber, int days, int rentalfee)
    {
    cout << "\n\t\t                       Car Rental - Customer Invoice                  "<<endl;
    cout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
    cout << "\t\t	| Invoice No. :"<<"------------------|"<<setw(10)<<"#Cnb81353"<<" |"<<endl;
    cout << "\t\t	| Customer Name:"<<"-----------------|"<<setw(10)<<customername<<" |"<<endl;
    cout << "\t\t	| Car Model :"<<"--------------------|"<<setw(10)<<carmodel+1<<" |"<<endl;
    cout << "\t\t	| Car No. :"<<"----------------------|"<<setw(10)<<carnumber<<" |"<<endl;
    cout << "\t\t	| Number of days :"<<"---------------|"<<setw(10)<<days<<" |"<<endl;
    cout << "\t\t	| Your Rental Amount is :"<<"--------|"<<setw(10)<<rentalfee<<" |"<<endl;
    cout << "\t\t	| Caution Money :"<<"----------------|"<<setw(10)<<"0"<<" |"<<endl;
    cout << "\t\t	| Advanced :"<<"---------------------|"<<setw(10)<<"0"<<" |"<<endl;
    cout << "\t\t	 ________________________________________________________"<<endl;
    cout <<"\n";
    cout << "\t\t	| Total Rental Amount is :"<<"-------|"<<setw(10)<<rentalfee<<" |"<<endl;
    cout << "\t\t	 ________________________________________________________"<<endl;
    cout << "\t\t	 # This is a computer generated invoce and it does not"<<endl;
    cout << "\t\t	 require an authorised signture #"<<endl;
    cout <<" "<<endl;
    cout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
    cout << "\t\t	You are advised to pay up the amount before due date."<<endl;
    cout << "\t\t	Otherwise penelty fee will be applied"<<endl;
    cout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
    int f;
    system("PAUSE");
    
    system ("CLS");
    
     ifstream inf("thanks.txt");

  
  char str[300];

  while(inf) {
    inf.getline(str, 300);
    if(inf) cout << str << endl;
  }
  inf.close();
	}


class start //welcome class
{
	public:
	int wc()
	{fstream in("welcome.txt"); //displaying welcome ASCII image text on output screen fn1353

    
  	if(!in) {
    	cout << "Cannot open input file.\n";
  			}
  	char str[1000];
  	//int a;
  	while(in) {
    in.getline(str ,1000);  // delim defaults to '\n' cp
    if(in) cout << str << endl;
 			  }
  	in.close();
  	sleep(1);
  	cout<<"\n               INITIATING THE SYSTEM, PLEASE WAIT FOR A MAOMENT....."<<endl;
  	sleep(1);
  	cout<<"\n               LOADING UP THE FILES....."<<endl;
  	sleep(1); //function which waits for (n) seconds
  	cout<<"\n               SHUBHAM & RITIK WELCOME YOU TO SOE CAR RENTAL SYSTEM!"<<endl;
  	sleep(3);
  	system ("CLS"); //cleares screen
	}
};




class welcome{
	int ch;
	public:
		welcome(){
			ch=-1;
		}
	void greetings(){
			char str[1000];
			ifstream in("Choice.txt");
			while(in) {
    		in.getline(str ,1000);  // delim defaults to '\n' cp
    		if(in) cout << str << endl;
 			  }
  			in.close();
			cout << "\t \t \t\t\tYour choice: ";
			cin>>ch;
			int p=0;
		while(1){
			
			
			if(ch==0){
				break;
			}
			if(ch!=1 && ch!=2 && ch!=3){
				cout << "\n\t \t \tInvalid choice.Please try again or press 0 to exit\n" << endl;
				cout << "\t \t \t\t\tYour choice: ";
				cin>>ch;
			}else {
				p=1;
				break;	
			}
			
		}
		if(p==1){
			sleep(1);
	  		system("CLS"); //cleares screen
		}
	}
	int choice(){
		return ch;
	}
};

class admin{
	string password = "admin";
	
	int balance=0;
	public:
	friend void car_renting(userI &,admin &);
	void bal(){
		cout << "\n\n\t\t\t\tEarnings till now : "<<balance<<"\n\n";
	}
	void typeI(){
		userI u;
		car_renting(u,*this);
		
	}
	void typeII(){
		car_owner();
	}
	void typeIII(){
		string pass;
		while(1){
			 cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t       SOE CAR RENTAL SYSTEM \n\n";
   			 cout<<"\t\t\t\t\t------------------------------";
   			 cout<<"\n\t\t\t\t\t\t     LOGIN \n";	
   			 cout<<"\t\t\t\t\t------------------------------\n\n";	
   			 cout << "\t\t\t\t\tEnter Password: ";
			cin >> pass;
			if(pass=="0"){
				system("CLS");
				break;
				}
			system("CLS");
			if(pass==this->password){
				cout << "\n\n\n\t\t\t\t\t     ***Access granted***\n" << endl;
				while(1){
				cout << "\n\t\t\t\tPress 1 to view the rates of different car models\n" << "\t\t\t\tPress 2 to view the number of owners\n\t\t\t\tPress 3 to view your earnings\n\t\t\t\tPress 0 to exit to main menu for admin\n";
				cout << "\n\t\t\t\tEnter your choice :  ";
				int ch;
				cin >>ch;
				cout << "\n\t\t\t\tLoading cars data . . . \n";
				sleep(1);
				system("CLS");
				if(ch==1){
					display();
					int x;
					cout<< "\n\t\t\t\tPress 1 if you want to alter the prices of any car model .Press 0 to exit\n";
					cout << "\n\t\t\t\t";
					cin >> x;
					if(x==1){
						int n,model;
						cout << "\n\t\t\tEnter the car model of which you want to change the rates followed by a space and then new rates for that model\n";
						cout << "\n\t\t\t";
						cin >> model >> n;
						model--;
						if(model<10){
							model_price[model][1]=n;
							cout <<"\t\t\tPrice for model "<<model<<" altered successfully\n\n";
							ofstream outf;
							outf.open("cardetails.txt");
							for(int i=0;i<N;i++){
								outf<<model_price[i][1]<<setw(20)<<model_price[i][2]<<endl;
							}
							outf.close();
						}else{
							cout << "\n\t\tSorry we dont have any car for that model .Please check the format again and try again" << endl;
						}
					}else{
						system("CLS");
						break;
					}
				}
				else if(ch==2){
					for(int i=0;i<100;i++){
						if(owners[i].car_number_()==-1){
							cout << "Number of owners are " << i << endl;
							break;
						}
					}
				}else if(ch==3){
					bal();
					sleep(2);
					system("CLS");
				}
				else if(ch==0){
					system("CLS");
					break;
				}
			}
			}else{
				cout << "\n\n\n\t\t\t\tWrong password .Access denied\n";
				cout << "t\t\t\tPlease try again or press 0 to exit\n";
			}
		}
	}
	
	void account(int x){
		balance+=x;
	}
};

void status(userII &x){  //to display the status of user-II car which is already in garage
	int n,rate;
	string model_name;
	ifstream fin;
	fin.open("Car Details.txt");
	cout << "Welcome " << x.owner_name << endl;
	cout << "Your car is : " << model_names[x.car_model_()] << endl;
	cout << "Your car number  : " << x.car_number << endl;
	cout << "Your account balance : " << x.balance << endl;
	if(g.arrofcars[x.car_model][x.car_number].occupied==0){
		cout << "Your car is currently available " << endl;
	}else{
		cout << "Your car is currently occupied " << endl; 
	}
}

int ownerID(){   //assigns the owner his/her id which is unique
		for(int i=0;i<100;i++){
			if(owners[i].car_number_()==-1){
				return i;
				break;
			}
		}
	}


void car_owner(){  //to handle type-II requests
	
	int ch;	
	cout << "\n\n\t\t\t\tEnter the type of request" << endl;
	cout << "\n\n\t\t\t\tPress 1 to provide your car for renting and earn some money" << endl;
	cout << "\t\t\t\tPress 2 to view your car status " << endl;
	cout << "\n\t\t\t\tYour choice : ";
	
	cin >> ch;
	sleep(1);
	system("CLS");
	if(ch==1){
		int car_model;
		cout << "\n\t\t\t\tWe only float these car models .Please see the rates too\n\n" << endl;
		display();
		
		int ID = ownerID();
		owners[ID].init(); //to take owner's name and car model from the user 
		car_model = owners[ID].car_model_();
		cout << "\n\t\t\t\tYour account has been created and your owner_ID is :" << ID+1 << "\n\t\t\t\tPlease save this for further access\n" <<endl;
		for(int i=10;i<MAX;i++){
			if(g.arrofcars[car_model][i].occupied==-1 && g.arrofcars[car_model][i].owner_id==-1){
				g.arrofcars[car_model][i].owner_id=ID+1;
				g.arrofcars[car_model][i].occupied=0;  //i.e. car created for renting
				owners[ID].number(i);  //to give his car a number unique for each car of a particular model
				break;
			}
		}
		sleep(2);
	  	system("CLS"); //cleares screen
		}else if(ch==2){
			//Take input ownerID 
			int id;
			
			while(1){
				cout << "\n\t\t\t\tEnter the id which was given to you at the starting .Must be between 1 and 100\n";
				cin >> id;
				id--;
				if(id==-2)break;
				if(owners[id].car_number_()!=-1){
					status(owners[id]);  //to print the current status of the owner's car
					break;
				}
				else{
					cout << "\t\t\t\tYour id number is wrong .Please try again or enter -1 to exit \n" ;
				}
				
			}	
		}
}

void car_renting(userI &u,admin &a){  //handling requests of type-I users
	int n,model,t;
	string s,k;
	display();
	cout << "\n";
	cout << "\t\t\t\tEnter the model number of your prefferd car: ";
	cin >> model;
	model--;
	model_price[model][2]++;
	cout << "\n";
	sleep(1);
	system("CLS");
	
	
	
	char str[1000];
	if(model==0)
	{
	
	ifstream in("1.txt"); 
	while(in) {
    	in.getline(str ,1000);  // delim defaults to '\n' cp
    	if(in) cout << str << endl;
 			  }
  		in.close();
    }
    else if(model==1)
	{
	ifstream in("2.txt"); 
	while(in) {
    	in.getline(str ,1000);  // delim defaults to '\n' cp
    	if(in) cout << str << endl;
 			  }
  		in.close();
    }
    else if(model==2)
	{
	ifstream in("3.txt"); 
	while(in) {
    	in.getline(str ,1000);  // delim defaults to '\n' cp
    	if(in) cout << str << endl;
 			  }
  		in.close();
    }
    else if(model==3)
	{
	ifstream in("4.txt"); 
	while(in) {
    	in.getline(str ,1000);  // delim defaults to '\n' cp
    	if(in) cout << str << endl;
 			  }
  		in.close();
    }
    else if(model==4)
	{
	ifstream in("5.txt"); 
	while(in) {
    	in.getline(str ,1000);  // delim defaults to '\n' cp
    	if(in) cout << str << endl;
 			  }
  		in.close();
    }
    else if(model==5)
	{
	ifstream in("6.txt"); 
	while(in) {
    	in.getline(str ,1000);  // delim defaults to '\n' cp
    	if(in) cout << str << endl;
 			  }
  		in.close();
    }
    else if(model==6)
	{
	ifstream in("7.txt"); 
	while(in) {
    	in.getline(str ,1000);  // delim defaults to '\n' cp
    	if(in) cout << str << endl;
 			  }
  		in.close();
    }
    else if(model==7)
	{
	ifstream in("8.txt"); 
	while(in) {
    	in.getline(str ,1000);  // delim defaults to '\n' cp
    	if(in) cout << str << endl;
 			  }
  		in.close();
    }
    else if(model==8)
	{
	ifstream in("9.txt"); 
	while(in) {
    	in.getline(str ,1000);  // delim defaults to '\n' cp
    	if(in) cout << str << endl;
 			  }
  		in.close();
    }
    else if(model==9)
	{
	ifstream in("10.txt"); 
	while(in) {
    	in.getline(str ,1000);  // delim defaults to '\n' cp
    	if(in) cout << str << endl;
 			  }
  		in.close();
    }
    else cout<<" Such model number doesn't exist. Please re-check the list.";
	
	
	
	cout << "\n\n";
	cout << "Please provide the following credentials                              [Note: Your ctredentials are safe with us]"<< endl;
	cout << "Enter your Name: ";
	cin >> s;
	cout << "Enter your Phone number: ";
	cin >>k;
	cout << "Enter the number of days you will be renting the car: ";
	cin >> n;
	//if(g.validate(model)){
		u.init_name(s);
		u.number_of_days = n;
		u.model = model;
		u.car_granted(g.car_taken(model,n,s));  //calls the car_taken fun to get the car number for that user;
		int price =0;
		price = model_price[model][1]*n;
		
		cout << "The Fare is : Rs "<< price << "\nPress 1 to confirm or 0 to cancel\n";
		cin >> t; 
		if(t==1){
			cout<< "Creating your invoice...";
			sleep(1);
			system("CLS");
			showrent(u.name_(),u.model_(),u.car_number_(),u.number_of_days_(),price);
			int owner_id = g.arrofcars[u.model][u.car_number].owner_id-1;
			if(owner_id==0){
				a.account(price);
				
			}else{
				owners[owner_id].account(price*0.9);
				a.account(price*0.1);
			}
			ifstream fin;
			fin.open("thanks.txt");
			string line;
			while(fin){
					getline(fin,line);
					cout << line <<endl;
			}
			fin.close();
			sleep(2);
			system("CLS");
		}else{
			cout << "Hope to see you soon!!" << endl;
		}
//	}else{
//		cout << "Sorry this car model is out of stock .Start from beginning" << endl;
//	}
	
	
}

class days{
	int model,number;
	public:
		days(){}
		days(int m,int n){
			model=m;
			number=n;
			int p=g.arrofcars[m][n].number_of_days;
			for(int i=0;i<p;i++){
				sleep(1);
				g.arrofcars[m][n].number_of_days--;
			}
			g.arrofcars[m][n].occupied=0;
			g.arrofcars[m][n].renter_name="None";
		}
};
int data[2][1000] = {0};

void* myturn(void *k){
	int *p = (int *)k;
	days* arr = new days[*p];
	for(int i=0;i<*p;i++){
		arr[i] = days(data[0][i],data[1][i]);
	}
}



void calci(){
	int k=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<MAX;j++){
			if(g.arrofcars[i][j].occupied==1){
				data[0][k]=i;
				data[1][k]=j;
				k++;
			}
		}
	}
	pthread_t mythread;
	pthread_create(&mythread, NULL, myturn,&k);
}

int main(){
	populate(); //getting ready the prices for each car model 
	start st;
	st.wc();
	welcome w;
	admin a;
	owners_init();
	calci();
	while(1){
		w.greetings();
		int ch = w.choice();  //getting the type of user
		if(ch==1){
			a.typeI();
		}
		else if(ch==2){
			a.typeII();
		}
		else if(ch==3){
			a.typeIII();
		}
		else if(ch==0){
			ofstream outf;
			outf.open("ownersdata.txt");
			for(int i=0;i<100;i++){
				outf << owners[i].balance_() << setw(20) << owners[i].owner_name_() << setw(20) << owners[i].car_model_() << setw(20) <<owners[i].car_number_()<<endl;
			}
			outf.close();
			outf.open("carsdata.txt");
			for(int i=0;i<N;i++){
				for(int j=0;j<MAX;j++){
					outf << g.arrofcars[i][j].occupied << setw(20) << g.arrofcars[i][j].number_of_days << setw(20) << g.arrofcars[i][j].owner_id <<setw(20) << g.arrofcars[i][j].renter_name << endl;
				}
			}
			outf.close();
			outf.open("cardetails.txt");
			for(int i=0;i<N;i++){
				outf<<model_price[i][1]<<setw(20)<<model_price[i][2]<<endl;
			}
			outf.close();
			break;
		}
	}
	
	
	
}

#include "network.h"
#include "user.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>

using namespace std;



int main(int argc, char *argv[])
{
	Network myConnect;
	if(myConnect.read_friends(argv[1])==-1){
		cout<<"Error reading file"<<endl;
	}
	while(1){ //loop until exit command
		cout << "Enter 1 to add a user(1 Steph Curry 1988 94027)'\n'";
		cout << "2 to add a connection(2 Steph Curry Michael Jordan)'\n'";
		cout << "3 to remove a connection(3 Michael Jordan LeBron James)'\n'";
		cout << "4 to print users(4)'\n'";
		cout << "5 to list a user's friends(5 Scottie Pippen)'\n'";
		cout << "6 to write data to file(6 1997_bulls.txt)'\n'";
		cout << "Any other character to exit'\n'";
		int choice;
		cin >> choice;
		if(choice >6 || choice<1){
			return 0;
		}
		else if(choice==1){ //add user
			string first_name, last_name, full_name;
			cin >> first_name >> last_name;
			full_name = first_name + " " + last_name;
			int year, zip;
			cin >> year >> zip;
			User temp(full_name, year, zip);
			myConnect.add_user(temp);
		}
		else if(choice==2){ //add connection
			string first_name, last_name, full_name1, full_name2;
			cin >> first_name >> last_name;
			full_name1 = first_name + " " + last_name;
			cin >> first_name >> last_name;
			full_name2 = first_name + " " + last_name;
			if(myConnect.add_connection(full_name1, full_name2) == -1){
				//person not in system
				cout<<"User does not exist"<<endl;
			}
		}
		else if(choice==3){ //remove connection
			string first_name, last_name, full_name1, full_name2;
			cin >> first_name >> last_name;
			full_name1 = first_name + " " + last_name;
			cin >> first_name >> last_name;
			full_name2 = first_name + " " + last_name;
			//invalid input
			if(myConnect.remove_connection(full_name1, full_name2) ==-1){
				cout<<"User does not exist"<<endl;
			}
		}
		else if(choice==4){ //print users
			cout<<"ID      Name                 Year";
			cout<<"    Zip"<<endl;
			for(int i=0; i<42; i++){
				cout<<"=";
			}
			cout<<endl;
			myConnect.printUsers();
		}
		else if(choice==5){ //List friends of given user
			//output friends list
			string first_name, last_name, full_name;
			cin >> first_name >> last_name;
			full_name = first_name + " " + last_name;
			int pos = myConnect.get_id(full_name);
			if(pos ==-1){
				//person not in system
				cout<<"User does not exist"<<endl;
			}
			else{
				//structure of grid output
				cout<<"ID      Name                 Year";
				cout<<"    Zip"<<endl;
				for(int i=0; i<42; i++){
					cout<<"=";
				}
				cout<<endl;

				//print friend info
				vector<int> p = (myConnect.getUser(pos)).getFriends();
				for(int i=0; i<p.size(); i++){
					User temp = myConnect.getUser(p[i]);
					if(p[i]<10){
						cout<<p[i]<<".      ";
					}
					else{
						cout<<p[i]<<".     ";
					}
					cout<<temp.getName();
					for(int j=(temp.getName()).size(); j<21; j++){
						cout<<" ";
					}
					cout<<temp.getYear()<<"    ";
					cout<<temp.getZip()<<endl;
				}
			}
		}
		else{ //choice==6, writes data to file
			string friendfile;
			cin >> friendfile;
			const char* c = friendfile.c_str();
			myConnect.write_friends(c);
		}
	}
//never reached
}

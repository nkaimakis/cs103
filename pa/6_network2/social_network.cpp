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
		cout << "7 for shortest connection(7 Steph Curry Scottie Pipen)'\n'";
		cout << "8 for disjoint sets(8)'\n'";
		cout << "9 for friend suggestions(9 Jimmy Butler)'\n'";
		cout << "Any other character to exit'\n'";
		int choice;
		cin >> choice;
		if(choice >9 || choice<1){
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
		else if(choice==6){ //writes data to file
			string friendfile;
			cin >> friendfile;
			const char* c = friendfile.c_str();
			myConnect.write_friends(c);
		}
		else if(choice==7){ //shortest path
			string first_name, last_name, full_name1, full_name2;
			cin >> first_name >> last_name;
			full_name1 = first_name + " " + last_name;
			cin >> first_name >> last_name;
			full_name2 = first_name + " " + last_name;
			int from = myConnect.get_id(full_name1);
			int to = myConnect.get_id(full_name2);
			if(from==-1 || to==-1){ //invalid users
				cout<<"User does not exist"<<endl;
			}
			else{
				vector<int> hold = myConnect.shortest_path(from, to);
				if(from==to){ //vector empty
					cout << "Distance: 0\n" << full_name1 << endl;
				}
				else if(hold.empty()){
					cout<<"Distance: 1"<<endl;
					cout << full_name1<< " -> "<< full_name2<< endl;
				}
				else if(hold[0] == -1){ //no path
					cout << "None\n";
				}
				else{
					cout << "Distance: " << hold.size()+1 << endl;
					cout << full_name1 << " -> ";
					for(int i=0; i< hold.size(); i++){
						cout << myConnect.getName(hold[ hold.size()-i-1 ]) << " -> ";
					}
					cout << full_name2 << endl;
					//print last user 
				}
			}
		} 
		else if(choice==8){ //disjoint sets
			vector<vector<int> > dSets = myConnect.groups();
			for(int i=0; i< dSets.size(); i++){
				cout<< "Set "<< i+1 << " => ";
				vector<int> setNames = dSets[i];
				for(int j=0; j< setNames.size(); j++){
					cout<< myConnect.getName(setNames[j]);
					if(j != setNames.size()-1){ //if not last entry add comma
						cout<< ", ";
					}
				}
				cout<<endl;
			}
		}
		else{ //choice==9 friend suggestions
			int score =0;
			string first_name, last_name, full_name;
			cin >> first_name >> last_name;
			full_name = first_name + " " + last_name;
			int who = myConnect.get_id(full_name);

			if(who==-1){ //invalid users
				cout<<"User does not exist"<<endl;
			}
			else{
				vector<int> suggestions = myConnect.suggest_friends(who, score);

				//print output
				if(suggestions.empty()){ //no friend suggestions
					cout<< "None" <<endl;
				}
				else if(suggestions.size() == 1){
					cout<< "The suggested friend is:\n";
				}
				else{
					cout<< "The suggested friends are:\n";
				}
				for(int i=0; i< suggestions.size(); i++){
					cout<< '\t'<< "Score: "<< score<< '\t';
					cout<< myConnect.getName(suggestions[i])<<endl;
				}
			}
		}
	}
//never reached
}

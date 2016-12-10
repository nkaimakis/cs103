#include "network.h"

Network::Network(){};
Network::~Network(){};

int Network::read_friends(const char *filename){
	ifstream myFile(filename);
	if(myFile.fail()){
		return -1;
	}
	int num_users;
	myFile >> num_users;
	for(int c=0; c < num_users; c++){
		int hold_id;
		myFile >> hold_id;
		string hold_first, hold_last, hold_name;
		myFile >> hold_first;
		myFile >> hold_last;
		hold_name = hold_first + " " + hold_last; 
		
		int hold_year;
		myFile >> hold_year;
		int hold_zip;
		myFile >> hold_zip;
		string eatEnd, myLine; // holds line of friends
		getline(myFile, eatEnd);
		getline(myFile, myLine);
		

		//create user to add to list vector
		User temp(hold_name, hold_year, hold_zip);
		stringstream ss(myLine);
		int tempFriend;

		while(ss >> tempFriend){
			temp.add_friend(tempFriend);
			//adds all friends on friend line
		}
		//add temp user to list vector
		add_user(temp);
	}

	myFile.close();
	return 0; //success
}

int Network::write_friends(const char *filename){
	ofstream outFile(filename);
	outFile << master_list.size() << endl;
	for(int i=0; i<master_list.size(); i++){
		outFile << i << endl; //saves user id
		//use temps and get functions to send
		outFile << '\t' << (master_list[i]).getName() << endl;
		outFile << '\t' << (master_list[i]).getYear() << endl;
		outFile << '\t' << (master_list[i]).getZip() << endl;
		outFile << '\t';

		vector<int> v = (master_list[i]).getFriends();
		for(int a=0; a< v.size(); a++){
			outFile << v[a] << " ";
		}
		outFile << endl;
		if(outFile.fail()){
			return -1;
		}
	}
	outFile.close();
	return 0;

}

void Network::add_user(User k){
	master_list.push_back(k);
}
int Network::add_connection(string name1, string name2){
	bool match=0;
	int tempID_1=0;
	int tempID_2=0;
	//find id number of name1
	for(int i=0; !match; i++){
		if((master_list[i]).getName() == name1){
			tempID_1 = i;
			match=1; //exit loop
		}
		else if(i == master_list.size()-1){
			return -1;
			//invalid user
		}
	}
	match=0;
	//find id number of name2
	for(int i=0; !match; i++){
		if((master_list[i]).getName() == name2){
			tempID_2 = i;
			match=1; //exit loop
		}
		else if(i == master_list.size()-1){
			return -1;
			//invalid user
		}
	}
	//add friend to both Users, respectively
	(master_list[tempID_1]).add_friend(tempID_2);
	(master_list[tempID_2]).add_friend(tempID_1);
	return 0;
}
int Network::remove_connection(string name1, string name2){
	int tempID_1;
	int tempID_2;
	//find id number of name1
	if(get_id(name1)== -1){
		return -1;
	}
	else{
		tempID_1 = get_id(name1);
	}
	//find id number of name2
	if(get_id(name1)== -1){
		return -1;
	}
	else{
		tempID_2 = get_id(name2);
	}
	//add friend to both Users, respectively
	(master_list[tempID_1]).delete_friend(tempID_2);
	(master_list[tempID_2]).delete_friend(tempID_1);
	return 0;
}
int Network::get_id(string username){
	//find id number to match username
	for(int i=0; i<master_list.size(); i++){
		if((master_list[i]).getName() == username){
			return i;
		}
	}
	return -1;
}

User Network::getUser(int loc){
	return master_list[loc];
}
void Network::printUsers(){
	for(int j=0; j<master_list.size(); j++){
		User temp = master_list[j];
		if(j<10){
			cout<<j<<".      ";
		}
		else{
			cout<<j<<".     ";
		}
		cout<<temp.getName();
		for(int k=(temp.getName()).size(); k<21; k++){
			cout<<" ";
		}
		cout<<temp.getYear()<<"    ";
		cout<<temp.getZip()<<endl;
	}
}
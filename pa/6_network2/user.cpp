#include "user.h"


User::User(string name, int year, int zip){
	_name = name;
	_year = year;
	_zip = zip;
	depth = -1;
	predecessor = -1;
	score = -1;
};

User::~User(){};

string User::getName(){
	return _name;
};
int User::getYear(){
	return _year;
};
int User::getZip(){
	return _zip;
};
vector<int> User::getFriends(){
	return friend_list;
}


void User::add_friend(int x){
	bool occurrence=0;
	for(int i=0; i< friend_list.size() && !occurrence; i++){
		int temp = (friend_list[i]);
		if(x == temp){
			//friend already connected
			occurrence=1;
		}
	}
	if(!occurrence){
		//add user to friends list
		friend_list.push_back(x);
	}
};

void User::delete_friend(int x){
	bool occurrence=0;
	int s = friend_list.size();
	for(int i=0; i< s && !occurrence; i++){
		int temp = (friend_list[i]);

		if(x == temp){
			//friend is connected
			friend_list.erase(friend_list.begin()+i);
			occurrence=1;
		}
	}
};

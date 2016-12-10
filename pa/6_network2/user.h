#ifndef USER_H
#define USER_H
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


class User {
 public:
 	User(string name, int year, int zip);
 	~User();
 	void add_friend(int x);
 	void delete_friend(int x);
 	int getYear();
 	int getZip();
  	string getName();
 	vector<int> getFriends();
 	int depth;
 	int predecessor;
 	int score;

 private:
 	string _name;
 	int _year;
 	int _zip;
 	vector<int> friend_list;
};

#endif

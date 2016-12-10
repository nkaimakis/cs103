#ifndef NETWORK_H
#define NETWORK_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "user.h"
using namespace std;

class Network {
	public:
	Network();
	~Network();
		int read_friends(const char *filename);
		int write_friends(const char *filename);
		void add_user(User temp);
		int add_connection(string name1, string name2);
		int remove_connection(string name1, string name2);
		int get_id(string username);
	  	User getUser(int loc);
	  	void printUsers();
	
	private:
		vector<User> master_list;
};

#endif

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

string Network::getName(int loc){
	return master_list[loc].getName();
}

vector<int> Network::shortest_path(int from, int to){
	master_list[from].depth = 0;

  	deque<int> d;
  	vector<int> passback;
  	d.push_front(from);
  	if(from == to){
  		resetUserVals();
  		return passback;
  		//return empty vector if from and to are the same
  	}

  	while(! d.empty()){  		
  		int index = d.front();
  		d.pop_front(); //remove checked

		vector<int> friends = master_list[index].getFriends();
		//add friends of user if not the end
		// ??????should i check if friends is empty?
		if(!friends.empty()){
			for(int i=0; i < friends.size(); i++){
				if(friends[i] == to){ //found
		  			while(index != from){
		  				//add index to passback vect and move back until at beginning
		  				passback.push_back( index );
		    			index = master_list[index].predecessor;
		  			}
		  			resetUserVals();
		  			return passback;
				}
				else{ //add to queue
					if(master_list[friends[i]].depth == -1){ //only add if not previously added
						(master_list[friends[i]]).predecessor = index;
						//sets predecessor as index and depth as one more than current depth
						(master_list[friends[i]]).depth = master_list[index].depth + 1;
						d.push_back(friends[i]);
					}
				}

			}
		}
  	}
  	//no path reached
  	passback.push_back(-1);
  	resetUserVals();
  	return passback;
  }


vector<vector<int> > Network::groups(){
  	vector<vector<int> > passback;
  	deque<int> unvisited;
  	int numsets=0;

	for(int i=0; i<master_list.size(); i++){
		if(master_list[i].depth == -1){ //if masterlist[i] has not been visited
			unvisited.push_back(i);
			//add friends to unvisited
			while(! unvisited.empty()){  		
		  		int index = unvisited.front();
		  		unvisited.pop_front(); //remove checked
		  		master_list[index].depth = i;

				vector<int> friends = master_list[index].getFriends();
				//add friends of user if not the end
				if(!friends.empty()){
					for(int j=0; j < friends.size(); j++){
						if(master_list[friends[j]].depth == -1){ //not yet added
							//changes depth to mark as visited
							(master_list[friends[j]]).depth = i;
							unvisited.push_back(friends[j]);
				  		}
					}
				}
		  	}
			//add vect to passback if new set found
	  		vector<int> temp;
		  	for(int j=0; j< master_list.size(); j++){ //add all users with depth of i to current vector in passback
		  		if(master_list[j].depth == i){
		  			temp.push_back(j);
		  		}
		  	}
		  	passback.push_back(temp);
		  	numsets++;
		}

	}

  return passback;
}


vector<int> Network::suggest_friends(int who, int &score){
  	vector<int> passback;
  	deque<int> unvisited;
  	master_list[who].depth = 1; //mark visited
  	score = -1; //score remains = -1 if no suggestions are found

  	vector<int> friendsfirst = master_list[who].getFriends();
  	for(int i=0; i< friendsfirst.size(); i++){
  		master_list[friendsfirst[i]].depth = 1; //mark visited
  	}
  	for(int i=0; i< friendsfirst.size(); i++){
  		vector<int> friendsecond = master_list[friendsfirst[i]].getFriends();
  		for(int j=0; j< friendsecond.size(); j++){
  			if(master_list[friendsecond[j]].depth == -1){ //if not an original friend
  				//count occurrences in score value of users
  				if(master_list[friendsecond[j]].score == -1){
  					master_list[friendsecond[j]].score = 1;
  				}
  				else{
  					master_list[friendsecond[j]].score++;
  				}

  				if(score < master_list[friendsecond[j]].score){ //update score
  					score = master_list[friendsecond[j]].score;
  				}
  			}
  		}
  	}
  	if(score== -1){ //no suggestions
  		resetUserVals(); //reset values
  		return passback;
  	}
  	else{ //find max score and return suggestions
  		int max=0;
  		for(int i=0; i< master_list.size(); i++){
  			if(master_list[i].score > max){
  				max = master_list[i].score; //set new max
  			}
  		}
  		//add all suggestions of score max to passback vector
  		for(int i=0; i< master_list.size(); i++){
  			if(master_list[i].score == max){
  				passback.push_back(i);
  			}
  		}
  		score = max; //set score memory to max
  		resetUserVals(); //reset values
		return passback;
  	}
}

void Network::resetUserVals(){
	for(int i=0; i < master_list.size(); i++){
		master_list[i].depth = -1;
		master_list[i].predecessor = -1;
		master_list[i].score = -1;
	}
}
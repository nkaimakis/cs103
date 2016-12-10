#include "bigint.h"
using namespace std;


BigInt::BigInt(string s){
	int len= s.size();
	for(int i=1; i<=len; i++){
		number.push_back(s.at(len-i)-'0'); //stores number in correct digit place
	}
}


string BigInt::to_string(){
	stringstream hold;
	for(int i=1; i<=number.size(); i++){
		hold << number[number.size()-i];
	}
	return (hold.str());
}

void BigInt::add(BigInt b){
	int test=-1;
	int diff=0;
	if(number.size()>(b.number).size()){
		diff = number.size()- (b.number).size();
		test=0;
	}
	else if((b.number).size()>number.size()){
		diff = (b.number).size()- number.size();
		test=1;
	}
	//difference in length of vectors

	if(test==0){
		for(int i=0; i<diff; i++){
			number.push_back(0);
		}
	}
	else if(test==1){
		for(int i=0; i<diff; i++){
			(b.number).push_back(0);
		}
	}

	int init_size = number.size();
	for(int i=0; i<init_size; i++){
			//add integers and put back into number
			number[i] = (number[i] + (b.number)[i]);
			//convert to base 10 when necessary
			//by carrying the 1
			if(number[i] > 9){
				//separate case for final place
				if(init_size-1 == i){
					number.push_back(1);
					cout << "onetime" << endl;
				}
				else{
					number[i+1]++;
				}
				number[i] -= 10;

			}
}
}


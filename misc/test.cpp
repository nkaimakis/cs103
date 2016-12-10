#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(){
	char * mine, yours;
	cout << "enter two strings to be compared" << endl;
	cin >> mine >> yours;
	cout << strcmp(mine, yours) << endl;
	return 0;
}
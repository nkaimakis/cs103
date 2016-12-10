#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

void licenses(string prefix){
	if(prefix.size() == 7){
		cout << prefix << endl;
	}
	else{
		int idx = prefix.size();

		if(idx >= 2 && idx <=3){
			for(int i=0; i<26;i++){
				string new_prefix= prefix + (char)('A' +i);
				licenses(new_prefix);
			}
		}
		else{
			for(int i=0; i<10; i++){
				string new_prefix = prefix + (char)('0'+1);
				licenses(new_prefix);
			}
		}
	}
}

void doit(char options[], string prefix, int n)
{
	if(prefix.size() == n){
		cout << prefix << endl;
	}	
	else{
		for(int i=0; i<strlen(options); i++){
			string new_prefix = prefix + options[i];
			doit(options, new_prefix, n);
		}
	}

}

int main(int argc, char*argv[]){
	//int n = atoi(argv[1]);
	//doit(argv[2], "", n);
	licenses("");

	return 0;
}
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	if(argc < 2){
		cout << "please enter a filename" << endl;
		return 1;
	}
  ifstream ifile(argv[1]);
  int x, y;
if(ifile.fail()){
	cout << "file does not exist" << endl;
	return 1;
}

ifile >> x >> y;

if(ifile.fail()){
	cout << "unable to read two ints" << endl;
	ifile.close();
	return 1;
}
ofstream outfile("results.txt");
  outfile << "sum is " << x + y << endl;

  ifile.close();
  outfile.close();

  return 0;
}

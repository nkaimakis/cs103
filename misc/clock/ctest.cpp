#include "clock.h"

//using namespace std;
int main(){
	Clock c1; //calls default constructor
	Clock c2(10, 22, 50);
	c1.printTime();
	c2.printTime();

	c2.setAlarmTime(10, 23, 0);
	c2.toggleEnable();

	for(int i = 0; i < 20; i++){
		c2.printTime();
		c2.tick();
	}

	return 0;
}
#include "clock.h"
#include <iostream>
using namespace std;

Clock::Clock(){
	_ch = 12; _cm = 0; _cs = 0;
	_ah = 12; _am = 0; _as = 0;
	_enabled = false;
}

Clock::Clock(int h, int m, int s){
	_ch = h; _cm = m; _cs = s;
	_ah = 12; _am = 0; _as = 0;
	_enabled = false;
}
void Clock::setTime(int h, int m, int s){
	_ch = h; _cm = m; _cs = s;
}
void Clock::setAlarmTime(int h, int m, int s){
	_ah = h; _am = m; _as = s;
}
void Clock::printTime(){
	cout << _ch << ":" << _cm << ":" << _cs << endl;
}
bool Clock::isEnabled(){
	return _enabled;
}
void Clock::toggleEnable(){
	_enabled = !_enabled;
}
bool Clock::checkAlarm(){
	return(_ch == _ah && _cm == _am && _cs == _as);
}
void Clock::tick(){
	_cs++;
	if(_cs == 60){
		_cs = 0;
		_cm++;
		if(_cm == 60){
			_cm = 0;
			_ch++;
			if(_ch == 24){
				_ch = 0;
			}
		}
	}
	if(checkAlarm()){
		cout << "ALARM!!" << endl;
	}
}
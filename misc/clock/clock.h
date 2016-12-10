class Clock {

public:
	Clock(); //default constructor
	Clock(int h, int m, int s);
	void setTime(int h, int m, int s);
	void setAlarmTime(int h, int m, int s);
	void printTime();
	bool isEnabled();
	void toggleEnable();
	void tick();


private:
	bool checkAlarm(); //helper function

	int _ch, _cm, _cs; //current time
	int _ah, _am, _as; //alarm time
	bool _enabled;


};
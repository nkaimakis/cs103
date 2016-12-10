#include "turtle.h"
#include <cmath>


Turtle::Turtle(double x0, double y0, double dir0){
	x_val = x0;
	y_val = y0;
	direction = dir0/360 * 2 * M_PI;
	c = draw::BLACK;
	trail = 1;
}
Turtle::~Turtle(){}

void Turtle::turn (double deg){
	deg = deg/360 * 2 * M_PI;
	direction += deg;
}

void Turtle::move (double dist){
	if(trail){
		draw::setcolor(c);
		double tempx = x_val;
		double tempy = y_val;
		x_val += dist * cos(direction);
		y_val += dist * sin(direction);
		draw::line(tempx, tempy, x_val, y_val);
	}
	else{
		x_val += dist * cos(direction);
		y_val += dist * sin(direction);
	}
}

void Turtle::on(){
	trail = 1;
}

void Turtle::off(){
	trail = 0;
}

void Turtle::setColor(Color color){
	c = color;
}
#pragma once
#include<iostream>>
#include<string>
using namespace std;

class Car2 {
private:
	int speed;
	int gear;
	string color;
public:
	int getSpeed();
	void setSpeed(int s);
};
#include<iostream>
#include<string>
using namespace std;

//	사용(use)		: 하나의 클래스가 다른 클래스를 사용
//					ex) 클래스 A의 멤버 함수에서 클래스 B의 멤버 함수들을 호출(클래스 B의 객체를 가지고 있어야함)
//	포함(has-a)		: 하나의 클래스가 다른 클래스를 포함
//					ex) 이 코드가 예제
//	상송(is-a)		: 하나의 클래스가 다른 클래스를 상송

class Time {
private:
	int time;
	int minute;
	int second;
public:
	Time();
	Time(int t, int m, int s);
	void print();
};

Time::Time() {
	time = 0;
	minute = 0;
	second = 0;
}

Time::Time(int t, int m, int s) {
	time = t;
	minute = m;
	second = s;
}

void Time::print() {
	cout << time << "시 " << minute << "분 " << second << "초 \n";
}

class AlarmClock {
private:
	Time currentTime;
	Time alarmTime;
public:
	AlarmClock(Time a, Time c);
	void print();
};

AlarmClock::AlarmClock(Time a, Time c) {
	alarmTime = a;
	currentTime = c;
}

void AlarmClock::print() {
	cout << "현재 시각: ";
	currentTime.print();
	cout << "알람 시각: ";
	alarmTime.print();
}

int main() {
	Time alarm(6, 0, 0);
	Time current(12, 56, 34);
	AlarmClock c(alarm, current);

	c.print();
	return 0;
}
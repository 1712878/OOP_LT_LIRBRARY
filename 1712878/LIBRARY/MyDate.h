#ifndef __MY_DATE_H__
#define __MY_DATE_H__

#include <iostream>
#include <string>
using namespace std;
#define MinYear 1900
#define	MaxYear 10000

class MyDate
{
private:
	int day, month, year;
public:
	MyDate(int day= 1, int month =1, int year = MinYear);
	MyDate(string s);
	bool CheckDay();
	MyDate operator= (const MyDate& Date);
	MyDate operator=(const string& s);
	bool operator == (const MyDate& Date);
	MyDate operator+ (int nDay) const;
	int operator- (MyDate Date);
	int Distance();
	int Distance(MyDate Date);
	string DayOfWeek();
	friend istream& operator >> (istream& inDev, MyDate &Date)
	{
		char ch;
		inDev >> Date.day >> ch >> Date.month >> ch >> Date.year;
		return inDev;
	}
	friend ostream& operator << (ostream& outDev,const MyDate& Date)
	{
		outDev << Date.day << "/" << Date.month << "/" << Date.year;
		return outDev;
	}
};
int CheckYear(int year);
int DayOfMonth(int month, int year);
#endif


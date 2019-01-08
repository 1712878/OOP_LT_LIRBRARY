#include "MyDate.h"

MyDate::MyDate(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

bool MyDate::CheckDay()
{
	if (day <1 || day>DayOfMonth(month,year) || CheckYear(year) == -1)
		return false;
	else
		return true;
}

MyDate MyDate::operator=(const MyDate & Date)
{
	this->day = Date.day;
	this->month = Date.month;
	this->year = Date.year;
	return *this;
}

bool MyDate::operator==(const MyDate & Date)
{
	return (day == Date.day && month == Date.month && year == Date.year);
}

MyDate MyDate::operator+ (int n) const
{	
	MyDate temp = *this;
	int nDay = n  + temp.day;
	while (nDay > DayOfMonth(temp.month, temp.year))
	{
		nDay -= DayOfMonth(temp.month, temp.year);
		if (temp.month + 1 <= 12)
			temp.month++;
		else
		{
			temp.month = 1;
			temp.year++;
		}
	}
	temp.day = nDay;
	return temp;
}

int MyDate::operator-(MyDate Date)
{
	return Distance(Date);
}

int MyDate::Distance()
{
	// 1/1/1900 -> this
	int nDay = 0;
	for (int i = MinYear; i < year; i++)
		nDay += 365 + (CheckYear(i) == 1);
	for (int i = 1; i < month; i++)
		nDay += DayOfMonth(i, year);
	nDay += day - 1;
	return nDay;
}

int MyDate::Distance(MyDate Date)
{
	int nDay = Distance() - Date.Distance();
	return abs(nDay);
}

string MyDate::DayOfWeek()
{
	string Day[] = { "MonDay", "Tuesday", "Wednesday", "Thusday", "Friday", "Saturday", "Sunday" };
	int n = Distance() % 7; // 1/1/1900 -> Monday
	return Day[n];
}

int CheckYear(int year)
{
	if (year < MinYear || year > MaxYear)
		return -1;
	else
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int DayOfMonth(int month, int year)
{
	if (month < 1 || month >12 || CheckYear(year) == -1)
		return -1;
	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31; break;
	case 4: case 6: case 9: case 11:
		return 30; break;
	default:
		if (CheckYear(year) == 1)
			return 29;
		else
			return 28;
	}
}
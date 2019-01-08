#include "MyDate.h"
#include <iostream>
using namespace std;

int main()
{
	MyDate Date(8,1,2019);
	MyDate Date2(28, 1, 2019);
	cout << "Date:  " << Date << endl;
	cout << "Date2: " << Date2 << endl;
	cout << "Distance Date - Date2:  " << Date.Distance(Date2) << endl;
	cout << "Date is:   " << Date.DayOfWeek() << endl;
	cout << "Date2 is:  " << Date2.DayOfWeek() << endl;
	system("pause");
	return 0;
}
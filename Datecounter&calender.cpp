#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

 int LeapYears(int year)
 {
	 return((year%4==0)&&(year%100!=0)||(year%400==0));
 }
 int DaysToMonth(int year,int month)
 {
	 int Days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	 int day = Days[month];
	 if(month == 2)
	 {
		 day = day+LeapYears(year);
	 }
	 return day;
 }

int DayToWeek(int year, int month, int day)
 {   
	 int DateWeek = 0;
	 int ret = 0;
	 int Daycode = day;
	 int num = 0;
	 int Monthcode[13]={0,6,2,2,5,0,3,5,1,4,6,2,4};
	 if(LeapYears(day))
	 {
		 Monthcode[1]=5;
		 Monthcode[2]=1;
	 }
	 int Yearmantissa = year%10+(year/10)%10*10;//后两位尾数
	 int Yearcode = (Yearmantissa/4+Yearmantissa)%7;
	 num = Daycode+Monthcode[month]+Yearcode;
	 if(num<7)
	 {
		 DateWeek = num;
	 }
	 else
	 {
		 ret = num%7;
		 if(ret == 0)
		 {
			 DateWeek = 7;
		 }
		 else
		 {
			 DateWeek = ret;
		 }

	 }
	 return DateWeek;

 }

 

class Date
{
public:
 Date(int year = 1900,int month = 1,int day = 1)
	 :_year(year)
	 ,_month(month)
	 ,_day(day)
 {
	 if((year<=0)
		 ||((month<=0)||(month>12))
		 ||((day<0)||(day>DaysToMonth(year,month))))
	 {
		 year = 1900;
		 month = 1;
		 day = 1;
	 }
 }
 void Display()
 {
	 int ret = 0;
	 ret = DayToWeek(_year,_month,_day);
	 switch(ret)
	 {
	 case 1:
		  cout<<_year<<"-"<<_month<<"-"<<_day<<"-"<<"星期一"<<endl;
		
		 break;
	 case 2:
		  cout<<_year<<"-"<<_month<<"-"<<_day<<"-"<<"星期二"<<endl;
		 
		  break;
	 case 3:
		  cout<<_year<<"-"<<_month<<"-"<<_day<<"-"<<"星期三"<<endl;
		 
		  break;
	 case 4:
		  cout<<_year<<"-"<<_month<<"-"<<_day<<"-"<<"星期四"<<endl;
		 
		  break;
	 case 5:
		  cout<<_year<<"-"<<_month<<"-"<<_day<<"-"<<"星期五"<<endl;
		 
		  break;
	 case 6:
		  cout<<_year<<"-"<<_month<<"-"<<_day<<"-"<<"星期六"<<endl;
		
		  break;
	 case 7:
		  cout<<_year<<"-"<<_month<<"-"<<_day<<"-"<<"星期日"<<endl;
		 
		  break;
	 default:
		
		  break;
	 
	 }
	
 }


 

 bool operator!=(Date &d)
 {
	 if((this->_year != d._year)||(this->_month!=d._month)||(this->_day!=d._day))
	 {
	   return true;
	 }
	 return false;
 }
 bool operator>(Date &d)
 {
	 if(this->_year<=d._year)
	 {
		 if(this->_month<=d._month)
		 {
			 if(this->_day<=d._day)
			 {
			    return false;
			 }
		 }
	 }
	else
	 {
		 return true;
	 }
 }
 Date operator+(int count)
 {
	 int day = _day;
     int month = _month;
	 int year = _year;
	 day += count;
	if(day<0)
	{
	while(day<0)
	{
		month--;
		if(month <= 0)
		{
			month = 12;
			year--;
		}
		day+=DaysToMonth(year,month);
	}
	}
	else 
	{
		while(day>DaysToMonth(year,month))
		{
			day-=DaysToMonth(year,month);
			month++;
			if(month>12)
			{
				month = 1;
				year++;
			}
		}
	}
	return Date(year,month,day);
 }
 Date operator-(int count)
 {
	 int day = _day;
     int month = _month;
	 int year = _year;
	 day -= count;
	if(day<0)
	{
	while(day<0)
	{
		month--;
		if(month <= 0)
		{
			month = 12;
			year--;
		}
		day+=DaysToMonth(year,month);
	}
	}
	else 
	{
		while(day>DaysToMonth(year,month))
		{
			day-=DaysToMonth(year,month);
			month++;
			if(month>12)
			{
				month = 1;
				year++;
			}
		}
	}
	return Date(year,month,day);
 }
 int operator-(Date &d)
 {
	 int n = 0;
	 if(*this>d)
	 {
		 while(*this!=d)
	     {
			 d=d+1;
			 n++;
	     }
	 }
	 else
	 {
		 while(*this!=d)
		 {
			 *this=*this-1;
			 n++;
		 }
	 }
	 return n;
 }
public:
	int _year;
	int _month;
	int _day;
};   

 void DateCalen(int year,int month)
 {
	 int Calen[43] = {0};
	 int Days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	 int i = 0;
	 int j = 1;
	 int n = DayToWeek(year,month,1);
	 for(i = n;i < Days[month]+n;i++)
	 {
		 Calen[i] = j;
		 j++;
	 }
	 cout<<"一"<<"  "<<"二"<<"  "<<"三"<<"  "<<"四"<<"  "<<"五"<<"  "<<"六"<<"  "<<"日"<<endl;
	 for(i = 1;i <43;i++)
	 {
		 if(i<=14)
		 {
			 printf("%d   ",Calen[i]);
		 }
		 else
		 {
			 printf("%d  ",Calen[i]);
		 }
		 if(i%7 == 0)
		 {
		     printf("\n"); 
		 }
	 }
 }
 void menu()
 {
	 cout<<"1:日期加天数"<<endl;
	 cout<<"2:日期减天数"<<endl;
	 cout<<"3:日期减日期"<<endl;
	 cout<<"4:万年历"<<endl;
 }

int main()
{
	int y = 0;
	int m = 0;
	int d = 0;
	int start = 0;
	int count = 0;
	int n = 0;
	menu();
	Date D;
	Date Sub;
	Date ret;
	cin>>start;
	switch(start)
	{

	case 1:
		cout<<"请输入年月日："<<endl;
		cin>>y>>m>>d;
		cout<<"请输入要加的天数:"<<endl;
		cin>>count;
		D._year = y;
		D._month = m;
		D._day = d;
		ret = D + count;
		cout<<"结果：";
		ret.Display();
		break;
	case 2:
        cout<<"请输入年月日："<<endl;
		cin>>y>>m>>d;
		cout<<"请输入要减的天数:"<<endl;
		cin>>count;
		D._year = y;
		D._month = m;
		D._day = d;
		ret = D - count;
		cout<<"结果：";
		ret.Display();
		break;
		break;
	case 3:
		cout<<"请输入被减数年月日："<<endl;
		cin>>y>>m>>d;
		D._year = y;
		D._month = m;
		D._day = d;
		cout<<"请输入减数年月日："<<endl;
		cin>>y>>m>>d;
		Sub._year = y;
		Sub._month = m;
		Sub._day = d;
		 n = D - Sub;
		cout<<"结果："<<n<<"天";
		break;
	case 4:
        cout<<"请输入年月："<<endl;
		cin>>y>>m;
		DateCalen(y,m);
		break;
		
	}
	system("pause");
	return 0;
}

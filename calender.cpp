#include<iostream>

#include<iomanip>

using namespace std;

//直接输入年份就能显示该改年的日历

//但1753年以前的日历不能显示出来，因为之前的历法和今天采用的历法不同，

//则在该年之前的日历不能按本程序的的现代历法方法给出

int MonthDay_leap_year[]={31,29,31,30,31,30,31,31,30,31,30,31};

int MonthDay_common_year[]={31,28,31,30,31,30,31,31,30,31,30,31};

char MonthName[][10]={"January","Feburary","March","April","May","June","July","August","September","October","November","December"};

char Week_of_date[][4]={"Sun","Mon","Tus","Wed","Tri","Fri","Sat"};

//用二维数组保存字符串常量，调用时用*(Week_of_date+jj)  ,jj=0,1,....7

 

bool isleapyear(int year)

{

bool isleap;

isleap=(year%4==0&&year%100!=0)||(0==year%400);

return isleap;

}

 

int leapyearnum(int year)

{

int leapnum=0;

for(int i=1;i<year;i++)

{

if(isleapyear(i))

{

leapnum++;

}

}

return leapnum;

}

 

int find_week_day(int year)

{

int LeapNum=leapyearnum(year);

if(year<1753)

{

cout<<"error! year must  big than 1752"<<endl;

exit(1);

}else

{

int firstday_of_year=(1+(year-1)*365+LeapNum)%7;

return  firstday_of_year;

}

}

 

int *choose_year(int year)

{

int *p;

if(isleapyear(year))

{

p=MonthDay_leap_year; 

}else

{

p=MonthDay_common_year;

}

return p;

}

 

void display_calendar(int year,int week)

{

int *month=choose_year(year);

int spacenum=week;

for(int i=0;i<12;i++)

{

cout<<endl<<"\t  "<<*(MonthName+i)<<setw(6)<<year;

cout<<endl<<"-----------------------------------"<<endl;

int jj=0;

for(int ii=0;ii<7;ii++)

{

cout<<setw(5)<<*(Week_of_date+jj);

jj++;

}

cout<<endl;

for(int k=0;k<spacenum;k++)//每月第一行输出空格

{

cout<<setw(5)<<" ";

}

for(int j=1;j<=month[i];j++)

{

cout<<setw(5)<<j;

if(0==(j+spacenum)%7)

{

cout<<endl;

}

}

cout<<endl<<endl;

spacenum=(spacenum+month[i])%7;//计算下个月首行空格数

}

}

 

int main()

{

int Year;

int Week;

cout<<"Please input the year :";

cin>>Year;

Week=find_week_day(Year);

display_calendar(Year,Week);

return 0;

}

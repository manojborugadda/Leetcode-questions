int op=0;
​
int year= stoi(date.substr(0, 4));
int month = stoi(date.substr(5, 2));
int day = stoi(date.substr(8, 2));
​
​
if(month == 01)
{
return day;
}
if(month == 02)
{
return day+31;
}
for(int i=1;i<month;i++)
{
if(i==2)
{
op = op + 28;
}
else if( i== 1 || i==3 || i== 5 || i==7 || i==8 || i==10 || i ==12 )
{
op = op + 31;
}
else
{
op = op + 30;
}
}
op = op + day;
​
​
​
if(year % 4 == 0)
{
return op+1;
}
else
{
return op;
}
#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<string>
using namespace std;
class validator
{
  time_t currentTime;
  struct tm *localTime;
  int day,month,year;

  public:
  validator()
  {
  time( &currentTime );
  localTime = localtime( &currentTime );
  day    = localTime->tm_mday;
  month  = localTime->tm_mon + 1;
  year   = localTime->tm_year + 1900;
  
  }

bool namevalid(string name)
{
    char nxt;
    bool valid;
 int i=0,length;
 length=name.length();
 while(i<length)
 {
     nxt=name.at(i);
     if( (nxt>=65 && nxt<=90) || (nxt>=97 && nxt<=122) || nxt==' ')
        valid=true;
     else
     {
        valid=false;
        break;
     }
     i++;
 }
 return valid;
}

bool novalid(string ph)
{
    char nxt;
    bool valid;
    int i=0,length;
    length=ph.length();
    if(length!=10)
    {
        valid=false;
        return valid;
    }
    while(i<length)
    {
        nxt=ph.at(i);
        if( nxt>=48 && nxt<=57)
            valid=true;
        else
        {
            valid=false;
            break;
        }
        i++;
    }
    return valid;
}
bool datevalid(int d,int m,int y)
{
    bool valid;
    bool leap=false;
    if(d<=0 || m<=0 || y<=0)
      return false;
    if(year%4==0)
        leap=true;
    if(m==2)
    {
    if(leap)
    {
           if(d>29)
                    return false;
    }
    else
    {
        if(d>28)
            return false;
    }
	}
    if( m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12 )
    {
        if(d>31)
            return false;
    }
    else
    {
        if(d>30)
            return false;
    }
    if(y>year || y<1917)
            return false;
    return true;
}
   int agecal(int d,int m,int y)
   {
   	 int age;
         if(m > month)
		 {
             age=year-y-1;
             return age;
        }
		else
		{
             age=year-y;
             return age;
        }
   }
}val;


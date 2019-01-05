#include<iostream>
#include<limits>
#include<fstream>
#include<ctime>
#include<string.h>
using namespace std;
class validator2
{
  time_t currentTime;
  struct tm *localTime;
  int day,month,year;

  public:
  validator2()
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
}val2;

class agent
{
	public:
		int id;
		char name[30];
		char gender[30];
		char add[30];
		char num[10];
		fstream f,f1;
		void create()
		{
			int wid;
      	f1.open("aid.txt",ios::in);
      	try{
            	if(!f1.is_open())
            		throw (1);
			}
			catch(int x)
			{
				cout<<"\nThe result file is not available\n";
				return;
			}
	  	f1>>wid;
	  	f1.close();
	  	id=wid;
	  	getchar();
	  	cout<<"\n Agent ID:"<<id;
		cout<<"\n Enter the name:";
		do{
		cin>>name;
		}while(val2.namevalid(name)==false);
		cout<<"\n Enter the gender:";
		do{
		cin>>gender;
		}while(val2.namevalid(gender)==false);
		cout<<"\n Enter the address:";
		cin>>add;
		cout<<"\n Enter the phone number:";
			do
		{
		cin>>num;
	}while(val2.novalid(num)==false);
		f.open("agent.txt",ios::app);
		try{
            	if(!f.is_open())
            		throw (1);
			}
			catch(int x)
			{
				cout<<"\nThe result file is not available\n";
				return;
			}
		f<<"\n"<<id;
		f<<"\t"<<name;
		f<<"\t"<<gender;
		f<<"\t"<<add;
		f<<"\t"<<num;
		f.close();
		f1.open("aid.txt",ios::in);
		try{
            	if(!f1.is_open())
            		throw (1);
			}
			catch(int x)
			{
				cout<<"\nThe result file is not available\n";
				return;
			}
	  	f1>>wid;
	  	f1.close();
		f.open("aid.txt",ios::out);
		wid+=1;
		f<<wid;
		f.close();
		}
		void view()
		{
			f.open("agent.txt",ios::in);
			try{
            	if(!f.is_open())
            		throw (1);
			}
			catch(int x)
			{
				cout<<"\nThe result file is not available\n";
				return;
			}
			while(!f.eof())
			{
				f>>id;
				f>>name;
				f>>gender;
				f>>add;
				f>>num;
				cout<<"\n Agent ID:"<<id;
				cout<<"\n Name:"<<name;
				cout<<"\n Gender:"<<gender;
				cout<<"\n Address:"<<add;
				cout<<"\n Phone Number:"<<num;
			}
			f.close();
		}
		void edit()
		{
				int aid;
			f.open("agent.txt",ios::in);
			try{
            	if(!f.is_open())
            		throw (1);
			}
			catch(int x)
			{
				cout<<"\nThe result file is not available\n";
				return;
			}
			f1.open("temp1.txt",ios::out);
			cout<<"\n Enter the Worker id to be edited:";
			cin>>aid;
			while(!f.eof())
			{
				
				f>>id;
				f>>name;
				f>>gender;
				f>>add;
				f>>num;
				if(aid==id)
				{
						getchar();
	  						cout<<"\n Agent ID:"<<id;
		cout<<"\n Enter the name:";
		do{
		cin>>name;
		}while(val2.namevalid(name)==false);
		cout<<"\n Enter the gender:";
		do{
		cin>>gender;
		}while(val2.namevalid(gender)==false);
		cout<<"\n Enter the address:";
		cin>>add;
		cout<<"\n Enter the phone number:";
			do
		{
		cin>>num;
	}while(val2.novalid(num)==false);
					f1<<"\n"<<id;
					f1<<"\t"<<name;
					f1<<"\t"<<gender;
					f1<<"\t"<<add;
					f1<<"\t"<<num;	
				}
				else
				{
					f1<<"\n"<<id;
					f1<<"\t"<<name;
					f1<<"\t"<<gender;
					f1<<"\t"<<add;
					f1<<"\t"<<num;	
				}
			}
			f.close();
			f1.close();
			f1.open("agent.txt",ios::out);
			f.open("temp1.txt",ios::in);
			try{
            	if(!f.is_open())
            		throw (1);
			}
			catch(int x)
			{
				cout<<"\nThe result file is not available\n";
				return;
			}
			while(!f.eof())
			{
					f>>id;
				f>>name;
				f>>gender;
				f>>add;
				f>>num;
				f1<<"\n"<<id;
					f1<<"\t"<<name;
					f1<<"\t"<<gender;
					f1<<"\t"<<add;
					f1<<"\t"<<num;	
			}
			f.close();
			f1.close();
		}
}ag1;

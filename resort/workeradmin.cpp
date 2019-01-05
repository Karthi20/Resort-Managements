#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
using namespace std;
class worker
{
	public:
		char name[200];
		char edu[300];
		char gender[30];
		char add[300];
		char user[30];
		char pass[30];
		int age;
		int st;
		char num[10];
		int dd,mm,yy;
		int id;
		//int status;
	fstream f,f1,f2;
	void create()
	{
		int wid;
      	f1.open("id.txt",ios::in);
	  	f1>>wid;
	  	f1.close();
	  	id=wid;
		getchar();
		cout<<"\n Enter the name:";
		cin.getline(name,200);
		cout<<"\n Enter the DOB:";
		cout<<"\nenter the date";
		cin>>dd;
		cout<<"\nenter the month";
		cin>>mm;
		cout<<"\nenter the year";
		cin>>yy;
		cout<<"\n Enter the age:";
		cin>>age;
		cout<<"\n Enter the gender:";
		cin>>gender;
		cout<<"\n Enter the address:";
		getchar();
		cin.getline(add,300);
		cout<<"\n Enter the phone number:";
		cin>>num;
		cout<<"\n Enter the educational qualification:";
		cin>>edu;
		cout<<"\n Enter the status:";
		cin>>st;
      f.open("worker.txt",ios::app);
    f<<"\n"<<id;
	f<<"\t"<<name;
	f<<"\t"<<dd;
	f<<"\t"<<mm;
	f<<"\t"<<yy;
	f<<"\t"<<age;
	f<<"\t"<<gender;
	f<<"\t"<<add;
	f<<"\t"<<num;
	f<<"\t"<<edu;
	f<<"\t"<<st;
    f.close();
    int i;
	  	f1.open("id.txt",ios::in);
	  	f1>>i;
	  	f1.close();
	  	i=i+1;
	  	wid=i;
		f1.open("id.txt",ios::out);
		f1<<wid;
		f1.close(); 
	}
	void view()
	{ 
	int i;
	f.open("worker.txt",ios::in);
	i=0;
    while(!f.eof())
	{
		i++;
	f>>id;
	cout<<"\n ID:"<<id;
	f>>name;
	cout<<"\n Name:"<<name;
	f>>dd;
	f>>mm;
	f>>yy;
	cout<<"\n DOB:"<<dd<<mm<<yy;
	f>>age;
	cout<<"\n Age:"<<age;
	f>>gender;
	cout<<"\n Gender:"<<gender;
	f>>add;
	cout<<"\n Address:"<<add;
	f>>num;
	cout<<"\n Phone Number:"<<num;
	f>>edu;
	cout<<"\n Educational qualification:"<<edu;
//	f>>user;
//	f>>pass;
		f>>st;
		//cout<<st;
		if(st==0)
		cout<<"\n Blocked person";
	//	cout<<user;
	//	cout<<pass;
	}  
	f.close();
	cout<<"i="<<i;
}
void edit()
{
			int eid;
			f.open("worker.txt",ios::in);
			f1.open("temp1.txt",ios::out);
			cout<<"\n Enter the Worker id to be edited:";
		     cin>>eid;
			while(!f.eof())
		   {
			f>>id;
			f>>name;
			f>>add;
			f>>mm;
			f>>yy;
			f>>age;
			f>>gender;
			f>>add;
			f>>num;
			f>>edu;
			f>>st;
			if(eid==id)
		{
		 	int wid;
      		f2.open("id.txt",ios::in);
	  		f2>>wid;
	  		f2.close();
	  		id=wid-1;
			getchar();
			cout<<"\n Enter the name:";
			cin.getline(name,200);
			cout<<"\n Enter the DOB:";
			cout<<"\nenter the date";
			cin>>dd;
			cout<<"\nenter the month";
			cin>>mm;
			cout<<"\nenter the year";
			cin>>yy;
			cout<<"\n Enter the age:";
			cin>>age;
			cout<<"\n Enter the gender:";
			cin>>gender;
			cout<<"\n Enter the address:";
			getchar();
			cin.getline(add,300);
			cout<<"\n Enter the phone number:";
			cin>>num;
			cout<<"\n Enter the educational qualification:";
			cin>>edu;
			cout<<"\n Enter the status:";
			cin>>st;
   		 	f1<<"\n"<<id;
			f1<<"\t"<<name;
			f1<<"\t"<<dd;
			f1<<"\t"<<mm;
			f1<<"\t"<<yy;
			f1<<"\t"<<age;
			f1<<"\t"<<gender;
			f1<<"\t"<<add;
			f1<<"\t"<<num;
			f1<<"\t"<<edu;
			f1<<"\t"<<st;
   }
	else
	{
			f1<<"\n"<<id;
			f1<<"\t"<<name;
			f1<<"\t"<<dd;
			f1<<"\t"<<mm;
			f1<<"\t"<<yy;
			f1<<"\t"<<age;
			f1<<"\t"<<gender;
			f1<<"\t"<<add;
			f1<<"\t"<<num;
			f1<<"\t"<<edu;
			f1<<"\t"<<st;	
	}
	   }
     	f.close();
		f1.close();
		f.open("temp1.txt",ios::in);
		f1.open("worker.txt",ios::out);
			while(!f.eof())
			{
			f>>id;
			f>>name;
			f>>add;
			f>>mm;
			f>>yy;
			f>>age;
			f>>gender;
			f>>add;
			f>>num;
			f>>edu;
			f>>st;
			f1<<"\n"<<id;
			f1<<"\t"<<name;
			f1<<"\t"<<dd;
			f1<<"\t"<<mm;
			f1<<"\t"<<yy;
			f1<<"\t"<<age;
			f1<<"\t"<<gender;
			f1<<"\t"<<add;
			f1<<"\t"<<num;
			f1<<"\t"<<edu;
			f1<<"\t"<<st;	
			}
			f.close();
			f1.close();
		}
	void block()
	{
		int bid;
		cout<<"\n Enter the Worker Id to be blocked:";
		cin>>bid;
		f.open("worker.txt",ios::in);
		f1.open("temp1.txt",ios::out);
	while(!f.eof())
	{
			f>>id;
			f>>name;
			f>>add;
			f>>mm;
			f>>yy;
			f>>age;
			f>>gender;
			f>>add;
			f>>num;
			f>>edu;
			f>>st;
			if(id==bid)
			{
				st=0;
			f1<<"\n"<<id;
			f1<<"\t"<<name;
			f1<<"\t"<<dd;
			f1<<"\t"<<mm;
			f1<<"\t"<<yy;
			f1<<"\t"<<age;
			f1<<"\t"<<gender;
			f1<<"\t"<<add;
			f1<<"\t"<<num;
			f1<<"\t"<<edu;
			f1<<"\t"<<st;		
			}
			else
			{
			f1<<"\n"<<id;
			f1<<"\t"<<name;
			f1<<"\t"<<dd;
			f1<<"\t"<<mm;
			f1<<"\t"<<yy;
			f1<<"\t"<<age;
			f1<<"\t"<<gender;
			f1<<"\t"<<add;
			f1<<"\t"<<num;
			f1<<"\t"<<edu;
			f1<<"\t"<<st;	
			}
	}
		f.close();
		f1.close();
	f.open("worker.txt",ios::out);
	f1.open("temp1.txt",ios::in);
		while(!f1.eof())
		{
				f1>>id;
			f1>>name;
			f1>>add;
			f1>>mm;
			f1>>yy;
			f1>>age;
			f1>>gender;
			f1>>add;
			f1>>num;
			f1>>edu;
			f1>>st;
			 f<<"\n"<<id;
			f<<"\t"<<name;
			f<<"\t"<<dd;
			f<<"\t"<<mm;
			f<<"\t"<<yy;
			f<<"\t"<<age;
			f<<"\t"<<gender;
			f<<"\t"<<add;
			f<<"\t"<<num;
			f<<"\t"<<edu;
			f<<"\t"<<st;
		}		
	f.close();
	f1.close();
//	d.dis();
}
}obj1;

#include<iostream>
#include<fstream>
using namespace std;
class cworker
{
	public:
		char name[200];
		char edu[300];
		char gender[30];
		char add[300];
		int age;
		int st;
		char num[10];
		int dd,mm,yy;
		int id;
		fstream f;
void view()
	{ 
	f.open("worker.txt",ios::in);
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
//	f>>user;
//	f>>pass;
		cout<<"\n ID:"<<id;
		cout<<"\n Name:"<<name;
		cout<<"\n DOB:"<<dd<<mm<<yy;
		cout<<"\n Age:"<<age;
		cout<<"\n Gender:"<<gender;
		cout<<"\n Address:"<<add;
		cout<<"\n Phone Number:"<<num;
		cout<<"\n Educational qualification:"<<edu;
		cout<<st;
		if(st==0)
		cout<<"\n Blocked person";
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
//	f>>user;
//	f>>pass;
		cout<<"\n ID:"<<id;
		cout<<"\n Name:"<<name;
		cout<<"\n DOB:"<<dd<<mm<<yy;
		cout<<"\n Age:"<<age;
		cout<<"\n Gender:"<<gender;
		cout<<"\n Address:"<<add;
		cout<<"\n Phone Number:"<<num;
		cout<<"\n Educational qualification:"<<edu;
		//cout<<st;
		if(st==0)
		cout<<"\n Blocked person";
	//	cout<<user;
	//	cout<<pass;
	}  
	f.close();
}
}o1;

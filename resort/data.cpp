#include<iostream>
#include<limits>
#include<fstream>
#include<conio.h>
#include "valid.cpp"
using namespace std;
struct off
{
	int id;
 char facc[200];
 off *next;
};
class data
{
	public:
		int id;
		int days;
		int nights;
		int cost;
		int age;
		int st;
		int dd,mm,yy;
		char name[200];
		char duration[200];
		char features[200];
		char edu[300];
		char gender[30];
		char add[300];
		char user[30];
		char pass[30];
		char num[10];
		
		fstream f,f1,f2;
		
};
class offers:public data
{
	public:
	void create()
	{
		 int wid;
      	f1.open("oid.txt",ios::in);
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
	  	cout<<"\n Enter the offer Id:"<<id;
		cout<<"\n Enter the name of the offers:";
		getchar();
		do{
		cin>>name;
		}while(val.namevalid(name)==false);
		//cin.ignore();
		cout<<"\n Enter the duration of the offers:";
		//getchar();
		cin>>duration;
		//cin.ignore();
		cout<<"\n Enter the features of the offers:";
		cin>>features;
	//	cin.ignore();
		cout<<"\n Enter the total cost:";
		while(!(cin>>cost))
		{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}
		f.open("offers.txt",ios::app);
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
		f<<"\t"<<duration;
		f<<"\t"<<features;
		f<<"\t"<<cost;
		f.close();
				f1.open("oid.txt",ios::in);
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
				f.open("oid.txt",ios::out);
				wid+=1;
				f<<wid;
				f.close();
	}
	void view()
	{
		f.open("offers.txt",ios::in);
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
		f>>duration;
		f>>features;
		f>>cost;
			cout<<"\n Offer Name:"<<name;
			cout<<"\n Offer Id:"<<id;
			cout<<"\n Offer Duration:"<<duration;
			cout<<"\n Offer features:"<<features;
			cout<<"\n Offer cost:"<<cost;
     	}
     	f.close();
	}
	void edit()
	{
		int eid;
		cout<<"\n Enter the offer Id to be edited:";
		cin>>eid;
		f.open("offers.txt",ios::in);
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
		while(!f.eof())
		{	
		f>>id;
		f>>name;
		f>>duration;
		f>>features;
		f>>cost;
		if(eid==id)
		{
		cout<<"\n Enter the offer Id:"<<id;
		cout<<"\n Enter the name of the offers:";
		getchar();
		do {
			cin>>name;
		}while(val.namevalid(name)==false);
		//cin.ignore();
		cout<<"\n Enter the duration of the offers:";
		//getchar();
		cin.getline(duration,200);
		//cin.ignore();
		cout<<"\n Enter the features of the offers:";
		cin.getline(features,200);
	//	cin.ignore();
		cout<<"\n Enter the offer percentage:";
		while(!(cin>>cost))
		{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}
		f1<<"\n"<<id;
		f1<<"\t"<<name;
		f1<<"\t"<<duration;
		f1<<"\t"<<features;
		f1<<"\t"<<cost;	
		     
		}
			else
	     	{
	     			f1<<"\n"<<id;
		f1<<"\t"<<name;
		f1<<"\t"<<duration;
		f1<<"\t"<<features;
		f1<<"\t"<<cost;
			 }
			}
			f.close();
			f1.close();
			f.open("offers.txt",ios::out);
			f1.open("temp1.txt",ios::in);
			try{
            	if(!f1.is_open())
            		throw (1);
			}
			catch(int x)
			{
				cout<<"\nThe result file is not available\n";
				return;
			}
		while(!f1.eof())
			{
			 f1>>id;
		f1>>name;
		f1>>duration;
		f1>>features;
		f1>>cost;
		f<<"\n"<<id;
		f<<"\t"<<name;
		f<<"\t"<<duration;
		f<<"\t"<<features;
		f<<"\t"<<cost;
			}
			f.close();
			f1.close();	
	}
	void del()
	{
		int did;
		cout<<"\n Enter the offer Id to be edited:";
		while(!(cin>>did))
		{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}
		f.open("offers.txt",ios::in);
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
	while(!f.eof())
		{
		f>>id;
		f>>name;
		f>>duration;
		f>>features;
		f>>cost;
			if(did!=id)
				{
				f1<<"\n"<<id;
			f1<<"\t"<<name;
			f1<<"\t"<<duration;
			f1<<"\t"<<features;
			f1<<"\t"<<cost;	
				}
		}
		f.close();
		f1.close();
		f.open("offers.txt",ios::out);
		f1.open("temp1.txt",ios::in);
		while(!f1.eof())
		{
		f1>>id;
		f1>>name;
		f1>>duration;
		f1>>features;
		f1>>cost;
		f<<"\n"<<id;
			f<<"\t"<<name;
			f<<"\t"<<duration;
			f<<"\t"<<features;
			f<<"\t"<<cost;
			
		}
		f.close();
		f1.close();
	}
}obj2;
class worker:public data
{
	public:
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
	try{
            	if(!f.is_open())
            		throw (1);
			}
			catch(int x)
			{
				cout<<"\nThe result file is not available\n";
				return;
			}
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
	//cout<<"i="<<i;
}
void edit()
{
			int eid;
			f.open("worker.txt",ios::in);
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
      		try{
            	if(!f2.is_open())
            		throw (1);
			}
			catch(int x)
			{
				cout<<"\nThe result file is not available\n";
				return;
			}
	  		f2>>wid;
	  		f2.close();
	  		id=wid-1;
		cout<<"\n Enter the name:";
		do{
		cin>>name;
		}while(val.namevalid(name)==false);
		do{
		cout<<"\n Enter the DOB:";
		cout<<"\nenter the date";
			while(!(cin>>dd))
		{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}
		cout<<"\nenter the month";
			while(!(cin>>mm))
		{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}
		cout<<"\nenter the year";
			while(!(cin>>yy))
		{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}
	}while(val.datevalid(dd,mm,yy)==false);
	age=val.agecal(dd,mm,yy);
		cout<<"\n The age is:"<<age;
		cout<<"\n Enter the gender:";
		do{
		cin>>gender;
		}while(val.namevalid(gender)==false);
		cout<<"\n Enter the address:";
		do{
		cin>>add;
		}while(val.namevalid(gender)==false);
		cout<<"\n Enter the phone number:";
		do{
		cin>>num;
		}while(val.namevalid(gender)==false);
		cout<<"\n Enter the educational qualification:";
		do{
		cin>>edu;
		}while(val.namevalid(gender)==false);
		cout<<"\n Enter the Stauts:";
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
		try{
            	if(!f.is_open())
            		throw (1);
			}
			catch(int x)
			{
				cout<<"\nThe result file is not available\n";
				return;
			}
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
	try{
            	if(!f1.is_open())
            		throw (1);
			}
			catch(int x)
			{
				cout<<"\nThe result file is not available\n";
				return;
			}
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
void block(int st1)
	{
		int bid;
		cout<<"\n Enter the Worker Id to be blocked:";
		cin>>bid;
		f.open("worker.txt",ios::in);
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
				st=st1;
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
	try{
            	if(!f1.is_open())
            		throw (1);
			}
			catch(int x)
			{
				cout<<"\nThe result file is not available\n";
				return;
			}
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
void work()
{
	string work;
	int i=1;
	f.open("work.txt",ios::app);
	cout<<"\n Enter the Worker Id:";
	cin>>work;
	f<<"\n"<<id;
	f<<"\t"<<work;
	f<<"\t"<<i;
	f.close();
}
}obj1;
class package:public data
{
	public:
   void add()
   {
   //	f.open("package.txt",ios::app);
   	    int wid;
      	f1.open("pid.txt",ios::in);
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
	cout<<"Package Id:"<<id;
   	cout<<"\n Enter the package name:";
   	getchar();
   	cin.getline(name,200);
   //	cin.ignore();
   	cout<<"\n Enter the total no. of days and night:";
   	cin>>days>>nights;
  // 	cin.ignore();
   	cout<<"\n Enter the total cost:";
   	cin>>cost;
   	f.open("package.txt",ios::app);
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
   	f<<"\t"<<days;
   	f<<"\t"<<nights;
   	f<<"\t"<<cost;
   	f.close();
   	 int i;
	  	f1.open("pid.txt",ios::in);
	  	try{
            	if(!f1.is_open())
            		throw (1);
			}
			catch(int x)
			{
				cout<<"\nThe result file is not available\n";
				return;
			}
	  	f1>>i;
	  	f1.close();
	  	i=i+1;
	  	wid=i;
		f1.open("pid.txt",ios::out);
		f1<<wid;
		f1.close(); 
   }
   void edit()
  {
  	int eid;
  	cout<<"\n Enter the package id that u want to edit:";
  	cin>>eid;
  	f.open("package.txt",ios::in);
  	try{
            	if(!f.is_open())
            		throw (1);
			}
			catch(int x)
			{
				cout<<"\nThe result file is not available\n";
				return;
			}
  	f1.open("temp.txt",ios::out);
  	while(!f.eof())
	  {
	  	f>>id;
  		f>>name;
  		f>>days;
  		f>>nights;
  		f>>cost;
	       if(id==eid)
  	    {	
  	    	cout<<"Package Id:"<<id;
   			cout<<"\n Enter the package name:";
   			getchar();
   			cin.getline(name,200);
   //	cin.ignore();
   			cout<<"\n Enter the total no. of days and night:";
   			cin>>days>>nights;
  // 	cin.ignore();
   			cout<<"\n Enter the total cost:";
   			cin>>cost;
		  	f1<<"\n"<<id;
   			f1<<"\t"<<name;
   			f1<<"\t"<<days;
   			f1<<"\t"<<nights;
   			f1<<"\t"<<cost;	
  	    
   			
		}
		else
	{
			f1<<"\n"<<id;
   			f1<<"\t"<<name;
   			f1<<"\t"<<days;
   			f1<<"\t"<<nights;
   			f1<<"\t"<<cost;	
		  
	  } 
}
	  f.close();
	  f1.close();
	  f1.open("temp.txt",ios::in);
	  try{
            	if(!f1.is_open())
            		throw (1);
			}
			catch(int x)
			{
				cout<<"\nThe result file is not available\n";
				return;
			}
	  f.open("package.txt",ios::out);
	while(!f1.eof())
	  {
  	    f1>>id;
  		f1>>name;
  		f1>>days;
  		f1>>nights;
  		f1>>cost;
  		f<<"\n"<<id;
   			f<<"\t"<<name;
   			f<<"\t"<<days;
   			f<<"\t"<<nights;
   			f<<"\t"<<cost;
		  
	  }
	  f1.close();
	  f.close();   	
   } 
   void del()
   {
   	int did;
  	cout<<"\n Enter the package id that u want to delete:";
  	cin>>did;
  	f.open("package.txt",ios::in);
  	try{
            	if(!f.is_open())
            		throw (1);
			}
			catch(int x)
			{
				cout<<"\nThe result file is not available\n";
				return;
			}
  	f1.open("temp.txt",ios::out);
  	while(!f.eof())
  	{
  		f>>id;
  		f>>name;
  		f>>days;
  		f>>nights;
  		f>>cost;
  		cout<<id<<did;
  		if(id!=did)
  		{
  			cout<<"check;";
  			f1<<"\n"<<id;
   			f1<<"\t"<<name;
   			f1<<"\t"<<days;
   			f1<<"\t"<<nights;
   			f1<<"\t"<<cost;		
		 }
  		
	}
	f.close();
	f1.close();
	f1.open("temp.txt",ios::in);
	try{
            	if(!f1.is_open())
            		throw (1);
			}
			catch(int x)
			{
				cout<<"\nThe result file is not available\n";
				return;
			}
	f.open("package.txt",ios::out); 
	while(!f1.eof())
	  {
	  	f1>>id;
  		f1>>name;
  		f1>>days;
  		f1>>nights;
  		f1>>cost;
	f<<"\n"<<id;
   	f<<"\t"<<name;
   	f<<"\t"<<days;
   	f<<"\t"<<nights;
   	f<<"\t"<<cost;
	  }
	  f1.close();
	  f.close();   	
	  //d.dis(); 
 }
 void view()
 {
  	//.open("package.txt",ios::in);
  	f.open("package.txt",ios::in);
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
  		f>>days;
  		f>>nights;
  		f>>cost;
  	cout<<"\n Id:"<<id;
  	cout<<"\n Name:"<<name;
  	cout<<"\n the total no. of days and night:"<<days<<nights;
  	cout<<"\nTotal cost:"<<cost;
} 
f.close();
}
}obj;
class facility:public data
{
	public:
		void add()
		{
			//f.open("fac.txt",ios::app);
			int wid;
      		f1.open("fid.txt",ios::in);
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
			cout<<"\n Enter the facility Id:"<<id;
			cout<<"\n Enter the name of the Facility:";
			getchar();
			cin.getline(name,200);
			f.open("fac.txt",ios::app);
			f<<"\n"<<id;
			f<<"\t"<<name;
			f.close();
			f1.open("fid.txt",ios::in);
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
				f.open("fid.txt",ios::out);
				wid+=1;
				f<<wid;
				f.close();
		}
		void view()
		{
			f.open("fac.txt",ios::in);
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
				cout<<"\n Id:"<<id;
				cout<<"\n Facility name:"<<name;
			}
			f.close();
		}
			void editt()
	{	
	off *ohead;
 off *otemp;
 ohead=NULL;
    ohead=NULL;
off *new1=ohead,*end=new1;
	   int eid;
			f.open("fac.txt",ios::in);
			try{
            	if(!f.is_open())
            		throw (1);
			}
			catch(int x)
			{
				cout<<"\nThe result file is not available\n";
				return;
			}
			cout<<"\n Enter the Facility Id to be edited:";
			cin>>eid;
			while(!f.eof())
			{new1=new off;
		 	 f>>new1->id;
		 	 cout<<new1->id;
		 	 f>>new1->facc;
		 	 cout<<new1->facc;
		 	 if(new1->id==eid)
		 	 { cout<<"\nENTER THE DESCRIPTION";
		 	 cin>>new1->facc;
		 	  }
		 	  if(ohead==NULL)
           ohead=new1;
        else
           end->next=new1;
        end=new1;
        end->next=NULL;
				
			}
			f.close();
			f.open("fac.txt",ios::out);
			new1=ohead;
			 while(new1!=NULL)
    {
    	f<<"\n"<<new1->id;
    	cout<<new1->id;
    	f<<"\t"<<new1->facc;
    	cout<<new1->facc;
		new1=new1->next;
    }
f.close(); }
	void edit()
		{
			int eid;
			f.open("fac.txt",ios::in);
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
			cout<<"\n Enter the Facility Id to be edited:";
			cin>>eid;
		while(!f.eof())
			{
				f>>id;
				f>>name;
				
				if(eid==id)
				{
						cout<<"\n Enter the facility Id:"<<id;
						cout<<"\n Enter the name of the Facility:";
						getchar();
						cin.getline(name,200);
				f1<<"\n"<<id;
				f1<<"\t"<<name;
				}
				else
					{
						f1<<"\n"<<id;
						f1<<"\t"<<name;
					}
				}
			f.close();
			f1.close();
			f.open("fac.txt",ios::out);
			f1.open("temp1.txt",ios::in);
			try{
            	if(!f1.is_open())
            		throw (1);
			}
			catch(int x)
			{
				cout<<"\nThe result file is not available\n";
				return;
			}
			while(!f1.eof())
			{
					f1>>id;
				f1>>name;
				f<<"\n"<<id;
				f<<"\t"<<name;
			}
			f.close();
			f1.close();
		}
		void del()
		{
			
			int did;
			f.open("fac.txt",ios::in);
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
			cout<<"\n Enter the Facility Id to be deleted:";
			cin>>did;
			while(!f.eof())
			{
				f>>id;
				f>>name;
				if(did!=id)
				  	{
				  		f1<<"\n"<<id;
				  		f1<<"\t"<<name;
					  }
			}
			f.close();
			f1.close();
			f.open("fac.txt",ios::out);
			f1.open("temp1.txt",ios::in);
			try{
            	if(!f1.is_open())
            		throw (1);
			}
			catch(int x)
			{
				cout<<"\nThe result file is not available\n";
				return;
			}
				while(!f1.eof())
			{
					f1>>id;
					f1>>name;
					f<<"\n"<<id;
					f<<"\n"<<name;	
			}
			f.close();
			f1.close();
		}
}obj3;


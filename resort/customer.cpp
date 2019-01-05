#include<iostream>
#include<limits>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<limits>
#include<ctime>
#include<stdlib.h>
#include "package2.cpp"
#include "offer2.cpp"
using namespace std;
int i=0,room[10]={0,0,0,0,0,0,0,0,0,0};
int info;
int hea=0,en=0;
int priq[10];
struct node
{
int data;
node *next;
};
 node *head;
 node *temp;
 class validator1
{
  time_t currentTime;
  struct tm *localTime;
  int day,month,year;

  public:
  validator1()
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

bool novalid(string aadhar)
{
    char nxt;
    bool valid;
    int i=0,length;
    length=aadhar.length();
    if(length!=10)
    {
        valid=false;
        return valid;
    }
    while(i<length)
    {
        nxt=aadhar.at(i);
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
}val1;
class customer
{
    public:
   int id;
	int mm,dd,yy;
	int age;
	int points;
	char name[10];
	char gender[10];
    char qua[10];
    char num[10];
    char occ[10];
    
    fstream f,f1,f2,f3;
    void create()
	{
		int wid;
      	f1.open("cid.txt",ios::in);
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
	  	cout<<"\n Customer ID:"<<id;
		cout<<"\n Enter the name:";
		do{
		cin>>name;
		}while(val1.namevalid(name)==false);
		cout<<"\n Enter the DOB:";
		do{
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
		
		}while(val1.datevalid(dd,mm,yy)==false);
		age=val1.agecal(dd,mm,yy);
		cout<<"\n Enter the age:"<<age;
		cout<<"\n Enter the gender:";
		do{
		cin>>gender;
		}while(val1.namevalid(gender)==false);
		cout<<"\n Enter the address:";
		cin>>qua;
		//cout<<add;ame;
		cout<<"\n Enter the phone number:";
		do
		{
		cin>>num;
	}while(val1.novalid(num)==false);
		
		cout<<"\n Occupation:";
		cin>>occ;
		f.open("customer.txt",ios::app);
		try{
            	if(!f.is_open())
            		throw (1);
			}
			catch(int x)
			{
				cout<<"\nThe result file is not available\n";
				return;
			}
			points=100;
		f<<"\n"<<id;
		f<<"\t"<<name;
		f<<"\t"<<dd;
		f<<"\t"<<mm;
		f<<"\t"<<yy;
		f<<"\t"<<age;
		f<<"\t"<<gender;
		f<<"\t"<<qua;
		f<<"\t"<<num;
		f<<"\t"<<occ;
		f<<"\t"<<points;
		f.close();
		f1.open("cid.txt",ios::in);
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
		f.open("cid.txt",ios::out);
		wid+=1;
		f<<wid;
		f.close();	
	}
   	void view()
	{
	 	f.open("customer.txt",ios::in);
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
		 f>>dd;
		 f>>mm;
		 f>>yy;
		 f>>age;
		 f>>gender;
		 f>>qua;
		 f>>num;
		 f>>occ;
		 f>>points;
		cout<<"\n ID:"<<id;
		cout<<"\n Name:"<<name;
		cout<<"\n DOB:"<<dd<<mm<<yy;
		cout<<"\n Age:"<<age;
		cout<<"\n Gender:"<<gender;
		cout<<"\n address:"<<qua;
		cout<<"\n Phone Number:"<<num;
		cout<<"\n Occupation:"<<occ;
	}
}
	void edit()
	{
		int eid;
			f.open("customer.txt",ios::in);
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
		 	f>>dd;
		 	f>>mm;
		 	f>>yy;
		 	f>>age;
		 	f>>gender;
		 	f>>qua;
		 	f>>num;
		 	f>>occ;
		 	f>>points;
			if(eid==id)
				{
					 	cout<<"\n Customer ID:"<<id;
		cout<<"\n Enter the name:";
		do{
		cin>>name;
		}while(val1.namevalid(name)==false);
		cout<<"\n Enter the DOB:";
		do{
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
		
		}while(val1.datevalid(dd,mm,yy)==false);
		age=val1.agecal(dd,mm,yy);
		cout<<"\n Enter the age:"<<age;
		cout<<"\n Enter the gender:";
		do{
		cin>>gender;
		}while(val1.namevalid(gender)==false);
		cout<<"\n Enter the address:";
		cin>>qua;
		//cout<<add;ame;
		cout<<"\n Enter the phone number:";
		do
		{
		cin>>num;
	}while(val1.novalid(num)==false);
		
		cout<<"\n Occupation:";
	do{
		cin>>occ;
		}while(val1.namevalid(gender)==false);
		points=100;
		 			f1<<"\n"<<id;
					f1<<"\t"<<name;
					f1<<"\t"<<dd;
					f1<<"\t"<<mm;
					f1<<"\t"<<yy;
					f1<<"\t"<<age;
					f1<<"\t"<<gender;
					f1<<"\t"<<qua;
					f1<<"\t"<<num;
					f1<<"\t"<<occ;
					f1<<"\t"<<points;
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
				f1<<"\t"<<qua;
				f1<<"\t"<<num;
				f1<<"\t"<<occ;	
				f1<<"\t"<<points;
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
		f1.open("customer.txt",ios::out);
			while(!f.eof())
			{
		      f>>id;
		 	f>>name;
		 	f>>dd;
		 	f>>mm;
		 	f>>yy;
		 	f>>age;
		 	f>>gender;
		 	f>>qua;
		 	f>>num;
		 	f>>occ;
		 	f>>points;
		 	 f1<<"\n"<<id;
				f1<<"\t"<<name;
				f1<<"\t"<<dd;
				f1<<"\t"<<mm;
				f1<<"\t"<<yy;
				f1<<"\t"<<age;
				f1<<"\t"<<gender;
				f1<<"\t"<<qua;
				f1<<"\t"<<num;
				f1<<"\t"<<occ;
				f1<<"\t"<<points;	
			}
			f.close();
			f1.close();
		}
void book()
{
	f3.open("bill.txt",ios::app);
			customer cus1;
		    int flag=0;
			char custph[10];
			int pack;
			int off;
			login:
			cout<<"Enter your phone number";
			cin>>custph;
			f1.open("customer.txt",ios::in);
		while(!f1.eof())
		{
			 f1>>id;
		 	f1>>name;
		 	f1>>dd;
		 	f1>>mm;
		 	f1>>yy;
		 	f1>>age;
		 	f1>>gender;
		 	f1>>qua;
		 	f1>>num;
		 	f1>>occ;
		 	f1>>points;
		 	cout<<custph<<num;
		   if(!strcmp(custph,num))
		   {f3<<"\n"<<id<<"\t"<<points;
			flag=1;
		break;
		}
		}
		f1.close();
		if(flag!=1)
		{
		cout<<"Enter the valid phone number";
		goto login;
		}
Again:
cout<<"PACKAGES";
flag=0;
pack1.view();
cout<<"Enter the package Id:";
cin>>pack;
f1.open("package.txt",ios::in);
while(!f1.eof())
{
		f1>>pack1.id;
  		f1>>pack1.name;
  		f1>>pack1.days;
  		f1>>pack1.nights;
  		f1>>pack1.cost;
  		cout<<pack<<pack1.id;
     if(pack==pack1.id)
	 {f3<<"\t"<<pack1.id<<"\t"<<pack1.cost;		
	 flag=1;
		break;
	}
}
f1.close();
if(flag!=1)
	{
	   cout<<"Enter the valid package id";
	   goto Again;	
	}
Begin:		

cout<<"OFFERS";
int i=0,pri;
if(points<100)
{pri=3;
}
else
if(points<1000)
{
	pri=2;
}else
{pri=0;
}

flag=0;
f1.open("offers.txt",ios::in);
while(!f1.eof())
		{
		f1>>offer1.oid;
		f1>>offer1.name;
		f1>>offer1.duration;
		f1>>offer1.features;
		f1>>offer1.cost;
	if(i>pri)
{
		cout<<"\n"<<offer1.oid;
		cout<<"\n"<<offer1.name;
		cout<<"\n"<<offer1.duration;
		cout<<"\n"<<offer1.features;
		cout<<"\n"<<offer1.cost;	
}i++;
     	}	f1.close();
     
		 
     	cout<<"Enter the offer id";
cin>>off;
f1.open("offers.txt",ios::in);
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
		f1>>offer1.oid;
		f1>>offer1.name;
		f1>>offer1.duration;
		f1>>offer1.features;
		f1>>offer1.cost;
		   if(off==offer1.oid)
		   {f3<<"\t"<<offer1.oid<<"\t"<<offer1.cost;
			flag=1;
		break;
		}
		}
		f1.close();
		if(flag!=1)
		{
		cout<<"Enter the valid offer id";
		goto Begin;
		}
int ch,n;
  node *newl=NULL,*end=newl;
  int count=0;
  head=NULL;
  cout<<"\n1.AC\n2.NON-AC\n3.MASTER \n4.MINI \n5.JACUZI";
  cin.ignore();
  cout<<"ENTER YOUR CHOICE";
  cin>>ch;
  cout<<"ENTER THE NUMBER OF ROOMS\t";
  cin>>n;
  f3<<"\t"<<ch<<"\t"<<n;
f1.open("rooms.txt",ios::in);
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
  		f1>>info;
        newl=new node;
        newl->data=info;
        if(newl->data/100==ch)
        {
			count++;
		}
        if(head==NULL)
           head=newl;
        else
        end->next=newl;
        end=newl;
        end->next=NULL;
    }
  f1.close();
  newl=head;
  if(count>=n)
  {
    cout<<"\nROOMS ARE AVAILBLE\n";
  	while(n>0)
  { 
   if(newl->data/100==ch)
   {
    cout<<"\nROOM NO ALLOTED: "<<newl->data;
  	f3<<"\t"<<newl->data;
	  newl->data=0;
  	n--;
   }
  if(newl->next!=NULL)
    newl=newl->next;
  }
  }
  else
    cout<<"ROOMS ARE NOT AVAILABLE";
  newl=head;
  f1.open("rooms.txt",ios::out);
     while(newl!=NULL)
     {
     	if(newl->data!=0)
     	{
     		f1<<"\t"<<newl->data;
		}
		   newl=newl->next;
	 }
	 f1.close();
     f3.close();}
  	 int billing()
  	 {int rcost,cust,ch,n,rooms[100],flag;
  	 	f3.open("bill.txt",ios::in);
  	 	cout<<"\nENTER THE CUSTOMER ID TO BILL";
  	 	cin>>cust;
  	 	flag=0;
  	 	while(!f3.eof())
  	 	{
		   	f3>>id;
  	 		f3>>points;
  	 		f3>>pack1.id>>pack1.cost;
  	 		f3>>offer1.oid>>offer1.cost;
  	 		f3>>ch>>n;	
		   for(int i=0;i<n;i++)
		   f3>>rooms[i];
		   if(id==cust)
		   {
		   	flag=1;
 			switch(ch)
 			{case 1:rcost=2000*n;
 			break;
 			case 2:rcost=5000*n;
 			break;
 			case 3:rcost=8000*n;
 			break;
 			case 4:rcost=10000*n;
 			break;
 			case 5:rcost=15000*n;
 			break;
			 }
			 cout<<"\n\t\t\t\tPACKAGE\n"<<pack1.id<<"\t"<<pack1.cost;
			 cout<<"\n\t\t\t\tOFFER\n"<<offer1.oid<<"\t"<<offer1.cost;
			 cout<<"\n\t\t\t\tROOMS\n"<<rcost;
			 cout<<"\nTOTAL COST\t\t\t\t\n"<<rcost+pack1.cost+offer1.cost;
			 f3.close();
			 f1.open("bill.txt",ios::in);
			 f3.open("temp1.txt",ios::out);
			 int sid;
			 while(!f1.eof())
			 {
			 	f1>>sid;
  	 			f1>>points;
  	 			f1>>pack1.id>>pack1.cost;
  	 			f1>>offer1.oid>>offer1.cost;
  	 			f1>>ch>>n;	
		   for(int i=0;i<n;i++)
		   f3>>rooms[i];
		   if(id!=sid)
		   {
		   	f3<<"\n"<<sid;
		   	f3<<"\t"<<points;
		   	f3<<"\t"<<pack1.id;
		   	f3<<"\t"<<pack1.cost;
		   	f3<<"\t"<<offer1.oid;
		   	f3<<"\t"<<offer1.cost;
		   }
		   f3.close();
		   f1.close();
		   f1.open("temp1.txt",ios::in);
		   f3.open("bill.txt",ios::out);
		   while(!f1.eof())
		   {
		   		f1>>sid;
  	 			f1>>points;
  	 			f1>>pack1.id>>pack1.cost;
  	 			f1>>offer1.oid>>offer1.cost;
  	 			f1>>ch>>n;	
		   for(int i=0;i<n;i++)
		   f3>>rooms[i];
		   f3<<"\n"<<sid;
		   	f3<<"\t"<<points;
		   	f3<<"\t"<<pack1.id;
		   	f3<<"\t"<<pack1.cost;
		   	f3<<"\t"<<offer1.oid;
		   	f3<<"\t"<<offer1.cost;
		   }
		   f1.close();
		   f3.close();
			 }
			 f3.open("rooms.txt",ios::app);
			 for(int i=0;i<n;i++)
			 f3<<"\t"<<rooms[i];
			 f3.close();
		   break;
		   }
		   }
		  	   }
  }cus;
  

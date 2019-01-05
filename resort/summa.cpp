#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
class customer
{
    public:
    int id;
	int mm,dd,yy;
	int age;
	char name[10];
	char gender[10];
    char qua[10];
    char num[10];
    char occ[10];
   //char ar[10];
    
    fstream f,f1,f2;
    void create()
	{   
	    int wid;
      	f1.open("cid.txt",ios::in);
	  	f1>>wid;
	  	f1.close();
	  	id=wid;
		
	  	getchar();
		cout<<"\n Enter the name:";
		cin>>name;
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
		cout<<"\n Addresss:";
		cin>>qua;
		//cout<<"\n Enter the address:";
		//cin>>ar;
		//cout<<add;
		cout<<"\n Enter the phone number:";
		cin>>num;
		cout<<"\n Occupation:";
		cin>>occ;
		
	}
	void add1()
	{
	   int wid;
		customer a;
		a.create();
		f.open("customer.txt",ios::app|ios::binary);
		f.write((char*)&a,sizeof(class customer));
		f.close();
		f1.open("cid.txt",ios::in);
	  	f1>>wid;
	  	f1.close();
		f.open("cid.txt",ios::out);
		wid+=1;
		f<<wid;
		f.close();	
	}	
   	void view()
	{ 
		cout<<"\n ID:"<<id;
		cout<<"\n Name:"<<name;
		cout<<"\n DOB:"<<dd<<mm<<yy;
		cout<<"\n Age:"<<age;
		cout<<"\n Gender:"<<gender;
		cout<<"\n Address:"<<qua;
		//cout<<"\n :"<<ar;
		cout<<"\n Phone Number:"<<num;
		cout<<"\n Occupation:"<<occ;
	}
	void dis()
	{
	    customer b;
		f.open("customer.txt",ios::in|ios::binary);
	/*	while(!f.eof())
		{
		   if((f.read((char*)&b,sizeof(b))!=NULL))
		   {
	       b.view();
	       }
		}*/
		f.read((char*) &b,sizeof(class customer));
		while(!f.eof())
		{
		
		//cout<<b.ar;
		b.view();
		f.read((char*) &b,sizeof(class customer));
		}
		f.close();	
	}
	void create1()
	{
		int wid;
      	f1.open("cid.txt",ios::in);
	  	f1>>wid;
	  	f1.close();
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
		cin>>qua;
	//	cin.getline(ar,30);
		cout<<"\n Enter the phone number:";
		cin>>num;
		cout<<"\n Occupation:";
		cin>>occ;
	}
	void edit()
	{
		customer c;
		int eid;
			f.open("customer.txt",ios::in|ios::binary);
			f1.open("temp1.txt",ios::out|ios::binary);
			cout<<"\n Enter the Worker id to be edited:";
		cin>>eid;
			while((f.read((char*)&c,sizeof(c)))!=NULL)
		{
			
				if(eid==c.id)
				{
		 			c.create1();
		         f1.write((char*)&c,sizeof(c));
	            }
	            else
	              f1.write((char*)&c,sizeof(c));
	   }
     	f.close();
		f1.close();
		f.open("temp1.txt",ios::in|ios::binary);
		f1.open("customer.txt",ios::out|ios::binary);
			while((f.read((char*)&c,sizeof(c)))!=NULL)
			{
			f1.write((char*)&c,sizeof(c));	
			}
			f.close();
			f1.close();
		}
}cus;

class clerk
{
public:
	int ch;
int cl()
{
	
	do
	{
		//system("cls");
		cout<<"\n\n\t\t\t\t\t 1.Workers Details \n\n\t\t\t\t\t 2.General Packages \n\n\t\t\t\t\t 3.Offers \n\n\t\t\t\t\t 4.Facilities \n\n\t\t\t\t\t 5.Customer\n\n\t\t\t\t\t6.Exit";
	    cin>>ch;
	    system("cls");
	    //getch();
	    switch(ch)
	    {
	    	/*case 1:o1.dis();
	    			break;
	    	case 2:o4.dis();
				//	cout<<"hiiiiiiiiii";
				//	getch();
	    			break;
	    	case 3:o3.dis();
	    			break;
	    	case 4:o2.dis();
	    			break;*/
	    	case 5:system("cls");
		  		{
		  				int ch1;
			    do
	  			{
	  		
		  		cout<<"\n\n\t\t\t\t\t 1.Add customer \n\n\t\t\t\t\t 2.View customer details \n\n\t\t\t\t\t 3.Edit customer profile \n\n\t\t\t\t\t 4.Exit";
//				cin.ignore();
				cin>>ch1;
				system("cls");
				//cin.ignore();
	  			switch(ch1)
	  			{
	  				case 1: cus.add1();
	  						//system("cls");
	  						break;
	  				case 2: cus.dis();
	  						//system("cls");
	  						break;
	  				/*case 3: cus.edit();
	  						//system("cls");
	  						break;*/
				  }
			   }while(ch1>=1 && ch1<=3 );
				break;
				}
	    	case 6:
				return 0;
		}
	}while(ch>=1 && ch<=4);
}
}oj1;

main()
{
	int ch;
	while(1)
	{
	cout<<"\n\n\t\t\t\t\t 1.Admin \n\n\t\t\t\t\t 2.Clerk \n\n\t\t\t\t\t 3.Exit";
	cin>>ch;
	switch(ch)
	{
		//case 1:oj.ad();
			//	break;
		case 2:oj1.cl();
				break;
		}	
	}
}

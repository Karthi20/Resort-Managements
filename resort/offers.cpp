#include<iostream>
#include<fstream>
using namespace std;
class offers
{
	public:
      char name[200];
	  int id;
	  char duration[200];
	  int cost;
	  char features[300];	
	  fstream f,f1,f2;
	void create()
	{
		 int wid;
      	f1.open("oid.txt",ios::in);
	  	f1>>wid;
	  	f1.close();
	  	id=wid;
	  	cout<<"\n Enter the offer Id:"<<id;
		cout<<"\n Enter the name of the offers:";
		getchar();
		cin.getline(name,200);
		//cin.ignore();
		cout<<"\n Enter the duration of the offers:";
		//getchar();
		cin.getline(duration,200);
		//cin.ignore();
		cout<<"\n Enter the features of the offers:";
		cin.getline(features,200);
	//	cin.ignore();
		cout<<"\n Enter the total cost:";
		cin>>cost;
		f.open("offers.txt",ios::app);
		f<<"\n"<<id;
		f<<"\t"<<name;
		f<<"\t"<<duration;
		f<<"\t"<<features;
		f<<"\t"<<cost;
		f.close();
				f1.open("oid.txt",ios::in);
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
		cin.getline(name,200);
		//cin.ignore();
		cout<<"\n Enter the duration of the offers:";
		//getchar();
		cin.getline(duration,200);
		//cin.ignore();
		cout<<"\n Enter the features of the offers:";
		cin.getline(features,200);
	//	cin.ignore();
		cout<<"\n Enter the total cost:";
		cin>>cost;	
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
		cin>>did;
		f.open("offers.txt",ios::in);
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

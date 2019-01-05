#include<iostream>
#include<fstream>
using namespace std;
struct off
{
	int id;
 char facc[200];
 off *next;
};

class facility
{
	public:
			int id;
		char name[200];
		fstream f,f1;
		void add()
		{
			//f.open("fac.txt",ios::app);
			int wid;
      		f1.open("fid.txt",ios::in);
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

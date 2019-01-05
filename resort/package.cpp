#include<iostream>
#include<fstream>
using namespace std;
class package
{
	public:
		int id;
		int days;
		int nights;
		//char room[300];
		int cost;
		//int id;
		char name[200];
		fstream f,f1;
   void add()
   {
   //	f.open("package.txt",ios::app);
   	    int wid;
      	f1.open("pid.txt",ios::in);
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
   	f<<"\n"<<id;
   	f<<"\t"<<name;
   	f<<"\t"<<days;
   	f<<"\t"<<nights;
   	f<<"\t"<<cost;
   	f.close();
   	 int i;
	  	f1.open("pid.txt",ios::in);
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



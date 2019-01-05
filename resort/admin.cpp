#include<iostream>
#include "facility.cpp"
#include "package.cpp"
#include "workeradmin.cpp"
#include "agent.cpp"
using namespace std;
class admin
{
 public:
		int ad()
		{
	 	int ch,ch1;
	 	while(1)
	 	{
	  		cout<<"\n\n\t\t\t\t\t 1.Workers Details \n\n\t\t\t\t\t 2.General Packages \n\n\t\t\t\t\t 3.Offers \n\n\t\t\t\t\t 4.Facilities\n\n\t\t\t\t\t5.Agent \n\n\t\t\t\t\t 6.Exit";
	  		cin>>ch;
	  	
	  switch(ch)
	   {
	  	case 1: system("cls");
		  		{
			    do
	  			{
	  			
		  		cout<<"\n\n\t\t\t\t\t 1.Add worker \n\n\t\t\t\t\t 2.View worker details \n\n\t\t\t\t\t 3.Edit worker profile \n\n\t\t\t\t\t 4.block worker";
//				cin.ignore();
				cin>>ch1;
				system("cls");
				//cin.ignore();
	  			switch(ch1)
	  			{
	  				case 1:obj1.create();
	  						//system("cls");
	  						break;
	  				case 2:obj1.view();
	  						//system("cls");
	  						break;
	  				case 3: obj1.edit();
	  						//system("cls");
	  						break;
	  				case 4:obj1.block();
	  						//system("cls");
	  						break;
				  }

			   }while(ch1>=1 && ch1<=4 );
				break;
				}
		case 2:  system("cls");
				do
		        {
				//system("cls");
		        cout<<"\n\n\t\t\t\t\t 1.Add Package \n\n\t\t\t\t\t 2.Edit Package \n\n\t\t\t\t\t 3.View Package \n\n\t\t\t\t\t 4.Delete Package";
			   cin>>ch1;
			  system("cls");
			   switch(ch1)
			   {
			   	case 1:obj.add();
			   			//system("cls");
			   			break;
			   	case 2:obj.edit();
			   			//system("cls");
			   			break;
			   	case 3:obj.view();
			   			//system("cls");
			   			break;
			   	case 4:obj.del();
			   			//system("cls");
			   			break;
			   }
			   }while(ch1>=1 && ch1<=4);
			   break;
		case 3:  system("cls");
				do
				{
				//system("cls");
				cout<<"\n\n\t\t\t\t\t 1.Add offers   \n\n\t\t\t\t\t 2.Edit offers   \n\n\t\t\t\t\t 3.View offers \n\n\t\t\t\t\t 4.Delete offers";
				cin>>ch1;
				system("cls");
				switch(ch1)
				{
					case 1:ocreate();
						//	system("cls");
							break;
					case 2:oedit();
						//	system("cls");
							break;
					case 3:oview();
						//	system("cls");
							break;
					case 4:odel();
						//	system("cls");
							break;
				}
				}while(ch1>=1 && ch1<=4);
				break;
		case 4: system("cls");
				do
				{
				//system("cls");
				cout<<"\n\n\t\t\t\t\t 1.Add facility \n\n\t\t\t\t\t 2.Edit facility \n\n\t\t\t\t\t 3.View facility \n\n\t\t\t\t\t 4.delete facility";
				cin>>ch1;
				system("cls");
				switch(ch1)
				{
					case 1:obj3.add();
						//	system("cls");
							break;
					case 2:obj3.editt();
						//	system("cls");
							break;
					case 3: obj3.view();
						//	system("cls");
							break;
					case 4: obj3.del();
						//	system("cls");
							break;
				}
			    }while(ch1>=1 && ch1<=4);
			    break;
		case 5:system("cls");
				do
				{
				//system("cls");
				cout<<"\n\n\t\t\t\t\t 1.Add Agent \n\n\t\t\t\t\t 2.Edit Agent \n\n\t\t\t\t\t 3.View Agent \n\n\t\t\t\t\t 4.Exit";
				cin>>ch1;
				system("cls");
				switch(ch1)
				{
					case 1:ag1.create();
						//	system("cls");
							break;
					case 2:ag1.edit();
						//	system("cls");
							break;
					case 3: ag1.view();
						//	system("cls");
							break;
					case 4: cout<<"\n";
				}
			    }while(ch1>=1 && ch1<=3);
			    break;
		case 6:cout<<"\n";
				break;
				
			   
	  }
	 }	
}
};
class offers : public admin
{
	public:
      char name[200];
	  int oid;
	  char duration[200];
	  int cost;
	  char features[300];	
	  fstream f,f1;
	void ocreate()
	{
		 int wid;
      	f1.open("oid.txt",ios::in);
	  	f1>>wid;
	  	f1.close();
	  	oid=wid;
	  	cout<<"\n Enter the offer Id:"<<oid;
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
		f<<"\n"<<oid;
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
	void oview()
	{
		f.open("offers.txt",ios::in);
		while(!f.eof())
		{
		f>>oid;
		f>>name;
		f>>duration;
		f>>features;
		f>>cost;
			cout<<"\n Offer Name:"<<name;
			cout<<"\n Offer Id:"<<oid;
			cout<<"\n Offer Duration:"<<duration;
			cout<<"\n Offer features:"<<features;
			cout<<"\n Offer cost:"<<cost;
     	}
     	f.close();
	}
	void oedit()
	{
		int eid;
		cout<<"\n Enter the offer Id to be edited:";
		cin>>eid;
		f.open("offers.txt",ios::in);
		f1.open("temp1.txt",ios::out);
		while(!f.eof())
		{	
		f>>oid;
		f>>name;
		f>>duration;
		f>>features;
		f>>cost;
		if(eid==oid)
		{
		cout<<"\n Enter the offer Id:"<<oid;
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
		f1<<"\n"<<oid;
		f1<<"\t"<<name;
		f1<<"\t"<<duration;
		f1<<"\t"<<features;
		f1<<"\t"<<cost;	
		     
		}
			else
	     	{
	     			f1<<"\n"<<oid;
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
			 f1>>oid;
		f1>>name;
		f1>>duration;
		f1>>features;
		f1>>cost;
		f<<"\n"<<oid;
		f<<"\t"<<name;
		f<<"\t"<<duration;
		f<<"\t"<<features;
		f<<"\t"<<cost;
			}
			f.close();
			f1.close();	
	}
	void odel()
	{
		int did;
		cout<<"\n Enter the offer Id to be edited:";
		cin>>did;
		f.open("offers.txt",ios::in);
		f1.open("temp1.txt",ios::out);	
	while(!f.eof())
		{
		f>>oid;
		f>>name;
		f>>duration;
		f>>features;
		f>>cost;
			if(did!=oid)
				{
				f1<<"\n"<<oid;
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
		f1>>oid;
		f1>>name;
		f1>>duration;
		f1>>features;
		f1>>cost;
		f<<"\n"<<oid;
			f<<"\t"<<name;
			f<<"\t"<<duration;
			f<<"\t"<<features;
			f<<"\t"<<cost;
			
		}
		f.close();
		f1.close();
	}
}obj2;

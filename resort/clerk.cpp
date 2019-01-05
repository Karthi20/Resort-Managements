#include<istream>
#include<conio.h>
#include "worker1.cpp"
#include "facility1.cpp"
#include "offers1.cpp"
#include "package1.cpp"
#include "customer.cpp"
#include<fstream>
using namespace std;
int choice,n;
int wid;
struct anode
{
int aid;
	int amm,add,ayy;
	int aage;
	char aname[10];
	char agender[10];
    char aqua[10];
    char anum[10];
    char aocc[10];
anode *anext;
};
	anode *anew1=NULL,*aend=anew1;
 anode *ahead;
 anode *atemp;
 fstream f,f1,f2;
class clerk
{
public:
	int ch;
	int agentid;
int cl()
{
	
	do
	{
		//system("cls");
		cout<<"\n\n\t\t\t\t\t 1.Workers Details \n\n\t\t\t\t\t 2.General Packages \n\n\t\t\t\t\t 3.Offers \n\n\t\t\t\t\t 4.Facilities \n\n\t\t\t\t\t5.Customer\n\n\t\t\t\t\t6.Booking\n\n\t\t\t\t\t7.Exit";
	    cin>>ch;
	    system("cls");
	    //getch();
	    switch(ch)
	    {
	    	case 1:o1.view();
	    			break;
	    	case 2:o4.view();
				//	cout<<"hiiiiiiiiii";
				//	getch();
	    			break;
	    	case 3:o3.view();
	    			break;
	    	case 4:o2.view();
	    			break;
	    	case 5:cout<<"1.AGENT\n2.CUSTOMER";
	    	cin>>choice;
	    	switch(choice)
	    	{
	    		case 1:
	    		f2.open("agentbok.txt",ios::app);
				cout<<"Enter the Agent ID:";
				cin>>agentid;
				cout<<"\nENTER THE NUMBER OF MEMEBERS";
	    		cin>>n;
	    		f<<"\n"<<agentid;
	    		f<<"\t"<<n;
	    		f2.close();
	    		 ahead=NULL;
f.open("customer.txt",ios::app);

				for(int i=-1;i<n;i++)
				{anew1=new anode;
				
        if(ahead==NULL)
           ahead=anew1;
        else{
		
      	f1.open("cid.txt",ios::in);
	  	f1>>wid;
	  	f1.close();
	  	anew1->aid=wid;
		
            	cout<<"\n Customer ID:"<<anew1->aid;
						cout<<"\n Enter the name:";
						cin>>anew1->aname;
						cout<<"\n Enter the DOB:";
					cout<<"\nenter the date";
					cin>>anew1->add;
					cout<<"\nenter the month";
					cin>>anew1->amm;
					cout<<"\nenter the year";
					cin>>anew1->ayy;
					cout<<"\n Enter the age:";
					cin>>anew1->aage;
					cout<<"\n Enter the gender:";
					cin>>anew1->agender;
					cout<<"\n Enter the address:";
					cin>>anew1->aqua;
		//cout<<add;ame;
					cout<<"\n Enter the phone number:";
					cin>>anew1->anum;
					cout<<"\n Occupation:";
					cin>>anew1->aocc;
		 			f<<"\n"<<anew1->aid;
					f<<"\t"<<anew1->aname;
					f<<"\t"<<anew1->add;
					f<<"\t"<<anew1->amm;
					f<<"\t"<<anew1->ayy;
					f<<"\t"<<anew1->aage;
					f<<"\t"<<anew1->agender;
					f<<"\t"<<anew1->aqua;
					f<<"\t"<<anew1->anum;
					f<<"\t"<<anew1->aocc;
	            
		   aend->anext=anew1;
        }aend=anew1;
        aend->anext=NULL;
		f1.open("cid.txt",ios::in);
	  	f1>>wid;
	  	f1.close();
		f1.open("cid.txt",ios::out);
		wid+=1;
		f1<<wid;
		f1.close();
				}
				f.close();

			system("cls");
		break;
		  		case 2:
		  				int ch1;
			    do
	  			{
	  		
		  		cout<<"\n\n\t\t\t\t\t 1.Add customer \n\n\t\t\t\t\t 2.View customer details \n\n\t\t\t\t\t 3.Edit customer profile\n\n\t\t\t\t\t 5.Exit";
//				cin.ignore();
				cin>>ch1;
				system("cls");
				//cin.ignore();
	  			switch(ch1)
	  			{
	  				case 1: cus.create();
	  						//system("cls");
	  						break;
	  				case 2: cus.view();
	  						//system("cls");
	  						break;
	  				case 3: cus.edit();
	  						//system("cls");
	  						break;
				  }
			   }while(ch1>=1 && ch1<=3 );
				break;
			}break;
				case 6:
					cus.book();
					break;
	    	case 7:
	    		
				return 0;
		}}while(ch>=1 && ch<=6);
}}oj1;

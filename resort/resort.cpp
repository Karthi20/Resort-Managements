#include<iostream>
#include<fstream>
#include "data.cpp"
#include "agent.cpp"
#include "customer.cpp"
#include<limits>
using namespace std;
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
class person
{
	public:
		int ch,choice,n,ch1;
		int wid;
	int agentid;
	fstream f,f1,f2;			
};
class admin:public person
{
 public:
		int ad()
		{
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
	  			
		  		cout<<"\n\n\t\t\t\t\t 1.Add worker \n\n\t\t\t\t\t 2.View worker details \n\n\t\t\t\t\t 3.Edit worker profile \n\n\t\t\t\t\t 4.block worker\n\n\t\t\t\t\t5.Unblock Worker \n\n\t\t\t\t\t6.Assign Work";
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
	  				case 5:obj1.block(1);
	  						break;
	  				//case 6:obj1.work();
	  					//	break;
				  }

			   }while(ch1>=1 && ch1<=5);
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
					case 1:obj2.create();
						//	system("cls");
							break;
					case 2:obj2.edit();
						//	system("cls");
							break;
					case 3:obj2.view();
						//	system("cls");
							break;
					case 4:obj2.del();
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
}ad1;
class clerk:public person
{
public:
int cl()
{
	do
	{
		//system("cls");
		cout<<"\n\n\t\t\t\t\t 1.Workers Details \n\n\t\t\t\t\t 2.General Packages \n\n\t\t\t\t\t 3.Offers \n\n\t\t\t\t\t 4.Facilities \n\n\t\t\t\t\t5.Customer\n\n\t\t\t\t\t6.Booking\n\n\t\t\t\t\t7.BILLING\n\n\t\t\t\t\t8.EXIT";
	    cin>>ch;
	    system("cls");
	    //getch();
	    switch(ch)
	    {
	    	case 1:obj1.view();
	    			break;
	    	case 2:obj.view();
				//	cout<<"hiiiiiiiiii";
				//	getch();
	    			break;
	    	case 3:obj2.view();
	    			break;
	    	case 4:obj3.view();
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
	    	case 7:cus.billing();
	    	break;
	    		case 8:
				return 0;
		}}while(ch>=1 && ch<=7);
}}cl1;
main()
{
		int ch4;
	while(1)
	{
	cout<<"\n\n\t\t\t\t\t 1.Admin \n\n\t\t\t\t\t 2.Clerk \n\n\t\t\t\t\t 3.Exit";
	cin>>ch4;
	switch(ch4)
	{
		case 1:ad1.ad();
				break;
		case 2:cl1.cl();
				break;
		case 3: return 1;
		}	
	}
}

#include<iostream>
#include<fstream>
using namespace std;
class offers1
{
	public:
      char name[200];
	  int oid;
	  char duration[200];
	  int cost;
	  char features[300];
	  fstream f;
	  	void view()
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
}o3;

#include<iostream>
#include<fstream>
using namespace std;
class facility1
{
	public:
		int fid;
		char fac[200];
		fstream f;
	  	void view()
		{
			f.open("fac.txt",ios::in);
			while(!f.eof())
			{
				f>>fid;
				f>>fac;
				cout<<"\n Id:"<<fid;
				cout<<"\n Facility name:"<<fac;
			}
			f.close();
		}
}o2;

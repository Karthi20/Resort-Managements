#include<iostream>
#include<limits>
#include<fstream>
using namespace std;
class dpackage
{
	public:
		int id;
		int days;
		int nights;
		//char room[300];
		int cost;
		char name[200];
		fstream f;
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
}pack1;

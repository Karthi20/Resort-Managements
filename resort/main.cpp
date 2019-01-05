#include<iostream>
#include "admin.cpp"
#include "clerk.cpp"
using namespace std;
main()
{
	int ch;
	while(1)
	{
	cout<<"\n\n\t\t\t\t\t 1.Admin \n\n\t\t\t\t\t 2.Clerk \n\n\t\t\t\t\t 3.Exit";
	cin>>ch;
	switch(ch)
	{
		case 1:obj2.ad();
				break;
		case 2:oj1.cl();
				break;
		case 3: return 1;
		}	
	}
}

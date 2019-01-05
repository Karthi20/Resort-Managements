#include <iostream>
#include <conio.h>
#include<fstream>
using namespace std;
struct node
{
int data;
node *next;
};
node *head;
 linklist()
 {head=NULL;}
 void create();
 void display();
fstream f;
void load()
{
  node *newl=NULL,*end=newl;
  int info;
  

			f.open("rooms.txt",ios::in);
  while(!f.eof())
  {f>>info;
			cout<<"\n"<<info;
        newl=new node;
        newl->data=info;
        if(head==NULL)
           head=newl;
        else
           end->next=newl;
        end=newl;
        end->next=NULL;
     }
  f.close();  }int str=0,room[10]={0,0,0,0,0,0,0,0,0,0};
int select(int a)
{int ch1;
 node *temp=head;
  {
    while(temp!=NULL)
    {
       cout<<temp->data;
       if(temp->data/100==a)
       {room[str]=temp->data;
       str++;
	   temp->data=0;
	break;}
        if(temp->next!=NULL)
          cout<<"==>";
        temp=temp->next;
    }
    
}

f.open("rooms.txt",ios::out);
temp=head;
 while(temp!=NULL)
    {
       cout<<temp->data;
	   if(temp->data!=0){
f<<"\t";	   
	   f<<temp->data;

}
	   if(temp->next!=NULL)
          cout<<"==>";
        temp=temp->next;
}

f.close();}
int main()
{
int ch,n;

load();

cout<<"\n1.AC\n2.NON-AC\n3.MASTER \n4.MINI \n5.JACUZI";
cout<<"ENTER YOUR CHOICE";
cin>>ch;
cout<"ENTER THE NUMBER OF ROOMS";
cin>>n;
for(int j=0;j<n;j++)
select(ch);
for(int i=0;i<n-1;i++)
cout<<"\n"<<"\n"<<room[i];
cout<<"\n\n\n\n"<<str<<"\n\n\n\n"<<n-1;
if(str==n-1) 
{
//cout<<"ROOMS ARE NOT AVAILLABLE";
f.open("rooms.txt",ios::app);
//cout<<"ROOMS ARE NOT AVAILLABLE";
for(int j=0;j<str;j++)
{
f<<"\t";
f<<room[str];
//cout<<"ROOMS ARE NOT AVAILLABLE";
}
}
}


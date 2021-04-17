#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

class hotel
{
int room_no;
char name[30];
char address[50];
char phone[10];
public:
void main_menu();
void add();//to book a room
void display();//to display customer record
void rooms();//to display alloted rooms
void edit();//to edit custmer record;
int check(int);//tocheck roomstatus
void modify(int);//to modify the record
void delete_rec(int);//to delete the record
};
void hotel::main_menu()
{
int choice;
while(choice!=5)
{
//clrscr();
cout<<"\n\t\t\t\t************";
cout<<"\n\t\t\t\t*MAIN MENU*";
cout<<"\n\t\t\t\t************";
cout<<"\n\n\n\t\t\t1.Book a Room";
cout<<"\n\t\t\t2.customer record";
cout<<"\n\t\t\t3.Rooms Alloted";
cout<<"\n\t\t\t4.Edit record";
cout<<"\n\t\t\t5.Exit";
cout<<"\n\n\t\t\tEnter your choice:";
cin>>choice;
switch(choice)
{
case 1:add();break;
case 2:display();break;
case 3:rooms();break;
case 4:edit();break;
case 5:break;
default:
{
cout<<"\n\n\t\t\tWrong choice!!!";
cout<<"\n\t\t\tpress any key to continue!!";
//getch();
}
}
}
}
void hotel::add()
{
//clrscr();
int r,flag;
ofstream fout("Record.dat",ios::trunc|ios::app);
cout<<"\nEnter customer details";
cout<<"\n**********************";
cout<<"\n\nRoom no:";
cin>>r;
flag=check(r);
if(flag)
cout<<"\nSorry..!!Room is already booked";
else
{
room_no=r;
cout<<"Name:";
cin.getline(name,30);
cout<<"Address:";
cin.getline(address,50);
cout<<"Phone number:";
cin.getline(phone,10);
fout.write((char*)this,sizeof(hotel));
cout<<"\nRoom is booked!!!";
}
cout<<"\nPress any key to continue!!";
//getch();
fout.close();
}
void hotel::display()
{
//clrscr();
int r,flag;
ifstream fin("Record.dat",ios::in);
cout<<"\nEnter room no:";
cin>>r;
while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{
//clrscr();
cout<<"\nCustomer Details";
cout<<"\n***************";
cout<<"\n\nRoom no:"<<room_no;
cout<<"\nName:"<<name;
cout<<"\nAddress:"<<address;
cout<<"\nPhone no:"<<phone;
flag=1;
break;
//getch();
}
}
if(flag==0)
{
cout<<"\nSorry Room no . not found or vacant!!";
cout<<"\n\npress any key to continue!!";
//getch();
fin.close();
}
//getch();
}
void hotel::rooms()
{
//clrscr();
ifstream fin("Record.dat",ios::in);
cout<<"\n\t\t\tList of rooms allotted";
cout<<"\n\t\t\t**********************";
cout<<"\n\nRoom no.\tName\t\tAddress\t\tPhone no.\n";
while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
cout<<"\n\n"<<room_no<<"\t\t"<<name;
cout<<"t\t"<<address<<"\t\t"<<phone;
}
cout<<"\n\n\n\t\t\tpress any key to continue!!";
//getch();
fin.close();
}
void hotel::edit()
{
//clrscr();
int choice,r;
cout<<"\nEDIT Menu";
cout<<"\n*********";
cout<<"\n\n1.Modify customer record";
cout<<"\n2.Delete customer record";
cout<<"\nEnter your choice:";
cin>>choice;
//clrscr();
cout<<"\nEnter room no:";
cin>>r;
switch(choice)
{
case 1:modify(r);
break;
case 2:delete_rec(r);
break;
default:
cout<<"\nWrong choice!!";
}
cout<<"\npress any key to continue!!!";
//getch();
}
int hotel::check(int r)
{
int flag=0;
ifstream fin("Record.dat",ios::in);
while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{
flag=1;
break;
}
}
fin.close();
return (flag);
}
void hotel::modify(int r)
{
long pos,flag=0;
fstream file("Record.dat",ios::in|ios::out|ios::binary);
while(!file.eof())
{
pos=file.tellg();
file.read((char*)this,sizeof(hotel));
if(room_no==r)
{
cout<<"\nEnter New details";
cout<<"\n*****************";
cout<<"\nName:";
cin.getline(name,30);
cout<<"Address";
cin.getline(address,50);
cout<<"Phone number";
cin.getline(phone,10);
file.seekg(pos);
file.write((char*)this,sizeof(hotel));
cout<<"\nRecord is modified!!";
flag=1;
break;
}
}
if(flag==0)
cout<<"\nSorry Room no.not found or vacant!!";
file.close();
}
void hotel::delete_rec(int r)
{
int flag=0;
char ch;
ifstream fin("Record.dat",ios::in);
ofstream fout("temp.dat",ios::out);
while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{
cout<<"\nName:"<<name;
cout<<"\nAddress:"<<address;
cout<<"\nphone no:"<<phone;
cout<<"\n\nDo you want to delete the record(y/n):";
cin>>ch;
if(ch=='n')
fout.write((char*)this,sizeof(hotel));
flag=1;
}
else
fout.write((char*)this,sizeof(hotel));
}
fin.close();
fout.close();
if(flag==0)
cout<<"\nSorry room no.not found or vacant!!";
else
{
remove("Record.dat");
rename("temp.dat","Record.dat");
}
}
int main()
{
hotel h;
//textmode(C80);
//textbackground(WHITE);
//textcolor(RED);
//clrscr();
cout<<"\n\t\t\t***************************";
cout<<"\n\t\t\t*HOTEL RESERVATION PROJECT*";
cout<<"\n\t\t\t***************************";
sleep(2);
cout<<"\n\n\n\n\t\tMade by:";
sleep(2);
cout<<"\n\t\tDK";
sleep(2);
cout<<"\n\n\n\n\n\t\t\t\tpress any key to continue!!";
h.main_menu();
return 0;
//getch();
}
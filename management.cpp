#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>

class hotel
{
    int room_no;
    char name[30];
    char address[50];
    char phone[10];

    public:
   
     void main_menu();    
    //to dispay the main menu
   
     void add();        
    //to book a room
   
     void display();    
    //to display the customer record
   
     void rooms();    
    //to display alloted rooms
   
     void edit();    
    //to edit the customer record
   
     int check(int);    
    //to check room status
   
     void modify(int);    
	 //to modify the record
   
     void delete_rec(int);    	
    //to delete the record
};

void hotel::main_menu()
{
    int choice;

	 while(choice!=5)
	 {
	clrscr();
	for(int p=0; p<=50; p++)
	{
	cout<<"-";
	}
	cout<<"\n\t\t\t\t* MAIN MENU *\n\t\t\t\t";

	 for(p=0; p<=50;p++)
	{
	cout<<"-";
	}
	
    cout<<"\n1.Book A Room";
	cout<<"\n2.Customer Record";
	cout<<"\n3.Rooms Allotted";
	cout<<"\n4.Edit Record";
	cout<<"\n5.Exit";
	cout<<"\nEnter Your Choice: ";
	cin>>choice;

	switch(choice)
	{
	    case 1: add();
		    break;
	    case 2: display();
		    break;
	    case 3: rooms();
		    break;
	    case 4: edit();
		    break;
	    case 5: break;
	    default:
		    {
			cout<<"\nWrong choice!!!";
			cout<<"\nPress any key to continue!!";
			getch();
		    }
	}
   }
}

void hotel::add()
{
    clrscr();
    int r,flag;
    ofstream fout("Record.dat",ios::app);
    for(int a=0; a<=80; a++)
    {
    cout<<"-";
    }

    cout<<"\n* Enter Customer Detalis *";
	 for(a=0; a<=80; a++)
    {
    cout<<"-";
    }

    cout<<"\n\n Room no: ";
    cin>>r;
    flag=check(r);

    if(flag)
	cout<<"\n Sorry..!!!Room is already booked";
    else
    {
	room_no=r;
	cout<<" Name: ";
	gets(name);
	cout<<" Address: ";
	gets(address);
	cout<<" Phone No: ";
	gets(phone);
	fout.write((char*)this,sizeof(hotel));
	cout<<"\n Room is booked!!!";
    }

    cout<<"\n Press any key to continue!!";
    getch();
    fout.close();
}

void hotel::display()
{
    clrscr();
    ifstream fin("Record.dat",ios::in);
    int r,flag;
    cout<<"\n Enter room no: ";
    cin>>r;

    while(!fin.eof())
    {
	fin.read((char*)this,sizeof(hotel));
	if(room_no==r)
	{
	    clrscr();
    for(int a=0; a<=80; a++)
    {
    cout<<"-";
    }

	    cout<<"\n* Customer Details *";
		 for(a=0; a<=80; a++)
    {
    cout<<"-";
    }

	    cout<<"\n\n Room no: "<<room_no;
	    cout<<"\n Name: "<<name;
	    cout<<"\n Address: "<<address;
	    cout<<"\n Phone no: "<<phone;
	    flag=1;
	    break;
	}
    }

    if(flag==0)
	cout<<"\n Sorry Room no. not found or vacant!!";

    cout<<"\n\n Press any key to continue!!";
    getch();
    fin.close();
}

void hotel::rooms()
{
    clrscr();
    ifstream fin("Record.dat",ios::in);
for(int a=0; a<=80; a++)
    {
    cout<<"-";
    }

    cout<<"\n\t\t\t* List Of Rooms Allotted *";
	 for(a=0; a<=80; a++)
    {
    cout<<"-";
    }

    cout<<"\n\n Room No.\tName\t\tAddress\t\tPhone No.\n";

    while(!fin.eof())
    {
	fin.read((char*)this,sizeof(hotel));
	cout<<"\n\n "<<room_no<<"\t\t"<<name;
	cout<<"\t\t"<<address<<"\t\t"<<phone;
    }

    cout<<"\n\n\n\t\t\tPress any key to continue!!";
    getch();
    fin.close();
}

void hotel::edit()
{
    clrscr();
    int choice,r;
    for(int a=0; a<=80; a++)
    {
    cout<<"-";
    }


    cout<<"\n * EDIT MENU *";
	 for(a=0; a<=80; a++)
    {
    cout<<"-";
    }

    cout<<"\n\n 1.Modify Customer Record";
    cout<<"\n 2.Delete Customer Record";

    cout<<"\n Enter your choice: ";
    cin>>choice;

    clrscr();
    cout<<"\n Enter room no: ";
    cin>>r;

    switch(choice)
    {
	case 1: modify(r);
		break;
	case 2: delete_rec(r);
		break;
	default: cout<<"\n Wrong Choice!!";
    }

    cout<<"\n Press any key to continue!!!";
    getch();
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
    return(flag);
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
	    cout<<"\n Enter New Details";
	    cout<<"\n ***";
	    cout<<"\n Name: ";
	    gets(name);
	    cout<<" Address: ";
	    gets(address);
	    cout<<" Phone no: ";
	    gets(phone);

	    file.seekg(pos);
	    file.write((char*)this,sizeof(hotel));
	    cout<<"\n Record is modified!!";
	    flag=1;
	    break;
	}
    }

    if(flag==0)
	cout<<"\n Sorry Room no. not found or vacant!!";

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
	    cout<<"\n Name: "<<name;
	    cout<<"\n Address: "<<address;
	    cout<<"\n Phone No: "<<phone;
	    cout<<"\n\n Do you want to delete this record(y/n): ";
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
	cout<<"\n Sorry room no. not found or vacant!!";
    else
    {
	remove("Record.dat");
	rename("temp.dat","Record.dat");
    }
}

void main()
{
    hotel h;

    clrscr();
    for(int a=0; a<=80; a++)
    {
    cout<<"-";
    }
    cout<<"\n\t\t\t* HOTEL MANAGEMENT PROJECT *";
	  for(a=0; a<=80; a++)
    {
    cout<<"-";
    }
    cout<<"\nPress any key to continue!!";
    getch();
    h.main_menu();
}

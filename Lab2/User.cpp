#include <iostream>
#include "User.h"
using namespace std;

void 
Create(User& user)
{

 


	cout<<"Please enter first name:"<<endl;
	cin>>user.fname;
	cout<<"Please enter last name:"<<endl;
	cin>>user.lname;
	cout<<"Please enter age:"<<endl;
	cin>> user.age;
	cin.ignore(1000,'\n');
}

void 
Update(User& user)
{

	cout<<"Please enter which attribute to update (First, Last, Age):"<<endl;
	string option;
	string Age = "Age", First = "First" , Last = "Last";
	//cout<<"what you want to update"<<endl;
	//cout<<"Please enter which attribute to update (First, Last, Age): "<<endl;
	cin>> option;

		if(option == First)
			{
				cout<<"Please enter the new value:"<<endl;
				cin>>user.fname;
			}

		if(option == Last)
		{
			cout<<"Please enter the new value:"<<endl;
			cin>>user.lname;
		}
		
		if(option == Age)
		{
			cout<<"Please enter the new value:"<<endl;
			cin>>user.age;
			cin.ignore(1000,'\n');

		}
		

}

void 
View(User& user)
{
	cout<<"First name:"<<user.fname<<endl;
	cout<<"Last name:"<< user.lname<<endl;
	cout<<"Age:"<<user.age<<endl;
	cout<<"Favorite Movies"<<endl;
	cout<<endl;
	
	int i;
	for( i = 0 ; i< 5 ; i++)
	{
		cout<<user.num[i]<<endl;
	}
}

void Favorites(User& user)
{
		cin.ignore(1000,'\n');

   	cout<<"Please input your new 5 Favorite Movies"<<endl;
	int i;
	for(i = 0; i < 5 ; i++)
	{
		//cin>>user.num[i];
		//cin.ignore(1000,'\n');
		getline (cin, user.num[i]);
	}
}

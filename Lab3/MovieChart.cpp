#include <iostream>
#include "User.h"
#include "MovieChart.h"
using namespace std;



MovieChart::MovieChart()
{
	current_user = NULL;
	num_users = 0;
}




/// you just create a user and you have no way to view the movies until you get to login 

void 
MovieChart::Create()
{
	std::string new_username, new_password;
	
	User* new_user = &users[num_users];
	num_users++;
	
	cout<<"Please enter first name: ";
	cin >> new_user->fname;
	cout<<"Please enter last name: ";
	cin >> new_user->lname;
	cout<<"Please enter age: ";
	cin >> new_user->age;
	cout<<"Please enter username: ";
	cin >> new_username;
	cout<<"Please enter password: ";
	cin >> new_password;
	cin.ignore(1000,'\n');
	
	new_user->setUsername(new_username);
	new_user->setPassword(new_password);
	
}




bool MovieChart::login()
{

	
	std::string login_username;
	std::string login_password;
	
	std::cout<<"Please enter your username: ";
	cin >> login_username;
	

	std::cout<<"Please enter your password: ";
	cin >> login_password;
	
	

	
	///go through all the users, check if `user` and password match
	/// any of them, and if they do, I will set the `current_user` to the
	/// 


	for (int i = 0; i < num_users; ++i)
	{
		User* useri = &users[i];
		
		if (useri->getUsername() == login_username && useri->authenticate(login_password))
		{
			
			current_user = useri;
			return true;
		}
	}
	
	return false;
}

void MovieChart::logout()
{
	current_user = NULL;
	cin.ignore(1000,'\n');

}



void MovieChart::Update()
{
		if (current_user == NULL)
		{
				std::cerr << "Please login before continuing." << std::endl;
				return;
		}
		
		
		cin.ignore(1000,'\n');
		string option;
		cout<<"Please enter which attribute to update (Password, Favorites): ";
		cin>>option;

		if(option == "Password")
		{
				cin.ignore(1000,'\n');
				std::string new_string;
				cout<<"Please enter the new password:"<<endl;
				cin>>new_string;
				current_user->setPassword(new_string);
		}

		if(option == "Favorites")
		{
			cin.ignore(1000,'\n');
			cout<<"Please input your new 5 Favorite Movies "<<endl;
			for (int i = 0; i < 5; ++i)
			{
					std::string new_fav;
					getline(cin,new_fav);
					current_user->movieList()[i] = new_fav;
			}
		}
		
}

void MovieChart::View()
{
	if (current_user == NULL)
	{
			std::cerr << "Please login before continuing." << std::endl;
			return;
	}
	cout<<"First name:"<<current_user->fname<<endl;
	cout<<"Last name:"<< current_user->lname<<endl;
	cout<<"Age:"<<current_user->age<<endl;
	cout<<"Username:"<<current_user->getUsername()<<endl;
	cout<<"Favorite Movies"<<endl;
	cout<<"\n";
	int i;
	for( i = 0 ; i< 5 ; i++)
	{
		cout<<current_user->movieList()[i]<<endl;
	}
}
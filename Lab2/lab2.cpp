#include <iostream>
#include "User.h"
using namespace std;


int main()
{
	User user;
	while(true)
	{

	string option;
	cout<<"Please enter a command (Create, Update, View, Favorites, or Quit):"<<endl;
	cin>> option;


			if(option == "Create")
			{
			    Create(user);  //// passing object to the funcion
			}

			else if(option == "Update")
			{
			    Update(user);
			}

			else if(option == "View")
			{
				View(user);   //// passing object to the funcion
			   // setUserName(User &user, string f, string l);
			}
			else if(option == "Favorites")
			{
			 	Favorites(user);   //// passing object to the funcion
			}

			else if(option == "Quit")
			{
				cout<<"You Exit from the Program "<<endl;
				break;			    
			}
			else if(option != "Create" || option != "Update" || option != "View" || option != "Favorites" || option != "Quit")
				cout<<"INVALID COMMAND"<<endl;			    


	}

	return 0;
}
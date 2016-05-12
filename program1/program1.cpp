
#include <iostream>
#include "User.h"
#include "MovieChart.h"
using namespace std;

int main()
{
	string option;
	MovieChart x;

	while(1)
	{
		cout<<"Please enter a command (Create, Update, View, Login, Logout, Close, List, or Quit):"<<endl;
		cin >> option;
		cin.ignore(1000,'\n');
		cout<<endl;

		if(option == "Create")
		{
				x.Create();

		}

		else if(option == "Login")
		{
			if (!x.login())
				std::cout << "Invalid username/password combination" << std::endl;

		}

		else if(option == "Update")
		{
				x.Update();

		}

		else if (option == "View")
		{
				x.View();
		}

		else if (option == "Logout")
		{
				x.logout();
		}

		else if (option == "Close")
		{
				x.Close();
		}
		else if (option == "List")
		{
				x.List();
		}

		else if(option == "Quit")
		{
			break;
		} 
		else 
		{
			std::cout << "INVALID COMMAND" << std::endl;
		}

		//movieList()

	}

	return 0;
}

#include <iostream>
#include "User.h"
#include "MovieChart.h"
using namespace std;


int main()
{
	string option;
	MovieChart x;
	//User user;

	
	while(1)
	{
		cout<<"Please enter a command (Create, Update, View, Login, Logout, or Quit):"<<endl;
		cin >> option;

		if(option == "Create")
		{
				x.Create();
				
		}

		else if(option == "Login")
		{
			x.login();

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
		
		else if(option == "Quit")
		{
			break;
		} else {
			std::cerr << "No such option: " << option << std::endl;
		}

		//movieList()

	}
	
	return 0;
}
#include <iostream>
#include <fstream>
#include "User.h"
#include "MovieChart.h"
using namespace std;



string getnextsignificantline(ifstream& infile)
{
	while (infile)
	{
		string line;
		getline(infile, line);
		if (line.size() == 0)
			continue;
		return line;
	}
	return "";
}

MovieChart::MovieChart()
{
	current_user = NULL;
	num_users = 0;

	ifstream infile("users.txt");

	if (!infile)
	{
		std::cerr << "Error opening users.txt for reading" << std::endl;
		//exit;
	}

	while (infile)
	{

		std::string username = getnextsignificantline(infile);
		std::string first_name = getnextsignificantline(infile);
		std::string last_name = getnextsignificantline(infile);

		int age;
		infile >> age;


		std::string password = getnextsignificantline(infile);

		// std::cerr << __FILE__ << ":" << __LINE__ << std::endl;
		// std::cerr << "first_name: " << first_name << std::endl;
		// std::cerr << "username: " << username << std::endl;
		// std::cerr << "password: " << password << std::endl;

		User user(first_name, last_name, age, username, password);

		std::string movie;

		///read as many movies as we can until the end of the file or until
		/// a blank line is encountered
		while (infile)
		{
			std::getline(infile, movie);

			if (movie.size() == 0)
				break;

			user.addMovie(movie);
		}
		///must have been an extra empty line.
		if (username.size() == 0)
			break;

		users.CreateLast(user);
	}
}

MovieChart::~MovieChart()
{
	std::ofstream outfile("users.txt");

	if (!outfile) {
		std::cerr << "Error opening users.txt for reading" << std::endl;
		//exit;
	}


	users.ResetCurrent();

	while (users.CurrentIsValid())
	{
		User& user = users.ReadCurrent();

		outfile << user.username << std::endl;
		outfile << user.fname << std::endl;
		outfile << user.lname << std::endl;
		outfile << user.age << std::endl;
		outfile << user.password << std::endl;

		LinkedList<std::string> movies = user.movieList();

		movies.ResetCurrent();

		while (movies.CurrentIsValid())
		{

			outfile << movies.ReadCurrent() << std::endl;

			movies.MoveCurrentNext();
		}

		///one extra line at the end of each user in the file
		outfile << std::endl;

		users.MoveCurrentNext();
	}
}


/// you just create a user and you have no way to view the movies until you get to login

void
MovieChart::Create()
{
	std::string new_username, new_password;


	User new_user;

	cout<<"Please enter first name: ";
	cin >> new_user.fname;
	cout << endl;
	cout<<"Please enter last name: ";
	cin >> new_user.lname;
	cout << endl;
	cout<<"Please enter age: ";
	cin >> new_user.age;
	cout << endl;
	cout<<"Please enter username: ";
	cin >> new_username;
	cout << endl;
	cout<<"Please enter password: ";
	cin >> new_password;
	cout << endl;
	cin.ignore(1000,'\n');

	new_user.setUsername(new_username);
	new_user.setPassword(new_password);


	users.CreateLast(new_user);

	++num_users;
}




bool MovieChart::login()
{


	std::string login_username;
	std::string login_password;

	std::cout<<"Please enter your username: ";
	cin >> login_username;
	cout << endl;


	std::cout<<"Please enter your password: ";
	cin >> login_password;
	cout << endl;



	///go through all the users, check if `user` and password match
	/// any of them, and if they do, I will set the `current_user` to the
	///


	// for (int i = 0; i < num_users; ++i)
	users.ResetCurrent();

	while (users.CurrentIsValid())
	{
		User& useri = users.ReadCurrent();

		if (useri.getUsername() == login_username && useri.authenticate(login_password))
		{

			current_user = &useri;
			return true;
		}

		users.MoveCurrentNext();
	}

	return false;
}

void MovieChart::logout()
{
	current_user = NULL;
}



void MovieChart::Update()
{
		if (current_user == NULL)
		{
				std::cerr << "Please login before continuing." << std::endl;
				return;
		}


		string option;
		cout<<"Please enter what you would like to update (Add, Remove, Password)"  << std::endl;
		cin>>option;
		cin.ignore(1000,'\n');

		if(option == "Password")
		{
				std::string new_string;
				cout<<"Please enter the new password:"<<endl;
				cin>>new_string;
				cin.ignore(1000,'\n');
				current_user->setPassword(new_string);
		} else if (option == "Add")	{
				cout<<"Please input your Favorite Movies (Quit to exit)" << std::endl;

				std::string movie;
				while (true)
				{
						getline(cin,movie);
						if (movie == "Quit")
								break;

						current_user->addMovie(movie);
				}
		} else if (option == "Remove") {
				cout<<"Please input the titles of the movies to be removed (Quit to exit)" << std::endl;

				std::string movie;
				while (true)
				{
						getline(cin,movie);
						if (movie == "Quit")
								break;
						current_user->removeMovie(movie);
				}

		} else {
				cerr<<"Unknown command, try again, Add, Remove, Done"<<endl;
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

	LinkedList<std::string> movies = current_user->movieList();


	movies.ResetCurrent();
	while (movies.CurrentIsValid())
	{
		cout<< movies.ReadCurrent() <<endl;

		movies.MoveCurrentNext();
	}
}

void MovieChart::Close()
{
	if (current_user == NULL)
	{
			std::cerr << "Please login before continuing." << std::endl;
			return;
	}

	users.ResetCurrent();
	users.Find(*current_user);
	users.RemoveCurrent();
	current_user = NULL;
}


void MovieChart::List()
{
	users.ResetCurrent();

	while (users.CurrentIsValid())
	{

		User& user = users.ReadCurrent();

		cout << user.getUsername() << std::endl;

		LinkedList<string> movies = user.movieList();

		movies.ResetCurrent();

		while(movies.CurrentIsValid())
		{
			string movie = movies.ReadCurrent();

			cout << movie << std::endl;

			movies.MoveCurrentNext();
		}

		cout<<endl;

		users.MoveCurrentNext();
	}


}

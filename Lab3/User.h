#include <iostream>
#ifndef USER_H
#define USER_H


class User
{
	private:
		std::string* movies;
		std::string username;
		std::string password;
	
	public:		
		std::string fname;
		std::string lname;
		int age;
	
		User()
		{

			this->movies = new std::string[5];
		}
	
		User(std::string fname, std::string lname, int age, std::string username, std::string password)
		{
			this->movies = new std::string[5];
			this->fname = fname;
			this->lname = lname;
			this->age = age;
			this->username = username;
			this->password = password;
		}

		bool authenticate(std::string password)
		{
			return (password == this->password);
		}
		
		std::string getUsername()
		{
			return username;
		}
	
		void setUsername(std::string new_username)
		{
			this->username = new_username;
		}
	
		void setPassword(std::string new_password)
		{
			this->password = new_password;
		}
		
		std::string* movieList()
		{
			return movies;
		}

};



#endif
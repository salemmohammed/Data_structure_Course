#include <iostream>
#ifndef USER_H
#define USER_H

#include "LinkedList.h"

///forward declaration so we can say it is a friend of User
class MovieChart;

class User
{
	private:
		LinkedList<std::string> movies;
		std::string username;
		std::string password;

	public:
		std::string fname;
		std::string lname;
		int age;

		User()
		{


		}
		User(std::string fname, std::string lname, int age, std::string username, std::string password)
		{
			this->fname = fname;
			this->lname = lname;
			this->age = age;
			this->username = username;
			this->password = password;
		}

		User(const User& other)
		{
			this->movies = other.movies;
			this->username = other.username;
			this->password = other.password;
			this->fname = other.fname;
			this->lname = other.lname;
			this->age = other.age;
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

		LinkedList<std::string> movieList()
		{
			return movies;
		}

		void addMovie(const std::string& movie)
		{
			movies.CreateLast(movie);
		}
		void removeMovie(const std::string& movie)
		{
			movies.ResetCurrent();
			movies.Find(movie);

			if (movies.CurrentIsValid())
				movies.RemoveCurrent();
		}

		///User a, b; if (a == b) ...
		///User a, b; if (a.operator==(b)) ...
		bool operator==(const User& other) const
		{
			return movies == other.movies && username == other.username && password == other.password && fname == other.fname
						&& lname == other.lname && age == other.age;
		}


		friend class MovieChart;
};



#endif

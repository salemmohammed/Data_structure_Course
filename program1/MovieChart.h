#include <iostream>
#ifndef MOVIECHART_H
#define MOVIECHART_H

#include "LinkedList.h"

class MovieChart{

	private:
		// User users[255];
		LinkedList<User> users;

		User* current_user;
		int num_users;



	public:

		MovieChart();
		~MovieChart();

		bool login();
		void Update();
		void View();
		void logout();
		void Create();
		void Close();
		void List();

		//~MovieChart();

};

#endif

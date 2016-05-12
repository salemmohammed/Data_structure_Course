#include <iostream>
#ifndef MOVIECHART_H
#define MOVIECHART_H


class MovieChart{

	private:
		User users[255];
		User* current_user;
		int num_users;



	public:

		MovieChart();
	
		bool login();
		void Update();
		void View();
		void logout();
		void Create();

		//~MovieChart();

};

#endif
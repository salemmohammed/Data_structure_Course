#ifndef USER_H
#define USER_H


class User
{
	

	public:
		std::string fname;
		std::string lname;
		std::string num[5];
		int age;
};

void Update(User &user);
void View(User &user);
void Create(User &user);
void Favorites(User &user);

#endif
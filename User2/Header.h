#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <windows.h>


#define Green 2
#define White 7

using namespace std;


void saveUserToFile(const User& user);


int choosenLine(string* items, int size);

class Exception {
protected:
	time_t ttime;
	string text, source, dateTime;
	int line;

	Exception(const string& text, const int& line, const string& source);
public:
	void saveData() const;
	void show()const;
}; 
class DatabaseException :public Exception {
public:
	DatabaseException(const string& text, const int& line, const string& source);
};
class InvalidArgumentException :public Exception {
public:
	InvalidArgumentException(const string& text, const int& line, const string& source);
};


class User {
	string username;
	string password;
	string name;
	string surname;
public:
	void setUsername(const string);
	void setPassword(const string);
	void setName(const string);
	void setSurname(const string);
	string getUsername() const;
	string getPassword() const;
	string getSurname() const;
	string getName() const;
	void show() const;
	User();
};

class Database {
	User** users;
	int user_count = 0;
public:
	void addUser(User& user);
	User& getUserByUsername(string username);
	void updateUser(User& olduser, User& newuser);
	Database();
};

class Registration {
	Database _database;
	
public:
	Registration(const Database& database) {
		_database = database;
	}
	Database& getDatabase();
	void addData(User& user);
	void signIn(string username, string password);
	void signUp(string username, string password, string name, string surname);
};

class System {
public:
	static void Control();

};
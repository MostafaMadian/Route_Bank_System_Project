#pragma once
#include "Validation.h"


class Person
{
protected:
	string name, password;
	int id{};
public:

	//Defult Constructor
	Person() : id(0) {};
	//Paramitrized Constructor
	Person(int id, string name, string password) : id(id) {
		if (Validation::validName(name)) {
			this->name = name;
		}
		setPassword(password);
	};


	//Setters
	void setPassword(string password) {
		if (Validation::validPassword(password)) {
			this->password = password;
		}
	}

	//Getters
	string const getName() {
		return name;
	}
	string const getPassword() {
		return password;
	}
	int getID() const {
		return id;
	}


	//vitual pure to stop object creation 
	virtual void displayInfo() = 0;
};


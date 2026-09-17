#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <vector>

using namespace std;

class Validation
{
public:
	//Name Validation
	static bool validName(string name) {

		if (!(name.size() >= 3 && name.size() <= 30)) {
			return false;
		}
		
		for (int i = 0; i < name.size(); i++)
		{
			if (!(isalpha(name[i]) || isspace(name[i]))) {
				return false;
			}
		}
		return true;

	}

	//Password Validation
	static bool validPassword(string password) {
		if (!(password.size() >= 8 && password.size() <= 25)) {
			return false;
		}
		for (int i = 0; i < password.size(); i++)
		{
			if (isspace(password[i])) {
				return false;
			}

		}
		return true;

	}


	//Balance Validation
	static bool validBalance(double balance) {
		return (balance >= 1500);
	}

	//Salary Validation 
	static bool validSalary(double salary) {
		return (salary >= 5000);
	}

};
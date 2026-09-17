#pragma once
#include "Validation.h"
class FillData
{
public:
	static string enterName() {
		string name;
		cout << "\nPlease Enter Your Name....\n";
		cin.ignore();
		getline(cin, name);
		
		while (!Validation::validName(name))
		{
			cin.ignore();
			cout << "\nName Is Not Valid!\n";
			cout << "Name Must be Alphabetic from 3 to 30 Character!";
			cout << "\nPlease Enter a Valid Name...\n";
			getline(cin , name);
		}
		return name;
	}

	static string enterPassword() {
		string password;
		cout << "\nPlease Enter Your Password....\n";
		cin >> password;
		while (!Validation::validPassword(password))
		{
			cout << "\nPassword Is Not Valid!\n";
			cout << "Password Must be from 8 to 25 Character without Space!";
			cout << "\nPlease Enter a Valid Password...\n";
			cin >> password;
		}
		return password;
	}

	static double enterBalance() {
		double balance;
		cout << "\nPlease Enter Client's Balance....\n";
		cin >> balance;
		while (!Validation::validBalance(balance))
		{
			cout << "\nBalance Is Not Valid!\n";
			cout << "Minimum Balance is 1500 L.E.";
			cout << "\nPlease Enter a Valid Balance...\n";
			cin >> balance;
		}
		return balance;
	}

	static double enterSalary() {
		double salary;
		cout << "\nPlease Enter Employee's Salary....\n";
		cin >> salary;
		while (!Validation::validSalary(salary))
		{
			cout << "\nSalary Is Not Valid!\n";
			cout << "Minimum Salary is 5000 L.E.";
			cout << "\nPlease Enter a Valid Salary...\n";
			cin >> salary;
		}
		return salary;
	}

};


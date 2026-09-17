#pragma once
#include "Person.h"

class Client : public Person
{
private:
	double balance{};
public:

	//Default Constructor
	Client() :balance(0) {};
	//Paramitrized Constructor
	Client(int id, string name, string password, double balance) :
		Person(id, name, password) {
		if (Validation::validBalance(balance)) {
			this->balance = balance;
		}

	};
	double  getBalance() const {
		return balance;
	}
	void checkBalance() const {
		cout << "Your Balance is : " << balance;
	}
	void deposit(double amount) {
		if (amount > 0) {
			balance += amount;
			cout << "\nSuccessful Transaction!\n";
		}
		else {
			cout << "\nMinimum Amount is Zero\n";
		}
	}
	void withdraw(double amount) {
		if (amount > 0 && amount <= balance) {
			balance -= amount;
			cout << "\nSuccessful Transaction!\n";
		}
		else {
			cout << "\nAmount Exceeded Balance\n";
		}
	}
	void tranfertToAnother(Client& recipient, double amount) {
		if (amount > 0 && amount <= balance) {
			this->withdraw(amount);
			recipient.deposit(amount);
			cout << "\nSuccessful Transaction!\n";
		}
		else {
			cout << "\nAmount Exceeded Balance\n";
		}
	}
	void displayInfo() {
		cout << "\nClient Info\n===========" << endl
			<< "ID : " << id << endl
			<< "Name : " << name << endl
			<< "Balance : " << balance << endl;
	}
};

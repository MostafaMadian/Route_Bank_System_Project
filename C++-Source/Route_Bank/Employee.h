#pragma once
#include "Client.h"
#include "DataStorage.h"


class Employee : public Person
{
protected:
	double salary{};
public:

	
	Employee() :salary(0) {};

	Employee(int id, string name, string password, double salary) :
		Person(id, name, password) {
		setSalary(salary);
	}

	void setSalary(double salary) {
		if (Validation::validSalary(salary)) {
			this->salary = salary;
		}

	}

	double getSalary() const {
		return salary;
	}
	void addClient(Client* client) {
		DataStorage::setAllClients(client);
	}
	Client* searchClient(int id) {
		for (auto& client : DataStorage::getAllClients()) {
			if (client->getID() == id) {
				return client;
			}
		}
		return nullptr;
	}

	void listClient() {

		for (auto& client : DataStorage::getAllClients()) {
			client->displayInfo();
		}
	}
	void editClient(int id, string password) {
		Client* searchResult = searchClient(id);
		if(searchResult) searchResult->setPassword(password);
	}
	void checkSalary() const {
		cout << "\nYour Salary is : " << salary << endl;
	}

	void displayInfo() {
		cout << "\nEmployee Info\n=============" << endl
			<< "ID : " << id << endl
			<< "Name : " << name << endl
			<< "Salary : " << salary << endl;

	}
};


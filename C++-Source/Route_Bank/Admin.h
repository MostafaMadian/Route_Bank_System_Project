#pragma once

#include "Employee.h"
class Admin : public Employee
{
public:
	Admin() {};
	Admin(int id, string name, string password, double salary) :
		Employee(id, name, password, salary) {};

	void displayInfo() {
		cout << "\nAdmin Info\n==========" << endl;
		Employee::displayInfo();
	}



void addEmployee(Employee* employee) {
	DataStorage::getAllEmployees().push_back(employee);
}

Employee* searchEmployee(int id) {
	for (auto& employee : DataStorage::getAllEmployees()) {
		if (employee->getID() == id) {
			return employee;
		}
	}
	return nullptr;
}
void listEmployee() {
	for (auto& employee : DataStorage::getAllEmployees()) {
		employee->displayInfo();
	}
}
void editEmployee(int id, string password, double salary) {
	Employee* search = searchEmployee(id);
	if (search) {
		search->setPassword(password);
		search->setSalary(salary);
	}
}
};

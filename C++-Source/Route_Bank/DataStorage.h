#pragma once
#include <vector>

using namespace std;

//Forward Declerations
class Admin;
class Employee;
class Client;

class DataStorage
{
	static vector<Admin*> allAdmins;
	static vector<Employee*> allEmployees;
	static vector<Client*> allClients;
public:
	static vector<Client*>& getAllClients() {
		return allClients;
	}
	static void setAllClients(Client* client) {
		allClients.push_back(client);
	}

	static vector<Employee*>& getAllEmployees() {
		return allEmployees;
	}
	static void setAllEmployees(Employee* employee) {
		allEmployees.push_back(employee);
	}

	static vector<Admin*>& getAllAdmins() {
		return allAdmins;
	}
	static void setAllAdmins(Admin* admin) {
		allAdmins.push_back(admin);
	}



	static void clearHeap() {
		for (auto& admin : allAdmins) {
		
			delete admin;
		}
		allAdmins.clear();

		for (auto& client : allClients) {

			delete client;
		}
		allClients.clear();

		for (auto& employee : allEmployees) {

			delete employee;
		}
		allEmployees.clear();
	
	}


};


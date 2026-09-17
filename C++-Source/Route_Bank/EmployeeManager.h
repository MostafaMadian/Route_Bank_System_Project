#pragma once
#include "FileManager.h"
#include "ClientManager.h"

class EmployeeManager
{
private:
	static void EmployeeMenu() {
		cout << "(1) Display Information\n";
		cout << "(2) Check Salary\n";
		cout << "(3) Edit Password\n";
		cout << "(4) Add New Client\n";
		cout << "(5) List All Clients\n";
		cout << "(6) Search for a Client\n";
		cout << "(7) Edit Client Information\n";
		cout << "(8) Back to Employee Menu\n";
		cout << "(9) Logout\n";
		cout << "(10) Logout & End Program\n";
	}
public:
	static void newClient(Employee* employee) {
		int id = FilesHelper::getLastID("ClientLastID.txt") + 1;
		string name = FillData::enterName();
		string password = FillData::enterPassword();
		double balance = FillData::enterBalance();
		Client* client = new Client(id, name, password, balance);
		employee->addClient(client);
		FileManager f;
		f.updateClient();
		cout << "\nClient is Added Successfully\n";
	}

	static void listAllClients(Employee* employee) {
		employee->listClient();
	}

	static void searchForClient(Employee* employee) {
		cout << "Please Enter Client ID\n";
		int id;
		cin >> id;
		system("cls");
		if (employee->searchClient(id) == nullptr) {
			cout << "\nClient is not Found\n";
		}
		else {
			employee->searchClient(id)->displayInfo();
		}
	}
	static void editClientInfo(Employee* employee) {
		cout << "Please Enter Client ID\n";
		int id;
		cin >> id;
		system("cls");
		if (employee->searchClient(id) == nullptr) {
			cout << "\nClient is not Found\n";
		}
		else {
			string password = FillData::enterPassword();
			employee->editClient(id, password);
			FileManager f;
			f.updateClient();
			cout << "\nClient Information is Edited Successfully\n";
		}

	}
	static Employee* login(int id, string password) {
		for (auto& employee : DataStorage::getAllEmployees()) {
			if (employee->getID() == id && employee->getPassword() == password) {
				return employee;
			}
		}
		return nullptr;
	}
	static void back(Employee* employee) {

		employeeOptions(employee);
	}
	static bool employeeOptions(Employee* employee) {
		EmployeeMenu();
		cout << "\nPlease Choose an Option...\n";
		int option;
		cin >> option;
		FileManager f;
		switch (option)
		{
		case 1:
			system("cls");
			employee->displayInfo();
			break;
		case 2:
			system("cls");
			employee->checkSalary();
			break;
		case 3:
			system("cls");
			ClientManager::editPassword(employee);
			f.updateEmployee();
			break;
		case 4:
			system("cls");
			newClient(employee);
			break;
		case 5:
			system("cls");
			listAllClients(employee);
			break;
		case 6:
			system("cls");
			searchForClient(employee);
			break;
		case 7:
			system("cls");
			editClientInfo(employee);
			break;
		case 8:
			system("cls");
			back(employee);
			break;
		case 9:
			system("cls");
			return false;
			break;
		case 10:
			system("cls");
			cout << "Thank you for Choosing Route Bank!\n";
			DataStorage::clearHeap();
			exit(0);
		default:
			system("cls");
			cout << "\nPlease Enter a Number Exists in the Menu!\n";
			back(employee);
			break;
		}
		char flag;
		cout << "\nDo you Want Another Operation?(Y/N)\n";
		cin >> flag;
		system("cls");
		if (flag == 'y' || flag == 'Y') {
			employeeOptions(employee);
		}
		else {
			return false;
		}

		return true;
	}
};


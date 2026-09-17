#pragma once
#include "EmployeeManager.h"

class AdminManager
{
	private:
		static void AdminMenu() {
			cout << "(1) Display Information\n";
			cout << "(2) Check Salary\n";
			cout << "(3) Edit Password\n";
			cout << "(4) Add New Employee\n";
			cout << "(5) Add New Client\n";
			cout << "(6) List All Employees\n";
			cout << "(7) List All Clients\n";
			cout << "(8) Search for an Employee\n";
			cout << "(9) Search for a Client\n";
			cout << "(10) Edit Employee Information\n";
			cout << "(11) Edit Client Information\n";
			cout << "(12) Back to Admin Menu\n";
			cout << "(13) Logout\n";
			cout << "(14) Logout & End Program\n";
		}
	public:
		static void back(Admin* admin) {
			AdminMenu();
		}

		static void newEmployee(Admin* admin) {
			int id = FilesHelper::getLastID("EmployeeLastID.txt") + 1;
			string name = FillData::enterName();
			string password = FillData::enterPassword();
			double salary = FillData::enterSalary();
			Employee* employee = new Employee(id,name, password, salary);
			admin->addEmployee(employee);
			FileManager f;
			f.updateEmployee();
			cout << "\nEmployee is Added Successfully\n";
		}

		static void listAllEmployees(Admin* admin) {
			admin->listEmployee();
		}

		static void searchForEmployee(Admin* admin) {
			cout << "Please Enter Employee ID\n";
			int id;
			cin >> id;
			system("cls");
			if (admin->searchEmployee(id) == nullptr) {
				cout << "\nEmployee is not Found\n";
			}
			else {
				admin->searchEmployee(id)->displayInfo();
			}
		}
		static void editEmployeeInfo(Admin* admin) {
			cout << "Please Enter Employee ID\n";
			int id;
			cin >> id;
			system("cls");
			if (admin->searchEmployee(id) == nullptr) {
				cout << "\nEmployee is not Found\n";
			}
			else {
				string password = FillData::enterPassword();
				double salary = FillData::enterSalary();
				admin->editEmployee(id, password, salary);
				FileManager f;
				f.updateEmployee();
				cout << "\nEmployee Information is Edited Successfully\n";
			}

		}
		static Admin* login(int id, string password) {
			for (auto& admin : DataStorage::getAllAdmins()) {
				if (admin->getID() == id && admin->getPassword() == password) {
					return admin;
				}
			}
			return  nullptr;
		}

		static bool adminOptions(Admin* admin) {
			AdminMenu();
			cout << "\nPlease Choose an Option...\n";
			int option;
			cin >> option;
			FileManager f;
			switch (option)
			{
			case 1:
				system("cls");
				admin->displayInfo();
				break;
			case 2:
				system("cls");
				admin->checkSalary();
				break;
			case 3:
				system("cls");
				ClientManager::editPassword(admin);
				f.updateAdmin();
				break;
			case 4:
				system("cls");
				newEmployee(admin);
				break;
			case 5:
				system("cls");
				EmployeeManager::newClient(admin);
				break;
			case 6:
				system("cls");
				listAllEmployees(admin);
				break;
			case 7:
				system("cls");
				EmployeeManager::listAllClients(admin);
				break;
			case 8:
				system("cls");
				searchForEmployee(admin);
				break;
			case 9:
				system("cls");
				EmployeeManager::searchForClient(admin);
				break;
			case 10:
				system("cls");
				editEmployeeInfo(admin);
				break;
			case 11:
				system("cls");
				EmployeeManager::editClientInfo(admin);
				break;
			case 12:
				system("cls");
				back(admin);
				break;
			case 13:
				system("cls");
				return false;
				break;
			case 14:
				system("cls");
				cout << "Thank you for Choosing Route Bank!\n";
				DataStorage::clearHeap();
				exit(0);
			default:
				system("cls");
				cout << "\nPlease Enter a Number Exists in the Menu!\n";
				back(admin);
				break;
			}
			char flag;
			
				cout << "\nDo you Want Another Operation?(Y/N)\n";
				cin >> flag;
				system("cls");
				if (flag == 'y' || flag == 'Y') {
					adminOptions(admin);
				}
				else {
					return false;
				}
			
			return true;


		}
};




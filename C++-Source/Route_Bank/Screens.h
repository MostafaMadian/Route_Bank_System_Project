#pragma once
#include <windows.h> 
#include "AdminManager.h"
#include "DataStorage.h"
class Screens
{
private:
	static void bankName() {
		cout << "\t    @@@@@@@   @@@@@@@@  @@    @@  @@@@@@@@  @@@@@@@       @@@@@@@   @@@@@@@@  @@@@    @@  @@   @@\n";
		cout << "\t    @@    @@  @@    @@  @@    @@     @@     @@            @@    @@  @@    @@  @@ @@   @@  @@  @@\n";
		cout << "\t    @@@@@@@   @@    @@  @@    @@     @@     @@@@@@        @@@@@@@   @@@@@@@@  @@  @@  @@  @@ @\n";
		cout << "\t    @@    @@  @@    @@  @@    @@     @@     @@            @@    @@  @@    @@  @@   @@ @@  @@  @@\n";
		cout << "\t    @@    @@  @@@@@@@@  @@@@@@@@     @@     @@@@@@@       @@@@@@@   @@    @@  @@    @@@@  @@   @@\n";
	}

	static void welcome() {
		system("Color 0e");
		cout << "\n\n\n\n\n\n\n\n\n";
		cout << "\t    @@       @@  @@@@@@@  @@      @@@@@@@  @@@@@@@@  @@@@    @@@@  @@@@@@@     @@@@@@@@  @@@@@@@@\n";
		cout << "\t    @@   @   @@  @@       @@      @@       @@    @@  @@  @  @  @@  @@		  @@	 @@    @@\n";
		cout << "\t    @@  @@@  @@  @@@@@@   @@      @@       @@    @@  @@   @@   @@  @@@@@@	  @@     @@    @@\n";
		cout << "\t    @@ @@ @@ @@  @@       @@      @@       @@    @@  @@        @@  @@             @@     @@    @@\n";
		cout << "\t    @@@     @@@  @@@@@@@  @@@@@@  @@@@@@@  @@@@@@@@  @@        @@  @@@@@@@        @@     @@@@@@@@\n\n\n";
		cout << "\033[0m";
		bankName();
		Sleep(6000);
		system("cls");
		system("Color 0e");
	}

	static void loginOptions() {
		cout << "(1) Admin\n";
		cout << "(2) Employee\n";
		cout << "(3) Client\n\n";
		cout << "Login as : \n";
	}

	static int loginAs() {
		loginOptions();
		int option;
		cin >> option;
		if (option == 1 || option == 2 || option == 3) {
			return option;
		}
		else {
			system("cls");
			return loginAs();
		}
	}
	static void invalid(int option) {
		system("cls");
		cout << "\nInvalid ID or Password\n";
		loginScreen(option);
	}

	static void logout() {
		system("cls");
		loginScreen(loginAs());
	}
	static void loginScreen(int option) {
		int id;
		string password;
		cout << "\nPlease Enter Your ID : ";
		cin >> id;
		cout << "\nPlease Enter Your Password : ";
		cin >> password;
		switch (option)
		{
		case 1: {
			system("cls");
			auto adminLog = AdminManager::login(id, password);
			if (adminLog != nullptr) {
				while (AdminManager::adminOptions(adminLog));
				logout();
			}
			else {
				invalid(1);
				break;
			}
		}
		
		case 2:
			system("cls");
			if (EmployeeManager::login(id, password) != nullptr) {
				while (EmployeeManager::employeeOptions(EmployeeManager::login(id, password)));
				logout();
			}
			else {
				invalid(2);
				break;
			}
		case 3:
			system("cls");
			if (ClientManager::login(id, password) != nullptr)
			{
				while (ClientManager::clientOptions(ClientManager::login(id, password)));
				logout();
			}
			else invalid(3);
			break; 
		default:
			system("cls");
			loginOptions();
			break;
		}
	}
public:
	static void runApp() {
		FileManager f;
		f.fetchAllData();
		welcome();
		loginScreen(loginAs());
		DataStorage::clearHeap();
	}
};


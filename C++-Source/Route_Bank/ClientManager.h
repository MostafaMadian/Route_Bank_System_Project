#pragma once
#include "FilesHelper.h"
#include "FileManager.h"
#include "FillData.h"


class ClientManager
{
private:
	static void ClientMenu() {
		cout << "(1) Check Balance\n";
		cout << "(2) Withraw\n";
		cout << "(3) Deposit\n";
		cout << "(4) Transfer Amount\n";
		cout << "(5) Edit Password\n";
		cout << "(6) Display Information\n";
		cout << "(7) Back to Client Menu\n";
		cout << "(8) Logout\n";
		cout << "(9) Logout & End Program\n";
	}
public:
	static void editPassword(Person* person) {
		string password = FillData::enterPassword();
		person->setPassword(password);
		cout << "\nPassword Is Edited Successfully!\n";
	}



	static Client* login(int id, string password) {
		for (auto& client : DataStorage::getAllClients()) {
			if (client->getID() == id && client->getPassword() == password) {
				return client;
			}

		}
		return nullptr;

	}


	static void back(Client* client) {

		clientOptions(client);
	}
	static bool clientOptions(Client* client) {
		ClientMenu();
		cout << "\nPlease Choose an Option...\n";
		int option;
		cin >> option;
		Employee employee;
		double amount;
		FileManager f;
		switch (option)
		{
		case 1:
			system("cls");
			client->checkBalance();
			break;
		case 2:
			system("cls");
			cout << "\nPlease Enter the Amount...\n";
			cin >> amount;
			client->withdraw(amount);
			f.updateClient();
			break;
		case 3:
			system("cls");
			cout << "\nPlease Enter the Amount...\n";
			cin >> amount;
			client->deposit(amount);
			f.updateClient();
			break;
		case 4:
			system("cls");
			cout << "\nPlease Enter the Recipient ID\n";
			int id;
			cin >> id;
			while (employee.searchClient(id) == nullptr) {
				cout << "Invalid ID\n";
				cout << "Please Enter a Valid ID\n";
				cin >> id;
			}
			cout << "\nPlease Enter the Amount...\n";
			cin >> amount;
			client->tranfertToAnother(*employee.searchClient(id), amount);
			f.updateClient();
			break;
		case 5:
			system("cls");
			editPassword(client);
			f.updateClient();
			break;
		case 6:
			system("cls");
			client->displayInfo();
			break;
		case 7:
			system("cls");
			back(client);
			break;
		case 8:
			system("cls");
			return false;
			break;
		case 9:
			system("cls");
			cout << "Thank you for Choosing Route Bank!\n";
			DataStorage::clearHeap();
			exit(0);
		default:
			system("cls");
			cout << "\nPlease Enter a Number Exists in the Menu!\n";
			clientOptions(client);
			break;
		}
		char flag;

		cout << "\nDo you Want Another Operation?(Y/N)\n";
		cin >> flag;
		system("cls");
		if (flag == 'y' || flag == 'Y') {
			clientOptions(client);
		}
		else {
			return false;
		}

		return true;
	}
};


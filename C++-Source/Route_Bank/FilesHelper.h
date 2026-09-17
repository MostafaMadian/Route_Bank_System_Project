#pragma once
#include "Parser.h"

class FilesHelper
{
private:
	static void saveLastID(string lastIDfile, int id) {
		ofstream file;
		file.open(lastIDfile);
		file << id;
		file.close();	
	}
	
public:
	static int getLastID(string lastIDfile) {
		int id;
		ifstream file;
		file.open(lastIDfile);
		file >> id;
		file.close();
		return id;
	}

	static void saveClient(Client client) {
		int id = getLastID("ClientLastID.txt");
		ofstream file;
		file.open("ClientData.txt" , ios::app);
		file << id + 1 << '-' << client.getName() << '-'
			<< client.getPassword() << '-' << client.getBalance() << '\n';
		file.close();
		saveLastID("ClientLastID.txt", id + 1);
	}

	static void saveEmployee(string dataFile, string lastIDfile, Employee employee) {
		int id = getLastID(lastIDfile);
		ofstream file;
		file.open(dataFile, ios::app);
		file << id + 1 << '-' << employee.getName() << '-'
			<< employee.getPassword() << '-' << employee.getSalary() << '\n';
		file.close();
		saveLastID(lastIDfile, id + 1);
	}

	//getClients() //Read from files
	static void fetchClient() {
		string line;
		ifstream file;
		file.open("ClientData.txt");
		while (getline(file, line)) {
			DataStorage::setAllClients(Parser::parseToClient(line));
		}
		file.close();
	}

	//getEmployees() //ReadData //ReadFile
	static void fetchEmployee() {
		string line;
		ifstream file;
		file.open("EmployeeData.txt");
		while (getline(file, line)) {
			DataStorage::setAllEmployees(Parser::parseToEmployee(line));
		}
		file.close();
	}

	static void fetchAdmin() {
		string line;
		ifstream file;
		file.open("AdminData.txt");
		while (getline(file, line)) {
			DataStorage::setAllAdmins(Parser::parseToAdmin(line));
		}
		file.close();
	}

	static void clearFile(string dataFile, string lastIDfile) {
		ofstream clearFile , zeroID;
		clearFile.open(dataFile, ios::trunc);
		clearFile.close();
		zeroID.open(lastIDfile);
		zeroID << 0;
		zeroID.close();
	}
	
};


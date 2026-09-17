#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"
#include "DataStorage.h"

class FileManager : public DataSourceInterface
{
private:
	 void addClient(Client client) override {
		 FilesHelper::saveClient(client);
	 }
	 void addEmployee(Employee employee) override {
		 FilesHelper::saveEmployee("EmployeeData.txt", "EmployeeLastID.txt", employee);
	 }
	 void addAdmin(Admin admin) override {
		 FilesHelper::saveEmployee("AdminData.txt", "AdminLastID.txt", admin);
	 }
	 void fetchAllClients() override {
		 FilesHelper::fetchClient();
	 };
	 void fetchAllEmployees() override {
		 FilesHelper::fetchEmployee();
	 };
	 void fetchAllAdmins() override {
		 FilesHelper::fetchAdmin();
	 };

	 void clearAllClients() override {
		 FilesHelper::clearFile("ClientData.txt", "ClientLastID.txt");
	 }
	 void clearAllEmployees() override {
		 FilesHelper::clearFile("EmployeeData.txt", "EmployeeLastID.txt");
	 }
	 void clearAllAdmins() override {
		 FilesHelper::clearFile("AdminData.txt", "AdminLastData.txt");
	 }
public:
	void fetchAllData() {
		fetchAllClients();
		fetchAllEmployees();
		fetchAllAdmins();
	}
	void updateClient() {
		clearAllClients();
		for (auto& client : DataStorage::getAllClients()) {
			addClient(*client);
		}
	}
	void updateEmployee(){
		clearAllEmployees();
		for (auto& employee : DataStorage::getAllEmployees()) {
			addEmployee(*employee);
		}
	}
	void updateAdmin() {
		clearAllAdmins();
		for (auto& admin : DataStorage::getAllAdmins()) {
			addAdmin(*admin);
		}
	}
};


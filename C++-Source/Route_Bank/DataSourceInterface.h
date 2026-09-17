#pragma once

#include "Admin.h"

class DataSourceInterface
{
protected:
	virtual void addClient(Client client) = 0;
	virtual void addEmployee(Employee employee) = 0;
	virtual void addAdmin(Admin admin) = 0;
	virtual void fetchAllClients() = 0;
	virtual void fetchAllEmployees() = 0;
	virtual void fetchAllAdmins() = 0;
	virtual void clearAllClients() = 0;
	virtual void clearAllEmployees() = 0;
	virtual void clearAllAdmins() = 0;
};


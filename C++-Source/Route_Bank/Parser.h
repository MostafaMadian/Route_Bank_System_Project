#pragma once
#include "Admin.h"
#include <fstream>
#include <sstream>
class Parser
{
private:
	static vector<string> split(string line) {
		stringstream convert(line);
		string token;
		vector<string> data;
		while (getline(convert,token,'-'))
		{
			data.push_back(token);
		}
		return data;
	}
public:
	static Client* parseToClient(string line) {
		vector<string> data = split(line);
		return  new Client(stoi(data[0]), data[1], data[2], stod(data[3]));
	}
	static Employee* parseToEmployee(string line) {
		vector<string> data = split(line);
		return  new Employee(stoi(data[0]), data[1], data[2], stod(data[3]));
	}
	static Admin* parseToAdmin(string line) {
		vector<string> data = split(line);
		return new Admin (stoi(data[0]), data[1], data[2], stod(data[3]));
	}
};


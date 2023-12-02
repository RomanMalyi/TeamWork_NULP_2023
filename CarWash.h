#ifndef CarWash
#define CarWash
#include <string>
#include <map>
#include <vector>
#include <time.h>
#include <iostream>
using namespace std;

class Member {
private:
	string FName;
	string SName;
public:
	Member() = delete;
	Member(string fname, string sname);
	string getFName();
	string getSName();
};

class Owner : public Member{ 
public:
	Owner() = delete;
	Owner(string fname, string sname);
};

class Worker : public Member{
private:
	unsigned ID;
public:
	Worker() = delete;
	Worker(string fname, string sname);
	unsigned getID();
};




class Service {
private:
	string Name;
	unsigned Price;
	unsigned WorkersN;
	vector<unsigned> WorkersIDs;
	tm Began;
	tm Ended;
public:
	Service() = delete;
	Service(string Name, unsigned Price, unsigned WorkersN, vector<unsigned> WorkersIDs, tm Began, tm Ended);
	static vector<string> services_catalog;
	static map<string, unsigned> service_price_map;
	tm getBegan();
	tm getEnded();
	friend void LoadCatalog();
	friend void LoadMap();
};
vector<string> Service::services_catalog;
const int names_N = 3;
const char* services_names[names_N] = { "Salon","Car Body + Salon","Dry-Cleaning" };
const int Prices[names_N] = { 250, 350, 1800 };
void LoadCatalog();  // CRUCIAL, use in the very beginning of program
void LoadMap();		 // CRUCIAL, use in the very beginning of program


class Table {
private:
	tm Date;
	
public:
	vector<Service> services_table;
	void AddService(Service service);
	friend ofstream& operator<<(ofstream& file, const Table& table);
	friend ifstream& operator>>(ifstream& file, const Table& table);
};





#endif
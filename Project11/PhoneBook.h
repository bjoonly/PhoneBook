#pragma once
#include<iostream>
#include<fstream>
using namespace std;

struct Contact {
	 char*name=nullptr;
	 char*mobileNumber=nullptr;
	 char*homeNumber=nullptr;
	 char*address=nullptr;
};
class PhoneBook{
	Contact*book;
	int size;

	bool CheckIndex(int index)const;
	void RemoveMemoryContact(int index);
public:
	PhoneBook();
	~PhoneBook();
	void SetName(const char* name, int index);
	void SetMobileNumber(const char*mobileNumber, int index);
	void SetHomeNumber(const char* homeNumber, int index);
	void SetAddress(const char* address, int index);
	void SetAll(const char* name, const char* mobileNumber, const char* homeNumber, const char* address,int index);

	const char*GetName(int index)const;
	const char* GetMobileNumber(int index)const;
	const char* GetHomeNumber(int index)const;
	const char* GetAddress(int index)const;

	void AddNewContact(const char* name, const char* mobileNumber, const char* homeNumber, const char* address);
	void DeleteContact(int index);
	
	void printContact(int index)const;
	void printAllContacts()const;
	
	void SearchByName(const char* name)const;
	void SearchByMobileNumber(const char* mobileNumber)const;
	void SearchByNameAndMobileNumber(const char* name, const char* mobileNumber)const;

	void Save()const;
	void Load();
};



#include "PhoneBook.h"


bool PhoneBook::CheckIndex(int index)const{
    return (index>=0 && index<size);
}

void PhoneBook::RemoveMemoryContact(int index){
    delete[]book[index].name;
    delete[]book[index].mobileNumber;
    delete[]book[index].homeNumber;
    delete[]book[index].address;
}

PhoneBook::PhoneBook():size(0),book(nullptr) {}

PhoneBook::~PhoneBook(){
    for (int i = 0; i < size; i++) 
        RemoveMemoryContact(i);
    
    delete[]book;
    size = 0;
}

void PhoneBook::SetName(const char* name,int index){
    if (CheckIndex(index)) {
            delete[]book[index].name;
        book[index].name = new char[strlen(name) + 1];
        strcpy_s(book[index].name, strlen(name) + 1, name);
    }
}

void PhoneBook::SetMobileNumber(const char* mobileNumber, int index){
    if (CheckIndex(index)) {
        delete[]book[index].mobileNumber;
        book[index].mobileNumber = new char[strlen(mobileNumber) + 1];
        strcpy_s(book[index].mobileNumber, strlen(mobileNumber) + 1, mobileNumber);
    }
}

void PhoneBook::SetHomeNumber(const char* homeNumber, int index){
    if (CheckIndex(index)) {
            delete[]book[index].homeNumber;
        book[index].homeNumber = new char[strlen(homeNumber) + 1];
        strcpy_s(book[index].homeNumber, strlen(homeNumber) + 1, homeNumber);
    }
}

void PhoneBook::SetAddress(const char* address, int index){
    if (CheckIndex(index)) {
            delete[]book[index].address;
        book[index].address = new char[strlen(address) + 1];
        strcpy_s(book[index].address, strlen(address) + 1, address);
    }
}

void PhoneBook::SetAll(const char* name, const char* mobileNumber, const char* homeNumber, const char* address, int index) {
        SetName(name, index);
        SetMobileNumber(mobileNumber, index);
        SetHomeNumber(homeNumber, index);
        SetAddress(address, index);
}

const char* PhoneBook::GetName(int index) const{
    if (CheckIndex(index)) 
    return book[index].name;
    return "Incorect index";
}

const char* PhoneBook::GetMobileNumber(int index) const{
    if (CheckIndex(index)) 
    return book[index].mobileNumber;
    return "Incorrect index";
}

const char* PhoneBook::GetHomeNumber(int index) const{
    if (CheckIndex(index)) 
    return book[index].homeNumber;
    return "Incorrect index";
}

const char* PhoneBook::GetAddress(int index) const{
    if (CheckIndex(index)) 
    return book[index].address;
    return "Incorrect index";
}

void PhoneBook::AddNewContact(const char* name, const char* mobileNumber, const char* homeNumber, const char* address){
    Contact*newBook = new Contact[++size];
    for (int i = 0; i < size-1; i++) 
        newBook[i] = book[i];
    
    delete[]book;
    book = newBook;
    SetAll(name, mobileNumber, homeNumber, address, size - 1);
}

void PhoneBook::DeleteContact(int index){
    if (CheckIndex(index)) {
        Contact* newBook = new Contact[--size];
        for (int i = 0; i < size; i++) {
            if (i < index)
                newBook[i] = book[i];
            else
                newBook[i] = book[i + 1];
        }
        RemoveMemoryContact(index);
        delete[]book;
        book = newBook;
    }
}

void PhoneBook::printContact(int index) const{
    if (CheckIndex(index)) {
        cout << "\nName: " << book[index].name << "\nMobile number:" << book[index].mobileNumber << "\nHome number:" <<
            book[index].homeNumber << "\nAddress: " << book[index].address << endl;
    }
}

void PhoneBook::printAllContacts()const {
    for (int i = 0; i < size; i++) {
        printContact(i);
        cout << endl;
    }

}

void PhoneBook::SearchByName(const char* name)const {
    bool res = false;
    for (int i = 0; i < size; i++) {
        if (strcmp(book[i].name,name)==0) {
            printContact(i);
            res = true;
        }
    }
    if (res == 0) {
        cout << "No contacts with the entered name.\n";

    }
}


void PhoneBook::SearchByMobileNumber(const char* mobileNumber)const {
    bool res = false;
    for (int i = 0; i < size; i++) {
        if (strcmp(book[i].mobileNumber, mobileNumber) == 0) {
            printContact(i);
            res = true;
        }
    }
    if (res == 0) {
        cout << "No contacts with the entered mobile number.\n";

    }
}

void PhoneBook::SearchByNameAndMobileNumber(const char* name, const char* mobileNumber) const{
    bool res = false;
    for (int i = 0; i < size; i++) {
        if (strcmp(book[i].mobileNumber, mobileNumber) == 0 && strcmp(book[i].name, name) == 0) {
            printContact(i);
            res = true;
        }
    }
    if (res == 0) {
        cout << "No contacts with the entered name and mobile number.\n";

    }

}

void PhoneBook::Save() const{
    ofstream fout;
    fout.open("PhoneBook.txt");
    bool isOpen = fout.is_open();
    if (isOpen == false) {
        system("cls");
        cout << "The file couldn't be opened.\n";
        return;
    }
    fout << size << endl;
    for (int i = 0; i < size; i++) {
        fout << book[i].name << endl << book[i].mobileNumber << endl << book[i].homeNumber << endl <<
            book[i].address << endl;
    }
    fout.close();
}

void PhoneBook::Load(){
    ifstream fin;
    fin.open("PhoneBook.txt");
    bool isOpen = fin.is_open();
    if (isOpen == false) {
        system("cls");
        cout << "The file couldn't be opened.\n";
        return;
    }
    for (int i = 0; i < size; i++)
        RemoveMemoryContact(i);
    delete[]book;
    fin >> size;
    book = new Contact[size];
    fin.ignore();
    for (int i = 0; i < size; i++) {
        char line[100];
        fin.getline(line, 100);
        SetName(line,i);
        fin.getline(line, 100);
        SetMobileNumber(line, i);
        fin.getline(line, 100);
        SetHomeNumber(line, i);
        fin.getline(line, 100);
        SetAddress(line, i);
    }
    fin.close();
}



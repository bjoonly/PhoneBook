#include<iostream>
#include"PhoneBook.h"
using namespace std;
int main() {
	PhoneBook pb1,pb2;
	cout << "First phone book:\n\nAdd contact to first book:\n";
	pb1.AddNewContact("Karyna", "+380975937769", "23322333", "Lonokombinativska 1");
	pb1.printAllContacts();
	cout << "\nSave first phone book.\n";
	pb1.Save();
	cout << "\nAdd contact to first book:\n";
	pb1.AddNewContact("Nastya", "+393939392", "28838383", "Generala Bezruchka Avenue 10");
	pb1.printAllContacts();
	cout << "\nDelete contact from first book:\n";
	pb1.DeleteContact(0);
	pb1.printAllContacts();
	cout << "\nSeaching by name:\n";
	pb1.SearchByName("Karyna");
	
	cout << "\nLoad phone book.\n";
	pb2.Load();
	cout << "\nSecond phone book:\n";
	pb2.printAllContacts();
	cout << "\nAdd contact to second book:\n";
	pb2.AddNewContact("Vasa", "+380682454542", "11123323", "Haharina 5");
	pb2.printAllContacts();
	cout << "\nSeaching by number:\n";
	pb2.SearchByMobileNumber("+380975937769");
	cout << "\nSeachin by number and name:\n";
	pb2.SearchByNameAndMobileNumber("Vasa", "+380682454542");
	return 0;
}
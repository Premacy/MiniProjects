#pragma_once

#include <iostream>

struct person_t{
    string name;
    string surname;
    string phoneNumber;

    bool isFill;
};

const int N = 100;

typedef person_t PhoneBook[] PhoneBook_t;

void PhoneBookInit(PhoneBook_t PhoneBook);

void PrintMenu();
void Menu(string action, PhoneBook_t PhoneBook);

void Add(PhoneBook_t PhoneBook);
void Delete(pPhoneBook_t PhoneBook);
void FindBySurname(person_t PhoneBook[]);
void FindByName(person_t PhoneBook[]);
void PrintPhoneBook(person_t PhoneBook[]);
void PrintPhoneBookAction(person_t PhoneBook[]);

void choice(string actions);
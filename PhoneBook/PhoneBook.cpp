#include "PhoneBook.h"

void PrintMenu(){
    cout << "1-Add" << endl;
    cout << "2-Delete" << endl;
    cout << "3-Find by surname" << endl;
    cout << "4-Find by name" << endl;
    cout << "5-Print phone book" << endl;
    cout << "6-Exit" << endl;
    cout << "" << endl;
}

void choice(string action, person_t PhoneBook[]){
    if(action == "1"){
        Add(PhoneBook);
    }
    else if(action == "2"){
        Delete(PhoneBook);
    }
    else if(action == "3"){
        FindBySurname(PhoneBook);
    }
    else if(action == "4"){
        FindByName(PhoneBook);
    }
    else if(action == "5"){
        PrintPhoneBookAction(PhoneBook);
    }
    else if(action == "6"){
        cout << "<<<<Goodbye>>>>" << endl;
        return;
    }
}

void Add(person_t PhoneBook[]){
    int g = 0;
    string action;
    int i = 0;

    do
    {
        for(; PhoneBook[i].isFill != false; i++){
        }

        cout << "Print name: ";
        cin >> PhoneBook[i].name;

        cout << "Print surname: ";
        cin >> PhoneBook[i].surname;

        cout << "Print phone number: ";
        cin >> PhoneBook[i].phoneNumber;

        cout << " " << endl;

        PhoneBook[i].isFill = true;
        cout << "1-Resume" << endl;
        cout << "2-Back to menu" << endl;
        cout << " " << endl;
        cout << "Enter the action: ";
        cin >> g;
    } while(g == 1);
    Menu(action, PhoneBook);
}

void Delete(person_t PhoneBook[]){
    PrintPhoneBook(PhoneBook);
    string PhoneNumber;
    int g = 0;
    string action;
    do
    {
        cout << "Enter the phone number: ";
        cin >> PhoneNumber;
        for(int i = 0; i < N; i++){
            if(PhoneNumber == PhoneBook[i].phoneNumber){
                PhoneBook[i].isFill = false;
            }
        }
        cout << " " << endl;
        cout << "1-Resume" << endl;
        cout << "2-Back to menu" << endl;
        cout << " " << endl;
        cout << "Enter the action: ";
        cin >> g;
    } while (g == 1);
    Menu(action, PhoneBook);
}

void FindBySurname(person_t PhoneBook[]){
    int g = 0;
    string action;
    string s;

    do
    {
        cout << "Print surname: ";
        cin >> s;

        for(int i = 0; i < N; i++){
            if(s == PhoneBook[i].surname){
                cout << PhoneBook[i].name << endl;
                cout << PhoneBook[i].surname << endl;
                cout << PhoneBook[i].phoneNumber << endl;
            }
        }
        
        cout << " " << endl;
        cout << "1-Resume" << endl;
        cout << "2-Back to menu" << endl;
        cout << " " << endl;
        cout << "Enter the action: ";
        cin >> g;
    } while(g == 1);
    Menu(action, PhoneBook);
}

void FindByName(person_t PhoneBook[]){
    int g = 0;
    string action;
    string s;

    do
    {
        cout << "Print name: ";
        cin >> s;

        for(int i = 0; i < N; i++){
            if(s == PhoneBook[i].name){
                cout << PhoneBook[i].name << endl;
                cout << PhoneBook[i].surname << endl;
                cout << PhoneBook[i].phoneNumber << endl;
            }
        }
        
        cout << " " << endl;
        cout << "1-Resume" << endl;
        cout << "2-Back to menu" << endl;
        cout << " " << endl;
        cout << "Enter the action: ";
        cin >> g;
    } while(g == 1);
    Menu(action, PhoneBook);
}

void PrintPhoneBook(person_t PhoneBook[]){
    for(int i = 0; i < N; i++){
        if(PhoneBook[i].isFill != false){
            cout << PhoneBook[i].name << endl;
            cout << PhoneBook[i].surname << endl;
            cout << PhoneBook[i].phoneNumber << endl;
            cout << "////////////////" << endl;
        }
    }
}

void PrintPhoneBookAction(person_t PhoneBook[]){
    PrintPhoneBook(PhoneBook);
    int g = 0;

    cout << "1-Back to menu" << endl;
    cout << " " << endl;
    cout << "Enter the action: ";
    cin >> g;
    string action;
    Menu(action, PhoneBook);
}

void Menu(string action, person_t PhoneBook[]){
    PrintMenu();
    cout << "Enter the action: ";
    cin >> action;
    cout << " " << endl;
    choice(action, PhoneBook);
}

void PhoneBookInit(person_t PhoneBook[]){
    for(int i = 0; i < N; i++){
        PhoneBook[i].isFill = false;
    }
}
#include <iostream>
#include <string>
using namespace std;

#include "PhoneBook.h"

#define MAX_BOOK_SIZE 100

const int N = 100;

int main(){
    cout << "<<<<Hello>>>>" << endl;
    cout << " " << endl;
    string action;
    person_t PhoneBook[N];

    PhoneBookInit(PhoneBook);
    Menu(action, PhoneBook);

    return 0;
}

//void find(persot_t PhoneBook[], ...){
    // by phone
    // by sername
    // by name 
//}
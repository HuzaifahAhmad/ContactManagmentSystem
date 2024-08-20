// Build a program to manage contacts with features to add, delete, search, and display contacts.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct contact {
    char name[100];
    int phoneNumber;
};

typedef struct contact Contact;

void displayContactArray(Contact array[], int arraySize) {

    for (int i = 0; i < arraySize ; i++) 
    {
        printf("Name: %s, Phone Number: %d\n", array[i].name, array[i].phoneNumber);
    }

};

void flush_input() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
 

Contact addContact(Contact *newContact) {
    printf("\n");
    printf("Enter Contact Name: ");
    fgets(newContact->name, 50, stdin);

    printf("Enter Contact Phone Number: ");
    scanf("%d", &newContact->phoneNumber);

    flush_input();
    return *newContact;
};


int main() {

    printf("WELCOME TO THE CONTACT MANAGEMENT SYSTEM!\n");

    // hardcoded variables to test
    Contact c1 = { "John Wick", 519 };
    Contact c2 = { "US MAN", 647 };

    // contact storage
    Contact contactsArray[] = {c1, c2};



    // size array
    int contactsArrayLength = sizeof(contactsArray)/sizeof(contactsArray[0]); 
    printf("array length: %d\n", contactsArrayLength);

    // working on add functionality
    Contact c3;
    Contact *c3ptr = &c3;
    addContact(c3ptr);

    Contact c4;
    Contact *c4ptr = &c4;
    addContact(c4ptr);
    
    Contact *a = malloc( sizeof(Contact) * 2 ); 

    a[0] = *c3ptr;
    a[1] = *c4ptr;
    for (int i = 0; i < 2; i++) {printf("Name: %s, Phone Number: %d\n", a[i].name , a[i].phoneNumber);};

    

    free(a);
    // display all contacts
    printf("\n");
    displayContactArray(contactsArray, contactsArrayLength);

    return 0;
};


// Build a program to manage contacts with features to add, delete, search, and display contacts.

#include <stdio.h>
#include <string.h>

struct contact {
    char name[100];
    int phoneNumber;
};

typedef struct contact Contact;

void displayContactArray(Contact array[], int arraySize) {
    
    printf("Test: %d\n", arraySize);

    for (int i = 0; i < arraySize ; i++) 
    {
        printf("Name: %s, Phone Number %d\n", array[i].name, array[i].phoneNumber);
    }

};




int main() {

    printf("WELCOME TO THE CONTACT MANAGEMENT SYSTEM!\n");

    // hardcoded variables to test
    Contact c1 = { "John Wick", 519 };
    Contact c2 = { "US MAN", 647 };

    Contact contactsArray[] = {c1, c2};

    int contactsArrayLength = sizeof(contactsArray)/sizeof(contactsArray[0]); // 1
    printf("%d\n", contactsArrayLength);

    displayContactArray(contactsArray, contactsArrayLength);

    return 0;
};


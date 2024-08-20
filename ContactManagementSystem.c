#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct contact {
    char name[100];
    char phoneNumber[100];
};

typedef struct contact Contact;

void displayContactArray(Contact array[], int arraySize) {

    for (int i = 0; i < arraySize ; i++) 
    {
        printf("Name: %s, Phone Number: %s\n", array[i].name, array[i].phoneNumber);
    }

};

void flush_input() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
 

Contact addNewContact(Contact *newContact) {
    printf("\n");
    printf("Enter Contact Name: ");
    fgets(newContact->name, 50, stdin);

    printf("Enter Contact Phone Number: ");
    fgets(newContact->phoneNumber, 50, stdin);

    flush_input();
    return *newContact;
};


int main() {

    printf("WELCOME TO THE CONTACT MANAGEMENT SYSTEM!\n");

    // initializing malloc
    int size = 1;
    Contact *a = malloc( sizeof(Contact) * size ); 

    Contact c3;
    Contact *c3ptr = &c3;
    addNewContact(c3ptr);
    a[0] = *c3ptr;

    for (int i = 0; i < size; i++) {printf("\nName: %sPhone Number: %s\n", a[i].name , a[i].phoneNumber);};
    // add is chosen, realloc some memory
    
    a = realloc (a, sizeof(Contact) * (size + 1));
    Contact c4;
    Contact *c4ptr = &c4;
    addNewContact(c4ptr);
    a[1] = *c4ptr;
    size += 1;

    // display all contacts
    printf("\n");
    printf("DISPLAY ALL CONTACTS\n");

    for (int i = 0; i < size; i++) {printf("\nName: %sPhone Number: %s\n", a[i].name , a[i].phoneNumber);};
    free(a);

    return 0;
};


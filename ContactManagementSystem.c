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

}

void flush_input() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
 

Contact addNewContact(Contact *newContact) {
    printf("\n");

    printf("Enter Name: ");
    fgets(newContact->name, 500, stdin);

    printf("Enter Phone Number: ");
    fgets(newContact->phoneNumber, 500, stdin);

    flush_input();
    return *newContact;
}


int main() {
    printf("\n");
    printf("WELCOME TO THE CONTACT MANAGEMENT SYSTEM!\n");

    // initializing malloc
    int size = 1;
    Contact *a = malloc( sizeof(Contact) * size ); 

    if (a == NULL) 
    {
        printf("Memory not Allocated\n");
        exit(0);
    }

    while (1) 
    {
        printf("Choose Option: Add Contact [1], Delete Contact [2], Search Contact [3], Display Contacts [4], Exit [5]\n");
        printf("Enter 1, 2, 3, 4, or 5: ");
        int userInput;
        scanf("%d", &userInput);
        flush_input();


        switch (userInput)
        {
        case 1:
            // add contacts 
            printf("\nADD CONTACT\n");

            Contact tempVariable;
            Contact *tempVariableptr = &tempVariable;

            // store contact information in temp variable
            addNewContact(tempVariableptr);

            // put the information in the allocated memory
            a[size - 1] = *tempVariableptr; 

            // increase size of memory by 1    
            a = realloc (a, sizeof(Contact) * (size + 1)); 

            if (a == NULL) 
            {
                printf("Memory not reallocated\n");
                exit(0);
            }

            size += 1; 

            // reset temp variable ptr
            tempVariableptr = NULL;
            break;
        
        case 2:
            printf("\nDELETE CONTACT\n");

            Contact deleteContact;
            Contact *deleteContactptr = &deleteContact;

            // gets input from the user
            printf("Enter Name: ");
            fgets(deleteContactptr->name, 500, stdin);

            printf("Enter Phone Number: ");
            fgets(deleteContactptr->phoneNumber, 500, stdin);

            flush_input();

            int deleteFound = 0;

            for (int i = 0; i < size - 1 ; i++) 
            {
                if (strcmp(a[i].name, deleteContactptr->name) == 0 && strcmp(a[i].phoneNumber, deleteContactptr->phoneNumber) == 0)
                {
                    printf("CONTACT DELETED:\n");


                    deleteFound = 1;
                    size -= 1;
                    break;     
                        
                } 
            };
            if (deleteFound == 0) 
            {
                printf("Contact was not found\n");
            }            

            break;
        
        case 3:
            printf("\nSEARCH CONTACT\n");

            Contact searchContact;
            Contact *searchContactptr = &searchContact;
            // gets input from the user
            printf("Enter Name: ");
            fgets(searchContactptr->name, 500, stdin);

            printf("Enter Phone Number: ");
            fgets(searchContactptr->phoneNumber, 500, stdin);

            flush_input();
            // check if a contains the contact information
            int searchFound = 0;

            for (int i = 0; i < size - 1 ; i++) 
            {
                if (strcmp(a[i].name, searchContactptr->name) == 0 && strcmp(a[i].phoneNumber, searchContactptr->phoneNumber) == 0)
                {
                    printf("CONTACT FOUND:\n");
                    printf("Name: %s", a[i].name);       
                    printf("Phone Number: %s", a[i].phoneNumber);
                    printf("\n");
                    searchFound = 1;
                    break;     
                        
                } 
            };
            if (searchFound == 0) 
            {
                printf("Contact was not found\n");
            }

            break;
        
        case 4:
            // display all contacts
            printf("\nDISPLAY ALL CONTACTS\n");
            for (int i = 0; i < size - 1; i++) 
            {
                printf("\nName: %s", a[i].name);
                printf("Phone Number: %s\n", a[i].phoneNumber);
            };
            break;

        case 5:
            // exit
            break;
        
        default:
            printf("Enter Valid Option\n");
        }

        if (userInput == 5) {
            printf("Thank you for using the Contact Management System\n");
            break;
        }
    }

    free(a);

    return 0;
};


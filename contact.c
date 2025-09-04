#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

void listContacts(AddressBook *addressBook) 
{
    if (addressBook->contactCount == 0)
    {
        printf("\nNo contacts found.\n");
        return;
    }

    printf("\033[1;36m"); 

    // Top border
    printf("+----+----------------------+--------------+-------------------------+\n");
    printf("\033[0m");
    // Header row
    printf("\033[1;35m");
    printf("| %-2s | %-20s | %-12s | %-23s |\n", "No", "Name", "Phone", "Email");
    printf("\033[0m");
    printf("\033[1;36m");
    // Separator
    printf("+----+----------------------+--------------+-------------------------+\n");
    printf("\033[0m");

    
    for (int i = 0; i < addressBook->contactCount - 1; i++)
    {
        for (int j = 0; j < addressBook->contactCount - i - 1; j++)
        {
            if (strcmp(addressBook->contacts[j].name, addressBook->contacts[j + 1].name) > 0)
            {
                Contact temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j + 1];
                addressBook->contacts[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        printf("| %-2d | %-20s | %-12s | %-23s |\n",
               i + 1,
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
               printf("\033[1;36m");
               printf("+----+----------------------+--------------+-------------------------+\n");
               printf("\033[0m");
    }
    
}
    
void initialize(AddressBook *addressBook) 
{
    addressBook->contactCount = 0;   // Start with zero contacts
    FILE* fptr = fopen("contacts.txt", "r"); 
    if (fptr == NULL)
    {
        printf("Unable to open file\n");
        return;
    }

    // Temporary variables to hold each field
    char name[100], phone[30], email[100];
    int i = 0;
    // Read line by line
    while (fscanf(fptr, "%99[^,],%29[^,],%99[^\n]\n", name, phone, email) == 3)
    {
        // Copy to the AddressBook structure
        strcpy(addressBook->contacts[i].name, name);
        strcpy(addressBook->contacts[i].phone, phone);
        strcpy(addressBook->contacts[i].email, email);
        i++;
    }
    addressBook->contactCount = i;

    fclose(fptr); 
}

void saveAndExit(AddressBook *addressBook) 
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
    
    if (addressBook->contactCount >= MAX_CONTACTS) 
    {
        printf("\033[1;31m");
        printf("Address book is full. Cannot add more contacts.\n");
        printf("\033[0m");
        return;
    }

	char temp[100];
    Contact *newContact = &addressBook->contacts[addressBook->contactCount];

    //For user entering a name 
    while(1)
    {
        printf("Enter the Name :");
        scanf(" %[^\n]", temp);
       

        if(is_valid_name(temp))
        {
            strcpy(newContact->name,temp);
            break;
        }
        else
        {
            printf("\033[1;31m");
            printf("Invalid Name! Only characters are allowed\n");
            printf("\033[0m");
        }

    }
    
    //For user entering a phone number 
    while(1)
    {
        printf("Enter a Mobile number : ");
        scanf(" %s", temp);
        getchar();

        if(!is_valid_phone(temp))
        {
            printf("\033[1;31m");
            printf("Invalid Phone number! Only digits are allowed\n");
            printf("\033[0m");
            continue;
        }

        if (is_phone_duplicate(addressBook, temp)) 
        {
            printf("\033[1;31m");
            printf("Phone number already exists in contacts! Please enter a different number.\n");
            printf("\033[0m");
            continue;
        }
        // If valid and not duplicate, copy the phone and break
        strcpy(newContact->phone, temp);
        break;
    }

    while(1)
    {
        printf("Enter a Email-ID : ");
        scanf(" %s", temp);

        if (is_email_duplicate(addressBook, temp)) 
        {
            printf("\033[1;31m");
            printf("Email is already exists in contacts! Please enter a different Email.id.\n");
            printf("\033[0m");
            continue;
        }

        if(is_valid_email(temp))
        {
            strcpy(newContact->email,temp);
            break;
        }
        else
        {
            printf("\033[1;31m");
            printf("Invalid E-Mail!\n");
            printf("\033[0m");
        }

    }
    addressBook->contactCount++;
    printf("\033[1;32m"); 
    printf("\nContact created successfully!!\n");
    printf("\033[0m");
	
    

    
}

void searchContact(AddressBook *addressBook) 
{
    

    int choice;
    char search[50];
    char again;
    

    while(1)
    {
        printf("\033[1;35m");
        printf("\n--#--Search Menu--#--\n");
        printf("\033[0m");
        printf("1.NAME\n");
        printf("2.PHONE NUMBER\n");
        printf("3.EMAIL\n");
        printf("4.EXIT FROM SEARCH MENU\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        int found = 0;

        switch(choice)
        {
           
            case 1:
                printf("Enter name to search: ");
                scanf(" %[^\n]",search);
                if (!is_valid_name(search)) 
                {
                    printf("\033[1;31m");
                    printf("Invalid name format.\n");
                    printf("\033[0m");
                    break;
                }
                printf("\033[1;35m");
                printf("\n----> Search Results <----\n");
                printf("\033[0m");
                  printf("\033[1;36m"); 

                // Top border
                printf("+----+----------------------+--------------+-------------------------+\n");
                printf("\033[0m");
                // Header row
                printf("\033[1;35m");
                printf("| %-2s | %-20s | %-12s | %-23s |\n", "No", "Name", "Phone", "Email");
                printf("\033[0m");
                printf("\033[1;36m");
                // Separator
                printf("+----+----------------------+--------------+-------------------------+\n");
                printf("\033[0m");
               
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (strncasecmp(addressBook->contacts[i].name, search, strlen(search)) == 0)  
                    {

                        printf("| %-2d | %-20s | %-12s | %-23s |\n",
                            i + 1,
                            addressBook->contacts[i].name,
                            addressBook->contacts[i].phone,
                            addressBook->contacts[i].email);
                            found = 1;
                            printf("\033[1;36m");
                            printf("+----+----------------------+--------------+-------------------------+\n");
                            printf("\033[0m");
                    }
                }
                if (found == 0)
                {
                    printf("No contact found with the name '%s'.\n", search);
                }
                break;

            case 2:
                printf("Enter Phone Number to search: ");
                scanf(" %[^\n]",search);
                if (!is_valid_phone(search)) 
                {
                    printf("\033[1;31m");
                    printf("Invalid Phone Number format.\n");
                    printf("\033[0m");
                    break;
                }
                printf("\n----> Search Results <----\n");
                // Top border
                printf("+----+----------------------+--------------+-------------------------+\n");
                printf("\033[0m");
                // Header row
                printf("\033[1;35m");
                printf("| %-2s | %-20s | %-12s | %-23s |\n", "No", "Name", "Phone", "Email");
                printf("\033[0m");
                printf("\033[1;36m");
                // Separator
                printf("+----+----------------------+--------------+-------------------------+\n");
                printf("\033[0m");

                 for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (strcmp(addressBook->contacts[i].phone, search) == 0) 
                    {

                        printf("| %-2d | %-20s | %-12s | %-23s |\n",
                            i + 1,
                            addressBook->contacts[i].name,
                            addressBook->contacts[i].phone,
                            addressBook->contacts[i].email);
                            found = 1;
                            printf("\033[1;36m");
                            printf("+----+----------------------+--------------+-------------------------+\n");
                            printf("\033[0m");
                    }
                }
                if (found == 0)
                {
                    printf("No contact found with the Phone Number '%s'.\n", search);
                }
                break;

            case 3:
            
                printf("Enter EMAIL - ID to search: ");
                scanf(" %[^\n]",search);
                if (!is_valid_email(search)) 
                {
                    printf("\033[1;31m");
                    printf("Invalid Email format.\n");
                    printf("\033[0m");
                    break;
                }
                printf("\n----> Search Results <----\n");
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (strcmp(addressBook->contacts[i].email, search) == 0)
                    {
                        printf("Name   : %s\n", addressBook->contacts[i].name);
                        printf("Phone  : %s\n", addressBook->contacts[i].phone);
                        printf("Email  : %s\n", addressBook->contacts[i].email);
                        printf("\n");
                        found = 1;
                    }
                }
                if (found == 0)
                {
                    printf("No contact found with the EMAIL-ID '%s'.\n", search);
                }
                break;
            
            case 4:
               printf("Exiting search menu...\n");
                return;
            
            default:
                printf("Please enter a valid choice (1-4).\n");
                break;


        }
        printf("\n");
        printf("Do you want to search again? (y/n): ");
        scanf(" %c", &again);
        getchar(); 

        if (again != 'y' && again != 'Y') 
        {
            break; 
        }
    }


}

void editContact(AddressBook *addressBook)
{
	

    int index, choice;
    char again = 'y';
    char phone[15];
    char email[50];
    char name[20];

    while (again == 'y' || again == 'Y')
    {
        printf("\nEdit Menu:\n");
        printf("1. Edit Name\n");
        printf("2. Edit Phone Number\n");
        printf("3. Edit Email-ID\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
 

        index = searchData( addressBook,choice);

        if (index >= 0 && index < addressBook->contactCount)
        {
            switch (choice)
            {
                case 1:
                    while (1)
                    {
                        printf("Enter new name:");
                        scanf(" %[^\n]", name);
                        getchar();

                        if (is_valid_name(name))
                            {
                                strcpy(addressBook->contacts[index].name, name);
                                break;
                            }
                            else
                            {
                                printf("Enter valid name.\n");
                            }
                    }
                        break;

                case 2:
                    while (1)
                    {
                        printf("Enter new phone number: ");
                        scanf(" %14[^\n]", phone);
                        getchar();

                        if (is_valid_phone(phone))
                        {
                            strcpy(addressBook->contacts[index].phone, phone);
                            break;
                        }
                        else
                        {
                            printf("\033[1;31m");
                            printf("Invalid phone number! Enter a 10-digit numeric phone number.\n");
                            printf("\033[0");
                        }
                    }
                    break;

                case 3:
                    while (1)
                    {
                        printf("Enter new Email-ID: ");
                        scanf(" %49[^\n]", email);  
                        getchar();

                        if (is_valid_email(email))
                        {
                            strcpy(addressBook->contacts[index].email, email);
                            break;
                        }
                        else
                        {
                            printf("\033[1;31m");
                            printf("Invalid Email-ID format! Please try again.\n");
                            printf("\033[0m");
                        }
                    }
                    break;

                default:
                    printf("Invalid choice! Please enter 1-4.\n");
                    continue;
            }

            printf("Edit Successful.\n");
        }
        else
        {
            printf("Contact not found.\n");
        }

        printf("Do you want to edit another contact? (y/n): ");
        scanf(" %c", &again);
    
    }

    printf("Exiting edit menu.\n");


    
}

void deleteContact(AddressBook *addressBook)
{
    int index, i, choice;
    char again = 'y';

    do
    {
        printf("\nDelete Menu:\n");
        printf("1. Delete by name\n");
        printf("2. Delete by phone number\n");
        printf("3. Delete by Email-ID\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        index = searchData( addressBook,choice);

        if (index >= 0 && index < addressBook->contactCount)
        {
            
            for (i = index; i < addressBook->contactCount - 1; i++)
            {
                addressBook->contacts[i] = addressBook->contacts[i + 1];
            }

            addressBook->contactCount--;  
            printf("\033[1;32m");
            printf("Contact deleted successfully.\n");
            printf("\033[0m");
        }
        else
        {
            printf("Contact not found.\n");
        }

        
        printf("Do you want to delete another contact? (y/n): ");
        scanf(" %c", &again);
        getchar();  

    } while (again == 'y' || again == 'Y');

    printf("Exiting delete menu.\n");
}

int is_valid_name(char *name)
{
    for (int i = 0; name[i] != '\0'; i++) 
    {
        if (!((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z') || name[i] == ' ')) 
        {
            return 0;
        }
    }
    return 1;
}

int is_valid_phone(char *phone) 
{
    int len = 0;

    for (int i = 0; phone[i] != '\0'; i++) 
    {
        if (phone[i] < '0' || phone[i] > '9')
        {
            return 0; 
        }
        len++;
    }

    if (len != 10) 
    {
        return 0; 
    }

    return 1;
}

int is_valid_email(char *email)
{
    int len = strlen(email);

    if (len < 6) 
        return 0;

    int at_count = 0;
    int at_pos = -1;
    for (int i = 0; i < len; i++) {
        if (email[i] == '@') {
            at_count++;
            at_pos = i;
        }
    }

    
    if (at_count != 1)
        return 0;

    if (at_pos == 0 || at_pos == len - 1)
        return 0;

    char *dot = strchr(email + at_pos + 1, '.');
    if (!dot)
        return 0;

    if (dot == email + len - 1)
        return 0;

    if (strcmp(email + len - 4, ".com") != 0)
        return 0;

    if (dot - (email + at_pos) < 2)
        return 0;

    if (at_pos < 1)
        return 0;

    if (len > 8) { 
        if (strcmp(email + len - 8, ".com.com") == 0)
            return 0;
    }

    return 1;
    
}


int searchData(AddressBook *addressBook, int choice)
{
    char search[100];
    int flag = 0;

    switch(choice)
    {
        case 1:  
            printf("Enter name to search: ");
            scanf("%[^\n]", search);

            for(int i = 0; i < addressBook->contactCount; i++)
            {
                if(strncasecmp(addressBook->contacts[i].name, search, strlen(search)) == 0)
                {
                    printf("------------------------------------------------------\n");
                    printf("%s\n",addressBook->contacts[i].name);
                    printf("%s\n",addressBook->contacts[i].phone);
                    printf("%s\n",addressBook->contacts[i].email);
                   
                    printf("------------------------------------------------------\n");
                    return i; 
                }
            }

            printf("Name not found!\n");
            return -1;

        case 2:  
            while(1)
            {
                printf("Enter phone number to search: ");
                scanf("%s", search);

                
                if (!is_valid_phone(search)) 
                {
                    printf("\033[1;31m");
                    printf("Invalid phone number format. Try again.\n");
                    printf("\033[0m");
                    continue;  
                }

                for(int i = 0; i < addressBook->contactCount; i++)
                {
                    if(strcmp(addressBook->contacts[i].phone, search) == 0)
                    {
                        printf("------------------------------------------------------\n");

                        printf("%s\n",addressBook->contacts[i].name);
                        printf("%s\n",addressBook->contacts[i].phone);
                        printf("%s\n",addressBook->contacts[i].email);

                        printf("------------------------------------------------------\n");
                        return i;
                    }
                }

                printf("Phone number not found!\n");
                return -1;
            }

        case 3:  
            while(1)
            {
                printf("Enter email to search: ");
                scanf("%s", search);

              
                if (!is_valid_email(search))
                {
                    printf("\033[1;31m");
                    printf("Invalid email format. Try again.\n");
                    printf("\033[0m");
                    continue; 
                }

                for(int i = 0; i < addressBook->contactCount; i++)
                {
                    if(strcmp(addressBook->contacts[i].email, search) == 0)
                    {
                        printf("------------------------------------------------------\n");
                        printf("%s\n",addressBook->contacts[i].name);
                        printf("%s\n",addressBook->contacts[i].phone);
                        printf("%s\n",addressBook->contacts[i].email);
                        printf("------------------------------------------------------\n");
                        return i;
                    }
                }

                printf("Email not found!\n");
                return -1;
            }

        

        default:
            printf("Invalid choice for search!\n");
            return -1;
    }
}
void saveContactsToFile(AddressBook *addressBook) 
{
    FILE* fptr = fopen("contacts.txt", "w"); 
    if (fptr == NULL)
    {
        printf("Unable to open file\n");
        return;
    }

    int count = addressBook->contactCount;

    for (int i = 0; i < count; i++) 
    {
       
        fprintf(fptr, "%s", addressBook->contacts[i].name);
        fputc(',', fptr);

        
        fprintf(fptr, "%s", addressBook->contacts[i].phone);
        fputc(',', fptr);

        
        fprintf(fptr, "%s", addressBook->contacts[i].email);
        fputc('\n', fptr);

    }

    fclose(fptr); 
    
}
int is_phone_duplicate(AddressBook *addressBook,const char *phone) {
    for (int i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(addressBook->contacts[i].phone, phone) == 0) {
            return 1;  // Duplicate found
        }
    }
    return 0;  // No duplicate
}

int is_email_duplicate(AddressBook *addressBook,const char *mail) {
    for (int i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(addressBook->contacts[i].email, mail) == 0) {
            return 1;  // Duplicate found
        }
    }
    return 0;  // No duplicate
}
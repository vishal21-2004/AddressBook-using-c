#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the chosen criteria
    int size =addressBook->contactCount; // for the size we incremented contactCount wiil be use
    int flag=0;
    int choice;
    char name[50];
    char phonenumber[90];
    char email[98];
    Contact temp;
    /* Define the logic for sorting the details */
    printf("1. Sort by name\n");
    printf("2. Sort by phonenumber\n");
    printf("3. Sort by email\n");
    printf("Enter the choice: ");
    scanf("%d",&choice);
    getchar();
    switch (choice)
    {
     case 1:
         for(int i=0;i<size-1;i++){
             for(int j=0;j<size-i-1;j++){
                 if(strcmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name)>0)
                 {
                   //copy entire structure
                   temp=addressBook->contacts[j];
                   addressBook->contacts[j]=addressBook->contacts[j+1];
                   addressBook->contacts[j+1]=temp;
            }
        }
       }
    break;

    case 2:
        for(int i=0;i<size-1;i++){
             for(int j=0;j<size-i-1;j++){
                 if(strcmp(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone)>0)
                 {
                   //copy entire structure
                   temp=addressBook->contacts[j];
                   addressBook->contacts[j]=addressBook->contacts[j+1];
                   addressBook->contacts[j+1]=temp;
            }
        }
       }
    break;
    case 3:
        for(int i=0;i<size-1;i++){
             for(int j=0;j<size-i-1;j++){
                 if(strcmp(addressBook->contacts[j].email,addressBook->contacts[j+1].email)>0)
                 {
                   //copy entire structure
                   temp=addressBook->contacts[j];
                   addressBook->contacts[j]=addressBook->contacts[j+1];
                   addressBook->contacts[j+1]=temp;
            }
        }
       }
    break;
}
    for(int i=0;i<size;i++){
        printf("%s   %s   %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
}

    
    


void initialize(AddressBook *addressBook) {
   // addressBook->contactCount = 0;
   // populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

int check_phoneno(AddressBook *addressbook,char *phone)
{
    for (int i = 0; i < addressbook->contactCount; i++)
    {
        if (strcmp(phone,addressbook->contacts[i].phone)==0)
        {
            return 0;
        }
        
    }
    return 1;
    
}

void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    /*
    read new name 
    read new number 
    read new email id 
    */
   char name[20],phone[20],email[50];
    int len;  
    getchar();

   printf("Enter the name: \n");
   scanf("%[^\n]",name);
   getchar();

   do
   {
    printf("Enter the phone number: \n");
   scanf("%s",phone);
   len=strlen(phone);
   if (len !=10)
   {
    printf("ERROE: Please enter the 10 digit number\n");
   }
   else
   {
         if(check_phoneno(addressBook,phone)==0)
         {
         printf("the phone number is already present ,so we can't add this contact\n");
         len = 0;// it check while loop then again take the phone number as an input   
         }
   }
   
   getchar();
   } while (len != 10);
   
   
/*
   check @, .com
   if not present then read email id again
   */
  do
{
    printf("Enter the email: \n");
    scanf("%s", email);

    if (strstr(email, "@") == NULL || strstr(email, ".com") == NULL)
    {
        printf("ERROR: Please enter a valid email ID\n");
    }

} while (strstr(email, "@") == NULL || strstr(email, ".com") == NULL);

//if substring is not found then it return the NULL
//when both is false then the email is accepted
   /*
   check @, .com
   if not present then read email id again
   */

   strcpy(addressBook->contacts[addressBook->contactCount].name,name);
   strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);
   strcpy(addressBook->contacts[addressBook->contactCount].email,email);
   (addressBook->contactCount)++;
    
}

//.......................................................................................//

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int choice,flag=0;
    char name[50];
    char phone[20];
    char email[50];
    printf("1. Search by name\n");
    printf("2. Search by phone_number\n");
    printf("3. Search by email:\n");
    printf("Enter the choice :\n");
    scanf("%d",&choice);
    getchar();

    switch (choice)
    {
    case 1 : printf("Enter the name: ");
             scanf("%[^\n]",name);
             for (int i = 0; i < addressBook->contactCount; i++)
             {
                if ((strcmp(name,addressBook->contacts[i].name))==0)
                {
                      printf("%s  %s  %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                      flag = 1;
                }
                
             }
             if (flag==0)
             {
                printf("Name is not present in the contact book");
             }
        break;
    case 2 :printf("Enter the phone number: ");
             scanf("%[^\n]",phone);
             for (int i = 0; i < addressBook->contactCount; i++)
             {
                if ((strcmp(phone,addressBook->contacts[i].phone))==0)
                {
                      printf("%s  %s  %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                      flag = 1;
                }
                
             }
             if (flag==0)
             {
                printf("phone number is not present in the contact book");
             }
            

        break;
    case 3 :printf("Enter the email: ");
             scanf("%[^\n]",email);
             for (int i = 0; i < addressBook->contactCount; i++)
             {
                if ((strcmp(email,addressBook->contacts[i].email))==0)
                {
                      printf("%s  %s  %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                      flag = 1;
                }
                
             }
             if (flag==0)
             {
                printf("email is not present in the contact book");
             }

        break;
    
    default:
            
        break;
    }
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
     int option,index,flag=0;
    char name[86], phone[20], email[80];
	printf("Select the contact : \n");
    printf("1. search by name: \n");
    printf("2. search by phone number: \n");
    printf("3. search by email id: \n");
    printf("Enter the option: ");
    scanf("%d",&option);
    switch (option)
    {
    case 1:
     do{
        printf("Enter the name : ");
        getchar();
        scanf("%[^\n]", name);
         flag = 0;       // reset flag
        for(int i=0;i<addressBook->contactCount;i++){
            if((strcmp(name, addressBook->contacts[i].name))==0){
                
                index=i;//if the already present then it gives the index and edit it
                flag=1;
                break;
            }
        }
        if(flag==0){
        printf("The name is not present in the contact book, enter the correct one\n");
        }
      }while(flag==0);


        break;

        case 2:
        do{
        printf("Enter the phone number : ");
        getchar();
        scanf("%[^\n]", phone);
         flag = 0;       // reset flag
        for(int i=0;i<addressBook->contactCount;i++){
            if((strcmp(phone, addressBook->contacts[i].phone))==0){
                
                index=i;//if the already present then it gives the index and edit it
                flag=1;
                break;
            }
        }
        if(flag==0){
        printf("The phone number is not present in the contact book, enter the correct one\n");
        }
      }while(flag==0);
        break;

        case 3:
        do{
        printf("Enter the email id : ");
        getchar();
        scanf("%[^\n]", email);
         flag = 0;       // reset flag
        for(int i=0;i<addressBook->contactCount;i++){
            if((strcmp(email, addressBook->contacts[i].email))==0){
                
                index=i;//if the already present then it gives the index and edit it
                flag=1;
                break;
            }
        }
        if(flag==0){
        printf("The email is not present in the contact book, enter the correct one\n");
        }
      }while(flag==0);
        break;
    
    }
    //ask the user which you want to edit beacause index consist of name, phone_number,email_id 
    printf("1.Edit the name: \n");
    printf("2.Edit the phone number: \n");
    printf("3.Edit the email id: \n");
    printf("Enter the option : ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        printf("Enter the new name : ");
        getchar();
        scanf("%[^\n]",name);
        strcpy(addressBook->contacts[index].name,name);

        break;
    case 2:
        printf("Enter the new phone number : ");
        getchar();
        scanf("%[^\n]",phone);
        strcpy(addressBook->contacts[index].phone,phone);

    break;

    case 3:
        printf("Enter the new email id : ");
        getchar();
        scanf("%[^\n]",email);
        strcpy(addressBook->contacts[index].email,email);

    break;
    }
    
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
   int option,index,flag=0;
    char name[86], phone[20], email[80];
	printf("Select the contact : \n");
    printf("1. search by name: \n");
    printf("2. search by phone number: \n");
    printf("3. search by email id: \n");
    printf("Enter the option: ");
    scanf("%d",&option);
    switch (option)
    {
    case 1:
     do{
        printf("Enter the name : ");
        getchar();
        scanf("%[^\n]", name);
         flag = 0;       // reset flag
        for(int i=0;i<addressBook->contactCount;i++){
            if((strcmp(name, addressBook->contacts[i].name))==0){
                
                index=i;//if the already present then it gives the index and edit it
                flag=1;
                break;
            }
        }
        if(flag==0){
        printf("The name is not present in the contact book, enter the correct one\n");
        }
      }while(flag==0);


        break;

        case 2:
        do{
        printf("Enter the phone number : ");
        getchar();
        scanf("%[^\n]", phone);
         flag = 0;       // reset flag
        for(int i=0;i<addressBook->contactCount;i++){
            if((strcmp(phone, addressBook->contacts[i].phone))==0){
                
                index=i;//if the already present then it gives the index and edit it
                flag=1;
                break;
            }
        }
        if(flag==0){
        printf("The phone number is not present in the contact book, enter the correct one\n");
        }
      }while(flag==0);
        break;

        case 3:
        do{
        printf("Enter the email id : ");
        getchar();
        scanf("%[^\n]", email);
         flag = 0;       // reset flag
        for(int i=0;i<addressBook->contactCount;i++){
            if((strcmp(email, addressBook->contacts[i].email))==0){
                
                index=i;//if the already present then it gives the index and edit it
                flag=1;
                break;
            }
        }
        if(flag==0){
        printf("The email is not present in the contact book, enter the correct one\n");
        }
      }while(flag==0);
        break;
    
    }

 for(int i=index;i<addressBook->contactCount;i++)
{
 addressBook->contacts[i]=addressBook->contacts[i+1];
}
(addressBook->contactCount)--;
}

#include <stdio.h>
#include "file.h"
#include<stdlib.h>
#include<string.h>

void saveContactsToFile(AddressBook *addressBook)
{
   FILE *fptr = fopen("contact.txt","w");
    // Sort contacts based on the chosen criteria

    int size =addressBook->contactCount;
    fprintf(fptr,"#%d#\n",size);//gives number of contacts

    for (int i = 0; i < size; i++)
    {
     fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fptr);
}

void loadContactsFromFile(AddressBook *addressBook) 
{
char str[100];
    FILE *fptr = fopen("contact.txt","r");
    if(fptr==NULL){
        printf("file is not present\n");
    }
    else{
          fscanf(fptr,"%[^\n]",str);
          int size = atoi(strtok(&str[1], "#"));//atoi for an integer because it befor it is integer
          addressBook->contactCount=size;      //for the size

          for (int i = 0; i < size; i++)// for the copy
          {
            fscanf(fptr," %[^\n]",str);
            strcpy(addressBook->contacts[i].name, strtok(str,","));
            strcpy(addressBook->contacts[i].phone, strtok(NULL,","));
            strcpy(addressBook->contacts[i].email, strtok(NULL,","));
          }
          
    }    
}

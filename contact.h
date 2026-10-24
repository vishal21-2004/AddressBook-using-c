#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100 //It means the Address Book can store a maximum of 100 contacts.

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;             // Contact is UDT

typedef struct {
    Contact contacts[MAX_CONTACTS];//it is the array of structure  
    //This means contacts is an array of 100 Contact structures.
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);

#endif

//
// Created by kenza on 09/12/2023.
//

#ifndef PROJETC_S3_FINAL_CONTACT_H
#define PROJETC_S3_FINAL_CONTACT_H

#include "appointments.h"

typedef struct s_contact
{
    char *name;
    appointment **myAppointments;
    int nb_levels;
    int nb_appointments;
    struct s_contact **next;
} contact;
typedef struct s_contact_list
{
    int nb_contacts;
    contact **heads;
} contact_list;
char* LowerCase(char* str);
// takes a string and returns it in lowercase
int compareStrings(const void* a, const void* b);
// compares two strings
char* generateRandomFullName();
// generates a random full name out of a list of first names and a list of last names
char* NewName();
// allows user to enter a new name converts it in the right format
contact *contact_creation(char* fullname, int levels, int appointments);
// allows us to create a contact with a given name, number of levels and number of appointments
contact_list* createFullNameList();
// creates a list of contacts with random names
void displayLevelContact(contact_list* list, int level);
// displays the contacts of a given level using the list format taught in class
void displayAllContacts(contact_list* list);
// displays all the contacts of a given list using the displayLevelContact function
void deleteContact(contact_list* list, char* name);
// deletes a contact from a given list
void initializeContactList(contact_list* list);
// adds a contact from txt file to a given list using the contact_creation function
contact *searchContact( char* name);
// searches for a contact in a given list using the name of the contact and returns a pointer to it
void insertContact(contact_list* list, contact* myContact);
// inserts a contact in a given list
#endif //PROJETC_S3_FINAL_CONTACT_H
//
// Created by kenza on 09/12/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "timer.h"
#include "contact.h"
#include "appointments.h"
#include "string.h"

int main() {
    contact_list* myContactList = createFullNameList();

    int choice;

    do {
        printf("\nDiary Management Application\n");
        printf("1. Search for a contact\n");
        printf("2. View a contact's appointments\n");
        printf("3. Create a contact\n");
        printf("4. Create an appointment for a contact\n");
        printf("5. Delete an appointment\n");
        printf("6. Save the file of all appointments\n");
        printf("7. Load an appointment file\n");
        printf("8. Exit\n");

        printf("Enter your choice (1-8): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[50];
                printf("\nEnter the name to search: ");
                scanf("%s", name);
                contact* foundContact = searchContact(name);
                if (foundContact != NULL) {
                    printf("Contact found: %s\n", foundContact->name);
                } else {
                    printf("Contact not found.\n");
                }
                break;
            }
            case 2: {
                char name[50];
                printf("\nEnter the name to view appointments: ");
                scanf("%s", name);
                contact* foundContact = searchContact(name);
                if (foundContact != NULL) {
                    displayAppointments(foundContact);
                } else {
                    printf("Contact not found.\n");
                }
                break;
            }
            case 3: {
                char* newContactName = NewName();
                contact* newContact = contact_creation(newContactName, 4, 0);
                insertContact(myContactList, newContact);
                printf("Contact created successfully.\n");
                break;
            }
            case 4: {
                char name[50];
                printf("\nEnter the name for the appointment: ");
                scanf("%s", name);
                contact* foundContact = searchContact(name);
                if (foundContact != NULL) {
                    int day, month, year, hour, lengthMinute;
                    char purpose[100];
                    printf("Enter appointment details:\n");
                    printf("Day (1-31): ");
                    scanf("%d", &day);
                    printf("Month (1-12): ");
                    scanf("%d", &month);
                    printf("Year: ");
                    scanf("%d", &year);
                    printf("Hour (0-23): ");
                    scanf("%d", &hour);
                    printf("Length (in minutes): ");
                    scanf("%d", &lengthMinute);
                    printf("Purpose: ");
                    scanf("%s", purpose);

                    appointment* newAppointment = createAppointment(day, month, year, hour, lengthMinute, purpose, foundContact->name);
                    addAppointmentToContact(foundContact, newAppointment);
                    printf("Appointment created successfully.\n");
                } else {
                    printf("Contact not found.\n");
                }
                break;
            }
            case 5: {
                char name[50];
                printf("\nEnter the name for the appointment: ");
                scanf("%s", name);
                contact* foundContact = searchContact(name);
                if (foundContact != NULL) {
                    displayAppointments(foundContact);
                    int index;
                    printf("Enter the index of the appointment to delete: ");
                    scanf("%d", &index);
                    if (index >= 0 && index < foundContact->nb_appointments) {
                        deleteAppointment(foundContact, foundContact->myAppointments[index]);
                        printf("Appointment deleted successfully.\n");
                    } else {
                        printf("Invalid index.\n");
                    }
                } else {
                    printf("Contact not found.\n");
                }
                break;
            }
            case 6: {
                char name[50];
                printf("\nEnter the name to save appointments: ");
                scanf("%s", name);
                saveFileAppointments(name);
                printf("Appointments saved successfully.\n");
                break;
            }
            case 7: {
                char name[50];
                printf("\nEnter the name to load appointments: ");
                scanf("%s", name);
                loadFileAppointments(name);
                printf("Appointments loaded successfully.\n");
                break;
            }
            case 8: {
                // Exit the program
                printf("\nExiting Diary Management Application. Goodbye!\n");
                break;
            }
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 8.\n");
        }
    } while (choice != 8);

    return 0;
}



/*
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "timer.h"
#include "contact.h"
#include "appointments.h"
#include "string.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h> // This is used for getch() function on Windows, for Linux use #include <curses.h>

#include "contact.h"
#include "appointments.h"

int main() {
    contact_list* myContactList = createFullNameList();

    while (1) {
        printf("\nDiary Management Application\n");
        printf("1. Search for a contact\n");
        printf("2. View a contact's appointments\n");
        printf("3. Create a contact\n");
        printf("4. Create an appointment for a contact\n");
        printf("5. Delete an appointment\n");
        printf("6. Save the file of all appointments\n");
        printf("7. Load an appointment file\n");
        printf("8. Exit\n");

        printf("Enter your choice (1-8): ");
        char choice = getch();

        switch (choice) {
            case '1': {
                printf("\nEnter the name to search: ");
                char name[50];
                scanf("%s", name);
                contact* foundContact = searchContact(name);
                if (foundContact != NULL) {
                    printf("Contact found: %s\n", foundContact->name);
                } else {
                    printf("Contact not found.\n");
                }
                break;
            }
            case '2': {
                printf("\nEnter the name to view appointments: ");
                char name[50];
                scanf("%s", name);
                contact* foundContact = searchContact(name);
                if (foundContact != NULL) {
                    displayAppointments(foundContact);
                } else {
                    printf("Contact not found.\n");
                }
                break;
            }
            case '3': {
                char* newContactName = NewName();
                contact* newContact = contact_creation(newContactName, 4, 0);
                insertContact(myContactList, newContact);
                printf("Contact created successfully.\n");
                break;
            }
            case '4': {
                printf("\nEnter the name for the appointment: ");
                char name[50];
                scanf("%s", name);
                contact* foundContact = searchContact(name);
                if (foundContact != NULL) {
                    int day, month, year, hour, lengthMinute;
                    char purpose[100];
                    printf("Enter appointment details:\n");
                    printf("Day (1-31): ");
                    scanf("%d", &day);
                    printf("Month (1-12): ");
                    scanf("%d", &month);
                    printf("Year: ");
                    scanf("%d", &year);
                    printf("Hour (0-23): ");
                    scanf("%d", &hour);
                    printf("Length (in minutes): ");
                    scanf("%d", &lengthMinute);
                    printf("Purpose: ");
                    scanf("%s", purpose);

                    appointment* newAppointment = createAppointment(day, month, year, hour, lengthMinute, purpose, foundContact->name);
                    addAppointmentToContact(foundContact, newAppointment);
                    printf("Appointment created successfully.\n");
                } else {
                    printf("Contact not found.\n");
                }
                break;
            }
            case '5': {
                printf("\nEnter the name for the appointment: ");
                char name[50];
                scanf("%s", name);
                contact* foundContact = searchContact(name);
                if (foundContact != NULL) {
                    displayAppointments(foundContact);
                    printf("Enter the index of the appointment to delete: ");
                    int index;
                    scanf("%d", &index);
                    if (index >= 0 && index < foundContact->nb_appointments) {
                        deleteAppointment(foundContact, foundContact->myAppointments[index]);
                        printf("Appointment deleted successfully.\n");
                    } else {
                        printf("Invalid index.\n");
                    }
                } else {
                    printf("Contact not found.\n");
                }
                break;
            }
            case '6': {
                printf("\nEnter the name to save appointments: ");
                char name[50];
                scanf("%s", name);
                saveFileAppointments(name);
                printf("Appointments saved successfully.\n");
                break;
            }
            case '7': {
                printf("\nEnter the name to load appointments: ");
                char name[50];
                scanf("%s", name);
                loadFileAppointments(name);
                printf("Appointments loaded successfully.\n");
                break;
            }
            case '8': {
                // Exit the program
                printf("\nExiting Diary Management Application. Goodbye!\n");
                return 0;
            }
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 8.\n");
        }

    }

    return 0;
}



#define maxlevel 1000

int main() {
    int option;
    int running = 1;
    contact_list *contacts = createFullNameList;
    initializeContactList(contacts);
    while (running) {
        printf("1. Search for a contact: \n");
        printf("2. View a contact's appointments: \n");
        printf("3. Create a contact\n");
        printf("4. Create an appointment for a contact: \n");
        printf("5. Delete an appointment: \n");
        printf("6. Delete a contact: \n");
        printf("7. Save the file of all appointments: \n");
        printf("8. Load an appointment fil: \n");
        printf("9. Provide calculation times for inserting a new contact : \n");
        scanf("%d", &option);
        switch (option) {
            case 1: {
                char *name = NewName();
                contact *myContact = searchContact( name);
                if (myContact != NULL) {
                    printf("Contact found.\n");
                } else {
                    printf("Contact not found.\n");
                }
                break;
            }
            case 2: {
                char *name = NewName();
                contact *myContact = searchContact(name);
                if (myContact != NULL) {
                    displayAppointments(myContact);
                } else {
                    printf("Contact not found.\n");
                }
                break;
            }
            case 3: {
                char *name = NewName();
                int levels;
                int appointments;
                printf("Enter the number of levels: ");
                scanf("%d", &levels);
                printf("Enter the number of appointments: ");
                scanf("%d", &appointments);
                contact *myContact = contact_creation(name, levels, appointments);
                insertContact(contacts, myContact);
                break;
            }
            case 4: {
                char *name = NewName();
                contact *myContact = searchContact(name);
                if (myContact != NULL) {
                    int day;
                    int month;
                    int year;
                    int hour;
                    int lengthMinute;
                    char *purpose = (char *) malloc(100 * sizeof(char));
                    printf("Enter the day of the appointment: ");
                    scanf("%d", &day);
                    printf("Enter the month of the appointment: ");
                    scanf("%d", &month);
                    printf("Enter the year of the appointment: ");
                    scanf("%d", &year);
                    printf("Enter the hour of the appointment: ");
                    scanf("%d", &hour);
                    printf("Enter the length of the appointment: ");
                    scanf("%d", &lengthMinute);
                    printf("Enter the purpose of the appointment: ");
                    scanf("%s", purpose);
                    appointment *myAppointment = createAppointment(day, month, year, hour, lengthMinute, purpose, name);
                    addAppointmentToContact(myContact, myAppointment);
                } else {
                    printf("Contact not found.\n");
                }
                break;
            }
            case 5: {
                char *name = NewName();
                contact *myContact = searchContact(name);
                if (myContact != NULL) {
                    int day;
                    int month;
                    int year;
                    int hour;
                    int lengthMinute;
                    char *purpose = (char *) malloc(100 * sizeof(char));
                    printf("Enter the day of the appointment: ");
                    scanf("%d", &day);
                    printf("Enter the month of the appointment: ");
                    scanf("%d", &month);
                    printf("Enter the year of the appointment: ");
                    scanf("%d", &year);
                    printf("Enter the hour of the appointment: ");
                    scanf("%d", &hour);
                    printf("Enter the length of the appointment: ");
                    scanf("%d", &lengthMinute);
                    printf("Enter the purpose of the appointment: ");
                    scanf("%s", purpose);
                    appointment *myAppointment = createAppointment(day, month, year, hour, lengthMinute, purpose, name);
                    deleteAppointment(myContact, myAppointment);
                } else {
                    printf("Contact not found.\n");
                }
                break;
            }
            case 6: {
                char *name = NewName();
                deleteContact(contacts, name);
                break;
            }
            case 7: {
                char *filename = (char *) malloc(50 * sizeof(char));
                printf("Enter the name of the file: ");
                scanf("%s", filename);
                saveFileAppointments(filename);
                break;
            }
            case 8: {
                char *filename = (char *) malloc(50 * sizeof(char));
                printf("Enter the name of the file: ");
                scanf("%s", filename);
                loadFileAppointments(filename);
                break;
            }
            default: {
                printf("Invalid option, please try again.\n");
                break;
            }
        }

    }



    return 0;
}
*/
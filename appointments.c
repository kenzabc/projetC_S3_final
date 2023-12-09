//
// Created by kenza on 09/12/2023.
//

#include "appointments.h"
#include "contact.h"
#include <stdlib.h>
#include <stdio.h>
#include "string.h"


appointment *createAppointment(int day, int month, int year, int hour, int lengthMinute, char *purpose, char *owner){
    appointment *myAppointment = (appointment*)malloc(sizeof(appointment));
    myAppointment->DateDay = day;
    myAppointment->DateMonth = month;
    myAppointment->DateYear = year;
    myAppointment->TimeHour = hour;
    myAppointment->LengthMinute = lengthMinute;
    myAppointment->Purpose = purpose;

    insertAppointmentAtBeginning(myAppointment, owner);
    return myAppointment;
}
void insertAppointmentAtBeginning(appointment *myAppointment, char *owner){
    char *filename = (char*)malloc(strlen(owner) + 15);  // Increased buffer size to accommodate "appointments/" and ".txt"
    sprintf(filename, "appointments/%s.txt", owner);

    FILE *file = fopen(filename, "a+");

    if (file != NULL) {
        fseek(file, 0, SEEK_SET);  // Move to the beginning of the file

        fprintf(file, "%d/%d/%d %d:%d %d %s\n",
                myAppointment->DateDay, myAppointment->DateMonth, myAppointment->DateYear,
                myAppointment->TimeHour, myAppointment->TimeMinute,
                myAppointment->LengthMinute, myAppointment->Purpose);

        fclose(file);
    } else {
        printf("Error opening file.\n");
    }

    free(filename);
}
void addAppointmentToContact(contact *myContact, appointment *newAppointment){
    myContact->myAppointments[myContact->nb_appointments] = newAppointment;
    myContact->myAppointments = (appointment**)realloc(myContact->myAppointments, myContact->nb_appointments * sizeof(appointment*));
    myContact->nb_appointments++;
}
void displayAppointment(appointment *myAppointment){
    printf("Date: %d/%d/%d\n", myAppointment->DateDay, myAppointment->DateMonth, myAppointment->DateYear);
    printf("Time: %d:%d\n", myAppointment->TimeHour, myAppointment->TimeMinute);
    printf("Length: %d\n", myAppointment->LengthMinute);
    printf("Purpose: %s\n", myAppointment->Purpose);
}
void displayAppointments(contact *myContact) {
    printf("Appointments for %s:\n", myContact->name);
    if (myContact->nb_appointments != 0) {
        for (int i = 0; i < myContact->nb_appointments; i++) {
            displayAppointment(myContact->myAppointments[i]);
        }
    } else {
        printf("No appointments found.\n");
    }
}
void displayFileAppointments(char* fullname){
    char *filename = (char*)malloc(strlen(fullname) + 15);  // Increased buffer size to accommodate "appointments/" and ".txt"
    sprintf(filename, "appointments/%s.txt", fullname);

    FILE *file = fopen(filename, "r");

    if (file != NULL) {
        char line[50];
        while (fgets(line, sizeof(line), file)) {
            line[strcspn(line, "\n")] = '\0';
            printf("%s\n", line);
        }
        fclose(file);
    } else {
        printf("No appointments under that name.\n");
    }

    free(filename);
}
void loadFileAppointments( char* fullname){
    char *filename = (char*)malloc(strlen(fullname) + 15);  // Increased buffer size to accommodate "appointments/" and ".txt"
    sprintf(filename, "appointments/%s.txt", fullname);

    FILE *file = fopen(filename, "r");

    if (file != NULL) {
        char line[50];
        while (fgets(line, sizeof(line), file)) {
            line[strcspn(line, "\n")] = '\0';
            char *purpose = (char*)malloc(100 * sizeof(char));
            int day;
            int month;
            int year;
            int hour;
            int lengthMinute;
            sscanf(line, "%d/%d/%d %d:%d %d %s", &day, &month, &year, &hour, &lengthMinute, purpose);
            appointment *myAppointment = createAppointment(day, month, year, hour, lengthMinute, purpose, fullname);
            free(purpose);
        }
        fclose(file);
    } else {
        printf("No appointments under that name.\n");
    }

    free(filename);
}
void deleteAppointment(contact *myContact, appointment *myAppointment){
    int i = 0;
    while (i < myContact->nb_appointments && myContact->myAppointments[i] != myAppointment) {
        i++;
    }
    if (i == myContact->nb_appointments) {
        printf("Appointment not found.\n");
    }
    else {
        appointment* temp = myContact->myAppointments[i];
        myContact->myAppointments[i] = myContact->myAppointments[i + 1];
        free(temp);
    }
}
void saveFileAppointments(char* fullname){
    char *filename = (char*)malloc(strlen(fullname) + 15);  // Increased buffer size to accommodate "appointments/" and ".txt"
    sprintf(filename, "appointments/%s.txt", fullname);

    FILE *file = fopen(filename, "w");

    if (file != NULL) {
        contact *myContact = searchContact(fullname);
        if (myContact != NULL) {
            for (int i = 0; i < myContact->nb_appointments; i++) {
                fprintf(file, "%d/%d/%d %d:%d %d %s\n",
                        myContact->myAppointments[i]->DateDay, myContact->myAppointments[i]->DateMonth, myContact->myAppointments[i]->DateYear,
                        myContact->myAppointments[i]->TimeHour, myContact->myAppointments[i]->TimeMinute,
                        myContact->myAppointments[i]->LengthMinute, myContact->myAppointments[i]->Purpose);
            }
        } else {
            printf("Contact not found.\n");
        }
        fclose(file);
    } else {
        printf("Error opening file.\n");
    }

    free(filename);
}

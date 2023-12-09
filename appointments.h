//
// Created by kenza on 09/12/2023.
//

#ifndef PROJETC_S3_FINAL_APPOINTMENTS_H
#define PROJETC_S3_FINAL_APPOINTMENTS_H

struct s_contact;

typedef struct s_appointment{
    int DateDay;
    int DateMonth;
    int DateYear;
    int TimeHour;
    int TimeMinute;
    int LengthMinute;
    char *Purpose;
} appointment;
void insertAppointmentAtBeginning(appointment *myAppointment, char *owner);
appointment *createAppointment(int day, int month, int year, int hour, int lengthMinute, char *purpose, char *owner);
void addAppointmentToContact(struct s_contact *myContact, appointment *newAppointment);
void displayAppointment(appointment *myAppointment);
void displayAppointments(struct s_contact *myContact);
void displayFileAppointments(char* fullname);
void loadFileAppointments( char* fullname);
void deleteAppointment(struct s_contact *myContact, appointment *myAppointment);
void saveFileAppointments(char* fullname);
#endif //PROJETC_S3_FINAL_APPOINTMENTS_H

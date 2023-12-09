//
// Created by kenza on 09/12/2023.
//

#include "contact.h"
#include <ctype.h>
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include <time.h>

char* LowerCase(char* str){
    int i = 0;
    while(str[i] != '\0'){
        if (str[i] <= 90 && str[i] >= 65){
            str[i] += 32;
        }
    }
    return str;
}
// Function to create a full name randomly from the first names and last names files
char* generateRandomFullName() {
    FILE *firstNamesFile = fopen("prénoms.txt", "r");
    FILE *lastNamesFile = fopen("noms.txt", "r");
    // we randomly select a first name and last name
    fseek(firstNamesFile, 0, SEEK_SET);
    fseek(lastNamesFile, 0, SEEK_SET);
    // We use the number of lines in both files to generate a random index
    int randomFirstNameIndex = rand() % 36047;
    int randomLastNameIndex = rand() % 218982;

    char firstName[50], lastName[50];
    for (int i = 0; i <= randomFirstNameIndex; i++) {
        fgets(firstName, sizeof(firstName), firstNamesFile);
    }

    for (int i = 0; i <= randomLastNameIndex; i++) {
        fgets(lastName, sizeof(lastName), lastNamesFile);
    }

    // Remove newline characters from names
    firstName[strcspn(firstName, "\n")] = '\0';
    lastName[strcspn(lastName, "\n")] = '\0';
    // Convert names to lowercase for easier comparison
    LowerCase(firstName);
    LowerCase(lastName);
    // Close files
    fclose(firstNamesFile);
    fclose(lastNamesFile);

    // Create the full name string
    char *fullName = (char*)malloc(strlen(firstName) + strlen(lastName) + 2); // 2 for '_' and null terminator
    sprintf(fullName, "%s_%s", firstName, lastName);

    return fullName;
}
#define LIST_SIZE 1000
int compareStrings(const void* a, const void* b) {
    return strcmp(((contact*)a)->name, ((contact*)b)->name);
}
contact_list* createFullNameList() {
    contact_list* new_list = malloc(sizeof(contact_list));
    new_list->nb_contacts = LIST_SIZE;
    new_list->heads = malloc(LIST_SIZE * sizeof(contact*));
    for (int i = 0; i < LIST_SIZE; ++i) {
        new_list->heads[i] = malloc(sizeof(contact));
        new_list->heads[i]= contact_creation(generateRandomFullName(), 4, 0);
    }

    qsort(new_list->heads, LIST_SIZE, sizeof(contact*), compareStrings);

    return new_list;
}
void displayLevelContact(contact_list* list, int level) {
    if (list->heads[level]!=NULL){
        contact *temp = list->heads[level];
        printf("[list head_%d @- ]-->", level);
        while (temp != NULL) {
            printf("[%s @- ]-->", temp->name);
            temp = temp->next[level];
        }
        printf("NULL\n");
    }
    else{
        printf("Empty contacts list.\n");
    }
}
void displayAllContacts(contact_list* list) {
    if (list->heads[0]!=NULL){
        for (int i = 0; i < list-> nb_contacts ; ++i) {
            displayLevelContact(list, i);
        }
    }
    else{
        printf("Empty contacts list.\n");
    }
}
char* NewName() {
    char* name = (char*)malloc(50*sizeof(char));
    char firstname[50];
    char lastname[50];
    printf("Enter the first name of the contact: ");
    scanf("%s", firstname);
    printf("Enter the last name of the contact: ");
    scanf("%s", lastname);
    sprintf(name, "%s_%s", firstname, lastname);
    return name;
}
contact *contact_creation(char* fullname, int levels, int appointments){
    contact * nouv_contact= (contact*)malloc(sizeof (contact));
    nouv_contact->name = fullname;
    nouv_contact->nb_levels = levels;
    nouv_contact->nb_appointments = appointments;
    nouv_contact->next = NULL;
    return nouv_contact;
}
void initializeContactList(contact_list* list) {
   FILE *file = fopen("contacts.txt", "r");
   if (file == NULL) {
       printf("Empty contacts list.\n");
   }
   else{
       char line[50];
       int i = 0;
       while (fgets(line, sizeof(line), file)) {
           line[strcspn(line, "\n")] = '\0';
           list->heads[i] = contact_creation(line, 4, 0);
           i++;
       }
       fclose(file);
   }
}
void deleteContact(contact_list* list, char* name) {
    int i = 0;
    while (i < LIST_SIZE && strcmp(list->heads[i]->name, name) != 0) {
        i++;
    }
    if (i == LIST_SIZE) {
        printf("Contact not found.\n");
    }
    else {
        contact* temp = list->heads[i];
        list->heads[i] = list->heads[i]->next[i];
        free(temp);
    }
}
contact *searchContact(char* name) {
    FILE *file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("Empty contacts list.\n");
    }
    else{
        char line[50];
        while (fgets(line, sizeof(line), file)) {
            line[strcspn(line, "\n")] = '\0';
            if (strcmp(line, name) == 0) {
                return contact_creation(line, 4, 0);
            }
        }
        fclose(file);
    }
    return NULL;

}
void insertContact(contact_list* list, contact* myContact) {
    int i = 0;
    while (i < LIST_SIZE && strcmp(list->heads[i]->name, myContact->name) < 0) {
        i++;
    }
    if (i == LIST_SIZE) {
        printf("Contact not found.\n");
    }
    else {
        myContact->next[i] = list->heads[i];
        list->heads[i] = myContact;
    }
}
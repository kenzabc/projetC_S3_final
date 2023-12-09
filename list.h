//
// Created by kenza on 09/12/2023.
//

#ifndef PROJETC_S3_FINAL_LIST_H
#define PROJETC_S3_FINAL_LIST_H

#include "cell.h"
#include "stdio.h"

typedef struct s_list
{
    int max_level;
    t_cell **heads;
} t_list;

t_list *create_list(int);
void InsertHeadList(t_list *, t_cell *, int);
void DisplayLevelList(t_list *, int);
void ShowAllLevels(t_list*);
void InsertCellInList(t_list* , t_cell *, int);
int searchValue(t_list *myList, int value);
int searchLevelValue(t_list *myList, int value);
t_list *createListToSearch(int maxvalue);

#endif //PROJETC_S3_FINAL_LIST_H

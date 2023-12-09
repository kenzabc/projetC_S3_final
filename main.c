//
// Created by kenza on 09/12/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "timer.h"




#define maxlevel 100000

int main() {

    // part 1 demo
    t_list *list = create_list(8); //on crée la list avec max level heads

    t_cell *cell = create_cell(5, maxlevel); // on crée une cell, valeur 5 et son nb de niveau max est maxlevel
    InsertCellInList(list, cell, 5); //on insère seulement pour 5 niveaux (0 à 4 du coup)

    cell = create_cell(3, maxlevel);
    InsertCellInList(list, cell, 3);
    ShowAllLevels(list);

    cell = create_cell(34, maxlevel);
    InsertCellInList(list, cell, 7);

    cell = create_cell(25, maxlevel);
    InsertCellInList(list, cell, 6);

    cell = create_cell(90, maxlevel);
    InsertHeadList(list, cell, 2);
    //ShowAllLevels(list); //on display tout
    //printf("%d\n", searchValue(list, 25)); //on cherche la valeur 34

    printf("\n\n");
// complexity study
/*
    FILE *log_file = fopen("../data.txt", "w");
    char format[] = "%d\t%s\t%s\n";
    int level;
    char *time_lvl0;
    char *time_all_levels;

    srand(time(NULL));

    for (int j = 1; j <= 64; j *= 2) {
        int maxval = 1000 * j;
        t_list *list = createListToSearch(maxval);

        // Classic search
        startTimer();
        for (int i = 0; i <= 10000; i++) {
            searchValue(list, rand() % maxval + 1);
        }
        stopTimer();
        displayTime();
        time_lvl0 = getTimeAsString();

        // Search by level
        startTimer();
        for (int i = 0; i <= 10000; i++) {
            int tosearch = rand() % 1001;
            searchLevelValue(list, tosearch);
        }
        stopTimer();
        displayTime();
        time_all_levels = getTimeAsString();

        // Log the results
        fprintf(log_file, format, maxval, time_lvl0, time_all_levels);
    }

    fclose(log_file);
    */
    return 0;
}
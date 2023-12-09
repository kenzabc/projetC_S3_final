//
// Created by kenza on 09/12/2023.
//

#ifndef PROJETC_S3_FINAL_CELL_H
#define PROJETC_S3_FINAL_CELL_H

typedef struct s_cell
{
    int max_level;
    int value;
    struct s_cell **pointers;
} t_cell;

t_cell *create_cell(int, int);

#endif //PROJETC_S3_FINAL_CELL_H

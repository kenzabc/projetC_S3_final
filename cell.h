
#ifndef PROJECT_BIS_S3_CELL_H
#define PROJECT_BIS_S3_CELL_H

typedef struct s_cell
{
    int max_level;
    int value;
    struct s_cell **pointers;
} t_cell;

t_cell *create_cell(int, int);

#endif //PROJECT_BIS_S3_CELL_H

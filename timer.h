//
// Created by kenza on 09/12/2023.
//

#ifndef PROJETC_S3_FINAL_TIMER_H
#define PROJETC_S3_FINAL_TIMER_H
#include <time.h>
#include "list.h"

// timer structure
typedef struct s_timer
{
    clock_t _start; // start time
    clock_t _end;   // end time
    double _msecs;  // duration in milliseconds
} t_timer;

static t_timer _timer;

/**
 * @brief start the timer
 * @param none
 * @return none
 */
void startTimer();

/**
 * @brief stop the timer
 * @param none
 * @return none
 */
void stopTimer();

/**
 * @brief display the time
 * @param none
 * @return none
 */
void displayTime();

/**
 * @brief return a string with the time in seconds and milliseconds
 * @param none
 * @return a string with the time in seconds and milliseconds
 */
char *getTimeAsString();
void classicSearch(t_list* list, int* values, int count);
void searchFromHighestLevel(t_list* list, int* values, int count);

#endif //PROJETC_S3_FINAL_TIMER_H

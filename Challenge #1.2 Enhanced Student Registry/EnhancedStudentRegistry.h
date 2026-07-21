#ifndef TEST_H
#define TEST_H

#include <stdio.h>

// ========================================================================= //
//                         1. CONSTANTS & DEFINITIONS                       //
// ========================================================================= //

#define MAXLETTERS  31
#define MAXSTUDENTS 10

// ========================================================================= //
//                         2. STRUCTURE DEFINITIONS                          //
// ========================================================================= //

typedef struct {
    int idnum;
    char name[MAXLETTERS];
    char major[MAXLETTERS];
    float gpa;
    int credit;
} STUDENT;

// ========================================================================= //
//                         3. UTILITIES & DESIGN FUNCTIONS                   //
// ========================================================================= //

void clsr(void);
void mainmenu(void);
void addstudentdesign(STUDENT *student, int *StudentCount);

// ========================================================================= //
//                         4. INPUT VALIDATORS & MENUS                       //
// ========================================================================= //

int intvalidator(STUDENT *student, int *StudentCount, char *question);
float floatvalidator(STUDENT *student, int *StudentCount, char *question);
int majorlist(void);
int getchoice(void);

// ========================================================================= //
//                         5. MAIN REGISTRY FUNCTIONS                        //
// ========================================================================= //

void addstudent(STUDENT *student, int *StudentCount);
void displayall(STUDENT *student, int *StudentCount);
void searchid(STUDENT *student, int *StudentCount);
void gpat(STUDENT *student, int *StudentCount);
void majort(STUDENT *student, int *StudentCount);

// ========================================================================= //
//                         6. FILE LOADING / SAVING OPERATIONS              //
// ========================================================================= //

void loadfile(STUDENT *student, int *StudentCount);
void savefile(STUDENT *student, int *StudentCount);

#endif
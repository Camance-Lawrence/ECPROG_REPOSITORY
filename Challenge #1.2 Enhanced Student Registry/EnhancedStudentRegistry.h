#ifndef TEST_H
#define TEST_H

#define MAXLETTERS 31
#define MAXSTUDENTS 10

typedef struct{
    int idnum;
    char name[MAXLETTERS];
    char major[MAXLETTERS];
    float gpa;
    int credit;
}STUDENT;

void clsr();
void mainmenu();
int majorlist();
int getchoice();
void addstudent(STUDENT *student, int *StudentCount);
void displayall(STUDENT *student, int *StudentCount);
void searchid(STUDENT *student, int *StudentCount);
void gpat(STUDENT *student, int *StudentCount);
void majort(STUDENT *student, int *StudentCount);

void loadfile(STUDENT *student, int *StudentCount);
void savefile(STUDENT *student, int *StudentCount);

#endif
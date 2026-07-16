#ifndef STUDENT_REGISTRY_H
#define STUDENT_REGISTRY_H

#define MAXLETTERS 31
#define MAXSTUDENTS 10

typedef struct{
    int idnum;
    char name[MAXLETTERS];
    char major[MAXLETTERS];
    float gpa;
    int credits;
}STUDENT;

//FPROTOTYPES:
void cls();
void addheader(STUDENT *s, int *slider);
void fullna();

void addstudent(STUDENT *s, int *lcounter);
void searchid(STUDENT *s, int *id, int *lcounter);
void gpathreshold(STUDENT *s, float *gpat, int *lcounter);
void searchmajor(STUDENT *s, char *smajor, int *lcounter);
void printall(STUDENT *s, int *lcounter);

#endif
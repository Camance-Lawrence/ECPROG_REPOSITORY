#include <stdio.h>
#include <string.h>


#define MAXLETTERS 31
#define MAXSTUDENTS 10

typedef struct{
    int idnum;
    int name[MAXLETTERS];
    int major[MAXLETTERS];
    float gpa;
    int credits;
}STUDENT;

void menu(int *men1, int *men2){
    printf("======================\nStudent Registry Menu:\n======================\n");
    printf("Press[1]:ADD NEW STUDENT\nPress[2]:SEARCH STUDENT\nPress[3]:DISPLAY ALL STUDENTS\nPress[0] EXIT PROGRAM\n\nEnter Choice:");

}

int main(){

    STUDENT student[MAXSTUDENTS];

    int restart = 0;

    while(!restart){
        int men1 = 0;
        int men2 = 0;

        menu(&men1, &men2);

    }

    
    
    

    return 0;
}
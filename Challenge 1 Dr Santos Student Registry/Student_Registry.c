#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Student_Registry.h"

void fullna(){
    printf("\nSTUDENT REGISTRY FULL!!\npress enter to go back to Main menu");
    while(getchar() !='\n');
    getchar();
}

void addheader(STUDENT *s, int *slider){
    cls();
    printf("===============================\n");
    printf("=====STUDENT INFORMATION=======\n");
    printf("===============================\n");

    if(s[*slider].idnum == 0){printf("Student ID:\n");} 
    else{printf("Student ID: %d\n", s[*slider].idnum);}
    printf("Name: %s\n", strlen(s[*slider].name) ? s[*slider].name : " ");
    printf("Major: %s\n", strlen(s[*slider].major) ? s[*slider].major: " ");
    printf("GPA: %.2f\n", s[*slider].gpa);
    printf("Credit: %d\n", s[*slider].credits);
}

//======================FUNCTIONS:

void cls(){
    #ifdef _WIN32
        system("cls");
    #else
        printf("\033[2J\033[1;1H");
    #endif
}

void addstudent(STUDENT *s, int *lcounter){

    char recycle2;
    do{
        if(*lcounter >= MAXSTUDENTS){
            fullna();
            return;
        }

        else{
            int i = *lcounter;
            //ID NUM
            addheader(s, &i);
            printf("\n\nEnter Student ID:"); 
            scanf("%d", &s[i].idnum);
            cls();

            //NAME
            addheader(s, &i);
            printf("\n\nEnter Name:"); 
            scanf("%s", s[i].name);
            cls();

            //MAJOR
            addheader(s, &i);
            printf("\n\nSELECT MAJOR:\nPress[1]COMPUTER_STUDIES\n\nChoice:");
            int choice = 0;
            if(scanf("%d", &choice)==1){strcpy(s[i].major, "COMPUTER_STUDIES");}
            cls();

            //GPA
            addheader(s, &i);
            printf("\n\nEnter GPA:");
            scanf("%f", &s[i].gpa);
            cls();

            //CREDITS
            addheader(s, &i);
            printf("\n\nEnter Credits:");
            scanf("%d", &s[i].credits);
            cls();

            //CONFIRM
            addheader(s, &i);
            while(getchar() != '\n');
            printf("\n\nStudent Info saved!\npress enter to continue\n");
            getchar();
            (*lcounter)++;

            printf("\nDo you want to add another student?(y/n):");
            scanf(" %c", &recycle2);
        }
    }while(recycle2 =='y' || recycle2 =='Y');
    
}

//SEARCH FUNCTIONS:
//BY ID
void searchid(STUDENT *s, int *id, int *lcounter){
    int found = 0;
    for(int i=0; i<*lcounter; i++){
        if(s[i].idnum == *id){
            printf("%6s | %15s | %17s | %6s | %7s\n", "ID", "Name", "Major", "GPA", "Credits");
            printf("----------------------------------------------------------------------\n");
            printf("%6d | %15.15s | %17.17s | %6.2f | %7d\n", s[i].idnum, s[i].name, s[i].major, s[i].gpa, s[i].credits);
            printf("----------------------------------------------------------------------\n");
            found =1;
            break;
        }
    }

    if(!found){
        printf("ID / STUDENT NOT FOUND!\n");
    }
}
//GPA THRESHHOLD
void gpathreshold(STUDENT *s, float *gpat, int *lcounter){
    int found=0;
    printf("%6s | %15s | %17s | %6s | %7s\n", "ID", "Name", "Major", "GPA", "Credits");
    printf("----------------------------------------------------------------------\n");
    for(int i=0; i<*lcounter; i++){
        if(s[i].gpa >= *gpat){
            printf("%6d | %15.15s | %17.17s | %6.2f | %7d\n", s[i].idnum, s[i].name, s[i].major, s[i].gpa, s[i].credits);
            printf("----------------------------------------------------------------------\n");
            found = 1;
        }
    }

    if(!found){
        printf("No students found with GPA >= %.2f\n", *gpat);
    }
}

//MAJOR
void searchmajor(STUDENT *s, char *smajor, int *lcounter){
    printf("%6s | %15s | %17s | %6s | %7s\n", "ID", "Name", "Major", "GPA", "Credits");
    printf("----------------------------------------------------------------------\n");
    int totalcount=0;
    int found=0;
    for(int i=0; i<*lcounter; i++){
        if(strcmp(s[i].major, smajor) == 0){
            printf("%6d | %15.15s | %17.17s | %6.2f | %7d\n", s[i].idnum, s[i].name, s[i].major, s[i].gpa, s[i].credits);
            printf("----------------------------------------------------------------------\n");
            found = 1;
            totalcount++;
        }
    }
    printf("                                              Total Students found: %d\n", totalcount);

    if(!found){
        printf("No students found with %s Major\n", smajor);
    }
}
//PRINTALL
void printall(STUDENT *s, int *lcounter){
    printf("%6s | %15s | %17s | %6s | %7s\n", "ID", "Name", "Major", "GPA", "Credits");
    printf("----------------------------------------------------------------------\n");
    if(*lcounter > 0){
        for(int i=0; i< *lcounter; i++){
            printf("%6d | %15.15s | %17.17s | %6.2f | %7d\n", s[i].idnum, s[i].name, s[i].major, s[i].gpa, s[i].credits);
            printf("----------------------------------------------------------------------\n");
        }
    }

    else{
        printf("                       Registry is empty!                             \n");
    }

}
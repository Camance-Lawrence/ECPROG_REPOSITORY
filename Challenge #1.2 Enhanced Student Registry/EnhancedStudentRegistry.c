#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EnhancedStudentRegistry.h"

void clsr() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void mainmenu(){
        printf(
        "MAIN MENU:\n"
        "Add Student...............[PRESS 1]\n"
        "Display All Students......[PRESS 2]\n"
        "Search by Student ID......[PRESS 3]\n"
        "Find by GPA Threshold.....[PRESS 4]\n"
        "Find by Major.............[PRESS 5]\n"
        "Save & Exit...............[PRESS 0]\n"
    );
}

int majorlist(){
    int major=0;
    int validator=0;
    while(!validator){
        printf(
            "\n"
            "SELECT A MAJOR:\n"
            "Computer_Studies........Press[1]\n"
            "SBM.....................Press[2]\n"
            "Enter choice:"
            );

        if(scanf("%d", &major)!=1){
            printf("Numbers only please!\npress enter to continue...\n");
            while (getchar()!='\n'); getchar();
            clsr();
        }
        else if(major < 1 || major > 2){
            printf("Choice is not on the list\npress enter to continue...\n");
            while (getchar()!='\n'); getchar();
            clsr();
        }
        
        else{
            validator=1;
        }
    }
    

    return major;
}

int getchoice(){
    int choice;
    int validator=0;//Flag to only accept numbers
    while(!validator){
        printf("\nENTER CHOICE:");
        if(scanf("%d", &choice)!=1){
            printf("Numbers only please!\npress enter to continue...\n");
            while (getchar()!='\n'); getchar();
            clsr();
            mainmenu();
        }

        else if(choice < 0 || choice > 5){//handles out of range input
            printf("Choice is not on the list!\n press enter to continue!\n");
            while (getchar()!='\n'); getchar();
            clsr();
            mainmenu();
        }
        else{
            validator=1;
        }
    }
    

    return choice;
}

void addstudent(STUDENT *student, int *StudentCount){
    char choice;
//INPUT AREA
    do{
        int i = *StudentCount;
        if(*StudentCount >= MAXSTUDENTS){//CHECK IF REGISTRY IS FULL
            printf("STUDENT REGISTRY IS FULL!\npress enter to continue\n");
            while (getchar()!='\n'); getchar();
            break;
        }

        printf("\nEnter Student id no:");
        scanf("%d", &student[i].idnum);

        printf("\nEnter Student Name:");
        scanf("%30s", student[i].name);

        int mchoice = majorlist();
        switch (mchoice){
            case 1: strcpy(student[i].major, "Computer_Studies"); break;
            case 2: strcpy(student[i].major, "SBM"); break;
        }

        printf("\nEnter GPA:");
        scanf("%f", &student[i].gpa);

        printf("\nEnter Credit:");
        scanf("%d", &student[i].credit);

        (*StudentCount)++;

        printf("\nAdd another student?(y/n)");
        scanf(" %c", &choice);
    }while(choice == 'Y' || choice == 'y');


    
}

void displayall(STUDENT *student, int *StudentCount){
    for(int i=0; i<*StudentCount; i++){
        printf("Student %d:\n%d\n%s\n%s\n%f\n%d\n\n", i+1, student[i].idnum, student[i].name, student[i].major, student[i].gpa, student[i].credit);
    }
}

void searchid(STUDENT *student, int *StudentCount){
    int TargetIdnumber=0;
    int found=0;
    printf("Enter student id Number:\n");
    scanf("%d", &TargetIdnumber);
    for(int i=0; i<*StudentCount; i++){
        if(student[i].idnum == TargetIdnumber){
            printf("Target id: %d\n", TargetIdnumber);
            printf("Student %d:\n%d\n%s\n%s\n%f\n%d\n\n", i+1, student[i].idnum, student[i].name, student[i].major, student[i].gpa, student[i].credit);
            found=1;
        }
    }
    if(!found){
        printf("Id number not found\n");
    }
    
}

void gpat(STUDENT *student, int *StudentCount){
    float targetGPA=0;
    int found=0;
    printf("Enter target GPA Threshold:\n");
    scanf("%f", &targetGPA);
    for(int i=0; i<*StudentCount; i++){
        if(student[i].gpa >= targetGPA){
            printf("Target id: %f\n", targetGPA);
            printf("Student %d:\n%d\n%s\n%s\n%f\n%d\n\n", i+1, student[i].idnum, student[i].name, student[i].major, student[i].gpa, student[i].credit);
            found=1;
        }
    }
    if(!found){
        printf("No Student found within Threshold\n");
    }
}

void majort(STUDENT *student, int *StudentCount){
    int TargetMajor= majorlist();
    char smajor[MAXLETTERS];
    int found=0;
    int pingcounter=0;
    
    if(TargetMajor == 1){
        strcpy(smajor, "Computer_Studies");
    }

    else if(TargetMajor == 2){
        strcpy(smajor, "SBM");
    }

    for(int i=0; i<*StudentCount; i++){
        if(strcmp(student[i].major, smajor)==0){
            printf("Student %d:\n%d\n%s\n%s\n%f\n%d\n\n", i+1, student[i].idnum, student[i].name, student[i].major, student[i].gpa, student[i].credit);
            pingcounter++;
            found=1;
        }
    }

    if (found){
        printf("total students found: %d", pingcounter);
    }
    

    if(!found){
        printf("No students found in this major.\n");
    }
}
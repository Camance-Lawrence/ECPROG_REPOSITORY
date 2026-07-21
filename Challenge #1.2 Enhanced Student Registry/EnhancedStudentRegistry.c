#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EnhancedStudentRegistry.h"

// ========================================================================= //
//                         1. UTILITIES FUNCTION                             //
// ========================================================================= //

void clsr() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void mainmenu() {
    printf("===================================\n");
    printf("  S T U D E N T   R E G I S T R Y  \n");
    printf("===================================\n");
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

void addstudentdesign(STUDENT *student, int *StudentCount) {
    int i = *StudentCount;
    clsr();
    printf("id no: %d\n", student[i].idnum);
    printf("Name: %s\n", student[i].name);
    printf("Major: %s\n", student[i].major);
    printf("GPA: %.2f\n", student[i].gpa);
    printf("Credit: %d\n", student[i].credit);
}

// ========================================================================= //
//                       2. INPUT VALIDATORS & MENUS                         //
// ========================================================================= //

int intvalidator(STUDENT *student, int *StudentCount, char *question) {
    int input;
    while(1) {
        addstudentdesign(student, StudentCount);
        printf("%s", question);
        if(scanf("%d", &input) == 1) {
            return input;
        }
        printf("Invalid input! Numbers only. Press enter to retry...");
        while(getchar() != '\n');
        getchar();
    }
}

float floatvalidator(STUDENT *student, int *StudentCount, char *question) {
    float input;
    while(1) {
        addstudentdesign(student, StudentCount);
        printf("%s", question);
        if(scanf("%f", &input) == 1) {
            return input;
        }
        printf("Invalid input! Numbers only. Press enter to retry...");
        while(getchar() != '\n');
        getchar();
    }
}

int majorlist() {
    int major = 0;
    int validator = 0;
    while(!validator) {
        printf(
            "\n"
            "SELECT A MAJOR:\n"
            "Computer Studies.............Press[1]\n"
            "BUSINESS.....................Press[2]\n"
            "Enter choice:"
        );

        if(scanf("%d", &major) != 1) {
            printf("Numbers only please!\npress enter to continue...\n");
            while (getchar() != '\n'); getchar();
            clsr();
        }
        else if(major < 1 || major > 2) {
            printf("Choice is not on the list\npress enter to continue...\n");
            while (getchar() != '\n'); getchar();
            clsr();
        }
        else {
            validator = 1;
        }
    }
    return major;
}

int getchoice() {
    int choice;
    int validator = 0;
    while(!validator) {
        printf("\nENTER CHOICE:");
        if(scanf("%d", &choice) != 1) {
            printf("Numbers only please!\npress enter to continue...\n");
            while (getchar() != '\n'); getchar();
            clsr();
            mainmenu();
        }
        else if(choice < 0 || choice > 5) {
            printf("Choice is not on the list!\n press enter to continue!\n");
            while (getchar() != '\n'); getchar();
            clsr();
            mainmenu();
        }
        else {
            validator = 1;
        }
    }
    return choice;
}

// ========================================================================= //
//                      3. MAIN REGISTRY FUNCTIONS                           //
// ========================================================================= //

void addstudent(STUDENT *student, int *StudentCount) {
    char choice;
    do {
        int i = *StudentCount;
        if(*StudentCount >= MAXSTUDENTS) {
            printf("STUDENT REGISTRY IS FULL!\npress enter to continue\n");
            while (getchar() != '\n'); getchar();
            break;
        }

        student[i].idnum = intvalidator(student, StudentCount, "\nEnter Student id no:");
        
        addstudentdesign(student, StudentCount);
        printf("\nEnter Student Name:");
        scanf(" %30[^\n]", student[i].name);

        addstudentdesign(student, StudentCount);
        int mchoice = majorlist();
        switch (mchoice) {
            case 1: strcpy(student[i].major, "Computer Studies"); break;
            case 2: strcpy(student[i].major, "BUSINESS"); break;
        }

        student[i].gpa = floatvalidator(student, StudentCount, "\nEnter GPA:");
        student[i].credit = intvalidator(student, StudentCount, "\nEnter Credit:");
        
        addstudentdesign(student, StudentCount);
        (*StudentCount)++;
        
        printf("\nAdd another student?(y/n)");
        scanf(" %c", &choice);
    } while(choice == 'Y' || choice == 'y');
}

void displayall(STUDENT *student, int *StudentCount) {
    printf("-------------------------------------------------------------------------\n");
    for(int i = 0; i < *StudentCount; i++) {
        printf("%-3d: %-6d | %-20s | %-18s | %-5.2f | %-5d |\n", i+1, student[i].idnum, student[i].name, student[i].major, student[i].gpa, student[i].credit);
        printf("-------------------------------------------------------------------------\n");
    }
}

void searchid(STUDENT *student, int *StudentCount) {
    int TargetIdnumber = 0;
    int found = 0;
    printf("Enter student id Number: ");
    scanf("%d", &TargetIdnumber);
    for(int i = 0; i < *StudentCount; i++) {
        if(student[i].idnum == TargetIdnumber) {
            printf("Target id: %d\n", TargetIdnumber);
            printf("-------------------------------------------------------------------------\n");
            printf("%-3d: %-6d | %-20s | %-18s | %-5.2f | %-5d |\n", i+1, student[i].idnum, student[i].name, student[i].major, student[i].gpa, student[i].credit);
            printf("-------------------------------------------------------------------------\n");
            found = 1;
        }
    }
    if(!found) {
        printf("Id number not found\n");
    }
}

void gpat(STUDENT *student, int *StudentCount) {
    float targetGPA = 0;
    int found = 0;
    printf("Enter target GPA Threshold: ");
    printf("\n-------------------------------------------------------------------------\n");
    if(scanf("%f", &targetGPA) == 1) {
        for(int i = 0; i < *StudentCount; i++) {
            if(student[i].gpa >= targetGPA) {
                printf("%-3d: %-6d | %-20s | %-18s | %-5.2f | %-5d |\n", i+1, student[i].idnum, student[i].name, student[i].major, student[i].gpa, student[i].credit);
                printf("-------------------------------------------------------------------------\n");
                found = 1;
            }
        }
        if(!found) {
            printf("No Student found within Threshold\n");
        }
    }
    else {
        printf("\nEnter a valid number!\n");
    }
}

void majort(STUDENT *student, int *StudentCount) {
    int TargetMajor = majorlist();
    char smajor[MAXLETTERS];
    int found = 0;
    int pingcounter = 0;
    
    if(TargetMajor == 1) {
        strcpy(smajor, "Computer Studies");
    }
    else if(TargetMajor == 2) {
        strcpy(smajor, "BUSINESS");
    }

    printf("-------------------------------------------------------------------------\n");
    for(int i = 0; i < *StudentCount; i++) {
        if(strcmp(student[i].major, smajor) == 0) {
            printf("%-3d: %-6d | %-20s | %-18s | %-5.2f | %-5d |\n", i+1, student[i].idnum, student[i].name, student[i].major, student[i].gpa, student[i].credit);
            printf("-------------------------------------------------------------------------\n");
            pingcounter++;
            found = 1;
        }
    }

    if (found) {
        printf("total students found: %d", pingcounter+1);
    }
    if(!found) {
        printf("No students found in this major.\n");
    }
}

// ========================================================================= //
//                    4. FILE LOADING / SAVING OPERATIONS                    //
// ========================================================================= //

void loadfile(STUDENT *student, int *StudentCount) {
    FILE *file = fopen("Student.dat", "r");
    if(file == NULL) return;

    *StudentCount = 0;
    char buffer[100];

    while(fgets(buffer, sizeof(buffer), file) != NULL && *StudentCount < MAXSTUDENTS) {
        int i = *StudentCount;

        char *token = strtok(buffer, "|");
        if(token == NULL) continue;
        student[i].idnum = atoi(token);

        token = strtok(NULL, "|");
        if(token == NULL) continue;
        strcpy(student[i].name, token);

        token = strtok(NULL, "|");
        if(token == NULL) continue;
        strcpy(student[i].major, token);

        token = strtok(NULL, "|");
        if(token == NULL) continue;
        student[i].gpa = atof(token);

        token = strtok(NULL, "|\n");
        if(token == NULL) continue;
        student[i].credit = atoi(token);

        (*StudentCount)++;
    }
    
    fclose(file);
    printf("\n%d student infos are loaded\n", *StudentCount);
}

void savefile(STUDENT *student, int *StudentCount) {
    FILE *file = fopen("Student.dat", "w");
    if(file == NULL) {
        printf("Cant save the data!\npress enter to continue\n");
        getchar();
        return;
    }

    for(int i = 0; i < *StudentCount; i++) {
        fprintf(file, "%d|%s|%s|%.2f|%d\n", student[i].idnum, student[i].name, student[i].major, student[i].gpa, student[i].credit);      
    }

    fclose(file);
    printf("%d student infos are saved\n", *StudentCount);
}
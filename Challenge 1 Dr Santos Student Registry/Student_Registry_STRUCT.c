#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXLETTERS 31
#define MAXSTUDENTS 10

typedef struct{
    int idnum;
    char name[MAXLETTERS];
    char major[MAXLETTERS];
    float gpa;
    int credits;
}STUDENT;


int main(){

    STUDENT student[MAXSTUDENTS];

    int men1=0, men2=0;
    char choi;
    do{
        int gate = 0;
        while(!gate){
            printf("======================\nStudent Registry Menu:\n======================\n");
            printf("Press[1]:ADD NEW STUDENT\nPress[2]:SEARCH STUDENT\nPress[3]:DISPLAY ALL STUDENTS\nPress[0] EXIT PROGRAM\n\nEnter Choice:");        

            if(scanf("%d", &men1) !=1){
                printf("Invalid choice, please enter a number only!\n");
                while(getchar() != '\n');
            }
            else if(men1 < 0 || men1 > 3){
                printf("Invalid choice, please select a numbers from 0-3 only!\n");
            }
            else{
                gate = 1;
            }
        }

        if(men1 == 1){ //ADDSTUDENT
            printf("You add student here:\n");


            // add_student(Idnum, name, major, gpa, credits, &Content, &MaxStudent);
        }

        else if(men1 == 2){ //SEARCH MENU AREA
            int searchflag=0;
            while(!searchflag){
                printf("\n\nSearch student by:\n\nID....................press[1]\nAbove GPA threshold...press[2]\nMajor.................press[3]\n\nEnter Choice:");
                if(scanf("%d", &men2)!= 1){
                    printf("Enter number only!\n");
                    while(getchar() != '\n');
                }

                else if(men2<1 || men2>3){
                    printf("choice out of range!\n");
                }

                else{
                    searchflag=1;
                    // search(Idnum, name, major, gpa, credits, &Content, &MaxStudent, &men2);
                }
            }
        }

        else if(men1 == 3){
            // printall(Idnum, name, major, gpa, credits, &Content, &MaxStudent);
        }

        else{ //(men1 == 0)
            printf("\n\nClosing program!");
            choi = 'n';
        }

        if(men1 != 0){
            printf("\n\nGo back to MAIN MENU?(y/n):");
            scanf(" %c", &choi);
        }

    }while(choi == 'y' || choi == 'Y');



    return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//FUNCTIONS:

void addstudent()
{
    
}
#include <stdio.h>
#include <stdlib.h>
#include "Student_Registry.h"


int main(){

    STUDENT student[MAXSTUDENTS]={0};//SET TO ZERO PARA IG PRINT SA INFO PLACE HOLDERS ZERO ANG MO GAWAS AS INITIAL VALUE DILI GARBAGE VALUE

    int men1=0, men2=0;
    char choi;
    int lcounter=0;
    do{
        int gate = 0;
        while(!gate){//MAIN MENU
            cls();
            printf("======================\nStudent Registry Menu:\n======================\n");
            printf("Press[1]:ADD NEW STUDENT\nPress[2]:SEARCH STUDENT\nPress[3]:DISPLAY ALL STUDENTS\nPress[0] EXIT PROGRAM\n\nEnter Choice:");        

            if(scanf("%d", &men1) !=1){
                printf("Invalid choice, please enter a number only!\npress enter to continue....\n");
                while(getchar() != '\n');getchar();
                cls();
            }
            else if(men1 < 0 || men1 > 3){
                printf("Invalid choice, please select a numbers from 0-3 only!\npress enter to continue....\n");
                getchar();getchar();
                cls();
            }
            else{
                gate = 1;
            }
        }

        if(men1 == 1){ //ADDSTUDENT
            if(lcounter < MAXSTUDENTS){//OVERFLOW GAURD
                printf("You add student here:\n");
                addstudent(student, &lcounter);
            }

            else{
                fullna();
            }
        }

        else if(men1 == 2){ //SEARCH MENU AREA
            int searchflag=0;//FLAGS FOR VALIDATIONS
            while(!searchflag){//
                cls();
                printf("\n\nSearch student by:\n");
                printf("\nID....................press[1]");
                printf("\nAbove GPA threshold...press[2]");
                printf("\nMajor.................press[3]");
                printf("\nExit..................press[0]");
                printf("\n\nEnter Choice:");
                
                if(scanf("%d", &men2)!= 1){
                    printf("Enter number only!\n");
                    while(getchar() != '\n');
                }
                else if(men2<0 || men2>3){
                    printf("choice out of range!\n");
                    getchar();
                }
                else if(men2 == 0){
                    break;
                }
                else{
                    //SEARCH BY ID
                    int tarid=0;//TARGET ID
                    if(men2 == 1){
                        cls();
                        printf("Enter Id number:");
                        scanf("%d", &tarid);
                        searchid(student, &tarid, &lcounter);//FOR AESTHTICS
                    }
                    //SEARCH BY GPA
                    else if(men2 == 2){
                        float gpat = 0;
                        cls();
                        printf("Enter GPA threshold:");
                        scanf("%f", &gpat);

                        gpathreshold(student, &gpat, &lcounter);
                    }
                    //SEARCH BY MAJOR
                    else if(men2 == 3){
                        char smajor[MAXLETTERS];
                        cls();
                        printf("PICK A MAJOR:");
                        scanf("%s", smajor);
                        searchmajor(student, smajor, &lcounter);
                    }
                    searchflag=1;//INPUTS ARE CORRECT, NO NEED TO LOOP
                }
            }
        }
        //PRINT ALL STUDENTS
        else if(men1 == 3){
            cls();
            printf("======================================================================\n");
            printf("=========================STUDENT INFORMATION==========================\n");
            printf("======================================================================\n");
            printall(student, &lcounter);
        }
        else{ //(men1 == 0)
            printf("\n\nClosing program!");
            choi = 'n';
        }
        if(men1 != 0){
            printf("\n\nGo back to MAIN MENU?\n\n");
            printf("Yes.....................[press y]\n");
            printf("Exit program............[press n]\n:");
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

//=========================DESIGNS:


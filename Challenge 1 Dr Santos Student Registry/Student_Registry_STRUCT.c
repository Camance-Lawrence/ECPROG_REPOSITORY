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

int numcheck(int *num);


int main(){

    STUDENT student[MAXSTUDENTS];
    int men1=0;
    char choice;
    do{
        int flag1=0;
        while(flag1==0){
            int men1=0;
            system("cls");
            printf("======================\nStudent Registry Menu:\n======================\n");
            printf("Press[1]:ADD NEW STUDENT\nPress[2]:SEARCH STUDENT\nPress[3]:DISPLAY ALL STUDENTS\nPress[0] EXIT PROGRAM\n\nEnter Choice:");

            int flag2=0;
            if(numcheck(&men1)){
                if(men1 < 0 || men1 > 3)
                {
                    printf("PLEASE SELECT FROM NUMBER 0-3 only\npress enter to continue:\n");
                    getchar();getchar();
                }

                else{
                    flag1=1;
                }

            }

            else{
                printf("ENTER A NUMBER ONLY!\npress enter to continue:\n");
                getchar();

            }
        }


        if(men1 != 0){
            printf("Return to Main Menu?(y/n):");
            scanf(" %c", &choice);           
        }


    }while(choice == 'y' || choice =='Y');

    
    
    

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//FUNCTIONS:

int numcheck(int *num){
    if(scanf("%d", num)==1){
        return 1;
    }

    else{
        while(getchar() !='\n');
        return 0;
    }

}

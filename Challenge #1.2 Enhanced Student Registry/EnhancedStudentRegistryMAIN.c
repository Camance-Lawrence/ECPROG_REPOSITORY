#include <stdio.h>
#include <stdlib.h>
#include "EnhancedStudentRegistry.h"

int main(){
    int choice;
    int StudentCount = 0; //COUNTS HOW MANY STUDENT IS INSIDE THE REGISTRY 
    STUDENT student[MAXSTUDENTS]={0};

    loadfile(student, &StudentCount);
    do{
        clsr();
        mainmenu();//DISPPLAYS MAINMENU
        choice = getchoice();
        switch (choice)
        {
        case 1: //done
            clsr();
            addstudent(student, &StudentCount);
            savefile(student, &StudentCount);
            printf("\nPress Enter to return to menu...");
            while (getchar()!='\n'); 
            getchar();
            break;
        
        case 2: //done
            clsr();
            printf("\nDisplay All Students\n");
            loadfile(student, &StudentCount);
            displayall(student, &StudentCount);
            printf("\nPress Enter to return to menu...");
            while (getchar()!='\n'); 
            getchar();
            break;

        case 3: //done
            clsr();
            loadfile(student, &StudentCount);
            printf("\nSearch by Student ID\n");
            searchid(student, &StudentCount);
            printf("\nPress Enter to return to menu...");
            while (getchar()!='\n'); 
            getchar();
            break;

        case 4: //done
            clsr();
            loadfile(student, &StudentCount);
            printf("\nFind by GPA Threshold");
            gpat(student, &StudentCount);
            printf("\nPress Enter to return to menu...");
            while (getchar()!='\n'); 
            getchar();
            break;

        case 5://done
            clsr();
            loadfile(student, &StudentCount);
            printf("\nFind by Major");
            majort(student, &StudentCount);
            printf("\nPress Enter to return to menu...");
            while (getchar()!='\n'); 
            getchar();
            break;
        
        case 0:
            clsr();
            printf("\nCLOSING PROGRAM");
            break;

        default:
            break;
        }
    }while(choice !=0);


    return 0;
}

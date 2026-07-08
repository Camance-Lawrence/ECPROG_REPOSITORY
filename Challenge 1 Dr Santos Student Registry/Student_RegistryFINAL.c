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

//FPROTOTYPES:
void cls();
void addheader(STUDENT *s, int *slider);
void fullna();

void addstudent(STUDENT *s, int *lcounter);
void searchid(STUDENT *s, int *id, int *lcounter);
void gpathreshold(STUDENT *s, float *gpat, int *lcounter);
void searchmajor(STUDENT *s, char *smajor, int *lcounter);
void printall(STUDENT *s, int *lcounter);

int main(){

    STUDENT student[MAXSTUDENTS]={0};

    int men1=0, men2=0;
    char choi;
    int lcounter=0;
    do{
        int gate = 0;
        while(!gate){
            cls();
            printf("======================\nStudent Registry Menu:\n======================\n");
            printf("Press[1]:ADD NEW STUDENT\nPress[2]:SEARCH STUDENT\nPress[3]:DISPLAY ALL STUDENTS\nPress[0] EXIT PROGRAM\n\nEnter Choice:");        

            if(scanf("%d", &men1) !=1){
                printf("Invalid choice, please enter a number only!\n");
                while(getchar() != '\n');getchar();
                cls();
            }
            else if(men1 < 0 || men1 > 3){
                printf("Invalid choice, please select a numbers from 0-3 only!\n");
                getchar();getchar();
                cls();
            }
            else{
                gate = 1;
            }
        }

        if(men1 == 1){ //ADDSTUDENT
            if(lcounter < MAXSTUDENTS){
                printf("You add student here:\n");
                addstudent(student, &lcounter);
            }

            else{
                fullna();
            }
        }

        else if(men1 == 2){ //SEARCH MENU AREA
            int searchflag=0;
            while(!searchflag){
                cls();
                printf("\n\nSearch student by:\n\nID....................press[1]\nAbove GPA threshold...press[2]\nMajor.................press[3]\n\nEnter Choice:");
                if(scanf("%d", &men2)!= 1){
                    printf("Enter number only!\n");
                    while(getchar() != '\n');
                }

                else if(men2<1 || men2>3){
                    printf("choice out of range!\n");
                }

                else{
                    //SEARCH BY ID
                    int tarid=0;
                    if(men2 == 1){
                        cls();
                        printf("Enter Id number:");
                        scanf("%d", &tarid);
                        searchid(student, &tarid, &lcounter);
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
                    searchflag=1;
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

//=========================DESIGNS:

void fullna(){
    printf("\nSTUDENT REGISTRY FULL!!\npress enter to go back to Main menu");
    while(getchar() !='\n');
    getchar();
}

void addheader(STUDENT *s, int *slider)
{
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

void cls()
{
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
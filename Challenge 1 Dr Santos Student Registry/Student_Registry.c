#include <stdio.h>
#include <stdlib.h>

//Function Protitypes:
void add_student(int Idnum[], char name[][31], char major[][31], float gpa[], int credits[], int *Content, int *MaxStudent);

void printall(int Idnum[], char name[][31], char major[][31], float gpa[], int credits[], int *Content, int *MaxStudent);

void cls();


int main()
{

    //student info area.
    int MaxStudent = 1; //tig limit sa pilay ma sulod always add 1

    int Content=0; // counter if pila na ang sulod
    int Idnum[MaxStudent]; 
    char name[MaxStudent][31];
    char major[MaxStudent][31];
    float gpa[MaxStudent]; //float ko 
    int credits[MaxStudent];

    //MENU
    int men1, men2;
    char choi;

    do
    {
        printf("======================\nStudent Registry Menu:\n======================\n");
        printf("Press[1]:ADD NEW STUDENT\nPress[2]:SEARCH STUDENT\nPress[3]:DISPLAY ALL STUDENTS\n\nEnter Choice:");

        scanf("%d", &men1);

        if(men1 == 1) //ADDSTUDENT
        {
            printf("You add student here:\n");

            add_student(Idnum, name, major, gpa, credits, &Content, &MaxStudent);
            getchar();
        }

        else if(men1 == 2) //SEARCH MENU AREA
        {
            printf("\n\nSearch student by:\n\nID....................press[1]\nAbove GPA threshold...press[2]\nMajor.................press[3]\n\nEnter Choice:");
            scanf("%d", &men2);

            if(men2 == 1)
            {
                printf("Searching through id\n");
            }

            else if(men2 == 2)
            {
                printf("Searching through GPA\n");
            }

            else if(men2 == 3)
            {
                printf("Searching through MAJOR\n");
            }

            else
            {
                printf("Invalid choice!\n");
            }

        }

        else if(men1 == 3)
        {
            printall(Idnum, name, major, gpa, credits, &Content, &MaxStudent);
        }

        else
        {
            printf("Number 1 or 2 lang nganeeee\n");
        }

        printf("\nRun Again?(y/n):");
        scanf(" %c", &choi);


        cls();
        }while(choi == 'y' || choi == 'Y');



    return 0;
}

//Funtions:
void cls()//Screen cleaner 2.0
{
    #ifdef _WIN32
        system("cls");
    #else
        printf("\033[2J\033[1;1H");
    #endif
}
void add_student(int Idnum[], char name[][31], char major[][31], float gpa[], int credits[], int *Content, int *MaxStudent)
{

    printf("Enter Student Information:");
    if(*Content >= *MaxStudent)
    {
        printf("\nStudent Regestry is full!!\n");
        return;
    }


    int i = *Content;
    printf("\nID:");
    scanf("%d", &Idnum[i]);
    printf("\nName:");
    scanf("%s", name[i]);
    printf("\nMajor:");
    scanf("%s", major[i]);  
    printf("\nGPA:");
    scanf("%f", &gpa[i]);
    printf("\nCredit:");
    scanf("%d", &credits[i]);

    (*Content)++;
}

void printall(int Idnum[], char name[][31], char major[][31], float gpa[], int credits[], int *Content, int *MaxStudent)
{
    printf("STUDENT LIST:\n");

    if(*Content < 0)
    {
        printf("\nStudent list is Currently empty!");
        getchar();
        return;
    }

    for(int i=0; i<*Content; i++)
    {
        printf("\n");
        
        printf("%6s | %15s | %15s | %6s | %7s\n", "ID", "Name", "Major", "GPA", "Credits");
        printf("----------------------------------------------------------------------\n");

        for(int i = 0; i < *Content; i++)
        {
            printf("%6d | %15.15s | %15.15s | %6.2f | %7d\n", Idnum[i], name[i], major[i], gpa[i], credits[i]);
        }
        printf("----------------------------------------------------------------------\n");
    }
}
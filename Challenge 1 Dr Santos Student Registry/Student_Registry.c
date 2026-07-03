#include <stdio.h>
#include <stdlib.h>

//Function Protitypes:
void add_student(int Idnum[], char name[][31], char major[][31], float gpa[], int credits[], int *Content, int *MaxStudent);

void printall(int Idnum[], char name[][31], char major[][31], float gpa[], int credits[], int *Content, int *MaxStudent);

void search(int Idnum[], char name[][31], char major[][31], float gpa[], int credits[], int *Content, int *MaxStudent, int *men2);

void cls();


int main()
{

    //student info area.
    int MaxStudent = 3; //tig limit sa pilay ma sulod

    int Content=0; // counter if pila na ang sulod
    int Idnum[MaxStudent]; 
    char name[MaxStudent][31];
    char major[MaxStudent][31];
    float gpa[MaxStudent]; //float ko 
    int credits[MaxStudent];

    //MENU
    int men1=0, men2=0;
    char choi=0;

    do
    {
        printf("======================\nStudent Registry Menu:\n======================\n");
        printf("Press[1]:ADD NEW STUDENT\nPress[2]:SEARCH STUDENT\nPress[3]:DISPLAY ALL STUDENTS\nPress[0] EXIT PROGRAM\n\nEnter Choice:");

        scanf("%d", &men1);

        if(men1 == 1) //ADDSTUDENT
        {
            printf("You add student here:\n");

            add_student(Idnum, name, major, gpa, credits, &Content, &MaxStudent);
        }

        else if(men1 == 2) //SEARCH MENU AREA
        {
            printf("\n\nSearch student by:\n\nID....................press[1]\nAbove GPA threshold...press[2]\nMajor.................press[3]\n\nEnter Choice:");
            scanf("%d", &men2);

            search(Idnum, name, major, gpa, credits, &Content, &MaxStudent, &men2);

        }

        else if(men1 == 3)
        {
            printall(Idnum, name, major, gpa, credits, &Content, &MaxStudent);
        }

        else if(men1 == 0)
        {
            printf("\n\nClosing program!");
            choi = 'n';
        }

        else
        {
            printf("Number 1 - 3 lang nganeeee\n");
        }

        if(men1 != 0)
        {
            printf("\n\nGo back to MAIN MENU?(y/n):");
            scanf(" %c", &choi);
        }



        cls();
        }while(choi == 'y' || choi == 'Y');



    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Funtions:

//Screen cleaner 2.0
void cls()
{
    #ifdef _WIN32
        system("cls");
    #else
        printf("\033[2J\033[1;1H");
    #endif
}

//ADDING OF NEW STUDENT FUNCTION
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

//SEARCH FUNTION
void search(int Idnum[], char name[][31], char major[][31], float gpa[], int credits[], int *Content, int *MaxStudent, int *men2)
{
    if(*men2 == 1) // SEARCH BY ID
    {
        int SIN=0; //Student ID NUMBERR
        int flaggy=0;
        printf("ENTER THE STUDENTS ID NUMBER:");// SEARCH USING ID NUMVERRR
        scanf("%d", &SIN);

        for(int i = 0; i<*Content; i++)
        {


            if(Idnum[i] == SIN)
            {
                printf("\n");
                printf("%6s | %15s | %15s | %6s | %7s\n", "ID", "Name", "Major", "GPA", "Credits");
                printf("----------------------------------------------------------------------\n");
                printf("%6d | %15.15s | %15.15s | %6.2f | %7d\n", Idnum[i], name[i], major[i], gpa[i], credits[i]);
                printf("----------------------------------------------------------------------\n");
                
                flaggy=1;
                break;
            }

        }

        if(flaggy == 0)
        {
            printf("\nStudent does not exist!");
        }



    }

    else if(*men2 == 2) //SEARCH USING = or ABOVE GIVEN GPA
    {
        float gp=0.0; //GPA SA STUDENT
        int flaggy=0;
        printf("ENTER GPA threshold:");
        scanf("%f", &gp);
        printf("%6s | %15s | %15s | %6s | %7s\n", "ID", "Name", "Major", "GPA", "Credits");
        printf("----------------------------------------------------------------------\n");

        for(int i=0; i<*Content; i++)
        {
            if(gpa[i] <=gp)
            {
                printf("%6d | %15.15s | %15.15s | %6.2f | %7d\n", Idnum[i], name[i], major[i], gpa[i], credits[i]);
                printf("----------------------------------------------------------------------\n");
                flaggy=1;
            }
        }

        if(flaggy==0)
        {
            printf("------------------------   NO STUDENT FOUND   ------------------------\n");
            printf("----------------------------------------------------------------------\n");
        }
    }

    else if(*men2 == 3)
    {
        char mj[31]; //MAJOR SA STUDENT
        int flaggy=0;
        int fcount=0;
        printf("MAJOR FILTER:");
        scanf("%s", mj);
        printf("%6s | %15s | %15s | %6s | %7s\n", "ID", "Name", "Major", "GPA", "Credits");
        printf("----------------------------------------------------------------------\n");

        for(int i=0; i<*Content; i++)
        {   
            int flaggy2=0; //Match flagg
            for(int j=0; j<31; j++)
            {
                if(major[i][j] != mj[j])
                {
                    break;
                }

                if(major[i][j] == '\0' && mj[j]=='\0')
                {
                    flaggy2=1; //match kai naka abots last
                    fcount++;
                    break;
                }
            }



            if(flaggy2==1)
            {
                printf("%6d | %15.15s | %15.15s | %6.2f | %7d\n", Idnum[i], name[i], major[i], gpa[i], credits[i]);
                printf("----------------------------------------------------------------------\n");

                flaggy=1;
            }
        }

        printf("Total students Found [%d]\n", fcount);

        if(flaggy==0)
        {
            printf("------------------------   NO STUDENT FOUND   ------------------------\n");
            printf("----------------------------------------------------------------------\n");
        }
    }

    else
    {
        printf("Invalid choice!\n");
    }   

}

//PRINT ALL STUDENT FUNTION
void printall(int Idnum[], char name[][31], char major[][31], float gpa[], int credits[], int *Content, int *MaxStudent)
{
    printf("STUDENT LIST:\n");

    if(*Content == 0)
    {
        printf("\nStudent list is Currently empty!");
        return;
    }

    printf("\n");
    
    printf("%6s | %15s | %15s | %6s | %7s\n", "ID", "Name", "Major", "GPA", "Credits");
    printf("----------------------------------------------------------------------\n");

    for(int i = 0; i < *Content; i++)
    {
        printf("%6d | %15.15s | %15.15s | %6.2f | %7d\n", Idnum[i], name[i], major[i], gpa[i], credits[i]);
        printf("----------------------------------------------------------------------\n");
    }

}
#include <stdio.h>
#include <stdlib.h>

//QUIZZ (TASK 1.1)
float inputScorequiz()
{
	float quiz;

	do
	{
		printf("Enter Quiz Score (0-100):");
		scanf("%f", &quiz);

		if(quiz < 0 || quiz > 100)
		{
			printf("Grade is out of range, Please press ENTER to try again!\n");
			getchar(); // para tangtang sa garbage value
			getchar(); // pause thing, 
			system("cls");
		}
	}while(quiz < 0 || quiz > 100);

	system ("cls");
	return quiz;
}

//EXAMM  (Task 1.2)
float inputScoreexam()
{
	float exam;
	do
	{
		printf("Enter Exam Score (0-100):");
		scanf("%f", &exam);

		if(exam < 0 || exam > 100 )
		{
			printf("Grade is out of range, Please press ENTER to try again!\n");
			getchar(); // para tangtang sa garbage value
			getchar(); // pause thing, 
			system("cls");
		}
	}while(exam < 0 || exam > 100);

	system ("cls");
	return exam;
}

//FINDING FINAL GRADE (task 2)
float calculateFinalGrade(float a, float b)
{
	float qz=a;
	float ex=b;
	float final = ((qz*0.4)+(ex*0.6));
	
	return final;
}

//Letter Grade (TASK 3) Broken permi hagbong ang student sa letter grade
void getLetterGrade(float finalg)
{
	if(finalg>=60 && finalg <70)
	{
		char range = 'D';
		printf("Letter Grade: %c\n", range);
	} 
	
	else if (finalg>=70 && finalg <80)
	{
		char range = 'C';
		printf("Letter Grade: %c\n", range);
	}
	
	else if (finalg>=80 && finalg <90)
	{
		char range = 'B';
		printf("Letter Grade: %c\n", range);
	}

	else if (finalg>=90 && finalg <100)
	{
		char range = 'A';
		printf("Letter Grade: %c\n", range);
	}
	
	else
	{
		char range = 'F';
		printf("Letter Grade: %c\n", range);
	}
	
}


//DISPlAY REPORT (TASK 4)
void displayReport()
{
	float Quiz;
	float Exam;
	float Finalgrade;
	printf("========== GRADE REPORT ==========\n");
	printf("Quiz Score:   %.2f\n", Quiz);
	printf("Exam Score:   %.2f\n", Exam);
	printf("Final Grade:  %.2f\n", Finalgrade);
	getLetterGrade(Finalgrade);
//	printf("%c", range);
	printf("==================================");
}



int main()
{
	float Quiz = 0.0;
	float Exam = 0.0;
	float Finalgrade = 0.0;
	
	char choice;

	
	do{
	system ("cls");
	Quiz = inputScorequiz();
	Exam = inputScoreexam();
	
	Finalgrade= calculateFinalGrade(Quiz,Exam);
	
//	char range = getrange(Finalgrade);
	displayReport();

	printf("\n\nProcess another grade? (Y/N): ");
	scanf(" %c", &choice);
	}
	while (choice == 'Y' || choice =='y');
	printf("\nThank you\n");

	return 0;
}
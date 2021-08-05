#include <stdio.h>
#define LEN 10
#define CSIZE 4
#define SCORES 3

struct name {
	char fname[LEN];
	char lname[LEN];
};

struct student {
	struct name FI;
	short int grade[SCORES];
	float average;
};

void inputGrades(struct student *students);
void calculateAverageGrade(struct student *students);
void getInfo(struct student *person);
void printAverageGrade(struct student *students);

int task5(void) {
	struct student students[CSIZE] = {
		{ { "Ivan", "Ivanov" } },
		{ { "Petr", "Petrov" } }, 
		{ { "Nikita", "Nikitin" } }, 
		{ { "Oleg", "Minin" } } 
	};
	int i;
	
	inputGrades(&students);
	calculateAverageGrade(&students);
	for(i=0; i<CSIZE; i++)
		getInfo(&students[i]);
	printAverageGrade(&students);
	
	puts("Program is finished.");
	return 0;
}

void printAverageGrade(struct student *students) {
	int i, j;
	float total;
	struct student *temp;
	
	for(temp = students, total = 0.0, i = 0; i < CSIZE; temp++, i++)
		total += temp->average;
	printf("Total average grade: %.2f.\n", total/CSIZE);
}

void getInfo(struct student *person) {
	int i;
	
	printf("%s %s has next grades: ",
			person->FI.lname, person->FI.fname);
	for(i = 0; i < SCORES; i++)
	printf("%hd ", person->grade[i]);  
	printf("\b. Average grade is %.2f.\n", person->average);

}

void calculateAverageGrade(struct student *students) {
	int i, j;
	float total;
	struct student *temp;
	
	for(temp = students, i = 0; i < CSIZE; total = 0.0, temp++, i++) {
		for(j = 0; j < SCORES; j++) 
			total += temp->grade[j];		
		temp->average = total / SCORES;
	}
}

void inputGrades(struct student *students) {
	int i, j;
	struct student *temp;
	
	for(temp = students, i = 0; i < CSIZE; temp++, i++) {
		printf("Enter %d scores for %s %s:\n",
			SCORES, temp->FI.fname, temp->FI.lname);
		for(j = 0; j < SCORES; j++) {
			while((scanf("%hd", &temp->grade[j]) != 1) ||
					((temp->grade[j] < 1) || (temp->grade[j] > 5) )) {
				scanf("%*s");
				puts("Grade is invalid. Please try again.");			
			}
		}	
	}
}

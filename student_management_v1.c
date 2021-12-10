#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENT 100 //Name an integer constant or real constant.
#define MAX_GRADE 10 //the compiler will replace the constant names you are using with their own values
#define MIN_GRADE 0
int n, i,choice, lowestGrade, highestGrade; //camelCase
int studentID[MAX_STUDENT]; //camelCase
float studentGrade[MAX_STUDENT], max, min, isValid; //camelCase
int MenuSystem(); //PascalCase
//OPTION 1:
int enterStudentInfo() {
	int isValid;	
			while  (isValid == 0 || n < 1 || n > MAX_STUDENT){
				printf("\n\t\t\t\t\t\t『 』Select the quantity to enter: ");
			    isValid = scanf("%d", &n);
			}
	for( i = 0; i < n; i++) {
	 do  {
	    printf("\n\t\t\t\t\t\t✽ Enter the ID of students: ");
	    isValid = scanf("%d", &studentID[i]);
	    if(isValid == 0 || studentID[i] < 0 ) {
        printf("\n\t\t\t\t\t\t╳ Invalid ╳, re-enter ▼\n") ;
       } fflush(stdin);
	 }  while  ( isValid == 0|| studentID[i] < 0 );	
	 do  {
	    printf("\t\t\t\t\t\t✽ Enter grade of the students: ");
	    isValid = scanf("%f", &studentGrade[i]);
	    if(studentGrade[i] < MIN_GRADE || studentGrade[i] > MAX_GRADE || isValid == 0 ) {
	    printf("\n\t\t\t\t\t\t╳ Invalid ╳, re-enter ▼\n");
	    } fflush(stdin);
	 }  while  (studentGrade[i] < MIN_GRADE || studentGrade[i] > MAX_GRADE ||isValid == 0 );
	}
	viewStudentInfo();
}
//OPTION 2:
int viewStudentInfo() {
    printf("\n\t\t\t\t\t\t\t\t|  ID\t\t\t|  Grade  ");
	printf("\n\t\t\t\t\t\t\t\t________________________________");
	for( i = 0; i < n; i++) {
	printf("\n\n\t\t\t\t\t\t\t\t| %d", studentID[i]);
	printf("\t\t\t| %.2f", studentGrade[i]);
	}	
}
//OPTION 3:
int viewHighestGrade() {
	max = studentGrade[0];
// Declare the variable max array studentGrade whose value is 0
	for( i = 0; i < n; i++) {
		if( max < studentGrade[i]) { //With studentGrade[i] greater than array max
			max = studentGrade[i]; 
//Assign the variable max to be the value of the largest number of points in the array
		    highestGrade = studentID[i]; 
//get studentID equal to the value of the student with the highest grade
			}
		}
	printf("\n\n\t\t\t\t\t\t\t============================RESULT===========================");
//Print the screen with the Highest grade & ID
	printf("\n\n\t\t\t\t\t\t\tStudent has highest grade: %.3f", max);
	for(i = 0; i < n; i++) {
        if(studentGrade[i] == max) printf("\n\t\t\t\t\t\t\tStudent ID: %3d\n", studentID[i]);  
	}
}	
//OPTION 4:
int viewLowestGrade() {
	min = studentGrade[0]; 
// Declare the variable min array studentGrade whose value is 0
	for( i = 0; i < n; i++) {
		if(min > studentGrade[i]) { //With studentGrade[i] smaller than array max
			min = studentGrade[i]; 
// Assign the variable min to be the value of the smallest number of points in the array			lowestGrade = studentID[i];
			}
		}
	printf("\n\n\t\t\t\t\t\t\t============================RESULT===========================");
//Print the screen with the lowest grade & ID
	printf("\n\n\t\t\t\t\t\t\tStudent has lowest grade: %.3f", min);
	for(i = 0; i < MAX_STUDENT; i++) {
        if(studentGrade[i] == min) printf("\n\t\t\t\t\t\t\tStudent ID: %3d\n", studentID[i]);
	    }
	}		
//MENU 		
int MenuSystem() {	
	switch (choice) {
		case 1: 
		    enterStudentInfo(); //enter student information 
			break;	
		case 2: viewStudentInfo(); //view all information
			break;
		case 3: viewHighestGrade(); //view highest grade
			break;
	    case 4: viewLowestGrade();	//view lowest grade	
			break;
	    case 5: printf("\t\t\t\t\t\tGOODBYE!"); //goodbye
		exit(0);
			break;
	    default:
			break;
    }
  }

int main() {
	 while (choice != 5){ 
		viewMenu(); //If not in the value, return viewmenu, menusystem
		MenuSystem();
	 };
}
int viewMenu() {
    printf("\n\n\t\t\t\t\t\t ================== ( ͡° ͜ʖ ͡°) MENU SYSTEM ( ͡° ͜ʖ ͡°) ======================\n");
    printf("\t\t\t\t\t\t |_____________________________________________________________________|\n");
    printf("\t\t\t\t\t\t |              𝟙: Enter your student's id and grade                   |\n");
    printf("\t\t\t\t\t\t |_________________________________ʕ•ᴥ•ʔ_______________________________|\n");
    printf("\t\t\t\t\t\t |              𝟚: View all student information                        |\n");
    printf("\t\t\t\t\t\t |_______________________________(՞•ﻌ•՞)۶______________________________|\n");
    printf("\t\t\t\t\t\t |              𝟛: View highest student grade                          |\n");
    printf("\t\t\t\t\t\t |________________________________ಠ_ಠ__________________________________|\n");
	printf("\t\t\t\t\t\t |              𝟜: View lowest student grade                           |\n");
    printf("\t\t\t\t\t\t |____________________________ᕕʕ •ₒ• ʔ୨________________________________|\n");
    printf("\t\t\t\t\t\t |              𝟝: Exit the program                                    |\n");
    printf("\t\t\t\t\t\t |_______________________________ʕ ˵• ₒ •˵ ʔ___________________________|\n\n");
	printf("\t\t\t\t\t\tEnter your choice here: ");
 	scanf("%d", &choice);
    fflush(stdin);
	return 0;
}
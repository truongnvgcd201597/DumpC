#include <stdio.h>
#include <stdlib.h>
#define MAX_STUDENT 100
int studentID[MAX_STUDENT];
float Grade[MAX_STUDENT];
int n, enterInfo(), viewInfo(), highestGrade(), lowestGrade();
int enterInfo() {
    printf("\n\t\t\t\t\t\t\t\tPlease input number of student: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\n\t\t\t\t\t\t\t\tStudent ID %d: ", i+1);
        scanf("%d", &studentID[i]);
        printf("\n\t\t\t\t\t\t\t\tStudent Grade %d: ", i+1);
        scanf("%f", &Grade[i]);
    }
}
int viewInfo(){
    for (int i = 0; i < n; i++) {
        printf("\n\t\t\t\t\t\t\t\tStudent has ID %d: %d\n",i+1,studentID[i]);
        printf("\n\t\t\t\t\t\t\t\tGrade %d: %.3f\n",i+1,Grade[i]);
    }
}
int highestGrade(){
    float highestStudentGrade = Grade[0];
    int highestStudentID = studentID[0];
    for (int i = 0; i < n; i++) {
        if (highestStudentGrade < Grade[i]) {
        highestStudentGrade = Grade[i];
        highestStudentID = studentID[i];
      }
    }
    printf("\n\t\t\t\t\t\t\t\t───────────────────────────HIGHEST GRADE STUDENT───────────────────────────");
    printf("\n\t\t\t\t\t\t\t\tID: %d",highestStudentID);
    printf("\n\t\t\t\t\t\t\t\tGrade: %f",highestStudentGrade);
}
int lowestGrade(){
    float lowestStudentGrade = Grade[0];
    int lowestStudentID = studentID[0];
    for (int i = 0; i < n; i++) {
        if (lowestStudentGrade > Grade[i]) {
        lowestStudentGrade = Grade[i];
        lowestStudentID = studentID[i];
        }
    }
    printf("\n\t\t\t\t\t\t\t\t───────────────────────────LOWEST GRADE STUDENT───────────────────────────");
    printf("\n\t\t\t\t\t\t\t\tID: %d\n",lowestStudentID);
    printf("\n\t\t\t\t\t\t\t\tGrade: %f\n",lowestStudentGrade);  
}

int main(){ 
	int option;
    do
    {
        printf("\n\t\t\t\t\t\t\t\t─────────────────────────────────Menu─────────────────────────────────");
        printf("\n\t\t\t\t\t\t\t\t                  1.Enter student information.");
        printf("\n\t\t\t\t\t\t\t\t──────────────────────────────────────────────────────────────────────");
        printf("\n\t\t\t\t\t\t\t\t                  2.View student information.");
        printf("\n\t\t\t\t\t\t\t\t──────────────────────────────────────────────────────────────────────");
        printf("\n\t\t\t\t\t\t\t\t                  3.Student with highest grade.");
        printf("\n\t\t\t\t\t\t\t\t──────────────────────────────────────────────────────────────────────");
        printf("\n\t\t\t\t\t\t\t\t                  4.Student with lowest grade.");
        printf("\n\t\t\t\t\t\t\t\t──────────────────────────────────────────────────────────────────────");
        printf("\n\t\t\t\t\t\t\t\t                  5.Exit the program.");
        printf("\n\t\t\t\t\t\t\t\t──────────────────────────────────────────────────────────────────────");
        printf("\n\t\t\t\t\t\t\t\tChoose option: ");
        scanf("%d",&option);
        switch (option) {
        case 1: enterInfo();
            break;
        case 2:viewInfo();
            break;
        case 3:highestGrade();
            break;
        case 4:lowestGrade();
            break;
        case 5:exit(0);
        default:printf("\n\t\t\t\t\t\t\t\tPlease re-try again");
            break;
        }
    } while (1 < option < 5);
    return 0;
}
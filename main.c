#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_STUDENTS        100
#define MAX_STUDENTS_NAME   100
#define MAX_COURSE_NAME     20  
#define MAX_COURSES         3

#define SAVE_NAME           "archive.txt"
#define MAX_DATA_LEN        150


int main();
int choice();
void average();
void addStudent();
void listStudents();


char students[MAX_STUDENTS][MAX_STUDENTS_NAME];
char courses[MAX_COURSES][MAX_COURSE_NAME];
float grades[MAX_STUDENTS][MAX_COURSES];
int qty_students = 0;


void loadData() {

    FILE * data;
    
    char line[MAX_DATA_LEN];
    data = fopen(SAVE_NAME, "r");
    
    while (fgets(line, MAX_DATA_LEN, data)) {

        sscanf(line, "%f|%f|%f|%s", &grades[qty_students][0], &grades[qty_students][1], &grades[qty_students][2], students[qty_students]);
        qty_students ++;
    } 

    fclose(data);
}

void saveData() {
    FILE * data;

    data = fopen(SAVE_NAME, "w");

    for (int i = 0; i < qty_students; i++){
        fprintf(data, "%.2f|%.2f|%.2f|%s\n", grades[qty_students][0], grades[qty_students][1], grades[qty_students][2], students[qty_students]);
    }

    fclose(data);
}


int choice() {

  int userChoice;

  puts("\n-------------------------------");
  puts("|      1 - ADD STUDENT        |");
  puts("|      2 - STUDENT AVERAGE    |");
  puts("|      3 - LIST STUDENTS      |");
  puts("|      4 - SAVE DATA          |");
  puts("|      0 - GET OUT            |");
  puts("-------------------------------");
  printf("> ");
  scanf("%i", &userChoice);

  return userChoice;
}


void addStudent() {

    float student_grade1, student_grade2, student_grade3;
    char student_name[MAX_STUDENTS_NAME];

    printf("\nName: ");
    scanf("%s", student_name);
    
    printf("\nGrade 1: ");
    scanf("%f", &student_grade1);
    
    printf("\nGrade 2: ");
    scanf("%f", &student_grade2);
    
    printf("\nGrade 3: ");
    scanf("%f", &student_grade3);
    
    strcpy(students[qty_students], student_name);
    grades[qty_students][0] = student_grade1;
    grades[qty_students][1] = student_grade2;
    grades[qty_students][2] = student_grade3;

    qty_students ++;

}


void listStudents() {

    for (int i = 0; i < qty_students; i++) {
        printf("\nName: %s | Grade 1: %.2f | Grade 2: %.2f | Grade 3: %.2f\n", students[i], grades[i][0], grades[i][1], grades[i][2]);
    }

}


void average() {

    char student_search[MAX_STUDENTS_NAME];
    float student_average;
    int i;

    printf("\nName: ");
    scanf("%s", student_search);

    for (i = 0; i < qty_students; i++) {
        if (strcmp(student_search, students[i]) == 0) {
            student_average = (grades[i][0] + grades[i][1] + grades[i][2]) / 3.0;
            break;
        }
    } 

    printf("\nGrade 1: %i | Grade 2: %i | Grade 3: %i\nAverage: %.2f", grades[i][0], grades[i][1], grades[i][2], student_average);
}


int main() {
    loadData();

    for (;;) {

        switch (choice()) {
        case 1:
            addStudent();
            break;
        case 2:
            average();
            break;
        case 3:
            listStudents();
            break;
        case 4:
            saveData();
            break;
        case 0:
            exit(0);
            break;

        }
    }
}

#include <stdio.h>
#include <string.h>

typedef struct {
    char name [20];
    char student_id [11]; // Assuming 10 digits.
    unsigned mark;
} student;

int main () {
    // Data generated using ChatGPT.
    int number_of_students = 10, i;
    student students [number_of_students];

    for (i=0; i<number_of_students; i++){
        char name[20];
        char studentid[11];
        unsigned mark;

        printf("-------------\n");
        printf("enter student name: ");
        scanf("%s",name);
        printf("enter student ID: ");
        scanf("%s",studentid);
        printf("enter final mark: ");
        scanf("%o",&mark);

        strcpy(students[i].name, name);
        strcpy(students[i].student_id, studentid);
        students[i].mark = mark;

    }


    for (i = 0; i < number_of_students; i++) {
        printf("-------------\n");
        printf("Student name: %s\n", students[i].name);
        printf("Student ID: %s\n", students[i].student_id);
        printf("Final mark: %u\n", students[i].mark);
    }
    printf("-------------\n");
    return 0;
}
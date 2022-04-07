#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
    char name[20];
    int age;
    char grade;
} Student;

void string_print(char const s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}

void student_print(const Student *X)
{
    printf("Name:  ");
    string_print(X->name);
    printf("Age:   %d\n", X->age);
    printf("Grade: %c\n", X->grade);
}

void student_array_print_table(const Student *students_arr, int size)
{
    printf("+--------------------+--------------------+--------------------+\n");
    printf("|        Name        |         Age        |        Grade       |\n");
    printf("+--------------------+--------------------+--------------------+\n");
    for (int i = 0; i < size; i++)
    {
        printf("|%-20s|%-20d|%-20c|\n", students_arr[i].name, students_arr[i].age, students_arr[i].grade);
        printf("+--------------------+--------------------+--------------------+\n");
    }
}

void student_array_print(const Student *students_arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        student_print(&students_arr[i]);
        printf("\n=========================\n");
    }
    
}

int main()
{
    Student class[10] = {
        {.name = "Ahmed Harbi",      .age = 22, .grade = 'C'},
        {.name = "Mostafa Ahmed",    .age = 23, .grade = 'A'},
        {.name = "Khaled Ali",       .age = 21, .grade = 'B'},
        {.name = "Omar Alaa",        .age = 20, .grade = 'F'},
        {.name = "Mohamed Khaled",   .age = 24, .grade = 'D'},
        {.name = "Abdullah Mohamed", .age = 19, .grade = 'C'},
        {.name = "Amr Alaa",         .age = 26, .grade = 'B'},
        {.name = "Youssef Mohamed",  .age = 27, .grade = 'D'},
        {.name = "Omar Ali",         .age = 25, .grade = 'A'},
        {.name = "Mohamed Ahmed",    .age = 18, .grade = 'F'},
    };
    student_array_print_table(class, 10);
    return 0;
}
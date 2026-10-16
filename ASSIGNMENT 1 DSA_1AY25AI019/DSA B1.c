#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Structure definition
struct Student {
    int roll_no;
    char name[20];
    float marks;
};
int main() {
    struct Student *ptr;   // pointer to Student
    int n, i;
    float sum = 0.0;
    struct Student *highest;
    // Step (a): Ask user for n and allocate memory
    printf("Enter number of students: ");
    scanf("%d", &n);
    ptr = (struct Student*) malloc(n * sizeof(struct Student));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    // Step (b): Read n records
    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i+1);
        printf("Roll No: ");
        scanf("%d", &(ptr+i)->roll_no);
        printf("Name: ");
        scanf("%s", (ptr+i)->name);
        printf("Marks: ");
        scanf("%f", &(ptr+i)->marks);
    }
    // Step (c): Compute average and highest marks
    highest = ptr;  // assume first student has highest marks
    for (i = 0; i < n; i++) {
        sum += (ptr+i)->marks;
        if ((ptr+i)->marks > highest->marks) {
            highest = (ptr+i);
        }
    }
    printf("\nAverage Marks = %.2f\n", sum/n);
    printf("Student with Highest Marks:\n");
    printf("Roll No: %d\n", highest->roll_no);
    printf("Name: %s\n", highest->name);
    printf("Marks: %.2f\n", highest->marks);
    // Step (e): Ask if user wants to add 2 more students
    char choice;
    printf("\nDo you want to add 2 more students? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        ptr = (struct Student*) realloc(ptr, (n+2) * sizeof(struct Student));
        if (ptr == NULL) {
            printf("Reallocation failed!\n");
            return 1;
        }
        for (i = n; i < n+2; i++) {
            printf("\nEnter details of student %d:\n", i+1);
            printf("Roll No: ");
            scanf("%d", &(ptr+i)->roll_no);
            printf("Name: ");
            scanf("%s", (ptr+i)->name);
            printf("Marks: ");
            scanf("%f", &(ptr+i)->marks);
        }
        n += 2; // update total count
    }    // Step (d): Free memory
free(ptr);
return 0;
}


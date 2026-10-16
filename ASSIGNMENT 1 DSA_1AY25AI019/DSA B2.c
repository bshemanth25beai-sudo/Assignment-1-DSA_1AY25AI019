#include <stdio.h>
#include <stdlib.h>
// Define Employee structure
typedef struct {
    char name[20];
    int emp_id;
    enum { FULL_TIME, CONTRACT } type;
    union {
        float salary;   // for full-time employees
        struct {
            float hourly_rate;
            int hours_worked;
        } contract_info; // for contract employees
    } pay;} Employee;
int main() {
    int n, i;
    float total_bill = 0.0, pay;
    Employee *e;
 // (a) Read number of employees and allocate memory
    printf("Enter number of employees: ");
    scanf("%d", &n);
 e = (Employee*) malloc(n * sizeof(Employee));
    if (e == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
 // (b) Read employee details
    for (i = 0; i < n; i++) {
        printf("\nEnter details of Employee %d:\n", i+1);
        printf("Name: ");
        scanf("%19s", (e+i)->name);
        printf("Employee ID: ");
        scanf("%d", &(e+i)->emp_id);
        int choice;
        printf("Type (0 for FULL_TIME, 1 for CONTRACT): ");
        scanf("%d", &choice);
        (e+i)->type = (choice == 0) ? FULL_TIME : CONTRACT;
        if ((e+i)->type == FULL_TIME) {
            printf("Monthly Salary: ");
            scanf("%f", &(e+i)->pay.salary);
        } else {
            printf("Hourly Rate: ");
            scanf("%f", &(e+i)->pay.contract_info.hourly_rate);
            printf("Hours Worked: ");
            scanf("%d", &(e+i)->pay.contract_info.hours_worked);
        }
    }
    // (c) Print payslip for each employee
    printf("\n--- Employee Payslips ---\n");
    for (i = 0; i < n; i++) {
        if ((e+i)->type == FULL_TIME) {
            pay = (e+i)->pay.salary;
            printf("\nName: %s\nID: %d\nType: Full-Time\nTotal Pay: %.2f\n",
                   (e+i)->name, (e+i)->emp_id, pay);
        } else {
            pay = (e+i)->pay.contract_info.hourly_rate *
                  (e+i)->pay.contract_info.hours_worked;
            printf("\nName: %s\nID: %d\nType: Contract\nTotal Pay: %.2f\n",
                   (e+i)->name, (e+i)->emp_id, pay);
        }
        total_bill += pay;
    }
    // (d) Print total salary bill
    printf("\nTotal Salary Bill of Company = %.2f\n", total_bill);
    // Free memory
    free(e);
    return 0;
}



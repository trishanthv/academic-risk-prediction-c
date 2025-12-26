#include <stdio.h>
#include <string.h>

struct student {
    int id;
    char name[50];
    int marks[5];
    int attendance;
    float average;
    char risk[15];
};

int main() {
    struct student s[50];
    int n, i, j;
    int sum;

    printf("ACADEMIC RISK PREDICTION SYSTEM\n");
    printf("--------------------------------\n");

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d\n", i + 1);

        printf("Student ID: ");
        scanf("%d", &s[i].id);

        printf("Student Name: ");
        scanf("%s", s[i].name);

        sum = 0;
        for (j = 0; j < 5; j++) {
            printf("Enter marks for subject %d: ", j + 1);
            scanf("%d", &s[i].marks[j]);
            sum += s[i].marks[j];
        }

        printf("Enter attendance percentage: ");
        scanf("%d", &s[i].attendance);

        s[i].average = sum / 5.0;

        if (s[i].average < 40 || s[i].attendance < 60) {
            strcpy(s[i].risk, "High Risk");
        } else if (s[i].average < 60) {
            strcpy(s[i].risk, "Medium Risk");
        } else {
            strcpy(s[i].risk, "Low Risk");
        }
    }

    printf("\n\nACADEMIC RISK ANALYSIS REPORT\n");
    printf("------------------------------------------------------------\n");
    printf("ID\tName\tAverage\tAttendance\tRisk Level\n");
    printf("------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\t%d%%\t\t%s\n",
               s[i].id,
               s[i].name,
               s[i].average,
               s[i].attendance,
               s[i].risk);
    }

    printf("------------------------------------------------------------\n");
    printf("Analysis completed successfully.\n");

    return 0;
}

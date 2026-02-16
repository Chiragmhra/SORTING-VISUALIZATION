#include <stdio.h>
#include "patient.h"

// It is the function to add patients.
void addpatient() {
    // Opening patient.txt.
    FILE *p = fopen("patient.txt", "w+");
    if (p != NULL) {
        int n;
        printf("Enter number of patients: ");
        scanf("%d", &n);
        getchar();

        struct patient s[n];
        // Loop for inputing details of patients.
        for (int i = 0; i < n; i++) {
            printf("Enter patient %d name: ", i + 1);
            fgets(s[i].name, 25, stdin);
            s[i].id=i+1;
            printf("Enter Date in format(dd-mm-yy) : ");
            scanf("%s", s[i].date);
            getchar();
            printf("Enter gender (M/F): ");
            scanf("%c", &s[i].gen);
            getchar();
            printf("Enter disease: ");
            fgets(s[i].dis, 25, stdin);
        }
        // Loop for printing details of patients.
        for (int i = 0; i < n; i++) {
            fprintf(p, "NAME: %sID: %d | Gender: %c | Date: %s | Disease: %s\n", s[i].name, s[i].id,  s[i].gen, s[i].date, s[i].dis);
        }

        fclose(p);
    } else {
        printf("Error opening patient.txt\n");
    }
}

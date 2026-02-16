#include <stdio.h>
#include<string.h>
#include "doctor.h"

// It is the fuction which operates doctor module.
void adddoctor() {
    // Opening doctor.txt.
    FILE *q = fopen("doctor.txt", "w+");
    if (q != NULL) {
        int n;
        printf("Enter number of doctors: ");
        scanf("%d", &n);
        getchar();

        struct doctor d[n];

    // Loop for adding doctor details and printing in the file.
        for (int i = 0; i < n; i++) {
            printf("\n--- Doctor %d ---\n", i+1);
            printf("Enter doctor ID : ");
            scanf("%d", &d[i].id);
            getchar();
            printf("Enter Name : ");
            fgets(d[i].name,sizeof(d[i].name),stdin);
            d[i].name[strcspn(d[i].name, "\n")]='\0';
            printf("Enter specialization : ");
            fgets(d[i].type,sizeof(d[i].type),stdin);
            d[i].type[strcspn(d[i].type, "\n")]='\0';
            printf("Enter the Date(dd-mm-yy) : ");
            scanf("%s", d[i].date);
            printf("Enter start time (ex : 0900) : ");
            scanf("%d", &d[i].stime);
            printf("Enter end time (ex : 1700) : ");
            scanf("%d", &d[i].etime);
            getchar();

            fprintf(q, "%d\t%s\t%s\t%s\t%d\t%d\n", d[i].id, d[i].name, d[i].type, d[i].date, d[i].stime, d[i].etime);

        }

        
        fclose(q);
        printf("\nDoctors added successfully\n");
    } else {
        printf("Error opening doctor.txt\n");
    }
}

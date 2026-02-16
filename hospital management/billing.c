#include <stdio.h>
#include<string.h>
#include "billing.h"

// This function will calculaate the bill for patient.
void billing() {
    char name[50], diagnosis[50];
    int ch, n, total = 0;
    FILE *u;

    getchar();
    printf("Enter Patient Name: ");
    fgets(name,sizeof(name),stdin);  
    name[strcspn(name, "\n")] = '\0';
    printf("Enter diagnosis : ");
    scanf(" %[^\n]", diagnosis);
    // Using switch case since number of choice is greater.
    while(1) {
        printf("\n--- Consultation Menu ---\n");
        printf("1. General Consultation : 500\n");
        printf("2. Blood Test : 300\n");
        printf("3. X-ray : 800\n");
        printf("4. Room charges(per day) : 1500\n");
        printf("5. Finish and Generate Bill\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                total += 500;
                printf("Added General Consultation\n");
                break;
            case 2:
                total += 300;
                printf("Added Blood Test\n");
                break;
            case 3:
                total += 800;
                printf("Added X-ray\n");
                break;
            case 4:
                printf("Enter number of days : ");
                scanf("%d", &n);
                total += n*1500;
                printf("Added Room charges\n");
                break;
            case 5:
                goto end_loop;
            default:
                printf("Invalid choice\n");
        }
    }  

    end_loop:
    //opening bill.txt
    u = fopen("bill.txt", "w");
    if (u == NULL) {
        printf("Error in opening file.\n");
        return;
    }
    // Printing bill in bill.txt
    fprintf(u, "Name : %s | Diagnosis : %s | Bill(in rupees) : %d\n", name, diagnosis, total);
    fclose(u);

    printf("\n Bill generated for %s : %d\n", name, total);

}


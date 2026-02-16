#include <stdio.h>
#include <stdlib.h>
#include "patient.h"
#include "doctor.h"
#include "appointment.h"
#include "view.h"
#include "billing.h"

void addpatient();
void adddoctor();
void scheduleap();
void view();
void billing();
// These are our modules which are connected to main.
void mainMenu() {
    int choice;
    while (1) {
        printf("\n--- Hospital Management System ---\n");
        printf("1 : Add Patient\n");
        printf("2 : Add Doctor\n");
        printf("3 : Schedule Appointment\n");
        printf("4 : View Details\n");
        printf("5 : Billing\n");
        printf("6 : Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    // switch case since number of choice is more.
        switch (choice) {
            case 1:
                addpatient();
                break;
            case 2:
                adddoctor();
                break;
            case 3:
                scheduleap();
                break;  
            case 4:
                view(); 
                break;  
            case 5:
                billing();
                break;       
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    mainMenu();
    // main menu function contains switch case to control all modules.
    return 0;
}


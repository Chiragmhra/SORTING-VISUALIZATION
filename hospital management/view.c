#include<stdio.h>
#include "view.h"
// Fuction for viewing different txt files.
void viewfile(const char *filename){
    // opening file.
    FILE *t=fopen(filename,"r");
    if(t!=NULL){
        char c;
        while ((c=fgetc(t))!=EOF)
        putchar(c);

        fclose(t);
    }
    else{
        printf("Error in opening %s\n", filename);
    }
    return;
}
// Function which controls viewing details module.
void view(){
    int ch;
    // Using switch case since number of choice is more.
    while(1){
        printf("\n--- View Menu ---\n");
        printf("1. View Patients\n");
        printf("2. View Doctors\n");
        printf("3. View Appointments\n");
        printf("4. View Bills\n");
        printf("5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
    

    switch(ch){
        case 1:
        printf("\n--- Patients ---\n");
        viewfile("patient.txt");
        break;
        case 2:
        printf("\n--- Doctors ---\n");
        viewfile("doctor.txt");
        break;
        case 3:
        printf("\n--- Appointments ---\n");
        viewfile("appointment.txt");
        break;
        case 4:
        printf("\n--- Bills ---\n");
        viewfile("bill.txt");
        break;
        case 5:
        return;
        default:
        printf("Invalid Choice");
        break;
    }
}
            
}
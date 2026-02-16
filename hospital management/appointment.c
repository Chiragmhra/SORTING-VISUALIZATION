#include<stdio.h>
#include<string.h>
#include "appointment.h"


//This function schedules appointments.
void scheduleap() {
    FILE *r = fopen("doctor.txt", "r");
    if (r == NULL) {
        printf("Error opening doctor file.\n");
        return;
    }

    struct apdoctor d[50];
    int c = 0;

    // Reading doctor details
    while (fscanf(r, "%d %s %s %s %d %d", &d[c].id, d[c].name, d[c].type, d[c].date, &d[c].stime, &d[c].etime) == 6) {
        c++;
    }    
    //Show available doctors
    printf("\nAvailable Doctors:\n");
    for (int i = 0; i < c; i++) {
        printf("%d. Dr. %s (%s) - Date: %s, Time: %d to %d\n", d[i].id, d[i].name, d[i].type, d[i].date, d[i].stime, d[i].etime);
    }

    // Takes Input from user
    int id, time;
    char date[11];
    printf("\nEnter Doctor ID: ");
    scanf("%d", &id);
    printf("Enter appointment time (e.g., 1000): ");
    scanf("%d", &time);
    printf("Enter appointment date (dd-mm-yyyy): ");
    scanf("%s", date);

    // Search doctor ID
    int found = 0;
    for (int i = 0; i < c; i++) {
        if (d[i].id == id) {
            found = 1;

            if (time >= d[i].stime && time <= d[i].etime && strcmp(d[i].date, date) == 0) {
                // Check clash
                FILE *s = fopen("appointment.txt", "a+");
                if (s != NULL) {
                    rewind(s);
                    int t_id, t_time;
                    char t_name[25], t_date[11];
                    int clash = 0;

                    while (fscanf(s, "ID: %d, Name: %s, Time: %d, Date: %s\n", &t_id, t_name, &t_time, t_date) == 4) {
                        if (t_id == id && t_time == time && strcmp(t_date, date) == 0) {
                            clash = 1;
                            break;
                        }
                    }

                    if (clash) {
                        printf("Clash! Doctor already has an appointment at this time and date.\n");
                    } else {
                        fseek(s,0,SEEK_END);
                        printf("Writing in file\n");
                        fprintf(s, "ID: %d, Name: %s, Time: %d, Date: %s\n", id, d[i].name, time, date);
                        printf("Appointment scheduled with Dr. %s at %d on %s\n", d[i].name, time, date);
                    }

                    fclose(s);
                } 
                else {
                    printf("Error opening appointment.txt\n");
                }
            } else {
                printf("Doctor is not available at this time or date.\n");
            }

            break;
        }
    }

    if (!found) {
        printf("Doctor ID not found.\n");
    }
}








#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for treatments
struct Treatment {
    int id;
    char name[100];
    int cost;
};

// Predefined treatments
struct Treatment treatments[] = {
    {1, "General Checkup", 500},
    {2, "Blood Test", 800},
    {3, "X-Ray", 1000},
    {4, "MRI Scan", 5000},
    {5, "Surgery Consultation", 2000}
};

int treatmentCount = sizeof(treatments) / sizeof(treatments[0]);

// Display all available treatments
void showAvailableTreatments() {
    printf("\n=== Available Treatments ===\n");
    for (int i = 0; i < treatmentCount; i++) {
        printf("%d. %s - ₹%d\n", treatments[i].id, treatments[i].name, treatments[i].cost);
    }
}

// Record treatment for a patient
void recordTreatment() {
    int patientID, treatmentID;

    printf("Enter Patient ID: ");
    scanf("%d", &patientID);

    showAvailableTreatments();
    printf("Select Treatment ID to record: ");
    scanf("%d", &treatmentID);

    int found = 0;
    for (int i = 0; i < treatmentCount; i++) {
        if (treatments[i].id == treatmentID) {
            FILE *fp = fopen("treatment_records.txt", "a");
            if (fp == NULL) {
                printf("Error opening treatment_records.txt\n");
                return;
            }

            fprintf(fp, "PatientID: %d\nTreatment: %s\nCost: %d\n\n",
                    patientID, treatments[i].name, treatments[i].cost);

            fclose(fp);
            printf("✅ Treatment recorded successfully for Patient ID %d.\n", patientID);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("❌ Invalid Treatment ID.\n");
    }
}

// Show treatment history for a patient
void showPatientTreatmentHistory() {
    int patientID;
    printf("Enter Patient ID to view treatment history: ");
    scanf("%d", &patientID);

    FILE *fp = fopen("treatment_records.txt", "r");
    if (fp == NULL) {
        printf("❌ No treatment records found.\n");
        return;
    }

    char line[256], treatment[100];
    int id, cost, match = 0;

    printf("\n--- Treatment History for Patient ID %d ---\n", patientID);

    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "PatientID: %d", &id) == 1 && id == patientID) {
            match = 1;

            fgets(line, sizeof(line), fp);
            sscanf(line, "Treatment: %[^\n]", treatment);

            fgets(line, sizeof(line), fp);
            sscanf(line, "Cost: %d", &cost);

            printf("Treatment: %-30s | Cost: ₹%d\n", treatment, cost);

            // skip blank line
            fgets(line, sizeof(line), fp);
        }
    }

    if (!match) {
        printf("❌ No treatments found for this patient.\n");
    }

    fclose(fp);
}

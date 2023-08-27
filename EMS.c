#include <stdio.h>
#include <string.h>

void student_details();
void print_hallticket(const char *name, const char *gender, const char *dob, const char *email, const char *phone_no, const char *ID, const char *BoardName, const char *Grade,const char *hallticket);
void allocate_hall_ticket(char *hall_ticket, const char *ID);

int main() {
    student_details();
    return 0;
}

void student_details() {
    char name[50], gender[2], dob[11], email[50], phone_no[11];
    char ID[20];
    char BoardName[10], Grade[2];
    char hall_ticket[10];

    printf("\t\t\t\t\t STUDENT DETAILS\t\t\t\t\t\n\n\n");
    printf("\t\t\tPlease enter all the details accurately\n\n\n");

    printf("\t\t\tStep 1: Personal Information \t\t\t \n\n");

    printf("Name: ");
    gets(name);

    printf("Sex(MF): ");
    gets(gender);

    printf("Date of birth (dd/mm/yyyy): ");
    gets(dob);

    printf("Email ID: ");
    gets(email);
    printf("Phone Number(10 digits):");
    gets(phone_no);

    printf("\n\t\t\t Step 2 : Identification \t\t\t \n");

    printf("Please enter your student identification number\n");
    gets(ID);

    printf("\n\t\t\t Step 3 : Previous Year Information \t\t\t\n");
    printf("Provide the Board acronym and the grade allotted\n");

    printf("Board Acronym: ");
    gets(BoardName);

    printf("Grade: ");
    scanf("%1s", Grade);

    // Generate and allocate hall ticket
    allocate_hall_ticket(hall_ticket, ID);

    // Print confirmation and report card
    printf("\n\t\t\t CONFIRM DATA ENTRY \t\t\t \n\n\n");
    printf("\t\t Personal Information\t\t\t\nName: %s\nGender: %s\nDate Of Birth: %s\nEmail: %s\nPhone Number: %s\n", name, gender, dob, email, phone_no);
    printf("\n\t\t\t Identification \t\t\t \n");
    printf("Identification Number : %s \n", ID);
    printf("\n\t\t\t Previous Study Information \t\t\t\n");
    printf("BoardName : %s\n", BoardName);
    printf("Grade: %s\n", Grade);
    
    // Add payment information here if needed

    printf("\t\t Hall Ticket \t\t\n");
    printf("Hall Ticket Number: %s\n", hall_ticket);

    // Write report card to a file
    print_hallticket(name, gender, dob, email, phone_no, ID, BoardName, Grade,hall_ticket);
}

void print_hallticket(const char *name, const char *gender, const char *dob, const char *email, const char *phone_no, const char *ID, const char *BoardName, const char *Grade,const char *hallticket) {
    FILE *report_file = fopen(hallticket, "w");

    if (report_file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(report_file, "\t\t\t\t\t HALL TICKET \t\t\t\n\n");
    fprintf(report_file, "\t\t\t BMS Institute of Technology and Management  \t\t\t\n\n");

    fprintf(report_file, "Name: %s\n", name);
    fprintf(report_file, "Hall Ticket Number: %s\n", hallticket);
    fprintf(report_file, "Gender: %s\n", gender);
    fprintf(report_file, "Date of Birth: %s\n", dob);
    // fprintf(report_file, "Email: %s\n", email);
    // fprintf(report_file, "Phone Number: %s\n", phone_no);
    fprintf(report_file, "ID: %s\n", ID);
    // fprintf(report_file, "Board Name: %s\n", BoardName);
    // fprintf(report_file, "Grade: %s\n", Grade);
    fprintf(report_file,"\n\n\n\t\t COE Signature \t\t\t\t\t Student Signature  ");

    fclose(report_file);
}

void allocate_hall_ticket(char *hall_ticket, const char *ID) {

    snprintf(hall_ticket, 10, "HT%s", ID + strlen(ID) - 5);
}

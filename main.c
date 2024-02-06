#include <stdio.h>

struct sdata {
    char studname[30]; // student name
    int rollno;        // student roll no
    int scontact;      // student contact no
    char email[30];
    int pcontact;      // parents contact no
    float fees;        // fees
    float rfees;       // remaining fees
};

struct sdata studentdata[100];
int noofstudent = 0;

void addstudent();
void getstudent();
void stram(int index);

int main() {
    int choice;

    do {
        printf("\nTotal students data we have: %d / 100\n", noofstudent);
        printf("1] Add student data\n");
        printf("2] Get student data\n");
        printf("3] Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addstudent();
                break;

            case 2:
                getstudent();
                break;

            case 3:
                // Exit
                printf("Exiting the program.\n");
                break;

            default:
                printf("\nInvalid option. Try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

void addstudent() {
    printf("\n*** Add New Student Information ***\n");

    if (noofstudent >= 100) {
        printf("Your Limit is over.\n");
        return;
    }

    printf("\nEnter student's name: ");
    scanf("%s", studentdata[noofstudent].studname);

    printf("Enter Roll No: ");
    scanf("%d", &studentdata[noofstudent].rollno);

    printf("Enter Phone No of student: ");
    scanf("%d", &studentdata[noofstudent].scontact);

    printf("Enter student's email id: ");
    scanf("%s", studentdata[noofstudent].email);

    printf("Enter Phone No of parents: ");
    scanf("%d", &studentdata[noofstudent].pcontact);

    stram(noofstudent); // Calculate fees and remaining fees

    noofstudent++;

    printf("\nStudent added successfully.\n");
}

void getstudent() {
    printf("\n*** Get Student Information ***\n");

    int i = 0;
    int rn;

    printf("Enter Roll No of student: ");
    scanf("%d", &rn);

    for (i = 0; i < noofstudent; i++) {
        if (studentdata[i].rollno == rn) {
            printf("\n**** Student Information ****\n");
            printf("NAME: %s\n", studentdata[i].studname);
            printf("ROLL NO: %d\n", studentdata[i].rollno);
            printf("Email: %s\n", studentdata[i].email);
            printf("Student Contact: %d\n", studentdata[i].scontact);
            printf("Parent Contact: %d\n", studentdata[i].pcontact);
            printf("Fees: %.2f\n", studentdata[i].fees);
            printf("Remaining Fees: %.2f\n", studentdata[i].rfees);
            printf("****************************\n\n");
            return;
        }
    }
    printf("\nStudent not found.\n");
}

void stram(int index) {
    int stream;
    int fees;
    int paidFees;

    printf("\nEnter student's stream:\n");
    printf("1. BCS\n");
    printf("2. BCA\n");
    printf("3. BSC\n");
    printf("Choose one: ");
    scanf("%d", &stream);

    switch (stream) {
        case 1:
            fees = 23500;
            break;
        case 2:
            fees = 22500;
            break;
        case 3:
            fees = 20000;
            break;
        default:
            printf("Invalid option\n");
            return;
    }

    printf("Total Fees: %d\n", fees);

    printf("Enter how much fees you paid: ");
    scanf("%d", &paidFees);

    studentdata[index].fees = fees;
    studentdata[index].rfees = fees - paidFees;
}

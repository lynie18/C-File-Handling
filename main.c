// #include <stdio.h>
// int main() {
    //Used to reference and manipulate files
    // FILE *fptr;
//     fptr = fopen("Write.txt", "r");
//     if(fptr == NULL) {
//         printf("File not found!");
//     }else {
//     printf("File read successfully.");
//     }
//     return 0;
// }





//     //Write mode
//     fptr = fopen("Write.txt", "w");
//     fprintf(fptr, "Hello, this is a write mode file handling in C!");
//     fclose(fptr);
//     if(fptr == NULL) {
//         printf("File not found!");
//     }else {
//     printf("File written successfully.");
//     }
//     return 0;
// }

    //Append mode
//     fptr = fopen("Write.txt", "a");
//     fprintf(fptr, "Hello, this is an append mode file handling in C!");
//     fclose(fptr);
//     if(fptr == NULL) {
//         printf("File not found!");
//     }else {
//     printf("File written successfully.");
//     }
//     return 0;
// }

    //read and write mode
//     fptr = fopen("Write.txt", "r+");
//     fprintf(fptr, "Hello, this is a read and write mode file handling in C!");
//     fclose(fptr);
//     if(fptr == NULL) {
//         printf("File not found!");
//     }else {
//     printf("File written successfully.");
//     }
//     return 0;
// }

    //Write and read mode
//     fptr = fopen("Write.txt", "w+");
//     fprintf(fptr, "Hello, this is a write and read mode file handling in C!");
//     fclose(fptr);
//     if(fptr == NULL) {
//         printf("File not found!");
//     }else {
//     printf("File written successfully.");
//     }
//     return 0;
// }


    //append and write mode
//     fptr = fopen("Write.txt", "a+");
//     fprintf(fptr, "Hello, this is an append and write mode file handling in C!");
//     fclose(fptr);
//     if(fptr == NULL) {
//         printf("File not found!");
//     }else {
//     printf("File written successfully.");
//     }
//     return 0;
// }




// #include <stdio.h>
// int main() {
//     FILE *fptr;
//     fptr = fopen("students.txt", "w");
//     if (fptr == NULL) {
//         printf("Error opening file!");
//     } else {
//         printf("File opened successfully!");
//     }
//     fclose(fptr);
//     return 0;
//     }



// #include <stdio.h> 
// int main() { 
// FILE *file = fopen("students.txt", "r"); 
// if (file == NULL) { 
// printf("Error opening file.\n"); 
// return 1; 
// } 
// fputc('H', file); // Writes 'H' to the file 
// fputc('e', file); // Writes 'e' to the file 
// fputc('l', file); // Writes 'l' to the file 
// fputc('l', file); // Writes 'l' to the file 
// fputc('o', file); // Writes 'o' to the file 
// fclose(file); 
// return 0; 
// }

// #include <stdio.h> 
// int main() { 
// FILE *file = fopen("output.txt", "w"); 
// if (file == NULL) { 
// printf("Error opening file.\n"); 
// return 1; 
// } 
// int number = 123; 
// fprintf(file, "Number: %d\n", number); // Writes formatted data to the file 
// fclose(file); 
// return 0; 
// }

// #include <stdio.h> 
// int main() { 
// FILE *file = fopen("output.txt", "w"); 
// if (file == NULL) { 
// printf("Error opening file.\n"); 
// return 1; 
// } 
// fprintf(file, "Writing data to file.\n"); 
// fclose(file); // Closes the file and flushes the buffer 
// return 0; 
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void writeRecords();
void appendRecords();

int main() {
    int choice;
    char input[10];

    do {
        printf("\n=== STUDENT RECORD SYSTEM ===\n");
        printf("1. Write New Records\n");
        printf("2. Add More Records (Append)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        fgets(input, sizeof(input), stdin);
        choice = atoi(input); // convert string to integer

        switch(choice) {
            case 1:
                writeRecords();
                break;
            case 2:
                appendRecords();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please enter 1–3.\n");
        }
    } while(choice != 3);

    return 0;
}

void writeRecords() {
    FILE *fptr;
    char name[50], gradeStr[10];
    float grade;
    int num, i;

    fptr = fopen("students.txt", "w");
    if (fptr == NULL) {
        printf("Error! Cannot create file.\n");
        return;
    }

    char input[10];
    printf("How many students to add? ");
    fgets(input, sizeof(input), stdin);
    num = atoi(input);

    for (i = 0; i < num; i++) {
        printf("\nEnter student name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0'; // remove newline

        if (strlen(name) == 0) {
            printf("Name cannot be empty. Try again.\n");
            i--;
            continue;
        }

        printf("Enter grade: ");
        fgets(gradeStr, sizeof(gradeStr), stdin);
        gradeStr[strcspn(gradeStr, "\n")] = '\0';

        if (strlen(gradeStr) == 0) {
            printf("Grade cannot be empty. Try again.\n");
            i--;
            continue;
        }

        grade = atof(gradeStr); // convert string to float

        fprintf(fptr, "%s %.2f\n", name, grade);
    }

    fclose(fptr);
    printf("\n Records saved successfully!\n");
}

void appendRecords() {
    FILE *fptr;
    char name[50], gradeStr[10];
    float grade;

    fptr = fopen("students.txt", "a");
    if (fptr == NULL) {
        printf("Error! Cannot open file.\n");
        return;
    }

    printf("\n--- APPEND NEW STUDENT RECORDS ---\n");
    while (1) {
        printf("\nEnter student name (or type 'stop' to finish): ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        if (strcmp(name, "stop") == 0)
            break;

        if (strlen(name) == 0) {
            printf(" Name cannot be empty. Try again.\n");
            continue;
        }

        printf("Enter grade: ");
        fgets(gradeStr, sizeof(gradeStr), stdin);
        gradeStr[strcspn(gradeStr, "\n")] = '\0';

        if (strlen(gradeStr) == 0) {
            printf("Grade cannot be empty. Try again.\n");
            continue;
        }

        grade = atof(gradeStr);

        fprintf(fptr, "%s %.2f\n", name, grade);
        printf("Record saved successfully!\n");
    }

    fclose(fptr);
    printf("\n All records updated successfully!\n");
}

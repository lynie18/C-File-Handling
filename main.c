#include <stdio.h>
int main() {
    //Used to reference and manipulate files
    FILE *fptr;
    fptr = fopen("Write.txt", "r");
    if(fptr == NULL) {
        printf("File not found!");
    }else {
    printf("File read successfully.");
    }
    return 0;
}





    //Write mode
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





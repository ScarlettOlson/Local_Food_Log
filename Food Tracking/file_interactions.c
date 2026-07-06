#include <stdio.h>
#include <string.h>




int read_user_csv(char *file) {

    FILE *fptr = fopen(file, 'r');
    if(fptr == NULL) {
        return 1;
    }
    else {

    }

    fclose(fptr);
    return 0;
}

int read_meal_csv(char *file) {

    FILE *fptr = fopen(file, 'r');
    if(fptr == NULL) return 1;
    
    char buff[100];

    while (fgets(buff, 100, fptr)) {

    }

    fclose(fptr);
    return 0;
}

int read_data_csv(char *file) {

    FILE *fptr = fopen(file, 'r');
    if(fptr == NULL) {
        return 1;
    }
    else {

    }

    fclose(fptr);
    return 0;
}


int main(int argc, char *argv[]) {
    printf("This main method is a place holder and should not be used.");

    return 1;
}
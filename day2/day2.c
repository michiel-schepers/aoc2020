#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Policy {
    int min;
    int max;
    char* character;
};

int main(){
    int counter1 = 0;
    int counter2 = 0;
    char str[50];
    FILE *fp = fopen("input.txt", "r");

    while (fgets(str, 50, fp) != NULL){

        // split on spaces
        struct Policy policy;
        char * token = strtok(str, " ");
        char * part1 = token;
        token = strtok(NULL, " ");
        char * part2 = token;
        token = strtok(NULL, " ");
        char * password = token;

        // split in min and max
        char * token2 = strtok(part1, "-");
        policy.min = atoi(token2);
        token2 = strtok(NULL, " ");
        policy.max = atoi(token2);
        token = strtok(NULL, " ");

        // split for character
        char * token3 = strtok(part2, ":");
        policy.character = token3;

        // check policy part 1
        int count = 0;
        for(int i = 0; i < strlen(password); i++){
            if (password[i] == *policy.character){
                count++;
            }
        }

        if (count > policy.min - 1 && count < policy.max + 1){
            counter1++;
        }

        // check policy part 2

        if ((password[policy.min-1] == *policy.character || password[policy.max-1] == *policy.character) && !(password[policy.min-1] == *policy.character && password[policy.max-1] == *policy.character)){
            counter2++;
        }
    }
    fclose(fp);

    printf("Number of valid passwords in part 1: %i\n", counter1);
    printf("Number of valid passwords in part 2: %i\n", counter2);
    return 0;
}

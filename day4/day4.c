#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *fp = fopen("input.txt", "r");
    char str[1000];
    int components = 0;
    int counter = 0;
    while (fgets(str, 100, fp) != NULL){
        if (str[0] == '\n'){
            if (components == 7){
                counter++;
            }
            components = 0;
        }
        else{
            if (strstr(str, "ecl") != NULL){
                components++;
            }
            if (strstr(str, "pid") != NULL){
                components++;
            }
            if (strstr(str, "eyr") != NULL){
                components++;
            }
            if (strstr(str, "hcl") != NULL){
                components++;
            }
            if (strstr(str, "byr") != NULL){
                components++;
            }
            if (strstr(str, "iyr") != NULL){
                components++;
            }
            if (strstr(str, "hgt") != NULL){
                components++;
            }
        }
    }

    printf("number of valid passports = %i\n", counter);

    return 0;
}
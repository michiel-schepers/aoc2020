#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int getrow(char *str){
    int min = 0;
    int max = 127;
    for (int i = 0; i < 7; i++){
        if (str[i] == 'F'){
            max -= (max - min) / 2 + 1;
        }
        else{
            min += (max - min) / 2 + 1;
        }
    }    
    return min;
}

int getcol(char *str){
    int min = 0;
    int max = 7;
    for(int i = 7; i < 10; i++){
        if (str[i] == 'L'){
            max -= (max - min) / 2 + 1;
        }
        else{
            min += (max - min) / 2 + 1;
        }
    }
    return min;
}

int main(){
    FILE *fp = fopen("input.txt", "r");
    char str[10];
    int maxid = 0;
    int ids[850] = { 0 };
    int c = 0;
    while (fscanf(fp, "%s", str) > 0){
        int id = 8 * getrow(str) + getcol(str);
        ids[c] = id;
        if (maxid < id)
            maxid = id;
        c++;
    }

    qsort(ids, 850, sizeof(int), cmpfunc);
    for(int i = 1; i < sizeof(ids)/sizeof(ids[0]); i++){
        if (ids[i] != ids[i-1] + 1){
            printf("Missing ID = %i\n", ids[i] - 1);
        }
    }

    printf("Highest ID = %i\n", maxid);
}
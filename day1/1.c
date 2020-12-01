
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen("input.txt", "r");
    int list[200];
    int num;
    
    for (int i = 0; fscanf(fp, "%d", &num) > 0; i++){
        list[i] = num;
    }
    fclose(fp);
    
    for (int i = 0; i < sizeof(list)/sizeof(int); i++){
        for (int j = 0; j < sizeof(list)/sizeof(int); j++){
            if (list[i] + list[j] == 2020){
                printf("%i\n", list[i] * list[j]);
            }
        }
    }

    return 0;
}
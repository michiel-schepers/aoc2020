#include <stdio.h>

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
            for (int k = 0; k < sizeof(list)/sizeof(int); k++){
                if (list[i] + list[j] + list[k] == 2020){
                    printf("%i\n", list[i] * list[j] * list[k]);
                }
            }
        }
    }

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#define ROWSIZE 32

uint64_t calcTrees(int right, int down){
    
    FILE *fp = fopen("input.txt", "r");
    char row[ROWSIZE];
    int col = 0;
    uint64_t trees = 0;
    int pos = 0;
    while(fscanf(fp, "%s", row) > 0){
        if ((row[col % (ROWSIZE - 1)] == '#') && (pos % down == 0)){
            trees++;
        }
        if(pos % down == 0){
            col += right;
        }
        pos++;
    }

    fclose(fp);
    return trees;
}

int main(){
    printf("Part 1: %li\n", calcTrees(3,1));
    uint64_t product = calcTrees(1,1) * calcTrees(3,1) * calcTrees(5,1) * calcTrees(7,1) * calcTrees(1,2);
    printf("Part 2: %lu\n", product);
    return 0;
}


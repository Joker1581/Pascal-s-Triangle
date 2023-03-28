#include <stdio.h>
#include <stdlib.h>
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize = numRows;
    int **output = calloc(1, sizeof(int *[numRows]));
    *returnColumnSizes = calloc(1, sizeof(int [numRows]));
     
    //Allocate memory for the whole triangle 
    for (int i=0; i<numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
        output[i] = calloc(1, sizeof(int [i + 1]));
    }
    
    //the first row will always be 1
    output[0][0] = 1;
    
    for (int i=1; i<numRows; i++) {
        output[i][0] = 1;
        for (int j=1; j<i; j++) {
            output[i][j] = output[i-1][j-1] + output[i-1][j];
        }
        output[i][i] = 1;
    }
    return output;
}

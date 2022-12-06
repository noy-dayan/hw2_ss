#include "my_mat.h"
#include <math.h>

// start the matrix input insertion
void A_ScanMat(int mat[10][10]){
    for(int i=0; i<10;i++)
        for(int j=0; j<10;j++)
            scanf("%d", &mat[i][j]);
}

// check if a route exists between i and j and print the answer
void B_isRoute(int mat[10][10]){
    if (C_shortestRoute(mat)==-1)
        printf("False\n");
    else
        printf("True\n");
}

// print the shortest route between i and j, if route does not exist print -1
// using Floyd-Warshall algorithm
int C_shortestRoute(int mat[10][10]){
    int mainI, mainJ;
    scanf("%d %d", &mainI,&mainJ);
    if(mainI==mainJ)
        return -1;

    // float matrix to contain INFINITY
    float float_mat[10][10];  
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if(mat[i][j]==0 && i!=j)
                float_mat[i][j]=INFINITY;
            else
                float_mat[i][j]=mat[i][j];
        
    for (int k = 0; k < 10; k++) 
       for (int i = 0; i < 10; i++) 
            for (int j = 0; j < 10; j++)
                if (float_mat[k][j] + float_mat[i][k] < float_mat[i][j])
                    float_mat[i][j] = float_mat[k][j] + float_mat[i][k];
            
    if (float_mat[mainI][mainJ]!=INFINITY)
        return (int)float_mat[mainI][mainJ];
        
    return -1;
}
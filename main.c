#include "my_mat.h"

int main(){   
    // initial variables
    char str;
    int tmp = 1;
    int mat[10][10];
    while (tmp != 0){
        // get option input from user
        scanf("%c", &str);

        // start the matrix input insetion
        if (str == 'A' || str == 'a')
            A_ScanMat(mat);

        // check if a route exists between i and j and print the answer
        else if (str == 'B' || str == 'b')
            B_isRoute(mat);

        // print the shortest route between i and j, if route does not exist and print -1
        else if (str == 'C' || str == 'c')
            printf("%d\n",C_shortestRoute(mat));
        
        // exit the program
        else if (str == 'D' || str == 'd')
            tmp = 0;
    }
}
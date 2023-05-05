/*each queen has to go on a separate row 
hence each kth queen has a corresponding column number
soln[kth_row_Queen] = col_no*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// bounding function
bool inPlace(int solution[], int k, int j){
    int i;
    for (i=0; i<k; i++) // checking all rows that have been filled before k
    {
        // i-> row, j ->particular column
        //   same column         same diagonal
        if ((solution[i]==j) || abs(solution[i] - j) == abs(k-i))
            return false;
    }
    return true;
}

void nQueens(int solution[], int k, int n){
    int i;
    static int count=0; //no_of solns
    for (i=0; i<n; i++) // checking all possible columns
    {
        if (inPlace(solution, k, i)) // checks if the position (k, i) is valid
        {
            solution[k] = i; // add i as column_no of kth Queen
            if (k==n-1) // all rows filled
            {
                count++;
                printf("Solution %d\n", count);
                for (int ct =0; ct <n; ct++)
                    printf("Queen %d placed in %d column\n",ct,solution[ct]);
                printf("\n");    
            }
            else
                nQueens(solution, k+1, n); //finding col for next Q

            // printf("Failure, Recursive call comes back to Queen %d\n",k) ;
            // checking more possible locations for kth queen as failure in children (backtracking) or success.
        }
    }
}

int main() {
    int n;
    printf("Enter the number of Queens on n x n board (value of n) : ");
    scanf("%d",&n);
    int solution[30]; //soln array of col_no
    int k=0;
    //we call for the 0th queen, rest is called recursively
    nQueens(solution, k, n);
}

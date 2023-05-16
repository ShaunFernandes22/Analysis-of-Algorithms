/*each queen has to go on a separate row 
hence each kth queen has a corresponding column number
soln[kth_row_Queen] = col_no*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int solution[30]; //soln array of col_no
int n;

// bounding function
bool inPlace(int k, int j){
    int i;
    for (i=0; i<k; i++) // checking all rows that have been filled before k
    {
        // i-> row, j ->specific column checked
        //   same column         same diagonal
        if ((solution[i]==j) || abs(solution[i] - j) == abs(k-i))
            return false;
    }
    return true;
}

void nQueens(int k){
    int i;
    static int count=0; //no_of solns
    for (i=0; i<n; i++) // checking all possible columns
    {
        if (inPlace(k, i)) // checks if the position (k, i) is valid
        {
            solution[k] = i; // add i as column_no of kth Queen
            if (k==n-1) // all rows filled
            {
                count++;
                printf("Solution %d\n", count);
                for (int ct =0; ct <n; ct++)
                    printf("Queen %d placed in column %d\n",ct+1,solution[ct]+1);
                printf("\n");    
            }
            else
                nQueens(k+1); //finding col for next Queen

            // printf("Dead end, Recursive call comes back to Queen %d\n",k) ;
            // checking more possible locations for kth queen as failure in children (backtracking) or success.
        }
    }
}

int main() {
    printf("Enter the number of Queens on n x n board (value of n) : ");
    scanf("%d",&n);
    
    int k=0;
    //we call for the 0th queen, rest is called recursively
    nQueens(k);
}

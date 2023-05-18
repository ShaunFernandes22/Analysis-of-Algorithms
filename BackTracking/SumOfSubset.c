/*s+w[k] , s+w[k] + w[k+1] --> solns possible with w[k], w[k+1]
s + r - w[k] >= m, s + w[k+1] <= m --> sum possible without w[k]*/

#include <stdio.h>

int w[20], x[20];
int n, m;

void printSolution()
{
    for (int i=0; i<n; i++)
        printf("%d \t", x[i]);
    printf("\n");    
    printf("{ ");
    for (int i=0; i<n; i++)
        if (x[i] == 1)
            printf("%d ", w[i]);
    printf("}");        
    printf("\n");    
}

void sumOfSubset(int s, int k, int r)
{
    static int count = 0;
    x[k] = 1;
    // checking if sum matches target
    if (s + w[k] == m)
    {
        count++;
        printf("\nSolution %d\n",count);
        // resetting 1's after k which were part of previous solutions, since we're back to k
        for (int ct=k+1; ct<n; ct++)
            x[ct] = 0;
        printSolution();
    }
    // calling left subtree (dfs) going 1 level deeper
    else if (s + w[k] + w[k+1] <= m)
        sumOfSubset(s + w[k] , k+1, r - w[k]);

    // calling right subtree after coming coming back to parent call (backtracking) on either success or dead ends -> not possible to get sum further 
    if ((s + r - w[k] >= m) && (s + w[k+1] <= m)) // checking if sum is possible in right tree
    {
        x[k] = 0;
        sumOfSubset(s, k+1, r - w[k]); //dfs
    }
}

int main() {
    int i, k=0, sum=0, rem=0;
    
    printf("Enter the number of weights : ");
    scanf("%d",&n);
    for (i=0; i<n; i++)
    {
        printf("Enter weight %d : ",i+1);
        scanf("%d",&w[i]);
    }
    for (i=0; i<n; i++)
    {
        rem += w[i];
        x[i] = 0;
    }   

    printf("\nEnter the sum needed : ");
    scanf("%d",&m);
    sumOfSubset(sum, k, rem);    

    return 0;
}

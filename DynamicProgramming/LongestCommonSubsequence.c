#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

// Longest Common Subsequence
void LCS(char *, char *, int, int, int [][MAX], char [][MAX]);
void print_LCS(char *, char *, int, int, int, char [], char [][MAX]);
void print_Tables(int [][MAX], char [][MAX], int, int);

int main() {
    char str1[MAX], str2[MAX];
    int seq_length[MAX][MAX];
    char symbol[MAX][MAX];
    
    printf("Enter string 1: ");
    scanf("%s",str1);
    printf("Enter string 2: ");
    scanf("%s",str2);
    int m = strlen(str1);
    int n = strlen(str2);
    
    LCS(str1, str2, m, n, seq_length, symbol);
    
    print_Tables(seq_length, symbol, m, n);
    
    int last = seq_length[m][n];
    char ans[MAX];
    ans[last] = '\0';
    print_LCS(str1, str2, m-1, n-1, last, ans, symbol);
    
    printf("The longest common subsequence is \'%s\'", ans);
    
    return 0;
}
// function to fill char table (m x n) using dp
void LCS(char *str1, char *str2, int m, int n, int seq_length[][MAX], char symbol[][MAX]) {
    int i, j;
    for (i = 0; i<=m; i++)
        seq_length[i][0] = 0;
    for (i = 0; i<=n; i++)
        seq_length[0][i] = 0;

    for (i = 1; i<=m; i++)
    {
        for (j = 1; j<=n; j++)
        {
            if (str1[i-1] == str2[j-1])
            {
                seq_length[i][j] = seq_length[i-1][j-1] + 1;
                symbol[i-1][j-1] = '\\'; // diagonal
            }
            else if (seq_length[i-1][j] > seq_length[i][j-1])
            {
                seq_length[i][j] = seq_length[i-1][j];
                symbol[i-1][j-1] = '|'; // top
            }
            else 
            {
                seq_length[i][j] = seq_length[i][j-1];
                symbol[i-1][j-1] = '-'; // left
            }
        }
    }       
   }
// function to store LCS 
void print_LCS(char *str1, char *str2, int i, int j, int last, char ans[], char symbol[][MAX]) {
    if (i==-1|| j==-1){
        return;
    }
    else if (symbol[i][j] == '\\')
    {
        ans[last-1] = str1[i];
        last--;
        print_LCS(str1, str2, i-1, j-1, last, ans, symbol);
        // printf("%d  %c \t %d  %c\n",i,str1[i],j,str2[j]);
    }
    else if (symbol[i][j] == '|')
        print_LCS(str1, str2, i-1, j, last, ans, symbol);
    else 
        print_LCS(str1, str2, i, j-1, last, ans, symbol);
}
// function to print calculated 2-d arrays
void print_Tables(int seq_length[][MAX], char symbol[][MAX], int m, int n)
{
    int i, j;
    for (i=0; i<=m; i++)
    {
        for (j =0; j<=n; j++)
        {
            printf("%d\t", seq_length[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (i=0; i<m; i++)
    {
        for (j =0; j<n; j++)
        {
            printf("%c\t", symbol[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

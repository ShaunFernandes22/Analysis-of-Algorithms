#include <stdio.h>
#include <string.h>

void computePrefix(char *pattern, int m, int lps[]) {
    int k = 0;
    lps[0] = 0;
    for (int q = 1; q < m; q++) {
        while (k > 0 && pattern[k] != pattern[q])
            k = lps[k-1];
        if (pattern[k] == pattern[q])
            k++;
        lps[q] = k;        
    }
}

void kmpMatcher(char *text, char *pattern, int n, int m, int lps[]) {
    int q = 0;
    for (int i = 0; i < n; i++) {
        while (q > 0 && text[i] != pattern[q]) 
            q = lps[q-1];
        if (pattern[q] == text[i])
            q++;
        if (q == m) {
            printf("\nPattern occurs with shift %d\n",i-m+1);
            q = lps[q-1];
        } 
    }
}

void printLPS(int lps[], int m) {
    int i;
    for (i=0; i< m; i++)
        printf("%d ",lps[i]);
    printf("\n");    
}

int main() {
    char text[100], pattern[20];
    printf("Enter the text : ");
    scanf("%s",text);
    printf("Enter the pattern to match : ");
    scanf("%s",pattern);
    
    int m, n;
    n = strlen(text);
    m = strlen(pattern);
    int lps[20];

    computePrefix(pattern, m, lps);

    // printLPS(lps, m);
    
    kmpMatcher(text, pattern, n, m, lps);
    
    return 0;
}

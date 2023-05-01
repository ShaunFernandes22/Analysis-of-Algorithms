#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// hash function to calculate hash for pattern and initial text same as pattern length (starting hash)
int HashFunction(char *pattern, int m) {
   int i, value=0;
   for (i=0; i<m; i++) //traverse window length and create hashvalue
       value = value*10 + ((int)pattern[i] - 96);
   
   return value;
}

// rolling hashfunction computes hash of sliding window
int RollingHash(char *pattern, int m, char* text, int n, int hash_init, int ct, int power) {
    int value;
    int prev_outgoing_digit = (int)text[ct-1] - 96;
    int next_incoming_digit = (int)text[ct+m-1] - 96;
    value  = (hash_init - ( power * prev_outgoing_digit ))*10 + next_incoming_digit;

    return value;
}

// on matching of hash values we check if characters are same
bool CheckWindow(int hash_init, int hash_pat, char *text, char *pattern, int m, int ct) {  
    int i, j, count = 0;
    for (i=ct,j=0 ; j<m; i++, j++)
    {
        if (text[i] == pattern[j])
            count++;
    }
    if (count==m)
        return true;
    
    return false;
}

int main() {
    char text[100], pattern[20];
    printf("Enter the text : ");
    scanf("%s",text);
    printf("Enter the pattern to match : ");
    scanf("%s",pattern);
    
    int m, n, ct=0, n_matches=0;
    n = strlen(text);
    m = strlen(pattern);
    
    // calculate starting static hashes
    int hash_pat = HashFunction(pattern, m);
    int hash_init = HashFunction(text, m);
    
    int power = pow(10, m-1); // power = 100 in case of 3 letter string
    bool check = false; // if substring found

    // comparing the hash values at beginning of the text string (index 0) as RollingHash would not be applicable
    if (hash_init == hash_pat) {
        check = CheckWindow(hash_init, hash_pat, text, pattern, m, ct);
        if (check)
        {
            n_matches++;
            printf("Pattern found at shift of %d\n", ct);
        }    
    }

    // for the rest hashes using sliding window (rolling) hashing
    for (ct=1; ct<n-m+1; ct++) {
        hash_init = RollingHash(pattern, m, text, n, hash_init, ct, power);
        if (hash_init == hash_pat) {
            check = CheckWindow(hash_init, hash_pat, text, pattern, m, ct);
            if (check)
            {
                n_matches++;
                printf("Pattern found at shift of %d\n", ct);
            }    
        }
    }

    if (n_matches == 0)
        printf("The pattern was not found in the string\n");

    return 0;
}

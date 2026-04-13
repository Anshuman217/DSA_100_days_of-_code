#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int freq[26] = {0};
    int i;

    printf("Enter string: ");
    scanf("%s", s);

    for(i = 0; i < strlen(s); i++) {
        freq[s[i] - 'a']++;

        if(freq[s[i] - 'a'] == 2) {
            printf("%c", s[i]);
            return 0;
        }
    }

    printf("-1");
    return 0;
}
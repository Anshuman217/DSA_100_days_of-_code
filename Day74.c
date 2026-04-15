#include <stdio.h>
#include <string.h>

int main() {
    int n;
    printf("Enter number of votes: ");
    scanf("%d", &n);

    char names[n][101];
    printf("Enter candidate names:\n");
    for(int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    int count[n];
    for(int i = 0; i < n; i++) count[i] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(strcmp(names[i], names[j]) == 0) {
                count[i]++;
            }
        }
    }

    int maxVotes = 0;
    char winner[101];

    for(int i = 0; i < n; i++) {
        if(count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        } else if(count[i] == maxVotes) {
            if(strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}
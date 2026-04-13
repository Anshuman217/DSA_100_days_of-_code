//Implement a hash table using quadratic probing with formula:
//h(k, i) = (h(k) + i*i) % m

#include <stdio.h>
#include <string.h>

int table[1000];

int main() {
    int m,n,i,j,key,idx;
    char op[10];

    printf("Enter table size: ");
    scanf("%d",&m);

    for(i=0;i<m;i++) table[i] = -1;

    printf("Enter number of operations: ");
    scanf("%d",&n);

    while(n--) {
        scanf("%s %d",op,&key);

        if(strcmp(op,"INSERT")==0) {
            for(i=0;i<m;i++) {
                idx = (key % m + i*i) % m;
                if(table[idx] == -1) {
                    table[idx] = key;
                    break;
                }
            }
        } else if(strcmp(op,"SEARCH")==0) {
            int found = 0;
            for(i=0;i<m;i++) {
                idx = (key % m + i*i) % m;
                if(table[idx] == key) {
                    found = 1;
                    break;
                }
                if(table[idx] == -1) break;
            }
            if(found) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }
}
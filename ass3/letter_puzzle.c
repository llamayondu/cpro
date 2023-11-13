#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char final[40321][9];
int t=0;

void swap(char* a, char* b)
{
    char temp= *a;
    *a = *b;
    *b = temp;
}

void perm(char a[], int l, int r)
{
    if(l==r){
        for(int i=0; i<8; i++){
            final[t][i]=a[i];
        }
        t++;
    }
    for(int i=l; i<=r; i++)
    {
        swap(&a[i], &a[l]);
        perm(a, l+1, r);
        swap(&a[i], &a[l]);
    }

}

int compare( const void *str1, const void *str2 )
{
    const char *rec1 = *(char**)str1;
    const char *rec2 = *(char**)str2;
    int val = strcmp(rec1, rec2);

    return val;
}

int main()
{
    char word[9];
    scanf("%s", word);
    final[40320][0]=0;
    int len = strlen(word);

    perm(word, 0, len-1);

    const char *sorted[t];

    for(int i=0; i<t; i++){
        sorted[i]=final[i];
    }

    qsort(sorted, t, sizeof(char*), compare);

    int counter=0;
    for(int i=1; i<t; i++){
        if(strcmp(sorted[i], sorted[i-1])!=0){
            counter++;
        }
    }

    printf("%d\n", counter+1);
    printf("%s\n", sorted[0]);

    for(int i=1; i<t; i++){
        if(strcmp(sorted[i], sorted[i-1])!=0){
            printf("%s\n", sorted[i]);
        }
    }

}
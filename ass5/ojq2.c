#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *a, char *b){
    char temp = *a;
    *a=*b;
    *b=temp;
}

void reverse(char a[], int n){
    for(int i=0; i<n/2; i++){
        swap(&a[i], &a[n-i-1]);
    }
}

void lappend(char a[], int n, char c){
    for(int i=n; i>=0; i--){
        a[i+1]=a[i];
    }
    a[0]=c;
}

void rappend(char a[], int n, char c){
    a[n]=c;
    a[n+1]='\n';
}

int main(){
    // char arr[10] = {'a', 'e', 'i', 'o', 'u', '\n'};
    // // reverse(arr, 5);
    // lappend(arr, 5, 'p');
    // printf("%s", arr);

    char word_old[100];
    scanf("%s", word_old);
    int n=strlen(word_old);
    int m;
    scanf("%d", &m);
    char word[n+m+1];
    memset(word, 0, (n+m+1)*sizeof(char));
    strcpy(word, word_old);

    for(int reps=0; reps<m; reps++){
        int q;
        scanf("%d", &q);
        if(q==1){
            reverse(word, n);
        } else {
            int l;
            char j;
            scanf("%d ", &l);
            scanf("%c", &j);
            if(l==1){
                lappend(word, n, j);
            } else {
                rappend(word, n, j);
            }
            n++;
        }
    }

    printf("%s\n", word);

}
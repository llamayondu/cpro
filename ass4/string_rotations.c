#include <stdio.h>
#include <string.h>

void rotate_left(char a[], int n){
    char temp=a[0];
    for(int i=0; i<n-1; i++){
        a[i]=a[i+1];
    }
    a[n-1]=temp;
}

void rotate_right(char a[], int n){
    char temp=a[n-1];
    for(int i=n; i>0; i--){
        a[i]=a[i-1];
    }
    a[0]=temp;
}

int main(){

    char word[1001];
    scanf("%s", word);

    int n=strlen(word);

    char least[1001];
    strcpy(least, word);

    for(int i=0; i<n; i++){
        rotate_left(word, n);
        if(strcmp(least, word)>0){
            strcpy(least, word);
        }
    }

    char highest[1001];
    strcpy(highest, word);

    for(int i=0; i<n; i++){
        rotate_left(word, n);
        if(strcmp(highest, word)<0){
            strcpy(highest, word);
        }
    }

    printf("%s\n%s", least, highest);
}
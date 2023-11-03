#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    char word[200000];
    scanf("%s", word);
    char copy[200000];

    int flag=0;

    for(int i=0; i<n; i++){
        if(word[i]=='"'){
            copy[i]=word[i];
            flag++;
        } else if(word[i]==',' && flag%2==0){
            copy[i]='*';
        } else {
            copy[i]=word[i];
        }
    }

    for(int i=0; i<n; i++){
        printf("%c", copy[i]);
    }
    
}
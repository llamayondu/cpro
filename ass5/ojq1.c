#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int alphabet[26]={0};
    int n, h;
    char s[200000];
    scanf("%d %d", &n, &h);
    scanf("%s", s);
    int counter=1;
    for(int i=1; i<n; i++){
        if(s[i]==s[i-1]){
            counter++;
        } else {
            alphabet[s[i-1]-'a']+=(counter/h);
            counter=1;
        }
    }
    alphabet[s[n-1]-'a']+=(counter/h);
    int ans = alphabet[0];
    for(int i=1; i<26; i++){
        if(alphabet[i]>ans){
            ans=alphabet[i];
        }
    }
    printf("%d", ans);
}
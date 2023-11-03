#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n;
    int h;
    char s[200];
    scanf("%d %d", &n, &h);
    scanf("%s", s);
    int alphabet[26]={0};
    for(int i=0; i<n; i++){
        alphabet[s[i]-'a']++;
    }
    int count_subs=0;
    int alphabet_factor[26];
    for(int i=0; i<26; i++){
        if(alphabet[s[i]-'a']<h){
            continue;
        }
        for(int j=0; j<n-h; j++){
            int check=0;
            int k=1;
            if(s[j]-'a'==i){
                check=1;
                for(k=1; k<h; k++){
                    if(s[j+k]-'a'!=i){
                        check=0;
                        break;
                    }
                }
            }
            if(check){
                j+=k-1;
                count_subs++;
            } else {
                j+=k;
            }
        }
    }
    printf("%d", count_subs);
}
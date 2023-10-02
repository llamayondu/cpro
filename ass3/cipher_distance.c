#include <stdio.h>

int max_cd(char a)
{
    int cd;
    if((int)a <= (int) 'm')
        cd = 'z'-a;
    if((int)a >= (int) 'n')
        cd = a - 'a';

    return cd;
}

int max_k(char a[], int n)
{
    int k=0;
    for(int i=0; i<n; i++){
        k+=max_cd(a[i]);
    }
    return k;
}

int main(){
    int n;
    int k;
    scanf("%d %d", &n, &k);
    char word[n];
    scanf("%s", word);
    int cipher_distances[n];
    // int max_k=0;
    for(int i=0; i<n; i++){
        cipher_distances[i]=max_cd(word[i]);
    }


    if(max_k(word, n)<k){
        printf("-1");
        return 0;
    }

    char final[n];

    for(int i=0; i<n; i++){
        final[i]=word[i];
    }

    for(int i=0; k>0 && i<n; i++){
        if(k>((int) final[i] - (int) 'a')){
            k=k-((int) final[i] - (int) 'a');
            final[i]='a';
        }

        else{
            final[i] -= k;
            k=0;
        }
    }
    for(int i=n-1; i>=0; i--){
        if(k>0){
            if((int)word[i]<=(int)'m'){
                if(k>(2*((int)'m'-(int)word[i])+1)){
                    k-=(2*((int)'m'-(int)word[i])+1);
                    final[i]='z';
                }
                else{
                    final[i]=(int)word[i]+(int)word[i] - (int)'a' + k;
                    break;
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        printf("%c", final[i]);
    }
}

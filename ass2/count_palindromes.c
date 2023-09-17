#include <stdio.h>

int main(){
    int n, counter=0;
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(arr[i]==arr[j]){
                int p=j-i+1;
                int subarr[p];
                for(int k=0; k<p; k++){
                    subarr[k]=arr[i+k];
                }
                    int check=1;
                    for(int t=0; t<=(p)/2; t++){
                        if(subarr[t]!=subarr[p-t-1]){
                            check=0;
                            break;
                        }
                    }
                    if(check) counter++;
                
            }

        }
    }
    printf("%d", counter);
}
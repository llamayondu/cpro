#include <stdio.h>

int main(){
    int reps;
    scanf("%d", &reps);
    int final[reps];
    for(int count=0; count<reps; count++){
        int n;
        scanf("%d", &n);
        int friends[n];
        int irritations[n];
        for(int i=0; i<n; i++){
            scanf("%d", &friends[i]);
        }

        int max_irritation = 0;

        for(int i=n-1; i>=0; i--){
            if(i+friends[i]>n-1){
                irritations[i]=friends[i];
            }
            else{
                irritations[i]=friends[i]+irritations[i+friends[i]];
            }
            if(irritations[i]>max_irritation){
                max_irritation=irritations[i];
            }
        }
        final[count]=max_irritation;
    }
    for(int i=0; i<reps; i++){
        printf("%d\n", final[i]);
    }
}
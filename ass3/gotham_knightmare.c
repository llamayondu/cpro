#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BLOCKED -1

int n, m, k;

int main(){
    scanf("%d %d %d", &n, &m, &k);
    long long int gotham[n][m+4];
    
    memset(gotham, 0, n*(m+4)*(sizeof(long long int)));

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m+4; j++){
    //         gotham[i][j]=0;
    //     }
    // }

    for(int i=0; i<k; i++){
        int tempx, tempy;
        scanf("%d %d", &tempx, &tempy);
        gotham[tempx-1][tempy+1]=BLOCKED;
    }

    for(int i=2; i<m+2; i++){
        gotham[0][i]=1;
    }

    if(gotham[1][2]!=BLOCKED&&m>=3) gotham[1][2]=1;
    if(gotham[1][3]!=BLOCKED&&m>=4) gotham[1][3]=1;
    if(gotham[1][m]!=BLOCKED&&m-4>=0) gotham[1][m]=1;
    if(gotham[1][m+1]!=BLOCKED&&m-3>=0) gotham[1][m+1]=1;

    for(int i=4; i<m; i++){
        if(gotham[1][i]!=BLOCKED) gotham[1][i]=2;
    }

    for(int i=2; i<n; i++){
        for(int j=2; j<m+2; j++){
            if(gotham[i][j]==BLOCKED) continue;
            if(gotham[i-1][j-2]!=BLOCKED) gotham[i][j] += gotham[i-1][j-2];
            if(gotham[i-2][j-1]!=BLOCKED) gotham[i][j] += gotham[i-2][j-1];
            if(gotham[i-2][j+1]!=BLOCKED) gotham[i][j] += gotham[i-2][j+1];
            if(gotham[i-1][j+2]!=BLOCKED) gotham[i][j] += gotham[i-1][j+2];
            gotham[i][j]%=1000000007;
        }
    }

    for(int i=2; i<m+2; i++){
        printf("%lld ", gotham[n-1][i]%1000000007);
    }
}
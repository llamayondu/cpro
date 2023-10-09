#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int blocks[k][2];
    for(int i=0; i<k; i++){
        scanf("%d %d", &blocks[i][0], &blocks[i][1]);
    }

    for(int i=0; i<k; i++){
        blocks[i][0]=n+1-blocks[i][0];
    }

    int gotham_sim[3][m+4][m];
    memset(gotham_sim, 0, 3*m*(m+4)*sizeof(int));
    for(int i=0; i<m; i++){
        gotham_sim[0][i+2][i]++;
    }
    // for(int i=0; i<m; i++){
    //     if(i>=2){
    //         gotham_sim[1][i][i]++;
    //     }
    //     if(i+4<=m-1){
    //         gotham_sim[1][i][i+4]++;
    //     }
    // }

    for(int i=2; i<m+2; i++){
        if(i-2>=2){
            gotham_sim[1][i][i-4]++;
        }
        if(i+2<=m+1){
            gotham_sim[1][i][i]++;
        }
    }

    for(int t=0; t<k; t++){
        if(blocks[t][0]==2){
            memset(gotham_sim[1][blocks[t][1]+1], 0, m*sizeof(int));
        }
    }

    for(int i=2; i<n; i++){
        memset(gotham_sim[i%3], 0, (m+4)*m*sizeof(int));
        for(int j=2; j<m+2; j++){
            for(int k=0; k<m; k++){
                gotham_sim[i%3][j][k]+=gotham_sim[(i-1)%3][j-2][k];//wide left
                gotham_sim[i%3][j][k]+=gotham_sim[(i-2)%3][j-1][k];//tall left
                gotham_sim[i%3][j][k]+=gotham_sim[(i-2)%3][j+1][k];//tall right
                gotham_sim[i%3][j][k]+=gotham_sim[(i-1)%3][j+2][k];//wide right
                gotham_sim[i%3][j][k]%=MOD;
            }
        }
        for(int t=0; t<k; t++){
            if(i==blocks[t][0]-1){
                memset(gotham_sim[i%3][blocks[t][1]+1], 0, m*sizeof(int));
            }
        }
    }

    int final_sum[m];
    for(int i=0; i<m; i++){
        final_sum[i]=0;
    }

    for(int j=2; j<m+2; j++){
        for(int k=0; k<m; k++){
            final_sum[k]+=gotham_sim[(n-1)%3][j][k];
        }
    }

    for(int i=0; i<m; i++){
        printf("%d ", final_sum[i]%MOD);
    }
}
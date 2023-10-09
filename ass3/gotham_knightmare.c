#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define BLOCKED (int *)1

int *zeroes=NULL;
int entrances[1000]={0};
int *gotham[1000][1000]={0};
int m;
int *knightmove(int *a[1000][1000], int start_x, int start_y, int end_x, int end_y, int* mem)
{
    if(gotham[start_x][start_y]==BLOCKED){
        return zeroes;
    }

    if(gotham[start_x][start_y]!=0){
        return gotham[start_x][start_y];
    }

    assert(mem != NULL);
    gotham[start_x][start_y]=mem+(start_x*m);
    // memset(gotham[start_x][start_y], 0, m*sizeof(int));
    
    if(start_y==end_y){
        // gotham[start_x][start_y]=(int *) malloc(sizeof(int)*m);
        // memset(gotham[start_x][start_y], 0, 8*sizeof(int));
        // memset(gotham[start_x][start_y] + start_x, 1, sizeof(int));
        gotham[start_x][start_y][start_x]=1;
        return gotham[start_x][start_y];
    }

    else{

        //wide left move
        if(start_x>=2){
            int *wide_left=knightmove(a, start_x-2, start_y+1, end_x, end_y, NULL);
            for(int i=0; i<m; i++){
                gotham[start_x][start_y][i] += wide_left[i];
            }
        }

        //tall left move
        if(start_x>=1 && start_y<=end_y-2){
            int *tall_left=knightmove(a, start_x-1, start_y+2, end_x, end_y, NULL);
            for(int i=0; i<m; i++){
                gotham[start_x][start_y][i] += tall_left[i];
            }
        }

        //tall right move
        if(start_y<=end_y-2 && start_x<=end_x-1){
            int *tall_right=knightmove(a, start_x+1, start_y+2, end_x, end_y, NULL);
            for(int i=0; i<m; i++){
                gotham[start_x][start_y][i] += tall_right[i];
            }
        }

        //wide right move
        if(start_x<=end_x-2){
            int *wide_right=knightmove(a, start_x+2, start_y+1, end_x, end_y, NULL);
            for(int i=0; i<m; i++){
                gotham[start_x][start_y][i] += wide_right[i];
            }
        }
    }
    // printf("memoising:%d %d:", start_x+1, start_y+1);
    // for(int j=0; j<m; j++){
    //     printf("%d ", gotham[start_x][start_y][j]);
    // }
    // printf("\n");
    return gotham[start_x][start_y];
}


int main(){

    int n, k;
    scanf("%d %d %d", &n, &m, &k);

    int a[m*m], b[m*m], c[m*m];
    int *N = a, *N1=b, *N2=c, *temp;

    zeroes = (int *)malloc(sizeof(int)*m);
    memset(zeroes, 0, m*sizeof(int));

    int row, column;

    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            gotham[i][j]=0;
        }
    }

    for(int i=0; i<k; i++){
        scanf("%d %d", &row, &column);
        gotham[column-1][row-1]=BLOCKED;
    }


    int final_sum[m];

    for(int i=0; i<m; i++){
        final_sum[i]=0;
    }


    for (int row = n-1; row >= n-2; row--){
        for(int i=0; i<m; i++){
            // temp=N2;
            // N2=N1;
            // N1=N;
            // N=temp;
            memset(N2, 0, m*m*sizeof(int));
            int* column_sum = knightmove(gotham, i, row, m-1, n-1, N2);
            printf("row=%d, i=%d: ", row+1, i);
            for(int k=0; k<m; k++){
                printf("%d ", column_sum[k]&1000000007);
            }
            printf("\n");
            for(int j=0; j<m; j++){
                final_sum[j]+=column_sum[j];
            }
        }
        if(row<=n-4){
            for(int j=0; j<m; j++){
                if(gotham[j][row+3]!=BLOCKED){
                    free(gotham[j][row+3]);
                }
            }
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            // final_sum[j]+=gotham[i][0][j];
        }
    }

    for(int i=0; i<m; i++){
        printf("%d ", final_sum[i]&1000000007);
    }

    // for(int i=0; i<m; i++){
    //     printf("%d ", entrances[i]%1000000007);
    // }

}
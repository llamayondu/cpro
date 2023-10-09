#include <stdio.h>

int entrances[1000]={0};
int gotham[1000][1000]={0};
void knightmove(int a[1000][1000], int start_x, int start_y, int end_x, int end_y)
{
    if(start_y==end_y){
        entrances[start_x]++;
    }

    else{

        //wide left move
        if(start_x>=2){
            if(a[start_y+1][start_x-2]==0){
                knightmove(a, start_x-2, start_y+1, end_x, end_y);
            }
        }

        //tall left move
        if(start_x>=1){
            if(start_y<=end_y-2){
                if(a[start_y+2][start_x-1]==0){
                    knightmove(a, start_x-1, start_y+2, end_x, end_y);
                }
            }
        }

        //tall right move
        if(start_y<=end_y-2 && start_x<=end_x-1 && a[start_y+2][start_x+1]==0){
            knightmove(a, start_x+1, start_y+2, end_x, end_y);
        }

        //wide right move
        if(start_x<=end_x-2 && a[start_y+1][start_x+2]==0){
            knightmove(a, start_x+2, start_y+1, end_x, end_y);
        }
    }
}

int main(){

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int temp_x, temp_y;

    

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            gotham[i][j]=0;
        }
    }

    for(int i=0; i<k; i++){
        scanf("%d %d", &temp_x, &temp_y);
        gotham[temp_x-1][temp_y-1]=1;
    }


    for(int i=0; i<m; i++){
        knightmove(gotham, i, 0, m-1, n-1);
    }

    for(int i=0; i<m; i++){
        printf("%d ", entrances[i]%1000000007);
    }

}
#include <stdio.h>
#include <strings.h>

int main(){
    char word[100]={0};
    scanf("%s", word);
    int len=0;
    
    for(len; word[len]!=0; len++);

    int count_capitals=0;
    for(int i=0; i<len; i++){
        if((int) word[i]<='Z' && (int) word[i]>='A'){
            count_capitals++;
        }
    }

    //check the capitals condition 
    if(count_capitals==0 || count_capitals==len){
        printf("No");
    }
    else{
        int isBeautiful=1; 

        //check repetitions
        for(int i=0; i<len-1; i++){
            for(int j=i+1; j<len; j++){
                if(word[i]==word[j]){
                    isBeautiful=0;
                    break;
                }
            }
        }

        if(isBeautiful==0)
            printf("No");
        else
            printf("Yes");
    }
}
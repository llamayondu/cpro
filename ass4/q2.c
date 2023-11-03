#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define DIMENSION 100 //number of dimensions of the complex numbers

//Assumptions:
//1. Maximum number of dimensions of the complex numbers is 100, can be changed in the #define for DIMENSION
//2. Both the numbers have the same number of dimensions
//3. Correct upto 2 decimals has been considered as truncating to 2 decimal places and not equal.

//struct of complex number
typedef struct Complex {
    int dimensions;
    float coeff[DIMENSION];
} Complex;

typedef struct Node {
    Complex com;
    struct Node *next;
} Node;

typedef Node* LinkedList;

Complex add(LinkedList c){
    int n = c->com.dimensions; 
    LinkedList l = (Node *) malloc(sizeof(Node*)+sizeof(int)+n*sizeof(float)); //mallocing a LinkedList to store the addition result 
    for(int i=0; i<n; i++){
        l->com.coeff[i]=c->com.coeff[i]+c->next->com.coeff[i];
    }
    return l->com;
}

Complex sub(LinkedList c){
    int n = c->com.dimensions; 
    LinkedList l = (Node *) malloc(sizeof(Node*)+sizeof(int)+n*sizeof(float)); //mallocing a LinkedList to store the subtraction result
    for(int i=0; i<n; i++){
        l->com.coeff[i]=c->com.coeff[i]-c->next->com.coeff[i];
    }
    return l->com;
}

float dot(LinkedList c){
    float ans=0;
    int n = c->com.dimensions; 
    for(int i=0; i<n; i++){
        ans+=(c->com.coeff[i]*c->next->com.coeff[i]);
    }
    return ans;
}

float cosineSimilarity(LinkedList c){
    float mod1=0;
    float mod2=0;
    int n = c->com.dimensions; 
    for(int i=0; i<n; i++){
        mod1+=c->com.coeff[i]*c->com.coeff[i];
        mod2+=c->next->com.coeff[i]*c->next->com.coeff[i];
    }
    mod1 = sqrt(mod1);
    mod2 = sqrt(mod2);
    return dot(c)/(mod1*mod2);
}

int main(){
    // float c1[DIMENSION];
    // float c2[DIMENSION];
    while(1){
        
        char operation[7];
        scanf("%s", operation);

        //if the command is ADD
        if(strcmp(operation, "ADD")==0){
            int n;
            LinkedList c = (Node *) malloc(sizeof(Node*)+sizeof(int)+n*sizeof(float));
            c->next = (Node *) malloc(sizeof(Node*)+sizeof(int)+n*sizeof(float));
            scanf("%d", &n);
            c->com.dimensions = n;
            c->next->com.dimensions = n;
            for(int i=0; i<n; i++){
                scanf("%f", &c->com.coeff[i]);
            }
            for(int i=0; i<n; i++){
                scanf("%f", &c->next->com.coeff[i]);
            }
            printf("Result: ");
            Complex sum = add(c);
            for(int i=0; i<n; i++){
                //removing the least significant zeroes before printing, does not remove the zero if the resulting value is obtained by rounding off
                if((((int)(sum.coeff[i]*100))%100)==0){
                    printf("%.0f ", sum.coeff[i]);
                } else if ((((int)(sum.coeff[i]*100))%10)==0){
                    printf("%.1f ", sum.coeff[i]);
                } else {
                    printf("%.2f ", sum.coeff[i]);
                }
            }
            printf("\n");

        //if the command is SUB
        } else if(strcmp(operation, "SUB")==0){
            int n;
            LinkedList c = (Node *) malloc(sizeof(Node*)+sizeof(int)+n*sizeof(float));
            c->next = (Node *) malloc(sizeof(Node*)+sizeof(int)+n*sizeof(float));
            scanf("%d", &n);
            for(int i=0; i<n; i++){
                scanf("%f", &c->com.coeff[i]);
            }
            for(int i=0; i<n; i++){
                scanf("%f", &c->next->com.coeff[i]);
            }
            c->com.dimensions = n;
            c->next->com.dimensions = n;
            Complex diff = sub(c);
            printf("Result: ");
            for(int i=0; i<n; i++){
                //removing the least significant zeroes before printing, does not remove the zero if the resulting value is obtained by rounding off
                if((((int)(diff.coeff[i]*100))%100)==0){
                    printf("%.0f ", diff.coeff[i]);
                } else if ((((int)(diff.coeff[i]*100))%10)==0){
                    printf("%.1f ", diff.coeff[i]);
                } else {
                    printf("%.2f ", diff.coeff[i]);
                }
            }
            printf("\n");


        //if the command is COSINE
        } else if(strcmp(operation, "COSINE")==0){
            int n;
            LinkedList c = (Node *) malloc(sizeof(Node*)+sizeof(int)+n*sizeof(float));
            c->next = (Node *) malloc(sizeof(Node*)+sizeof(int)+n*sizeof(float));
            scanf("%d", &n);
            for(int i=0; i<n; i++){
                scanf("%f", &c->com.coeff[i]);
            }
            for(int i=0; i<n; i++){
                scanf("%f", &c->next->com.coeff[i]);
            }
            c->com.dimensions = n;
            c->next->com.dimensions = n;
            printf("Result: ");

            //removing the least significant zeroes before printing, does not remove the zero if the resulting value is obtained by rounding off
            if((((int)(cosineSimilarity(c)*100))%100)==0){
                printf("%.0f\n", cosineSimilarity(c));
            } else if ((((int)(cosineSimilarity(c)*100))%10)==0){
                printf("%.1f\n", cosineSimilarity(c));
            } else {
                printf("%.2f\n", cosineSimilarity(c));
            }

        //if the command is DOT
        } else if(strcmp(operation, "DOT")==0) {
            int n;
            LinkedList c = (Node *) malloc(sizeof(Node*)+sizeof(int)+n*sizeof(float));
            c->next = (Node *) malloc(sizeof(Node*)+sizeof(int)+n*sizeof(float));
            scanf("%d", &n);
            for(int i=0; i<n; i++){
                scanf("%f", &c->com.coeff[i]);
            }
            for(int i=0; i<n; i++){
                scanf("%f", &c->next->com.coeff[i]);
            }
            c->com.dimensions = n;
            c->next->com.dimensions = n;
            printf("Result: ");
            //removing the least significant zeroes before printing, does not remove the zero if the resulting value is obtained by rounding off
            if((((int)(dot(c)*100))%100)==0){
                printf("%.0f\n", dot(c));
            } else if ((((int)(dot(c)*100))%10)==0){
                printf("%.1f\n", dot(c));
            } else {
                printf("%.2f\n", dot(c));
            }

        //if the command is -1
        } else if(strcmp(operation, "-1")==0) {
            break;

        //if the command is not one of those
        } else {
            printf("Please enter a valid operation from the following operations:\nADD\nSUB\nCOSINE\nDOT\n-1\n\n");
        }
    }
}
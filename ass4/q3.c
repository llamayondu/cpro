#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int color;
    struct Node *next;
} Node;

typedef Node* LinkedList;

//function to print all the colors in the list with the required format
void printlist(LinkedList l){
    printf("%d", l->color);
    l=l->next;
    while(l!=NULL){
        printf(" -> %d", l->color);
        l=l->next;
    }
    printf("\n");
}

//function to remove the duplicate colors in the linked list
LinkedList removeDuplicates(LinkedList l){
    LinkedList l_dummy = l; //making a dummy list to preseve l as a pointer to the head
    while(l_dummy!=NULL){
        while(l_dummy->next!=NULL && l_dummy->color==l_dummy->next->color){
            LinkedList temp = l_dummy->next->next;
            free(l_dummy->next);
            l_dummy->next = temp;
        }
        l_dummy=l_dummy->next;
    }
    return l;
}

int main(){
    int n;
    printf("Enter the number of colors in the list: ");
    scanf("%d", &n);
    if(n==0){
        return 0;
    }

    //Populating the list
    printf("Enter the colors: ");
    LinkedList L = (Node *) malloc(sizeof(Node *));
    scanf("%d", &L->color);
    LinkedList L_dummy = L; //making a dummy list to preseve L as a pointer to the head

    //populating the list
    for(int i=0; i<n-1; i++){
        L_dummy->next = (Node *) malloc(sizeof(Node *));
        L_dummy=L_dummy->next;
        scanf("%d", &L_dummy->color);
    }
    L_dummy->next=NULL; //ending the list
    L = removeDuplicates(L); //using the funcion to remove the list, we can also not store the output of the function in L as the function works in place
    printf("Modified Linked List: ");
    printlist(L); //printing the list using the function 
}
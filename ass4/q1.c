#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMELEN 50

//Assumptions:
//1. Maximum length of name is 50, can be changed in the define for NAMELEN
//2. All inputs are correct, in the correct order:
//      for CREATE:  AccountType Name Amount
//      for DELETE:  AccountType Name
//      for TRANSACTION: AccountNumber Amount Code
//3. All values of money have been rounded off to 2 decimal points as each rupee can only have 100 paise
//4. Linked list has been globally defined and the program can work only for one bank

typedef enum AccountType {
    savings,
    current
} AccountType;

typedef struct AccountInfo {
    int account_number;
    AccountType acc_type;
    char name[NAMELEN];
    float balance;
} AccountInfo;

char acctype[2][8] = {"savings", "current"};

typedef struct Node {
    AccountInfo* acc;
    struct Node* next;
} Node;

typedef Node* LinkedList;

LinkedList L=NULL;

void display(){
    LinkedList l_dummy = L;
    if(L==NULL){
        printf("No Accounts to display\n\n");
    } else {
        printf("Account Number\t\tAccount Type\t\tName\t\t Balance\n");
        printf("---------------------------------------------------------------------------------\n");
        while(l_dummy!=NULL){
            printf("%d\t\t\t%s\t\t\t%s\t%16.2f\n", l_dummy->acc->account_number, acctype[l_dummy->acc->acc_type], l_dummy->acc->name, l_dummy->acc->balance);
            l_dummy=l_dummy->next;
        }
        printf("\n");
    }
}

LinkedList createAccount(AccountType accountType, char* Name, float Amount){
    //In the case of an empty list
    if(L==NULL){
        Node* newAccount = (Node *) malloc(sizeof(Node));
        newAccount->next = NULL;
        newAccount->acc = (AccountInfo *) malloc(sizeof(AccountInfo));
        strcpy(newAccount->acc->name, Name);
        newAccount->acc->acc_type = accountType;
        newAccount->acc->balance = Amount;
        newAccount->acc->account_number = 100;
        printf("Account Number: %d\nAccount Holder: %s\nAccount Type: %s\nBalance: Rs %.2f\n\n", newAccount->acc->account_number, newAccount->acc->name, acctype[newAccount->acc->acc_type], newAccount->acc->balance);
        L=newAccount;
        return L;
    }

    //Checking if the desired account already exists
    LinkedList l_dummy=L;
    int alreadyExists=0;
    while(l_dummy!=NULL){
        if(strcmp(l_dummy->acc->name, Name)==0 && l_dummy->acc->acc_type==accountType){
            alreadyExists=1;
            break;
        }
        l_dummy=l_dummy->next;
    }

    //If the account already exists
    if(alreadyExists==1){
        printf("Invalid: User already exists!\n");
        return L;
    }

    //Otherwise, mallocing a space to store the new account and then populating it
    Node* newAccount = (Node *) malloc(sizeof(Node));
    newAccount->next = NULL;
    newAccount->acc = (AccountInfo *) malloc(sizeof(AccountInfo));
    strcpy(newAccount->acc->name, Name);
    newAccount->acc->acc_type = accountType;
    newAccount->acc->balance = Amount;
    l_dummy = L;
    int acc_num;

    //If account number 100 is not taken, we assign that as the account number for the new account
    if(l_dummy->acc->account_number!=100){
        acc_num = 100;
        newAccount->acc->account_number = acc_num;
        printf("Account Number: %d\nAccount Holder: %s\nAccount Type: %s\nBalance: Rs %.2f\n\n", newAccount->acc->account_number, newAccount->acc->name, acctype[newAccount->acc->acc_type], newAccount->acc->balance);
        LinkedList temp = l_dummy;
        L=newAccount;
        newAccount->next = temp;
        return L;
    }

    //Otherwise, keep proceeding until first time there is a gap in the account number or until we reach end of linked list
    while(l_dummy->next!=NULL && l_dummy->next->acc->account_number - l_dummy->acc->account_number == 1){
        l_dummy=l_dummy->next;
    }

    //assigning the acc num in the first gap or the last one 
    acc_num = l_dummy->acc->account_number + 1;
    newAccount->acc->account_number = acc_num;
    printf("Account Number: %d\nAccount Holder: %s\nAccount Type: %s\nBalance: Rs %.2f\n\n", newAccount->acc->account_number, newAccount->acc->name, acctype[newAccount->acc->acc_type], newAccount->acc->balance);
    LinkedList temp = l_dummy->next;
    l_dummy->next=newAccount;
    newAccount->next = temp;
    return L;
}

LinkedList deleteAccount(AccountType accountType, char* Name) {
    LinkedList l_dummy = L;

    //if the first account is to be deleted
    if(L->acc->acc_type == accountType && strcmp(L->acc->name, Name)==0){
        LinkedList temp=L->next;
        free(L);
        L=temp;
        printf("Account deleted successfully\n\n");
        return L;
    }

    //if the second account is to be deleted
    if(l_dummy->next==NULL && strcmp(l_dummy->acc->name, Name)==0 && l_dummy->acc->acc_type == accountType){
        free(l_dummy);
        L=NULL;
        printf("Account deleted successfully\n\n");
        return L;
    }

    //keep going till we reach the required user to be deleted
    while(l_dummy!=NULL && l_dummy->next!=NULL){
        if(l_dummy->next->acc->acc_type == accountType && strcmp(l_dummy->next->acc->name, Name) == 0){
            break;
        }
        l_dummy=l_dummy->next;
    }

    //if the user does not exist
    if(l_dummy == NULL || (l_dummy->next==NULL && (l_dummy->acc->acc_type != accountType || strcpy(l_dummy->acc->name, Name) != 0))){
        printf("Invalid: User does not exist\n\n");
        return L;
    }
    LinkedList temp = l_dummy->next->next;
    free(l_dummy->next);
    l_dummy->next = temp;
    printf("Account deleted successfully\n\n");
    return L;
}

void lowBalanceAccounts(){
    LinkedList l_dummy = L;
    while(l_dummy!=NULL){
        if(l_dummy->acc->balance<100){
            printf("Account Number: %d, Name: %s, Balance: %.2f\n", l_dummy->acc->account_number, l_dummy->acc->name, l_dummy->acc->balance);
        }
        l_dummy=l_dummy->next;
    }
    printf("\n");
}

void transaction(int accountNumber, float amount, int code){
    LinkedList l_dummy = L;

    //keep going till wee reach the required user
    while(l_dummy!=NULL && l_dummy->acc->account_number != accountNumber){
        l_dummy=l_dummy->next;
    }
    if(l_dummy==NULL){
        printf("Invalid: User does not exist\n\n");
    } else if(code==0 && (l_dummy->acc->balance-amount)<amount){
        printf("The balance is insufficient for the specified withdrawal.\n\n");
    } else if (code==0) {
        l_dummy->acc->balance-=amount;
        printf("Updated balance is Rs %.2f\n\n", l_dummy->acc->balance); //if money is withdrawnn
    } else {
        l_dummy->acc->balance+=amount;
        printf("Updated balance is Rs %.2f\n\n", l_dummy->acc->balance); //if mmoney is deposited
    }
}

int main(){
    while(1){
        char operation[10];
        scanf("%s", operation);

        //if the command is CREATE
        if(strcmp(operation, "CREATE")==0){
            char account_type[8];
            char name[NAMELEN];
            float amount;
            scanf("%s %s %f", account_type, name, &amount);
            if(strcmp(account_type, "savings")==0){
                createAccount(savings, name, amount);
            } else if(strcmp(account_type, "current")==0) {
                createAccount(current, name, amount);
            }
            
        //if the command is DELETE
        } else if(strcmp(operation, "DELETE")==0){
            char account_type[8];
            char name[NAMELEN];
            scanf("%s %s", account_type, name);
            if(strcmp(account_type, "savings")==0){
                deleteAccount(savings, name);
            } else if(strcmp(account_type, "current")==0) {
                deleteAccount(current, name);
            }

        //if the command is TRANSACTION
        } else if(strcmp(operation, "TRANSACTION")==0){
            int account_number, code;
            float amount;
            scanf("%d %f %d", &account_number, &amount, &code);
            transaction(account_number, amount, code);

        //if the command is LOWBALANCE
        } else if(strcmp(operation, "LOWBALANCE")==0) {
            lowBalanceAccounts();

        //if the command is DISPLAY
        } else if(strcmp(operation, "DISPLAY")==0) {
            display();

        //if the command is EXIT
        } else if(strcmp(operation, "EXIT")==0) {
            break;

        //if the command is not one of those
        } else {
            printf("Please enter a valid operation from the following operations:\nCREATE\nDELETE\nTRANSACTION\nLOWBALANCE\nDISPLAY\nEXIT\n\n");
        }
    }
}
# **Assignment 4**

## **Question 1 - *Bank Accounts***

### **Program:**

The program simulates the working of a bank that allows the addition and deletion of accounts, transactions related to the account and other functions that can be useful in a bank.

The program takes one of six inputs:

        CREATE AccountType Name Amount
        DELETE AccountType Name
        TRANSACTION AccountNumber Amount Code
        LOWBALANCE
        DISPLAY
        EXIT

It performs the actions required as explained in the functions below.

### **Headers Used:**

1. #include <stdio.h>
2. #include <stdlib.h>
3. #include <string.h>

### **Functions Used**:

1. **display ( )**

    - Displays all the accounts currently present in the bank in the format

            Account Number  Account Type    Name    Balance
    - If there are no accounts in the bank, it prints *"No Accounts to display"*.

2. **createAccount ( Account Type, Name, Amount )**

    - Takes the parameters *Account Type*, *Name* and *Amount*
    - Creates a new account with the given account type, name and amount
    - Prints the details of the new account created in the format
        
            Account Number: Num
            Account Holder: Name
            Account Type: savings/current
            Balance: Rs x

    - Here, x is the floatinc point number for the balance in the account
    - If the account already exists, prints *"Invalid: User already exists!"*


3. **deleteAccount ( Account Type, Name )**

    - Takes the parameters *Account Type* and *Name*
    - Searches for the account of the given details in the bank
    - If the account exists, it deletes the account and prints *"Account deleted successfully!"*
    - If the account does not exist in the bank, it prints *"Invalid: User does not exist"*

4. **lowBalanceAccounts ( )**

    - Prints all the accounts with a balance of less than Rs 100

5. **transaction ( Account Number, Amount, Code )**

    - Takes the parameters *Account Number*, *Amount* and *Code*
    - Searches for the account with the given details
    - If the user does not exist in the bank, prints *“Invalid: User does not exist”*
    - If the code input is 1, the amount is added to the balance of the account
    - If the code input is 0, the amount is deducted from the balance of the account
    - If the balance after deduction would be less than Rs 100, no amount would be deducted and the function prints *"The balance is insufficient for the specified withdrawal."*
    - After a successful transaction, the function prints *"Updated balance is Rs x"*, where x is the updated balance

### **Data Structures Used:**

1. **enum AccountType**

    - Enumerates the values *savings* and *current* as 0 and 1 to be used in the functions

2. **struct AccountInfo**

    - Contains four fields related to a bank account:

            Account Number
            Account Type
            Name
            Balance

    - The name is an array of max length *NAMELEN* and balance is a floating point number

3. **struct Node**

    - Node is used to create a Linked List, each of whose elements points to the next element, if any, and points to NULL if it is the last element.
    - Contains two fields:

            Account
            Next

    - Account is of type *struct AccountInfo* and Next is a pointer to the Next node which will be used in the Linked List.
    - Note: Node pointer has been typedefined to LinkedList for ease in usage in the program

### **Assumptions Made:**

1. All the inputs are in the correct order as mentioned above

2. All values of money have been rounded off to two decimal places as each rupee can only have 100 paise.

3. Linked list has been globally defined and hence program can only work for one bank and is not easily explandable.

## **Question 2 - *Complex Numbers***

### **Program:**

The program takes an input of two commplex numbers of the same dimension and an integer input, *n*,  for the number of dimensions of the inputs. It also takes one of five operations in the following format:

        ADD n
        C1
        C2

        SUB
        C1
        C2

        COSINE
        C1
        C2

        DOT
        C1
        C2
        
        -1

Here, n is the number of dimensions of the complex numbers and C1 and C2 are the two complex numbers taken in the format:

        a1 a2 b3 ... an
        b1 b2 b3 ... bn

Here, a1, a2, a3, ... an are the coefficients of each dimension of the first complex number and b1, b2, b3, ... bn for the second. 

The function operations are explained below:

### **Functions Used:**

1. **add ( Linked List )**

    - Takes a linked list as an argument
    - Adds the complex numbers in the first and second node of the linkedlist
    - Returns a complex number which is the sum of the two given complex numbers

2. **sub ( Linked List )**

    - Takes a linked list as an argument
    - Subtracts the second complex number from the first complex number of the given linked list
    - Returns a complex number which is the difference of the two given complex numbers

3. **dot ( Linked List )**

    - Takes a linked list as an argument
    - Computes the dot product of the two commplex numbers in the linked list
    - Returns the floating point number of the resultant dot product of the given complex numbers

4. **cosineSimilarity ( Linked List )**

    - Takes a linked list as an argument
    - Computes the cosine similarity between the two complex numbers of the given linked list
    - Returns the floating point number of the resultant cosine similarity between the two given complex numbers

### **Data Structures Used:**

1. **struct Complex**

    Contains two fields:

            dimensions
            coeff[DIMENSION]

    Here, dimensions is an integer which determines the number of dimensions of the complex number stored in the struct and coeff is an array which stores all the coefficients of each term of the complex number. Note that DIMENSION is the maximum number of dimensions that the complex number can have and has been set to 100 by default.

2. **struct Node**

    - Node is used to create a Linked List, each of whose elements points to the next element, if any, and points to NULL if it is the last element.
    - Contains two fields:

            Complex
            Next

    - Complex is of type *struct Complex* and Next is a pointer to the Next node which will be used in the Linked List.
    - Note: Node pointer has been typedefined to LinkedList for ease in usage in the program

### **Assumptions made:**

1. Maximum number of dimensions that a complex number can have is 100. This can be changed in the #define for DIMENSION.
2. Both the complex numbers have the same number of dimensions.
3. Correct upto 2 decimal placed has been assumed to mean truncating upto 2 decimal places and not equal values of each place value. For example, *3.978* has been displayed as *3.98* and not *3.97*.

## **Question 3 - *Colors***

### **Program:**

The program takes and input n followed by n integer inputs in non-decreasing order. These n inputs are considered to be colors and are arranged in a linked list in the order given by the user. The program then makes use of a function to delete any duplicates and then prints the new linked list.

### **Functions Used:**

1. **printlist ( Linked List )**

    - Takes a linked list as an argument
    - Iterates through the linked list, while printing the color stored in each node of the linked list in the following format


            a1 -> a2 -> a3 -> ... -> an

    Here, a1, a2, a3, ... an are the n colors given by the user.

2. **removeDuplicates ( Linked List )**

    - Iterates through the linked list and if the colors of any two consecutive nodes are the same, it deletes the latter of the two and repeats the process until it reaches the last node
    - This way, all the duplicates are deleted
    - Note that the function deletes duplicates in place, so it would work even if we do not assign the returned linked list value

### **Structures Used:**

1. **struct Node**

    - Node is used to create a Linked List, each of whose elements points to the next element, if any, and points to NULL if it is the last element.
    - Contains two fields:

            Color
            Next

    - Color is an integer value which dennotes the color stored in the particular node
    - Note: Node pointer has been typedefined to LinkedList for ease in usage in the program
 
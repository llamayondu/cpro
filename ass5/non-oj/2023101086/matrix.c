#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

Matrix* create_matrix(int r, int c) {
    Matrix* m = (Matrix*) malloc(sizeof(Matrix));
    m->num_rows = r;
    m->num_cols = c;
    m->data = (long long int**) calloc(r, sizeof(long long int*));
    for (int i =0; i < r; i++) {
        m->data[i] = (long long int*) calloc(c, sizeof(long long int));
    }
    return m;
}

void destroy_matrix(Matrix* m) {
    // 1: Write code here to free all memory used by the matrix stored in m
    for(int i=0; i<m->num_rows; i++){
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

Matrix* add_matrix(Matrix* A, Matrix* B) {
    // 2: write code here to add the matrices A and B and return a new matrix with the results.
    // A, B should remain unmodified. If dimensions don't match, it should return NULL.
    if(A->num_cols!=B->num_cols || A->num_rows!=B->num_rows){
        return NULL;
    }
    Matrix* m = create_matrix(A->num_rows, A->num_cols);

    for(int i=0; i<m->num_rows; i++){
        for(int j=0; j<m->num_cols; j++){
            m->data[i][j]=A->data[i][j]+B->data[i][j];
        }
    }
    return m;
}

Matrix* mult_matrix(Matrix* A, Matrix* B) {
// 3: write code here to multiply the matrices A and B and return a new matrix with the results.
// A, B should remain unmodified. If the dimensions don't match, it should return NULL.
    if(A->num_cols!=B->num_rows){
        return NULL;
    }

    Matrix* m = create_matrix(A->num_rows, B->num_cols);

    for(int row=0; row<A->num_rows; row++){
        for(int col=0; col<B->num_cols; col++){
            int temp=0;
            for(int i=0; i<A->num_cols; i++){
                temp+=(A->data[row][i])*(B->data[i][col]);
            }
            m->data[row][col]=temp;
        }
    }
    return m;
}

Matrix* scalar_mult_matrix(long long int s, Matrix* M) {
// 4: write code here to multiply the matrix A with a scalar s and return a new matrix with the results.
// M should remain unmodified.
    Matrix* m = create_matrix(M->num_rows, M->num_cols);

    for(int row=0; row<m->num_rows; row++){
        for(int col=0; col<m->num_cols; col++){
            m->data[row][col] = s*M->data[row][col];
        }
    }

    return m;
}

int check_square(Matrix* A){
    if(A->num_cols == A->num_rows){
        return 1;
    }
    return 0;
}

Matrix* transpose_matrix(Matrix* A) {
// 5: write code here to find the transpose of given matrix A and return a new matrix with the results.
// A should remain unmodified.
    Matrix* m = create_matrix(A->num_cols, A->num_rows);

    for(int row=0; row<m->num_rows; row++){
        for(int col=0; col<m->num_cols; col++){
            m->data[row][col] = A->data[col][row];
        }
    }

    return m;
}

long long int determinant(Matrix* M) {
// 6: Write code here to calculate the determinant of the given matrix M (if not a square matrix, return -1).
// Return the determinant value.
    long long int det = 0;
    if(M->num_cols==1){
        return M->data[0][0];
    }
    if(M->num_cols == 2){
        det = (M->data[0][0]*M->data[1][1]) - (M->data[0][1]*M->data[1][0]);
        return det;
    }
    long long int minor[M->num_cols];
    memset(minor, 0, M->num_cols*sizeof(long long int));
    for(int col=0; col<M->num_cols; col++){
        Matrix* m = create_matrix(M->num_rows-1, M->num_cols-1);
        int index = 0;
        for(int column=0; column<M->num_cols; column++){
            if(column == col){
                continue;
            }
            for(int row=0; row<m->num_rows; row++){
                m->data[row][index] = M->data[row+1][column];
            }
            index++;
        }
        minor[col] = determinant(m);
        destroy_matrix(m);
    }
    for(int i=0; i<M->num_cols; i++){
        if(i%2==0){
            det+=M->data[0][i]*minor[i];
        } else {
            det-=M->data[0][i]*minor[i];
        }
    }
    return det;
}

// DO NOT MODIFY THE OUTPUT FORMAT of this function. Will be used for grading
void print_matrix(Matrix* m) {
    printf("%d %d\n", m->num_rows, m->num_cols);
    for (int i = 0; i < m->num_rows; i++) {
        for (int j = 0; j < m->num_cols; j++) {
            printf("%lld ", m->data[i][j]);
        }
        printf("\n");
    }
}

Matrix* read_matrix_from_file(char fn[]){
    FILE* fp = fopen(fn, "r");
    if(fp==NULL){
        printf("ERROR: INVALID ARGUMENT");
        return NULL;
    }
    int r, c;
    fscanf(fp, "%d %d\n", &r, &c);
    Matrix* m = create_matrix(r, c);
    for(int i=0; i<m->num_rows; i++){
        for(int j=0 ;j<m->num_cols; j++){
            fscanf(fp, "%lld", &m->data[i][j]);
        }
    }
    fclose(fp);
    return m;
}

void write_matrix_to_file(char fn[], Matrix* M){
    FILE* fp = fopen(fn, "w");
    if(fp==NULL){
        printf("ERROR: INVALID ARGUMENT");
        return;
    }
    fprintf(fp, "%d %d\n", M->num_rows, M->num_cols);
    for(int i=0; i<M->num_rows; i++){
        for(int j=0; j<M->num_cols; j++){
            fprintf(fp, "%lld ", M->data[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}
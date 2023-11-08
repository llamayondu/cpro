
// REMEMBER TO DESTROY ALL MATRICES CREATED INSIDE THE FUNCITONS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

int main() {
    int q;
    scanf("%d", &q);

    FILE* hist = fopen("mx_history", "a");
    if(hist==NULL)
        printf("burh");

    for(int reps=0; reps<q; reps++){
        char operation[20];
        int destination;
        scanf("%s", operation);
        if(strcmp(operation, "history")==0){
            fprintf(hist, "LOG::%s\n", operation);
            FILE* history = fopen("mx_history", "r");
            char ch;
            do {
                ch = fgetc(history);
                putchar(ch);
            } while(ch != EOF);
            
            continue;
        }
        scanf("%d", &destination);
        fprintf(hist, "LOG::%s %d\n", operation, destination);

        if(destination==0){
            if(strcmp(operation, "add_matrix")==0){
                int r1, c1;
                scanf("%d %d", &r1, &c1);
                Matrix* m1 = create_matrix(r1, c1);
                for(int i=0; i<r1; i++){
                    for(int j=0; j<c1; j++){
                        scanf("%lld", &m1->data[i][j]);
                    }
                }

                int r2, c2;
                scanf("%d %d", &r2, &c2);
                Matrix* m2 = create_matrix(r2, c2);
                for(int i=0; i<r2; i++){
                    for(int j=0; j<c2; j++){
                        scanf("%lld", &m2->data[i][j]);
                    }
                }

                Matrix* result = add_matrix(m1, m2);
                if(result==NULL){
                    printf("ERROR: INVALID ARGUMENT\n");
                    continue;
                }
                print_matrix(result);

                destroy_matrix(m1);
                destroy_matrix(m2);
                destroy_matrix(result);

            } else if(strcmp(operation, "mult_matrix")==0){
                int r1, c1;
                scanf("%d %d", &r1, &c1);
                Matrix* m1 = create_matrix(r1, c1);
                for(int i=0; i<r1; i++){
                    for(int j=0; j<c1; j++){
                        scanf("%lld", &m1->data[i][j]);
                    }
                }

                int r2, c2;
                scanf("%d %d", &r2, &c2);
                Matrix* m2 = create_matrix(r2, c2);
                for(int i=0; i<r2; i++){
                    for(int j=0; j<c2; j++){
                        scanf("%lld", &m2->data[i][j]);
                    }
                }

                Matrix* result = mult_matrix(m1, m2);
                if(result==NULL){
                    printf("ERROR: INVALID ARGUMENT\n");
                    continue;
                }
                print_matrix(result);

                destroy_matrix(m1);
                destroy_matrix(m2);
                destroy_matrix(result);

            } else if(strcmp(operation, "scalar_mult_matrix")==0){
                long long int s;
                scanf("%lld", &s);

                int r, c;
                scanf("%d %d", &r, &c);
                Matrix* m = create_matrix(r, c);
                for(int i=0; i<r; i++){
                    for(int j=0; j<c; j++){
                        scanf("%lld", &m->data[i][j]);
                    }
                }

                Matrix* result = scalar_mult_matrix(s, m);
                print_matrix(result);

                destroy_matrix(m);
                destroy_matrix(result);

            } else if(strcmp(operation, "transpose_matrix")==0){
                int r, c;
                scanf("%d %d", &r, &c);
                Matrix* m = create_matrix(r, c);
                for(int i=0; i<r; i++){
                    for(int j=0; j<c; j++){
                        scanf("%lld", &m->data[i][j]);
                    }
                }

                Matrix* result = transpose_matrix(m);

                if(result==NULL){}
                print_matrix(result);

                destroy_matrix(m);
                destroy_matrix(result);


            } else if(strcmp(operation, "determinant")==0){
                int r, c;
                scanf("%d %d", &r, &c);
                Matrix* m = create_matrix(r, c);
                for(int i=0; i<r; i++){
                    for(int j=0; j<c; j++){
                        scanf("%lld", &m->data[i][j]);
                    }
                }
                if(check_square(m)!=1){
                    printf("ERROR: INVALID ARGUMENT\n");
                    continue;
                }
                printf("%lld\n", determinant(m));

                destroy_matrix(m);

            }
        } else if(destination==1){
            if(strcmp(operation, "add_matrix")==0){
                char a[4096];
                char b[4096];
                scanf("%s", a);
                scanf("%s", b);
                char dest[4096];
                scanf("%s", dest);
                Matrix* m1 = read_matrix_from_file(a);
                Matrix* m2 = read_matrix_from_file(b);
                Matrix* result = add_matrix(m1, m2);
                write_matrix_to_file(dest, result);

                destroy_matrix(m1);
                destroy_matrix(m2);
                destroy_matrix(result);

            } else if(strcmp(operation, "mult_matrix")==0){
                char a[4096];
                char b[4096];
                scanf("%s", a);
                scanf("%s", b);
                char dest[4096];
                scanf("%s", dest);
                Matrix* m1 = read_matrix_from_file(a);
                Matrix* m2 = read_matrix_from_file(b);
                Matrix* result = mult_matrix(m1, m2);
                write_matrix_to_file(dest, result);

                destroy_matrix(m1);
                destroy_matrix(m2);
                destroy_matrix(result);

            } else if(strcmp(operation, "scalar_mult_matrix")==0){
                long long int s;
                scanf("%lld", &s);
                char a[4096];
                scanf("%s", a);
                char dest[4096];
                scanf("%s", dest);
                Matrix* m = read_matrix_from_file(a);
                Matrix* result = scalar_mult_matrix(s, m);
                write_matrix_to_file(dest, result);

                destroy_matrix(m);
                destroy_matrix(result);

            } else if(strcmp(operation, "transpose_matrix")==0){
                char a[4096];
                scanf("%s", a);
                char dest[4096];
                scanf("%s", dest);
                Matrix* m = read_matrix_from_file(a);
                Matrix* result = transpose_matrix(m);
                write_matrix_to_file(dest, result);

                destroy_matrix(m);
                destroy_matrix(result);

            } else if(strcmp(operation, "determinant")==0){
                char a[4096];
                scanf("%s", a);
                Matrix* m = read_matrix_from_file(a);
                if(m->num_cols!=m->num_rows){
                    printf("ERROR: INVALID ARGUMENT\n");
                    continue;
                }
                long long int det;
                det = determinant(m);
                printf("%lld", det);

                destroy_matrix(m);
            }
        }
    }
}

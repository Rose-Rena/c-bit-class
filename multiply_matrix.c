/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix {
    int row;
    int col;
    int** data;
} Matrix;

Matrix* create(int m, int n) {
    Matrix* res;
    res = (Matrix*) malloc(sizeof(Matrix));
    res->row = m;
    res->col = n;
    res->data = (int**) malloc(m * sizeof(int*));
    for(int i = 0; i < m; i++){
        res->data[i] = (int*) malloc(n * sizeof(int));
    }
    return res;
}

void fill(int c, Matrix* res){
    int m = res->row;
    int n = res->col;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            res->data[i][j] = c;
        }
    }
}

Matrix* add(Matrix* a, Matrix* b) {
    int m1 = a->row;
    int m2 = b->row;
    int n1 = a->col;
    int n2 = b->col;
    if(m1 != m2 || n1 != n2){
        return NULL;
    }
    int m = a->row;
    int n = a->col;
    Matrix* res = create(m, n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            res->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return res;
}

Matrix* multiply(Matrix* a, int c) {
    int m = a->row;
    int n = a->col;
    Matrix* res = create(m, n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            res->data[i][j] = a->data[i][j] * c;
        }
    }
    return res;
}

Matrix* negate(Matrix* a) {
    return multiply(a, -1);
}

Matrix* subtract(Matrix* a, Matrix* b){
    return add(a, negate(b));
}

Matrix* transpose(Matrix* a){
    int m = a->col;
    int n = a->row;
    Matrix* res = create(m, n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            res->data[i][j] = a->data[j][i];
        }
    }
    return res;
}

int* get_row(Matrix* b, int n){
    return b->data[n];
}

int* get_col(Matrix* b, int n){
    int* col = (int*) malloc(b->row * sizeof(int)); 
    for(int i = 0; i < b->row; i++){
        col[i] = b->data[i][n];
    }
    return col;
}

int sum_multiply(int size, int* row, int* col){
   int sum = 0;
   for(int i = 0; i < size; i++){
        sum += col[i] * row[i];
    } 
    return sum;
}

Matrix* multiply_matrix(Matrix* a, Matrix* b){
    if(a->col != b->row){
        return NULL;
    }
    Matrix* res = create(a->row, b->col);
    for(int i = 0; i < a->row; i++){
        int* r = get_row(a, i);
        for(int j = 0; j < b->col; j++){ 
        	int* c = get_col(b, j);
        	int sum = sum_multiply(a->col, r, c);           
        	res->data[i][j] = sum;
        }
    }
    return res;
}

void print(Matrix* res){
    if(res == NULL){
        printf("NULL\n");
    }
    int m = res->row;
    int n = res->col;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", res->data[i][j]);
        }
        printf("\n");
    }
}

void test_matrix_multiply(){
    printf("test_matrix_multiply\n");
    Matrix* a = create(2, 3);
    Matrix* b = create(3, 2);
    fill(10, a);
    fill(2, b);
    print(multiply_matrix(a, b));
}

void test_create(){
    printf("test_create\n");
    Matrix* res = create(8, 9);
    fill(2, res);
    print(res);
}

void test_add(){
    printf("test_add\n");
    Matrix* a = create(3, 3);
    Matrix* b = create(3, 3);
    fill(10, a);
    fill(2, b);
    print(add(a, b));
}

void test_add_fail(){
    printf("test_add_fail\n");
    Matrix* a = create(3, 3);
    Matrix* b = create(8, 3);
    fill(10, a);
    fill(2, b);
    print(add(a, b));
}

int main(){
    test_create();
    test_add();
    // test_add_fail();
    test_matrix_multiply();
}
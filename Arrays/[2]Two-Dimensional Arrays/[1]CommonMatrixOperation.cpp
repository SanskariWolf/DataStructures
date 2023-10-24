#include<iostream>
#include<math.h>
using namespace std;
const int MAX = 3;

class matrix{
    private:
        int mat[MAX][MAX];
    public:
        matrix();
        void create();
        void display();
        void matmul(matrix &m1,matrix &m2);
        void matadd(matrix &m1,matrix &m2);
        void transpose(matrix &m1);
        int determinant();
};

matrix::matrix(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            mat[i][j]=0;
        }
    }
}

void matrix::create(){
    int n;
     for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            cout << "\nEnter the elements mat[" << i <<"][" << j << "] : ";
            cin >> n;
            mat[i][j]=n;
        }
     }
}

void matrix::display(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            cout << mat[i][j];
        }
        cout << endl;
    }
}

void matrix::matadd(matrix &m1,matrix &m2){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            mat[i][j]=m1.mat[i][j]+m2.mat[i][j];
        }
    }
}

void matrix::matmul(matrix &m1,matrix &m2){
    for(int k=0;k<MAX;k++){
        for(int i=0;i<MAX;i++){
            for(int j=0;j<MAX;j++){
                mat[k][i]+=m1.mat[k][j]*m2.mat[j][i];
            }
        }
    }
}

void matrix::transpose(matrix &m1){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            mat[i][j]=m1.mat[j][i];
        }
    }
}

int matrix::determinant(){
    int sum,j,k,p;
    sum=0;j=1,k=MAX-1;

    for(int i=0;i<MAX;i++){
        p=pow(-1,i);
        if(i==MAX-1){
            k=1;
        }
        sum+=(mat[0][i]*(mat[1][j]*mat[2][k]-mat[2][j]*mat[1][k]))*p;
        j=0;
    }
    return sum;
}


int main(){
    matrix mat1;
    cout << "Enter the elements of first array : \n";
    mat1.create();

    cout << "\nFirst Matrix : \n";
    mat1.display();

    matrix mat2;
    cout << "Enter the elements of first array : \n";
    mat2.create();

    cout << "\nSecond Matrix : \n";
    mat2.display();

    matrix mat3;
    mat3.matadd(mat1,mat2);
    cout << "\nAfter addition : \n";
    mat3.display();

    matrix mat4;
    mat4.matmul(mat1,mat2);
    cout << "\nAfter mulitplication : \n";
    mat4.display();

    matrix mat5;
    mat5.transpose(mat1);
    cout << "\nTranspose of first matrix : \n";
    mat5.display();
    
    cout << "\nDeterminant of first matrix : \n";
    cout << mat1.determinant();
    return 0;
}
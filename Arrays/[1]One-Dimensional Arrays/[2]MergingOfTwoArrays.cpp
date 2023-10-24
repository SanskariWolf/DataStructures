#include<iostream>
using namespace std;

const int MAX1=5;
const int MAX2=7;

class array{
    private:
        int *arr;
        int size;
    public:
        void create(int sz);
        void sort();
        void display();
        void merge(array &a, array &b);
};

void array::create(int sz){
    size =sz;
    arr = new int[size];
    int n;
    for(int i=0;i<size;i++){
        cout <<"\nEnter the element no. " << (i+1) <<" ";
        cin >> n;
        arr[i]=n;
    }
}

void array::sort(){
    int temp;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]>arr[i+1]){
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
}

void array::display(){
    for(int i=0;i<size;i++){
        cout << " " << arr[i];
    }
}

void array::merge(array &a, array &b){
    int i,k,j;
    size=a.size+b.size;
    arr = new int[size];

    for(k=0,j=0,i=0;i<=size;i++){
        if(a.arr[k]<b.arr[j]){
            arr[i]=a.arr[k];
            k++;
            if(k>=a.size){
                for(i++;j<b.size;j++,i++){
                    arr[i]=b.arr[j];
                }
            }else{
                arr[i]=b.arr[j];
                j++;
                if(j>=b.size){
                    for(i++;k<a.size;k++,i++){
                        arr[i]=arr[k];
                    }
                }
            }
        }
    }
}

int main(){
    array a;
    cout << "\nEnter elements for first array: \n";
    a.create(MAX1);

    array b;
    cout << "\nEnter elements for second array: \n";
    a.create(MAX2);

    a.sort();
    b.sort();

    cout << "\nFirst array : \n";
    a.display();

    cout << "\nSecond array : \n";
    b.display();

    array c;
    c.merge(a,b);

    cout << "\nArray after merging : \n";
    c.display();
    
    return 0;
}
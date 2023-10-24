#include<iostream>
using namespace std;
const int MAX = 4;

class array{
    private:
        int arr[MAX]={0};
    public:
        void insert(int pos, int num);
        void del(int pos);
        void reverse();
        void display();
        void search(int num);
};

void array::insert(int pos, int num){
    int i;
    for(i = MAX-1; i>=pos;i--){
        arr[i]=arr[i-1];
    }
    arr[i]=num;
}

void array::del(int pos){
    int i;
    for(i = pos ; i<MAX ; i++){
        arr[i-1]=arr[i];
    }
    arr[i-1]=0;
}

void array::reverse(){
    int i;
    for(i=0;i<MAX/2;i++){
        int temp=arr[i];
        arr[i]=arr[MAX-1-i];
        arr[MAX-1-i]=temp;
    }
}

void array::display(){
    cout << endl;

    for(int i=0; i<MAX;i++){
        cout << " " << arr[i];
    }
}

void array::search(int num){
    int i;
    for(i=0;i<MAX;i++){
        if(arr[i]==num){
            cout << "\n\nThe element " << num << " is present at " << (i+1) << " position\n";
            return;
        }
    }

    if (i==MAX){
        cout << "\n\nThe element is not present in the array";
    }
}

int main(){
    array a;

    a.insert(1,1);
    a.insert(2,2);
    a.insert(3,3);
    a.insert(4,4);

    cout << "\n\nElements of array : ";
    a.display();

    a.del(3);

    cout << "\n\nElements of array : ";
    a.display();

    a.reverse();

    cout << "\n\nElements of array : ";
    a.display();
    return 0;
}
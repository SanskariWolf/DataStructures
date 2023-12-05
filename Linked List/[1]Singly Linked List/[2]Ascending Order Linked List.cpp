#include<iostream>
using namespace std;

class linklist{
    private:
        struct node{
            int data;
            node *link;
        }*p;
    public:
        linklist();
        void add(int num);
        void display();
        int count();
        void del(int num);
        ~linklist();
};

linklist::linklist(){
    p=NULL;
}

void linklist::add(int num){
    
}

void linklist::display(){
    node *temp;
    temp = p;
    cout << "\nThe list is : ";
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> link;
    }
    cout << endl;
}

int linklist::count(){
    int c = 0;
    node *temp;
    temp = p;
    cout << "\nThe count is : ";
    while(temp != NULL){
        temp = temp -> link;
        c++;
    }
    cout << c << endl;
}

void linklist::del(int num){

}

linklist::~linklist(){
    node *q;
    while(p != NULL){
        q = p -> link;
        delete p;
        p = q;
    }
}

int main(){

    return 0;
}
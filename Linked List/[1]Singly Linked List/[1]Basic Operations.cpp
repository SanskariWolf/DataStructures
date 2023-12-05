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
        void append(int num);
        void addatbeg(int num);
        void addafter(int loc, int num);
        void display();
        int count();
        void del(int num);
        ~linklist();
};

linklist::linklist(){
    p=NULL;
}

void linklist::append(int num){
    node *temp, *r;
    if(p==NULL){
        temp = new node;
        temp -> data = num;
        temp -> link = NULL;
        p=temp;
    }else{
        temp = p;
        
        while(temp -> link != NULL){
            temp = temp -> link;
        }
        r = new node;
        r -> data = num;
        r -> link = NULL;
        temp -> link = r;
    }
}

void linklist::addatbeg(int num){
    node *temp;
    temp = new node;
    temp -> data = num;
    temp -> link =p;
    p=temp;
}

void linklist::addafter(int loc, int num){
    node *temp, *r;
    temp = p;

    for(int i=0;i<loc;i++){
        temp = temp -> link;
        if(temp == NULL){
            cout << "\nThere are less than " << loc << " elements in list" << endl;
            return;
        }
    }

    r=new node;
    r -> data = num;
    r -> link = temp -> link;
    temp -> link = r;
}

void linklist::display(){
    node *temp;
    temp = p;
    cout << endl;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> link;
    }
    cout << endl;
}

int linklist::count(){
    node *temp = p;
    int c = 0;
    while(temp != NULL){
        temp = temp -> link;
        c++;
    }
    return c;
}

void linklist::del(int num){
    node *old, *temp;
    temp = p;
    while(temp != NULL){
        if(temp -> data == num){
            if(temp ==p){
                p=temp -> link;
            }else{
                old -> link = temp -> link;
            }
            delete temp;
            return;
        }else{
            old = temp;
            temp = temp -> link;
        }
    }
    cout << "\n\nElement " << num << " not found\n";
}

linklist::~linklist(){
    node *q;
    while(p!=NULL){
        q = p -> link;
        delete p;
        p = q;
    }
}

int main(){
    linklist l;
    int choice, num, pos;
    while(true){
        cout << "Append - 1, AddAtBeg - 2, AddAfter - 3, Display - 4, Delete - 5, Count -6, Exit - 7 : ";
        cin >> choice;
        if(choice == 1){
            cout << "Enter the number : ";
            cin >> num;
            l.append(num);
        }else if(choice == 2){
            cout << "Enter the number : ";
            cin >> num;
            l.addatbeg(num);
        }else if(choice == 3){
            cout << "Enter the number : ";
            cin >> num;
            cout << "Enter the position : ";
            cin >> pos;
            l.addafter(pos,num);
        }else if(choice == 4){
            l.display();
        }else if(choice == 5){
            cout << "Enter the number : ";
            cin >> num;
            l.del(num);
        }else if(choice == 6){
            cout << "Number of elements are : " << l.count() << "\n";
        }else if(choice == 7){
            break;
        }else{
            cout << "Wrong Option\n";
        }
    }
    return 0;
}
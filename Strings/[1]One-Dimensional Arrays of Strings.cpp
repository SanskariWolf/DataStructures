#include<iostream>
using namespace std;

const int MAX=10;

class Hello{
    private:
        char str[MAX];

    public:
        string();
        string(char *s);
        int xstrlen();
        static void xstrcpy(string &t, string &s);
        static void xstrcat(string &t, string &s);
        static int xstrcmp(string &t, string &s);
        void show();
};

Hello::string(){}

Hello::string(char *s){

}

int Hello::xstrlen(){

}

int main(){

    return 0;
}
#include<iostream>
using namespace std;
class Stack{
public:
    int a[100];
    int top;
    Stack(){
        top=-1;
    }
    void push(int v){
        if(top==100-1){
            cout<<"\nStack is full";
            return;
        }
        a[++top]=v;

    }
    void pop(){
        if(top==-1){
            cout<<"\nStack is empty";
            return;
        }
        top--;
    }
    int peek(){
        if(top==-1){
            cout<<"\nStack is empty";
            return -99;
        }
        return a[top];
    }
    int isempty(){
        if(top==-1)
            return 1;
        else
            return 0;
    }
};
int main(){
    int n;
    cout<<"\nenter the number of elements : ";
    cin>>n;
    int e[n],neg[n];
    for (int i=0;i<n;i++) {
        cin>>e[i];
    }
    Stack s;
    for(int i=n-1;i>=0;i--){
        while(!s.isempty() && s.peek() <= e[i]) {
            s.pop();
        }
        if(s.isempty()) {
            neg[i] = -1;
        } else {
            neg[i] = s.peek();
        }
        s.push(e[i]);
    }

    for(int i=0;i<n;i++){
        cout<<neg[i]<<" ";
    }

}

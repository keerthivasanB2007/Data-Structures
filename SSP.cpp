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
    cout<<"enter the stock price size : ";
    cin>>n;
    Stack s;
    int stock[n];
    int r[n];
    cout<<"\nenter the stock price details ";
    for(int i=0;i<n;i++){
        cout<<"\nDay "<<i+1<<" : ";
        cin>>stock[i];
    }
    for(int i=0;i<n;i++){
          while(!s.isempty() &&  stock[s.peek()]<=stock[i]){
            s.pop();
          }
          if(s.isempty()){
            r[i]=1;
              s.push(i);
          }
          else{
             r[i]=i-s.peek();
              s.push(i);
          }

    }
    for (int i=0;i<n;i++) {
        cout<<r[i]<<" ";
    }
}
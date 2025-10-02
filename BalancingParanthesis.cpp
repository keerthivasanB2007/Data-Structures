#include <iostream>
using namespace std;
class Stack{
     char a[100];
     int top;
     public:
       Stack(){
         top=-1;
         }
         void push(char x){
           if(top==99) {
             //  cout<<"Stack is full";
             return;
           }
             a[++top]=x;
             }
             void pop(){
               if(top==-1){
            //     cout<<"Stack is empty"<<endl;
                 return;
                 }
                 top=top-1;
                 }
                 int peek(){
                   if(top==-1){
                  //   cout<<"Stack is empty"<<endl;
                     return -1;
                   }
                   return a[top];
           }
           };
           bool isbalanced(string s){
             Stack st;
             for(char c: s){
                   if(c=='(' || c=='{' || c=='['){
                     st.push(c);
                   }
                   else if(c==')' || c=='}' || c==']'){
                     char ct=st.peek();
                     if(ct=='(' && c==')' || ct=='{' && c=='}' || ct=='[' && c==']'){
                       st.pop();
                     }
                     else {
                       return false;
                     }
                   }
                   }
                   if(st.peek()==-1)
                     return true;
                   else
                     return false;
                   }
           int main(){
             string s;
             cout<<"Enter the String:";
             cin>>s;
             if(isbalanced(s)){
               cout<<"\nBalanced";
               }
               else{
                 cout<<"\nNot Balanced";
                 }
                 }



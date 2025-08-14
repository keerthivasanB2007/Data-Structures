#include<iostream>
using namespace std;
class stack{
    char b[1000];
      int top;
public:
    stack(){
     top=-1;
 } 
 void push(char a){
         if(top<(1000-1)){
              top=top+1;
             b[top]=a;
}
}
void pop(){
          if(top>=0){
              top=top-1;
  }
}
 char peek(){
      return b[top];
}
 int rtop(){
 return top;
}
};
int main(){
     string s;
    stack brk;
        cout<<"enter list of brackets like this '{()[]}':";
            cin>>s;
         for(int i=0;i<=s.length();i++){
              if(s[i]=='{' || s[i]=='(' || s[i]=='['){
                       brk.push(s[i]);
               }
                 if(s[i]=='}' || s[i]==')' || s[i]==']'){
                         if((brk.peek()=='{' && s[i]=='}') ||(brk.peek()=='(' && s[i]==')') || (brk.peek()=='[' && s[i]==']')  ){
                              brk.pop();
       }
}
}
if(brk.rtop()==-1)
     cout<<"\nstring is balanced";
else 
     cout<<"\nstring is not balanced";
}
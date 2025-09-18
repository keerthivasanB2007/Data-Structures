#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
class stack{
    public:
    string data;
    stack *top;
    stack(string v){
        data=v;
        top=nullptr;
    }
};
stack *head=nullptr;
void push(stack *&head,string v){
    stack *newnode=new stack(v);
        newnode->top=head;
        head=newnode;
}
void pop(stack *&head){
        stack *temp=head;
         head=temp->top;
         delete temp;
}
string peek(stack *head){
    if(head==nullptr)
       return "";
    return head->data;
}
bool isempty(stack *head){
    return head==nullptr;
}
bool isoperator(string s){
    return (s=="+" || s=="-" || s=="*" || s=="/" || s=="^");
}
bool isnum(string l){
    for(char s : l){
   if(!isdigit(s))
      return false;
    }
    return true;
}
vector<string> tokenize(string s){
    vector<string> token;
    string num="";
    for(int i=0;i<s.size();){
        if(isdigit(s[i])){
        while(isdigit(s[i])){
           num+=s[i];
           i++;
        }
        token.push_back(num);
        num="";
    }
       else if(isoperator(string(1,s[i]))){
           token.push_back(string(1,s[i]));
           i++;
        }
        else if(s[i]==' '){
            i++;
        }
        else if(s[i]=='(' || s[i]==')'){
            token.push_back(string(1,s[i]));
            i++;
        }
        else{
            i++;
        }
    }
    return token;
}
int precedence(string s){
    if(s=="*" || s=="/")
        return 2;
    if(s=="+" || s=="-")
        return 1;
    if(s=="^")
    return 3;
  return 0;
}
//to postfix converter
vector<string> topostfix(vector<string> s){
    vector<string> postfix;
    for(string i : s){
        if(isnum(i)){
            postfix.push_back(i);
        }
        else if(isoperator(i)){
            while(!isempty(head) && isoperator(peek(head)) &&  precedence(i) < precedence(peek(head))){
                postfix.push_back(peek(head));
                pop(head);
            }
            push(head,i);
        }
        else if(i=="(")
            push(head,i);
        else if(i==")"){
            while(!isempty(head) && peek(head)!="("){
                postfix.push_back(peek(head));
                pop(head);
            }
            if(peek(head) == "(")
                pop(head);
        }
    }
    while(!isempty(head)){
        postfix.push_back(peek(head));
        pop(head);
    }
    return postfix;

}
void  postfixeval(vector<string> s){
     vector<int> result;
    for(string f : s){
        if(isdigit(f[0])){
            result.push_back(stoi(f));
        }
        else if(isoperator(f)){
            int res=0;
            int a=result.back();
            result.pop_back();
            int b=result.back();
            result.pop_back();
            if(f=="+")
                 res=a+b;
            else if(f=="-")
                res=a-b;
            else if(f=="*")
                 res=a*b;
            else if(f=="/")
                res=a/b;
            else if(f=="^") 
               res=pow(a,b); 
            result.push_back(res);              
        }
    }
    cout<<"\nFinal computed value is  "<<result.back();
}
int main(){
    string s;
    cout<<"\nenter the infix expression : ";
    getline(cin,s);
    cout<<"\npostfix expression : ";
    vector<string> token=tokenize(s);
    vector<string> postfix=topostfix(token);
    for(string f : postfix)
        cout<<f<<" ";
    postfixeval(postfix);
}

#include<iostream>
using namespace std;
class stack{
    public:
    int data;
    stack *top;
    stack(int v){
        data=v;
        top=nullptr;
    }
};
void push(stack *&head,int v){
    stack *newnode=new stack(v);
        newnode->top=head;
        head=newnode;
}
void pop(stack *&head){
    if(head==nullptr){
        cout<<"\nstack is emply";
    }
    else{
        stack *temp=head;
         head=temp->top;
         delete temp;
    }
}
void display(stack *head){
    stack *temp=head;
    if(head==nullptr){
        cout<<"\nStack is empty";
    }
    else{
        while(temp!=nullptr){
            cout<<temp->data<<" -> ";
            temp=temp->top;
        }
        cout<<"NULL";
    }
}
int main(){
    stack *head=nullptr;
    int choice,value;
    do{
        cout<<"\nmenu:";
        cout<<"\n1.Push";
        cout<<"\n2.Pop";
        cout<<"\n3.display";
        cout<<"\n4.exit";
        cout<<"\neneter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"\nEnter the element to push : ";
            cin>>value;
            push(head,value);
            break;
            case 2:
            cout<<"\nDeleting the top";
            pop(head);
            break;
            case 3:
            cout<<"\nContenet in the stack : ";
            display(head);
            break;
            case 4:
            cout<<"\nexiting.....";
            break;
            default:
            cout<<"\nInvalid choice";
        }
    }while(choice!=4);
}
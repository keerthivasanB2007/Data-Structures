#include<iostream>
using namespace std;
class queue{
    public:
    int data;
    queue *next;
    queue(int v){
        data=v;
        next =nullptr;
    }
};
void enqueue(queue *&head,queue *&tail,int v){
    queue *newnode=new queue(v);
    if(head==nullptr && tail == nullptr){
        head=newnode;
        tail=newnode;
    }
    else{
        tail->next=newnode;
        tail=newnode;
    }
}
void dequeue(queue *&head,queue *&tail){
        if(head==nullptr){
            cout<<"\nQueue is empty";
           return;
        }
            queue *temp=head;
        head=temp->next;
        if(head==nullptr){
            tail=nullptr;
        }
        delete temp;
}
void display(queue *head,queue *tail){
    if(head==nullptr){
        cout<<"\nQueue is empty";
        return;
    }
        queue *temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL";
    }
    
    int main(){
        queue *head=nullptr;
        queue *tail=nullptr;
        int choice,v;
        do{
            cout<<"\nmenu:";
            cout<<"\n1.Enqueue";
            cout<<"\n2.Dequeue";
            cout<<"\n3.Display";
            cout<<"\n4.Exit";
            cout<<"\nenter your choice : ";
            cin>>choice;
            switch(choice){
                case 1:
                cout<<"\nenter value to enqueue : ";
                cin>>v;
                enqueue(head,tail,v);
                break;
                case 2:
                cout<<"\nDequeued";
                dequeue(head,tail);
                break;
                case 3:
                cout<<"\ncontent in the Queue : ";
                display(head,tail);
                break;
                case 4:
                cout<<"\nExiting...";
                break;
                default:
                cout<<"\n!Invalid choice";
            }
        }while(choice!=4);
    }
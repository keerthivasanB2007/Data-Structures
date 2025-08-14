#include <iostream>
using namespace std;
int count = -1;
class node {
public:
    int data;
    node *next;
    node(int val) {
        data = val;
        next = nullptr;
        count++;
    }
    node() {
        next = nullptr;
    }
};
void insertatend(node *head, int val) {
    node *newnode = new node(val);
    node *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newnode;
}
void insertatbegin(node *head, int val) {
    if (head->next == nullptr) {
        insertatend(head, val);
    } else {
        node *newnode = new node(val);
        newnode->next = head->next;
        head->next = newnode;
    }
}
void insertatpos(node *head, int val, int p) {
    if (p == 1) {
        insertatbegin(head, val);
        return;
    }
    if (p > count) {
        insertatend(head, val);
        return;
    }
    node *newnode = new node(val);
    node *temp = head;
    for (int i = 1; i < p; i++) {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void display(node *head) {
    node *temp = head->next;
    int i = 1;
    while (temp != nullptr) {
        cout << "\nNode " << i << ": " << temp->data;
        temp = temp->next;
        i++;
    }
}
void deleteatbegin(node *head) {
    if (head->next == nullptr)
        return;

    if (head->next->next == nullptr) {
        delete head->next;
        head->next = nullptr;
        return;
    }
    node *temp = head->next;
    head->next = temp->next;
    delete temp;
    count--;
}
void deleteatend(node *head) {
    if (head->next == nullptr)
        return;
    if (head->next->next == nullptr) {
        delete head->next;
        head->next = nullptr;
        return;
    }
    node *temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    node *t = temp->next;
    temp->next = nullptr;
    delete t;
    count--;
}
void deleteatpos(node *head, int p) {
    if (p == 1) {
        deleteatbegin(head);
        return;
    }
    if (p > count) {
        deleteatend(head);
        return;
    }
    node *temp = head;
    for (int i = 1; i < p; i++) {
        temp = temp->next;
    }
    node *t = temp->next;
    temp->next = t->next;
    delete t;
    count--;
}
void deletebyvalue(node *head,int v){
    node *temp=head->next;
    bool flag=false;
    node *prev=head;
    while(temp->next != nullptr){
        if(temp->data== v){
            flag=true;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    if(flag){
        prev->next=temp->next;
        delete temp;
    }
    else{
        cout<<"User entered value is not in the linked list";
    }
}
int main(){
    node *head = new node();  
    int choice,v,p;
    do{
        cout<<"Menu:\n";
        cout<<"1.Insert at begining\n";
        cout<<"2.Insert at end\n";
        cout<<"3.Insert at position\n";
        cout<<"4.Delete at begining\n";
        cout<<"5.Delete at end\n";
        cout<<"6.Delete at give postion\n";
        cout<<"7.Delete by value\n";
        cout<<"8.Displat\n";
        cout<<"9.Exiting....";
        cout<<"\nenter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"\nenter the value to insert at begining : ";
            cin>>v;
            insertatbegin(head,v);
            break;
            case 2:
            cout<<"\nenter the value to insert at end : ";
            cin>>v;
            insertatend(head,v);
            break;
            case 3:
            cout<<"\nenter the position to Insert element : ";
            cin>>p;
            cout<<"\nenter value to insert : ";
            cin>>v;
            insertatpos(head,v,p);
            break;
            case 4:
            cout<<"\nDeletion at begining";
            deleteatbegin(head);
            break;
            case 5:
            cout<<"\nDeletion at end ";
            deleteatend(head);
            break;
            case 6:
            cout<<"\nenter the postion to delete : ";
            cin>>p;
            deleteatpos(head,p);
            break;
            case 7:
            cout<<"\nenter the value to delete : ";
            cin>>v;
            deletebyvalue(head,v);
            break;
            case 8:
            cout<<"\ndata in the linked list\n";
            display(head);
            break;
            case 9:
            cout<<"Exiting.....";
            break;
            default:
            cout<<"!Invalid choice"; 

        }
    }while(choice!=9);
    
}
#include<iostream>
using namespace std;

int count = 0;

class node {
public:
    int data;
    node* next;
    node* prev;
    node(int v) {
        next = nullptr;
        prev = nullptr;
        data = v;
        count++;
    }
    node() {
        next = nullptr;
        prev = nullptr;
    }
};

void insertatbegin(node* head, node*& tail, int v) {
    node* temp = head;
    node* newnode = new node(v);
    if (temp->next == nullptr) {
        temp->next = newnode;
        newnode->prev = temp;
        tail = newnode;
        return;
    }
    node* t = temp->next;
    newnode->next = t;
    t->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
}
void insertatend(node* head, node* tail, int v) {
    if (head->next == nullptr) {
        insertatbegin(head, tail, v);
        return;
    }
    node* newnode = new node(v);
    if (tail->next == nullptr) {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}
void insertatpos(node* head, node*& tail, int p, int v) {
    if (p == 1) {
        insertatbegin(head, tail, v);
        return;
    }
    if (p == count) {
        node* t = tail->prev;
        node* newnode = new node(v);
        t->next = newnode;
        newnode->prev = t;
        newnode->next = tail;
        tail->prev = newnode;
        return;
    }
    if (p == count + 1) {
        insertatend(head, tail, v);
        return;
    }
    if (p > count || p <= 0) {
        cout << "\ngiven position is outoff bound";
        return;
    }
    node* temp = head->next;
    p = p - 2;
    node* newnode = new node(v);
    while (p != 0) {
        temp = temp->next;
        p--;
    }
    node* t = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = t;
    t->prev = newnode;
}
void display(node* head) {
    node* temp = head->next;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}
void deleteatbegin(node* head) {
    if (head->next == nullptr) {
        cout << "\nempty list";
        return;
    }
    node* temp = head->next;
    head->next = temp->next;
    if (temp->next != nullptr) {
        temp->next->prev = head;
    }
    delete temp;
    count--;
}
void deleteatend(node*& tail) {
    if (tail == nullptr) {
        cout << "\nempty list";
        return;
    }
    node* temp = tail;
    if (tail->prev == nullptr) {
        tail = nullptr;
    }
    else {
        tail = temp->prev;
        tail->next = nullptr;
    }
    delete temp;
    count--;
}
void deleteatpos(node* head, node* tail, int p) {
    if (p == 1) {
        deleteatbegin(head);
        return;
    }
    if (p == count) {
        deleteatend(tail);
        return;
    }
    if (p > count) {
        cout << "\ngiven position is out of bound";
        return;
    }
    p = p - 1;
    node* temp = head->next;
    while (p != 0) {
        temp = temp->next;
        p--;
    }
    node* t = temp;
    temp = temp->prev;
    temp->next = t->next;
    if (t->next != nullptr) {
        t->next->prev = temp;
    }
    delete t;
    count--;
}

int main() {
    node* head = new node();
    node* tail = nullptr;
    int choice, v, p;
    do {
        cout << "\nmenu:\n";
        cout << "1.insert at begin\n";
        cout << "2.insert at end\n";
        cout << "3.insert at postion\n";
        cout << "4.delete at begin\n";
        cout << "5.delete at end\n";
        cout << "6.delete at positon\n";
        cout << "7.display\n";
        cout << "8.exit..\n";
        cout << "\nenter your choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "\nenter the value to insert :";
            cin >> v;
            insertatbegin(head, tail, v);
            break;
        case 2:
            cout << "\nenter the vlaue to insert :";
            cin >> v;
            insertatend(head, tail, v);
            break;
        case 3:
            cout << "\nenter the position to insert :";
            cin >> p;
            cout << "\nenter the value to insert :";
            cin >> v;
            insertatpos(head, tail, p, v);
            break;
        case 4:
            cout << "\ndelete at begining";
            deleteatbegin(head);
            break;
        case 5:
            cout << "\ndelete at end";
            deleteatend(tail);
            break;
        case 6:
            cout << "\nenter the positon to delete : ";
            cin >> p;
            deleteatpos(head, tail, p);
            break;
        case 7:
            cout << "\ncontenet in the list : ";
            display(head);
            break;
        case 8:
            cout << "\nExitint...";
            break;
        default:
            cout << "\nInvalid choice";
        }
    } while (choice != 8);
}

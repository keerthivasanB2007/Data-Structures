#include<iostream>
using namespace std;
const int SIZE=6;
class queue{
    int a[SIZE];
    int f,r;
public:
    queue(){
        f=-1;
        r=-1;
    }
    void enqueue(int v){
        if(f==-1)
            f++;
        if(r==SIZE-1){
            cout<<"queue is full";
        }


        else
            a[r++]=v;
    }
    void dequeue(){
        if(f==-1 || f>r){
            cout<<"\nqueue is empty";
        }
        else{
            cout<<"enqueued element:"<<a[f++];


        }
    }
    void display(){
        cout<<"\nelements in the queue\n";
        for(int i=f;i<=r;i++){
            cout<<a[i];
        }
    }
};
int main(){
    cout<<"queue based program";
    queue q;
    for(int i=0;i<SIZE;i++)
        q.enqueue(i*10);
    q.display();
    q.dequeue();
    q.display();
}
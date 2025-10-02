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
int fit(int height[],int n){
    int nsl[n],nsr[n];
    Stack s;
    for(int i=0;i<n;i++){
        while(!s.isempty() && height[s.peek()]>=height[i])
                   s.pop();
        if(s.isempty())
             nsl[i]=-1;
        else
              nsl[i]=s.peek();
        s.push(i);
    }
    Stack c;
     for(int i=n-1;i>=0;i--){
        while(!c.isempty() && height[c.peek()]>=height[i])
                   c.pop();
        if(c.isempty())
             nsr[i]=n;
        else
              nsr[i]=c.peek();
        c.push(i);
    }
    int max=0;
    for(int i=0;i<n;i++){
        int width=nsr[i]-nsl[i]-1;
        int area=height[i]*width;
        if(max<=area)
            max=area;
    }
    return max;

}
int main(){
    int n;
    cout<<"\nenter no. bars in histogram : ";
    cin>>n;
    cout<<"\nEnter the heights of the bars in the Histogram";
    int height[n];
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    cout<<"\nMax Size of the Rectangle that can be fit into the Histogram chart is "<<fit(height,n);
}
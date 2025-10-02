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
int trap(int height[],int n){
    Stack s;
    int water=0;
    for(int i=0;i<n;i++){
      while(!s.isempty() && height[s.peek()]<height[i]){
        int pre=s.peek();
          s.pop();
          if (s.isempty())
              break;
        int width=i-s.peek()-1;

        int m=min(height[s.peek()],height[i])-height[pre];
        water+=m*width;
    }
    if(!s.isempty() && height[s.peek()]>height[i])
        s.push(i);
    else
            s.push(i);
   }
   return water;
   }
int main(){
  int n;
  cout<<"enter no. of bars : ";
  cin>>n;
  int height[n];
  cout<<"\nenter the heights of the bars : ";
  for(int i=0;i<n;i++){
    cin>>height[i];
  }
  cout<<"\nMax Unit of Water that can Trap : "<<trap(height,n);
  }
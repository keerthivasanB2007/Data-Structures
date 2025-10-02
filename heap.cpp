#include<iostream>
using namespace std;
int count=0;
int m;
void deletemin(int h[]){
	if(count<=0){
	  cout<<"\n!! Heap is empty !!";
	  return;
	   }
   int i=1;
   int last=h[count];
   while(i*2<=count){
    int child=2*i;
    if(child+1<=count && h[child+1]>h[child]){
      child++;
    }
    if(h[child]>=last){
      break;
    }
     h[i]=h[child];
     i=child;
   }
   h[count]=last;
   }
    int search(int h[],int key) {
	   for(int i=1;i<=count;i++) {
		   if(h[i]==key) {
			   return i;
		   }
	   }
	return -1;
}
       void inspriority(int h[],int key,int priority) {
	int i=search(h,key);
	  if (i==-1) {
	  	cout<<"\nKey element is not found";
        return;
	  }
      if(priority>key){
            cout<<"\nTo increse the priority (priority < key )";
             return;
       }
    while(i>1 && priority<h[i/2]) {
           h[i]=h[i/2];
          i=i/2;
       }
      h[i]=priority;
}
void decpriority(int h[],int key,int priority) {
      int i=search(h,key);
       if(i==-1) {
cout<<"\nKey element is not found";
return;
}
     if(priority<key){
          cout<<"\nTo decrement the priority (priority > key )";
           return;
         }
       while(i*2<=count){
    int child=2*i;
    if(child+1<=count && h[child+1]<h[child]){
      child++;
    }
    if(h[child]>=priority){
      break;
    }
     h[i]=h[child];
     i=child;
   }
   h[i]=priority;
}


    
void insert(int h[],int v){

	if(count==m){
	cout<<"!! Heap is full !!";
	return;
	}
	 
	int i=count+1;
	while(h[i/2] > v){
	     h[i]=h[i/2];
	     i=i/2;
	     }
	     h[i]=v;
	     count++;
	     }
 void display(int h[]){
     if(count<=0){
       cout<<"\n!! Heap is empty !!";
       return;
       }
    for(int i=1;i<=count;i++)
      cout<<h[i]<<" ";
     }
int main(){
int n;
cout<<"enter the no. of elements in the priority queue : ";
cin>>n;
m=n;
int h[n+1];
h[0]=-9999;
int choice, v,priority;
    do{
    	int m;
 	cout<<"\nmenu:";
 	cout<<"\n1.Insert";
    	cout<<"\n2.Enter Series of values to insert";
 	cout<<"\n3.Delete";
 	cout<<"\n4.display";
    	cout<<"\n5.Increase priority";
    cout<<"\n6.Decrease priority";
 	cout<<"\n7.Exit";
 	cout<<"\nenter your choice : ";
 	cin>>choice;
     switch(choice){
  	case 1:
 	cout<<"\nEnter value to insert : ";
 	cin>>v;
      insert(h,v);
      break;
     	case 2:
     		cout<<"\nEnter no. of value you want to enter Range(1 to "<<n<<") : ";
     	     cin>>m;
     	    cout<<"\nEnter values to insert : ";
     	     while (m>0) {
	     	     cin>>v;
     	     	insert(h,v);
     	     	m--;
     	     }
     	break;
      case 3:
          cout<<"\nDeleting the Minimum element";
          deletemin(h);
          break;
      case 4:
          cout<<"\nElements in the priority Queue : ";
          display(h);
          break;
     	case 5:
     		display(h);
     	  cout<<"\nDo you want to increase which element priority : ";
     	  cin>>v;
     	  cout<<"\n--To Increase the priority Decrease the value--";
     	   cout<<"\nenter the priority : ";
     	  cin>>priority;
     	inspriority(h,v,priority);
        break;
       case 6:
          display(h);
          cout<<"\nDo you want to decrease which element priority : ";
          cin>>v;
          cout<<"\n--to Decrease the priority Increase the Value--";
          cout<<"\nenter the priority : ";
          cin>>priority;
            decpriority(h,v,priority);
     break;

      case 7:
         cout<<"\nExiting....";
         break;
      default:
         cout<<"\nInvalid choice";
         break;
     }
     }while(choice!=7);
 }   
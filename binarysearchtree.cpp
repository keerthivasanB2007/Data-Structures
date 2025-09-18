 #include<iostream>
 using namespace std;
 class tree {
 public:
     int data;
     tree* left;
     tree* right;
    tree(int v){
        data=v;
        left=nullptr;
        right=nullptr;
    }
 };
 void insert(tree* &node,int v){
     if(node==nullptr){
           node=new tree(v);
           return;
     }
     if(v < node->data){
        insert(node->left,v);
     }
     if(v>node->data){
        insert(node->right,v);
     }
}
void inorder(tree* node){
    if(node!=nullptr){
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }
   
}
void postorder(tree* node){
       
    if(node!=nullptr){
        postorder(node->left);
        postorder(node->right);
        cout<<node->data<<" ";
    }

}
void preorder(tree* node){
           
    if(node!=nullptr){
        cout<<node->data<<" ";
        preorder(node->left);
        preorder(node->right);
    }
   
}
tree* minimum(tree *node){
    if(node==nullptr)
      return nullptr;
    if(node->left==nullptr)
       return node;
   return minimum(node->left);
}
tree* maximum(tree *node){
    if(node==nullptr)
      return nullptr;
    if(node->right==nullptr)
       return node;
   return maximum(node->right);
}
tree* del(tree *node,int v){
        /*if(node==nullptr){
             cout<<"\nTree is Empty!!!";
             return;
             }
             if(!node->right && !node->left){
             cout<<"yes this condition is working";
             //delete node;
              node=nullptr;
              return;
              }
        tree *temp=node;
        tree *t=nullptr;
        int flag=0;
        while(1){
               if(temp->data==v){
               flag=1;
                break;
                }
               if(temp->data > v){
                      t=temp;
                     temp=temp->left;
                     }
               else if(temp->data < v){
                     t=temp;
                     temp=temp->right;
             }
             }
       if(flag==0){
       cout<<"\nTree not contain the given value";
       return;
       }
       else{
       if(!temp->left && !temp->right){
       
             if(t->left->data == v){
                  delete t->left;
                  t->left=nullptr;
                  return;
                  }
             else{
             delete t->right;
             t->right=nullptr;
             return;
                 }
             }
             if(!temp->left && temp->right || temp->left && !temp->right){
                if(!temp->left){
                t->right=temp->right;
                delete temp;
                temp=nullptr;
                return;
                      }
                 else{
                 t->left=temp->left;
                 delete temp;
                 temp=nullptr;
                 return;
                 }
            }
            if(temp->left && temp->right){
                  int d=minimum(temp->right)->data;
                  cout<<"minimum: "<<d;
                  del(node,d);
                  temp->data=d;
                  return;
           }
            }
           */
       
        if(node==nullptr)
          return node;
        if(node->data > v)
           node->left=del(node->left,v);
        else if(node->data < v)
           node->right=del(node->right,v);
        else{
            if(!node->left && !node->right){
                delete node;
                return nullptr;
            }
            else if(!node->left){
                tree *t=node->right;
                delete node;
                return t;
            }
            else if(!node->right){
                tree *t=node->left;
                delete node;
                return t;
            }
            else{
                tree *t=minimum(node->right);
                node->data=t->data;
                node->right=del(node->right,t->data);
            }
        }
        return node;
       }    
           

 int main(){
    tree* node=nullptr;
    int choice,v,n;
    cout<<"-------------Implementation of Binary Search Tree-----------------";
    do{
        cout<<"\nMenu:";
        cout<<"\n1.Insert";
        cout<<"\n2.Enter Array of elements to insert";
        cout<<"\n3.Inorder";
        cout<<"\n4.Postorder";
        cout<<"\n5.Preorder";
        cout<<"\n6.Minimum";
        cout<<"\n7.Maximum";
        cout<<"\n8.Delete";
        cout<<"\n9.Exit";
        cout<<"\nEnter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"enter element to insert : ";
            cin>>v;
            insert(node,v);
            break;
            case 2:
             cout<<"\nenter no. of element to insert : ";
             cin>>n;
             cout<<"\nEnter elements\n";
             for(int i=0;i<n;i++){
                  cin>>v;
                  insert(node,v);
                 
              }
              break;
            case 3:
            cout<<"\nInorder(Left - Root - Right) : ";
            inorder(node);
            break;
            case 4:
            cout<<"\nPostorder(Left - Right - Root) : ";
            postorder(node);
            break;
            case 5:
            cout<<"\nPreorder(Left - Root - Right) : ";
            preorder(node);
            break;
            case 6:
            cout<<"\nminimum element in the Tree : "<<minimum(node)->data;
            break;
            case 7:
              cout<<"\nMaximum element in the Tree : "<<maximum(node)->data;
              break;
            case 8:
              cout<<"\nenter the value you want to delete : ";
               cin>>v;
              node=del(node,v);
               break;
            case 9:
            cout<<"\nExiting...";
            break;
            default:
            cout<<"\nInvalid Choice";
        }
    }while(choice!=9);
 }
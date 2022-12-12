#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node* left,*right;
        
        node(){
            data=0;
            right=NULL;
            left=NULL;
        }
};
class trees{
    private: node* root=NULL;
    public:
    void insert(int data){
        node* temp=root;
        node* newnode=new node;
        newnode->data=data;
        if(root==NULL){
            root=newnode;
        }
        else{
            while(temp->data!=data){

                if(data< temp->data){
                    if(temp->left==NULL){
                        temp->left=newnode;
                        temp=newnode;
                    }
                    else{
                        temp=temp->left;
                    }
                }
                else{
                    if(temp->right==NULL){
                        temp->right=newnode;
                        temp=newnode;
                    }
                    else{
                        temp=temp->right;
                    }
                }
            }
        }
    }
    void search(int data){
        
    }

    void display(){
        int ch;
        do{
            cout<<"\n1:to preorder\n2:to inorder\n3:to postorder\n";
            cin>>ch;
            switch(ch){
                case 1:
                        preorder(root);
                        break;
                case 2:
                        inorder(root);
                        break;
                case 3:
                        postorder(root);
                        break;                
            }
        }
        while(ch!=0);
    }
    void preorder(node* root){
        if(root!=NULL){
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    void inorder(node * root){
        if(root!=NULL){
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }

    void postorder(node * root){
        if(root!=NULL){
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<" ";
        }
    }

   
};
int main(){
    int x,ch;
    trees s;
    do{
        int data;
        cout<<"\n0:to exit\n1:to insert\n2:to search\n3:to display\n";
        cin>>ch;
        switch(ch){
            case 1:
                    cout<<"enter the data to enter:\n";
                    cin>>data;
                    s.insert(data);
                    break;
            case 2:
                    cout<<"enter the element to search";
                    cin>>x;
                    s.search(x);
                    break;
            case 3:
                    s.display();
                    break;                
        }
    }
    while(ch!=0);
    
}
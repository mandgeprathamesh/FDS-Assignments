#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

};
class queue{
    private:
        node *front,*rear;
    public:
    queue(){
        rear=front=NULL;
    }
    void enqueue(){
        node* newnode=new node;
        int x;
        cout<<"enter the data:\n";
        cin>>x;
        newnode->data=x;
        newnode->next=NULL;
        if(front==NULL){
            front=rear=newnode;
        }
        else{
            rear->next=newnode;
            rear=newnode;
        }
        rear=newnode;
    }
    void dequeue(){
        node* newnode=new node;
        if(front==  NULL){
            cout<<"queue is empty\n";
        }
        else{
            node* temp=front;
            front=front->next;
            free(temp);
            cout<<"delted successfully\n";
        }
    }
    void display(){
        node* temp=front;
        if(temp==NULL){
            cout<<"queue is empty";
        }
        else{
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};
int main()
{
    queue s;
    int ch;
    while(1){
    cout<<"1:to enqueue\n2:to dequeue\n3:to display\n";
    cin>>ch;
    switch(ch){
        case 1:
                s.enqueue();
                break;
        case 2:
                s.dequeue();
                break;   
        case 3:
                s.display();
                break;          
    }
    }
    return 0;
}

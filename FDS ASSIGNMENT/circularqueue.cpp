#include<iostream>
using namespace std;
class circularqueue{
    private:
    int q[3];
    int front;
    int rear;
    int size;
    public:
    circularqueue(){
        rear=-1;
        front=-1;
        size=3;
    }
    void enqueue(){
        int x;
        cout<<"enter the value:\n";
        cin>>x;
        if(rear==-1){
            front++,rear++;
            q[rear]=x;
        }
        else if((rear+1)%size==front){
             cout<<"overflow\n";
        }
        else{
            rear=(rear+1)%size;
            q[rear]=x;
        }
    }

    void isempty(){
        if(front==-1){
            if(rear==-1){
                cout<<"queue is empty";
            }
        }
    }

    void isfull(){
        if(rear==size-1){
            cout<<"queue is full";
        }
    }

    void dequeue(){
        if(front==-1){
            cout<<"underflow\n";
        }
        else if(rear==front){
             cout<<"deleted:"<<q[front]<<endl;
             rear=front=-1;
        }
        else{
            cout<<"deleted successfully:\n"<<q[front]<<endl;
            front=(front+1)%size;
        }
    }
    void print(){
        if(front==-1){
            cout<<"queue is empty\n";
        }
        else{
            int i=front;
            while(1){
                cout<<q[i]<<" ";
                if(i==rear){
                    break;
                }
                i=(i+1)%size;
            }
        cout<<endl;
        }
    }

};
int main(){
    circularqueue s;
    int ch;
    while(1){
        cout<<"\n0:to exit\n1:to enqueue\n2:to dequeue\n3:to display the queue\n4:to check is queue full\n5:to check if queue is empty\n";
        cin>>ch;
        switch(ch){
            case 1:{
                    s.enqueue();
                    break;
                    }
            case 2:{
                    s.dequeue();
                    break;
                    }
            case 3:{
                    s.print();
                    break;
                    }
            case 4:{
                    s.isfull();
                    break;
                    }
            case 5:{
                    s.isempty();
                    break;
                    }                

        }
    }
}
#include<iostream>
using namespace std;

class Node{
   
    public:
     int info;
    Node *next;
    Node(int val){
        info = val;
        next = NULL;
    }
};

class Stack{
    int capacity,len;
    Node *top;

    public:
    Stack(int size){
        capacity = size;
        len=0;
        top = NULL;

    }
    // ~Stack(){
    //     delete []arr;
    // }
    bool isEmptyStack(){
        if(len) return false;
        else    return true;

    }
    bool isFullStack(){
    if(len==capacity) return true;
    else              return false;

    }   
    int topValue(){
        if(isEmptyStack()){
        cout<<"Stack is Empty"<<endl;
        return 0;
        }
        return top->info;
         
    }
    void push(int val){
        if(isFullStack()){
            cout<<"Stack is Full"<<endl;
            return;
        }
        Node *n = new Node(val);
        if(len)
        n->next=top;
        top = n;
        len++;
         
    }

    int pop(){
        if(isEmptyStack()){
            cout<<"Stack is Empty"<<endl;
            return 0;
        }
      
        Node *n = top;
        int data = n->info;
        top = top->next;
        delete n;
        len--; 
        return data;

    }
    void display(){
        if(isEmptyStack()){
            cout<<"Stack is Empty"<<endl;
            return;
        }
        else{
            Node *curr = top;
            while(curr){
                cout<<curr->info<<"--------";
                curr= curr->next;
            }
            cout<<endl;
        }


    }
    void reverse(Stack &s1){
        Stack s2(10);
            while(!isEmptyStack()){
                s2.push(pop());
            }
            s1 = s2;


    }


};

int main(int argc, char const *argv[])
{
    Stack s1(10),s2(10);

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.display();
    // cout<<s1.pop()<<endl;
    // s1.display();
    s1.reverse(s1);
    s1.display();


    
    return 0;
}

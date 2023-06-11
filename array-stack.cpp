#include<iostream>
using namespace std;

// updated

class Stack{
    int capacity,len,*arr;
    public:
    Stack(int size){
        arr = new int[size];
        capacity = size;
        len=0;

    }
    ~Stack(){
        delete []arr;
    }
    bool isEmptyStack(){
        if(len) return false;
        else    return true;

    }
    bool isFullStack(){
    if(len==capacity) return true;
    else              return false;

    }   
    int top(){
        if(isEmptyStack()){
        cout<<"Stack is Empty"<<endl;
        }
        else
        return arr[len];
         
    }
    void push(int val){
        if(isFullStack()){
            cout<<"Stack is Full"<<endl;
            return;
        }
        arr[len++] = val;
         
    }

    int pop(){
        if(isEmptyStack()){
            cout<<"Stack is Empty"<<endl;
            return 0;
        } 
        return arr[--len];
    }
    void display(){
        if(isEmptyStack()){
            cout<<"Stack is Empty"<<endl;
            return;
        }
        else{
            for (int i=len-1; i>=0; i--){
                cout<<arr[i]<<"-----";
            }
            cout<<endl;
        }


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
    s1.pop();
    s1.display();


    
    return 0;
}

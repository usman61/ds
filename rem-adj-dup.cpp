#include<iostream>
using namespace std;

class Node{
   
    public:
     char info;
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
    Stack(){
        len=0;
        top = NULL;

    }
    bool isEmptyStack(){
        if(len) return false;
        else    return true;

    }
    
    char topValue(){
        if(isEmptyStack()){
        cout<<"Stack is Empty"<<endl;
        return 0;
        }
        return top->info;
         
    }
    void push(char val){
        
        Node *n = new Node(val);
        if(len)
        n->next=top;
        top = n;
        len++;
         
    }

    char pop(){
        if(isEmptyStack()){
            cout<<"Stack is Empty"<<endl;
            return 0;
        }
      
        Node *n = top;
        char data = n->info;
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
                cout<<curr->info;
                curr= curr->next;
            }
            cout<<endl;
        }
    }
    void reverse(Stack &s1){
        Stack s2;
        while(!isEmptyStack()){
            s2.push(pop());
        }
        s1 = s2;
    }

    void removeAdjacentDuplicates(string str){
        int len = str.length();
        char ch,top;

        for (int i=0; i<len; i++){
                ch = str[i]; 
            
            if(isEmptyStack())
            push(ch);

            else{
                top = topValue();
                if(ch==top)
                pop();
                else
                push(ch);
            } 
                
            }


    }
    
};

int main(int argc, char const *argv[])
{
    string str="azxxzy";
    Stack s1,s2;
    s1.removeAdjacentDuplicates(str);
    s1.reverse(s1);

    s1.display();   

    
    return 0;
}

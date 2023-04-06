/*
Basic implementation of binary search tree
*/
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;
    Node(int v=0){
        data = v;
        left=right = NULL;
    }
};

class BST{
    public:
    Node *root;
    BST(){
        root=NULL;
    }
    Node* insert(Node *r,int val);
    void inOrderTraversal(Node *r);
     

};
int main(int argc, char const *argv[])
{
    BST t1;


    t1.insert((t1.root),8);
    t1.insert((t1.root),2);
    t1.insert((t1.root),12);

 
    cout<<"-----------------------"<<endl;
    t1.inOrderTraversal(t1.root);
    cout<<"-----------------------"<<endl;

    return 0;
}

Node* BST::insert(Node *r,int val){

    if(r==NULL){
        
        Node *temp = new Node(val);

        if(r==root){
        /*
        this would run when first node in tree is entered
        so assigning the root to the first node         
        */
           root = r = temp;   
        }
        return temp;
    }
    else{
        
        if(r->data== val){
            cout<<"Already Exist"<<endl;
            return r;  
        
        }
        else if(val<r->data)
        r->left = insert(r->left,val);
        else{
        r->right = insert(r->right,val);

        }
        
    return r;    
    }

}


void BST::inOrderTraversal(Node *temp){

    if(temp==NULL) return;

    inOrderTraversal(temp->left);
    cout<<temp->data<<endl;
    inOrderTraversal(temp->right);


}


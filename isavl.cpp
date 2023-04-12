/*
Basic implementation of binary search tree
*/
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;
    int height;
    Node(int v=0){
        data = v;
        left=right = NULL;
        height = 0;
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
    bool isAVL(Node *r);

    int height(Node* t)
    {
    return (t == NULL ? -1 : t->height);
    }
     

};
int main(int argc, char const *argv[])
{
    BST t1;


    t1.insert((t1.root),6);
    t1.insert((t1.root),5);
    t1.insert((t1.root),4);

 
    cout<<"-----------------------"<<endl;
    t1.inOrderTraversal(t1.root);
    cout<<"-----------------------"<<endl;

    cout<<t1.isAVL(t1.root)<<endl;

    return 0;
}
bool BST::isAVL(Node *r){
    int bf = height(r->left) - height(r->right);
            if (bf >1 || bf<-1)
            return false;
            else
            return true;


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
        
    r->height = max(height(r->left), height(r->right)) + 1;
    return r;    
    }

}


void BST::inOrderTraversal(Node *temp){

    if(temp==NULL) return;

    inOrderTraversal(temp->left);
    cout<<temp->data<<endl;
    inOrderTraversal(temp->right);


}


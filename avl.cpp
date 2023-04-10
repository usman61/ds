#include<iostream>
#include<string>
using namespace std;

struct Trunk
{
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};


// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
    if (p == NULL)
        return;

    showTrunks(p->prev);

    cout << p->str;
}



class Node
{
public:
int data;
Node* left;
Node* right;
int height;

Node(int data)
{
this->data = data;
left = right = NULL;
height = 0;
}
};

void printTree(Node *&root, Trunk *prev, bool isRight)
{
    if (root == NULL)
        return;
    
    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight)
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout<<root->data << endl;

    if(prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}


class AVLTree{

    public:
    Node *root;
    AVLTree(){
        root = NULL;
    }
    Node* insert(Node *r,int val);
    Node* inOrderTraversal( Node* r);

    int height(Node* t)
    {
    return (t == NULL ? -1 : t->height);
    }

};

int main()
{
    AVLTree t1;
    t1.insert(t1.root,15);
    t1.insert(t1.root,8);
    t1.insert(t1.root,12);
    t1.insert(t1.root,3);
    t1.insert(t1.root,17);
    t1.insert(t1.root,18);
    t1.inOrderTraversal(t1.root);
    cout<<endl;
   // printTree();
    printTree(t1.root, NULL, false);
    
    return 0;
}

Node* AVLTree::insert(Node *r,int val){

    if(r==NULL){
        Node *temp = new Node(val);

        if(r==root){
            root = r = temp;
        }
        return temp;
    }
    else{
        
        if(r->data== val){
            cout<<"Already Exist"<<endl;
        
        }
        else if(val<r->data)
        r->left = insert(r->left,val);
        else{
        r->right = insert(r->right,val);

        }
        
    return r;    
    }

}

Node* AVLTree::inOrderTraversal( Node* r){
     if (r == NULL)
        return NULL;
   
    
    inOrderTraversal(r->left);
    cout << " "<< r->data << ",";
    inOrderTraversal(r->right);    
    return NULL;
}

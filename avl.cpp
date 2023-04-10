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


class node
{
public:
int data;
node* left;
node* right;
int height;

node(int data)
{
this->data = data;
left = right = NULL;
height = 0;
}
};

void printTree(node *&root, Trunk *prev, bool isRight)
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
    node *root;
    AVLTree(){
        root = NULL;
    }
    node* insert(node *&r,int val);
    node* inOrderTraversal( node* r);
    // Rotation
    node* singleRightRotate(node* &t);
    node* singleLeftRotate(node* &t);
    node* doubleRightLeftRotate(node* &t);
    node* doubleLeftRightRotate(node* &t);

    int height(node* t)
    {
    return (t == NULL ? -1 : t->height);
    }

    
};

int main()
{
    AVLTree t1;
    t1.insert(t1.root,8);
    t1.insert(t1.root,10);
    t1.insert(t1.root,9);
    // t1.insert(t1.root,3);
    // t1.insert(t1.root,17);
    // t1.insert(t1.root,18);
    t1.inOrderTraversal(t1.root);
    cout<<endl;
   // printTree();
    printTree(t1.root, NULL, false);
    
    return 0;
}

node* AVLTree::singleRightRotate(node* &t)
{
node* u = t->left;
t->left = u->right;
u->right = t;
t->height = max(height(t->left), height(t->right)) + 1;
u->height = max(height(u->left), t->height) + 1;
return u;
}
node* AVLTree::singleLeftRotate(node* &t)
{
node* u = t->right;
t->right = u->left;
u->left = t;
t->height = max(height(t->left), height(t->right)) + 1;
u->height = max(height(u->right), t->height) + 1;
return u;
}
node* AVLTree::doubleRightLeftRotate(node* &t)
{
t->right = singleRightRotate(t->right);
return singleLeftRotate(t);
}
node* AVLTree::doubleLeftRightRotate(node* &t)
{
t->left = singleLeftRotate(t->left);
return singleRightRotate(t);
}

node* AVLTree::insert(node *&r,int val){

    if(r==NULL){
        node *temp = new node(val);
        r = temp;
    }
    else if(val<r->data){
            r->left = insert(r->left,val);
            int bf = height(r->left) - height(r->right);
            if (bf == 2)
            {
            if (val < r->left->data)
            r = singleRightRotate(r);
            else
            r = doubleLeftRightRotate(r);
            }
    }
    else if (val>r->data){
        r->right = insert(r->right,val);
        int bf = height(r->right) - height(r->left);
        if (bf == 2)
        {
        if (val > r->right->data)
        r = singleLeftRotate(r);
        else
        r = doubleRightLeftRotate(r);
        }

        }
    r->height = max(height(r->left), height(r->right)) + 1;
        
    return r;    
    }


node* AVLTree::inOrderTraversal( node* r){
     if (r == NULL)
        return NULL;
   
    
    inOrderTraversal(r->left);
    cout << " "<< r->data << ",";
    inOrderTraversal(r->right);    
    return NULL;
}

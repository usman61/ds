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
        int info;
        node *left;
        node *right;
        
    node(int val)
    {
        info = val;
        left = NULL;
        right = NULL;
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
    cout << root->info << endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}

node* insert(node *r,int val)
{
	node* root;

	if(r==NULL)
	{
		node *temp = new node(val);
		if(r==root)
		{
/*
this would run when first node in tree is entered
so assigning the root to the first node
*/
		root = r = temp;
		}
		return temp;

	}
		else
		{
			if(r->info== val){
			cout<<"Already Exist"<<endl;
			return r;
		}
		else if(val<r->info)
		r->left = insert(r->left,val);
		
		else
		{
			r->right = insert(r->right,val);
		}
		return r;
		}
}





//Tree traversels function start from here

void preOrder(node *n)
{
    if(n == NULL)
        return;
    
    cout<<n->info<<"\t";
    preOrder(n->left);
    preOrder(n->right);
}

void inOrder(node *n)
{
    if(n == NULL)
        return;

    inOrder(n->left);
    cout<<n->info<<"\t";
    inOrder(n->right);
}

void postOrder(node *n)
{
    if(n == NULL)
        return;
    
    postOrder(n->left);
    postOrder(n->right);
    cout<<n->info<<"\t";
}

// Finding Smallest

int findSmallest(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    
    while(root->left != NULL)
    {
        root = root->left;
    }
    
    return root->info;
}

// Counting Nodes
int countNodes(node* root)
{
    if (root == NULL) 
	{
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Find Value
node* search(node* root, int val)
{
    if(root == NULL || root->info == val)
        return root;

    if(val > root->info )
        return search(root->right, val);
        

    return search(root->left, val);
    

}



int main() 
{
    node *root = new node(5);
	insert((root),2);
	insert((root),7);
	insert((root),3);
	insert((root),9);
	insert((root),6);
	insert((root),1);
	insert((root),20);
    
	cout<<"------------    TREE  -----------"<<endl;
    printTree(root, NULL, false);
	cout<<"----------------------------------------------------------------------------------------------"<<endl;
    cout<<"PREORDER  = [      ";
    preOrder(root);
    cout<<"]"<<endl;
    cout<<"----------------------------------------------------------------------------------------------"<<endl;
    cout<<"INORDER   = [      ";
    inOrder(root);
    cout<<"]"<<endl;
    cout<<"----------------------------------------------------------------------------------------------"<<endl;
    cout<<"POSTORDER = [      ";
    postOrder(root);
    cout<<"]"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------"<<endl;
    
    cout<<"Smallest value : "<<findSmallest(root)<<endl;
    cout<<"-----------------------------------------------------------------------------------------------"<<endl;
    
    cout << "Total Nodes: " << countNodes(root) << endl;
    cout<<"-----------------------------------------------------------------------------------------------"<<endl;
    
    //Finding value
	int val = 7;
    root = search(root, val);
    if(root == NULL)
        cout<<"No Node exist with this value: "<<val<<endl;
    else
    {
        cout<<"Subtree with root node value "<<val<<":"<<endl;
        printTree(root, NULL, false);
    }
    cout<<"-----------------------------------------------------------------------------------------------"<<endl;
	
	int val1 = 43;
    root = search(root, val1);
    if(root == NULL)
        cout<<"No Node exist with this value: "<<val1<<endl;
    else
    {
        cout<<"Subtree with root Node value "<<val1<<":"<<endl;
        printTree(root, NULL, false);
    }
    cout<<"-----------------------------------------------------------------------------------------------"<<endl;


    return 0;
}



















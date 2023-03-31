#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node *prev;
        node *next;
        node(int val) {
            data = val;
            prev = NULL;
            next = NULL;    
        }   
};

class doublyLL {
    private:
        node *head;
        int len;
    public:
        doublyLL() {
            head = NULL;
            len = 0;    
        }
    
        void insertatpos(int val,int pos) {
            if(pos > len+1) {
                return;
            }
            node *n = new node(val);
            if(pos == 1) {
                n->next = head;
                if(head != NULL) {
                    head->prev = n;
                }
                head = n;
            } else {
                node *curr = head;
                for(int i = 1; i < pos-1; i++) {
                    curr = curr->next;
                }
                n->next = curr->next;
                n->prev = curr;
                if(curr->next != NULL) {
                    curr->next->prev = n;
                }
                curr->next = n;
            }
            len++;
        }
    
    void reorder() {
    if (len < 2) {
        return;
    }

    node* x = head;       //initizaling node as x keeping on head
    node* y = head;    //initizaling node y keepig on head
    // while (y != NULL && y->next != NULL) {  //incase of null
    //     x = x->next;
    //     y = y->next->next;
    // }

    node* second = x->next;
    x->next = NULL;

    node* prev = NULL;
    node* curr = second; // as it will point the next node
    while (curr != NULL) {
        node* next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    second = prev;

    node* first = head;
    while (first != NULL && second != NULL)
	 {
        node* first_next = first->next;
    
	    node* second_next = second->next;
    
	    first->next = second;
    
	    second->prev = first;
        second->next = first_next;
        if (first_next != NULL) 
		{
            first_next->prev = second;
        }
        first = first_next;
        second = second_next;
    }
}

    
        void print()
{
    node *curr = head;
    if (curr == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }

    while (curr!= NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

};

int main() {
    doublyLL l;
    l.insertatpos(1, 1);
    l.insertatpos(2, 2);
    l.insertatpos(3, 3);
    l.insertatpos(4, 4);
    l.insertatpos(5, 5);
    l.insertatpos(6, 6);
    
    // l.insertatpos(7, 7);
    // l.insertatpos(8, 8);
    // // l.insertatpos(7, 7);

    cout << "Insertion: ";
    l.print();

    l.reorder();

    cout << "Reorder : ";
    l.print();

    return 0;
}

#include <iostream>
using namespace std;
    
class Node{
    public:
    int info;   
    Node *next,*prev;
    Node(int val){
        info=val;
        next=NULL;
        prev=NULL;
    }
};

class DoublyLinkedList{
    int length;
    Node *head;
    public:
    DoublyLinkedList(){
        head=NULL;
        length=0;
    }

    void insert(int val,int pos);
    void remove(int pos);
    void display();
    void splitFromMiddle(DoublyLinkedList &l2,DoublyLinkedList &l3);
    void splitEvenOdd(DoublyLinkedList &l2,DoublyLinkedList &l3);
    
};

void DoublyLinkedList::splitEvenOdd(DoublyLinkedList &l2,DoublyLinkedList &l3){
    
    Node *curr = head;
        
    for (int i=0; i<length; i++){
        if(curr->info%2==0){
            if (l2.length==0)
                l2.length++;
            l2.insert(curr->info,l2.length);
            
        }
        else{

            if (l3.length==0)
                l3.length++;
            l3.insert(curr->info,l3.length);
        }
        curr = curr->next;
        }

    
  }
void DoublyLinkedList::splitFromMiddle(DoublyLinkedList &l2,DoublyLinkedList &l3){
    
    Node *curr = head;
    int split_size;

    l2.head = head;

    if(length%2==0){
        split_size = length/2;
        l2.length=split_size;
        l3.length=split_size;
    }
    else{
        split_size = (length/2)+1;

        l2.length=split_size;
        l3.length=split_size-1;
    }

    for (int i=1; i<split_size; i++)
        curr = curr->next;

    l3.head = curr->next;
    l3.head->prev = NULL;

    curr->next = NULL;
    // curr->prev = NULL;

  }
void DoublyLinkedList::remove(int pos){

     if(pos<1 || pos> length){
        cout<<"Invalid Position"<<endl;
        return;
    }
    Node *curr = head;

    if(pos==1){
        head=head->next;
        head->prev=NULL;
        delete curr;
    }
    else{
        Node *temp=NULL;
        for (int i=1; i<pos; i++){
            temp = curr;
            curr = curr->next;
        }

        temp->next=curr->next;
        if(curr->next!=NULL)
        curr->next->prev=temp;
        delete curr;


    }
    length--;


}
void DoublyLinkedList::display(){
    Node *curr = head;
    if(!length){
        cout<<"List is Empty"<<endl;
        return;
    }
    cout<<"---------------------------------"<<endl;
    while (curr!=NULL){
        cout<<curr->info<<"\t";
        curr = curr->next;
    }
    cout<<endl;
    cout<<"---------------------------------"<<endl;


}
void DoublyLinkedList::insert(int val,int pos){
    
    if (pos <1 || pos> length+1){
        cout<<"Invalid position."<<pos<<endl;
        return;
    }
    Node *n = new Node(val);

    if(pos==1){
        if(!head)
            head = n;
        else{
            n->next=head;
            head->prev=n;
            head=n;
        }
       
    }
    else{

        Node *curr = head;
        for (int i=1; i<(pos-1); i++)
        curr = curr->next;

        n->next=curr->next;
        n->prev=curr;
        
        if(curr->next!=NULL)
            curr->next->prev=n;
        curr->next=n;    

    }
    length++;



}

int main()
{
     DoublyLinkedList l1,l2,l3;
    l1.insert(1,1);
    l1.insert(2,2);
    l1.insert(3,3);
    
    l1.insert(4,4);
    l1.insert(5,5);
    l1.insert(6,6);
    l1.insert(7,7);
    l1.display();
    // l1.remove(1);
    // l1.display();
    l1.splitFromMiddle(l2,l3);
    
    // l1.splitEvenOdd(l2,l3);
    l2.display();
    l3.display();
    
    return 0;
}

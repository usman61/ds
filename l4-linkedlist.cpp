#include <iostream>
using namespace std;

class node{
    public:
    node *next;
    int info;
    node(int val){
        info = val;
        next = NULL;

    }
};

class LinkedList{
    private:
    
    int length;

    public:
    node *head;
    LinkedList(){
        head = NULL;
        length = 0;
    }

    void insertion(int value,int pos);
    void printing();
    void concatenate(LinkedList l1,LinkedList l2);
    void deletion(int pos);
    void last_to_front();
    void swapNodes(node *n1,node *n2);
    void copyList(LinkedList l1,LinkedList &l2);

};


int main(int argc, char const *argv[])
{
    LinkedList l1,l2;
    l1.insertion(5,1);
    l1.insertion(6,2);
    l1.insertion(7,3);
    l1.insertion(8,4);
    l1.insertion(9,5);
    l1.insertion(10,6);
    // l1.deletion(2);
    cout<<"L1 Content"<<endl;
    l1.printing();
    // l1.last_to_front();

    l1.copyList(l1,l2);  //l1.bst_print(bst1,bst2);

    cout<<"L2 Content"<<endl;
    l2.printing();

    // l1.swapNodes(l1.head->next,l1.head->next->next->next);
    // l1.printing();

    
    // l2.insertion(8,1);
    // l2.insertion(9,2);
    // l1.concatenate(l1,l2);
    // l1.printing();

    
    return 0;
}

void LinkedList::copyList(LinkedList l1,LinkedList &l2){
    node *temp=l1.head;
    int pos=1;
    // LinkedList l3;    //5,6,7,8,9,10 --->10,12,14
    while(temp!=NULL){
        // l3.insertion(temp->info,pos);

        l2.insertion(temp->info,pos);
        pos++;
        temp= temp->next;
    }
    // l2.printing();
    // l3.printing();
}


void LinkedList::swapNodes(node *n1,node *n2){
    if(n1==n2)
    return;

    node *prev1=NULL,*prev2=NULL;
    node *curr = head;

    while(curr!=NULL){
        if(curr->next==n1)
            prev1=curr;

        if(curr->next==n2)
            prev2=curr;
    
    curr=curr->next;
    }

    prev1->next=n2;
    prev2->next=n1;

    node *temp = n1->next;
    n1->next=n2->next;
    n2->next=temp;
    


}
void LinkedList::last_to_front(){
    node *temp = head;
    node *temp2;
    while(temp->next!=NULL){
        temp2= temp;
        temp = temp->next;
    }
   temp2->next=NULL;
   temp->next=head;
   head = temp; 

 }


void LinkedList::concatenate(LinkedList l1,LinkedList l2){
    node *temp=l1.head;
    while(temp->next!=NULL)
    temp= temp->next;

    temp->next=l2.head;

}

void LinkedList::insertion(int value,int pos){

    if(pos<1 || pos>length+1){
        cout<<"Invalid Position"<<endl;
        return;
    }
    node *n = new node(value);

    if(pos==1){
        //node would be inserted at the head
        n->next=head;
        head = n;
        length++;
    }
    else{
        node *curr = head;
        for(int i=1; i<(pos-1); i++){
            curr = curr->next;
        }
        n->next=curr->next;
        curr->next=n;
        length++;

    }

}
void LinkedList::printing(){
    node *n=head;
    cout<<"---------------------------------"<<endl;
    while(n!=NULL){
        cout<<n->info<<"--->";
        n=n->next;
    }
    cout<<endl;
    cout<<"---------------------------------"<<endl;
    
}

void LinkedList::deletion(int pos){
    if(pos<1 || pos> length){
        cout<<"Invalid Position"<<endl;
    }
    node *temp=head;

    if(pos==1){
        head=head->next;
        delete temp;
        length--;
        return ;

    }

    for(int i=1; i<(pos-1);i++){
        temp=temp->next;
    }
   
    node *del=temp->next;

    temp->next = temp->next->next;
    del->next=NULL;
    delete del;
    length--; 
}
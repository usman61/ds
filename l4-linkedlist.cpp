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
    node *head;
    int length;

    public:
    LinkedList(){
        head = NULL;
        length = 0;
    }

    void insertion(int value,int pos);
    void printing();
    void concatenate(LinkedList l1,LinkedList l2);
    void deletion(int pos);
    void last_to_front();

};

int main(int argc, char const *argv[])
{
    LinkedList l1,l2;
    l1.insertion(5,1);
    l1.insertion(6,2);
    l1.insertion(7,3);
    l1.insertion(8,4);
    // l1.deletion(2);
    l1.printing();
    l1.last_to_front();
    l1.printing();

    
    // l2.insertion(8,1);
    // l2.insertion(9,2);
    // l2.insertion(10,3);
    // l2.insertion(11,4);

    // l1.concatenate(l1,l2);
    // l1.printing();

    
    return 0;
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
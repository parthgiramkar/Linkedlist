#include<iostream>
using namespace std;

class cll{
    public:
    int data;
    cll *next;
    
    cll(int data1) {
        this->data=data1;
        this->next=NULL;
    }
    ~cll() {
        int value=this->data;
        while(this->next!=NULL) {
            delete next;
            next=NULL;
        }
        cout<<"memory freed for node with data - "<<value<<endl;
    }
};    
void insertnode(cll *&tail ,int element , int data2) {
        //if the list is empty
        if(tail==NULL) {
            cll *temp=new cll(data2);
            tail=temp;
            temp->next=temp;
        }
       else {
           //list is non-empty
           cll *temp=tail;
           while(temp->data!=element) {
               temp=temp->next;
           }
           //then element is found i.e is stored in ->next
           cll *newnode =new cll(data2);
           newnode->next=temp->next;
           temp->next=newnode;
       } 
        
           
}
void printdata(cll *&tail ) {
        cll *temp=tail;
        
        if(tail==NULL) {
            cout<<"The list is empty";
            return;
        }
        do {
          cout<<temp->data<<" ";
          temp=temp->next;
        }
        while(temp!=tail);
        cout<<endl;
}
void deletenode(cll *&tail , int value) {
    //list is empty
    if(tail==NULL) {
        cout<<"List is empty please refill it"<<endl;
    }
    else {
        //non empty
        cll *prev=tail;
        cll *curr=prev->next;
        while(curr->data !=value) {
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        
        //only 1 node after deletion then lsit will be empty i.e tail=null
        if(curr==prev) {
             tail=NULL;
        }
        //=2 || >2 nodes
        if(tail==curr) {
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}
// for checking nature of LL --  in depth 
bool iscircular(cll *tail) {
    //list empty
    if(tail==NULL) {
        return true;
    }
    //>1 node
    cll *temp=tail->next;
    while(temp != NULL && temp != tail) {
        temp=temp->next;
    }
    if(temp==tail) {
        return true;
    }
    return false;
}


int main() {
    cll *tail=NULL;
    //when list is empty
    insertnode(tail ,5 , 3);
    printdata(tail);
    
    
    insertnode(tail ,3 , 5);
    printdata(tail);
    
    insertnode(tail ,3 , 10);
    printdata(tail); 
    
    insertnode(tail ,5 , 25);
    printdata(tail);
    
    if( iscircular(tail) ) {
        cout<<"the linkedlist is circular in nature";
    }
    else {
        cout<<"not CLL";
    }
    
    
    return 0;
}


/*
When the list is empty (tail == NULL):
The code enters the if (tail == NULL) block.
A new node is created with the provided data2 value.
This new node becomes the tail of the list, and it points to itself (temp->next = temp), making it a circular linked list with just one node.
Since the list was empty, there is no need to search for an element to insert after. The node is inserted directly into the list
Let’s say you have a circular list with nodes containing values 1 → 2 → 3 → 4 → 1 (circular). If you call insertnode(tail, 3, 5), the program will:

Search through the list to find the node containing 3.
Once the 3 is found, it will insert a new node with data 5 after the node with 3.
*/

bool isCircular(Node* head) {
     
    /*
    without checking cycle in LL that creates loop and not reach end
    if(head==NULL) {
        return true;
    }
    //>1 node
    Node *temp=head->next;
    while(temp != NULL && temp != head) {
        temp=temp->next;
    }
    if(temp==head) {
        return true;
    }
    return false;
    
    // in case of cylce in LL  - Floyd cycle detection algo
    if(head==NULL) {
      return true;
    }
    Node *slow=head , *fast=head ;
    while(fast !=NULL && fast->next != NULL) {
        slow=slow->next;
        fast=fast->next->next;

        if (slow == fast) {
          return true ;// cycle is detected
        }
    }
    return false;
    */
    //in case of cycle loop present in CLL and nature is circular
    if(head==NULL) {
      return true;
    }
    Node *slow=head , *fast=head ;
    while(fast !=NULL && fast->next != NULL) {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast) {
            Node *temp=slow;  //cycle detected in LL or work in normalcasealso

            while (temp != head) {
              temp = temp->next;
              if(temp==slow) {
                return false;
              }
            }
            return true;
        }


    }
    return false;
}


#include <iostream>
using namespace std;

class doublyll {
public:
    int data ;
    doublyll *prev;
    doublyll *next;
    
    //constructor for perfect logic use null instead of prev and next
    doublyll(int data1) {
        this ->data=data1;
        this->prev=NULL;
        this->next=NULL;
    }
    //destructor to avoid memory leak thatwhy to free the memory automatically invoked when delete is called
    ~doublyll() {
        int value=this->data;
        while(this->next!=NULL) {
            delete next;
            this->next=NULL;
        }
        cout<<"memory is freed for node with data -"<<value<<endl;
    }
    //print the data
    void print(doublyll *&head) {
        doublyll *temp=head;
        
        while(temp!=NULL) {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
         cout<<endl;
    }
    //to find length of ll
    int length(doublyll *&head) {
        doublyll *temp=head;
        int length=0;
        while(temp!=NULL) {
            length++;
            temp=temp->next;
        }
        return length;
    }  
    void inserthead(int data2 , doublyll *&head) {
        if(head==NULL) {
            doublyll *temp=new doublyll(data2);
            head=temp;
            
        }else {
            doublyll *temp=new doublyll(data2);
            temp ->next=head;
            head->prev=temp;
            head=temp;
        }
    }
    void inserttail(int data2 , doublyll *&tail) {
        if(tail==NULL) {
            doublyll *temp=new doublyll(data2);
            tail=temp;
            
        }else {
            doublyll *temp=new doublyll(data2);
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
        
    }
    void insertmiddle(doublyll *&head ,doublyll *&tail ,int data2 ,  int position) {
           
            if(position==1) {
                inserthead(data2 ,head);
                return;
            }
            doublyll *temp=head;
            int count=1;
            while(count < position-1) {
                temp=temp->next;
                count++;
            }
            if(temp->next==NULL) {
                inserttail(data2 , tail);
                return;
            }
            doublyll *newnode=new doublyll(data2);
            newnode->next=temp->next;
            temp->next->prev=newnode;
            temp->next=newnode;
            newnode->prev=temp;
    }
    void deletenode(int position , doublyll *&head , doublyll *&tail) {
        doublyll *temp=head;
        if(position==1) {
            temp->next->prev=NULL;
            head=temp->next;
            temp->next=NULL;
            delete temp;
        }
        else {
            int count=1;
            doublyll *prev=NULL;
            while(count < position) {
                prev=temp;
                temp=temp->next;
                count++;
            }
            if(temp->next==NULL) {
                tail=prev;
            }
            temp->prev=NULL;
            prev->next=temp->next;
            temp->next=NULL;
            delete temp;
        }
        
    }
   
};

int main() {
    doublyll *nodeptr= new doublyll(10);
    
    cout<<nodeptr ->data<<endl;
    cout<<nodeptr->prev<<endl;
    cout<<nodeptr->next<<endl;
    
    doublyll *head=nodeptr;
    doublyll *tail=nodeptr;
    
    cout<<"The length of linked list is -";
    cout<<nodeptr->length(head)<<endl;
    nodeptr->print(head);
    
    nodeptr->inserttail(8 , tail);
    nodeptr->print(head);
    
    nodeptr->inserttail(5 , tail);
    nodeptr->print(head);
    
    nodeptr->inserthead(98 , head);
    nodeptr->print(head);
    
    nodeptr->insertmiddle(head ,tail,18 ,2);
    nodeptr->print(head);
    
    nodeptr->deletenode(5,head ,tail);
    nodeptr->print(head);
    
    cout<<"Head position-"<<head->data<<endl;
    cout<<"Tail position-"<<tail->data<<endl;
    
    return 0;
}


 //set this->next = nullptr; before calling delete next;, you lose the reference to the next node, causing a memory leak

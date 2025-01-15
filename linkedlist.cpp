#include<iostream>
//#include<map>
using namespace std;

class node {
public:    
    int data;
    node *next;
    
    //constructor
    node(int data1) {
        this->data=data1;
        this->next;
    }
    //destructor 
    ~node() {
        int value = this->data;
        // Free memory
        if (this->next != nullptr) {
            delete next;
            this->next = nullptr;
        }
        cout << "Memory is freed for node with data " << value << endl;
    }
    
   //insertion of node , &head so multiple copies do not get created as we change dynamically for that create a new node of name temp
    
    void insertHead(node *&head , int data2) {
        node *temp=new node(data2);
        temp -> next=head;
        head=temp;
    }
    
   //insertion of tail same data2 as starting mein tail head same as its single 
    void inserttail(node *&tail , int data2) {
        node *temp=new node(data2);
        tail -> next=temp;
        tail=temp;
    }
    //to print value 
    void print(node *&head) {
        node *temp=head;
        
        while(temp!=NULL) {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    // insert at any position middle first last
    void insertatpos(node *&head , int data2 ,int position,node *&tail)
    { 
        node *newnode=new node(data2);
        
        //position is =1 or head
        if(position==1) {
            insertHead(head , data2);
            return ;
        }
        
        node *temp=head;
        int count=1;
        while(count < position-1) {
            temp=temp->next;
            count++;
        }
        if(temp->next==NULL) {
            inserttail(tail , data2);
            return ;
        }
        
	// this temp->next will get printed in print(head)
        newnode->next=temp->next;
        temp->next=newnode;
        
    }
    // delete node from 1 to length of node
    void deletenode(int position , node *&head, node *&tail) {
        if(position==1) {
        //to access temp - the value deleted  can be accessed when needed
            node *temp=head;
            head=head->next;
            temp=NULL;
            delete temp;
        }
        else {
        // delete middle or last node
        //deleting any middle node or last node
            node* curr = head;
            node* prev = NULL;

            int cnt = 1;
            while(cnt < position) {
                prev = curr;
                curr = curr -> next;
                cnt++;
            }
            if(curr -> next==NULL) {
                tail=prev;
            }
            prev -> next = curr -> next;
            //free the node point to null as it has been removed
            curr -> next  = NULL;
            delete curr;
        }
    }
   // bool detectloop(node *head) {                      //to detect cycle in LL
    map<node* , bool >visited;
    node *temp = head;
    while(temp !=NULL) {
        //cycle is present
        if(visited[temp] == true) {
            return 1;           //return true;
        }
        visited[temp]=true;
        temp=temp->next;
         
        if(temp = head) {
            break;
        }
    }
    return false ;         //no cycle
    
    }

}; 

int main() {
    node *nodeptr = new node(10);
    cout << nodeptr->data << endl;
    cout << nodeptr->next << endl;
    
    node *head = nodeptr;
    node *tail = nodeptr;
    
    nodeptr->print(head);
    
    nodeptr->inserttail(tail, 12);
    nodeptr->print(head);
    
    nodeptr->inserttail(tail, 5);
    nodeptr->print(head);
    
    nodeptr->insertatpos(head, 22, 4, tail); 
    nodeptr->print(head);
    
    cout << "Head position: " << head->data << endl;
    cout << "Tail position: " << tail->data << endl;
    
    nodeptr->deletenode(4 ,head,tail); 
    nodeptr->print(head);
    
    cout << "Head position: " << head->data << endl;
    cout << "Tail position: " << tail->data << endl;
    
    /*if(nodeptr->detectloop(head) ) {
        cout <<"Loop detected in linked list." << endl;
    }
    else {
         cout <<"No loop detected in linked list."<< endl;
    }
    */	
    return 0;
}

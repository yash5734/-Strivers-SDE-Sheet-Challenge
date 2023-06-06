/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    if(head== NULL) return NULL;
    if(head->next == NULL) return NULL;

    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        cnt++;
    }
    int k = cnt-K;
    if(k==0) return head->next;
    int i=0;
    Node* curr = head;
    Node* prev = head;
    while(i<k){
        prev  = curr;
        curr = curr->next;
        i++;
    }
    prev->next  =prev->next->next;
    curr->next = NULL;
    return head;
}

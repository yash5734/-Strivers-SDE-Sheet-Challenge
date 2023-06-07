#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

bool isPalindrome(LinkedListNode<int> *head) {
    if(head == NULL || head->next==NULL) return true;
    // Write your code here.
     int len = 0;
     LinkedListNode<int> *temp = head;
     while(temp!=NULL){
         temp = temp->next;
         len++;
     }

     int num = len/2;
     LinkedListNode<int> *prev = NULL;
     LinkedListNode<int> *head1 = head;

     LinkedListNode<int> *next = NULL;
     LinkedListNode<int> *curr = head;
     int i=0;
     while(curr!=NULL && i<num){
         next = curr->next;
         curr->next = prev;
         prev = curr;
         curr = next;
         i++;
     }          
    head1->next = curr;
    if(len%2!=0) curr = curr->next;
    while(curr!=NULL){
        if(prev->data!=curr->data) return false;
        prev = prev->next;
        curr = curr->next;
    }
return true;


}

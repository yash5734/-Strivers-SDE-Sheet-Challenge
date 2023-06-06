#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* solve(Node<int>* list1 , Node<int>* list2){
    
    Node<int>* curr1 = list1;
    Node<int>* curr2 = list2;
    Node<int>* next1 = curr1->next;
    Node<int>* next2 = curr2->next;
    
    if(next1==NULL){
        curr1->next = curr2;
        return curr1;
    }
    
    while(curr1!=NULL && curr2!= NULL){
        if(curr1->data<=curr2->data && next1->data>=curr2->data){
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
            
        }else{
            curr1 = next1;
            next1 = next1->next;
            if (next1 == NULL) {
              curr1->next = curr2;
              break;
            }
        }
    }


    return list1;
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    
    if(first == NULL && second == NULL) return NULL;
    if(first==NULL) return second;
    if(second == NULL) return first;
    
    if(first->data < second->data){
        return solve(first,second);
    }
    else{
        return solve(second,first);
    }
    
}

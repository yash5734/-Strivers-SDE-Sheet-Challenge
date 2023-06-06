Node *findMiddle(Node *head) {
    // Write your code here
    Node* curr = head;
        int i=0;
        int n=0;
        while(curr!=NULL){
            n++;
            curr = curr->next;
        }
        while(i<n/2){
      head = head->next;
        i++;
        }
       return head;
}

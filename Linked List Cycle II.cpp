Node* detect(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return slow;

    }

    return nullptr;
}

Node *firstNode(Node *head)
{
    //    Write your code here.
    if(head == NULL || head->next == NULL) return nullptr;

    Node* detectCycle = detect(head);

    if(detectCycle!=NULL){
        Node* ptr1 = head;
        Node* ptr2 = detectCycle;

        while(ptr1!=ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    } 
    return nullptr;
   
}

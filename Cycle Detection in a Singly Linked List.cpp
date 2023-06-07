bool detectCycle(Node *head)
{
	//	Write your code here
    if(head == NULL || head->next==NULL) return false;
    Node* fast = head;
    Node* slow = head;
    while(fast!=NULL&& fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow&& slow!=NULL) return true;
    }
    return false;
}

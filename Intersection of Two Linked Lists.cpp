/****************************************************************

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

*****************************************************************/
int len(Node* node){
        int len =0;
        Node* temp = node;
        while(temp){
            len++;
            temp = temp->next;
        }
        return len;
    }
Node* findIntersection(Node* headA, Node* headB) {
    if(!headA || !headB) return NULL;
        int len1 = len(headA);
        int len2 = len(headB);
        if(len1>len2){
            while(len1>len2){
            headA = headA->next;
            len1--;
            }
        }else if(len1<len2){
            while(len1<len2){
                headB = headB->next;
                len2--;
            }
        }

        while(headB&&headA){
            if(headA==headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
}

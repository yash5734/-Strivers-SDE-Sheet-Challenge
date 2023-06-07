/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node* head = new Node(-1);
    int carry = 0;
    Node * curr = head;

    while(num1 && num2){
        int sum = num1->data + num2->data+carry;
        curr->next = new Node(sum%10);
        carry = sum/10;
        curr = curr->next;
        num1 = num1->next;
        num2 = num2->next;
    }
    
    while(num1){
        int sum = num1->data+carry;
        curr->next = new Node(sum%10);
        carry = sum/10;
        curr = curr->next;
        num1 = num1->next;
    }
    while(num2){
        int sum = num2->data+carry;
        curr->next = new Node(sum%10);
        carry = sum/10;
        curr = curr->next;
        num2 = num2->next;
    }

    if(carry){
        curr->next = new Node(carry);
    }


    return head->next;
}

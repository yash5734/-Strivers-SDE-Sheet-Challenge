/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL ||head->next == NULL) return head;

        int len = 1;
        ListNode* curr = head;
        while(curr->next!=NULL){
            curr = curr->next;
            ++len;
        } 
        curr->next = head;
        int temp =0;
        k = k%len;
        temp = len-k-1;
        curr = head;
        while(temp--){
            curr = curr->next;
            
        }
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};

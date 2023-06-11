/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node* solve(Node* list1, Node* list2) {
    Node* curr1 = list1;
    Node* curr2 = list2;
    Node* next1 = NULL;
    Node* next2 = NULL;

    if (curr1->child == NULL) {
        curr1->child = list2;
        return curr1;
    }

    next1 = curr1->child;
    next2 = curr2->child;

    while (next1 != NULL && curr2 != NULL) {
        if (curr2->data >= curr1->data && curr2->data <= next1->data) {
            curr1->child = curr2;
            next2 = curr2->child;
            curr2->child = next1;
            curr1 = curr2;
            curr2 = next2;
        } else {
            curr1 = next1;
            next1 = next1->child;
            if (next1 == NULL) {
                curr1->child = curr2;
                return list1;
            }
        }
    }
    return list1;
}

Node* merge(Node* list1, Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    if (list1->data < list2->data) {
        return solve(list1, list2);
    } else {
        return solve(list2, list1);
    }
}

Node* flattenLinkedList(Node* head) {
    if (head == NULL || head->next == NULL) return head;

    Node* down = head;
    Node* right = flattenLinkedList(head->next);
    return merge(down, right);
}

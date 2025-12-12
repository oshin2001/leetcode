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
    ListNode* merge(ListNode* a, ListNode* b) {

        ListNode* head = nullptr;
        if (!a)
            return b;
        if (!b)
            return a;

        if (a->val < b->val) {

            head = a;
            head->next = merge(a->next, b);

        } else {
            head = b;
            head->next = merge(a, b->next);
        }

        return head;
    }

    ListNode* middle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;


        ListNode* left = head;

        ListNode* mid = middle(head);
        ListNode* right = mid->next;
        mid->next = nullptr;
        
        ListNode* leftnode = sortList(left);
        ListNode* rightnode = sortList(right);

        return merge(leftnode, rightnode);
    }
};
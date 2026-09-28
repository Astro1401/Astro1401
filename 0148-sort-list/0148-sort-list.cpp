class Solution {
public:

    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* temp = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }
        }

        if (l1) temp->next = l1;
        else temp->next = l2;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* mid = findMiddle(head);

        ListNode* right = mid->next;
        mid->next = NULL;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
};
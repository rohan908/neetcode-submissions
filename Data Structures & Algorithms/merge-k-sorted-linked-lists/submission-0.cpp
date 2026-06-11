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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        //find valid head
        ListNode* head = nullptr;
        int i = 0;
        for (i = 0; i < lists.size(); i++) {
            if(lists[i]) {
                head = lists[i];
                i++;
                break;
            }
        }
        cout << head->val;

        for (i; i < lists.size(); i++) {
            head = mergeTwoLists(head, lists[i]);
        }
        return head;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        if (l1 && l2) {
            if (l1->val <= l2->val) {
                head = l1;
                l1 = l1->next;
            } else {
                head = l2;
                l2 = l2->next;
            }
        } else if (l1) {
            head = l1;
            l1 = l1->next;
        } else if (l2) {
            head = l2;
            l2 = l2->next;
        }

        ListNode* curr = head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        while (l1) {
            curr->next = l1;
            l1 = l1->next;
            curr = curr->next;
        }
        while (l2) {
            curr->next = l2;
            l2 = l2->next;
            curr = curr->next;
        }
        return head;
        
    }
};

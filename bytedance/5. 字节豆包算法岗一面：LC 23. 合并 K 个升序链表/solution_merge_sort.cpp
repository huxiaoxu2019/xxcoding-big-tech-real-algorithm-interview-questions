/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *
 *
 * Time Complexity: T(k) = n*k + 2T(k/2) = O(nk*logk)
 */
class Solution {
public:
    ListNode* mergeTwoList(ListNode* first, ListNode* second) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while (first != nullptr && second != nullptr) {
            if (first->val <= second->val) {
                cur->next = first;
                first = first->next;
            } else {
                cur->next = second;
                second = second->next;
            }
            cur = cur->next;
        }
        while (first != nullptr) {
            cur->next = first;
            cur = cur->next;
            first = first->next;
        }
        while (second != nullptr) {
            cur->next = second;
            cur = cur->next;
            second = second->next;
        }
        return dummy->next;
    }
    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if (l == r) return lists[l];
        if (l + 1 == r) {
            return mergeTwoList(lists[l], lists[r]);
        }
        int m=l+(r-l)/2;
        ListNode* first = merge(lists, l, m);
        ListNode* second = merge(lists, m+1, r);
        return mergeTwoList(first, second);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return merge(lists, 0, lists.size() - 1);
    }
};

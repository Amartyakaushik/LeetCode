#include <queue>

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        int nodesCount = 0;
        ListNode* temp = head;
        while (temp) {
            nodesCount++;
            temp = temp->next;
        }

        std::queue<ListNode*> firstHalf;
        std::stack<ListNode*> secondHalf;

        int half = (nodesCount + 1) / 2;

        temp = head;
        for (int i = 0; i < half; i++) {
            firstHalf.push(temp);
            temp = temp->next;
        }
        for (int i = half; i < nodesCount; i++) {
            secondHalf.push(temp);
            temp = temp->next;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (!firstHalf.empty() || !secondHalf.empty()) {
            if (!firstHalf.empty()) {
                curr->next = firstHalf.front();
                firstHalf.pop();
                curr = curr->next;
            }
            if (!secondHalf.empty()) {
                curr->next = secondHalf.top();
                secondHalf.pop();
                curr = curr->next;
            }
        }
        curr->next = nullptr;

        head = dummy->next;
        delete dummy;
    }
};

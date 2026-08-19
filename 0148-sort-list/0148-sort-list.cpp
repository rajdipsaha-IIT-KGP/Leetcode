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
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* node1,ListNode* node2){
        if(!node1)
        return node2;
        if(!node2)
        return node1;

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        ListNode* ptr1 = node1;
        ListNode* ptr2 = node2;

        while(ptr1 && ptr2){
            if(ptr1->val > ptr2->val){
              temp->next = ptr2;
              temp = temp->next;
              ptr2 = ptr2->next;
            } else {
              temp->next = ptr1;
              temp = temp->next;
              ptr1 = ptr1->next;
            }
        }
        if(ptr1){
            temp->next = ptr1;
        } 
        if(ptr2){
            temp->next = ptr2;
        }
        return dummyNode->next;
    }
    ListNode* mergeSort(ListNode* head){
       if(!head || !head->next)
        return head;

      ListNode* middle = findMiddle(head);
      ListNode* right = middle->next;
      middle->next = nullptr;

     ListNode* leftPart =  mergeSort(head);
     ListNode* rightPart = mergeSort(right);

     return merge(leftPart,rightPart);

    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
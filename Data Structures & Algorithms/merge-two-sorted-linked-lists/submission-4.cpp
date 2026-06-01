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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2; 
        if(list2 == NULL) return list1; 

        ListNode* dummyNode = new ListNode(); 
        ListNode* tail = dummyNode; 

        ListNode* curr1 = list1; 
        ListNode* curr2 = list2; 

        while(curr1 != NULL && curr2 != NULL){
            if(curr1->val <= curr2->val){
                tail->next = new ListNode(curr1->val); 
                curr1 = curr1->next; 
            }else{
                tail->next = new ListNode(curr2->val); 
                curr2 = curr2->next;  
            }
            tail = tail->next; 
        }

        while(curr1 != NULL){
            tail->next = new ListNode(curr1->val); 
            curr1 = curr1->next; 
            tail = tail->next; 
        }while(curr2 != NULL){
            tail->next = new ListNode(curr2->val); 
            curr2 = curr2->next; 
            tail = tail->next; 
        }
        return dummyNode->next;
    }
};

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

        vector<int> temp; 
        
        ListNode* curr1 = list1; 
        ListNode* curr2 = list2; 

        //O(n)
        while(curr1 != NULL){
            temp.push_back(curr1->val); 
            curr1 = curr1->next; 
        }

        //O(m)
        while(curr2 != NULL){
            temp.push_back(curr2->val); 
            curr2 = curr2->next; 
        }

        //O((n+m)log(n+m))
        sort(temp.begin(), temp.end()); 

        ListNode* dummy = new ListNode(); 
        ListNode* tail = dummy; 

        for(int i = 0; i < temp.size(); i++){
            tail->next = new ListNode(temp[i]); 
            tail = tail->next; 
        }
        return dummy->next; 
    }
};

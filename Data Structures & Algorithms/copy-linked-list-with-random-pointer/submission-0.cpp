/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL; 

        //create all dummy nodes
        unordered_map<Node*, Node*> map;

        Node* curr = head; 

        while(curr != NULL){
            Node* newNode = new Node(curr->val);
            map[curr] = newNode;
            curr = curr->next;
        }
        //set curr to head again
        curr = head; 

        //deep copy all node pointers
        while(curr != NULL){
            Node* copyNode = map[curr]; 
            copyNode->next = map[curr->next];
            copyNode->random = map[curr->random]; 
            curr = curr->next; 
        }
        return map[head]; 
    }
};

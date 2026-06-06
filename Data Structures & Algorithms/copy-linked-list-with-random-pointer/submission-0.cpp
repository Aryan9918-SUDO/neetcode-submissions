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

        if(head == NULL)
            return NULL;

        unordered_map<Node*, Node*> mp;

        Node* curr = head;

        // Pass 1: create copy nodes
        while(curr) {

            mp[curr] = new Node(curr->val);

            curr = curr->next;
        }

        curr = head;

        // Pass 2: connect pointers
        while(curr) {

            mp[curr]->next =
                curr->next ? mp[curr->next] : NULL;

            mp[curr]->random =
                curr->random ? mp[curr->random] : NULL;

            curr = curr->next;
        }

        return mp[head];
    }
};
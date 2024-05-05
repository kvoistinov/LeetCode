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
    Node* copyRandomList(Node* head) 
    {
        if (!head) {
            return nullptr;
        }
        std::unordered_map<Node*, Node*> rand_to_copy;

        Node* curr_orig = head;
        Node  dummy(head->val);
        Node* curr_copy = &dummy;

        while (curr_orig != nullptr)
        {
            Node* new_node  = new Node(curr_orig->val);
            curr_copy->next = new_node;

            rand_to_copy[curr_orig] = curr_copy->next;

            curr_orig = curr_orig->next;
            curr_copy = curr_copy->next;
        }
        curr_orig = head;
        curr_copy = dummy.next;

        while (curr_orig != nullptr)
        {
            auto it = rand_to_copy.find(curr_orig->random);

            if (it != rand_to_copy.end()) {
                curr_copy->random = it->second;
            }
            curr_orig = curr_orig->next;
            curr_copy = curr_copy->next;
        }

        return dummy.next;
    }
};

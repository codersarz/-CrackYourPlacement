//Time-Complexity-> O(n*logn)

TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return new TreeNode(head->val);
        }

        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev_slow=NULL;

        while(fast!=NULL && fast->next!=NULL){
            prev_slow=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        TreeNode* root=new TreeNode(slow->val);

        prev_slow->next=NULL;
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(slow->next);

        return root;
    }

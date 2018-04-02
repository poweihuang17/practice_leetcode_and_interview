/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr) return nullptr;
        TreeNode * root=helper(head,nullptr);
        return root;
    }

private:
	TreeNode * helper(ListNode *head, ListNode * end)
	{
		//Why this condition?
		if(head==end) return nullptr;
		ListNode * first=head;
		ListNode * second=head;

		while(second!=end && second->next!=end)
		{
			second=second->next->next;
			first=first->next;
		}

		TreeNode * root=new TreeNode(first->val);
		TreeNode * right=helper(first->next, end);
		TreeNode * left=helper(head, first);
		root->left=left;
		root->right=right;
		return root;
	}
};
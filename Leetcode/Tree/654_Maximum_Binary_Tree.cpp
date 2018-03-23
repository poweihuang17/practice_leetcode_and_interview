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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return makeMBT(nums,0,nums.size());
    }

private:
	TreeNode * makeMBT(const vector<int> & nums, int begin, int end)
	{
		if(begin>=end) return nullptr;
		auto it=std::max_element(nums.begin()+begin,nums.begin()+end);
		TreeNode * root=new TreeNode(*it);
		int index= it-nums.begin();
		root->left=makeMBT(nums,begin,index);
		root->right=makeMBT(nums,index+1, end);
		return root;
	}
};
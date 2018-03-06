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
    bool findTarget(TreeNode* root, int k) {
    	vector<int> t;
    	inorder(root,t);

    	return twoSum(t,k);
    }

    void inorder(TreeNode * root, vector<int> & t){
    	if(root!=nullptr)
    	{
    		t.push_back(root->value);
    		inorder(root->left, t);
    		inorder(root->right,t);
    	}
    }

    bool twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable;
        unordered_map<int,int>::iterator iter;
        vector <int> result(2);

        for(int i=0;i<nums.size();i++)
        {
        	int x=nums[i];
        	iter=hashTable.find(target-x);
        	if(iter!=hashTable.end())
        	{
        		//result[0]=iter->second;
        		//result[1]=i;
        		return true;
        	}
        	else
        	{
        		hashTable[nums[i]]=i;
        	}
        }

        return false;
    }

};
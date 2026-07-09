/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root== NULL) return 0;
        int ans=INT_MIN;

        //queue<TreeNode*,int i> q; (queue in pair becoz queue stores one type, so you need a pair)
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});

        long long first, last;
        while(!q.empty()){
            int size= q.size();
            long long mini= q.front().second;

            for(int i=0;i< size;i++){

                TreeNode* curr= q.front().first;
                int id= q.front().second;
                q.pop();
                
                //to prevent overflow
                long long cur_id= id- mini;

                if(i==0) first=cur_id;
                if(i==size-1) last = cur_id;

                if(curr->left){
                    q.push({curr->left, 2*cur_id+1});
                }
                if(curr->right){
                    q.push({curr->right, 2*cur_id+2});
                }
                ans= max(ans,(int) (last - first + 1) );

            }
        }
        return ans;

    }
};
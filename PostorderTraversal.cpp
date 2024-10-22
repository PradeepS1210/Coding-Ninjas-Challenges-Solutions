// Companies asking this question: Amazon, Microsoft, PayPal

/********************************************************************************
Problem statement
You have been given a Binary Tree of 'n' nodes, where the nodes have integer values. Your task is to return its postorder traversal.

For Example:
For the given tree below,
Postorder traversal for the given tree will be [4, 5, 2, 3, 1]. Hence, the answer is [4, 5, 2, 3, 1].

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
1 2 3 4 -1 -1 5 6 7 -1 -1 -1 -1 -1 -1
Sample Output 1:
6 7 4 2 5 3 1
Explanation:
The given tree is:

Postorder traversal for the given tree will be [6, 7, 4, 2, 5, 3, 1]. Hence, the answer is [6, 7, 4, 2, 5, 3, 1].
Sample Input 2:
10 20 11 -1 -1 -1 -1
Sample Output 2:
20 11 10
Expected time complexity:
The expected time complexity is O(n).
Constraints :
1 <= 'n' <= 10^5
0 <= 'data' <= 10^5     

where 'n' is the number of nodes and 'data' denotes the node value of the binary tree nodes.

Time limit: 1 sec
*********************************************************************************/

/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

/*
    Time Complexity: O(N)
    Space Complexity: O(N)

*/

void postorder(TreeNode* node, vector<int> &ans)
{
    if (node == NULL)
    {
        return;
    }

    postorder(node->left, ans);

    postorder(node->right, ans);
 
    ans.push_back(node->data);
}   

vector<int> postorderTraversal(TreeNode* root)
{   
    vector<int> ans;
    
    postorder(root, ans);
    return ans;
}

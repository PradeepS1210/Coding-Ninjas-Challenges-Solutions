// Companies asking this question: Google, Tata, Visa, Swiggy, TCS, Snapdeal, Paytm, Amazon, IBM, Wipro

/*********************************************************************************
Problem statement
You have been given a Binary Tree of 'n' nodes, where the nodes have integer values. Your task is to return the In-Order traversal of the given binary tree.

For example :
For the given binary tree:

The Inorder traversal will be [5, 3, 2, 1, 7, 4, 6].
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
1 2 3 -1 -1 -1  6 -1 -1
Sample Output 1 :
2 1 3 6
Explanation of Sample Output 1 :
The given binary tree is shown below:

Inorder traversal of given tree = [2, 1, 3, 6]
Sample Input 2 :
1 2 4 5 3 -1 -1 -1 -1 -1 -1
Sample Output 2 :
5 2 3 1 4
Explanation of Sample Output 2 :
The given binary tree is shown below:

Inorder traversal of given tree = [5, 2, 3, 1, 4]
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
    Time Complexity: O( N )
    Space Complexity: O( N )
*/

void inOrderHelper(TreeNode *node, vector<int> &answer)
{
    if (node == NULL)
    {
        return;
    }

    inOrderHelper(node->left, answer);

    answer.push_back(node->data);

    inOrderHelper(node->right, answer);
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> answer;

    inOrderHelper(root, answer);

    return answer;
}

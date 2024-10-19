// Companies asking this question: HSBC, Accenture, Flipkart

/**********************************************************************************
Problem statement
You are given a binary search tree of integers with 'N' nodes. Your task is to return the K-th largest element of this BST.

If there is no K-th largest element in the BST, return -1.

A binary search tree (BST) is a binary tree data structure which has the following properties.

• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
1 <= N <= 5000
1 <= K <= 5000
0 <= Data <= 10^6 and Data != -1

Time Limit: 1sec
Sample Input 1 :
2
3
3 1 5 -1 2 -1 6 -1 -1 -1 -1 
2
2 1 -1 -1 -1 
Sample Output 1:
3
1
Explanation for Sample 1:
Test Case 1:
The sorted array corresponding to the first test case will be [1, 2, 3, 5, 6]. The 3rd largest element will be 3.

Test Case 2:
The sorted array corresponding to the second test case will be [1, 2]. The 2nd largest element will be 1.
Sample Input 2 :
1
5
10 -1 20 -1 30 -1 40 -1 -1
Sample Output 2:
-1
***********************************************************************************/

#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void inorder(TreeNode<int>* root, vector<int>& inTraversal)
{
	if (root == NULL)
	{
		return;
	}

	inorder(root -> left, inTraversal);

    inTraversal.push_back(root -> data);

	inorder(root -> right, inTraversal);
}


int KthLargestNumber(TreeNode<int>* root, int k)
{
	vector <int> inTraversal;

	inorder(root, inTraversal);

	int n = inTraversal.size();

	if (k > n)
	{
		return -1;
	}
	
	return inTraversal[n - k];
}

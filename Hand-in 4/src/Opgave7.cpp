#include <algorithm>
#include <iostream>
using namespace std;

// Structure of a AvlTree
struct AvlTree {
	int element;
	struct AvlTree* left;
	struct AvlTree* right;
	AvlTree(int data)
	{
		element = data;
		left = right = NULL;
	}
};

// Function to check if tree is height balanced
int isBalanced(AvlTree* root)
{
/**
 * The base case returns 0 for an empty tree
 * 
 */
	if (root == NULL)
		return 0;

/**
 * Now we recursively travel down the roots children until we hit the base case
 * Here -1 denotes that the tree is unbalanced
 * If LeftHeight and rightHeight are already -1 we just return false immediatly without having to traverse the whole tree
 */
	int leftHeight = isBalanced(root->left);
	if (leftHeight == -1)
		return -1;

	int rightHeight = isBalanced(root->right);
	if (rightHeight == -1)
		return -1;
/**
 * here we Check to see if any of the branches were unbalanced
 * 
 */
	if (abs(leftHeight - rightHeight) > 1)
		return -1;
/**
 * Otherwise we take the longest branch and return the height of that branch
 * After this else statement is called we go back one branch and check the above if statement again
 * if we make it to the root without the above if statement being true then the tree is balanced
 */
    else
		return max(leftHeight, rightHeight)+1;
}


int main()
{

	AvlTree* root = new AvlTree(10);
	root->left = new AvlTree(5);
	root->right = new AvlTree(30);
	root->right->left = new AvlTree(15);
	root->right->right = new AvlTree(20);
    root->right->right->right = new AvlTree(22);
    root->left->right = new AvlTree(3);

   // root->left->left = new AvlTree(18);

//root->right->right->right = new AvlTree(88);

    cout << isBalanced(root);
	if (isBalanced(root)>0)
		cout << "Balanced";
	else
		cout << "Not Balanced";
	return 0;
}

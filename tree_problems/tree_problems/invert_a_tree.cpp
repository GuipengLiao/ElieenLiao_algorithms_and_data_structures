#include<iostream>
#include<queue>
#include<iomanip>

struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int d)
		:data{ d }, left(nullptr), right{nullptr}
	{

	}
};

void invertTreeRecursion(TreeNode *root) 
{
	if (root == nullptr)return;

	// Swap left and right trees
	TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;

	// Do this recursively for left and right sub-trees.
	invertTreeRecursion(root->left);
	invertTreeRecursion(root->right);
}

void invertTreeIter(TreeNode* root) 
{
	if (root == nullptr)return;

	std::queue<TreeNode*> nodeQueue;
	nodeQueue.push(root);

	while (!nodeQueue.empty())
	{
		TreeNode *curr = nodeQueue.front();
		nodeQueue.pop();

		//Sawp left and right children
		TreeNode *tmp = curr->left;
		curr->left = curr->right;
		curr->right = tmp;

		if (curr->left)
			nodeQueue.push(curr->left);
		if (curr->right)
			nodeQueue.push(curr->right);
	}
}

// Prints post order traversal of tree, where level expands left to right.
void postOrder(TreeNode* root, int indent = 0) 
{

}

int main() 
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);;
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	std::cout << "Current Tree: \n";
	postOrder(root);
	std::cout << "\nInverting it recursively:\n";
	invertTreeRecursion(root);
	postOrder(root);
	std::cout << "\nInverting it again iteratively:\n";
	invertTreeIter(root);
	postOrder(root);
	std::cout << std::endl;
	return 0;
}
/*5. Write a C program to construct a binary tree and do inorder, preorder and postorder traversals,
printing the sequence of TreeNodes visited in each case.
*/

#include <iostream>
#include <stack>
#include <queue>
#define null NULL
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *CreateTreeNode(int data)
{
    TreeNode *newTreeNode = new TreeNode();
    if (!newTreeNode)
    {
        cout << "Memory error\n";
        return null;
    }
    newTreeNode->data = data;
    newTreeNode->left = newTreeNode->right = null;
    return newTreeNode;
}

TreeNode *InsertTreeNode(TreeNode *root, int data)
{

    if (root == null)
    {
        root = CreateTreeNode(data);
        return root;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();

        if (temp->left != null)
            q.push(temp->left);
        else
        {
            temp->left = CreateTreeNode(data);
            return root;
        }

        if (temp->right != null)
            q.push(temp->right);
        else
        {
            temp->right = CreateTreeNode(data);
            return root;
        }
    }
}

void inorder(TreeNode *temp)
{
    if (temp == null)
        return;

    inorder(temp->left);
    cout << temp->data << " -> ";
    inorder(temp->right);
}

void printPreorder(struct TreeNode *TreeNode)
{
    if (TreeNode == null)
        return;

    cout << TreeNode->data << " -> ";
    printPreorder(TreeNode->left);
    printPreorder(TreeNode->right);
}

void printPostorder(struct TreeNode *TreeNode)
{
    if (TreeNode == null)
        return;
    printPostorder(TreeNode->left);
    printPostorder(TreeNode->right);
    cout << TreeNode->data << " -> ";
}

int main()
{
    TreeNode *root = CreateTreeNode(8);
    root->left = CreateTreeNode(9);
    root->left->left = CreateTreeNode(5);
    root->right = CreateTreeNode(7);
    root->right->left = CreateTreeNode(13);
    root->right->right = CreateTreeNode(6);

    cout << "Inorder traversal( without insertion being operated ): ";
    inorder(root);
    cout << "null \n";

    int treeNodeData = 10;
    root = InsertTreeNode(root, treeNodeData);

    cout << "Inorder traversal (after insertiion has been operated): ";
    inorder(root);
    cout << "null \n";
    cout << endl;
    cout << "postOrder traversal: ";
    printPostorder(root);
    cout << "null \n";
    cout << "preOrder traversal: ";
    printPreorder(root);
    cout << "null \n";
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Node structure for Binary Search Tree
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to build a Balanced BST from sorted array
TreeNode* buildBST(vector<int>& arr, int left, int right) {
    if (left > right) return NULL; // Base case

    int mid = left + (right - left) / 2; // Middle element as root
    TreeNode* root = new TreeNode(arr[mid]);

    // Recursively build left and right subtrees
    root->left = buildBST(arr, left, mid - 1);
    root->right = buildBST(arr, mid + 1, right);

    return root;
}

// Inorder Traversal (Left, Root, Right) -> sorted output
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Preorder Traversal (Root, Left, Right)
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal (Left, Right, Root)
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements (preferably sorted):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort the array to ensure it is sorted
    sort(arr.begin(), arr.end());

    // Build Balanced BST from sorted array
    TreeNode* root = buildBST(arr, 0, n - 1);

    int choice;
    cout << "\nChoose traversal type:\n";
    cout << "1. Inorder Traversal\n";
    cout << "2. Preorder Traversal\n";
    cout << "3. Postorder Traversal\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "\nTraversal Output: ";

    // Switch case to choose traversal type
    switch (choice) {
        case 1:
            inorder(root);
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            postorder(root);
            break;
        default:
            cout << "Invalid choice!";
    }

    cout << endl;
    return 0;
}

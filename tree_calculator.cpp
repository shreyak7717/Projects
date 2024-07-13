#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

struct TreeNode {
    string value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* constructTree(const string& postfix) {
    stack <TreeNode*> st;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            st.push(new TreeNode(string(1, ch)));
        } else {
            TreeNode* node = new TreeNode(string(1, ch));

            node->right = st.top();
            st.pop();

            node->left = st.top();
            st.pop();

            st.push(node);
        }
    }

    return st.top();
}

int evaluateTree(TreeNode* root) {
    if (!root){
        return 0;}

    if (!root->left && !root->right){
        return stoi(root->value);}

    int leftVal = evaluateTree(root->left);
    int rightVal = evaluateTree(root->right);

    if (root->value == "+"){
        return leftVal + rightVal;}
    if (root->value == "-"){
        return leftVal - rightVal;}
    if (root->value == "*"){
        return leftVal * rightVal;}
    if (root->value == "/"){
        return leftVal / rightVal;}

    return 0;
}

int main() {
    string postfix = "55+82-*";  // Example postfix i.e in infix expression: ((5 + 5) * (8 - 2))

    TreeNode* root = constructTree(postfix);
    int result = evaluateTree(root);

    cout << "The result of the expression is: " << result << endl;

    return 0;
}

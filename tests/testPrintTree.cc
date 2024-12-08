#include <gtest/gtest.h>
#include "print_tree.h"

typedef struct TreeNode {
    const char *value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* create_sample_tree() {
    TreeNode* node3 = new TreeNode{"C", nullptr, nullptr};
    TreeNode* node2 = new TreeNode{"B", nullptr, nullptr};
    TreeNode* node1 = new TreeNode{"A", node2, node3};
    return node1;
}

void delete_tree(TreeNode* node) {
    if (node == nullptr)
		return;
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

void collect_preorder(TreeNode* node, std::vector<std::string>& values) {
    if (node == nullptr) return;
    values.push_back(node->value);
    collect_preorder(node->left, values);
    collect_preorder(node->right, values);
}

void collect_inorder(TreeNode* node, std::vector<std::string>& values) {
    if (node == nullptr) return;
    collect_inorder(node->left, values);
    values.push_back(node->value);
    collect_inorder(node->right, values);
}

void collect_postorder(TreeNode* node, std::vector<std::string>& values) {
    if (node == nullptr) return;
    collect_postorder(node->left, values);
    collect_postorder(node->right, values);
    values.push_back(node->value);
}

TEST(PrintTreeTest, TestPreorderTraversal) {
    TreeNode* root = create_sample_tree();
    std::vector<std::string> values;
    collect_preorder(root, values);
    std::vector<std::string> expected_values = {"A", "B", "C"};
    EXPECT_EQ(values, expected_values);
    delete_tree(root);
}

TEST(PrintTreeTest, TestInorderTraversal) {
    TreeNode* root = create_sample_tree();
    std::vector<std::string> values;
    collect_inorder(root, values);
    std::vector<std::string> expected_values = {"B", "A", "C"};
    EXPECT_EQ(values, expected_values);
    delete_tree(root);
}

TEST(PrintTreeTest, TestPostorderTraversal) {
    TreeNode* root = create_sample_tree();
    std::vector<std::string> values;
    collect_postorder(root, values);
    std::vector<std::string> expected_values = {"B", "C", "A"};
    EXPECT_EQ(values, expected_values);
    delete_tree(root);
}

TEST(PrintTreeTest, TestEmptyTree) {
    TreeNode* root = nullptr;
    std::vector<std::string> values;
    collect_preorder(root, values);
    std::vector<std::string> expected_values = {};
    EXPECT_EQ(values, expected_values);
}

TEST(PrintTreeTest, TestSingleNodeTree) {
    TreeNode* root = new TreeNode{"A", nullptr, nullptr};
    std::vector<std::string> values;
    collect_preorder(root, values);
    std::vector<std::string> expected_values = {"A"};
    EXPECT_EQ(values, expected_values);
    delete_tree(root);
}

TEST(PrintTreeTest, TestLargerTree) {
    TreeNode* node4 = new TreeNode{"D", nullptr, nullptr};
    TreeNode* node3 = new TreeNode{"C", nullptr, nullptr};
    TreeNode* node2 = new TreeNode{"B", nullptr, nullptr};
    TreeNode* node1 = new TreeNode{"A", node2, node3};
    node2->left = node4;

    std::vector<std::string> values;
    collect_preorder(node1, values);
    std::vector<std::string> expected_values = {"A", "B", "D", "C"};
    EXPECT_EQ(values, expected_values);
    delete_tree(node1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
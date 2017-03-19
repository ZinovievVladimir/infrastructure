#include <gtest/gtest.h>
#include <bintree.h>
#include <queue>

TEST(Tree, CorrectTreeOfUneven) {
  int a[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
  CNode* tree = CreateTree(a, 13);
  std::queue<CNode*> q;
  q.push(tree);
  bool b = true;

  while (!q.empty()) {
    CNode* tmp = q.front();
    q.pop();

    if (tmp->left != 0) {
      if (tmp->left->v > tmp->v) {
        b = false;
        break;
      }
      q.push(tmp->left);
    }
    if (tmp->right != 0) {
      if (tmp->right->v < tmp->v) {
        b = false;
        break;
      }
      q.push(tmp->right);
    }
  }

  EXPECT_TRUE(b);
}

TEST(Tree, CorrectTreeOfEven) {
  int a[8] = { 1, 2, 3, 4, 5, 6, 10, 11 };
  CNode* tree = CreateTree(a, 8);
  std::queue<CNode*> q;
  q.push(tree);
  bool b = true;

  while (!q.empty()) {
    CNode* tmp = q.front();
    q.pop();

    if (tmp->left != 0) {
      if (tmp->left->v > tmp->v) {
        b = false;
        break;
      }
      q.push(tmp->left);
    }
    if (tmp->right != 0) {
      if (tmp->right->v < tmp->v) {
        b = false;
        break;
      }
      q.push(tmp->right);
    }
  }

  EXPECT_TRUE(b);
}

TEST(Tree, TreeOfOne) {
  int a[1] = { 4 };
  CNode* tree = CreateTree(a, 1);

  EXPECT_EQ(tree->v, 4);
  EXPECT_EQ(tree->left, nullptr);
  EXPECT_EQ(tree->right, nullptr);
}

TEST(Tree, TreeOfNothing) {
  CNode* tree = CreateTree(nullptr, 1);

  EXPECT_EQ(tree, nullptr);
}

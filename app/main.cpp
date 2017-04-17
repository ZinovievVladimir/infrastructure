#include <bintree.h>
#include <iostream>
#include <queue>

int main() {
  int a[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
  CNode* tree = CreateTree(a, 13);
  std::queue<CNode*> q;
  q.push(tree);
  while (!q.empty()) {
    int size = q.size();
    CNode* tmp;
    for (int i = 0; i < size; i++) {
      tmp = q.front();
      q.pop();
      std::cout << tmp->v;
      if (tmp->left != 0)
        q.push(tmp->left);
      if (tmp->right != 0)
        q.push(tmp->right);
    }
    std::cout << std::endl;
  }
}

#ifndef INCLUDE_BINTREE_H_
#define INCLUDE_BINTREE_H_
#include <queue>

struct CNode {
  int v;
  CNode* left;
  CNode* right;
  explicit CNode(int val = 0) {
	  v = val;
	  left = nullptr;
	  right = nullptr;
  }
};

CNode* CreateTree(int* m, int l);

#endif  // INCLUDE_ADD_H_

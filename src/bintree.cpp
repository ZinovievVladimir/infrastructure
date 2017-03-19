#include "bintree.h"

CNode* CreateTree(int* m, int l){
  std::queue<int> ql, qr;
  std::queue<CNode**> qt;
  CNode* tree;
  int mid, left, right;

  ql.push(0);
  qr.push(l-1);
  qt.push(&tree);

  while (!ql.empty()) {
	CNode** node = qt.front();
    int lf = ql.front();
	int rg = qr.front();
	ql.pop();
	qr.pop();
	qt.pop();

	mid = (rg - lf)/2;

	if (lf < rg) {
	  *node = new CNode (m[mid]);

	  qt.push (&(*node)->left);
	  ql.push(lf);
	  qr.push(mid);

	  qt.push (&(*node)->right);
	  ql.push(mid+1);
	  qr.push(rg);
	}
  }
  return tree;
}




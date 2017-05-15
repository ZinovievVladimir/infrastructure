#include <vector>
#include "UF.h"

using std::pair;
using std::vector;

vector< int > tk(vector <pair <int, int> > p, int n) {
  UF mn(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a = mn.Find(i);
      int b = mn.Find(j);
      int size = p.size();
      bool why = true;
      for (int k = 0; k < size; k++) {
        if (((mn.Find(p[k].first) == a) &&
            (mn.Find(p[k].second) == b)
          || (mn.Find(p[k].first) == b) &&
            (mn.Find(p[k].second) == a))) {
          why = false;
          break;
        }
      }
      if (why)
        mn.Union(a, b);
    }
  }

  vector< int > ret;
  for (int i = 0; i < n; i++)
    ret.push_back(mn.Find(i));

  return ret;
}

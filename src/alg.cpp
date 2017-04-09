#include <vector>
#include <utility>
#include <set>

using std::vector;
using std::pair;

bool all_false(bool* a, int b) {
  for (int i = 0; i < b; i++)
    if (a[b] == true)
      return false;
  return true;
}

vector<int> alg(vector< vector < pair < int, int > > > ls, int a) {
  std::set <pair <int, int> > T;
  bool *aw = new bool[ls.size()];
  for (unsigned int i = 0; i < ls.size(); i++)
    aw[i] = true;

  auto t = ls[a];
  for (auto it = t.begin(); it != t.end(); it++) {
    T.insert(*it);
  }
  vector<int> ret(ls.size(), INT_MAX);

  ret[a] = 0;
  aw[a] = false;
  while(!all_false(aw, ls.size())) {
    int vs = T.begin()->second;
    T.erase(T.begin());
    if (aw[vs] != false) {
      aw[vs] = false;
      t = ls[vs];

      for (auto it = t.begin(); it != t.end(); it++) {
        if (it->first < ret[it->second])
          ret[it->second] = it->first;
        T.insert(*it);
      }
    }
  }
  return ret;
}

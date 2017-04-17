#include <vector>
#include <utility>
#include <set>
#include <stdexcept>
#include <limits.h>

using std::vector;
using std::pair;

bool all_false(bool* a, int b) {
  for (int i = 0; i < b; i++)
    if (a[i] == true)
      return false;
  return true;
}

vector<int> alg(vector< vector < pair < int, int > > > ls, int a) {
  if (a >= static_cast<int>(ls.size())) {
    throw std::logic_error("Wrong Vertex!");
  }
  std::set <pair <int, int> > T;
  bool *aw = new bool[ls.size()];
  for (unsigned int i = 0; i < ls.size(); i++)
    aw[i] = true;

  vector<int> ret(ls.size(), INT_MAX);
  auto t = ls[a];

  for (auto it = t.begin(); it != t.end(); it++) {
    T.insert(*it);
    ret[it->second] = it->first;
  }

  ret[a] = 0;
  aw[a] = false;
  while (!all_false(aw, ls.size())) {
    int vs = T.begin()->second;
    T.erase(T.begin());
    if (aw[vs] != false) {
      aw[vs] = false;
      t = ls[vs];

      for (auto it = t.begin(); it != t.end(); it++) {
        if (it->first + ret[vs] < ret[it->second])
          ret[it->second] = it->first + ret[vs];
        T.insert(*it);
      }
    }
  }
  return ret;
}

#ifndef INCLUDE_ALGS_H_
#define INCLUDE_ALGS_H_
#include <vector>

using std::vector;

struct edge {
  int f, s;
  int w;

  explicit edge(int f_ = 0, int s_ = 0, int w_ = 0) :
    f(f_), s(s_), w(w_) {}

  bool operator<(const edge &b);
  bool operator>(const edge &b);
};

bool all_true(bool* a, int l);
vector<edge> Kruskal(vector< vector< int > >);
vector<edge> Prim(vector< vector< int > >);

#endif  // INCLUDE_ALGS_H_

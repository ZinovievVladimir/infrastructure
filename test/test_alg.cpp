#include <gtest/gtest.h>
#include <vector>
#include <utility>
#include "alg.h"

using std::vector;
using std::pair;
using std::make_pair;

//взял пример с пары

vector< vector< std::pair< int, int > > > CreateTestGraph() {
  vector< vector< std::pair< int, int > > > test(7);
  auto it = test.begin();
  it->push_back(make_pair(4, 1));
  it->push_back(make_pair(6, 2));
  it++;
  it->push_back(make_pair(1, 3));
  it++;
  it->push_back(make_pair(3, 3));
  it->push_back(make_pair(2, 4));
  it++;
  it->push_back(make_pair(1, 5));
  it++;
  it->push_back(make_pair(4, 6));
  it->push_back(make_pair(1, 5));
  it++;
  it->push_back(make_pair(2, 6));
  return test;
}

TEST(Dijkstra, WorkAlg1) {
  auto gr = CreateTestGraph();
  vector<int> TrueWays = { 0,  4, 6, 5, 8, 6, 8 };

  vector<int> ways = alg(gr, 0);

  EXPECT_EQ(ways, TrueWays);
}

TEST(Dijkstra, OneVertex) {
  vector < vector < pair<int, int> > > gr(1);
  vector <int> res = alg(gr, 0);
  EXPECT_EQ(res[0], 0);
}

TEST(Dijkstra, IncorrectVertex) {
  vector < vector < pair<int, int> > > gr1;
  EXPECT_ANY_THROW(alg(gr1, 1));
  vector < vector < pair<int, int> > > gr2(7);
  EXPECT_ANY_THROW(alg(gr2, 8));
}

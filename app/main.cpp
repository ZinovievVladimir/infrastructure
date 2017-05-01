#include <vector>
#include "Algs.h"
#include <stdio.h>

using std::vector;

int main() {
  int c;
  printf("1 - Kruskal\n2 - Prim\n");
  scanf("%d", &c);

  printf("path to file: ");
  char path[150];
  scanf("%s", path);
  FILE* fp = fopen(path, "r");

  if (fp == 0) {
    printf("Error open file\n");
    return 0;
  }

  vector< vector < int > > graph;

  int ch = 0;
  vector<int>* v = new vector<int>;

  while ((ch = fgetc(fp)) != EOF) {
    if (ch != ' ') {
      if (ch == '\n') {
        graph.push_back(*v);
        v = new vector<int>;
      } else {
        v->push_back(ch - 48);
      }
    }
  }
  graph.push_back(*v);
  fclose(fp);

  vector< edge > res;
  switch (c) {
  case 1:
    res = Kruskal(graph);
    break;
  case 2:
    res = Prim(graph);
  }

  printf("Graph is saved in graph.gv on the desktop.\n");

  return 0;
}

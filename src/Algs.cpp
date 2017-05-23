#include <vector>
#include <algorithm>
#include <iostream>
#include "Algs.h"
#include "UF.h"
#include "heap2.h"



bool edge::operator<(const edge &b) {
  return (this->w < b.w);
}

bool edge::operator>(const edge &b) {
  return (this->w > b.w);
}


bool all_true(bool* a, int l) {
  for (int i = 0; i < l; i++)
    if (a[i] == false) {
      return false;
    }
  return true;
}

void graph_to_gv(vector< edge > graph, vector< edge > ost) {
  FILE* fp = fopen("graph.gv", "w");

  vector< edge > graph2;
  bool flag;
  for (auto it = graph.begin(); it < graph.end(); it++) {
    flag = false;
    for (auto it1 = ost.begin(); it1 < ost.end(); it1++) {
      if (((*it).f == (*it1).f) && ((*it).s == (*it1).s)) {
        flag = true;
        break;
      }
    }
    if (!flag) {
      graph2.push_back(*it);
    }
  }

  fprintf(fp, "graph ostov {\n");
  fprintf(fp, "\tnode[shape=circle];\n");
  fprintf(fp, "\tedge[color=red];\n");

  for (auto it = ost.begin(); it < ost.end(); it++) {
    fprintf(fp, "\tedge[label=%d];\n", (*it).w);
    fprintf(fp, "\t%d -- %d;\n", (*it).f, (*it).s);
  }

  fprintf(fp, "\tedge[color=black,style=dashed];\n");


  for (auto it = graph2.begin(); it < graph2.end(); it++) {
    fprintf(fp, "\tedge[label=%d];\n", (*it).w);
    fprintf(fp, "\t%d -- %d;\n", (*it).f, (*it).s);
  }

  fprintf(fp, "}");

  fclose(fp);
}

vector< edge > MI_to_graph(vector< vector < int > > graph) {
  vector< edge > gr;
  for (auto it = graph.begin(); it < graph.end(); it++) {
    int j = 0;

    while ((*it)[j] == 0)
      j++;
    int f = j;
    j++;
    while ((*it)[j] == 0)
      j++;
    int s = j;

    gr.push_back(edge(f, s, (*it)[j]));
  }
  return gr;
}

vector< edge > LS_to_graph(vector< vector < int > > list) {
  vector<edge> gr;

  for (auto it = list.begin(); it < list.end(); it++) {
    gr.push_back(edge((*it)[0], (*it)[1], (*it)[2]));
  }
  return gr;
}

vector<edge> Kruskal(vector<edge> gr) {
  vector<edge> ret;

  if (gr.size() == 0)
    throw std::logic_error("vector is 0-size");

  std::sort(gr.begin(), gr.end());
  vector<edge> tmp(gr);

  UF unions(gr.size());
  edge min;

  while (!unions.all_in_one() && !gr.empty()) {
    min = gr[0];
    gr.erase(gr.begin());

    if (unions.Find(min.f) != unions.Find(min.s)) {
      unions.Union(min.f, min.s);

      ret.push_back(min);
    }
  }

  return ret;
}

vector<edge> Prim(vector< edge > gr) {
  vector<edge> ret;

  if (gr.size() == 0)
    throw std::logic_error("vector is 0-size");

  heap2<edge> h;

  for (auto it = gr.begin(); it < gr.end(); it++)
    if ((*it).f == 0 || (*it).s == 0) {
      h.add(*it);
    }

  int size = gr.size();

  bool *vrtx = new bool[size];

  for (int i = 0; i < size; i++)
    vrtx[i] = false;

  while (!all_true(vrtx, size) && !h.empty()) {
    edge min = h.min();
    h.delmin();

    if (!vrtx[min.f] || !vrtx[min.s]) {
      if (!vrtx[min.f]) {
        for (auto it = gr.begin(); it < gr.end(); it++)
          if ((*it).f == min.f || (*it).s == min.f) {
            h.add(*it);
          }
        vrtx[min.f] = true;
      }

      if (!vrtx[min.s]) {
        for (auto it = gr.begin(); it < gr.end(); it++)
          if ((*it).f == min.s || (*it).s == min.s) {
            h.add(*it);
          }
        vrtx[min.s] = true;
      }

      ret.push_back(min);
    }
  }

  return ret;
}

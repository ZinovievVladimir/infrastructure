#include "UF.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define n 6
#define m 6

int main() {
  bool** island = new bool*[n];
  for (int i = 0; i < n; i++)
    island[i] = new bool[m];

  srand(time(0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (rand() % 2 == 0) {
        island[i][j] = false;
      } else {
        island[i][j] = true;
      }
      std::cout << island[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  isl(island, n, m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << island[i][j] << ' ';
    }
    std::cout << std::endl;
  }

  std::cout << std::endl;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (rand() % 2 == 0) {
        island[i][j] = false;
      } else {
        island[i][j] = true;
      }
      std::cout << island[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  isl_sh(island, n, m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << island[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}

#include "perc.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#define n 10

int main() {
  srand(time(NULL));
  std::vector<double> v;
  bool** arr = new bool*[n];
  for (int i = 0; i < n; i++) {
    arr[i] = new bool[n];
    for (int j = 0; j < n; j++)
      arr[i][j] = false;
  }

  int k = 0;

  double ret;
  while (k < 30000) {
    ret = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        arr[i][j] = false;

    int a = rand() % n, b = rand() % n;
    arr[a][b] = true;

    double count = 1;
    while (!perc(arr, n)) {
      do {
        a = rand() % n;
        b = rand() % n;
      } while (arr[a][b] == true);
      arr[a][b] = true;
      count++;
    }

    count /= n * n;
    v.push_back(count);
    k++;
    for (int i = 0; i < k; i++)
      ret += v[i];
    std::cout << ret / k << std::endl;
  }
  return 0;
}

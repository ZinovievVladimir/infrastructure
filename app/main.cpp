#include "perc.h"
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#define n 10

int main() {
  std::mt19937 gen(time(0));
  std::uniform_int_distribution<> uid(0, n - 1);

  std::vector<double> v;
  bool** arr = new bool*[n];
  for (int i = 0; i < n; i++) {
    arr[i] = new bool[n];
    for (int j = 0; j < n; j++)
      arr[i][j] = false;
  }

  int k = 0;
  double tmp = 0;

  double ret = 10;
  while (k < 30000) {
   // tmp = ret;
    ret = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        arr[i][j] = false;

    int a, b;

    double count = 1;
    while (!perc(arr, n)) {
      do {
        a = uid(gen);
        b = uid(gen);
      } while (arr[a][b] == true);
      arr[a][b] = true;
      count++;
      /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
      }
      std::cout << std::endl;*/
    }

    

    count /= n * n;
    v.push_back(count);
    k++;
    for (int i = 0; i < k; i++)
      ret += v[i];
    ret /= k;
    
  }
  std::cout << ret << std::endl;
  return 0;
}

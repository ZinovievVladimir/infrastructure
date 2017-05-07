#include <iostream>
#include <queue>

using std::queue;

int Find(int* mas, int pos) {
  pos = mas[pos];
  while (pos != mas[pos]) {
    pos = mas[pos];
  }
  return pos;
}

void Union(int* mas, int* len, int a, int b) {
  a = Find(mas, a);
  b = Find(mas, b);
  if (len[a] > len[b]) {
    len[a] += 1;
    mas[b] = mas[a];
  } else {
    len[b] += 1;
    mas[a] = mas[b];
  }
}

void isl(bool** arr, int n, int m) {
  int size = (n + 2)*(m + 2);

  bool** newmas = new bool*[n+2];
  for (int i = 0; i < n + 2; i++)
    newmas[i] = new bool[m + 2];


  for (int i = 0; i < n + 2; i++)
    for (int j = 0; j < m + 2; j++)
      newmas[i][j] = true;

  for (int i = 0; i < n ; i++)
    for (int j = 0; j < m; j++)
      newmas[i + 1][j + 1] = arr[i][j];

  /*for (int i = 0; i < n + 2; i++) {
    for (int j = 0; j < m + 2; j++)
      std::cout << newmas[i][j] << ' ';
    std::cout << std::endl;
  }*/


  int* mas = new int[size];
  int* len = new int[size];
  for (int i = 0; i < size; i++) {
    mas[i] = i;
    len[i] = 1;
  }

  for (int i = 0; i < n + 2; i++) {
    mas[i] = 0;
    mas[(n + 2)*(m + 2) - (n + 2) + i] = 0;
  }

  for (int i = 0; i < m + 2; i++) {
    mas[(n + 2)*i] = 0;
    mas[(n + 1)*i] = 0;
  }

  for (int i = 0; i < n + 2; i++) {
    for (int j = 0; j < m + 2; j++) {
      if (newmas[i][j] == true) {
        if (i != 0) {
          if (newmas[i - 1][j] == true) {
            Union(mas, len, (i - 1) * (n + 2) + j, i * (n + 2) + j);
          }
        }
        if (j != 0) {
          if (newmas[i][j - 1] == true) {
            Union(mas, len, i * (n + 2) + j - 1, i * (n + 2) + j);
          }
        }
        if (i != n + 1) {
          if (newmas[i + 1][j] == true) {
            Union(mas, len, (i + 1) * (n + 2) + j, i * (n + 2) + j);
          }
        }
        if (j != n + 1) {
          if (newmas[i][j + 1] == true) {
            Union(mas, len, i * (n + 2) + j + 1, i * (n + 2) + j);
          }
        }
      }
    }
  }

  /*for (int i = 0; i < n + 2; i++) {
    for (int j = 0; j < m + 2; j++)
      std::cout << Find(mas , i*(n + 2) + j) << ' ';
    std::cout << std::endl;
  }

  std::cout << std::endl;*/

  for (int i = 0; i < n + 2; i++)
    for (int j = 0; j < m + 2; j++)
      if (Find(mas, i*(n + 2) + j) != Find(mas, 0)) {
        arr[i - 1][j - 1] = 0;
      }

  delete[] mas;
  delete[] len;
}


void FillAround(bool **a, int **B, int m, int n, int cura, int curb,
  queue< std::pair<int, int> > q) {
  if (cura + 1 < m) {
    if ((a[cura + 1][curb] == true) && (B[cura + 1][curb] == 0)) {
      B[cura + 1][curb] = 1;
      q.push(std::pair<int, int>(cura + 1, curb));
    }
  }
  if (curb + 1 < n) {
    if ((a[cura][curb + 1] == true) && (B[cura][curb + 1] == 0)) {
      B[cura][curb + 1] = 1;
      q.push(std::pair<int, int>(cura, curb + 1));
    }
  }

  if (cura > 0) {
    if ((a[cura - 1][curb] == true) && (B[cura - 1][curb] == 0)) {
      B[cura - 1][curb] = 1;
      q.push(std::pair<int, int>(cura - 1, curb));
    }
  }

  if (curb > 0) {
    if ((a[cura][curb - 1] == true) && (B[cura][curb - 1] == 0)) {
      B[cura][curb - 1] = 1;
      q.push(std::pair<int, int>(cura, curb - 1));
    }
  }
}

void isl_sh(bool** arr, int n, int m) {
  queue< std::pair< int, int > > q;

  bool** newmas = new bool*[n + 2];
  for (int i = 0; i < n + 2; i++)
    newmas[i] = new bool[m + 2];

  for (int i = 0; i < n + 2; i++)
    for (int j = 0; j < m + 2; j++)
      newmas[i][j] = true;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      newmas[i + 1][j + 1] = arr[i][j];

  int** mas12 = new int*[n + 2];
  for (int i = 0; i < n + 2; i++)
    mas12[i] = new int[m + 2];

  for (int i = 0; i < n + 2; i++)
    for (int j = 0; j < m + 2; j++)
      mas12[i][j] = 0;

  mas12[0][0] = 1;
  q.push(std::pair<int, int>(0, 0));
  while (!q.empty()) {
    int i = q.front().first;
    int j = q.front().second;
    q.pop();
    FillAround(newmas, mas12, n + 2, m + 2, i, j, q);
  }

  for (int i = 0; i < n + 2; i++) {
    for (int j = 0; j < m + 2; j++) {
      std::cout << mas12[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  for (int i = 0; i < n + 2; i++)
    for (int j = 0; j < m + 2; j++)
      if (mas12[i][j] == 0)
        arr[i - 1][j - 1] = 0;
}

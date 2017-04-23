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

bool perc(bool** arr, int n) {
  int* mas = new int[n*n];
  int* len = new int[n*n];
  for (int i = 0; i < n*n; i++) {
    mas[i] = i;
    len[i] = 1;
  }

  for (int i = 0; i < n; i++) {
    mas[i] = 0;
    mas[n*n - n + i] = n*n - n;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != 0) {
        if (arr[i - 1][j] == true) {
          Union(mas, len, (i - 1) * n + j, i * n + j);
        }
      }
      if (j != 0) {
        if (arr[i][j - 1] == true) {
          Union(mas, len, i * n + j - 1, i * n + j);
        }
      }
      if (i != n - 1) {
        if (arr[i + 1][j] == true) {
          Union(mas, len, (i + 1) * n + j, i * n + j);
        }
      }
      if (j != n - 1) {
        if (arr[i][j + 1] == true) {
          Union(mas, len, i * n + j + 1, i * n + j);
        }
      }
      if (Find(mas, 0) == Find(mas, n*n - n)) {
        delete[] mas;
        delete[] len;
        return true;
      }
    }
  }
  delete[] mas;
  delete[] len;
  return false;
}

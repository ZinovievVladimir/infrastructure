char* min_way(int x, int y) {
  char* b = new char[100];

  int i = 1, k = 0, l = 0;

  if (x > 0) {
    while (k + i < x) {
      k = k + i;
      b[i - 1] = 'E';
      i++;
    }
  } else {
    if (x < 0) {
      while (k - i > x) {
        k = k - i;
        b[i - 1] = 'W';
        i++;
      }
    }
  }

  if (y > 0) {
    while (l + i < y) {
      l = l + i;
      b[i - 1] = 'N';
      i++;
    }
  } else {
    if (y < 0) {
      while (l - i > y) {
        l = l - i;
        b[i - 1] = 'S';
        i++;
      }
    }
  }

  if (x > 0) {
    while (k != x) {
      k = k - i;
      b[i - 1] = 'W';
      i++;
      k = k + i;
      b[i - 1] = 'E';
      i++;
    }
  } else {
    if (x < 0) {
      while (k != x) {
        k = k + i;
        b[i - 1] = 'E';
        i++;
        k = k - i;
        b[i - 1] = 'W';
        i++;
      }
    }
  }
  if (y > 0) {
    while (l != y) {
      l = l - i;
      b[i - 1] = 'S';
      i++;
      l = l + i;
      b[i - 1] = 'N';
      i++;
    }
  } else {
    if (y < 0) {
      while (l != y) {
        l = l + i;
        b[i - 1] = 'N';
        i++;
        l = l - i;
        b[i - 1] = 'S';
        i++;
      }
    }
  }

  b[i - 1] = 0;

  return b;
}

int* multip(int* a, int l) {
  if ((l == 0) || (a == nullptr))
    return nullptr;

  int* b = new int[l];
  int c = 1;

  for (int i = 0; i < l; i++) {
    b[i] = c;
    c *= a[i];
  }

  c = 1;
  for (int i = l - 1; i > -1; i--) {
    b[i] *= c;
    c *= a[i];
  }

  return b;
}

#ifndef INCLUDE_UF_H_
#define INCLUDE_UF_H_

class UF {
  int* arr;
  int* len;
  int size;
 public:
  explicit UF(int s = 0) {
    arr = new int[s];
    for (int i = 0; i < s; i++)
      arr[i] = i;
    len = new int[s];
    for (int i = 0; i < s; i++)
      len[i] = 1;
    size = s;
  }
  int Find(int a);
  void Union(int a, int b);
  bool all_in_one();
  ~UF() {
    delete[] arr;
  }
};

#endif  // INCLUDE_UF_H_

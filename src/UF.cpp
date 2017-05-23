#include "UF.h"
#include "stdexcept"

int UF::Find(int a) {
  if ((a < 0) || (a - 1) > size) {
    throw std::logic_error("position <0");
  } else {
    a = arr[a];
    while (a != arr[a]) {
      a = arr[a];
    }
    return a;
  }
}

void UF::Union(int a, int b) {
  if ((a < 0) || (b < 0) ||
    (a - 1 > size) || (b - 1 > size)) {
    throw std::logic_error("position <=0");
  } else {
    a = Find(a);
    b = Find(b);
    if (len[a] > len[b]) {
      len[a] += 1;
      arr[b] = arr[a];
    } else {
      len[b] += 1;
      arr[a] = arr[b];
    }
  }
}

bool UF::all_in_one() {
  int f = Find(arr[0]);
  for (int i = 0; i < size; i++)
    if (Find(arr[i]) != f)
      return false;
  return true;
}

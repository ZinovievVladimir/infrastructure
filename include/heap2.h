#ifndef INCLUDE_HEAP2_H_
#define INCLUDE_HEAP2_H_
#include <vector>
#include <stdexcept>

using std::vector;
using std::pair;

template <typename T>
class heap2 {
  vector<T> head;
  void shift_up(int a);
  void shift_down(int b);

 public:
  T min();
  void add(T);
  void delmin();
  bool empty();
};

template <typename T>
bool heap2<T>::empty() {
  return head.empty();
}

template <typename T>
void heap2<T>::add(T pr) {
  head.push_back(pr);
  shift_up(head.size() - 1);
}

template <typename T>
T heap2<T>::min() {
  if (!head.empty())
    return head[0];
  else
    throw std::logic_error("Heap is empty!");
}

template <typename T>
void heap2<T>::delmin() {
  if (!head.empty()) {
    head[0] = head[head.size() - 1];
    head.erase(head.end() - 1);
    shift_down(0);
  } else {
    throw std::logic_error("Heap is empty!");
  }
}

template <typename T>
void heap2<T>::shift_up(int pos) {
  int pospar = (pos - 1) / 2;
  while (head[pospar] > head[pos]) {
    std::swap(head[pospar], head[pos]);

    pos = pospar;
    pospar = (pospar - 1) / 2;
  }
}

template <typename T>
void heap2<T>::shift_down(int pos) {
  int end = head.size();
  int fc = 2 * pos + 1, sc = 2 * pos + 2;
  while (fc < end) {
    int posmin = fc;
    if (sc < end)
      if (head[sc] < head[fc])
        posmin = sc;
    std::swap(head[pos], head[posmin]);
    pos = posmin;
    fc = 2 * pos + 1;
    sc = 2 * pos + 2;
  }
}
#endif  // INCLUDE_HEAP2_H_

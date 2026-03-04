#include <iostream>

template< class T >
struct BiList {
  T val;
  BiList< T > * next;
  BiList< T > * prev;
};

template< class T >
BiList< T > * getTail(BiList< T > * h)
{
  while (h->next) {
    h = h->next;
  }
  return h;
}

template< class T >
BiList< T > * add(BiList< T > * h, const T & d)
{
  BiList< T > * prev = h->prev;
  BiList< T > * r = new BiList< T > {d, h, prev};
  h->prev = r;
  if (prev) {
    prev->next = r;
  }
  return r;
}

template< class T >
BiList< T > * insert(BiList< T > * h, const T & d)
{
  BiList< T > * next = h->next;
  BiList< T > * r = new BiList< T > {d, next, h};
  h->next = r;
  if (next) {
    next->prev = r;
  }
  return r;
}

template< class T >
BiList< T > * cut(BiList< T > * h) noexcept
{
  BiList< T > * next = h->next;
  BiList< T > * prev = h->prev;
  if (prev) {
    prev->next = next;
  }
  if (next) {
    next->prev = prev;
  }
  delete h;
  if (next) {
    return next;
  }
  return prev;
}

template< class T >
BiList< T > * eraseAfter(BiList< T > * h) noexcept
{
  if (h->next) {
    cut(h->next);
  }
  return h;
}

template< class T >
BiList< T > * eraseBefore(BiList< T > * h) noexcept
{
  if (h->prev) {
    cut(h->prev);
  }
  return h;
}

template< class T >
BiList< T > * clear(BiList< T > * h, BiList< T > * e) noexcept
{
  while (h != e) {
    h = cut(h);
  }
  return h;
}

template< class T, class F >
F traverse(F f, BiList< T > * h, BiList< T > * e)
{
  while (h != e) {
    f(h->val);
    h = h->next;
  }
  return f;
}

template< class T, class F >
F traverseRevers(F f, BiList< T > * h, BiList< T > * e)
{
  while (h != e) {
    f(h->val);
    h = h->prev;
  }
  return f;
}

template< class T >
BiList< T > * convert(const T * data, size_t size)
{
  BiList< T > * h = new BiList< T > {data[0], nullptr, nullptr};
  BiList< T > * temp = h;
  try {
    for (size_t i = 1; i < size; ++i) {
      temp = insert(temp, data[i]);
    }
  } catch (...) {
    BiList<T>* null_ptr = nullptr;
    clear(h, null_ptr);
    throw;
  }
  return h;
}

void printInt(int num)
{
  std::cout << num << " ";
}

template< int K >
void multiply(int & num)
{
  num *= K;
}

int main()
{
  constexpr size_t size = 5;
  int array[size] = {1, 2, 3, 4, 5};
  BiList< int > * list = convert(array, size);
  BiList<int>* null_ptr = nullptr;
  traverse(printInt, list, null_ptr);
  std::cout << "\n";
  traverse(multiply< 2 >, list, null_ptr);
  traverseRevers(printInt, getTail(list), null_ptr);
  std::cout << "\n";
  clear(list, null_ptr);
}
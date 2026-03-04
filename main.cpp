#include <iostream>

template< class T >
struct BiList {
  T val;
  BiList< T > * next;
  BiList< T > * prev;
};

template< class T >
BiList< T > * add(BiList< T > * h, const T & d)
{
  BiList< T > * p = h->prev;
  BiList< T > * r = new BiList< T > {d, h, p};
  h->prev = r;
  if (p) {
    p->next = r;
  }
  return r;
}

template< class T >
BiList< T > * insert(BiList< T > * h, const T & d)
{
  BiList< T > * n = h->prev;
  BiList< T > * r = new BiList< T > {d, n, h};
  h->next = r;
  if (n) {
    n->prev = r;
  }
  return r;
}

template< class T >
BiList< T > * cut(BiList< T > * h) noexcept;

template< class T >
BiList< T > * eraseAfter(BiList< T > * h) noexcept;

template< class T >
BiList< T > * eraseBefore(BiList< T > * h) noexcept;

template< class T >
BiList< T > * clear(BiList< T > * h, BiList< T > * e) noexcept;

template< class T, class F >
F traverse(F f, BiList< T > * h, BiList< T > * e);

template< class T, class F >
F traverseRevers(F f, BiList< T > * h, BiList< T > * e);

int main()
{
  std::cout << "\n";
}
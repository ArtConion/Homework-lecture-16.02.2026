#include <iostream>

template< class T > struct BiListNode
{
  T val;
  BiListNode< T >* next;
  BiListNode< T >* prev;

  BiListNode(const T& value = T(), BiListNode<T>* n = nullptr, BiListNode<T>* p = nullptr):
    val(value),
    next(n),
    prev(p)
  {}
};
template< class T > struct BiList
{
  BiListNode< T >* fake;

  BiList()
  {
    fake = new BiListNode<T>();
    fake->next = fake;
    fake->prev = fake;
  }
};
template< class T > BiListNode< T >* add(BiListNode< T > node, const T& v)
{
  BiListNode< T >* newNode = new BiListNode< T >(v);

  newNode->prev = node->prev;
  newNode->next = node;

  node->prev->next = newNode;
  node->prev = newNode;

  return newNode;
}
template< class T > BiList< T > insert(BiListNode< T > node, const T& v)
{
  BiListNode< T >* newNode = new BiListNode< T >(v);

  newNode->next = node->next;
  newNode->prev = node;

  node->next->prev = newNode;
  node->next = newNode;

  if (newNode->next == node)
  {
    node->prev = newNode;
  }

  return newNode;
}

template< class T > BiListNode< T >* cut(BiListNode< T >* node)
{
  BiListNode< T > newHead = node->next;

  newHead->prev = node->prev;
  node->prev->next = newHead;

  delete node;

  return newHead;
}
template< class T > BiListNode< T >* erase(BiListNode< T >* node)
{
  BiListNode< T > newTail = node->prev;

  newTail->next = node->next;
  node->next->prev = newTail;

  delete node;

  return newTail;
}
template< class T > void clear(BiList< T >* pseudoknot)
{
  while(pseudoknot->fake->next != pseudoknot->fake)
  {
    BiListNode< T > tmp = pseudoknot->fake->next;
    pseudoknot->fake->next = pseudoknot->fake->next->next;
    delete t;
  }
}
template< class T, class F > F traverse(F f, BiList< T > pseudoknot)
{
  BiListNode< T > node = pseudoknot->fake->next;
  for(; node != pseudoknot->fake; node = node->next)
  {
    f(node->val)
  }
  return f;
}
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
    fake = new BiListNode<T>(); // Конструктор
    fake->next = fake; // Копирующий конструктор
    fake->prev = fake; // Копирующий конструктор
  }
};

template< class T > BiListNode< T >* add(BiListNode< T > node, const T& v)
{
  BiListNode< T >* newNode = new BiListNode< T >(v); // Конструктор

  newNode->prev = node->prev; // Копирующий конструктор
  newNode->next = node; // Копирующий конструктор

  node->prev->next = newNode; // Копирующий конструктор
  node->prev = newNode; // Копирующий конструктор

  return newNode;
}

template< class T > BiList< T > insert(BiListNode< T > node, const T& v)
{
  BiListNode< T >* newNode = new BiListNode< T >(v); // Конструктор

  newNode->next = node->next; // Копирующий конструктор
  newNode->prev = node; // Копирующий конструктор

  node->next->prev = newNode; // Копирующий конструктор
  node->next = newNode; // Копирующий конструктор

  if (newNode->next == node)
  {
    node->prev = newNode; // Копирующий конструктор
  }

  return newNode;
}

template< class T > BiListNode< T >* cut(BiListNode< T >* node)
{
  BiListNode< T > newHead = node->next; // Копирующий конструктор

  newHead->prev = node->prev; // Копирующий конструктор
  node->prev->next = newHead; // Копирующий конструктор

  delete node; // Деструктор

  return newHead;
}

template< class T > BiListNode< T >* erase(BiListNode< T >* node)
{
  BiListNode< T > newTail = node->prev; // Копирующий конструктор

  newTail->next = node->next; // Копирующий конструктор
  node->next->prev = newTail; // Копирующий конструктор

  delete node; // Деструктор

  return newTail;
}

template< class T > void clear(BiList< T >* pseudoknot)
{
  while(pseudoknot->fake->next != pseudoknot->fake)
  {
    BiListNode< T > tmp = pseudoknot->fake->next; // Копирующий конструктор
    pseudoknot->fake->next = pseudoknot->fake->next->next; // Копирующий конструктор
    delete t; // Деструктор
  }
}

template< class T, class F > F traverse(F f, BiList< T > pseudoknot)
{
  BiListNode< T > node = pseudoknot->fake->next; // Копирующий конструктор
  for(; node != pseudoknot->fake; node = node->next)
  {
    f(node->val) // Оператор присваивания
  }
  return f;
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  size_t size = 5;

  BiList< int >* pseudoknot; // Конструктор
  BiListNode< int >* node; // Конструктор

  pseudoknot->fake->next = node; // Копирующий конструктор
  pseudoknot->fake->prev = node; // Копирующий конструктор

  node->val = arr[0]; // Оператор присваивания
  node->next = pseudoknot->fake; // Копирующий конструктор
  node->prev = pseudoknot->fake; // Копирующий конструктор

  for (size_t i = 1; i < size; ++i)
  {
    BiListNode< int >* newNode; // Конструктор

    newNode->val = arr[i]; // Оператор присваивания
    newNode->prev = node; // Копирующий конструктор
    newNode->next = pseudoknot->fake; // Копирующий конструктор

    node->next = newNode; // Копирующий конструктор

    node = newNode; // Копирующий конструктор
  }
  clear(pseudoknot); // Деструктор
  return 0;
}
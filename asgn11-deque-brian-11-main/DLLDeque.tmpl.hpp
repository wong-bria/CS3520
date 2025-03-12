// iterator functions

template<typename T>
DLLDeque<T>::iterator::iterator(IterPtr n)
{
  //(void) n; // TODO
  m_node = n;
}

template<typename T>
DLLDeque<T>::iterator::iterator(const iterator & it)
{
  //(void) it; // TODO
  m_node = it.m_node;
}

template<typename T>
typename DLLDeque<T>::iterator &
DLLDeque<T>::iterator::operator++()
{
  //return *this; // TODO
  if (m_node) {
    m_node = m_node->next; // move to next node
  }
  return *this;
}

template<typename T>
typename DLLDeque<T>::iterator
DLLDeque<T>::iterator::operator++(int)
{
  //return *this; // TODO
  iterator temp = *this; // store current state
  if (m_node) {
    m_node = m_node->next;
  } 
  return temp;
}

template<typename T>
T &
DLLDeque<T>::iterator::operator*()
{
  return m_node->item;
}

template<typename T>
bool
DLLDeque<T>::iterator::operator==(const iterator & it)
{
  //(void) it; return false; // TODO
  return m_node == it.m_node;
}

template<typename T>
bool
DLLDeque<T>::iterator::operator!=(const iterator & it)
{
  //(void) it; return false; // TODO
  return m_node != it.m_node;
}



// deque functions

template<typename T>
void
DLLDeque<T>::push_front(const T & t)
{
  //(void) t; // TODO: allocate a new node and add it to the front of the list
  auto new_node = std::make_shared<Node>();
  new_node->item = t;
  new_node->next = m_head;
  new_node->prev.reset();

  if (m_head) {
    m_head->prev = new_node;
  } else {
    m_tail = new_node;
  }
  m_head = new_node;
}

template<typename T>
void
DLLDeque<T>::push_back(const T & t)
{
  //(void) t; // TODO: allocate a new node and add it to the back of the list
  auto new_node = std::make_shared<Node>();
  new_node->item = t;
  new_node->prev = m_tail;
  new_node->next.reset();

  if (m_tail) {
    m_tail->next = new_node;
  } else {
    m_head = new_node;
  }
  m_tail = new_node;
}

template<typename T>
void
DLLDeque<T>::pop_front()
{
  // TODO: remove front node from the list
  if (m_head) {
    m_head = m_head->next;
    if (m_head) {
      m_head->prev.reset();
    } else {
      m_tail.reset();
    }
  }
}

template<typename T>
void
DLLDeque<T>::pop_back()
{
  // TODO: remove back node from the list
  if (m_tail) {
    m_tail = m_tail->prev.lock();
    if (m_tail) {
      m_tail->next.reset();
    } else {
      m_head.reset();
    }
  }
}

template<typename T>
typename DLLDeque<T>::iterator
DLLDeque<T>::begin()
{
  return iterator(m_head);
}

template<typename T>
typename DLLDeque<T>::iterator
DLLDeque<T>::end()
{
  return iterator(nullptr);
}

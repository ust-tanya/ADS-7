// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
 private:
  struct ITEM {
  T data;
  ITEM* prev, * next;
  };
  ITEM* head, * tail, * val;
  TPQueue::ITEM* create(const T& data) {
  ITEM* indx = new ITEM;
  indx->data = data;
  indx->next = nullptr;
  indx->prev = nullptr;
  return indx;
  }

 public:
  TPQueue() {
  head = tail = val = nullptr;
  }
  ~TPQueue() {
  while (head)
  pop();
  }
  T getNext() {
  if (tail && head) {
  if (!val)
  val = head;
  else if (val->next)
  val = val->next;
  else
  throw std::string("Out error");
  return val->data;
  } else {
  throw std::string("Out error");
  }
  }
  T pop() {
  if (tail && head) {
  ITEM* temp = head->next;
  if (temp)
  temp->prev = nullptr;
  T data = head->data;
  delete head;
  head = temp;
  if (!head)
  tail = nullptr;
  return data;
  } else {
  throw std::string("Out error");
  }
  }
  void push(const T& data) {
  ITEM* temp = head;
  ITEM* indx = create(data);
  while (temp && temp->data.prior >= data.prior)
  temp = temp->next;
  if (!temp && head) {
  tail->next = indx;
  indx->prev = tail;
  tail = indx;
  } else if (!temp && !head) {
  head = tail = indx;
  } else if (!temp->prev) {
  head->prev = indx;
  indx->next = head;
  head = indx;
  } else {
  temp->prev->next = indx;
  indx->prev = temp->prev;
  indx->next = temp;
  temp->prev = indx;
  }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif // INCLUDE_TPQUEUE_H_

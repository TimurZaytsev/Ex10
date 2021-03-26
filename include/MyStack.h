// Copyright 2021 TimurZaytsev

#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template <class T>
class MyStack {
 private:
  T* arr;
  int length, pos = 0;

 public:
  explicit MyStack(int length) {
    arr = new T[length];
    this->length = length;
  }

  MyStack(const MyStack& s) {
    this->arr = new T[s.length];
    for (int i = 0; i < s.length; ++i) {
      this->arr[i] = s.arr[i];
    }
    this->length = s.length;
    this->pos = s.pos;
  }

  ~MyStack() { delete[] arr; }

  T get() const { return arr[pos - 1]; }

  T pop() {
    if (isEmpty()) {
      throw "Stack is empty!";
    } else {
      return arr[--pos];
    }
  }

  void push(T x) {
    if (isFull()) {
      throw "Stack is full!";
    } else {
      arr[pos] = x;
      pos++;
    }
  }

  bool isFull() const {
    if (pos == length) {
      return true;
    }
    return false;
  }

  bool isEmpty() const {
    if (pos == 0) {
      return true;
    }
    return false;
  }
};

#endif  // INCLUDE_MYSTACK_H_

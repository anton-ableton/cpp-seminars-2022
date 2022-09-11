#include <iostream>
#include <cstdlib>

using namespace std;

class vector {
public:
  int *data;
  int size;
  int capacity;

  vector(int capacity) {
    this->capacity = capacity;
    this->size = size;
    this->data = new int[capacity]();
  }

  ~vector() { delete[] data; }

  // adds element to the last avaialable position,
  // resizes vector if current capacity is reached
  void push_back(int num) {
    if (this->size == this->capacity) this->resize(capacity * 2);
    this->data[size + 1] = num;
  }
  // resizes vector to given capacity
  void resize(int new_capacity) {
    this->capacity = new_capacity;
    int* new_data = new int[new_capacity]();
    for (int i = 0; i < capacity; i++) {
      new_data[i] = data[i];
    }
    delete[] this->data;
    this->data = new_data;
  }

  int get_size() { return this->size; }

  void set(int num, int idx);
  int at(int idx);
};

int main(int argc, char **argv) {
  vector *v = new vector(4);
  v->resize(5);
  cout << v->capacity << endl;
  v->push_back(100);
  
  // v->push_back(200);
  // v->push_back(300);
  // v->push_back(400);
  // v->push_back(500);
  // v->push_back(600);
  for (int i = 0; i < v->capacity; i++) cout << v->data[i] << endl;
  delete v;
  // v.size();
  // // size(&v)
  // vector v1;
  // v1.size();
}
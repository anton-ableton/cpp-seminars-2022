#include <iostream>
#include <cstdlib>

using namespace std;

class vector {
public:

  vector(int capacity) {
    this->capacity_ = capacity;
    this->size_ = 0;
    this->data_ = new int[capacity]();
  }

  ~vector() { delete[] data_; }

  // adds element to the last avaialable position,
  // resizes vector if current capacity is reached
  void push_back(int num) {
    if (this->size_ == this->capacity_) this->resize_(capacity_ * 2);
    this->data_[this->size_++] = num;
  }

  vector(vector &other) {
    this->capacity_ = other.capacity_;
    this->size_ = other.size_;
    this->data_ = new int[other.capacity_];
    for (int i=0; i < other.size_; i++) {
        this->data_[i] = other.data_[i];
    }
  }

  vector &operator = (const vector &other) {
    this->capacity_ = other.capacity_;
    this->size_ = other.size_;
    if (this->data_!=nullptr) {
        delete[] this->data_;
    }
    this->data_ = new int[other.capacity_];
    for (int i=0; i < other.size_; i++) {
        this->data_[i] = other.data_[i];
    }
    return *this;
  }

  int &operator [] (size_t index) {
    return data_[index];
  }

  void printVector() {
    cout << "Vector capacity is " << this->capacity_ << endl;
    cout << "Vector size is " << this->size_ << endl;
    for (int i=0; i < this->size_; i++) {
        cout << this->data_[i] << " ";
    }
    cout << endl;
  }
  
  int get_size() { 
    return this->size_; 
  }
  
  void set(int num, int idx) {
    this->operator[](idx) = num;
  }

  int at(int idx) {
    return this->operator[](idx);
  }

private:
  int *data_;
  int size_;
  int capacity_;

  void resize_(int new_capacity) {
    int* new_data = new int[new_capacity]();
    for (int i = 0; i < capacity_; i++) {
      new_data[i] = data_[i];
    }
    this->capacity_ = new_capacity;
    delete[] this->data_;
    this->data_ = new_data;
  }
};


int main(int argc, char **argv) {
  vector *v = new vector(4);
  // v->printVector();
  // v->resize(5);
  // cout << v->capacity << endl;
  v->push_back(100);
  v->push_back(100);
  v->push_back(100);
  v->push_back(100);
  v->push_back(100);
  v->operator[](3) = 5;
  v->printVector();
  cout << v->operator[](3) << " " << endl;
  vector *w = new vector(0); 
  vector *z = v; //copy constructor
  // z->printVector();
  // w->operator=(*v); //or *w = *v
  // w->printVector();
  // v.size();
  // // size(&v)
  // vector v1;
  // v1.size();
  return 0;
}
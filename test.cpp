#include <iostream>
#include <cstdlib>

using namespace std;

class vector {
public:

  vector() {
    cout << "Object:"<< this << " Called Constructor" << endl;
  }
    
  vector(int capacity) {
    cout << "Object:"<< this << " Called Constructor" << endl;
    this->capacity_ = capacity;
    this->size_ = 0;
    this->data_ = new int[capacity]();
  }

  ~vector() { 
    cout << "Object:"<< this << " Called Destructor" << endl;
    // delete[] data_;
  }

  // adds element to the last avaialable position,
  // resizes vector if current capacity is reached
  void push_back(int num) {
    if (this->size_ == this->capacity_) this->resize_(capacity_ * 2);
    this->data_[this->size_++] = num;
  }

  vector(vector &other) {
    cout << "Object:"<< this << " Called Copy Constructor" << endl;
    this->capacity_ = other.capacity_;
    this->size_ = other.size_;
    this->data_ = new int[other.size_];
    for (int i=0; i < other.size_; i++) {
        // this->data_[i] = other.data_[i];
    }
  }

  vector &operator = (const vector &other) {
    this->capacity_ = other.capacity_;
    this->size_ = other.size_;
    if (this->data_!=nullptr) {
        delete[] this->data_;
    }
    this->data_ = new int[other.size_];
    for (int i=0; i < other.size_; i++) {
        this->data_[i] = other.data_[i];
    }
    return *this;
  }
  // resizes vector to given capacity


  void printVector() {
    cout << "Vector capacity is " << this->capacity_ << endl;
    cout << "Vector size is " << this->size_ << endl;
    for (int i=0; i < this->size_; i++) {
        cout << this->data_[i] << " ";
    }
    cout << endl;
  }
  
  int get_size() { return this->size_; }
  void set(int num, int idx);
  int at(int idx);

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
  vector A;
  vector B;
  return 0;
}
#pragma once
#include <cstdint>
#include <iostream>
#include <vector>

#include "interpreter.hpp"
#include "interpreter_error.hpp"
#include <algorithm>
#include <sstream>

class Command {
  public:
    virtual void apply(uint8_t * ptr) = 0;
};

class Right: public Command {
  public:
    void apply(uint8_t * ptr) override {
      ptr++;
    }
};

class Left: public Command {
  public:
    void apply(uint8_t * ptr) override {
      ptr--;
    }
};

class Plus: public Command {
  public:
    void apply(uint8_t * ptr) override {
      *ptr++;
    }
};

class Minus: public Command {
  public:
    void apply(uint8_t * ptr) override {
      *ptr--;
    }
};

class Write: public Command {
  public:
    void apply(uint8_t * ptr) override {
      std::cout << (*ptr) << std::endl;
    }
};

class Read: public Command {
  public:
    void apply(uint8_t * ptr) override {
      int number;
      std::cin >> number;
      *ptr = number;
    }
};

class While: public Command {
  public:
    While(std::vector<Command *> & body): body_(body) {}
    void apply(uint8_t * ptr) override {
      while (*ptr != 0) {
        for (Command * command : body_) {
          command->apply(ptr);
        }
      }
    }
  private:
    std::vector<Command *> body_;
};
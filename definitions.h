#include <string>

struct Payload {
  char c;
  int i;
  char r;
  int y;
  bool b;
  std::string s;
  Payload() : c('c'), i(-1), r('r'), y(-1), b(false), s("string") {
    std::cout << "Payload::Payload()\n";
  }
  Payload(char c, int i, char r, int y, bool b, std::string s)
      : c(c), i(i), r(r), y(y), b(b), s(s) {
        std::cout << "Payload::Payload(char, int, char, int, bool, std::string)\n";
      }
} Str;

struct Widget {
  Widget(int m) : member(m) {}
  ~Widget() {}
  int member;
};

/**
 * @brief Function object to be used by smart pointers
 *
 */
struct Free {
  void operator()(Payload *pyl) {
    free(pyl);
    std::cout << "freed Payload*\n";
  }
};


class Interface {
public:
  Interface() = default;
  virtual ~Interface() = default;
  virtual void baz() const noexcept = 0;
};

class Client1 : public Interface {
public:
  void baz() const noexcept override {
    std::cout << "Client1::baz()\n";
  }
};

class Client2 : public Interface {
public:
  void baz() const noexcept override {
    std::cout << "Client2::baz()\n";
  }
};



class C1{
private:
  //double* d; OLD WAY
  std::shared_ptr<double> d;
public:
  explicit C1(std::shared_ptr<double> value) : d(value) {
    std::cout << "C1 constructor -> ref count : "<< d.use_count() <<"\n";
    }
  virtual ~C1() { std::cout << "\nC1 destructor\n";}
  void print() const { std::cout << "Value " << *d; }
};


class C2{
private:
  //double* d; OLD WAY
  std::shared_ptr<double> d;
public:
  C2(std::shared_ptr<double> value) : d(value) {
    std::cout << "C2 constructor -> ref count : "<< d.use_count() <<"\n";
    }
  virtual ~C2() { std::cout << "\nC2 destructor\n";}
  void print() const { std::cout << "Value " << *d; }
};


struct Base {
  int m_base;
  virtual void display() const {
    std::cout << "Base::Display() => " << m_base << "\n";
  }
  Base() : m_base{-1} {
    std::cout << "Base::Base()\n";
  }
  Base(int j) : m_base{j} {
    std::cout << "Base::Base(int)\n";
  }
};

struct Derived : public Base {
  int m_derived;
  void display() const override {
    std::cout << "Derived::Display() => " << m_derived << "\n";
  }
  Derived() : m_derived{-1} {
    std::cout << "Derived::Derived()\n";
  }
  Derived(int j) : Base(j) { 
    std::cout << "Derived::Derived(int)\n";
    m_base = j;
    m_derived = j;
  }
};
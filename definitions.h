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

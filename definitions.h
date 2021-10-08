#include <string>

struct Payload {
  char c;
  int i;
  char r;
  int y;
  bool b;
  std::string s;
  Payload() : c('c'), i(-1), r('r'), y(-1), b(false), s("string") {}
  Payload(char c, int i, char r, int y, bool b, std::string s)
      : c(c), i(i), r(r), y(y), b(b), s(s) {}
} Str;

struct Widget {
  Widget(int m) : member(m) {}
  ~Widget() {}
  int member;
};

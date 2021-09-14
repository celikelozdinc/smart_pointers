
#include <cstring>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct Payload {
  char c;
  int i;
  char r;
  int y;
  bool b;
  string s;
} Str;

int main() {
  Payload *payload = new Payload{'c', 60, 'r', 90, false, "sex"};
  Payload payloadd{'c', 70, 'r', 90, true, "sex"};
  std::unique_ptr<Payload *> unique = make_unique<Payload *>(payload);
  std::unique_ptr<Payload> uniquePtr =
      make_unique<Payload>(Payload{'o', 17, 'c', 91, true, "sex"});

  size_t sizeOfStruct = sizeof(*uniquePtr.get());
  cout << "Size of *uniquePtr.get() : " << sizeOfStruct << "\n"; // 56
  cout << "=============================================================\n";
  /*
  cout << "uniquePtr -> " << uniquePtr << "\n";                   // 0x126b6c0
  */
  cout << "uniquePtr.get() -> " << uniquePtr.get() << "\n";       // 0x126b6c0
  cout << "sizeof(uniquePtr) -> " << sizeof(uniquePtr) << "\n";   // 8
  cout << "sizeof(*uniquePtr) -> " << sizeof(*uniquePtr) << "\n"; // 56
  cout << "sizeof(uniquePtr.get()) -> " << sizeof(uniquePtr.get()) << "\n"; // 8
  cout << "sizeof(*uniquePtr.get()) -> " << sizeof(*uniquePtr.get())
       << "\n";                                                       // 56
  cout << "(*uniquePtr.get()).i -> " << (*uniquePtr.get()).i << "\n"; // 17
  cout << "(*uniquePtr.get()).s -> " << (*uniquePtr.get()).s << "\n"; // sex
  cout << "=============================================================\n";
  cout << "unique.get() -> " << unique.get() << "\n";       // 0x126bb60
  cout << "*(unique.get()) -> " << *(unique.get()) << "\n"; // 0x126bb60
  size_t size = sizeof(*unique.get());
  cout << size << "\n";
  cout << "=============================================================\n";
  cout << "sizeof(Str) -> " << sizeof(Str) << "\n"; // 56
  cout << "=============================================================\n";
  cout << "sizeof(payloadd) -> " << sizeof(payloadd) << "\n"; // 56
  cout << "=============================================================\n";
  void *dummyPtr = malloc(sizeof(Str));
  memcpy(dummyPtr, uniquePtr.get(), sizeof(Str));
  cout << "dummyPtr -> " << dummyPtr << "\n"; // 0x126b700
  cout << "dummyPtr->c -> " << (*static_cast<Payload *>(dummyPtr)).c
       << "\n"; // o
  cout << "dummyPtr->i -> " << (*static_cast<Payload *>(dummyPtr)).i
       << "\n"; // 17
  cout << "dummyPtr->r -> " << (*static_cast<Payload *>(dummyPtr)).r
       << "\n"; // c
  cout << "dummyPtr->y -> " << (*static_cast<Payload *>(dummyPtr)).y
       << "\n"; // 91
  cout << "dummyPtr->b -> " << (*static_cast<Payload *>(dummyPtr)).b
       << "\n"; // 1
  cout << "dummyPtr->s -> " << (*static_cast<Payload *>(dummyPtr)).s
       << "\n"; // sex
  cout << "=============================================================\n";
}

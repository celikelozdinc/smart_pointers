
#include <cstring>
#include <iostream>
#include <memory>
#include <string>

#include "definitions.h"

/**
 * @brief  Passing unique_ptr by value means “sink.”, transfers ownership of the pointer
 *
 * This is the preferred way to express a widget-consuming function, also known
 * as a “sink.
 *
 * Passing a unique_ptr by value is only possible by moving the object and its
 * unique ownership from the caller to the callee.
 *
 * @param uniqueWidget
 */
void sink(std::unique_ptr<Widget> uniqueWidget) {
  std::cout << "sink() :: Printing member before modification : " << uniqueWidget->member << "\n";
  uniqueWidget->member = 17;
  std::cout << "sink() :: Printing member after modification: " << uniqueWidget->member << "\n";
  Widget *released = uniqueWidget.release();
  std::cout << "sink() :: Printing member of released : " << released->member
            << "\n";
}

/**
 * @brief Transfers ownership of the pointer
 * 
 * @param ptr 
 */
void take_ownership(std::shared_ptr<int> ptr) {
  std::cout << "take_ownership()::use_count() -> " << ptr.use_count() << "\n";
}

/**
 * @brief Take ownership of a Widget
 *
 * Use a non-const unique_ptr& parameter only to modify the unique_ptr
 *
 * When the function is supposed to actually accept an existing unique_ptr and
 * potentially modify it to refer to a different object
 *
 * @param uniqueWidget
 */
void reseat(std::unique_ptr<Widget> &uniqueWidget) {
  uniqueWidget.reset(new Widget(10));
  /*
  Widget *released = uniqueWidget.release();
  std::cout << "reseat() :: Printing member of released : " << released->member
            << "\n";
  */
}

/**
 * @brief Passing shared_ptr by value implies taking shared ownership.
 *
 * a copy is needed anyway so the copying cost is fine.
 * 
 * reference counter will be updated.
 * 
 *  Express that a function will store and share ownership of a heap object
 * using a by-value shared_ptr parameter
 * 
 * Such operation is relatively heavy
 *
 * @param sharedWidget
 */
void share(std::shared_ptr<Widget> sharedWidget) {
  std::cout << "share() :: sharedWidget.use_count() == "
            << sharedWidget.use_count() << " (object @ " << sharedWidget
            << ")\n";
}


std::unique_ptr<Payload> baz() {
  std::unique_ptr<Payload> baz =
      std::make_unique<Payload>(Payload{'s', 10, 'd', 10, true, "SandorDargo"});
  return baz;
}

void foo(std::unique_ptr<Payload> up) {
  std::cout << (*up.get()).c << "\n";
  std::cout << (*up).i << "\n";
  std::cout << (*up.get()).r << "\n";
  std::cout << (*up).y << "\n";
  std::cout << (*up.get()).b << "\n";
  std::cout << (*up).s << "\n";
}

void bar(std::unique_ptr<Payload> p) {
  std::cout << p->i << "\n";
  std::cout << p->y << "\n";
}

int main() {
  Payload *payload = new Payload{'c', 60, 'r', 90, false, "sex"};
  Payload payloadd{'c', 70, 'r', 90, true, "sex"};
  std::unique_ptr<Payload *> unique = std::make_unique<Payload *>(payload);
  std::unique_ptr<Payload> uniquePtr =
      std::make_unique<Payload>(Payload{'o', 17, 'c', 91, true, "sex"});

  size_t sizeOfStruct = sizeof(*uniquePtr.get());
  std::cout << "Size of *uniquePtr.get() : " << sizeOfStruct << "\n"; // 56
  std::cout << "===================================================\n";
  /*
  cout << "uniquePtr -> " << uniquePtr << "\n";                   // 0x126b6c0
  */
  std::cout << "uniquePtr.get() -> " << uniquePtr.get() << "\n"; // 0x126b6c0
  std::cout << "sizeof(uniquePtr) -> " << sizeof(uniquePtr) << "\n";   // 8
  std::cout << "sizeof(*uniquePtr) -> " << sizeof(*uniquePtr) << "\n"; // 56
  std::cout << "sizeof(uniquePtr.get()) -> " << sizeof(uniquePtr.get())
            << "\n"; // 8
  std::cout << "sizeof(*uniquePtr.get()) -> " << sizeof(*uniquePtr.get())
            << "\n";                                                       // 56
  std::cout << "(*uniquePtr.get()).i -> " << (*uniquePtr.get()).i << "\n"; // 17
  std::cout << "(*uniquePtr.get()).s -> " << (*uniquePtr.get()).s
            << "\n"; // sex
  std::cout << "===================================================\n";
  std::cout << "unique.get() -> " << unique.get() << "\n";       // 0x126bb60
  std::cout << "*(unique.get()) -> " << *(unique.get()) << "\n"; // 0x126bb60
  size_t size = sizeof(*unique.get());
  std::cout << size << "\n";
  std::cout << "===================================================\n";
  std::cout << "sizeof(Str) -> " << sizeof(Str) << "\n"; // 56
  std::cout << "===================================================\n";
  std::cout << "sizeof(payloadd) -> " << sizeof(payloadd) << "\n"; // 56
  std::cout << "===================================================\n";
  // cast to void* and then cast back to Payload* again
  void *dummyPtr = malloc(sizeof(Str));
  memcpy(dummyPtr, uniquePtr.get(), sizeof(Str));
  Payload *dummyPayloadPtr = static_cast<Payload *>(dummyPtr);
  std::cout << "dummyPayloadPtr -> " << dummyPayloadPtr << "\n"; // 0x126b700
  std::cout << "dummyPayloadPtr->c -> " << (*dummyPayloadPtr).c << "\n"; // o
  std::cout << "dummyPayloadPtr->i -> " << (*dummyPayloadPtr).i << "\n"; // 17
  std::cout << "dummyPayloadPtr->r -> " << (*dummyPayloadPtr).r << "\n"; // c
  std::cout << "dummyPayloadPtr->y -> " << (*dummyPayloadPtr).y << "\n"; // 91
  std::cout << "dummyPayloadPtr->b -> " << (*dummyPayloadPtr).b << "\n"; // 1
  std::cout << "dummyPayloadPtr->s -> " << (*dummyPayloadPtr).s << "\n"; // sex
  std::cout << "===================================================\n";
  auto p = baz();
  // foo(p); // error: use of deleted function
  foo(move(p));
  std::cout << "===================================================\n";
  /**
   * unique_ptr is movable only, it should be passed with std::move to
   * explicitly express the ownership transfer
   *
   */
  auto myP = std::make_unique<Payload>();
  bar(std::move(myP));
  // std::cout << myP->i <<"\n"; //seg fault
  // std::cout << myP->y <<"\n"; //seg fault

  std::cout << "===================================================\n";

  /**
   * Examples from
   * https://www.modernescpp.com/index.php/c-core-guidelines-passing-smart-pointer
   *
   */
  auto uniqueWidget = std::make_unique<Widget>(20);
  // sink(uniqueWidget); //=> we can not copy unique ptr
  sink(std::move(uniqueWidget));
  // std::cout << "struct member after moving unique ptr : " <<
  // uniqueWidget->member << "\n";

  auto uWidget = std::make_unique<Widget>(20);
  // reseat(std::move(uniqueWidget)); //=> can not bind rvalue to lvalue
  // reference
  std::cout << "struct member before reseat : " << uWidget->member << "\n";
  reseat(uWidget); //=> a lvalue can be bound to lvalue reference
  std::cout << "struct member after reseat : " << uWidget->member << "\n";

  auto sharedWidget = std::make_shared<Widget>(80);
  share(sharedWidget);
  std::cout << "in main() : sharedWidget.use_count() == "
            << sharedWidget.use_count() << " (object @ " << sharedWidget
            << ")\n";

  std::cout << "===================================================\n";
  std::cout << "We'll initialize custom deleter for smart pointer: \n";
  std::unique_ptr<Payload, Free> uniquePtrWithDeleter{new Payload{}};
  std::cout << "Initialized Payload with custom deleter with member -> " << uniquePtrWithDeleter->s << "\n";

  std::cout << "===================================================\n";
  // https://www.demo2s.com/cpp/cpp-smart-pointers-exercise-1.html => Question6
  std::unique_ptr<Interface> pointerToClient1 = std::make_unique<Client1>();
  std::unique_ptr<Interface> pointerToClient2 = std::make_unique<Client2>();
  pointerToClient1->baz();
  pointerToClient2->baz();

  // https://www.demo2s.com/cpp/cpp-smart-pointers-exercise-1.html => Question4
  int dataToBeCopied = 10;
  std::shared_ptr<int> shared1 = std::make_shared<int>(dataToBeCopied);
  std::shared_ptr<int> shared2, shared3;
  shared2 = shared1;
  shared3 = shared1;
  std::cout <<"SharedPointer1 ref count -> " << shared1.use_count() << "\n"; //=> keeping track of the number of shared owners
  std::cout <<"SharedPointer2 ref count -> " << shared2.use_count() << "\n"; //=> keeping track of the number of shared owners
  std::cout <<"SharedPointer3 ref count -> " << shared3.use_count() << "\n"; //=> keeping track of the number of shared owners
  take_ownership(std::move(shared1));
  std::cout <<"SharedPointer1 ref count -> " << shared1.use_count() << "\n"; //=> keeping track of the number of shared owners
  std::cout <<"SharedPointer2 ref count -> " << shared2.use_count() << "\n"; //=> keeping track of the number of shared owners
  std::cout <<"SharedPointer3 ref count -> " << shared3.use_count() << "\n"; //=> keeping track of the number of shared owners
  take_ownership(std::move(shared2));
  std::cout <<"SharedPointer1 ref count -> " << shared1.use_count() << "\n"; //=> keeping track of the number of shared owners
  std::cout <<"SharedPointer2 ref count -> " << shared2.use_count() << "\n"; //=> keeping track of the number of shared owners
  std::cout <<"SharedPointer3 ref count -> " << shared3.use_count() << "\n"; //=> keeping track of the number of shared owners
  std::cout << "===================================================\n";
  // https://www.datasim.nl/application/files/6815/3777/1447/Exercise_3_Smart_Pointers.pdf => Question2
  std::shared_ptr<double> data = std::make_shared<double>(23.0);
  std::cout << "data ref count before C1() -> " << data.use_count() << "\n"; //=> keeping track of the number of shared owners
  C1 object1(data);
  std::cout << "data ref count after C1(), before C2()  -> " << data.use_count() << "\n"; //=> keeping track of the number of shared owners
  C2 object2(data);
  std::cout << "data ref count after C2(), before C2(std::move())  -> " << data.use_count() << "\n"; //=> keeping track of the number of shared owners
  C2 obj2(std::move(data));
  std::cout << "data ref count after C2(std::move())  -> " << data.use_count() << "\n"; //=> keeping track of the number of shared owners
  std::cout << "===================================================\n";
  std::unique_ptr<Base> polymorphic = std::make_unique<Derived>(10);
  polymorphic->display();
  std::cout << "===================================================\n";

}

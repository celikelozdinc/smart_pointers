# Reminders
+ std::unique_ptr &rarr; That will only permit one owner of the pointer
+ std::shared_ptr &rarr; If you want to deal with multiple owners. Maintains a reference count of all the pointers which point to the object

# Aim of this repository
+ sizeof with struct
+ sizeof with pointer to _struct_
+ sizeof with smart pointer to _struct_
+ sizeof with smart pointer to _pointer to struct_
+ Copy from smart pointer to `void*` via _memcpy_
+ smart pointers and their copy ctor/copy assignment


# Give it try on Wandbox
[Wandbox link](https://wandbox.org/permlink/YqVUGvU4boTvVAuZ)


# Compile & Run
```bash
g++ smart_pointers.cpp -o smart ; ./$_
OR
g++ smart_pointers.cpp -o smart ; ./smart
```

# References
+ [Definitions](https://www.journaldev.com/37481/smart-pointers-in-c-plus-plus)
+ [Size of struct](https://www.geeksforgeeks.org/is-sizeof-for-a-struct-equal-to-the-sum-of-sizeof-of-each-member/)
+ [void* in cpp](https://www.geeksforgeeks.org/void-pointer-c-cpp/)
+ [const and unique_ptr by Sandor Dargo](https://dev.to/sandordargo/const-and-smart-pointers-1hn1)
+ [smart pointers](https://medium.com/codex/everything-you-need-to-know-about-smart-pointers-in-c-3a92c9dcd532)
+ [ref card](https://www.cppstories.com/2021/smart-ptr-ref-card/)
+ [Passing smart pointers by Rainer Grimm](https://www.modernescpp.com/index.php/c-core-guidelines-passing-smart-pointer)
+ [use_count() from cppreference](https://en.cppreference.com/w/cpp/memory/shared_ptr/use_count)
+ [GotW #91 : Smart Pointer Parameters by Herb Sutter](https://herbsutter.com/2013/06/05/gotw-91-solution-smart-pointer-parameters/)
+ [Smart pointers gotchas](https://www.cppstories.com/2013/02/smart-pointers-gotchas/)
+ [Exercises](https://www.demo2s.com/cpp/cpp-smart-pointers-exercise-1.html)
+ [Smart Pointer Exercises](https://www.datasim.nl/application/files/6815/3777/1447/Exercise_3_Smart_Pointers.pdf)
+ [Inbal Levi on Meeting C++ online](https://www.youtube.com/watch?v=XU-dujj72SM)
+ [Refactor into unique ptr -> 5. Locally for buffers](https://www.cppstories.com/2021/refactor-into-uniqueptr/)
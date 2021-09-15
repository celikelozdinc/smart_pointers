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
+ [Size of struct](https://www.geeksforgeeks.org/is-sizeof-for-a-struct-equal-to-the-sum-of-sizeof-of-each-member/)
+ [void* in cpp](https://www.geeksforgeeks.org/void-pointer-c-cpp/)
+ [const and unique_ptr by Sandor Dargo](https://dev.to/sandordargo/const-and-smart-pointers-1hn1)
+ [smart pointers](https://medium.com/codex/everything-you-need-to-know-about-smart-pointers-in-c-3a92c9dcd532)

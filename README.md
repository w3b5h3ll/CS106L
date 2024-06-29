# CS106L
"Standard C++ Programming" course learning...

### Assignments
暂时没有06, 07的starter code


- [x] Assignment 01: SimpleEnroll
- [x] Assignment 02: Marriage Pact
- [x] Assignment 03: Make a Class
- [x] Assignment 04: Weather Forecast
- [ ] Assignment 05: TreeBook


尝试使用`std::move()`进行右值转换,但是内部调用`set`的insert操作还是使用了`copy constructor`,如下
```cpp

int main()
{

    // create a bunch of users
    User alice("Alice");
    User bob("Bob");
    User charlie("Charlie");
    User dave("Dave");

    // make them friends
    // alice = alice + bob;
    alice = std::move((alice) + bob);
    alice = std::move((alice) + charlie);

    dave = std::move((dave) + bob);
    charlie = std::move((charlie) + dave);

    // print out their friends
    printFriends(alice);
    printFriends(bob);
    printFriends(charlie);
    printFriends(dave);

    return 0;
}

```
报错
```bash
user.cpp:47:23:   required from here
   47 |     lhs.friends.insert(rhs.friends.begin(), rhs.friends.end());
      |     ~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/14.1.1/bits/new_allocator.h:191:11: 错误：使用了被删除的函数‘User::User(const User&)’
  191 |         { ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
      |           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
user.h:10:5: 附注：在此声明
   10 |     User(const User &) = delete;
      |     ^~~~
/usr/include/c++/14.1.1/bits/new_allocator.h:191:11: 附注：use ‘-fdiagnostics-all-candidates’ to display considered candidates
  191 |         { ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }


```



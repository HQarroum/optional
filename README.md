# optional

An implementation of the C++14 optional pattern.

Current version: **1.0.0**

Lead Maintainer: [Halim Qarroum](mailto:hqm.post@gmail.com)

# Description

This project consists of a header-only file containing a minimalist implementation of the `optional` pattern introduced by the C++14 standard library. This implementation does not aim at being complete, its goal is purely educative.

The `optional` pattern makes it possible to manipulate values that may, or may not be available.

Imagine that you would like to override the behaviour of the `atoi` function so that it does not return the misleading `0` value if the input string is invalid, but a not-an-int value instead. Here is how you would do that using `optional` :

```c++
Optional<int> my_atoi(const char* value)
{
  int nb = atoi(value);
  
  if (nb == 0) {
    return Optional<int>();
  }
  return (nb);
}
```

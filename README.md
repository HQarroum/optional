# optional

An implementation of the C++14 optional pattern.

Current version: **1.0.0**

Lead Maintainer: [Halim Qarroum](mailto:hqm.post@gmail.com)

## Description

This project consists of a header-only file containing a minimalist implementation of the `optional` pattern introduced by the C++14 standard library. This implementation does not aim at being complete, its goal is purely educative.

The `optional` pattern makes it possible to manipulate values that may, or may not be available.

## Example

Imagine that you would like to override the behaviour of the `atoi` function so that it does not return the misleading `0` value if the input string is invalid, but a not-an-int value instead. Here is how you would do that using `optional` :

```c++
/**
 * \return an optional long integer which contains the integer
 * value extracted from the given string on success, a not
 * a number value otherwise.
 */
Optional<long int> my_atoi(const char* value)
{
  auto nb = strtol(value, NULL, 10);
  
  if (nb == 0
    || nb == LONG_MAX
    || nb == LONG_MIN) {
    return Optional<long int>();
  }
  return (nb);
}

int main()
{
  auto value = my_atoi("123");
  
  if (value) {
    printf("The value is %ld\n", value.get());
  } else {
    printf("The value is not a number\n");
  }
  return (0);
}
```

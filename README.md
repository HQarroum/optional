# Optional
> An implementation of the C++17 optional pattern.

![Production ready](https://img.shields.io/badge/Production-Ready-brightgreen.svg)

Current version: **1.0.0**

Lead Maintainer: [Halim Qarroum](mailto:hqm.post@gmail.com)

## Description

This project consists of a header-only file containing a minimalist implementation of the `optional` pattern introduced by the C++17 standard library. The `optional` pattern makes it possible to manipulate values that may, or may not be available and provides therefore the appropriate semantics to deal with optional values in a type-safe manner.

## Example

Imagine that you would like to override the behaviour of the `atoi` function so that it does not return a misleading `0` value if the input string is invalid, but a not-an-int value instead. Here is how you would do that using `optional` :

```c++
/**
 * \return an optional long integer which contains the integer
 * value extracted from the given string on success, a not
 * a number value otherwise.
 */
Optional<long int> my_atoi(const char* value)
{
  char* ptr = nullptr;
  auto nb   = strtol(value, &ptr, 10);
  
  if (ptr == str || *ptr != '\0'
    || ((nb == LONG_MIN || nb == LONG_MAX) && errno == ERANGE)) {
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

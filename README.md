# Optional
> An implementation of the C++17 optional pattern.

![Experimental](https://img.shields.io/badge/status-experimental-brightgreen.svg)

Current version: **1.0.0**

Lead Maintainer: [Halim Qarroum](mailto:hqm.post@gmail.com)

## Description

This project consists of a header-only minimalist implementation of the [optional pattern](https://en.cppreference.com/w/cpp/utility/optional) introduced by the C++17 standard library. This pattern makes it possible to manipulate values that may, or may not be available and provides therefore the appropriate semantics to deal with optional values in a type-safe manner.

## Example

Imagine that you would like to override the behaviour of the `strtol` function so that it returns a *not-an-int* value if the input is invalid. Here is how you would do that using `optional` :

```c++
/**
 * \return an optional integer which holds the integer
 * value extracted from the given string on success, a not
 * a number value otherwise.
 */
static experimental::optional<int> integer_of(const char* value) {
  try {
    return (std::stoi(value, nullptr, 10));
  } catch (std::invalid_argument&) {
    return experimental::optional<int>();
  }
}

int main() {
  auto value = integer_of("123");
  
  if (value) {
    std::cout << "The value is " << value.get() << std::endl;
  } else {
    std::cout << "The value is not a number" << std::endl;
  }
  return (0);
}
```

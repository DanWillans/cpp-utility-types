# cpp-utility-types

Header-only C++ utility types for safer return values and lightweight identifiers.

Namespace alias: `cut`

---

## Features

- **`cut::Result<T, Error>`**
  A generic result type inspired by Rust’s `Result<T, E>`.
  Return either a success value or an error in a type-safe way.

- **`cut::Error`**
  A simple error container that integrates with `Result`.

- **`cut::Id<Tag>`**
  Strongly-typed identifiers that prevent accidental mixing of unrelated IDs.

---

## Example Usage

```cpp
#include "cut/result.hpp"
#include "cut/error.hpp"
#include "cut/is.hpp"

#include <iostream>

using namespace cut;

// Example function that may fail
Result<int, Error> divide(int a, int b) {
    if (b == 0) {
        return Error{"Division by zero"};
    }
    return a / b;
}

struct UserTag {}; // tag type for IDs
using UserId = ID<UserTag>;

struct AdminTag {}; // tag type for IDs
using AdminId = ID<AdminTag>;

int main() {
    auto res = divide(10, 2);

    if (res) {
        std::cout << "Result: " << res.Value() << "\n";
    } else {
        std::cout << "Error: " << res.Error().Message() << "\n";
    }

    UserID u1{1};
    UserID u2{2};
    // UserID cannot be mixed with other ID<Tag> types
    AdminID a1{1};
    AdminID a2{2};
    // UserID != AdminId

    return 0;
}
```

## Goals

- Minimal and dependency-free
- Familiar syntax for anyone used to std::optional, Rust’s Result, or functional-style error handling
- Prevent common mistakes through strong typing (Id<Tag>)

## License

MIT License. See LICENSE for details.
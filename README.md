# Funky

Functional and ergonomic transformations.

![Review](https://img.shields.io/github/actions/workflow/status/JoelLefkowitz/funky/review.yaml)
![Quality](https://img.shields.io/codacy/grade/_)

## Installing

```bash
conan install funky
```

You can also download the [sources](https://download-directory.github.io?url=https://github.com/JoelLefkowitz/funky/tree/master/src).

## Motivation

Rather than this:

```cpp
#include <algorithm>
#include <vector>

std::vector<int> sequence({1, 2, 3});
std::vector<int> mapped;

std::transform(
    sequence.begin(),
    sequence.end(),
    std::back_inserter(mapped),
    [](auto x) { return x + 1; }
);
```

Let's write this:

```cpp
#include <funky/iterables/iterables.tpp>
#include <vector>

std::vector<int> sequence({1, 2, 3});

auto mapped = map<std::vector<int>>(
    [](auto x) { return x + 1; },
    sequence
);
```

Now `mapped` will still be:

```cpp
std::vector<int>({2, 3, 4});
```

And this function doesn't mutate the input and is much easier to read.

> Most structures are small enough that immutability makes transformations easier to read and thread safe without loss of performance.

The C++ templating system is smart enough to evaluate the types involved in these kinds of transformations for us. This means we can avoid using std::function or interfaces to declare the types involved. This also means we don't need to define concepts for `Functor` or `Foldable` to use `map` and `fold`.

Our `map` function makes an empty container and still uses `.begin()` and `.end()` internally to map the results. This makes it just as generic as `std::transform` and suitable for transforming any iterable structure. This is reflected in its type signature:

```cpp
// map ≔ (A → B) → [ A ] → [ B ]
```

If we do need to mutable a structure we can use the functions in `mutable.tpp`:

```cpp
#include <funky/iterables/mutable.tpp>
#include <vector>

auto sequence = std::vector<int>({1, 2, 3, 2});
remove(sequence, 2);
```

Now `sequence` will be updated in place:

```cpp
std::vector<int>({1, 3});
```

## Documentation

Documentation and more detailed examples are hosted on [Github Pages](https://joellefkowitz.github.io/funky).

## Usage

This package makes use of templates. The definitions and implementations are split between `.hpp` and `.tpp` files. If you are calling the functions implemented in them then include the `.tpp` file instead.

## Overview

### Callables

Available in: `funky/generics/callables.hpp`

#### compose

```cpp
// T → U → auto
auto compose(const T &f, const U &g);

// T → U → auto
auto compose(const T &f, const U &...gs);
```

#### pipe

```cpp
// T → U → auto
auto pipe(const T &f, const U &...gs);
```

### Iterables

Available in: `funky/generics/iterables.hpp`

#### convert

```cpp
// [ A ] → [ B ]
FB convert(const FA &source);
```

#### reverse

```cpp
// [ A ] → [ A ]
FA reverse(const FA &vec);
```

#### map

```cpp
// (char → char) → std::string → std::string
std::string map(const T &mapper, const std::string &source);

// (A → B → C) → std::map<A, B> → std::vector<C>
std::vector<C> map(const T &mapper, const std::map<A, B> &source);

// (A → B) → [ A ] → [ B ]
FB map(const T &mapper, const FA &source);

// (A → size_t → B) → [ A ] → [ B ]
FB map(const T &mapper, const FA &source);
```

#### foreach

```cpp
// (A → void) → [ A ] → void
void foreach (const T &effect, const FA &source);

// (A → size_t → void) → [ A ] → void
void foreach (const T &effect, const FA &source);
```

#### filter

```cpp
// (A → bool) → [ A ] → [ A ]
FA filter(const T &condition, const FA &source);
```

#### fold

```cpp
// (B → A → B) → B → [ A ] → B
B fold(const T &folder, const B &initial, const FA &source);
```

#### concat

```cpp
// [ A ] → A → [ A ]
FA concat(const FA &vec, const A &x);

// [ A ] → [ A ] → [ A ]
FA concat(const FA &vec, const FA &x);
```

#### flatten

```cpp
// std::vector<[ A ]> → [ A ]
FA flatten(const std::vector<FA> &vec);
```

#### slice

```cpp
// [ A ] → size_t → size_t → [ A ]
FA slice(const FA &vec, const size_t start, const size_t end);
```

#### slice_first

```cpp
// [ A ] → size_t → [ A ]
FA slice_first(const FA &vec, size_t width);
```

#### slice_last

```cpp
// [ A ] → size_t → [ A ]
FA slice_last(const FA &vec, size_t width);
```

#### drop_first

```cpp
// [ A ] → size_t → [ A ]
FA drop_first(const FA &vec, size_t width);
```

#### drop_last

```cpp
// [ A ] → size_t → [ A ]
FA drop_last(const FA &vec, size_t width);
```

#### aperture

```cpp
// [ A ] → size_t → std::vector<[ A ]>
std::vector<FA> aperture(const FA &vec, size_t width);
```

### Sets

Available in: `funky/generics/sets.hpp`

#### contains

```cpp
// [ A ] → A → bool
bool contains(const FA &vec, const A &x);
```

#### is_unique

```cpp
// [ A ] → bool
bool is_unique(const FA &vec);
```

#### unique

```cpp
// [ A ] → [ A ]
FA unique(const FA &vec);
```

#### intersects

```cpp
// [ A ] → [ A ] → bool
bool intersects(const FA &source, const FA &target);
```

#### intersection

```cpp
// [ A ] → [ A ] → [ A ]
FA intersection(const FA &source, const FA &target);
```

#### difference

```cpp
// [ A ] → [ A ] → [ A ]
FA difference(const FA &source, const FA &target);
```

#### index

```cpp
// [ A ] → A → size_t
size_t index(const FA &vec, const A &x);
```

#### find

```cpp
// (A → bool) → [ A ] → size_t
size_t find(const T &condition, const FA &source);
```

#### min

```cpp
// [ A ] → A → A
A min(const FA &vec, A empty);
```

#### max

```cpp
// [ A ] → A → A
A max(const FA &vec, A empty);
```

### Pairs

Available in: `funky/generics/pairs.hpp`

#### zip

```cpp
// [ A ] → [ B ] → std::vector<std::pair<A, B>>
std::vector<std::pair<A, B>> zip(const FA &a, const FB &b);
```

#### product

```cpp
// [ A ] → [ B ] → std::vector<std::pair<A, B>>
std::vector<std::pair<A, B>> product(const FA &a, const FB &b);
```

#### pairs

```cpp
// std::map<A, B> → std::vector<std::pair<A, B>>
std::vector<std::pair<A, B>> pairs(const std::map<A, B> &source);
```

### Mutable

Available in: `funky/generics/mutable.hpp`

#### insert

```cpp
// [ A ] → [ A ] → void
void insert(const FA &source, FA &target);
```

#### remove

```cpp
// [ A ] → A → void
void remove(FA &vec, const A &x);
```

#### partition

```cpp
// (A → bool) → [ A ] → void
void partition(const T &filter, FA &vec);
```

### Booleans

Available in: `funky/concrete/booleans.hpp`

#### all

```cpp
// [ A ] → bool
bool all(const FA &source);

// (A → bool) → [ A ] → bool
bool all(const T &predicate, const FA &source);
```

#### any

```cpp
// [ A ] → bool
bool any(const FA &source);

// (A → bool) → [ A ] → bool
bool any(const T &predicate, const FA &source);
```

#### at_least

```cpp
// size_t → [ A ] → bool
bool at_least(size_t min, const FA &source);

// (A → bool) → size_t → [ A ] → bool
bool at_least(const T &predicate, size_t min, const FA &source);
```

### Numbers

Available in: `funky/concrete/numbers.hpp`

#### fractional

```cpp
// double → double
double fractional(double x);
```

#### round

```cpp
// double → size_t → double
double round(double x, size_t dps);
```

#### sign

```cpp
// int → int
int sign(int n);
```

#### order

```cpp
// double → int
int order(double n);
```

#### proportion

```cpp
// double → double
double proportion(double x);
```

#### normalise

```cpp
// double → double → double → double → double
double normalise(double x, double min, double max, double scale);
```

#### is_factor

```cpp
// int → int → bool
bool is_factor(int divisor, int dividend);
```

#### has_factor

```cpp
// int → int → bool
bool has_factor(int dividend, int divisor);
```

#### ratio

```cpp
// size_t → double → double
double ratio(size_t dividend, double divisor);

// double → size_t → double
double ratio(double dividend, size_t divisor);

// size_t → size_t → double
double ratio(size_t dividend, size_t divisor);
```

#### unit

```cpp
// double → std::string → std::string
std::string unit(double n, const std::string &metric);
```

#### bounds

```cpp
// A → A → A → bool
bool bounds(A lower, A x, A higher);
```

#### includes

```cpp
// A → A → A → bool
bool includes(A lower, A x, A higher);
```

#### clamp

```cpp
// A → A → A → A
A clamp(A lower, A x, A higher);
```

### Strings

Available in: `funky/concrete/strings.hpp`

#### starts_with

```cpp
// std::string → std::string → bool
bool starts_with(const std::string &str, const std::string &prefix);
```

#### ends_with

```cpp
// std::string → std::string → bool
bool ends_with(const std::string &str, const std::string &suffix);
```

#### reverse

```cpp
// std::string → std::string
std::string reverse(const std::string &str);
```

#### pad

```cpp
// std::string → size_t → std::string
std::string pad(const std::string &str, size_t size);
```

#### truncate

```cpp
// std::string → size_t → std::string → std::string
std::string truncate(const std::string &str,size_t limit,const std::string &ellipsis = "...");
```

#### uppercase

```cpp
// std::string → std::string
std::string uppercase(const std::string &str);
```

#### lowercase

```cpp
// std::string → std::string
std::string lowercase(const std::string &str);
```

#### split

```cpp
// std::string → std::string → std::vector<std::string>
std::vector<std::string> split(const std::string &str,const std::string &delimiter);
```

#### join

```cpp
// std::vector<std::string> → std::string → std::string
std::string join(const std::vector<std::string> &strings,const std::string &delimiter = "");
```

#### chunk

```cpp
// std::string → size_t → std::vector<std::string>
std::vector<std::string> chunk(const std::string &str, size_t size);
```

#### without_substrings

```cpp
// std::string → std::vector<std::string> → std::string
std::string without_substrings(const std::string &str,const std::vector<std::string> &substr);
```

#### format_hex

```cpp
// int → size_t → std::string
std::string format_hex(int n, size_t length = 6UL);
```

#### parse_hex

```cpp
// std::string → int
int parse_hex(const std::string &str);
```

### Vectors

Available in: `funky/concrete/vectors.hpp`

#### range

```cpp
// size_t → std::vector<size_t>
std::vector<size_t> range(size_t limit);

// A → A → A → std::vector<A>
std::vector<A> range(A start, A stop, A step = 1);
```

#### linspace

```cpp
// A → A → size_t → std::vector<A>
std::vector<A> linspace(A start, A stop, size_t count);
```

#### enumerate

```cpp
// std::vector<A> → std::vector<Indexed<A>>
std::vector<Indexed<A>> enumerate(const std::vector<A> &vec);
```

## Tooling

### Dependencies

To install dependencies:

```bash
yarn install
pip install .[all]
conan install .
```

### Tests

To run tests:

```bash
scons test
```

### Documentation

To generate the documentation locally:

```bash
scons docs
```

### Linters

To run linters:

```bash
scons lint
```

### Formatters

To run formatters:

```bash
scons format
```

### Toolchains

Scripts are defined in the `scripts` folder and can be invoked with `toolchains`:

To generate header guards:

```bash
npx toolchains guards
```

## Contributing

Please read this repository's [Code of Conduct](CODE_OF_CONDUCT.md) which outlines our collaboration standards and the [Changelog](CHANGELOG.md) for details on breaking changes that have been made.

This repository adheres to semantic versioning standards. For more information on semantic versioning visit [SemVer](https://semver.org).

Bump2version is used to version and tag changes. For example:

```bash
bump2version patch
```

### Contributors

- [Joel Lefkowitz](https://github.com/joellefkowitz) - Initial work

## Remarks

Lots of love to the open source community!

<div align='center'>
    <img width=200 height=200 src='https://media.giphy.com/media/osAcIGTSyeovPq6Xph/giphy.gif' alt='Be kind to your mind' />
    <img width=200 height=200 src='https://media.giphy.com/media/KEAAbQ5clGWJwuJuZB/giphy.gif' alt='Love each other' />
    <img width=200 height=200 src='https://media.giphy.com/media/WRWykrFkxJA6JJuTvc/giphy.gif' alt="It's ok to have a bad day" />
</div>

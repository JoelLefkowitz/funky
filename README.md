# Funky

Functional type classes and instances.

![Review](https://img.shields.io/github/actions/workflow/status/JoelLefkowitz/funky/review.yaml)
![Quality](https://img.shields.io/codacy/grade/_)

## Installing

```bash
conan search funky
```

You can also download the [sources](https://download-directory.github.io?url=https://github.com/JoelLefkowitz/funky/tree/master/src).

## Documentation

Documentation and more detailed examples are hosted on [Github Pages](https://joellefkowitz.github.io/funky).

## Overview

### Ranges

Available in: `funky/vectors/ranges.hpp`

#### range

`size_t → std::vector<size_t>`

```cpp
std::vector<size_t> range(size_t limit);
```

`T → T → T → std::vector<T>`

```cpp
std::vector<T> range(T start, T stop, T step = 1);
```

#### linspace

`T → T → size_t → std::vector<T>`

```cpp
std::vector<T> linspace(T start, T stop, size_t count);
```

#### enumerate

`std::vector<T> → std::vector<Indexed<T>>`

```cpp
std::vector<Indexed<T>> enumerate(const std::vector<T> &vec);
```

### Mutable

Available in: `funky/vectors/mutable.hpp`

#### insert

`std::vector<T> → std::vector<T> → void`

```cpp
void insert(const std::vector<T> &source, std::vector<T> &target);
```

#### erase

`std::vector<T> → T → void`

```cpp
void erase(std::vector<T> &vec, T x);
```

#### move_to_back

`(T → bool) → std::vector<T> → void`

```cpp
void move_to_back(const std::function<bool(T)> &filter,std::vector<T> &vec);
```

### Immutable

Available in: `funky/vectors/immutable.hpp`

#### unique

`std::vector<T> → std::vector<T>`

```cpp
std::vector<T> unique(const std::vector<T> &vec);
```

#### reverse

`std::vector<T> → std::vector<T>`

```cpp
std::vector<T> reverse(const std::vector<T> &vec);
```

#### difference

`std::vector<T> → std::vector<T> → std::vector<T>`

```cpp
std::vector<T> difference(const std::vector<T> &source,const std::vector<T> &target);
```

#### intersection

`std::vector<T> → std::vector<T> → std::vector<T>`

```cpp
std::vector<T> intersection(const std::vector<T> &source,const std::vector<T> &target);
```

#### slice

`std::vector<T> → size_t → size_t → std::vector<T>`

```cpp
std::vector<T> slice(const std::vector<T> &vec,const size_t start,const size_t end);
```

#### slice_first

`std::vector<T> → size_t → std::vector<T>`

```cpp
std::vector<T> slice_first(const std::vector<T> &vec, size_t width);
```

#### slice_last

`std::vector<T> → size_t → std::vector<T>`

```cpp
std::vector<T> slice_last(const std::vector<T> &vec, size_t width);
```

#### drop_first

`std::vector<T> → size_t → std::vector<T>`

```cpp
std::vector<T> drop_first(const std::vector<T> &vec, size_t width);
```

#### drop_last

`std::vector<T> → size_t → std::vector<T>`

```cpp
std::vector<T> drop_last(const std::vector<T> &vec, size_t width);
```

#### aperture

`std::vector<T> → size_t → std::vector<std::vector<T>>`

```cpp
std::vector<std::vector<T>> aperture(const std::vector<T> &vec,size_t width);
```

#### concat

`std::vector<T> → T → std::vector<T>`

```cpp
std::vector<T> concat(const std::vector<T> &vec, const T &x);
```

`std::vector<T> → std::vector<T> → std::vector<T>`

```cpp
std::vector<T> concat(const std::vector<T> &vec, const std::vector<T> &x);
```

#### flatten

`std::vector<std::vector<T>> → std::vector<T>`

```cpp
std::vector<T> flatten(const std::vector<std::vector<T>> &vec);
```

#### from_deque

`std::deque<T> → std::vector<T>`

```cpp
std::vector<T> from_deque(const std::deque<T> &deque);
```

### Elements

Available in: `funky/vectors/elements.hpp`

#### min

`std::vector<T> → T`

```cpp
T min(const std::vector<T> &vec);
```

#### max

`std::vector<T> → T`

```cpp
T max(const std::vector<T> &vec);
```

#### index

`std::vector<T> → T → size_t`

```cpp
size_t index(const std::vector<T> &vec, const T &x);
```

`(const T & → bool) → std::vector<T> → size_t`

```cpp
size_t index(std::function<bool(const T &)> condition,const std::vector<T> &vec);
```

#### contains

`std::vector<T> → T → bool`

```cpp
bool contains(const std::vector<T> &vec, const T &x);
```

#### repeats

`std::vector<T> → bool`

```cpp
bool repeats(const std::vector<T> &vec);
```

#### overlaps

`std::vector<T> → std::vector<T> → bool`

```cpp
bool overlaps(const std::vector<T> &source, const std::vector<T> &target);
```

### Accumulators

Available in: `funky/vectors/accumulators.hpp`

#### average

`std::vector<T> → T`

```cpp
T average(const std::vector<T> &vec);
```

### Strings

Available in: `funky/strings/strings.hpp`

#### reverse_copy

`std::string → std::string`

```cpp
std::string reverse_copy(const std::string &str);
```

#### pad

`std::string → size_t → std::string`

```cpp
std::string pad(const std::string &str, size_t size);
```

#### chunk

`std::string → size_t → std::vector<std::string>`

```cpp
std::vector<std::string> chunk(const std::string &str, size_t size);
```

#### split

`std::string → std::string → std::vector<std::string>`

```cpp
std::vector<std::string> split(const std::string &str,const std::string &delimiter);
```

#### starts_with

`std::string → std::string → bool`

```cpp
bool starts_with(const std::string &str, const std::string &prefix);
```

#### ends_with

`std::string → std::string → bool`

```cpp
bool ends_with(const std::string &str, const std::string &suffix);
```

#### uppercase

`std::string → std::string`

```cpp
std::string uppercase(const std::string &str);
```

#### lowercase

`std::string → std::string`

```cpp
std::string lowercase(const std::string &str);
```

#### truncate

`std::string → size_t → std::string → std::string`

```cpp
std::string truncate(const std::string &str,size_t limit,const std::string &ellipsis = "...");
```

#### join

`std::vector<std::string> → std::string → std::string`

```cpp
std::string join(const std::vector<std::string> &strings,const std::string &delimiter = "");
```

#### remove_substrings

`std::string → std::vector<std::string> → std::string`

```cpp
std::string remove_substrings(const std::string &str,const std::vector<std::string> &substr);
```

### Hex

Available in: `funky/strings/hex.hpp`

#### hex

`int → size_t → std::string`

```cpp
std::string hex(int n, size_t length);
```

#### parse_hex

`std::string → int`

```cpp
int parse_hex(const std::string &str);
```

### Numbers

Available in: `funky/numbers/numbers.hpp`

#### frac

`double → double`

```cpp
double frac(double x);
```

#### round

`double → size_t → double`

```cpp
double round(double x, size_t dps);
```

#### sign

`int → int`

```cpp
int sign(int n);
```

#### order

`double → int`

```cpp
int order(double n);
```

#### units_prefix

`double → std::string`

```cpp
std::string units_prefix(double n);
```

### Limits

Available in: `funky/numbers/limits.hpp`

#### between

`T → T → T → bool`

```cpp
bool between(T lower, T x, T higher);
```

#### contains

`T → T → T → bool`

```cpp
bool contains(T lower, T x, T higher);
```

#### clamp

`T → T → T → T`

```cpp
T clamp(T lower, T x, T higher);
```

#### clamp_proportion

`double → double`

```cpp
double clamp_proportion(double x);
```

#### normalise

`double → double → double → double → double`

```cpp
double normalise(double x, double min, double max, double scale);
```

### Division

Available in: `funky/numbers/division.hpp`

#### factor

`int → int → bool`

```cpp
bool factor(int dividend, int divisor);
```

#### ratio

`size_t → double → double`

```cpp
double ratio(size_t dividend, double divisor);
```

`double → size_t → double`

```cpp
double ratio(double dividend, size_t divisor);
```

`size_t → size_t → double`

```cpp
double ratio(size_t dividend, size_t divisor);
```

### Zip

Available in: `funky/iterables/zip.hpp`

#### zip

`[ A ] → [ B ] → std::vector<std::pair<A, B>>`

```cpp
std::vector<std::pair<A, B>> zip(const FA &a, const FB &b);
```

### Product

Available in: `funky/iterables/product.hpp`

#### product

`[ A ] → [ B ] → std::vector<std::pair<A, B>>`

```cpp
std::vector<std::pair<A, B>> product(const FA &a, const FB &b);
```

### Pair

Available in: `funky/iterables/pair.hpp`

#### pair

`[ A ] → std::vector<std::pair<A,A>>`

```cpp
std::vector<std::pair<A, A>> pair(const FA &source);
```

### Map

Available in: `funky/iterables/map.hpp`

#### map

`(char → char) → std::string → std::string`

```cpp
std::string map(const T &mapper, const std::string &source);
```

`(A → B → C) → std::map<A, B> → std::vector<C>`

```cpp
std::vector<C> map(const T &mapper, const std::map<A, B> &source);
```

`(A → B) → [ A ] → [ B ]`

```cpp
FB map(const T &mapper, const FA &source);
```

### Foreach

Available in: `funky/iterables/foreach.hpp`

#### foreach

`(A → void) → [ A ] → void`

```cpp
void foreach (const T &effect, const FA &source);
```

`(A → size_t → void) → [ A ] → void`

```cpp
void foreach (const T &effect, const FA &source);
```

`(A → B → void) → [ A ] → [ B ] → void`

```cpp
void foreach (const T &effect, const FA &a, const FB &b);
```

`(A → B → size_t → void) → [ A ] → [ B ] → void`

```cpp
void foreach (const T &effect, const FA &a, const FB &b);
```

### Fold

Available in: `funky/iterables/fold.hpp`

#### fold

`(B → A → B) → B → [ A ] → B`

```cpp
B fold(const T &folder, const B &initial, const FA &source);
```

### Filter

Available in: `funky/iterables/filter.hpp`

#### filter

`(A → bool) → [ A ] → [ A ]`

```cpp
FA filter(const T &condition, const FA &source);
```

### Pipe

Available in: `funky/callables/pipe.hpp`

#### pipe

`T → U → auto`

```cpp
auto pipe(const T &f, const U &...gs);
```

### Compose

Available in: `funky/callables/compose.hpp`

#### compose

`T → U → auto`

```cpp
auto compose(const T &f, const U &g);
```

`T → U → auto`

```cpp
auto compose(const T &f, const U &...gs);
```

### Booleans

Available in: `funky/booleans/booleans.hpp`

#### all

`[ A ] → bool`

```cpp
bool all(const FA &source);
```

`(A → bool) → [ A ] → bool`

```cpp
bool all(const T &mapper, const FA &source);
```

#### any

`[ A ] → bool`

```cpp
bool any(const FA &source);
```

`(A → bool) → [ A ] → bool`

```cpp
bool any(const T &mapper, const FA &source);
```

#### at_least

`size_t → [ A ] → bool`

```cpp
bool at_least(size_t min, const FA &source);
```

`(A → bool) → size_t → [ A ] → bool`

```cpp
bool at_least(const T &mapper, size_t min, const FA &source);
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

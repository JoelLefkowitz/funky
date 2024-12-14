// Can't make ABC for functor without mixing generics and overrides which doesn't work
// Lib contents:
// 1. Create concepts for abstractions eg is_functor
// 2. Create methods for common abstractions links eg map for is_iterable so you can map a vector because it has start()
// and end()
// 3. Useful methods for instances eg drop_last for functors

// #include <functional>
// #include <map>
// #include <numeric>

// template <template <typename...> typename F, typename A, typename B>
// F<B> map(const std::function<B(A)> &mapper, const F<A> &source) {
//     F<B> target;
//     std::transform(source.begin(), source.end(), std::back_inserter(target), mapper);
//     return target;
// }

// std::vector<int> source = {};

// std::function<std::string(int)> mapper = [](int x) { return std::to_string(x); };

// std::vector<std::string> target = map(mapper, source);

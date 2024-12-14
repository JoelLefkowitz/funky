#include <functional/generics/functor/map.tpp>
#include <functional>
#include <vector>

int main() {
    std::function<int(int)> increment = [](int x) { return x + 1; };
    functional::map(increment, std::vector<int>({1, 2, 3}));
    return 0;
}

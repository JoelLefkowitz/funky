#include <functional>
#include <funky/generics/functor/map.tpp>
#include <vector>

int main() {
    std::function<int(int)> increment = [](int x) {
        return x + 1;
    };
    funky::map(increment, std::vector<int>({1, 2, 3}));
    return 0;
}

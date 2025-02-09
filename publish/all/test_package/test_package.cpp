#include <funky/iterables/iterables.tpp>
#include <vector>

auto increment = [](auto x) {
    return x + 1;
};

int main() {
    std::vector<int> numbers({1, 2, 3});
    auto output = map<std::vector<int>>(increment, numbers);
    return 0;
}

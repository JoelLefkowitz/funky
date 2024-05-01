#include "map.hpp"
#include <algorithm>
#include <iterator>
#include <string>

std::string functional::map(const std::function<char(char)> &mapper, const std::string &source) {
    std::string target;
    std::transform(source.begin(), source.end(), std::back_inserter(target), mapper);
    return target;
}

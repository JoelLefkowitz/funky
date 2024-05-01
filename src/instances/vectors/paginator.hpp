#ifndef PAGINATOR_HPP
#define PAGINATOR_HPP

#include <cstddef>
#include <vector>

namespace functional {
    template <typename T>
    class Paginator {
      private:
        std::vector<T> vector;

        size_t size;

        size_t page;
        size_t upper;
        size_t lower;

      public:
        explicit Paginator(const std::vector<T> &vector = {}, size_t size = 10);

        std::vector<T> current();

        void previous();
        void next();

        bool first();
        bool last();
    };
} // namespace functional

#endif

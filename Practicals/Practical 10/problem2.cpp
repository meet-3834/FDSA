#include <iostream>
#include <vector>

int main() {
    const int shelfCount = 10;
    std::vector<std::vector<long long>> shelves(shelfCount);
    int bookCount;

    std::cout << "Number of books: ";
    if (!(std::cin >> bookCount) || bookCount < 0) {
        std::cerr << "Enter a non-negative number of books.\n";
        return 1;
    }

    for (int i = 0; i < bookCount; ++i) {
        long long code;
        std::cout << "Book code " << i + 1 << ": ";
        if (!(std::cin >> code)) {
            std::cerr << "Invalid book code.\n";
            return 1;
        }

        const int shelf = static_cast<int>((code % shelfCount + shelfCount) % shelfCount);
        shelves[shelf].push_back(code);
    }

    std::cout << "\nFinal shelf contents:\n";
    for (int shelf = 0; shelf < shelfCount; ++shelf) {
        std::cout << "Shelf " << shelf << ": ";
        if (shelves[shelf].empty()) {
            std::cout << "Empty";
        } else {
            for (std::size_t i = 0; i < shelves[shelf].size(); ++i) {
                if (i > 0) {
                    std::cout << " -> ";
                }
                std::cout << shelves[shelf][i];
            }
        }
        std::cout << '\n';
    }

    return 0;
}

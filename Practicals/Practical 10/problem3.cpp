#include <iostream>
#include <vector>

int main() {
    const int tableSize = 10;
    std::vector<long long> table(tableSize);
    std::vector<bool> occupied(tableSize, false);
    int studentCount;

    std::cout << "Number of students: ";
    if (!(std::cin >> studentCount) || studentCount < 0) {
        std::cerr << "Enter a non-negative number of students.\n";
        return 1;
    }

    for (int i = 0; i < studentCount; ++i) {
        long long id;
        std::cout << "Student ID " << i + 1 << ": ";
        if (!(std::cin >> id) || id < 0) {
            std::cerr << "Enter a non-negative student ID.\n";
            return 1;
        }

        const int firstSlot = static_cast<int>(id % tableSize);
        const int jumps[] = {1, 3, 7, 9};
        const int jump = jumps[id % 4];

        bool inserted = false;
        for (int attempt = 0; attempt < tableSize; ++attempt) {
            const int slot = (firstSlot + attempt * jump) % tableSize;
            if (!occupied[slot]) {
                table[slot] = id;
                occupied[slot] = true;
                inserted = true;
                break;
            }
        }

        if (!inserted) {
            std::cout << "Table is full. Student ID " << id
                      << " could not be stored.\n";
        }
    }

    std::cout << "\nFinal hash table:\n";
    for (int slot = 0; slot < tableSize; ++slot) {
        std::cout << "Slot " << slot << ": ";
        if (occupied[slot]) {
            std::cout << table[slot];
        } else {
            std::cout << "Empty";
        }
        std::cout << '\n';
    }

    return 0;
}

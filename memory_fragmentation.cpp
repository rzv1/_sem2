#include <iostream>
#include <vector>
#include <cstdlib> // pentru malloc și free

int main() {
    std::cout << "Simulare fragmentare heap:\n";

    // Pas 1: alocăm mai multe blocuri mici (ex: 5 x 256KB)
    std::vector<void*> blocuri;
    for (int i = 0; i < 5; ++i) {
        void* ptr = malloc(256 * 1024); // 256KB
        if (ptr) {
            std::cout << "Bloc " << i << " alocat la " << ptr << "\n";
            blocuri.push_back(ptr);
        } else {
            std::cout << "Eșec la alocarea blocului " << i << "\n";
        }
    }

    // Pas 2: eliberăm câteva blocuri intercalate (ex: 1 și 3)
    free(blocuri[1]);
    std::cout << "Bloc 1 eliberat\n";
    free(blocuri[3]);
    std::cout << "Bloc 3 eliberat\n";

    // Pas 3: încercăm să alocăm un bloc mai mare (ex: 500KB)
    void* bigBlock = malloc(500 * 1024); // 500KB
    if (bigBlock) {
        std::cout << "Bloc mare alocat la " << bigBlock << "\n";
    } else {
        std::cout << "Eșec la alocarea blocului mare (fragmentare!)\n";
    }

    // Cleanup
    for (int i = 0; i < blocuri.size(); ++i) {
        if (i != 1 && i != 3) free(blocuri[i]);
    }
    if (bigBlock) free(bigBlock);

    return 0;
}

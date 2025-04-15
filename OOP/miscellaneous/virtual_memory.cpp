#include <sys/mman.h>
#include <unistd.h>
#include <iostream>

int main() {
    size_t size = 100L * 1024 * 1024 * 1024; // 100 GB
    void* ptr = mmap(NULL, size, PROT_READ | PROT_WRITE,
                     MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (ptr == MAP_FAILED) {
        std::cerr << "Eșec la alocarea virtuală!\n";
    } else {
        std::cout << "Alocare reușită!\n";
        // accesează memoria dacă vrei să forțezi mapping
        ((char*)ptr)[0] = 42;  // doar dacă vrei să testezi mapping real
        munmap(ptr, size);
    }

    return 0;
}

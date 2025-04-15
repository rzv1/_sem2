#include <vector>
#include <iostream>

int main() {
    try {
        std::cout << "Aloc vector mare...\n";
        std::vector<int> v(500'000'000); // ~2GB
        std::cout << "Alocat cu succes!\n";
    } catch (const std::bad_alloc& e) {
        std::cerr << "Eroare de alocare: " << e.what() << '\n';
    }

    std::cin.get(); // asteapta input ca sa ofere timp pentru a vizualiza Task Manager.
    return 0;
}

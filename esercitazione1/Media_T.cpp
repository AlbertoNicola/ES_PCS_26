#include <iostream>
#include <fstream>
#include <string>

int main(int argc, const char *argv[]) {
    std::ifstream file(argv[1]);
    std::string citta;
    double t1, t2, t3, t4;


    while (file >> citta >> t1 >> t2 >> t3 >> t4) {
        double media = (t1 + t2 + t3 + t4) / 4.0;

        std::cout << citta << " " << media << "\n";
    }

    file.close();
    return 0;
}
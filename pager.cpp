#include <iostream>
#include <string>
#include <vector>

int main () {

    std::string phrase;
    std::vector <std::string> vec;
    int p = 0;
    int q;

    while (std::getline(std::cin, phrase)) {

        vec.push_back(phrase);
        p ++;

        if (p == 4) {

            for (q = 0; q < 4; q++) {

                std::cout << vec[q] << std::endl;

            }

            std::cout << "====" << std::endl;

            vec.clear();
            p = 0;

        }

    }

    return 0;

}
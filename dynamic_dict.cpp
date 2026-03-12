#include <iostream>
#include <sstream>
#include <string>

int main() {

    std::string phrase;

    std::getline(std::cin, phrase);

    std::istringstream new_stream (phrase);

    std::string pol_word;
    std::string fr_word;

    std::getline(new_stream, pol_word, ':');
    std::getline(new_stream, fr_word);

    std::cout << "slowo: " << pol_word << ", tlumaczenie: " << fr_word << std::endl;

}
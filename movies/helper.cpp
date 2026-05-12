#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {

    std::map<std::string, int> m;

    m["kot"] = 1;
    m["pies"] = 2;
    m["ptak"] = 3;

    // - pierwsze przejscie --- !!! najlepszy

    for (auto& [key, value] : m) { 

        std::cout << key << value << std::endl;

    }

    // - drugie przejscie

    for (auto& it : m) {

        std::cout << it.first << it.second << std::endl;

    }

    // - trzecie przejscie

    for (auto it = m.begin(); it != m.end(); ++it) {

        std::cout << it->first << it->second << std::endl;

    } 

}

// - insert w vectorze wstawia przed wskazanym iteratorem


// - sprawdzanie czy dany elemeny byl juz w parze

/*
// Rozpakowujemy parę prosto do dwóch zmiennych!
auto [gdzie_jest, czy_dodano] = m.insert({"pies", 2});

if (czy_dodano == false) {
    std::cout << "Pies juz byl w mapie!";
}
*/

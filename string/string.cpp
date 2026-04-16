#include "mini_string.hpp"
#include <cstring>

void string_init(MiniString& s, const char* initial_text) {

    s.length = strlen(initial_text);
    s.text = new char [s.length + 1];

    for (int i = 0; i < s.length + 1; i++) {

        s.text[i] = initial_text[i];

    }

}

void string_destroy(MiniString& s) {

    delete [] s.text;
    s.text = nullptr;
    s.length = 0;

}

void string_copy(MiniString& dest, const MiniString& src) {

    string_destroy(dest);

    if (src.text != nullptr) {

        string_init(dest, src.text);

    }

}

void string_append(MiniString& s, const char* suffix) {

    size_t old_length = s.length;
    
    s.length = old_length + strlen(suffix);
    char * temp = new char [s.length + 1];

    for (int i = 0; i < s.length; i++) {

        if (i < old_length) {

            temp[i] = s.text[i];

        }

        else {

            temp[i] = suffix[i - old_length];

        }

    }

    temp[s.length] = '\0';

    string_destroy(s);
    string_init(s, temp);

    delete[] temp;

}

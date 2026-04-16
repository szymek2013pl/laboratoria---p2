#ifndef MINI_STRING_HPP
#define MINI_STRING_HPP

struct MiniString {

    char* text;
    int length;

};

void string_init(MiniString& s, const char* initial_text);

void string_destroy(MiniString& s);

void string_copy(MiniString& dest, const MiniString& src);

void string_append(MiniString& s, const char* suffix);

#endif

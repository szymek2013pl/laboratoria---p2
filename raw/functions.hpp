ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <cstring>

int *filter_positives(const int * input, int input_size, int &outsize);

int **generate_pascal(int rows);

void free_pascal(int** triangle, int rows);

char** split_string(const char* text, char delimiter, int& out_count);

void free_split(char** words, int count);

#endif

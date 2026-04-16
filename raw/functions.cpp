#include "functions.hpp"

int *filter_positives(const int * input, int input_size, int &outsize) {

    int count = 0;

    for (int i = 0; i < input_size; i++) {

        if (*(input + i) > 0) {

            count ++;

        }

    }

    if (count == 0) {

        outsize = 0;
        return nullptr;

    }

    int * arr = new int [count];

    outsize = count;
    int minus = 0;

    for (int i = 0; i < input_size; i++) {

        if (*(input + i) <= 0) {

            minus ++;

        }

        else {

            arr[i - minus] = input[i];

        }

    }
    
    return arr;

}

int **generate_pascal(int rows) {

    int ** matrix = new int * [rows];

    for (int i = 0; i < rows; i++) {

        matrix[i] = new int [i + 1];

    }

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < i + 1; j++) {

            if (j == 0 || j == i) {

                matrix[i][j] = 1;

            }

            else {

                matrix[i][j] = matrix[i - 1][j - 1] + matrix[i - 1][j];

            }

        }

    } 

    return matrix;

}

void free_pascal(int** triangle, int rows) {

    for (int i = 0; i < rows; i++) {

        delete [] triangle[i];

    }

    delete [] triangle;

}

char** split_string(const char* text, char delimiter, int& out_count) {

    int s = strlen(text);
    int count = 0;
    
    for (int i = 0; i < s; i++) {

        if (text[i] == delimiter) {

            count++;

        }

    }

    out_count = count + 1;
    char ** matrix = new char * [out_count];

    int length = 0;
    int words = 0;
    int index = 0;

    for (int i = 0; i <= s; i++) {

        if (text[i] != delimiter) {

            length++;

        }

        else {

            matrix[words] = new char [length + 1];
            matrix[words][length] = '\0';

            for (int j = 0; j < length; j++) {

                matrix[words][j] = text[index];
                index ++;

            }
            
            words++;
            length = 0;

        }

    }

    return matrix;

}

void free_split(char** words, int count) {

    for (int i = 0; i < count; i++) {

        delete [] words[i];

    }

    delete [] words;

}

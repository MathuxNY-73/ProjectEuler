#ifndef INPUT_HPP
#define INPUT_HPP

#include <cstdio>
#include <cstdlib>

#include <string>

static inline void fastscan(int& number) {
    //variable to indicate sign of input number
    bool negative = false;
    int c;

    number = 0;

    // extract current character from buffer
    c = getchar_unlocked();

    if (c=='-')
        {
            // number is negative
            negative = true;

            // extract the next character from the buffer
            c = getchar_unlocked();
        }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar_unlocked())
        number = number *10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
};

static inline int fastscan_char_w(char (&str)[], int buffer_size) {
    char c;
    int size_of_str = 0;

    // extract current character from buffer
    c = getchar_unlocked();

    // Keep on extracting characters if they are not
    // space, carriage return or end of string
    for (; c != ' '
             && c != '\n'
             && c != '\0'
             && c != EOF;
         c=getchar_unlocked(),++size_of_str)
        {
            if(size_of_str > buffer_size)
                exit(-1);
            str[size_of_str] = c;
        }
    return  size_of_str;
};

static inline int fastscan_string_w(std::string& str, int buffer_size)
{
    char c;
    int size_of_str = 0;

    // extract current character from buffer
    c = getchar_unlocked();

    // Keep on extracting characters if they are not
    // space, carriage return or end of string
    for (; c != ' '
             && c != '\n'
             && c != '\0'
             && c != EOF;
         c=getchar_unlocked(),++size_of_str)
        {
            if(size_of_str > buffer_size)
                exit(-1);
            str.push_back(c);
        }
    return  size_of_str;
};

#endif

//
// Created by eisenmenger on 13.08.21.
//

#ifndef TDD_SOUNDEX_H
#define TDD_SOUNDEX_H

#include <string>

using std::string;

class Soundex
{
private:
    string zeroPad(const string &word) const
    {
        return word + "000";
    }

public:
    string encode(const string &word) const
    {
        return zeroPad(word);
    }
};
#endif //TDD_SOUNDEX_H

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
    static const size_t MaxCodeLength{4};

    string encodedDigit(char letter) const {
        const std::unordered_map<char, std::string> encodings
        {
            {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
            {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"},
            {'s', "2"}, {'x', "2"}, {'z', "2"},
            {'d', "3"},{'t', "3"},
            {'l', "4"},
            {'m', "5"},{'n', "5"},
            {'r', "6"}
        };
        auto it = encodings.find(letter);
        // encodings.end() will only be reached if nothing could be found
        return it == encodings.end() ? "" : it->second;
    }

    string encodedDigits(const string &word) const
    {
        string encoding;
        for (auto letter : word)
        {
            if (isComplete(encoding)) break;
            encoding += encodedDigit(letter);
        }
        return encoding;
    }

    string head(const string &word) const
    {
        return word.substr(0, 1);
    }

    bool isComplete(const string &encoding) const
    {
        return encoding.length() == MaxCodeLength - 1;
    }

    string tail(const string &word) const
    {
        return word.substr(1);
    }

    string zeroPad(const string &word) const
    {
        auto zerosNeeded = MaxCodeLength - word.length();
        return word + string(zerosNeeded, '0');
    }

public:
    string encode(const string &word) const
    {
        return zeroPad(head(word) + encodedDigits(tail(word)));
    }
};
#endif //TDD_SOUNDEX_H

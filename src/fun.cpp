// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cstring>
#include <cmath>

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool hasDigit = false;

    for (size_t i = 0; i < std::strlen(str); ++i) {
        if (std::isspace(str[i])) {
            if (inWord && !hasDigit) {
                ++count;
            }
            inWord = false;
            hasDigit = false;
        }
        else {
            if (!inWord) {
                inWord = true;
                hasDigit = false;
            }
            if (std::isdigit(str[i])) {
                hasDigit = true;
            }
        }
    }

    if (inWord && !hasDigit) {
        ++count;
    }

    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool validWord = false;

    for (size_t i = 0; i < std::strlen(str); ++i) {
        if (std::isspace(str[i])) {
            if (inWord && validWord) {
                ++count;
            }
            inWord = false;
            validWord = false;
        }
        else {
            if (!inWord) {
                if (std::isupper(str[i])) {
                    inWord = true;
                    validWord = true;
                }
                else {
                    inWord = false;
                    validWord = false;
                }
            }
            else {
                if (!std::islower(str[i])) {
                    validWord = false;
                }
            }
        }
    }

    if (inWord && validWord) {
        ++count;
    }

    return count;
}

unsigned int faStr3(const char *str) {
    unsigned int wordCount = 0;
    unsigned int totalLength = 0;
    bool inWord = false;
    unsigned int currentWordLength = 0;

    for (size_t i = 0; i < std::strlen(str); ++i) {
        if (std::isspace(str[i])) {
            if (inWord) {
                wordCount++;
                totalLength += currentWordLength;
                inWord = false;
                currentWordLength = 0;
            }
        }
        else {
            if (!inWord) {
                inWord = true;
            }
            currentWordLength++;
        }
    }

    if (inWord) {
        wordCount++;
        totalLength += currentWordLength;
    }

    if (wordCount == 0) {
        return 0;
    }

    double averageLength = static_cast<double>(totalLength) / wordCount;
    return static_cast<unsigned int>(std::round(averageLength));
}

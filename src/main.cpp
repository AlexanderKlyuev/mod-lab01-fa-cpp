// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>

int main() {
    const char* testStr1 = "Hello world! This is a test 123 string.";
    const char* testStr2 = "Alice has a Cat Bob's friend.";
    const char* testStr3 = "Average word length calculation.";

    unsigned int countNoDigits = faStr1(testStr1);
    std::cout << "Количество слов без цифр: " << countNoDigits << std::endl;

    unsigned int countCapitalWords = faStr2(testStr2);
    std::cout << "Количество слов, начинающихся с заглавной латинской буквы и содержащих только строчные буквы: " << countCapitalWords << std::endl;

    unsigned int averageWordLength = faStr3(testStr3);
    std::cout << "Средняя длина слова: " << averageWordLength << std::endl;

    return 0;
}

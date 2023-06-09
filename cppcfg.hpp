//
//                                        .d888
//                                       d88P"
//                                       888
//    .d8888b 88888b.  88888b.   .d8888b 888888 .d88b.
//   d88P"    888 "88b 888 "88b d88P"    888   d88P"88b
//   888      888  888 888  888 888      888   888  888
//   Y88b.    888 d88P 888 d88P Y88b.    888   Y88b 888
//    "Y8888P 88888P"  88888P"   "Y8888P 888    "Y88888
//            888      888                          888
//            888      888                     Y8b d88P
//            888      888                      "Y88P"
//
//              Created by febru. Version 1.1.
//              https://febru.me/
//              Github: @februu
//
//              Distributed under MIT License
//              Copyright (c) 2023 Kacper Lutomski
//

#pragma once
#include <string>
#include <unordered_map>

class ConfigurationFile
{

private:
    const bool suppressErrorMessages;
    const std::string filePath;
    std::unordered_map<std::string, float> doubles;
    std::unordered_map<std::string, double> floats;
    std::unordered_map<std::string, std::string> strings;
    std::unordered_map<std::string, bool> bools;
    std::unordered_map<std::string, char> chars;
    std::unordered_map<std::string, int> integers;

    bool parseLine(std::string line);

public:
    // Creates new ConfigurationFile object. Requires path to .cfg file (string) as argument. Setting the second argument to true suppresses all error messages.
    ConfigurationFile(std::string filePath, bool suppressErrorMessages = false);
    ~ConfigurationFile(){};

    // Reloads values from file. Returns true if file exists, false if not.
    bool reload(void);

    // Get double value.
    double getDouble(std::string key);

    // Get float value.
    float getFloat(std::string key);

    // Get string value.
    std::string getString(std::string key);

    // Get char value.
    char getChar(std::string key);

    // Get integer value.
    int getInt(std::string key);

    // Get boolean value.
    bool getBool(std::string key);
};

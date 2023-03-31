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
//              Created by febru. Version 1.0.
//              https://febru.me/
//              Github: @februu
//

#pragma once
#include <string>
#include <unordered_map>

class ConfigurationFile
{

private:
    std::string filePath;
    std::unordered_map<std::string, float> doubles;
    std::unordered_map<std::string, double> floats;
    std::unordered_map<std::string, std::string> strings;
    std::unordered_map<std::string, bool> bools;
    std::unordered_map<std::string, char> chars;
    std::unordered_map<std::string, int> integers;

    bool parseLine(std::string line);

public:
    ConfigurationFile(std::string filePath);
    ~ConfigurationFile(){};

    void reload(void);

    double getDouble(std::string key);
    float getFloat(std::string key);
    std::string getString(std::string key);
    char getChar(std::string key);
    int getInt(std::string key);
    bool getBool(std::string key);
};

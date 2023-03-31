#include <iostream>
#include <unordered_map>
#include <fstream>
#include "cppcfg.hpp"

ConfigurationFile::ConfigurationFile(std::string filePath)
{
    this->filePath = filePath;
    reload();
}

void ConfigurationFile::reload(void)
{
    // Opens new file.
    std::ifstream file(filePath);

    // Checks if file exists.
    if (file.fail())
    {
        std::cerr << "Error! Path '" << filePath << "' is invalid!\n";
        return;
    }

    // Reads file line by line.
    int lineCount = 1;
    std::string line;
    while (std::getline(file, line))
    {
        if (!parseLine(line))
            std::cerr << "Error when reading " << filePath << ". Invalid line. (Line " << lineCount << ", '" << line << "')\n";
        lineCount++;
    }

    file.close();
}

bool ConfigurationFile::parseLine(std::string line)
{
    // Checks if line is not empty.
    if (line.length() == 0)
        return true;

    // Checks if line is not a comment.
    if (line[0] == '#')
        return true;

    int charCount = 0;
    int lineLength = line.length();
    std::string key = "", value = "";

    // Reads key from line.
    while (charCount < lineLength)
    {

        // Breaks the loop when finds '='.
        if (line[charCount] == '=')
        {
            charCount++;
            break;
        }

        // Checks if key only contains a-z,A-Z,0-9.
        if (!((line[charCount] > 47 && line[charCount] < 58) || (line[charCount] > 64 && line[charCount] < 91) || (line[charCount] > 96 && line[charCount] < 123)))
            return false;

        key += line[charCount];
        charCount++;
    }

    // Checks if value && key have length > 0. If not, returns false.
    if (charCount >= lineLength || charCount == 1)
        return false;

    // valueCharCount is later used to store value (string) length.
    int valueCharCount = charCount;
    // Used to check if there is a dot in value. If true, that eliminates INT as possible type.
    bool hasDot = false;
    // Used to check if there are only digits from 0-9. If true, it suggest that there is high probability of value being INT, DOUBLE or FLOAT.
    bool onlyNumbers = true;

    // Reads value from line.
    while (charCount < lineLength)
    {
        if (!hasDot && line[charCount] == '.')
            hasDot = true;

        // Second condition is used to check if last char is 'f' which indicates float value and shouldn't affect onlyNumbers variable.
        else if (onlyNumbers && ((line[charCount] > 57 || line[charCount] < 48) && !(charCount == (lineLength - 1) && line[charCount] == 'f')))
            onlyNumbers = false;

        value += line[charCount];
        charCount++;
    }

    // Calculates length of value variable.
    valueCharCount = charCount - valueCharCount;

    // Recognizes value type.
    try
    {

        // Boolean
        if (value == "true" || value == "false")
        {
            bools[key] = value[0] == 't';
            return true;
        }

        // String
        else if (value[0] == '"' && value[valueCharCount - 1] == '"')
        {
            strings[key] = value;
            return true;
        }

        // Char (max length of 3 chars because it should be in 'x' fromat).
        else if (value[0] == '\'' && value[valueCharCount - 1] == '\'' && valueCharCount == 3)
        {
            chars[key] = value[1];
            return true;
        }

        // Integer
        else if (onlyNumbers && !hasDot)
        {
            integers[key] = std::stoi(value);
            return true;
        }

        // Float
        else if (onlyNumbers && hasDot && value[valueCharCount - 1] == 'f')
        {
            floats[key] = std::stof(value.erase(valueCharCount - 1));
            return true;
        }

        // Double
        else if (onlyNumbers && hasDot)
        {
            doubles[key] = std::stod(value);
            return true;
        }
    }
    catch (...)
    {
        // In case conversion fails, returns false.
        return false;
    }

    // In case value wasn't recognized as any of the types, returns false.
    return false;
}

double ConfigurationFile::getDouble(std::string key) { return doubles[key]; }
float ConfigurationFile::getFloat(std::string key) { return floats[key]; }
std::string ConfigurationFile::getString(std::string key) { return strings[key]; }
char ConfigurationFile::getChar(std::string key) { return chars[key]; }
int ConfigurationFile::getInt(std::string key) { return integers[key]; }

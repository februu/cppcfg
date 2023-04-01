# cppcfg ⚙️

#### Simple C++ library for parsing custom .cfg files.

## About 📘

**Hey!** I always had a need to be able to add config files to my programs. I just like to have an ability to change some values in file and see the program process them in many different ways. But this always meant that I had to write myself a .cfg file parser to load those values... So I decided to make this library. This is my first C++ library released publicly so it might be kinda bad but I will try to improve it as I progress with my coding skills lmao.

✨ My website: [https://febru.me/](https://febru.me/) ✨

[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com) [![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](https://forthebadge.com)

## Usage 🛠️

**Installation:**

- Download the `cppcfg.hpp` file and place it in _include_ directory.
- Download the `cppcfg.cpp` file and place it in _src_ directory.
- Create new ConfigurationFile object like this. Values from the file will be automatically imported.

```cpp
ConfigurationFile config("config.cfg");
ConfigurationFile settings("settings.cfg", true);
```

> NOTE: If the second parameter is true, all error messages will be suppressed.

**Available methods:**

- `.reload()` - Reloads values from file. Returns true if file exists, false if not.
- `.getString(std::string key)` - Returns string value of key.
- `.getInt(std::string key)` - Returns integer value of key.
- `.getDouble(std::string key)` - Returns double value of key.
- `.getFloat(std::string key)` - Returns float value of key.
- `.getChar(std::string key)` - Returns char value of key.
- `.getBool(std::string key)` - Returns bool value of key.

## Syntax of .cfg files 📝

If you want to create a config file and be able to parse it using this library, you must stick to some rules.

- In one line there can only be one pair: `<key>=<value>`
- You can only use `a-z,A-Z,0-9` symbols when defining keys. No spaces allowed. _You can use underscores tho._
- Do not use spaces between key and '=' and between '=' and value.
- Strings have to be put into `""`. Chars have to be put into `''`.
- When creating decimal values, you can put `f` at the end to make them float, not double.
- To create boolean value, just type `true` or `false`.
- Blank lines are allowed.
- Lines beginning with `#` symbol are treated as comments and are skipped.
- Lines containing errors and are skipped. However, you will see an error message.

If this is confusing, don't be upset. Just look at the example shown below.

## Example code ⌨️

**config.cfg**

```ini
# Exemplary config.

hello="world"
ultimateAnswerToLifeTheUniverseAndEverything=42
someRandomNumber=21.37
someRandomNumberButFloat=326.23f
idkJustAChar=';'
isThisRepoAnyGood=true

# Some more values...
check=false
fun_number=82471.30f

# This library only cares about first and last char of your string to be ".
# This means that you don't have to escape special characters.
hey_look="you dont have to escape special chars here / | " "

```

**main.cpp**

```cpp
#include <iostream>
#include "cppcfg.hpp"

int main()
{
    ConfigurationFile config("config.cfg");
    std::cout << config.getString("hello") << "\n";
    std::cout << config.getInt("ultimateAnswerToLifeTheUniverseAndEverything") << "\n";
    std::cout << config.getDouble("someRandomNumber") << "\n";
    std::cout << config.getFloat("someRandomNumberButFloat") << "\n";
    std::cout << config.getChar("idkJustAChar") << "\n";
    std::cout << config.getBool("isThisRepoAnyGood") << "\n";
}
```

**Output:**

```
world
42
21.37
326.23
;
1
```

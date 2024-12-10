#include "vconfig.hpp"

#include <fstream>

Vconfig vConfig;

Vconfig::Vconfig() {
    set("ini_file", "config.ini");
}

// returns false if file coudn't be open
bool Vconfig::loadIni(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        auto splitPos = line.find('=');
        if (splitPos != std::string::npos) {
            std::string key = line.substr(0, splitPos);
            std::string value = line.substr(splitPos + 1);

            key = trim(key);
            value = trim(value);

            m_data[key] = value;
            m_persistentData[key] = value;
        }
    }

    return true;
}

bool Vconfig::saveIni(const std::string& fileName) {
    std::ofstream file(fileName);
    if (!file.is_open()) {
        return false;
    }

    for (const auto& [key, value] : m_persistentData) {
        file << key << "=" << value << "\n";
    }

    return true;
}

std::string Vconfig::get(const std::string& key, std::string defaultValue) {
    auto it = m_data.find(key);
    if (it == m_data.end()) {
        return defaultValue;
    }

    return m_data[key];
}

void Vconfig::set(const std::string key, const std::string value) {
    m_data[key] = value;
}

void Vconfig::setAndSave(const std::string& key, const std::string& value, const std::string& iniFile) {
    set(key, value);

    m_persistentData[key] = value;
    saveIni(iniFile);
}

std::string Vconfig::trim(const std::string& string) {
    size_t start = string.find_first_not_of(" \t\n\r\f\v");
    size_t end = string.find_last_not_of(" \t\n\r\f\v");

    return string.substr(start, end - start + 1);
}
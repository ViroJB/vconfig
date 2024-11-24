#pragma once

#include <map>
#include <string>

class Vconfig {
   public:
    const std::string APP_NAME;

   public:
    Vconfig();

    std::string get(const std::string& key, std::string defaultValue = "");
    void set(const std::string key, const std::string value);
    void setAndSave(const std::string& key, const std::string& value, const std::string& iniFile);

    bool loadIni(const std::string& fileName);

   private:
    std::map<std::string, std::string> m_data;
    std::map<std::string, std::string> m_persistentData;

   private:
    std::string trim(const std::string& string);
    bool saveIni(const std::string& fileName);
};

extern Vconfig vConfig;
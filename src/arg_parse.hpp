#pragma once

#include <string>
#include <map>

class ArgumentParser {
private:
    std::map<std::string, std::string> arguments;

public:
    ArgumentParser(int argc, char* argv[]);

    bool hasKey(const std::string& key) const;

    std::string const& getString(const std::string& key, const std::string& default_value="") const;
    int getInt(const std::string& key, int default_value=0) const;
    double getDouble(const std::string& key, double default_value=0.0) const;
    bool getBool(const std::string& key, bool default_value=false) const;
};

class ProjectArguments {
private:
    ArgumentParser parser;
    void help() const;
    void setup_logging() const;
public:
    const std::string default_map_file_path;
    ProjectArguments(int argc, char* argv[]);
};
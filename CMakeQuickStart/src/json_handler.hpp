#include <nlohmann/json.hpp>
#include <string>

class JsonHandler{
    private:
        std::string path;
    public:
        JsonHandler(std::string Path);
        nlohmann::json read_json(std::string path);
        void write_json(std::string path, nlohmann::json data);
};
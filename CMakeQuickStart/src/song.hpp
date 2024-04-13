#pragma once
#include <string>
#include <nlohmann/json.hpp>

class Song{
    private:
        std::string artist;
        std::string title;
        unsigned int length; // in seconds
    public:
        Song
        (
            std::string Artist,
            std::string Title,
            unsigned int Length    
        );
        std::string get_artist() const;
        std::string get_title() const;
        unsigned int get_length() const;
        void set_artist(std::string Artist);
        void set_title(std::string Title);
        void set_length(unsigned int Length);
        bool operator==(const Song& other) const;
        nlohmann::json to_json() const;
        std::string to_string() const;
};

namespace std{
    template<>
    struct hash<Song>{
        std::size_t operator()(const Song& song) const{
            return std::hash<std::string>()(song.get_artist()) ^ std::hash<std::string>()(song.get_title());
        }
    };
}
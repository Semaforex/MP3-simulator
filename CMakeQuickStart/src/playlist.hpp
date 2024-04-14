#pragma once
#include "song.hpp"
#include <unordered_set>
#include <string>
#include <vector>
#include <chrono>
#include <nlohmann/json.hpp>


class Playlist{
    private:
        std::string name;
        std::string author;
        std::unordered_set<size_t> song_list;
    public:
        Playlist(
            std::string Name,
            std::string Author        
        );
        std::string get_name() const;
        std::string get_author() const;
        std::unordered_set<size_t> get_song_list() const;
        void change_name(std::string Name);
        void change_author(std::string Author);
        void add_song(Song song);
        bool remove_song(Song song);
        bool operator==(const Playlist& other) const;
        nlohmann::json to_json() const;
        void from_json(const nlohmann::json& j);
};

namespace std{
    template<>
    struct hash<Playlist>{
        std::size_t operator()(const Playlist& playlist) const{
            return std::hash<std::string>()(playlist.get_author()) ^ std::hash<std::string>()(playlist.get_name());
        }
    };
}
#pragma once
#include "song.hpp"
#include <unordered_set>
#include <string>
#include <vector>
#include <chrono>
#include <nlohmann/json.hpp>

enum PlaylistEvent{
    add,
    del
};

static const char *PlaylistEventStrings[] = {
    "A song has been added",
    "A song has been deleted"
};

struct modify_event{
    std::chrono::time_point<std::chrono::system_clock> date;
    PlaylistEvent event_type;
    std::string song;
};

class Playlist{
    private:
        std::string name;
        std::string author;
        std::vector<modify_event> modifications;
        std::unordered_set<Song> song_list;
    public:
        Playlist(
            std::string Name,
            std::string Author        
        );
        std::string get_name() const;
        std::string get_author() const;
        std::vector<modify_event> get_modifications() const;
        std::unordered_set<Song> get_song_list() const;
        unsigned int get_total_length() const;
        void change_name(std::string Name);
        void change_author(std::string Author);
        void add_song(std::string Artist, std::string Title, unsigned int length);
        bool remove_song(std::string Artist, std::string Title);
        bool operator==(const Playlist& other) const;
        nlohmann::json to_json() const;
        void from_json(const nlohmann::json& j);
        std::string to_string() const;
        std::string get_modification_string() const;
};

namespace std{
    template<>
    struct hash<Playlist>{
        std::size_t operator()(const Playlist& playlist) const{
            return std::hash<std::string>()(playlist.get_author()) ^ std::hash<std::string>()(playlist.get_name());
        }
    };
}
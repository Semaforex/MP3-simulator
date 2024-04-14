#pragma once
#include "playlist.hpp"
#include <string>
#include <nlohmann/json.hpp>
#include <unordered_set>

class Memory {
    private:
        std::unordered_set<Song> songs;
        std::unordered_set<Playlist> playlists;
        unsigned int capacity;
    public:
        Memory();
        bool add_song(Song song);
        bool remove_song(Song song);
        bool add_playlist(Playlist playlist);
        bool remove_playlist(Playlist playlist);
        bool add_song_to_playlist(std::string playlist_name, std::string song_name, std::string artist);
        bool remove_song_from_playlist(std::string playlist_name, std::string song_name, std::string artist);
        unsigned int storage_used();
        unsigned int storage_left();
        nlohmann::json to_json();
        void from_json(nlohmann::json json_data);
        Song find_song(std::string song_name, std::string artist);
        Song find_song(std::string hash);
        Playlist find_playlist(std::string playlist_name);
        Playlist find_playlist(std::string hash);

};
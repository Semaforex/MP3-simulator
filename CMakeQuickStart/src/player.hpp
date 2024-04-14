#pragma once
#include "playlist.hpp"
#include "memory.hpp"
#include "battery.hpp"
#include "json_handler.hpp"
#include <queue>
#include <unordered_set>
#include <string>
#include <vector> 
#include <nlohmann/json.hpp>

class Player{
    private:
        std::string name;
        std::queue<std::size_t> song_queue;
        Battery battery;
        Memory memory;
        JsonHandler json_handler;
    public:
        Player(std::string Path, std::string Name, unsigned int Battery_capacity = 100);
        Player(std::string Path);
        void add_song(Song song);
        void remove_song(Song song);
        void add_playlist(Playlist playlist);
        void remove_playlist(Playlist playlist);
        void add_song_to_playlist(Playlist playlist, Song song);
        void list_playlist() const;
        void play_playlist(Playlist playlist) const;
        void play_song(Song song) const;
};
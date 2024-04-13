#pragma once
#include "playlist.hpp"
#include <unordered_set>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

class Player{
    private:
        Playlist playlist;
        std::string path;
    public:
        Player(std::string Path);
        Player(std::string Path, std::string Author, std::string Name);
        void add_song(std::string Artist, std::string Title, unsigned int Length);
        void remove_song(std::string Artist, std::string Title);
        void list_playlist() const;
        void play_songs() const;
        void list_modification_history() const;
        void play_song(std::string Artist, std::string Title) const;
};
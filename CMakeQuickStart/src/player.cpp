#include "player.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <thread>

enum message{
    song_add_success = 0,
    song_add_fail = 1,
    song_remove_success = 2,
    song_remove_fail = 3,
    playlist_add_success = 4,
    playlist_add_fail = 5,
    playlist_remove_success = 6,
    playlist_remove_fail = 7,
    song_playlist_add_success = 8,
    song_playlist_add_fail = 9,
    song_playlist_remove_success = 10,
    song_playlist_remove_fail = 11,
};

static const char *message_strings[] = {
    "Song added successfully",
    "Failed to add song",
    "Song removed successfully",
    "Failed to remove song",
    "Playlist added successfully",
    "Failed to add playlist",
    "Playlist removed successfully",
    "Failed to remove playlist",
    "Song added to playlist successfully",
    "Failed to add song to playlist",
    "Song removed from playlist successfully",
    "Failed to remove song from playlist"
};


Player::Player(std::string Path, std::string Name, unsigned int Battery_capacity) :
    memory{Memory()},
    json_handler{JsonHandler(Path)},
    battery{Battery(Battery_capacity)},
    name{Name}
{
    if(name.empty())
        throw(std::invalid_argument("Name cannot be empty"));
}

Player::Player(std::string Path) : 
    memory{Memory()},
    json_handler{JsonHandler(Path)},
    battery{Battery()}
{
    nlohmann::json json_data = json_handler.read_json();
    memory.from_json(json_data["memory"]);
    battery.from_json(json_data["battery"]);
}

std::string Player::add_song(Song song){
    if(memory.add_song(song))
        return(message_strings[song_add_success]);
    else
        return(message_strings[song_add_fail]);
}

std::string Player::remove_song(std::string Artist, std::string Title){
    memory.remove_song(Artist, Title);
}

void Player::list_playlist() const{
    std::cout << "Playlist: " << playlist.get_name() << " by " << playlist.get_author() << std::endl;
    std::cout << "Total length: " << playlist.get_total_length() << " seconds" << std::endl;
    std::cout << "Songs: " << std::endl;
    for(const auto& song : playlist.get_song_list())
        std::cout << song.get_artist() << " - " << song.get_title() << " - " << song.get_length() << " seconds" << std::endl;
}

void Player::play_playlist() const{
    for(const auto& song : playlist.get_song_list()){
        std::cout << "Now playing: " << song.get_artist() << " - " << song.get_title() << std::endl;
        for(unsigned int timer = song.get_length(); timer > 0; timer--){
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "time left: " << timer << std::endl;
        }
        std::cout << "Finished playing: " << song.get_artist() << " - " << song.get_title() << std::endl;
    }
}


void Player::play_song(std::string Artist, std::string Title) const{
    for(const auto& song : playlist.get_song_list()){
        if(song.get_artist() == Artist && song.get_title() == Title){
            std::cout << "Now playing: " << song.get_artist() << " - " << song.get_title() << std::endl;
            for(unsigned int timer = song.get_length(); timer > 0; timer--){
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "time left: " << timer << std::endl;
            }
            std::cout << "Finished playing: " << song.get_artist() << " - " << song.get_title() << std::endl;
            return;
        }
    }
    std::cout << "Song not found" << std::endl;
}
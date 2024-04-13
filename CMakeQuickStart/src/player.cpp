#include "player.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <thread>

bool check_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

Player::Player(std::string Path) : playlist{Playlist("null", "null")}, path{Path} {
    std::ifstream file(path);
    if(check_empty(file)){
        std::cout << "Playlist does not exist" << '\n';
        return;
    }
    nlohmann::json playlistJson;
    file >> playlistJson;
    playlist.from_json(playlistJson);
}

Player::Player(std::string Path, std::string Author, std::string Name): playlist{Playlist(Name, Author)}, path{Path} {
    std::ofstream file(path);
    file << playlist.to_json().dump(4);
}

void Player::add_song(std::string Artist, std::string Title, unsigned int Length){
    try{
        playlist.add_song(Artist, Title, Length);
        std::ofstream file(path);
        file << playlist.to_json().dump(4);
    }
    catch (std::invalid_argument& e){
        std::cout << e.what() << std::endl;
    }
}

void Player::remove_song(std::string Artist, std::string Title){
    if(playlist.remove_song(Artist, Title)){
        std::ofstream file(path);
        file << playlist.to_json().dump(4);
    }
    else
        std::cout << "Song not found" << std::endl;
}

void Player::list_playlist() const{
    std::cout << "Playlist: " << playlist.get_name() << " by " << playlist.get_author() << std::endl;
    std::cout << "Total length: " << playlist.get_total_length() << " seconds" << std::endl;
    std::cout << "Songs: " << std::endl;
    for(const auto& song : playlist.get_song_list())
        std::cout << song.get_artist() << " - " << song.get_title() << " - " << song.get_length() << " seconds" << std::endl;
}

void Player::play_songs() const{
    std::vector<Song> songs;
    for(const auto& song : playlist.get_song_list())
        songs.push_back(song);
    if(songs.size() == 0){
        std::cout << "No songs in the playlist" << std::endl;
        return;
    }
    for(const auto& song : songs){
        std::cout << "Now playing: " << song.get_artist() << " - " << song.get_title() << std::endl;
        for(unsigned int timer = song.get_length(); timer > 0; timer--){
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "time left: " << timer << std::endl;
        }
        std::cout << "Finished playing: " << song.get_artist() << " - " << song.get_title() << std::endl;
    }
}

void Player::list_modification_history() const{
    std::cout << playlist.get_modification_string() << std::endl;
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
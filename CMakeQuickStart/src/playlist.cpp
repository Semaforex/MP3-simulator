#include "playlist.hpp"
#include <stdexcept>
#include <iomanip>
#include <fmt/core.h>
#include <fmt/chrono.h>


void check_name(std::string Name){
    if(Name == "")
        throw(std::invalid_argument("Name cannot be empty"));
}

void check_auhtor(std::string Author){
    if(Author == "")
        throw(std::invalid_argument("Author cannot be empty"));
}


Playlist::Playlist(
    std::string Name,
    std::string Author
) : name{Name}, author{Author}, song_list{std::unordered_set<size_t>()}{
    check_name(Name);
    check_auhtor(Author);
}

std::string Playlist::get_name() const{
    return name;
}

std::string Playlist::get_author() const{
    return author;
}


std::unordered_set<size_t> Playlist::get_song_list() const{
    return song_list;
}


void Playlist::change_name(std::string Name){
    check_name(Name);
    name = Name;
}

void Playlist::change_author(std::string Author){
    check_auhtor(Author);
    author = Author;
}
void Playlist::add_song(Song song){
    std::hash<Song> hasher;
    size_t songHash = hasher(song);
    song_list.insert(songHash);
}

bool Playlist::remove_song(Song song){
    std::hash<Song> hasher;
    size_t songHash = hasher(song);
    if(song_list.erase(songHash) == 0)
        return false;
    return true;
}

bool Playlist::operator==(const Playlist& other) const{
    return name == other.name && author == other.author;
}

nlohmann::json Playlist::to_json() const{
    nlohmann::json j;
    j["name"] = name;
    j["author"] = author;
    j["song_list"] = nlohmann::json::array({});
    for(const auto& song_hash : song_list)
        j["song_list"].push_back(song_hash);
    return j;
}

void Playlist::from_json(const nlohmann::json& j){
    name = j.at("name").get<std::string>();
    author = j.at("author").get<std::string>();
    for(const auto& song : j.at("song_list"))
        song_list.insert(song.get<size_t>());
}
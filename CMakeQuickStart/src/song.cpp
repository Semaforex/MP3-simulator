#include "song.hpp"
#include <stdexcept>
#include <fmt/core.h>

void check_artist(std::string Artist){
    if(Artist == "") throw std::invalid_argument("Author name cannot be empty"); 
}

void check_title(std::string Title){
    if(Title == "") throw std::invalid_argument("Title cannot be empty");
}

void check_length(unsigned int Length){
    if(Length <= 0) throw std::invalid_argument("Lnegth in seconds must be a positive integer");
}

Song::Song
(
    std::string Artist,
    std::string Title,
    unsigned int Length    
) : artist{Artist}, title{Title}, length{Length}{
    check_artist(Artist);
    check_title(Title);
    check_length(Length);
}
std::string Song::get_artist() const {
    return artist;
}

std::string Song::get_title() const{
    return title;
}

unsigned int Song::get_length() const{
    return length;
}

void Song::set_artist(std::string Artist){
    check_artist(Artist);
    artist = Artist;
}

void Song::set_title(std::string Title){
    check_title(Title);
    title = Title;
}

void Song::set_length(unsigned int Length){
    check_length(Length);
    length = Length;
}

bool Song::operator==(const Song& other) const{
    return artist == other.artist && title == other.title;
}

nlohmann::json Song::to_json() const{
    nlohmann::json j;
    j["artist"] = artist;
    j["title"] = title;
    j["length"] = length;
    return j;
}

std::string Song::to_string() const{
    return fmt::format("{}-{}-{}-{}", artist, title, length, "seconds");
}
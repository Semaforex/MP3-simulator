#include "playlist.hpp"
#include <stdexcept>
#include <iomanip>
#include <fmt/core.h>
#include <fmt/chrono.h>


std::chrono::time_point<std::chrono::system_clock> StringToDate(const std::string &date_str) {
    std::tm t = {};
    strptime(date_str.c_str(), "%Y-%m-%d", &t);
    std::chrono::time_point<std::chrono::system_clock> dp = std::chrono::system_clock::from_time_t(std::mktime(&t));
    auto dp2 = dp + std::chrono::hours(12);
    return dp2;
}


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
) : name{Name}, author{Author}, modifications{std::vector<modify_event>()}, song_list{std::unordered_set<Song>()}{
    check_name(Name);
    check_auhtor(Author);
}

std::string Playlist::get_name() const{
    return name;
}

std::string Playlist::get_author() const{
    return author;
}

std::vector<modify_event> Playlist::get_modifications() const{
    return modifications;
}

std::unordered_set<Song> Playlist::get_song_list() const{
    return song_list;
}

unsigned int Playlist::get_total_length() const{
    unsigned int L = 0;
    for(const auto& song : song_list)
        L += song.get_length();
    return L;
}

void Playlist::change_name(std::string Name){
    check_name(Name);
    name = Name;
}

void Playlist::change_author(std::string Author){
    check_auhtor(Author);
    author = Author;
}
void Playlist::add_song(std::string Artist, std::string Title, unsigned int length){
    Song song = {Artist, Title, length};
    auto succes = song_list.insert(song);
    if(succes.second){
        const std::chrono::time_point now{std::chrono::system_clock::now()};
        modify_event event = {now, PlaylistEvent::add, Artist + " - " + Title};
        modifications.push_back(event);
    }
}

bool Playlist::remove_song(std::string Artist, std::string Title){
    Song song = {Artist, Title, 1};
    if(song_list.erase(song) == 0)
        return false;
    const std::chrono::time_point now{std::chrono::system_clock::now()};
    modify_event event = {now, PlaylistEvent::del, Artist + " - " + Title};
    modifications.push_back(event);
    return true;
}

bool Playlist::operator==(const Playlist& other) const{
    return name == other.name && author == other.author;
}

nlohmann::json Playlist::to_json() const{
    nlohmann::json j;
    j["name"] = name;
    j["author"] = author;
    j["modifications"] = nlohmann::json::array({});
    for (const auto& modification : modifications){
        std::string string_date = fmt::format("{:%Y-%m-%d}", modification.date);
        unsigned int type_int = static_cast<unsigned int>(modification.event_type);
        j["modifications"].push_back({string_date, type_int, modification.song});
    }
    j["song_list"] = nlohmann::json::array({});
    for(const auto& song : song_list)
        j["song_list"].push_back(song.to_json());
    return j;
}

void Playlist::from_json(const nlohmann::json& j){
    name = j.at("name").get<std::string>();
    author = j.at("author").get<std::string>();
    for(const auto& modification : j.at("modifications")){
        std::string dateString = modification.at(0).get<std::string>();
        auto date = StringToDate(dateString);
        PlaylistEvent event_type = static_cast<PlaylistEvent>(modification.at(1).get<unsigned int>());
        modify_event event = {date, event_type, modification.at(2).get<std::string>()};
        modifications.push_back(event);
    }
    for(const auto& song : j.at("song_list"))
        song_list.insert(Song(song.at("artist").get<std::string>(), song.at("title").get<std::string>(), song.at("length").get<unsigned int>()));
}

std::string Playlist::to_string() const{
    std::string result = name + " - " + author + '\n' + "Songs:\n";
    for(auto song : song_list)
        result += song.to_string() + '\n';
    result += "modifications:\n";
    for(auto event : modifications){
        result += fmt::format("{:%Y-%m-%d} - {} - {}",  event.date, PlaylistEventStrings[event.event_type], event.song);
    }
    return result;
}


std::string Playlist::get_modification_string() const{
    std::string result = "modifications:\n";
    for(auto event : modifications){
        result += fmt::format("{:%Y-%m-%d} - {} - {}\n",  event.date, PlaylistEventStrings[event.event_type], event.song);
    }
    return result;
}
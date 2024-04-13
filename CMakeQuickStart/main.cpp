#include "player.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "include/CLI11.hpp"

int main(int argc, char** argv) {
    CLI::App app{"Music Player"};
    app.require_subcommand(1);
    CLI::App* create = app.add_subcommand("create", "Create a new playlist");
    CLI::App* add = app.add_subcommand("add", "Add a song to the playlist");
    CLI::App* remove = app.add_subcommand("remove", "Remove a song from the playlist");
    CLI::App* list = app.add_subcommand("list", "List the playlist");
    CLI::App* play_all = app.add_subcommand("play_all", "Play the playlist");
    CLI::App* modification_history = app.add_subcommand("history", "List the modification history");
    CLI::App* play_song = app.add_subcommand("play_song", "Play a song from the playlist");

    std::string path = "./Playlist/playlist.json";
    std::string author;
    std::string name;
    std::string artist;
    std::string title;
    unsigned int length;

    create->add_option("-a,--author", author, "Author of the playlist")->required();
    create->add_option("-n,--name", name, "Name of the playlist")->required();
    add->add_option("-a,--artist", artist, "Artist of the song")->required();
    add->add_option("-t,--title", title, "Title of the song")->required();
    add->add_option("-l,--length", length, "Length of the song")->required();
    remove->add_option("-a,--artist", artist, "Artist of the song")->required();
    remove->add_option("-t,--title", title, "Title of the song")->required();
    play_song->add_option("-a,--artist", artist, "Artist of the song")->required();
    play_song->add_option("-t,--title", title, "Title of the song")->required();

    create->callback([&](){
        Player player{path, author, name};
    });

    add->callback([&](){
        Player player{path};
        player.add_song(artist, title, length);
    });

    remove->callback([&](){
        Player player{path};
        player.remove_song(artist, title);
    });

    list->callback([&](){
        Player player{path};
        player.list_playlist();
    });

    play_all->callback([&](){
        Player player{path};
        player.play_songs();
    });

    modification_history->callback([&](){
        Player player{path};
        player.list_modification_history();
    });

    play_song->callback([&](){
        Player player{path};
        player.play_song(artist, title);
    });

    try 
    {
        app.parse(argc, argv);
    } 
    catch (const CLI::ParseError &e) 
    {
        return app.exit(e);
    }
}
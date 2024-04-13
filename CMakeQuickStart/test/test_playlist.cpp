#include <catch2/catch_test_macros.hpp>
#include "playlist.hpp"

TEST_CASE("playlist_test-contructor and getters", "[Playlist]"){
    Playlist playlist = {"Name", "Author"};
    REQUIRE(playlist.get_name() == "Name");
    REQUIRE(playlist.get_author() == "Author");
    REQUIRE(playlist.get_modifications().size() == 0);
    REQUIRE(playlist.get_song_list().size() == 0);
    REQUIRE(playlist.get_total_length() == 0);
}

TEST_CASE("playlist_test-constructor invalid arguments", "[Playlist]"){
    REQUIRE_THROWS_AS(Playlist("", "Author"), std::invalid_argument);
    REQUIRE_THROWS_AS(Playlist("Name", ""), std::invalid_argument);
}

TEST_CASE("playlist_test-setters"){
    Playlist playlist = {"Name", "Author"};
    playlist.change_name("Name2");
    playlist.change_author("Author2");
    REQUIRE(playlist.get_name() == "Name2");
    REQUIRE(playlist.get_author() == "Author2");
}

TEST_CASE("playlist_test-setters errors"){
    Playlist playlist = {"Name", "Author"};
    REQUIRE_THROWS_AS(playlist.change_name(""), std::invalid_argument);
    REQUIRE_THROWS_AS(playlist.change_author(""), std::invalid_argument);
}

TEST_CASE("playlist_test-add_song"){
    Playlist playlist = {"Name", "Author"};
    playlist.add_song("Artist", "Title", 5);
    REQUIRE(playlist.get_song_list().size() == 1);
    REQUIRE(playlist.get_total_length() == 5);
    playlist.add_song("Artist2", "Title2", 10);
    REQUIRE(playlist.get_song_list().size() == 2);
    REQUIRE(playlist.get_total_length() == 15);
}

TEST_CASE("playlist_test-add_song errors"){
    Playlist playlist = {"Name", "Author"};
    REQUIRE_THROWS_AS(playlist.add_song("", "Title", 5), std::invalid_argument);
    REQUIRE_THROWS_AS(playlist.add_song("Artist", "", 5), std::invalid_argument);
    REQUIRE_THROWS_AS(playlist.add_song("Artist", "Title", 0), std::invalid_argument);
}

TEST_CASE("playlist_test-modifications"){
    Playlist playlist = {"Name", "Author"};
    playlist.add_song("Artist", "Title", 5);
    REQUIRE(playlist.get_modifications().size() == 1);
    playlist.add_song("Artist2", "Title2", 10);
    REQUIRE(playlist.get_modifications().size() == 2);
}

TEST_CASE("playlist_test-modifications errors"){
    Playlist playlist = {"Name", "Author"};
    REQUIRE_THROWS_AS(playlist.get_modifications().at(0), std::out_of_range);
}

TEST_CASE("playlist_test-add_song duplicate song"){
    Playlist playlist = {"Name", "Author"};
    playlist.add_song("Artist", "Title", 5);
    playlist.add_song("Artist", "Title", 5);
    REQUIRE(playlist.get_song_list().size() == 1);
}


#include <catch2/catch_test_macros.hpp>
#include "song.hpp"

TEST_CASE("song_test-contructor and getters", "[Song]"){
    Song song = {"Artist", "Title", 5};
    REQUIRE(song.get_artist() == "Artist");
    REQUIRE(song.get_title() == "Title");
    REQUIRE(song.get_length() == 5);
}

TEST_CASE("song_test-constructor invalid arguments", "[Song]"){
    REQUIRE_THROWS_AS(Song("", "Title", 5), std::invalid_argument);
    REQUIRE_THROWS_AS(Song("Artist", "", 5), std::invalid_argument);
    REQUIRE_THROWS_AS(Song("Artist", "Title", 0), std::invalid_argument);
}

TEST_CASE("song_test-setters"){
    Song song = {"Artist", "Title", 5};
    song.set_artist("Artist2");
    song.set_length(10);
    song.set_title("Title2");
    REQUIRE(song.get_artist() == "Artist2");
    REQUIRE(song.get_title() == "Title2");
    REQUIRE(song.get_length() == 10);
}

TEST_CASE("song_test-setters errors"){
    Song song = {"Artist", "Title", 5};
    REQUIRE_THROWS_AS(song.set_artist(""), std::invalid_argument);
    REQUIRE_THROWS_AS(song.set_title(""), std::invalid_argument);
    REQUIRE_THROWS_AS(song.set_length(0), std::invalid_argument);
}

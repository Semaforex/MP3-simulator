include(AddCatch2)

add_executable(
  unit_tests
  test_song.cpp
  test_playlist.cpp
)
target_link_libraries(
  unit_tests PRIVATE song Catch2::Catch2WithMain
)
target_link_libraries(
    unit_tests PRIVATE playlist Catch2::Catch2WithMain
)

include(CTest)
include(Catch)
catch_discover_tests(unit_tests)

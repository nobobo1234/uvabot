#CMakeLists.txt
cmake_minimum_required (VERSION 3.6)
project(uva-bot)

add_executable(uva-bot source.cpp)

add_subdirectory(deps/sleepy-discord)
target_link_libraries(uva-bot sleepy-discord)
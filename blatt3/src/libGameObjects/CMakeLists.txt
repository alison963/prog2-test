# TODO Aufgabe 1:
#  Fügt dem Projekt die Bibliothek `GameObjects` hinzu, mit den Dateien im Verzeichnis src/libGameObjects/ und der Bibliothek `Sea`.
add_library(GameObjects Constants.h Missile.h Missile.cpp PlayerSea.h PlayerSea.cpp Ship.h Ship.cpp)

target_include_directories(GameObjects PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
TARGET_LINK_LIBRARIES(GameObjects Sea)
#
# ???
#

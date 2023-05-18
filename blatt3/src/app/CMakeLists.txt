# TODO Aufgabe 1:
#  Fügt dem Projekt die Anwendung `Battleship` hinzu, mit den Dateien im Verzeichnis src/app/ und der Bibliothek `GameObjects`.
add_executable(Battelship main.cpp game.h game.cpp init.h init.cpp test.cpp test.h)
TARGET_LINK_LIBRARIES(Battelship GameObjects)
#
# ???
#

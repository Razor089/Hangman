#!/bin/zsh

g++ -Iinc/ src/*.cpp -o bin/hangman

g++ -Iinc/ test/test.cpp src/file.cpp src/game.cpp src/player.cpp -o bin/test_hangman

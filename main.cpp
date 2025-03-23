/*
  	This software and the content provided for use with it is Copyright © 2014-2020 Singular Sound 
 	BeatBuddy Manager is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License version 2 as published by
    the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "src/player/player.h"  // Include the Player class header

int main(int argc, char *argv[])
{
    // Simple command-line flags
    bool playFlag = false;
    bool stopFlag = false;

    // Minimal manual parsing of arguments
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-p" || arg == "--play") {
            playFlag = true;
        } else if (arg == "-s" || arg == "--stop") {
            stopFlag = true;
        } else if (arg == "-h" || arg == "--help") {
            std::cout << "Usage: " << argv[0] << " [options]\n"
                      << "Options:\n"
                      << "  -p, --play       Play the song.\n"
                      << "  -s, --stop       Stop the song.\n"
                      << "  -h, --help       Show this help message.\n";
            return 0;
        }
    }

    // Instantiate the Player object
    Player player;

    // Handle the play command
    if (playFlag) {
        std::cout << "Playing the song...\n";
        player.play();
    }

    // Handle the stop command
    if (stopFlag) {
        std::cout << "Stopping the song...\n";
        player.pedalDoubleTap();
    }

    // If neither play nor stop was provided, print usage instructions
    if (!playFlag && !stopFlag) {
        std::cout << "No valid command provided.\n"
                  << "Use -p or --play to play the song, or -s or --stop to stop the song.\n";
    }

    // Enter an interactive loop for additional commands
    std::string command;
    while (true) {
        std::cout << "\nEnter a command (play, stop, t/transition, quit): ";
        std::cin >> command;

        if (command == "play") {
            std::cout << "Playing the song...\n";
            player.play();
        } else if (command == "stop") {
            std::cout << "Stopping the song...\n";
    	    player.pedalDoubleTap();
        } else if (command == "t" || command == "transition") {
            std::cout << "Executing transition...\n";
            player.pedalPress();
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            player.pedalRelease();
        } else if (command == "quit") {
            std::cout << "Exiting...\n";
            break;
        } else {
            std::cout << "Invalid command. Try again.\n";
        }
    }

    return 0;
}

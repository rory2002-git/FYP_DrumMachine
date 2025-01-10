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
#include "bbmanagerapplication.h"

#include <QCoreApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QDebug>
#include "player.h"  // Include the Player class header

int main(int argc, char* argv[])
{
    // Initialize application
    QCoreApplication app(argc, argv);

    // Command-line parser setup
    QCommandLineParser parser;
    parser.setApplicationDescription("Song Player Control");
    parser.addHelpOption();
    parser.addVersionOption();

    // Define available command-line options
    QCommandLineOption playOption(QStringList() << "p" << "play", "Play the song.");
    parser.addOption(playOption);

    // Parse the command-line arguments
    parser.process(app);

    // Instantiate the Player object
    Player player;

    // Handle the play command
    if (parser.isSet(playOption)) {
        qDebug() << "Playing the song...";
        player.start();  // Start or resume the song playback
    }
    else {
        qDebug() << "No valid command provided. Use -p to play the song.";
    }

    return app.exec();
}

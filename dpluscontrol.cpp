/*
* dpluscontrol.cpp
* (c)2017 - Joshua Holmes, W4JDH <w4jdh@arrl.net>
* Program to manage DPLUS links on a D-STAR repeater.
* /dstar/tmp must be world-writable for this to work most effectively.
* Usage information can be seen by running the program without any arguments.
*
*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main(int argc, char *argv[]) {
	std::vector<std::string> args(argv, argv + argc);
	std::string linkCommand;
	std::ofstream linkFile;
	if (argc < 3 || argc > 5) { std::cerr << "Usage: \nLinking: " << args[0]
			<< " link <local module> <remote repeater> <remote port>\nUnlinking: "
			<< args[0] << " unlink <local module>" << std::endl
			<< "Variable arguments must be in ALL CAPS." << std::endl; }
	else if(args[1] == "link") {
		if(args[3].length() == 4) { linkCommand = args[3] + "  " + args[4] + "L"; }
		else if(args[3].length() == 5) { linkCommand = args[3] + " " + args[4] + "L"; }
		else if(args[3].length() == 6) { linkCommand = args[3] + args[4] + "L"; }
		if (args[2] == "A") {
			linkFile.open("/dstar/tmp/link-a");
			linkFile << linkCommand << std::endl;
			linkFile.close();
		}
		else if (args[2] == "B") {
			linkFile.open("/dstar/tmp/link-b");
			linkFile << linkCommand << std::endl;
			linkFile.close();
			}
		else if (args[2] == "C") {
			linkFile.open("/dstar/tmp/link-c");
			linkFile << linkCommand << std::endl;
			linkFile.close();
		}
		else if (args[2] == "D") {
			linkFile.open("/dstar/tmp/link-d");
			linkFile << linkCommand << std::endl;
			linkFile.close();
		}
	}
	else if(args[1] == "unlink") {
		linkCommand = "       U";
		if(args[2] == "A") {
			linkFile.open("/dstar/tmp/link-a");
			linkFile << linkCommand << std::endl;
			linkFile.close();
		}
		else if(args[2] == "B") {
			linkFile.open("/dstar/tmp/link-b");
			linkFile << linkCommand << std::endl;
			linkFile.close();
		}
		else if(args[2] == "C") {
			linkFile.open("/dstar/tmp/link-c");
			linkFile << linkCommand << std::endl;
			linkFile.close();
		}
		else if(args[2] == "D") {
			linkFile.open("/dstar/tmp/link-d");
			linkFile << linkCommand << std::endl;
			linkFile.close();
		}
	}
	else {
		std::cerr << "Usage: \nLinking: " << args[0]
			<< " link <local module> <remote repeater> <remote port>\nUnlinking: "
			<< args[0] << " unlink <local module>" << std::endl
			<< "Variable arguments must be in ALL CAPS." << std::endl;
	}
	return 0;
}

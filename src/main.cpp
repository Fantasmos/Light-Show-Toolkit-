
// my first program in C++

#define HAVE_STRUCT_TIMESPEC
#define STRUCT_TIMESPEC_HAS_TV_SEC
#ifdef __arm__
<<<<<<< HEAD
#define RaspberryPi
#warning Compiling for Raspberry PI, errors may occur on other platforms
=======
#warning Compiling for Raspberry PI, errors may occur on other platforms
#define RaspberryPi
#define RPI
>>>>>>> 033ce288d9292d359845386dab6b2a99638b6832
#endif

#include "config.h"
#include <stdint.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <memory>
#include "SongPlayer.h"
#include "CommandLineInterface.h"

<<<<<<< HEAD

=======
>>>>>>> 033ce288d9292d359845386dab6b2a99638b6832

void signalHandler(int signum)
{
	std::cout << "Interrupt signal (" << signum << ") received.\n";
	CommandLineInterface::RUNNING = false;
#if USING_SDL == 1
	SDL_Quit();
#endif
	exit(signum);
}

int main(int argc, char *argv[])
{
	std::unique_ptr<CommandLineInterface> cli = std::make_unique<CommandLineInterface>();
	if (argc > 1)
	{
		for (auto i = 0; i < argc - 1; i += 2)
		{
			cli->ParseLine(std::string(argv[i]) + std::string(" ") + std::string(argv[i + 1]));
		}
	}
	else
	{
		cli->Run();
	}

#if USING_SDL == 1
	SDL_Quit();
#endif
	return 0;
}

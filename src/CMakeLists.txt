
cmake_minimum_required(VERSION 3.7)
project(LightShowProject)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17 -pthread")
set(CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_STANDARD 17)

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 sdl2)
PKG_SEARCH_MODULE(SDLMAIN  sdl2_main)
PKG_SEARCH_MODULE(SDL_NET SDL2_net>=2.0.0)
PKG_SEARCH_MODULE(SDL_MIXER SDL2_mixer>=2.0.0)

find_path(SDL2_INCLUDE_DIRS NAME SDL.h HINTS "../../library/SDL2/include")
find_library(SDL2_LIBRARIES NAME SDL2 HINTS "../../library/SDL2/lib/x86")

find_path(SDLMAIN_INCLUDE_DIRS NAME SDL_main.h HINTS "../../library/SDL2/include")
#find_library(SDLMAIN_LIBRARIES NAME SDL2main HINTS "../../library/SDL2/lib/x86")

find_path(SDL_NET_INCLUDE_DIRS NAME SDL_net.h HINTS "../../library/SDL2_net/include")
find_library(SDL_NET_LIBRARIES NAME SDL2_net HINTS "../../library/SDL2_net/lib/x86/")


find_path(SDL_MIXER_INCLUDE_DIRS NAME SDL_mixer.h HINTS "../../library/SDL2_mixer/include")
find_library(SDL_MIXER_LIBRARIES NAME SDL2_mixer HINTS "../../library/SDL2_mixer/lib/x86/")

add_executable(LightShowProject
config.h

BinaryLightController.h
Colour.h
CommandLineInterface.h
ConsoleLight.h
FileParser.h
GroupManager.h
LightShowFileReader.h
Milight.h
SDL_TCPSender.h
SDL_UDPSender.h
SongPlayer.h
BinaryLight.h
GPIO_PI.h
BinLight_SYSFS.h
ProgrammableLight.h
SDL_Light.h
ProxyMaker.h
ProgrammableLight_Async.h
Light_Command.h
Light_Command_Queue.h
LIGHT_COMMAND_TYPE.h
UserCommand.h
AudioPlayer_Dummy.h
SDL_AudioPlayer.h
Tick_Listener.h
ProxyMaker.cpp
main.cpp
Colour.cpp
Colour_Combiner.cpp
Command.h
CommandOperation.h
CommandType.h
CommandLineInterface.cpp
ConsoleLight.cpp
GroupManager.cpp
Milight.cpp
SDL_TCPSender.cpp
SDL_UDPSender.cpp
SongPlayer.cpp
GPIO_PI.cpp
BinLight_SYSFS.cpp
SDL_Light.cpp
)

INCLUDE_DIRECTORIES(LightShowProject ${SDL2_INCLUDE_DIRS} ${SDL_MIXER_INCLUDE_DIRS} ${SDL_NET_INCLUDE_DIRS})

if(${SDL2_FOUND})
	message("SDL2 FOUND" )
elseif()
	message(status "SDL2 NOT FOUND")
endif(${SDL2_FOUND})

if(${SDL_NET_FOUND})
	message("SDL2_NET FOUND")
elseif()
	message(status "SDL2_NET NOT FOUND")
endif(${SDL_NET_FOUND})

if(${SDL_MIXER_FOUND})
	message("SDL2_MIXER FOUND")
elseif()
	message(status "SDL2_MIXER NOT FOUND")
endif(${SDL_MIXER_FOUND})

find_library(wiringPi_LIB wiringPi)
if (NOT wiringPi_LIB)
	message("Wiringpi was not found. Not going to attempt to link the 433mhz project.
There may be compilation issues if you are on Raspberry Pi. Install wiringPi using sudo apt-get install wiringPi")
elseif (wiringPi_LIB)
	target_link_libraries(LightShowProject 433)
endif(NOT wiringPi_LIB)

find_path(RF24 NAME RF24.h HINTS "../RF24")
if(NOT EXISTS ${RF24}/utility/includes.h)
	message("RF24 was not found. Not going to attempt to link projects")
elseif(EXISTS ${RF24}/utility/includes.h)
		target_link_libraries(LightShowProject RF24_proj)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DRPI -lwiringPi")
endif(NOT EXISTS ${RF24}/utility/includes.h)


target_link_libraries(LightShowProject  ${SDL2_LIBRARIES} ${SDL_NET_LIBRARIES} ${SDL_MIXER_LIBRARIES})
target_include_directories (LightShowProject PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

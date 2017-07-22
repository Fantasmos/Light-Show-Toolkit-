# Light-Show-Toolkit

This software can be used to play "Light Show" Files, which are files designed to go along with a light system (Such as Hue or LimitlessLED/Milight) and play a timed lightshow with music!

This works by running a function (which means commands in sequence), which are interpreted properly by each individual system. This program will begin running the function "Play" from a given file, alongside a given song.

The aim is for future light systems to be added, allowing for a standard method. 

## Libraries utilised

This program uses SDL for audio playback and TCP/UDP networking, more specifically: SDL2, SDL2_mixer and SDL2_net


## Using the CLI

* LoadMain <LightShowFile.lightshow>: Is used to load the file used to play the song

* LoadSupport <LightShowFile.lightshow>: Loads a file that the "FunctionName" command will also search inside

* Run <AudioFile.wav>: Begins executing the "Play" function, with the given music

* Help: Prints out some helpful text


## LightShow file format
The lightshow file format is a unique file format used by this program, "Example.lightshow" outlines the syntax and functionality of the format

Generally, a function is a collection of sequential commands. A command has three properties: 
* What the command does
* The Operator
* The Value

The "Play" Function is where the song starts from.

If you are still confused, Example.lightshow will definetely clear up a few questions

## Available "Commands"
* ColourChange: Change the colour to what is specified for the currently selected groups
* Wait: Pause for an amount of seconds
* Group: Set the current group  
* FunctionName: Run another function
* SpecificCommand: Passes a string to the light class, for individual interpretation
  
## Available Operations
Operations can be applied to a command, changing their functionality

Within the lightshow file format, a command preceeded by '+' denotes "add", '-' denotes "Subtract", nothing denotes "Set"

### Set Operator (Default)
* For Colour, will SET the colour to the given value for each "Currently Selected Group" 
* For Group, will SET the "Currently Selected Group" to the given value
* For FunctionName, will run every function
    
### Add operator (+Command)
* For Colour, will ADD the colour to each light individually
* For Group, will ADD the group to the currently selected group
* For FunctionName, will run every command with the + operator
### Subtract Operator (-Command)
* The opposite for each

### Repeat Operator (Integer)
* For a function, will execute it the given number of times

## General Principle of changing a light's colour:

To change the colour of a light, 
1. FIRST you set the "Current Groups" to the light.
2. Secondly you fire off a Colour. 

## Settings Files

### LimitlessLED/Milight Settings
MiLightSettings.txt holds the settings for LimitlessLED/MiLight. 
* The first line is the IP Address (e.g: 10.0.0.65)
* The second line is the PORT (e.g: 8899)
* The third line is UDP or TCP (Protocol to use)

## Currently Supports: 
### Currently Supported Light-Systems: 
* Milight/LimitlessLED

### Currently supported File-Formats for light-shows
* .LS (Lightshow file format)
### Currently supported Operating systems
* Windows

### Currently support audio file formats
* Windows: .Wav

## Compiling
### Windows
I run Compile.bat with G++, works fine. 

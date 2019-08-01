# bitbitJAM3
central repository for experiments, assets, and game dev for [bitbitJAM3: Red Hot Princess Carnage][1]

* [Overview](#overview)
* [Game](#game)
* [Directory Structure](#directory-structure)
* [Dev Setup](#dev-setup)
  - [Linux](#linux)
  - [OSX](#osx)
  - [Windows](#windows)

## Overview
bitbitJAM is a 1-week game jam to produce a game targetted for a 8-bit or 16-bit computer or game system. David Frankel, Vivekanand Vimal, and Quin Kennedy are working together to create a game. They are targetting the GameBoy(Color?Advanced?) system.

## Game
Undecided. Must incorporate theme of _Red Hot Princess Carnage_. Interests involve:

* recursive game mechanics
* [bytebeat][3] audio
* changing dimensions/modes with color palette swaps

## Directory Structure

This repository is broken up into four main parts

* [art/](art/) contains art assets (backgrounds, sprites, fonts) created for the game
* [gbdk/](gbdk/) is the GBDK included as a submodule
* [prod/](prod/) is the actual game
* [proto/](proto/) contains a series of tests and prototypes

Other folders include

* [tools/](tools/) contains some utilities, mainly for producing art assets
* [vagrant_files/](vagrant_files/) contains Vagrant-specific scripts and configuration files

## Dev Setup
### Linux:

Most of the development occured on an Ubuntu 16.04 machine. I used Vagrant to create a development sandbox, which means this should work relatively painlessly on Windows or OSX as well.

#### Dependencies

* [VirtualBox](https://www.virtualbox.org/)
* [Vagrant](https://www.vagrantup.com/)
* [git](https://git-scm.com/)
* [mednafen](http://mednafen.fobby.net/)

#### Setup

0. `git clone --recursive https://github.com/quinkennedy/bitbitJAM3.git`
0. `cd bitbitJAM3`
0. `vagrant up`
  * This will update the Vagrant box with the necessary dependencies and compile the GBDK
0. `vagrant ssh`

#### Usage

When you are logged into the Vagrant guest OS, you can run `make` from any project directory to build that project into a GameBoy ROM image.

From your host OS you can run the GameBoy ROM image using `make run`.

### OSX

### Windows

This was set up on Windows 10, the directions included with the original GBDK were sufficient to get it working.

#### Dependencies

* A GameBoy emulator
  - [GBG](http://www.zophar.net/gb/bgb.html)
  - [vba10](https://www.microsoft.com/en-us/store/apps/vba10/9nblggh2k04v)

#### Setup

0. download _gbdk-2.95-3-win32.zip_ from the [sourceforge][4] site
0. unzip it to a location you want to "install" it 
  * for me that was _D:\appswinx\_ , the standard choice would be _"C:\Program Files (x86)\"_
0. edit your system `Path` to include GBDK's _bin_ directory
  * I get to it by opening a file explorer, right-clicking on _This PC_, selecting _Properties_, selecting the _Advanced Systems Settings_ link on the right, and clicking the _Environment Variables_ button near the bottom
  * Once you have the _Environment Variables_ dialog open, you can edit an existing _User variable_ (if you have one named `Path`) or create a new _User variable_ named `Path`
  * add the path to GBDK's _bin_ directory, so if you unzipped to _C:\_ it might be _C:\Program Files (x86)\gbdk\bin_
  * 

#### Usage

There are not scripts for Windows yet, so you need to run `lcc -o rom.gb file.c` from a command prompt to compile. Where _rom.gb_ would be the name of the output GameBoy rom you want to create, and _file.c_ is the name of the C file to compile.

[1]: http://bitbitjam.com/
[2]: http://mednafen.fobby.net/
[3]: http://greggman.com/downloads/examples/html5bytebeat/html5bytebeat.html
[4]: https://sourceforge.net/projects/gbdk/files/gbdk-win32/2.95-3/

--

http://gamejolt.com/games/her-sovereign-virus/162382

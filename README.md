# langton-ant
A simple implementation of Langton's ant
Information about the rules of the cellular automata can be found by following this link:
https://en.wikipedia.org/wiki/Langton%27s_ant

[![Screen_Shot_2017-11-25_at_12.52.26_PM.png](https://s7.postimg.org/ualk0pcp7/Screen_Shot_2017-11-25_at_12.52.26_PM.png)](https://postimg.org/image/wrxb7ywlj/)

## Dependencies
* SDL2
* CMake

## Usage guide
1. Clone the repository via typing `git clone https://github.com/Balajanovski/langton-ant.git` into your terminal
2. Enter the reposity by typing `cd langton-ant`
3. Generate a makefile by typing `cmake .`
4. Build the project by typing `make`
5. Run it by typing `./langton [width] [height] [cell_size_in_px] [num_of_ants]` where the values in the square brackets are replaced by the values of your choosing

## Planned features
* Config file
* Multi-threading

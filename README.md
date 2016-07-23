# Example "Coming Soon" Application
This application is an simple example SDL program originally created to communicate to Linux users on Steam that [Day of the Tentacle Remastered](http://dott.doublefine.com) was close, but not ready for release.

When Day of the Tentacle Remastered was set up in a private testing branch, Steam would indicate to users who had previously purchased the game that they could download and play it. When the user attempted to run the game, they would receive an error about a "missing executable."

To avoid this situation and to remind Linux users that we were being thoughtful, I created this small application which could be placed in the default branch usign the same executable name as the final game. When attempting to run the game, users would now see a window containing a Day of the Tentacle themed graphic and "coming soon" message thanking them for their patience.

This had the upside of reassuring Linux users that work was being made, allowed Linux users to receive Steam card drops before released, and quelled panick about platform statistics for users who wanted to purchase before the Linux version was ready. By using a penguin in the graphic, we were also able to generate additional excitement and positivity regarding the then yet-to-be-released port.

For more information on Day of the Tentacle Remastered's Linux port, visit http://cheesetalks.net/porting_dott.php


## Files and Usage

* **main.c** contains all application source code
* **splash_image.c** contains macro definitions for a char array representing the image to be rendered, as well as relevant image metadata
* **icon_image.c** contains macro definitions for a char array representing the image to be used as a window icon, as well as relevant image metadata
* **README.md** is this file

To customise this application, replace **splash_image.c** and **icon_image.c** with files containing data for your desired images. **splash_image.c** and **icon_image.c** were exported via the GIMP using the RGBA C-source image dump exporter and the following options:

* Save comment to file: No
* Use Glib types (guint8*): No
* Use macros instead of struct: Yes
* Use 1 byte Run-Length-Encoding: No
* Save alpha channel: Yes
* Save as RGB565 (16-bit): No


## Dependencies and Compiling
The application requires [SDL2](http://libsdl.org).

GCC compilation on a typical Linux distro install with SDL2 development packages installed will look like this:
``gcc main.c `sdl2-config --libs` -o my-cool-game``

## Licence
The sources for this application are licenced under the MIT Licence, with full terms below:

Copyright (c) 2016 Josh "Cheeseness" Bush

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to
deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
IN THE SOFTWARE.


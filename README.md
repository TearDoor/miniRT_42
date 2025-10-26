# miniRT
My first Raytracer with MiniLibX

## Usage
#### before running for first time
clone the submodules [libft](https://github.com/TearDoor/libft_42) and [minilibx](https://github.com/42Paris/minilibx-linux) before compiling for the first time
```sh
git submodule update --init --recursive
```
Then, cd into mlx_linux and run `./configure` or `make` to compile mlx
* Note on Arch(or any system using modern C compiler) before compiling go to `mlx_linux/test` 
and modify `Makefile.mk` - add `-std=gnu90` to CFLAGS

#### How to run the program
pass a scene description with .rt extension as the first argument to the `miniRT` program

example
`./miniRT rt_files/sample.rt`

### Controls
* Most of the controls will automatically change the rendering to low-res to for faster performance, press `space` to togggle it back to normal

#### Mouse
* Scrolling mouse wheel moves the camera forwards and backwards
* `Left Mouse` press and hold when over object to move up/down/left/right based on camera angle

#### Keyboard
* `Esc` quits the program
* Press 1 to control the camera (default)
* Press 2 to control the lights
* Press 3 to control the objects' rotation
* `Backspace` resets the camera postion and angle to default
* `Space` to toggle between low-res and normal-res rendering

#### Camera controls

* `WASD` changes the camera angle to tilt up/down or pan left/right
* `QE` rolls the camera clockwise/counter-clockwise
* `Arrow Keys` to move the camera up/down/left/right without changing angle

#### Light controls

* `TAB` changes the current selected light
* `Q` to toggle the light on/off
* `WASD` moves the selected light up/down/left/right
* `RF` moves the selected light front/back

#### Object controls

* `TAB` changes the current selected object
* If currently mouse is holding object, the object will be the controlled object
* `WS, AD, QE` rotates the object around its X,Y, and Z axis 
* `C` toggles checkered pattern

## References
[The Ray Tracer Challenge](http://raytracerchallenge.com) - Most of the methods of implementing a raytracer is based on this book

[Texture Mapping](http://raytracerchallenge.com/bonus/texture-mapping.html) - Bonus of the raytracer challenge book.

Explaination of dot products and cross products - [BetterExplained](https://betterexplained.com)

Mouse dragging movement calculation based on another miniRT submission - [ricardoreves](https://github.com/ricardoreves/42-minirt/blob/main/srcs/ui/mouse.c)

Rotation matrix to align two vectors formula - [link](https://gist.github.com/kevinmoran/b45980723e53edeb8a5a43c49f134724)

Formula for quadratic formula to avoid catastrophic cancellation - [Scratch a pixel](https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-sphere-intersection.html)

## Texture Files
The earth texture/bump map files used are downloaded from [this website](http://planetpixelemporium.com/earth.html) (see "color map")

More textures from [Poly Haven](https://polyhaven.com/textures)

Converted from jpg to ppm using [ImageMagick](https://imagemagick.org/script/download.php). Command used:
`$ magick image.jpg -compress none image.ppm`

## Contribution
* [Theodore Tio](https://github.com/TearDoor)
* [Natalie](https://github.com/hni-natalie)

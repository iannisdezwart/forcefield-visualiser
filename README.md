# Forcefield visualiser

Special credits to [DDunda's C# Field generator](https://github.com/DDunda/Field-generator). This was my main inspiration for this project.

![output](https://user-images.githubusercontent.com/38715718/109413160-527a1380-79ac-11eb-8dc8-35c34320da4b.gif)

### Dependencies

You might need to install `libpng-dev`.
The following command installs it on debian-based systems:

```sh
$ sudo apt-get install libpng-dev
```

### Compilation

Compile the program with:

```sh
$ make
```

### Execution

After you have compiled the program, execute it with:

```sh
$ ./forces
```

### Converting PNGs to MP4

After you ran the program, the output PNG files will be stored in the `./output` directory.

Use a tool like `ffmpeg` to convert the PNGs into a video.

On debian-based systems you can install `ffmpeg` with this command:

```sh
$ sudo apt-get install ffmpeg
```

Then execute this command to convert the PNGs into video. Change both `30`s you see in the command to your desired framerate.

```sh
$ ffmpeg -r 30 -i output/%04d.png -c:v libx264 -vf "fps=30,format=yuv420p" out.mp4
```

ExtensionCorrecter is a little program that will add file extension to files without one.

It currently only support a few image type (PNG, JPG, TIFF, GIF, BMP). This was the first goal of this program.
It accepts different commands/arguments, you can have more information about them by passing the command -help to the program.

Or by reading the following: 

Commands available:

-agressive: even check files with an extension and add the corresponding one.

-nonAgressive: check files without extension and add the corresponding one.

-allSubDir: correct files of current directory and his sub directory.

-onlySubDir: correct only files of sub directory of directory.

-removeExts: Will make sure that files name does not contains multiple extension.

Default commands are: -nonAgressive -removeExts
If you want to specify a path to correct, it MUST be put before any commands.
Example: [path] -cmd -cmd...

While it executes, the program will display all the filename that it might parse.

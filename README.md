This repository will be used for storing the classwork, homework and course projects.

The student work must be submited from a separate working branch.

All the work is expected to be done in Linux environment, particularly in Ubuntu.

For this reason, tha students are advised to either download install Ubuntu image as a bootable operating system in their PCs, use virtual machine software (e.g. VM Workstation player or Virtual Box) or install Windows Subsystem for Linux (WSL).

After installation the following tools should be installed from the terminal:

- ```git``` for working with the repo
- ```vim``` for editing
- ```gcc``` with ```g++``` for compiling
- ```gdb``` for debugging
- ```cmake``` for build automation
- ```flex```` for lexical analysis

Installation can be performed using [apt command in Ubuntu](https://ubuntu.com/server/docs/package-management).

Suitable IDE for easier programming, like VSCode, with ```vim``` extension may also be installed.

Common ```git``` commands may be found [here](https://www.freecodecamp.org/news/10-important-git-commands-that-every-developer-should-know/).

Compiling with g++:
```
g++ <source files> -o <output executable file>
```

Compiling for GDB debugging:
```
g++ <source file paths> -g -o <path to output executable>
```

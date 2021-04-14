# Simple shell 🐚
[![image.jpg](https://i.postimg.cc/vHFSG4DY/image.jpg)](https://postimg.cc/9zbBpFGK)

## About "simple shell"

This project is a simple UNIX command interpreter. Simple Shell can be execute in two ways, the interactive and non-interactive mode.

The objective to make this project was to learn about:
- How does a shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of main
- How does the shell use the PATH to find the programs
- How to execute another program with the execve system call
- How to suspend the execution of a process until one of its - - children terminates
- What is EOF / “end-of-file”?

_We decided not to use several of the existing functions, to have the opportunity to develop them ourselves, all this for academic purposes._


## How to install simple shell
- You can be on Ubuntu 14.04 LTS or Ubuntu 20.04 LTS
- You must clone the repository
```
https://github.com/Jfprado11/simple_shell.git
```
- You can compile in this way
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
- Now you can execute the program

## How to use simple shell
You can use the shell in two different modes: interactive mode and non-interactive mode
### Interactive mode
- To execute the shell in interactive mode type `./hsh`
- Now the prompt will appear and you can type any command you want, to exit the program type command `exit` or `ctrl + D`
#### Example of interactive mode
```
jfprado@JUANFE:~/simple_shell$ ./hsh
$ ls
AUTHORS    built_in.c        env_help   free_matrix.c  hsh               man_1_simple_shell   strdup.c
README.md  c_path            execute.c  help_help      initialization.c  non_interactive.c
_which.c   call_functions.c  exit_help  holberton.h    interactive.c     our_own_functions.c
$ ps
  PID TTY          TIME CMD
   10 pts/0    00:00:00 bash
 4333 pts/0    00:00:00 hsh
 4337 pts/0    00:00:00 ps
$ exit
jfprado@JUANFE:~/simple_shell$
```
### Non-interactive mode
- To execute the non interactive mode type `echo "command" | ./hsh`
- in `"command"` you can type whatever command you want

#### Example of non-interactive mode
```
jfprado@JUANFE:~/simple_shell$ echo "pwd" | ./hsh
/home/jfprado/simple_shell
jfprado@JUANFE:~/simple_shell$ echo "ls" | ./hsh
AUTHORS    built_in.c        env_help   free_matrix.c  hsh               man_1_simple_shell   strdup.c
README.md  c_path            execute.c  help_help      initialization.c  non_interactive.c
_which.c   call_functions.c  exit_help  holberton.h    interactive.c     our_own_functions.c
jfprado@JUANFE:~/simple_shell$ echo "ps" | ./hsh
  PID TTY          TIME CMD
   10 pts/0    00:00:00 bash
 4569 pts/0    00:00:00 hsh
 4570 pts/0    00:00:00 ps
jfprado@JUANFE:~/simple_shell$
```

## Built-in functions
The Simple Shell has as built-in functions:
- env: Prints the current environment.
Usage:
``
env
``
- exit: Exits the shell (do not handle arguments)
Usage:
``
exit
``
- help: Display the help information about built-in functions.
Usage:
``
help [BUILTIN]
``

## Flowchart
![Flowchart](https://drive.google.com/uc?export=view&id=1mXgSb9QbpMzP7r5iQ6U0tVwUgFengulO)

## Authors

Juan Felipe Prado Cruz

Paula Louvani Hernandez Morales

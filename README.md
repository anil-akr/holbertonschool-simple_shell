Simple Shell
Description
Simple Shell is a simplified implementation of a UNIX command line interpreter, developed as part of
the Holberton School curriculum.
This project aims to provide a deeper understanding of how a shell works internally, including process
management, environment variables, and fundamental system calls such as fork , execve , and
wait .
The shell reproduces basic behavior similar to /bin/sh , with a limited and well-defined feature set
based strictly on the project requirements.
Features
The Simple Shell is able to:
Display a prompt and wait for user input
Execute commands using an absolute path ( /bin/ls )
Execute commands using the PATH environment variable ( ls )
Handle commands with arguments ( ls -l /tmp )
Implement the following built-in commands:
exit : exit the shell
env : print the current environment
Support interactive and non-interactive modes
Handle the EOF condition (Ctrl+D)
Display appropriate error messages
Never call fork() if the command does not exist
Non-implemented Features
According to the project constraints, the shell does not support:
Command separators ( ; )
Pipes ( | )
Redirections ( > , < , >> )
Special characters ( " , ' , \\ , * , & , # )
Cursor movement
Custom environment variables
Aliases
•
•
•
•
•
•
•
•
•
•
•
•
•
•
•
•
•
•
1
Project Architecture
The project is organized in a modular way to clearly separate responsibilities.
holbertonschool-simple_shell/
│
├── main.c # Shell main loop
├── shell.h # Project header file
│
├── prompt.c # Prompt display
├── read_line.c # User input reading
├── parse_line.c # Command parsing into argv
│
├── builtins.c # Built-in commands (exit, env)
├── execute.c # External command execution
├── path.c # PATH handling
├── error.c # Error handling
├── free.c # Memory management
│
└── README.md # Project documentation
How the Shell Works
The shell displays a prompt (if interactive)
It reads the user input
The input line is parsed into arguments ( argv )
The shell checks if the command is a built-in
If the command is not a built-in:
The command is searched using the PATH
The executable is verified
fork() and execve() are called
The parent process waits for the child process to finish
Allocated memory is freed
The prompt is displayed again
Built-in Commands
exit
exit
Exits the shell
Does not accept arguments
Does not call fork()
1.
2.
3.
4.
5.
6.
7.
8.
9.
10.
11.
•
•
•
2
env
env
Prints all environment variables
Uses the global environ variable
Does not call fork()
Non-interactive Mode
The shell supports command execution through pipes:
echo "/bin/ls" | ./simple_shell
In this mode:
The prompt is not displayed
Commands are read from standard input
Error Handling
If a command does not exist:
./simple_shell: command not found
The shell never exits unexpectedly on error
fork() is never called when a command is invalid
Compilation
Compile the project using:
gcc -Wall -Werror -Wextra -pedantic *.c -o simple_shell
Usage Examples
$ ./simple_shell
$ ls
$ ls -l /tmp
•
•
•
•
•
•
•
•
3
$ /bin/ls
$ env
$ exit
Requirements
Operating System: Linux
Compiler: GCC
Coding Style: Betty
Allowed system calls and functions include:
fork , execve , wait , getline , stat , access , malloc , free
Authors
Project developed as part of Holberton School.
Audu Mila
Aker Anil
Cornibe Ilan
License
This project is for educational purposes only.
•
•
•
•
•
•
•
•
4

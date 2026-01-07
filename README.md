# Simple Shell

## Description
Simple Shell is a simplified implementation of a UNIX command line interpreter, developed as part of the Holberton School curriculum.  
This project provides a deeper understanding of how a shell works internally, including process management, environment variables, and fundamental system calls such as `fork`, `execve`, and `wait`.  
The shell reproduces basic behavior similar to `/bin/sh`, with a limited and well-defined feature set based strictly on the project requirements.

---

## Features
The Simple Shell is able to:  
- Display a prompt and wait for user input  
- Execute commands using an absolute path (e.g., `/bin/ls`)  
- Execute commands using the `PATH` environment variable (e.g., `ls`)  
- Handle commands with arguments (e.g., `ls -l /tmp`)  
- Implement the following built-in commands:  
  - `exit`: exit the shell  
  - `env`: print the current environment  
- Support interactive and non-interactive modes  
- Handle the EOF condition (Ctrl+D)  
- Display appropriate error messages  
- Never call `fork()` if the command does not exist  

### Non-implemented Features
According to project constraints, the shell does not support:  
- Command separators (`;`)  
- Pipes (`|`)  
- Redirections (`>`, `<`, `>>`)  
- Special characters (`"`, `'`, `\`, `*`, `&`, `#`)  
- Cursor movement  
- Custom environment variables  
- Aliases  

---

## Project Architecture

```
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
```

---

## How the Shell Works
1. The shell displays a prompt (if interactive)  
2. It reads the user input  
3. The input line is parsed into arguments (`argv`)  
4. The shell checks if the command is a built-in  
5. If the command is not a built-in:  
   - The command is searched using the `PATH`  
   - The executable is verified  
   - `fork()` and `execve()` are called  
   - The parent process waits for the child process to finish  
6. Allocated memory is freed  
7. The prompt is displayed again  

---

## Built-in Commands

### `exit`
- Exits the shell  
- Does not accept arguments  
- Does not call `fork()`  

### `env`
- Prints all environment variables  
- Uses the global `environ` variable  
- Does not call `fork()`  

---

## Non-interactive Mode
The shell supports command execution through pipes:

```bash
echo "/bin/ls" | ./simple_shell

The project is organized in a modular way to clearly separate responsibilities:



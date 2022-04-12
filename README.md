# Simple Shell Project
> Create a simple UNIX command interpreter in C programming language

## Description

This is a project for Holberton School Peru. The objective is to create a simple UNIX command interpreter with limited functionality but applying main functionalities of a more robust shell. Shell is a program that takes commands from an input given by the user in order to perfomm this in the opearting system.  Typical operations performed by shell scripts include file manipulation, program execution, and printing text.

Previously, we need to learn about:
* How does a shell work.
* What is a PID and a ppid, and how to use them.
* How to manipulate the environment of the current process.
* What is the difference between a function and a system call.
* How to create processes.
* How does the shell use the ```PATH``` to find the programs.
* How to execute another program with the ```execve``` system call.
* How to suspend the execution of a process until one of its children terminates.

## Technologies & Tools
+ Allowed editors: **vi**, **vim**, **emacs**
+ Git platform: **Github**
---

## Requirements
Installed gcc (GNU Compiler Collection) version 4.8.4 or newer.

---

## Example
### Clone repo using HTTPS
```
$ git clone https://github.com/Leslor/simple_shell.git
```

### Compilation
You can compile the files using this command to check that there are no errors:
```
$ gcc -Wall -pedantic -Werror Wextra *.c -o hsh
```

### Usage
After you have cloned this repository and compiled the program with the command above, you will generate a file called **hsh** that can be executed by entering  ```./hsh``` in your shell. Last step will display the interactive mode:

```bash
$ ./hsh
 mysimple@shell $ /bin/ls
 README.md main.h shell.c tokens.c frees.c
 mysimple@shell $
 mysimple@shell $ exit
$
```
---

## Contribution
Create a new branch with the name of your feature or fix and make a pull request to develop branch explaining your work.

---

## Authors
* **Leslie Paz** - [Leslor](https://github.com/Leslor)
* **Yohel Cruz** - [yohelce](https://github.com/yohelce)

# Pipex - 42 School Project

# Overview
  	Pipex is a C programming project from the 42 School curriculum. It simulates the behavior of shell pipes (|) by 	redirecting input from a file through multiple commands and writing the final output to another file. This 		project focuses on mastering UNIX system calls like pipe(), fork(), dup2(), and execve().
  	The program takes four arguments:
		- <infile>: The input file.
		- <cmd1>: The first command.
 		- <cmd2>: The second command.
		- <outfile>: The output file.
## Example usage:
	./pipex infile "ls -l" "wc -l" outfile
	This replicates: < infile ls -l | wc -l > outfile.

# Features
    Handles basic piping between two commands.
    Supports error management (e.g., file not found, command not executable).
    [Optional Bonus Features: Add if applicable, e.g., "Supports multiple pipes" or "Implements here_doc (<< LIMITER) functionality."]

# Usage
	Run the program with the following syntax:
	./pipex infile "command1" "command2" outfile

# Example:
	./pipex input.txt "grep hello" "sort" output.txt

# Project Structure
    pipex.c: Main logic for parsing arguments and setting up pipes.
    utils.c: Helper functions (e.g., error handling, string manipulation).

# Learning Outcomes
    Understanding UNIX processes and inter-process communication (pipes).
    File descriptor management with dup2().
    Command execution in a child process using execve().

# Requirements
    A UNIX-based system (Linux, macOS).
    GCC or another C compiler.

# Author
	[kolani Biman / b-kolani]

# Process Management in C
I leaned the 3 topics.
1. Process management
2. Pipe implementation
3. Command execution
4. File redirection
5. Error handling

## Process Management
I practiced the below system call
* fork()    --  create a new process
* wait()    --  wait for process termination
* waitpid() --  " " " "

## Pipe implementation
Learn about way to use pipe command

Implementation the pipe command
* pipe()    --  Postfix delivery to external command


## Command execution
Learn about way to execute commands in the context of the "pipex" program.

Using the function can be replace the current process with a new process
running the desired command.
* execve()  --  execute a file

## File redirection
Lean about the way to handle file input and output redirection
using system calls like open(), close(), dup(), and dup2().
* dup, dup2 --  duplicate an existing file descriptor

## Error handling
Learn to use the function like perror(), strerror().

These functions provide error messages when system calls or library functions
encounter errors.
* perror(), strerror()    --  system error messages

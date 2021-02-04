# TASK 4:
## 2.) There are many options available for ls but the most important ones are a,l, and R. Write down the meanings of each of these options. 
```
-a
    do not ignore entries starting with .

-l    
    use a long listing format

-R
    list subdirectories recursively
```

## 3.) Move to your home directory and invoke ls with no options. Now invoke ls -l. Now invoke ls -a. Write down how the output of ls differs from the output of ls -a. 
- ***ls*** lists the directories.
- ***ls -a*** lists the all the dotfiles, files, and directories.

## 4.) Different entities may have the same name. For example time as a user command differs from time as a system call. Write down the NAME information for both of these time entities. 
```
(base) ➜  ~ man 1 time
NAME
       time - run programs and summarize system resource usage
```

```
(base) ➜  ~ man 2 time
NAME
       time - get time in seconds
```

## 5.) Of course, man itself is a user command, so it should have a man page. Write down the NAME information for the man page on man. 
```
(base) ➜  ~ man man
NAME
       man - an interface to the system reference manuals
```
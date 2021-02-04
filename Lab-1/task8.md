# Task 8:
## 1.) Copy the file ~/.bash_history to the file ~/dotbashhistory. Write down the exact command you used. 
```
(base) ➜  ~ cp ~/.bash_history ~/dotbashhistory
```

## 2.) Write down the file and directory permissions necessary to successfully copy a file in general.
- source directory: xr
- source file: r
- destination directory: xw
- destination file: w

## 3.) Invoke the exact command again in an attempt to copy the "source" to the now-existing "destination." Write down how the system handled this.
```
(base) ➜  ~ cp ~/.bash_history ~/dotbashhistory
```
- no output

## 4.) Compare the permissions and date on the original file and the copy. Write down if and how they differ.
```
(base) ➜  ~ ls -l ~/.bash_history 
-rw------- 1 blaine blaine 4062 Dec 11 13:02 /home/blaine/.bash_history
```

```
(base) ➜  ~ ls -l ~/dotbashhistory
-rw------- 1 blaine blaine 4062 Feb  4 14:18 /home/blaine/dotbashhistory
```
- No difference between permissions, but they have different dates.
  
## 5.) Write down the cp command you would use to insure that the copy has the same permissions and date as the original. 
```
(base) ➜  ~ cp ~/.bash_history ~/dotbashhistory --preserve
```
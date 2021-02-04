# Task 12:

## 1.) Write down what happens when you invoke rmdir ~/Foo. 
```
(base) ➜  ~ rmdir ~/Foo
rmdir: failed to remove '/home/blaine/Foo': Directory not empty
```

## 2.) Write down a sequence of rmdir commands that would allow removal of the ~/Foo directory and its subdirectory Bar. Don't invoke the commands, just write down what you would do. 
```
(base) ➜  ~ rmdir ~/Foo/Bar
(base) ➜  ~ rmdir ~/Foo
```

## 3.) Invoke a single rm command to remove the ~/Foo directory and all its contents (check the man page). Write down the exact command you used. Hint: it involves two flags, one to force the operation, the other to descend the directory recursively. 
```
(base) ➜  ~ rm -rf ~/Foo
```
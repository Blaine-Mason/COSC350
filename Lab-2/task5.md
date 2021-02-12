# Task 5:
1.)Create a file named numbs that contains the integers 1 through 100, one integer per line. The file will have 100 lines. Write down a short description of how you did this. (You can do it any way you want, including dumb brute force. You might also want to consider the bash for loop or a small C++ program.) 
```
(base) ➜  ~ seq 1 100 > numbs
(base) ➜  ~ man seq
NAME
       seq - print a sequence of numbers

```
- I used the seq command which allows you to output a sequence of numbers, then redirected the output to the file numbs.

2.) Run wc on the file numbs. Write down the output and your explanation of what it means. Check the man page for wc if you're not sure. 
```
(base) ➜  ~ wc numbs
100 100 292 numbs
```
- Number of new lines, words, bytes for file

3.) Use pipes and redirection to produce a second file named somenumbs that contains lines 25 through 38 of numbs. Write down exactly what you did.
```
(base) ➜  ~ tail -n +25 numbs | head -n 14 > somenumbs
(base) ➜  ~ cat somenumbs
25
26
27
28
29
30
31
32
33
34
35
36
37
38

```

4.) Run wc on the file somenumbs. Write down the output and your explanation of
what it means. 
```
(base) ➜  ~ wc somenumbs 
14 14 42 somenumbs
```
- Number of new lines, words, bytes for file
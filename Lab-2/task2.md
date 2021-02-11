# Task 2:
1.)Save your prompt. Write down exactly how you did it. 

```
bash-3.2$ echo $PS1 >> prompt.txt
```
2.) Change your prompt so it looks like [COSC350 basecwd]:
where "basecwd" means the basename of the current working directory. Write down exactly how you did it. 

```
bash-3.2$ PS1="[COSC350 \W]"
```

3.)  Change your prompt to its previous value. Write down exactly how you did it. 

```
[COSC350 ~]PS1=`cat prompt.txt`
bash-3.2$
```
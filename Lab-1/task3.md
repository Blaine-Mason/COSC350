# TASK 3:
## 2.) Write out your answers to the following questions
### a.) What are the permissions on the file?
```
(base) ➜  ~ ls -l foo
-rw-rw-r-- 1 blaine blaine 0 Feb  4 12:51 foo 
```
- read write for users, read write for groups, and just read for others.
### b.)  Who owns the file?
```
(base) ➜  ~ ls -l foo
-rw-rw-r-- 1 blaine blaine 0 Feb  4 12:51 foo 
```
- "blaine" owns the file
### c.) What group is associated with the file?
```
(base) ➜  ~ ls -lg foo
-rw-rw-r-- 1 blaine 0 Feb  4 12:51 foo
```
- the "blaine" group is associated with this file
### d.) Are you in the group? (Invoke groups to find out).
- From the answer below we can see that I am in fact a member of the "blaine" group
### e.) Write down the names of all the groups you are in.
```
(base) ➜  ~ cat /etc/group
root:x:0: daemon:x:1: bin:x:2: sys:x:3: adm:x:4:syslog,blaine tty:x:5:syslog disk:x:6: lp:x:7: mail:x:8: news:x:9: uucp:x:10: man:x:12: proxy:x:13: kmem:x:15:
dialout:x:20: fax:x:21: voice:x:22: cdrom:x:24:blaine floppy:x:25: tape:x:26: sudo:x:27:blaine audio:x:29:pulse dip:x:30:blaine www-data:x:33: backup:x:34: operator:x:37: list:x:38: irc:x:39: src:x:40: gnats:x:41: shadow:x:42: utmp:x:43: video:x:44: sasl:x:45: plugdev:x:46:blaine staff:x:50: games:x:60: users:x:100: nogroup:x:65534:
systemd-journal:x:101: systemd-network:x:102: systemd-resolve:x:103: systemd-timesync:x:104: crontab:x:105: messagebus:x:106: input:x:107: kvm:x:108: render:x:109: syslog:x:110: tss:x:111: bluetooth:x:112: ssl-cert:x:113: uuidd:x:114: tcpdump:x:115: avahi-autoipd:x:116: rtkit:x:117: ssh:x:118: netdev:x:119: lpadmin:x:120:blaine
avahi:x:121: scanner:x:122:saned saned:x:123: nm-openvpn:x:124: whoopsie:x:125: colord:x:126: geoclue:x:127: pulse:x:128: pulse-access:x:129: gdm:x:130: lxd:x:131:blaine
blaine:x:1000: sambashare:x:132:blaine systemd-coredump:x:999: lightdm:x:133: nopasswdlogin:x:134:
```
## 3.) Change the permissions on ~/foo so owner has only execute permission, group has only write permission, and all others have both read and execute permission. Write out the command(s) you used to do this.
```
(base) ➜  ~ chmod u-rw foo
(base) ➜  ~ chmod u+x foo
```
```
(base) ➜  ~ chmod g-r foo
```
```
(base) ➜  ~ chmod o+x foo
```
```
(base) ➜  ~ ls -l foo
---x-w-r-x 1 blaine blaine 0 Feb  4 13:23 foo
```
## 4.) Attempt to delete the file. Write down the command you used and what happened.
```
(base) ➜  ~ rm foo
rm: remove write-protected regular empty file 'foo'?
```
## 5.) Change permissions on ~/foo so you can delete it, then do so. 
```
(base) ➜  ~ chmod u+w foo 
(base) ➜  ~ rm foo
```
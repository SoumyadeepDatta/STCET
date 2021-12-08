# Signal handling using c in Linux
### To kill a process using SIGKILL whose PID is 1234
```
kill -s SIGKILL 1234 
```
1. Use the kill command to find the number of signals available on your system and then write a program that ignores all of them.
```
kill -l
```
2. In what ways can a process behave when it receives a signal? What is special about the SIGSTOP and SIGKILL signals?
```
When a process receives a signal it gets interrupted & the default signal handler is invoked. When the signal handler returns, the interrupted activity is continued.
SIGKILL & SIGSTOP are the only signals which can't be handled by the user. It is handled by the kernel in a default way.
```

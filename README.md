# 42-philosophers

```draw
P: Philosopher
F: Fork

Table:
P1 F1 P2 F2 P3 F3

P1 need F3 and F1
P2 need F1 and F2
P3 need F2 and F3

t1: P1 eat
t1: p2 [NOTHING]
t1: p3 [NOTHING]

t2: p1 sleep
t2: P2 eat
t2: p3 [NOTHING]

t3: p1 thinks
t3: p2 sleep
t3: P3 eat

t4: p1 eat
t4: p2 think
t4: P3 spleep
```

### What a life

The main loop:

1. lock the two forks
2. eat
   1. lock message
   2. write the message
   3. unlock message
   4. wait the eat time
3. unlock the two forks
4. sleep
   1. lock message
   2. write the message
   3. unlock message
   4. wait the sleep time
5. think
   1. lock message
   2. write the message
   3. unlock message
   4. wait available fork

## Informations

### Difference between processes and threads

#### process

The process will duplicate his data into the child.

#### thread

Every threads share the same data.

## Resources

* CodeVault Videos: [Unix Threads in C](https://youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
* Wikipedia: [Dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
* Wikipedia: [Philosopher](https://en.wikipedia.org/wiki/Philosopher)

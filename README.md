# 42-philosophers

```draw
P: Philosopher
F: Fork

Table:
P1 F1 P2 F2 P3 F3

P1 need F3 and F1
P2 need F1 and F2
P3 need F2 and F3
```

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

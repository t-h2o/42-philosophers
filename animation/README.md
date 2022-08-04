# Table of philosophers

```table
TIME   1     2     3     4     5
0      FFE         FFE
400    S     FFE   S     FFE   F
600    T           T
802          S           S     FE
1002         T           T
1202                           S
1402                           T
```

From this log

```log
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
0 3 has taken a fork
0 3 has taken a fork
0 3 is eating
400 1 is sleeping
400 2 has taken a fork
400 2 has taken a fork
400 2 is eating
400 4 has taken a fork
401 4 has taken a fork
401 4 is eating
400 5 has taken a fork
400 3 is sleeping
600 1 is thinking
600 3 is thinking
802 2 is sleeping
802 4 is sleeping
802 5 has taken a fork
802 5 is eating
1002 4 is thinking
1002 2 is thinking
1202 5 is sleeping
1402 5 is thinking
```

## Usage

1. Create a log file

   ```sh
   ./philo ${NUMBER_OF_PHILOS} ... > log
   ```

2. Use animation
   
   ```sh
   ./animation ${PATH_LOG_FILE} ${NUMBER_OF_PHILOS}
   ```

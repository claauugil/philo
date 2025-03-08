# 🍽️ Philosophers

The Dining Philosophers problem is a classic synchronization problem, where multiple philosophers sit at a table and eat. They need two forks to eat, but there is a limited number of forks available. This simulation demonstrates concurrency management using `pthread` and `mutex` in C, allowing philosophers to safely share resources while avoiding deadlock and starvation.

## 🎯 Objective

The goal of the project is to implement a solution to the Dining Philosophers. Philosophers alternate between eating 🍴 and sleeping 💤, while attempting to pick up two forks simultaneously. The simulation ensures that no philosopher dies from starvation and all resources are managed efficiently.

## ⚙️ Features

- Each philosopher is represented as a thread.
- Mutexes are used to prevent race conditions when accessing shared resources (forks 🍽️, print statements, etc.).
- A monitoring thread oversees the simulation, detecting if a philosopher has died ☠️.

## 📝 Notes

- Time values must be at least **60ms** ⏳.
- Negative or non-numeric input values are not allowed.
- If only one philosopher is present, they will pick up a fork and starve (as per the problem constraints).

## 🔢 Arguments

- **number_of_philosophers**: Number of philosophers (and forks 🍴) at the table.
- **time_to_die**: Time (in milliseconds ⏱️) a philosopher can live without eating before dying.
- **time_to_eat**: Time (in milliseconds ⏱️) a philosopher takes to eat.
- **time_to_sleep**: Time (in milliseconds ⏱️) a philosopher takes to sleep.
- **[number_of_times_each_philosopher_must_eat]** (optional): If specified, the simulation stops once all philosophers have eaten at least this many times 🍽️.

## 🚀 Run

Run the program with:
```bash
./philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

# xv6 - OSTEP
This repository contains my implementation for [OSTEP xv6 Kernel Projcts](https://github.com/remzi-arpacidusseau/ostep-projects/tree/master?tab=readme-ov-file#kernel-hacking-projects-xv6) based on the [xv6 Kernel by MIT](https://github.com/mit-pdos/xv6-public).
## Modifications
1. Added new system call `getreadcount()` which returns the total number of disk read operations done since system boot
    - Tested using readtest.c, which adds the `readtest` command to verify disk read counting.
2. changed the Scheduling Policy from `round robin` to `lottery` scheduling
    - Each process has a number of tickets determining its likelihood of being scheduled.
    - The scheduler conducts a lottery after every `time slice` to select the process to run, ensuring proportional CPU allocation based on ticket count.
    - Processes inherit their parent's ticket count by default, with the INIT_TICKETS value assigned to the initial process.
    - Processes can update their ticket count using the `settickets()` system call (up to a maximum of `MAX_TICKETS`).
    - Added the `getpinfo()` system call used to retrieve processes information
        - is the process in use or not.
        - Ticket count.
        - Process ID.
        - Number of lotteries won.
    - `test_lottery [time-to-run] [tickets-num]` command is provided to test the scheduler

        ```bash
        test_lottery 100 1 &; test_lottery 100 100
        
        process with 100 tickets is running
        process with 100 tickets is running
        process with 100 tickets is running
        ...
        process with 1 tickets is running
        ```
## Usage
- Prerequisites: `make qemu gcc`
- Build
    ```bash
    make qemu
    ```

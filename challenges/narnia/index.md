# [Narnia Challenge](https://overthewire.org/wargames/narnia/)

## Overview of the Narnia Challenge

<p align="center">
<img src="./assets/narnia.jpg" width="500" height="500" alt="the chronicles of narnia" />
</p>

### Narnia Challenge Description

**Narnia** is one of the wargames available on **OverTheWire**. It is designed to introduce participants to the fundamentals of binary exploitation and low-level program analysis. Unlike entry-level challenges that focus on command-line usage, Narnia centers on interacting with vulnerable compiled programs, typically written in C, and understanding how they behave at runtime.

The objective of each level is to analyze a provided binary, identify a vulnerability, and exploit it in order to retrieve the password for the next level. Participants connect to the remote server via SSH and are given access to the source code of each vulnerable program, allowing them to study its implementation and reason about potential weaknesses.

Narnia serves as a practical introduction to memory-related vulnerabilities and basic exploitation techniques.

#### General Structure

1. **Levels**: The Narnia wargame consists of multiple sequential levels. Each level provides a vulnerable binary owned by the next user, usually with setuid permissions.
2. **Source Code Access**: The source code for each binary is available to players, enabling static analysis before attempting exploitation.
3. **Exploitation Process**: Players typically analyze the program, identify a flaw (such as improper bounds checking), craft a suitable input, and execute the binary to gain access to the next level’s credentials.
4. **Tools and Techniques**: Common tools and concepts involved include:

   * `gdb`
   * environment variables
   * stack inspection
   * buffer overflows
   * input crafting
   * basic shellcode understanding (depending on the level)

#### Learning Outcomes

* **Understanding Program Behavior**: Develop the ability to read and reason about C source code, particularly regarding memory handling and user input.
* **Introduction to Memory Exploitation**: Learn how common vulnerabilities arise from improper memory management.
* **Debugging and Analysis Skills**: Gain experience using debugging tools to inspect program execution and memory state.
* **Foundation for Advanced Exploitation**: Build the groundwork necessary for tackling more complex binary exploitation challenges.

## Where to Start?

You can start by viewing the walkthrough for the [first level](./narnia0.md)

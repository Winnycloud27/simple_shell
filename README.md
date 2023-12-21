# THE GATE OF SHELL SHALL NOT PREVAIL AGAINST ME

## About

Simple Shell is one of the famous project in Alx Software Engineering that is totally written in C language. It replicates functionalities of UNIX shell (sh). This is one of the most anticipated project and also one that challenges with all the concepts learnt so far in the program in C language:

    * Basics of programming
    * Basics of C
    * Basics of thinking like an engineer
    * Group work
    * and Learning how to learn
    
## COPYRIGHT

Copyright (C) 2023 by Winner Ezaka(@Winnycloud27)
All rights reserved

## Installation

   - Clone this repository.
   - cd to test directory
   - Compile it using `gcc -Wall -Werror -Wextra -pedantic-std=gnu89 ../*.c -o hsh`
   - run `./hsh`

## Usage

After compilation, the resulting program can run stand-alone, either in interactive or non-interactive mode.
Interactive Mode

In interactive mode, simply run the program and wait for the prompt to appear. From there, you can type commands freely, exiting with either the "exit" command or ctrl-D.
Non-Interactive Mode

In non-interactive mode, echo your desired command and pipe it into the program like this:

<button id="copyButton" data-clipboard-target="#copyTarget">Copy</button>

<pre id="copyTarget">
echo "ls" | ./shell
</pre>

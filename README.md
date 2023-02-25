# Turing Machine

A simple Turing machine on **C** that can solve tasks by input file with specific format.

## Getting Started

1. First you need to run `gcc main.c`
2. Then you can run `./main {input file name (e.g. input1.txt)}` for use the program

## Input

Input file format:
1. The first line contains the input string
2. The second line contains the initial and final states, respectively
3. The next lines to the file's end contain the transactions of the Turing machine

Transaction line format: <br />
`"current state" "input symbol" -> "new state" "new symbol" "movement"`

P.S. States that are not initial or terminal are written directly in transitions and nowhere else. `_` is used as a lambda symbol.

## Output

At the end of program's work terminal contains three strings. First string contains information about program work, second string contains output (content of the strip after the end of the work), and third string contains last state and transactions count at the moment of program's finish.

Next paragraphs are about options of first line.

Program has transactions count limit equals 10000. So if it makes 10000 transactions, you get a message: <br />
-> *MADE 10000 transactions*.

If it fails on some transaction, you get a message: <br />
-> *FAIL after* {transactions count} *transactions*.

Else if program successfully finishes, you get a message: <br />
-> *STOP after* {transactions count} *transactions*.

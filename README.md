# TuringMachine

A simple Turing machine on `C` that can solve tasks by input file with specific format.

___

Input format:
1. The first line contains the input string
2. The second line contains the initial and final states, respectively
3. The next lines to the file's end contain the transactions of the Turing machine

Transaction line format: <br />
**`"current state" "input symbol" -> "new state" "new symbol" "movement"`**

___

At the end of program's work terminal should contain two strings. First string contains information about program work, second string contains last state and transactions count at the moment of program's finish.

Next paragraphs is about options of first line.

Program has transactions count limit equals 10000. So if it makes 10000 transactions, you get a message **`MADE 10000 transactions`**.

If it fails on some transaction, you get a message **`FAIL after {transactions count} transactions`**.

Else if program successfully finishes, you get a message **`STOP after {transactions count} transactions`**.
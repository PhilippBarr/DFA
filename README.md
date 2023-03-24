# Deterministic Finite Automaton (DFA)

Deterministic Finite Automaton (or DFA) is a finite state machine that
accepts or rejects strings of characters by parsing them through a sequence
that is uniquely determined by each string.

It consists of:
1) A finite number of states
2) A finite set of symbols
3) A transition function
4) A start state
5) One or many final states

# Description of code logic

To solve this problem i used the C language.

In the code i used as a key element the integers that i read from the file, as
and various other factors eg size of integers in row without ```" "```, size of lines.

- There should be no spaces after the end of each line
- There must not be a double space anywhere in the file
- When entering data from the user, there MUST be a space between the data

# Usage example

1) Enter data from the keyboard: 1 0 1 1 0 ENTER

2) After each input of each element, always press SPACE
3) After entering the last item, press ENTER directly

# Code Functions

```void print(int *a,int length)```

I created it so i can check if my data is correct, and where i want it.
I left it in the code so you too can test the results from any
array i have made, simply by writing the array and its size.

```int *makeArray(int n)```

As its name suggests, it creates a array, i made this function so that i do not have to
write more code every time i allocated memory for arrays i needed.

```int *readInput(int *inputLength)```
Input of numbers by the user, the files are stored in a array where he
is returned as a pointer.

```int findRealInt(int a)```

This function takes the size of one line of the file along with ```" "```  and calculates it
number of integers the line has without spaces.
The most numbers that can be present in one line are 9.

```int *returnRealIntsNumberOnLine(int *array,int length)```

 Returns an array of the actual number of integers present in each row
 (without the spaces ```" "```) using ```findRealInt```.
 
```int *read_ints (int *length)```

It reads the integers from the file and stores them in a array.

```int *find_linesAndLengthOfLine(int *fileLines)```

Finds through the file how many lines the file has and the size of each line along with
the spaces.

```int *findSymbols(int *ints,int *realInts,int *symbolsLength)```

Finds the symbols present in the file (they are on the 2nd line of the file).

```int findStartingState(int *ints,int *realInts)```

Finds the initial state of Our DFA (which is in the 3rd line of the file).

```int *findFinishStates(int * ints,int *realInts,int *lengthOfFinishStates)```

Finds the final states that exist in our file (they are on the 4th line, and
returns an array of them).

```int *findStatesDescription(int *ints,int intsLength,int *realInts,int lines,int *DescriptionLength)```

Finds and returns an array of integers characterizing the states of the automaton.
These states are from the 5th to the last line of our file.

```int *getPouEimai(int *statesDescription,int statesDescriptionLength,int *poyEimaiLength)```

```int *getInput(int *statesDescription,int statesDescriptionLength)```

```int *getPouPaw(int *statesDescription,int statesDescriptionLength)```

These three functions split the one-dimensional array with the description of the states
and each one contains elements of them.
I will show an example of what the arrays contain.

# Code Example

```2 1 2``` If the automaton is in state q2 and with 1 it will go to state q2.

Therefore:

```pouEimai``` ```2```

```meTiInput``` ```1```

```powPaw``` ```2```

```1 1 2``` If the automaton is in state q1 and with 1 it will go to state q2.

Therefore:

```getPouEimai``` ```1```

```getInput``` ```1```

```getPouPaw``` ```2```

 

```
int runDFA(int startState,int *finishStates,int finishStatesLength, int *pouEimai,int *meTiInput, 
int *pouPaw,int eimaiInputPawLength,int *edolesXristi,int edolesXristiLength)
```
This is the main function, it runs the DFA.
It uses the above three arrays, their size as well as the user commands (that is
stored in an array) to return a result for ```TRUE```, ```1``` and for ```FALSE```, ```0```.
I explain it in detail below.

```void isitOrNot(int *ints,int intsLength,int *realInts,int lines)```

It is executed only by main and runs the above functions as well as the while loop for 
the case that the user wants to enter data.

# Methodologies Used

The methodology for creating the automaton is as follows.
After taking the data from the separate file, i split them into variables and arrays to use them, the gist of the code for DFA is in the ```runDFA()``` function.

After i took all the elements from the file and modified them as i wanted, i used them in the
function ```runDFA()``` where there i have:

- ```startState``` Integer with the initial state

- ```finishStates``` Array of final states

- ```finishStatesLength``` Size of the above array

In the above three variables i put the instances of states and their possible transitions
as explained above.

Then, inside the function i use two loops.

1st loop is for the elements given by the user and is executed as many times as the number of them
information he provided.

In 2nd loop i search the three arrays with the old state (```pouEimai```) – input (```meTiInput```) –
next state (```pouPaw```) so that i can find, depending on the user's input, in which state
i am and which one should i go to next?

As soon as i find it, i save this state as the next state in the variable ```currentState``` and
```break``` from the 2nd loop to continue for the next element given by the user.

# File Details

- Items in the file must have only one (```1```) space per symbol read
- The alphabet symbols can be from ```0``` to ```9```
- After each line there should not be an extra space (```" "```) but only a newline


# DFA Example

Let's assume we have the following DFA:

![DFA](https://user-images.githubusercontent.com/103950889/227155748-e9f78de9-d0f1-41ca-96a0-ea13bdd728fd.PNG)

Then the file should contain the following:


```dfa.txt```

```
3
0 1
0
0 1
0 1 1
0 0 0
1 1 2
1 0 0
2 1 2
2 0 2
```

The above file is analyzed here:

```dfaCommented.txt```


```
3	//The DFA has 3 states
0 1	//The alphabet has 2 symbols (0) and (1)
0	//Start state is q0
0 1	//Final state is q0 and q1
0 1 1	//If the DFA is in state q0, with 1 it will go to q1
0 0 0	//If the DFA is in state q0, with 0 it will go to q0
1 1 2	//If the DFA is in state q1, with 1 it will go to q2
1 0 0	//If the DFA is in state q1, with 0 it will go to q0
2 1 2	//If the DFA is in state q2, with 1 it will go to q2
2 0 2	//If the DFA is in state q2, with 0 it will go to q2
```

# Input-Output

If we finish on a ```final state``` then the result is ```TRUE``` else the result is ```FALSE```.


Finished on final state            |  Finished in other state
:-------------------------:|:-------------------------:
![](https://user-images.githubusercontent.com/103950889/227163166-7b2cfa01-0cc9-427a-88eb-df7d2f0e7cf6.PNG)  |  ![](https://user-images.githubusercontent.com/103950889/227164882-5d870791-c10a-4b24-80cc-1e15604fa1ba.PNG)

# Libraries Used

- ```stdio.h```

- ```math.h```
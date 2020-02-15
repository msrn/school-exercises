## Data structures and algorithms* coursework

(Tietorakenteet ja algoritmit -kurssi = TRA)

Goal was to create a program which scans text file and prints the most frequently occuring words in ascending order .

Created with hashtables that use chain collision

**Usage:**
````
./a.out [FILE] 
eg: ./tra big.txt
````

**Performance of the program:**
|File   |Words|Unique|Windows|Ubuntu|
|---|-----|------|-------|------|
small.txt |2 887 | 231 | 0.021s | 0.031s|
TheGun.txt | 7 886 | 1 736 | 0.024s | 0.031s |
MetaMorph.txt | 25 183 | 3 046 | 0.032s | 0.031s
Species.txt | 209 743 | 10 201 | 0.128s | 0.093s
Ulysses.txt | 267 827 | 30 102 | 0.158s | 0.125s
WarPeace.txt | 566 223 | 20 749 | 0.301s | 0.203s 
big.txt | 1 094 050 | 36 573 | 0.650s |  0.390s
soap-text.txt | 2 539 007 |  24 442 | 1.181s |  0.671s|

*Tested using i5-2500k 3,30ghz*

Example output:

````
Total Words: 267980
Unique Words: 30102
TOP 100 UNIQUE WORDS
WORD             VALUE
the              15107
of               8257
and              7282
a                6560

Cont-----------------------
Execution time: 0.1250 seconds
````
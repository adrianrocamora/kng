# Problem F - Krakovia
**Time Limit: 1 second**


Viktor lives in a far and cold country named Krakovia that is passing by difficult times. Viktor works in a factory and after a work day he often goes with some friends to a bar to drink some beers and to dream with better times.


Due to some economical problems the inflation is very high in Krakovia and a beer costs about 5,400,000,000 Krakovian dollars. Because this, is hard to check the value of the bill and to divide its value equally by Viktor and his friends. As you have a good heart you have decided to help them to solve this problem.

### Input
There will be several test cases, each test case stats with two numbers 1 ≤ N ≤ 1000 that is the number of itens in the bill and 1 ≤ F ≤ 20 that represents how many friends are in the bar and should pay the bill. Then there will be N lines, each line represents the value of a item. The value of a item is indicated by an integer 1 ≤ V ≤ 1020. Input is terminated by a bill where N = F = 0.
### Output
For each test case you should print the message: Bill #N costs S: each friend should pay P, where N represents the number of the bill, starting from 1; S indicates the sum of the itens of the bill; and P is how much money each friend should pay, you should calculte this value by dividing the total value of the bill by the number of friends in the bar, if the result is not an integer value just print the integer part of the number, see the sample input/output. After each test case, you should print a blank line.
### Sample Input
```
3 3
5400000000
5400000000
5400000000
3 2
5400000000
5400000000
9000000001
0 0
```
### Sample Output
```
Bill #1 costs 16200000000: each friend should pay 5400000000

Bill #2 costs 19800000001: each friend should pay 9900000000
```

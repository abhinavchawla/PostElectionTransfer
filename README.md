#Post Election Transfers
##Design & Analysis of Algorithms Project, Spring 2015
###Authored by
- Abhinav Chawla         IMT2013002  Abhinav.Chawla@iiitb.org
- Apoorv Vikram Singh    IMT2013006  ApoorvVikram.Singh@iiitb.org
- Siddartha Sekhar Padhi IMT2013043  SiddarthaSekhar.Padhi@iiitb.org


###General Usage:
- To Compile:
```
-$ make

```
- To Clean:
```
-$ make clean

```
- To Run:
```
-$ ./postElectionTransfer
```
- Input Format
	* The First line contains 3 Integers N L K Where:
		* N is the number of Stations
		* L is the number of Station Masters
		* K is the maximum distance a station master can be moves from his place
	* Then L lines follow containing the position of L Station Masters
	* Constraints:
		* L < N <= 10^5
		* N,K and L are positive integers

- The folder TestCases contains various Test Cases to test the program
- To run the program against the testcase:
```
-$ cat <testCase> | ./postElectionTransfer
```
- To automatically create input test cases:
```
-$ python createInput.py <Number of Stations N> 
```

###Pseudo Code
```
1. n is the total number of stations.
2. l is the number of stations which have station masters.
3. k is the maximum number of stations by which a station master can move.
4. m[i] is the position of the ith station master originally.

MAXIMIZE-THE-MINIMUM(n,l,k,m)
	FINAL = m
	int TEMP[l]
	TEMP[0] = MAX(1,m[0]-k)
	TEMP[l-1] = MIN(m[l-1]+k,n)
	ans=1
	low=1,high=(n/(l-1))
	a = (low+high)/2

  WHILE low<=high
		FOR i=0 to l-3
			IF (TEMP[i] + a) < (m[i+1] - k)
				TEMP[i+1] = m[i+1] - k
			ELSE IF (TEMP[i]+a) <= m[i+1])
				TEMP[i+1] = TEMP[i]+a
			ELSE IF (TEMP[i]+a) > (m[i+1] + k)
				high =a-1
				a = (low+high)/2
				break
			ELSE IF (TEMP[i]+a) >= m[i+1])
				TEMP[i+1] = TEMP[i] + a;
			IF i==l-3
				IF TEMP[l-1]-TEMP[l-2]) >= a
					ans = a
					low = a+1
					FOR j=0 to l-1
						FINAL[j] = TEMP[j]
				ELSE
					high = a-1
				a = (low+high)/2
	PRINT ans
	PRINT FINAL
```


###Data Structures Used
Arrays 

###Algorithms Used
Binary Search

###Programming Paradigm
Dynamic Programming

###Contribution by each team member
- Abhinav Chawla
	* Algorithm
	* Implementing Pseudo Code in C++ 
	* Creating Makefile and Test Cases.
- Apoorv Vikram Singh
	* Algorithm
	* Implementing various modules of the project in C++
	* Creating the Test Cases
- Siddartha Sekhar Padhi
	* Algorithm
	* Implementing Pseudo Code in c++ 
	* Creating README files

###Source(s)
Introduction to Algorithm by Cormen et al. 

#Post Election Transfers
##Design & Analysis of Algorithms Project, Spring 2015
###Authored by
- Abhinav Chawla         IMT2013043  Abhinav.Chawla@iiitb.org
- Apoorv Vikram Singh    IMT2013006  ApoorvVikram.Singh@iiitb.org
- Siddartha Sekhar Padhi IMT2013043  SiddarthaSekhar.Padhi@iiitb.org


###General Usage:
- To Compile:
```
g++ postElectionTransfer-Binary.cc -o postElectionTransfer
```

- To Run:
```
./postElectionTransfer
```
- Input Format
	* The First line contains 3 Integers N L K Where:
		* N is the number of Stations
		* L is the number of Station Masters
		* K is the maximum distance a station master can be moves from his place
	* Then L lines follow containing the position of L Station Masters
	* Constraints:
		* L <= 10^5
		* N,K are integers

- The folder TestCases contains various Test Cases to test the program
- To run the program against the testcase:
```
cat <testCase> | ./postElectionTransfer
```

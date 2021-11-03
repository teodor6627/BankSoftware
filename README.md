# Bank Software
 This is my first course work from the university. The purpose of the program is to create a software for banks where the user can choose options from deposit, withdraw, balance check and others
 The program contains 2 key functions - DATA and LOGIN
 void DATA(int IDs[],int passwords[],float balances[]);
 The purpose of the function DATA is filling the three main arrays which contain the IDs, passwords and balances.
 void LOGIN(int IDs[],int passwords[],float balances[]);
 The purpose of the function LOGIN is to read ID and password, then it reads regime of work.The options are  DRAW, PUT, TRANSFER and INFO.
 If the user choose LOGOUT as regime, the program exits the current bank account and waits to login again. If the user choose EXIT as regime, the program ends.

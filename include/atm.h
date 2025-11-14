#ifndef ATM_H
#define ATM_H

#define PIN 9760
#define INITIAL_BALANCE 10000.0
#define MAX_ATTEMPTS 3


void checkBalance(float balance);
void withdrawCash(float *balance);
void depositMoney(float *balance);
int verifyPIN();

#endif

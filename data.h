#ifndef __DATA_H__
#define __DATA_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


typedef struct Ip Ip;

Ip* createIp(void);

void setMask(Ip* network,const char* mask);
void setIpNetwork(Ip* network,const char* IpAddress);

char* getMask(Ip* network);
char* getIpNetwork(Ip* network);
char* getNetworkId(unsigned networkNumber,const Ip* network);
char* getNetworkHost(unsigned hostNumber,const Ip* network);

void printIpHost(Ip* network,const unsigned hostNumber);

#endif
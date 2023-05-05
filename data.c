#include "data.h"


struct Ip {
    union{
        unsigned char ip[4];
        unsigned ipValue;
    }ip;    

    union{
        unsigned char mask[4];
        unsigned maskValue;
    }mask;
    unsigned decimalMask;
};

Ip* createIp(void){
    Ip* network = NULL;
    network = (Ip*)malloc(sizeof(Ip));
    return network;
}

void setIpNetwork(struct Ip* network,const char* IpAddress){

    if(!IpAddress){
        printf("IpAddress is NULL\n");
        exit(0);
    }
    if(!network){
        printf("Network is NULL\n");
        exit(0);
    }

    if(sscanf(IpAddress,"%hhu.%hhu.%hhu.%hhu",&network->ip.ip[3],&network->ip.ip[2],&network->ip.ip[1],&network->ip.ip[0]) != 4){
        printf("\033[91mIpAddress is Invalid\033[0m\n");
        printf("Ip address format [A.B.C.D]\n");
        exit(0);
    }

    //printf("Network Address completed\n");
}

void setMask(struct Ip* network,const char* Mask){
    if(!Mask){
        printf("Mask is NULL\n");
        exit(0);
    }
    

    if(sscanf(Mask,"/%u",&network->decimalMask) != 1){
        printf("\033[91mMask is Invalid\033[0m\n");
        exit(0);
    }

    network->mask.maskValue = ~(0xffffffff >> network->decimalMask);

    //printf("Network Mask completed\n");
}


char* getMask(Ip* network){
    char* mask = (char*)malloc(sizeof(char)*20);
    sprintf(mask, "%-u.%-u.%-u.%-u", network->mask.mask[3], network->mask.mask[2], network->mask.mask[1], network->mask.mask[0]);
    return mask;
}

char* getIpNetwork(Ip* network){
    char* Ip = (char*)malloc(sizeof(char)*20);
    sprintf(Ip, "%-u.%-u.%-u.%-u", network->ip.ip[3],network->ip.ip[2],network->ip.ip[1],network->ip.ip[0]);
    return Ip;
}

char* getNetworkId(unsigned networkNumber, const Ip* network){
    unsigned numberOfHosts = pow(2, (32 - network->decimalMask));

    Ip networkId = *network;
    networkId.ip.ipValue = network->ip.ipValue + ((networkNumber-1) * numberOfHosts);

    char* Ip = (char*)malloc(sizeof(char)*20);
    sprintf(Ip, "%-u.%-u.%-u.%-u", networkId.ip.ip[3],networkId.ip.ip[2],networkId.ip.ip[1],networkId.ip.ip[0]);
    return Ip;
}

char* getNetworkHost(unsigned hostNumber,const Ip* network){

    Ip networkId = *network;
    networkId.ip.ipValue = network->ip.ipValue + hostNumber;

    char* Ip = (char*)malloc(sizeof(char)*20);
    sprintf(Ip, "%-u.%-u.%-u.%-u", networkId.ip.ip[3],networkId.ip.ip[2],networkId.ip.ip[1],networkId.ip.ip[0]);
    return Ip;
}



void printIpHost(Ip* network,const unsigned hostNumber){
    if(!network){
        printf("\033[91mNetwork is NULL\033[0m\n");
        exit(0);
    }

    if(hostNumber == 0){
        printf("\033[91mHost number is 0\033[0m\n");
        exit(0);
    }

    Ip host = *network;
    Ip LastNetwork = *network;

    for(int i = 0; i <= hostNumber; i++){
        if((host.ip.ipValue & host.mask.maskValue) != (LastNetwork.ip.ipValue & LastNetwork.mask.maskValue)){
            LastNetwork.ip.ipValue = host.ip.ipValue;
            printf("--------------------------\n");
        }        
        printf("\033[96m%-3d\033[0m : %-hhu.%-hhu.%-hhu.%-hhu\n", i, host.ip.ip[3], host.ip.ip[2], host.ip.ip[1], host.ip.ip[0]);
        host.ip.ipValue++;
    }
}
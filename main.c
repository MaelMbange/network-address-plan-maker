#include <stdlib.h>
#include <stdio.h>
#include "data.h"


int main(int argc, char* argv[]){

    Ip* network = NULL;
    network = createIp();

    setIpNetwork(network, argv[1]);    
    setMask(network, argv[2]);

    char* IpNetwork = getIpNetwork(network);
    char* Mask = getMask(network);

    printf("%-10s: %s\n","Network ID",IpNetwork);
    printf("%10s: %s\n","Mask ID",Mask);
    printf("--------------------------\n");
    printIpHost(network, atoi(argv[3]));
    printf("\n");


    free(IpNetwork);
    free(Mask);
    free(network);
    return 0;
}
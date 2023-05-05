#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include "data.h"
/*
Ip* network = NULL;
network = createIp();

setIpNetwork(network, argv[1]);    
setMask(network, argv[2]);

char* IpNetwork = getIpNetwork(network);
char* Mask = getMask(network);
char* NetworkId = getNetworkId(10, network);
char* NetworkHost = getNetworkHost(255, network);

printf("%-10s: %s\n","Network ID",IpNetwork);
printf("%10s: %s\n","Mask ID",Mask);
printf("%10s: %s\n","10th network-id",NetworkId);
printf("%10s: %s\n","255th network-hosts",NetworkHost);
printf("--------------------------\n");
printIpHost(network, atoi(argv[3]));
printf("\n");

free(IpNetwork);
free(Mask);
free(NetworkId);
free(network);
*/

int main(int argc, char* argv[]){
    const char option[] = "i:m:N:h:H:";
    int opt = 0;
    Ip* network = createIp();
    char* string = NULL;
    char* token = NULL;

    while((opt = getopt(argc,argv,option)) != -1){
        switch(opt){

        case 'i':
                setIpNetwork(network,(const char*)optarg);

                string = getIpNetwork(network);
                printf("----------------------------\n");
                printf("%-10s: %s\n\n","Network ID",string);
                free(string);
            break;
        
        case 'm':
                setMask(network,(const char*)optarg);

                string = getMask(network);
                printf("----------------------------\n");
                printf("%-10s: %s\n\n","Mask ID",string);
                free(string);
            break;

        case 'N':
                    token = strtok(optarg,",");
                    printf("----------------------------\n");

                    while(token != NULL){
                        string = getNetworkId((unsigned)atoi(token),network);
                        printf("Network %-2d : %s\n",(unsigned)atoi(token),string);
                        free(string);
                        token = strtok(NULL,",");
                    }
                    printf("\n");
            break;

        case 'h':
                    token = strtok(optarg,",");
                    printf("----------------------------\n");

                    while(token != NULL){
                        string = getNetworkHost((unsigned)atoi(token),network);
                        printf("Host %-2d : %s\n",(unsigned)atoi(token),string);
                        free(string);
                        token = strtok(NULL,",");
                    }
                    printf("\n");
            break;

        case 'H':
                    printf("----------------------------\n");
                    printIpHost(network,(unsigned)atoi(optarg));
                    printf("\n");
            break;

        case '?':
                printf("Invalid option\n");
                abort();
            break;
        }
    }
    

    
    return 0;
}
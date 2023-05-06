#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include "data.h"

struct option longOptions[] = {
    {"network-Id", required_argument, 0, 'n'},
    {"mask", required_argument, 0, 'm'},
    {"specific-host", required_argument, 0, 'H'},
    {"show-host", required_argument, 0, 'p'},
    {"subnet", required_argument, 0, 's'},
    {"help", no_argument, 0, 'h'},
    {0,0,0,0}
};

int option_index = 0; 

int main(int argc, char* argv[]){
    int opt = 0;
    Ip* network = createIp();
    char* string = NULL;
    char* token = NULL;
    int isSet = 1;

    while((opt = getopt_long(argc,argv,"n:m:s:H:p:s",longOptions,&option_index)) != -1 && isSet){
        switch(opt){
            case 'n':
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

            case 's':
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

            case 'H':
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

            case 'p':
                    printf("----------------------------\n");
                    printIpHost(network,(unsigned)atoi(optarg));
                    printf("\n");
                break;

            case 'h':
            case '?':
                    printf("----------------------------\n");
                    printf("Usage: %s [options]\n",argv[0]);
                    printf("Options:\n");
                    printf("  -n, --network-Id <A.B.C.D>     Set the network-id\n");
                    printf("  -m, --mask </mask>             Set the mask-id\n");
                    printf("  -s, --subnet <subnet-number>   Print the network-subnet number x\n");
                    printf("  -H, --specific-host <1,...>    Print the specific-host(s)\n");
                    printf("  -p, --show-host <number>       Show the x host(s)\n");
                    printf("  -h, --help                     Print this help\n");
                    printf("\n");
                    isSet = 0;
                break;

            default:
                    isSet = 0;
        }
    }
        
    return 0;
}
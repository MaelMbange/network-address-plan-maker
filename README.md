# network-address-plan-maker

Executable argument : 
```
-n, --network-Id <A.B.C.D>     Set the network-id
-m, --mask </mask>             Set the mask-id
-s, --subnet <subnet-number>   Print the network-subnet number x
-H, --specific-host <1,...>   Print the specific-host(s)
-p, --show-host <number>       Show the x host(s)
-h, --help                     Print this help
```

### Commandes

*  ``--network-Id <A.B.C.D>`` 

```
terminal : .\main.exe --network-Id 192.168.1.0
-------------------------------------
Network ID: 192.168.1.0
```

*  ``--mask </mask>``

```  
terminal : .\main.exe --mask /24
-------------------------------------
Mask ID   : 255.255.255.0
```

* ``--subnet <subnet-number>``

```
terminal : .\main.exe --subnet 11,12
-------------------------------------
Network 11 : 192.168.11.0
Network 12 : 192.168.12.0
```

* ``--specific-host <1,...>``

```
terminal : .\main.exe --specific-host 1,2,3
-------------------------------------
Host 1  : 192.168.1.1
Host 3  : 192.168.1.3
Host 5  : 192.168.1.5
```

* ``--show-host <number>``

```
terminal : .\main.exe --show-host 10
-------------------------------------
0   : 192.168.1.0
1   : 192.168.1.1
2   : 192.168.1.2
3   : 192.168.1.3
4   : 192.168.1.4
5   : 192.168.1.5
6   : 192.168.1.6
7   : 192.168.1.7
8   : 192.168.1.8
9   : 192.168.1.9
10  : 192.168.1.10
```


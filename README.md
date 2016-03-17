Just CPP Things
===============
Random collection of things written in CPP. Everything in here is a toy app/lib, written for fun or to better my knowledge of something. Don't expect it to work all the time, as it should, or be useful even. Do feel free to ping me if you see something really stupid that I shouldn't be doing, it will only further my goal of learning more.

linked_list
-----------
A few different implementations of a linked list, all very simple and not the way you'd want to have one. I mean, it only stores ```int```s for example.

Compile / run with:
```
g++ -std=c++11 -W -Wall -Wextra -pedantic linked_list/*.cpp -o run_list && ./run_list
```

simple_chat
-----------
Creating a simple chat server in c++ without using a framework/lib to better my understanding of the low level shit going on. First goal is an echo server, then something higher level.

Compile / run with:
```
g++ -std=c++11 -W -Wall -Wextra -pedantic simple_chat/*.cpp -o run_server && ./run_server
```

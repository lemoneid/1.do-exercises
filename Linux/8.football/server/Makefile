.PHONY clean
CC=gcc
CFLAGS=-g -Wall
MAINOBJ =server.o sum.o
all :$(MAINOBJS)
		$(CC) $(CFLAGS) $(MAINOBJS) -o ./server
server.o:server.c
	$(CC) $(CFLAGS) -I./ -c -o server.o ./server.c ../common/common.c ../common/ball_status.c ../common/show_data_stream.c ../common/server_re_draw.c ../common/server_exit.c ../common/game_ui.c ../common/heart_beat.c ../common/udp_epoll.c ../common/cJSON.c  -lpthread -lncurses

clean :
	rm -rf *.o a,out

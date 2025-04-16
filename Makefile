CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lcurl
TARGET = mekill

SRC = main.c api_client.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
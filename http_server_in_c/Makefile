CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -std=c11
SRCDIR = src
INCDIR = include
BUILDDIR = build
TARGET = $(BUILDDIR)/http_server

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)

$(TARGET): $(OBJ)
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILDDIR)

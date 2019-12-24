CFLAGS  = `pkg-config --cflags gobject-introspection-1.0 gobject-2.0` -g
LDFLAGS = `pkg-config --libs  gobject-introspection-1.0 gobject-2.0`

test: main
	./main

main:

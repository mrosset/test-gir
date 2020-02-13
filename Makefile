PKGS    = "gobject-introspection-1.0 gobject-2.0 gtk+-3.0 webkit2gtk-4.0"
CFLAGS  = `pkg-config --cflags $(PKGS)` -Werror
LDFLAGS = `pkg-config --libs $(PKGS)`
CC      = gcc

default:
	./open.scm

test: open main
	./open & disown
	./open https://www.gnu.org/software/guile/

open: open.o

main: main.o

.PHONY:

clean:
	-rm *.o
	-rm main open

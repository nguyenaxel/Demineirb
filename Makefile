CFLAGS+= -std=c99 -Wall -Werror -Wno-unused-variable
LDLIBS+=-lncurses

# Nom de votre executable
TARGET=demineirb
# Liste des fichiers nécessaires à sa réalisation
OBJS=demineirb.o print.o ncurses.o

# Create dependencies while compiling
CFLAGS+=-MMD

$(TARGET): $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS) *.d

# Injecte les dependences si presentes
-include *.d

print : print.o ncurses.o
demineirb : demineirb.o ncurses.o print.o

.PHONY: clean clean-deps

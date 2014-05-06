
DIR	=#/opt/gcc-4.3-ls232/bin/
CROSS_COMPILE = mips-linux-gnu-
DEBUG = -Wall -Werror -g #-O3 
FLAGS = -EL -mips32 -msingle-float 

CC	= $(DIR)$(CROSS_COMPILE)gcc
LD	= $(DIR)$(CROSS_COMPILE)ld
OBJCOPY	= $(DIR)$(CROSS_COMPILE)objcopy
OBJDUMP	= $(DIR)$(CROSS_COMPILE)objdump
AR	= $(DIR)$(CROSS_COMPILE)ar
	
export AR CC DEBUG FLAGS

libuser.a: user/*
	make -C user $@
	cp user/libuser.a ./
	
start.o:bootloader/start.S include/*
	$(CC) $(DEBUG) $(FLAGS) -I include/asm/ -c -o $@ $<
	
main.o:main.c include/* lib/*
	$(CC) $(DEBUG) $(FLAGS) -c -o $@ $< -I . -I include/
	
demo:start.o main.o lib/lib1dfunc.a lib/libtinyc.a lib/lib1dtest.a user.lds libuser.a
	$(LD) -T user.lds -Ttext 0xBFC00000 -Map demo.map start.o main.o -o $@ -L . -luser -L lib/ -l1dtest -L lib/ -l1dfunc -L lib/ -ltinyc
	rm -f *.o
	rm libuser.a
	
demo.bin:demo 
	$(OBJCOPY) --gap-fill=0xff -O binary $< $@
	$(OBJDUMP) -Slz demo >demo.txt

all: demo.bin
	make -C user clean

clean:
	make -C user clean
	rm -f *.o *.a *.s 
	rm -f demo demo.map demo.txt demo.bin
	
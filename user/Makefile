
%.o:%.c
	$(CC) $(DEBUG) $(FLAGS) -c -o $@ $< -I ../ -I ../include/

src = $(wildcard *.c)
objs = $(patsubst %.c,%.o,$(src))

libuser.a: $(objs) $(src)
	$(AR) -cr  $@ $?

clean:
	rm -f *.o *.a *.s 


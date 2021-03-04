OBJS = tokenizer.o uimain.o history.o

CFLAGS =-g -O3



all: tokenizer



tokenizer: $(OBJS)

	cc -o tokenizer $(CFLAGS) $(OBJS)



$(OBJS): uimain.c history.h tokenizer.h



clean:

	rm -f *.o tokenizer



run:tokenizer

	./tokenizer

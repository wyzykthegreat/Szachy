DEPS = main.c ruchy_bierek.c

szachy: $(DEPS)
	cc $(DEPS) -o $@ 

clean:
	rm -f szachy	

test:
	./szachy	
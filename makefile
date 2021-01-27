DEPS = main.c ruchy_bierek.c bialypionek.c czarnypionek.c hetmangoniecwieza.c krolkon.c negaMax.c planszowe.c

szachy: $(DEPS)
	cc $(DEPS) -o $@ 

clean:
	rm -f szachy	

test:
	./szachy	
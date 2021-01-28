DEPS = main.c ruchy_bierek.c bialypionek.c czarnypionek.c hetmangoniecwieza.c kon.c negaMax.c planszowe.c krol.c

szachy: $(DEPS)
	cc $(DEPS) -o $@ 

clean:
	rm -f szachy	

graj:
	./szachy	
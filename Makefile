cc=gcc
output:add.o data_component.o delete.o modify.o view.o main.o 
	$(cc) $^ -o $@
.o:.c
	$(cc) -g $<
clean:
	rm *.o
	rm -f output

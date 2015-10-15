all: pipe_overhead pipe_kthread_switch_overhead pipe_process_switch_overhead

pipe_overhead: pipe_overhead.o
	gcc -o pipe_overhead pipe_overhead.o

pipe_overhead.o: pipe_overhead.c
	gcc -c -Wall pipe_overhead.c

pipe_kthread_switch_overhead: pipe_kthread_switch_overhead.o
	gcc -o pipe_kthread_switch_overhead pipe_kthread_switch_overhead.o

pipe_kthread_switch_overhead.o: pipe_kthread_switch_overhead.c
	gcc -c -Wall pipe_kthread_switch_overhead.c

pipe_process_switch_overhead: pipe_process_switch_overhead.o
	gcc -o pipe_process_switch_overhead pipe_process_switch_overhead.o

pipe_process_switch_overhead.o: pipe_process_switch_overhead.c
	gcc -c -Wall pipe_process_switch_overhead.c

clean:
	rm pipe_overhead pipe_kthread_switch_overhead pipe_process_switch_overhead *.o *.txt

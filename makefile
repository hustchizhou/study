obj=TimeSliceRunStructure.o Task_PT.o
output: $(obj)
	gcc $(obj) -o output
TimeSliceRunStructure.o: Task_PT.h
Task_PT.o: Task_PT.h 
.PHONY:clean
clean:
	-rm $(obj) output
       	

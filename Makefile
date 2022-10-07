output:
	gcc -Wall -o output main.c library.c CASE1_ADD.c CASE2_Lookup.c CASE3_Update.c CASE4_DEL.c CASE5_Display.c CASE6_Alias.c CASE7_Save.c CASE8_Exit.c

clean:
	rm output
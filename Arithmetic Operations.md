```
    EXPORT __main
    AREA PROG_1, CODE, READONLY

__main
    	LDR R1, =OUR_FIXED_DATA         ; Load the length of the arrays (8 in this case)
    	LDR R2, =RESULT   ; Load the address of ARRAY1
    	LDR R3,[R1] ; Load the address of ARRAY2
    	LDR R4,[R1,#4]     ; Load the address of the writable ARRAY1
		LDR R5,[R1,#8]
		CMP R3,#1
		BNE CHK_SUB
		ADDS R7,R5,R4
		B LAST
CHK_SUB
		CMP R3,#2
		BNE CHK_MUL
		SUBS R7,R5,R4
		B LAST
CHK_MUL
		CMP R3,#3
		BNE CHK_DIV
		UMULL R7,R8,R5,R4
		B  LAST
CHK_DIV
		CMP R3,#4
		BNE LAST
		UDIV R7,R5,R4
LAST STR R7,[R2]
HERE B HERE

    AREA tempData, DATA, READONLY, ALIGN=4
OUR_FIXED_DATA DCD 0x00000004,0x00000020,0x00000030,0x00000000

    AREA result, DATA, READWRITE, ALIGN=4
RESULT SPACE 4

    END
```

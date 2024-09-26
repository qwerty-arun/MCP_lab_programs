```
	PRESERVE8
Stack EQU 0x00000100

	AREA STACK, NOINIT, READWRITE
StackMem SPACE Stack

	AREA RESET,DATA,READONLY
	EXPORT_Vectors

__Vectors
	DCD StackMem+Stack
	DCD Reset_Handler


	AREA tempData,DATA,READONLY
Array DCD 1,2,3,55,5,6,7,8,9,10


	AREA |.text|, CODE, READONLY
	ENTRY	

EXPORT Reset_Handler
Reset_Handler
Reset_Handler_End

	LDR R0, =ArrayMOV R1; Load address of Array_Start into R0.
	MOV R2,#55 ; Move #55 into R2.
	BL Linear_Search_Start
stop B stop ; Branch to Stop label.

Linear_Search_Start

	EXPORT Linear_Search_Start
	MOV R4, R0 ; Initializing index of array to #0
	MOV R3, #0 ; Loading iteration
	MOV R0, #0 ; Clearing R0 to make it available to 
            ; return result

loop
	ADD R3,R3,#1
	LDR R5,[R4]
	CMP R5,R2
	ADDEQ R0,R0,R3
	MOVEQ PC,LR
	ADD R4,R4,#4
	CMP R3,R1 
	BNE loop
	MOV PC,LR
	END 
```

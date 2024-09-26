```
EXPORT __main
    AREA PROG_2, CODE, READONLY

__main
    MOV R0, #LEN         ; Load the length of the arrays (8 in this case)
    LDR R1, =ROMARRAY1   ; Load the address of ARRAY1
    LDR R2, =ROMARRAY2   ; Load the address of ARRAY2
    LDR R3, =ARRAY1      ; Load the address of the writable ARRAY1
    LDR R4, =ARRAY2      ; Load the address of the writable ARRAY2

label1
    LDR R5, [R1], #4     ; Load a word from ROMARRAY1 and increment R1
    LDR R6, [R2], #4     ; Load a word from ROMARRAY2 and increment R2
    STR R5, [R4], #4     ; Store the value from ROMARRAY1 into ARRAY2
    STR R6, [R3], #4     ; Store the value from ROMARRAY2 into ARRAY1
    SUBS R0, R0, #1      ; Decrement the counter
    BNE label1           ; If not zero, repeat

STOP B STOP              ; Infinite loop to stop execution

    AREA tempData, DATA, READONLY, ALIGN=4

ROMARRAY1 DCD 0x00000001, 0x00000002, 0x00000003, 0x00000004, 0x00000005, 0x00000006, 0x00000007, 0x00000008
ROMARRAY2 DCD 0x00000009, 0x00000010, 0x00000011, 0x00000012, 0x00000013, 0x00000014, 0x00000015, 0x00000016

    AREA data, DATA, READWRITE, ALIGN=4

LEN EQU 0x08             ; Define the length as 8
ARRAY1 SPACE 32          ; Reserve space for ARRAY1 (8 words)
ARRAY2 SPACE 32          ; Reserve space for ARRAY2 (8 words)

    END
```

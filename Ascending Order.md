```
    EXPORT __main
    AREA ASCENDING, CODE, READONLY
__main
    MOV R8, #4                  ; Number of elements
    LDR R2, =CVALUE             ; Load base address of source array (CVALUE)
    LDR R3, =DVALUE             ; Load base address of destination array (DVALUE)
    
LOOP0
    LDR R1, [R2], #4            ; Load each element from CVALUE into R1, increment R2
    STR R1, [R3], #4            ; Store R1 into DVALUE, increment R3
    SUBS R8, R8, #1             ; Decrement counter R8
    CMP R8, #0                  ; Check if all elements have been copied
    BNE LOOP0                   ; If not, repeat

START1
    MOV R5, #3                  ; Outer loop counter, number of passes (n-1 elements to compare)
    MOV R7, #0                  ; Flag to check if any swap happened
    LDR R1, =DVALUE             ; Load the address of the array to sort (DVALUE)
    
LOOP
    LDR R2, [R1]                ; Load the current element into R2
    LDR R3, [R1, #4]            ; Load the next element into R3 (adjacent element)
    CMP R2, R3                  ; Compare the current element with the next
    BLT LOOP2                   ; If R2 < R3, no swap needed, jump to LOOP2
    STR R3, [R1]                ; Swap: store the smaller value (R3) in the current position
    STR R2, [R1, #4]            ; Store the larger value (R2) in the next position
    MOV R7, #1                  ; Set the swap flag to indicate a swap was made
    
LOOP2
    ADD R1, R1, #4              ; Move to the next pair of elements
    SUBS R5, R5, #1             ; Decrement the outer loop counter
    CMP R5, #0                  ; Check if we have compared all elements
    BNE LOOP                    ; If not, repeat comparison
    
    CMP R7, #0                  ; Check if any swaps were made
    BNE START1                  ; If swaps were made, repeat the entire sorting process
    
STOP	B STOP                      ; End the program

CVALUE DCD 0x44444444, 0x11111111, 0x33333333, 0x22222222  ; Original array

    AREA DATA1, DATA, READWRITE
DVALUE DCD 0x00000000, 0x00000000, 0x00000000, 0x00000000  ; Destination array (empty)
    END
```

## Mahdi khaliki
## Final Project
## 5/7/18

        .data 
source:
        .asciiz "Thhis is my sTrInG that is more than 40 chars long!123?\n"
display:
        .space 100
var:    .word 0
pointer:
        .word 0

        .text
        .globl main
main:
        la      $t0, source
        sw      $t0, pointer            # Pointer used for transmitter

        la      $t1, display
        addiu   $sp, $sp, -4            # Push address of sourse and display
        sw      $t0, ($sp)
        addiu   $sp, $sp, -4
        sw      $t1, ($sp)
        jal     copy                    # Call copy subroutine
        addiu   $sp, $sp, 8             # Deallocated parameter space

        mfc0    $t0, $12                # Raise interrupt enable bit in $12
        ori     $t0, $t0, 0xC01
        mtc0    $t0, $12

        li      $t1, 0x2                # Raise interrupt enable bit
        sw      $t1, 0xffff0000         # Store $t1 in receiver control register
        li      $t1, 0x2                # Raise interrupt enable bit
        sw      $t1, 0xffff0008         # Store $t1 in transmitter control register

interrupt:
        lw      $t0, var
        beqz    $t0, interrupt          # Check if variable has changed

        li      $v0, 10                 # End program
        syscall

copy:
        addiu   $sp, $sp, -4
        sw      $ra, ($sp)
        addiu   $sp, $sp, -4
        sw      $fp, ($sp)
        or      $fp, $zero, $sp
        lw      $t0, 8($fp)             # $t0 = address of display
        lw      $t1, 12($fp)            # $t1 = address of source
loop:
        lb      $t2, ($t1)              # $t2 = char from source
        sb      $t2, ($t0)              # Store $t2 to display
        addi    $t0, $t0, 1             # Increment address of source and display
        addi    $t1, $t1, 1
        beqz    $t2, end                # If char copied was NUL end loop
        b       loop
end:
        lw      $fp, ($sp)              # Pop $fp and $ra
        addiu   $sp, $sp, 4
        lw      $ra, ($sp)
        addiu   $sp, $sp, 4
        jr      $ra

        .kdata
saveat: .word 0
savet0: .word 0
savet1: .word 0

        .ktext 0x80000180
        .set    noat                    # Save $at
        move    $k0, $at
        .set    at
        sw      $k0, saveat
        sw      $t0, savet0             # Save $t0
        sw      $t1, savet1             # Save $t1

        mfc0    $t0, $13
        srl     $k0, $t0, 2
        sll     $k0, $k0, 27
        beqz    $k0, query              # If code == 0
        b       return

query:
        andi    $k0, $t0, 0x800         # Check if receiver interrupt
        beq     $k0, 0x800, receiver

        andi    $k0, $t0, 0x400         # Check if transmitter interrupt
        beq     $k0, 0x400, transmitter
        b       return

receiver:
        lw      $t0, 0xffff0004         # Load char entered by user
        beq     $t0, 0x73, sort
        beq     $t0, 0x74, toggle
        beq     $t0, 0x61, replace
        beq     $t0, 0x72, reverse
        beq     $t0, 0x71, quit
        b       return

sort:
        la      $t0, display            # Load address of display
        li      $t1, 0                  # Used as a flag
for:
        lb      $k0, ($t0)              # Load current char
        lb      $k1, 1($t0)             # Load next char in string
        beq     $k1, 0xA, endSort       # If next char is a newline endSort
        blt     $k1, $k0, swap          # If next char < current char, swap
        addi    $t0, $t0, 1             # Increment address
        b       for
swap:
        sb      $k1, ($t0)
        sb      $k0, 1($t0)
        li      $t1, 1
        addi    $t0, $t0, 1
        b       for
endSort:
        beq     $t1, 1, sort            # Check if a sort took place in loop
        b       return                  # If no sort then return

toggle:
        la      $t0, display            # Load address of display
ToggleLoop:
        lb      $t1, ($t0)              # Load char
        beq     $t1, 0xA, return        # If char == newline, return

        sge     $k0, $t1, 0x41          # Check if char is a capital alphabet
        sle     $k1, $t1, 0x5A
        and     $k0, $k0, $k1
        beq     $k0, 1, LowerCase       # If char is a capital letter make it lower case

        sge     $k0, $t1, 0x61          # Check if char is a lower case alphabet
        sle     $k1, $t1, 0x7A
        and     $k0, $k0, $k1
        beq     $k0, 1, UpperCase       # If char is a lower case letter make it capital
        addi    $t0, $t0, 1             # else increment and loop
        b       ToggleLoop
LowerCase:
        addi    $t1, $t1, 32
        sb      $t1, ($t0)
        addi    $t0, $t0, 1
        b       ToggleLoop
UpperCase:
        addi    $t1, $t1, -32
        sb      $t1, ($t0)
        addi    $t0, $t0, 1
        b       ToggleLoop

replace:
        la      $t0, display            # Load address of display
        la      $t1, source             # Load address of source
replaceLoop:
        lb      $k0, ($t1)              # Load char from source
        sb      $k0, ($t0)              # Store char into display
        addi    $t0, $t0, 1             # Increment addresses
        addi    $t1, $t1, 1
        beqz    $k0, return             # If char copied was a NUL, return
        b       replaceLoop

reverse:
        la      $t0, display            # Load address of display
traverse:
        addi    $t0, $t0, 1             # Traverse pointer until '\n' is found
        lb      $t1, ($t0)
        bne     $t1, 0xA, traverse

        addi    $t0, $t0, -1            # Move pointer one place back
        la      $t1, display            # Load base address of display
reverseLoop:
        lb      $k0, ($t1)              # Load char from low pointer
        lb      $k1, ($t0)              # Load char from high pointer
        sb      $k0, ($t0)              # Swap the 2 chars
        sb      $k1, ($t1)
        addi    $t1, $t1, 1             # Increment low
        addi    $t0, $t0, -1            # Decrement high
        bge     $t1, $t0, return        # If low is >= high, return
        b       reverseLoop

quit:
        li      $k0, 1                  # Store 1 into var
        sw      $k0, var
        b       return

transmitter:
        li      $t0, 0xffff0000         # Load transmitter control register address
        lw      $k0, pointer            # Load pointer
        lb      $k1, ($k0)              # Load char from display using pointer
        sw      $k1, 12($t0)            # Store char into transmitter data
        addi    $k0, $k0, 1             # Increment pointer
        sw      $k0, pointer            # Store pointer
        beqz    $k1, reset              # If char printed was NUL, reset
        b       return
reset:
        la      $k0, display            # Load address of display
        sw      $k0, pointer            # Store display address into pointer
        b       return

return:
        lw      $t1, savet1             # Restore $t and $a registers
        lw      $t0, savet0
        lw      $k0, saveat
        .set    noat
        move    $at, $k0
        .set    at
        eret

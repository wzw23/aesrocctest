#include "riscv_test.h"

RVTEST_RV64UV        # Define TVM used by program.

# Test code region.
RVTEST_CODE_BEGIN   # Start of test code.
        li a0, 32       
	csrw vstart,0
	li a1,5
        li t1, 2       # 设置 t0 为零（用作临时寄存器）
        vsetvl t0, a0, t1  # 使用 vsetvl 指令将 vlmul 设置为 1
	li a1,8
        la a0,num1
        vmv.v.i v4,0
        vle8.v v0,(a0)
        vredsum.vs v8,v0,v4
        vredmaxu.vs v8,v0,v4
        vredmax.vs v8,v0,v4
        vredminu.vs v8,v0,v4
        vredmin.vs v8,v0,v4
        vredand.vs v8,v0,v4
        vredor.vs v8,v0,v4
        vredxor.vs v8,v0,v4
        li a1,2
        vwredsumu.vs v8,v0,v4
        vwredsum.vs v8,v0,v4
                


        la a0,num2
        vle8.v v0,(a0)
        vredsum.vs v8,v0,v4
        vredmaxu.vs v8,v0,v4
        vredmax.vs v8,v0,v4
        vredminu.vs v8,v0,v4
        vredmin.vs v8,v0,v4
        vredand.vs v8,v0,v4
        vredor.vs v8,v0,v4
        vredxor.vs v8,v0,v4
        li a1,2
        vwredsumu.vs v8,v0,v4
        vwredsum.vs v8,v0,v4
        
        la a0,num3
        vle8.v v0,(a0)
        vredsum.vs v8,v0,v4
        vredmaxu.vs v8,v0,v4
        vredmax.vs v8,v0,v4
        vredminu.vs v8,v0,v4
        vredmin.vs v8,v0,v4
        vredand.vs v8,v0,v4
        vredor.vs v8,v0,v4
        vredxor.vs v8,v0,v4
        li a1,2
        vwredsumu.vs v8,v0,v4
        vwredsum.vs v8,v0,v4
        
        



        
        RVTEST_PASS           # Signal success.
        //RVTEST_FAIL           # Signal success.
fail:
        RVTEST_FAIL
RVTEST_CODE_END     # End of test code.

# Input data section.
# This section is optional, and this data is NOT saved in the output.
.data
        num1:   .byte 1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8    # 第一个数字，以字（4字节）形式存储
        num2:   .byte 2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1   # 第二个数字，以字（4字节）形式存储
        num3:   .byte 3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2    # 第二个数字，以字（4字节）形式存储
testdata:
        .dword 41

# Output data section.
RVTEST_DATA_BEGIN   # Start of test output data region.
        .align 3
result:
        .dword -1
RVTEST_DATA_END     # End of test output data region.

#!/bin/bash

# 定义要执行的指令列表
commands=(
    "riscv64-unknown-elf-gcc -g -fno-common -fno-builtin-printf -specs=htif_nano.specs -c conv1d.c "
    "riscv64-unknown-elf-gcc -g -fno-common -fno-builtin-printf -specs=htif_nano.specs -c conv1d_conv.S "
    "riscv64-unknown-elf-gcc -g -static -specs=htif_nano.specs conv1d_conv.o conv1d_init.o conv1d.o -o conv1d.riscv"
)

# 遍历指令列表并执行每个指令
for cmd in "${commands[@]}"; do
    echo "Executing command: $cmd"
    # 执行指令
    eval "$cmd"
    echo "Command execution complete"
    echo "------------------------------------------"
done

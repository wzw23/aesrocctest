../../../install/bin/riscv64-unknown-elf-gcc -march=rv64gcv -O3 -static -S conv1d_conv.c -o conv1d_conv.S
riscv64-unknown-elf-gcc -march=rv64gcv -g -fno-common -fno-builtin-printf -specs=htif_nano.specs -c vre_14.S -T./link.ld
riscv64-unknown-elf-gcc -g -fno-common -fno-builtin-printf -specs=htif_nano.specs -c conv1d.c    
riscv64-unknown-elf-gcc -g -static -specs=htif_nano.specs vre_14.o conv1d.o -o vre_14.riscv 
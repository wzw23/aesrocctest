	.file	"conv1dh.c"
	.option nopic
	.attribute arch, "rv64i2p1_m2p0_a2p1_f2p2_d2p2_c2p0_v1p0_zicsr2p0_zifencei2p0_zve32f1p0_zve32x1p0_zve64d1p0_zve64f1p0_zve64x1p0_zvl128b1p0_zvl32b1p0_zvl64b1p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	1
	.globl	convolution
	.type	convolution, @function
convolution:
	addi	sp,sp,-48
	sd	s0,32(sp)
	sd	s1,24(sp)
	sd	s2,16(sp)
	sd	s3,8(sp)
	mv	s2,a4
	addw	a5,a3,a4
	sd	ra,40(sp)
	li	a4,1
	mv	s0,a3
	mv	s3,a0
	mv	s1,a1
	mv	a6,a2
	ble	a5,a4,.L2
	addiw	a5,a5,-1
	slli	a4,a5,32
	mv	a0,a6
	srli	a2,a4,30
	li	a1,0
	call	memset
	mv	a6,a0
.L2:
	ble	s0,zero,.L16
	ble	s2,zero,.L16
	slli	a3,s2,2
	csrr	a4,vlenb
	mv	a0,s3
	mv	a2,a6
	add	t6,a3,s1
	addi	a4,a4,-8
	li	t5,0
	addi	a1,s1,4
.L4:
	mv	t0,a0
	add	a5,a2,a3
	addi	a0,a0,4
	sltu	a5,t0,a5
	sltu	a6,a2,a0
	seqz	a5,a5
	seqz	a6,a6
	or	a5,a5,a6
	andi	a5,a5,0xff
	mv	t3,a2
	beq	a5,zero,.L10
	sub	a5,a2,a1
	bleu	a5,a4,.L10
	mv	a7,s2
	mv	a6,a2
	mv	t4,s1
	vsetvli	a5,zero,e32,m1,ta,ma
	vlse32.v	v3,0(t0),zero
.L5:
	vsetvli	a5,a7,e32,m1,ta,ma
	slli	t1,a5,2
	vle32.v	v1,0(t3)
	vle32.v	v2,0(t4)
	sub	a7,a7,a5
	vmacc.vv	v1,v3,v2
	vse32.v	v1,0(a6)
	add	t3,t3,t1
	add	t4,t4,t1
	add	a6,a6,t1
	bne	a7,zero,.L5
	addiw	t5,t5,1
	addi	a2,a2,4
	bne	s0,t5,.L4
.L16:
	ld	ra,40(sp)
	ld	s0,32(sp)
	ld	s1,24(sp)
	ld	s2,16(sp)
	ld	s3,8(sp)
	addi	sp,sp,48
	jr	ra
.L10:
	mv	a6,s1
	mv	a5,a2
.L7:
	lw	a7,0(t0)
	lw	t1,0(a6)
	mulw	t1,t1,a7
	lw	a7,0(a5)
	addi	a6,a6,4
	addi	a5,a5,4
	addw	a7,a7,t1
	sw	a7,-4(a5)
	bne	a6,t6,.L7
	addiw	t5,t5,1
	addi	a2,a2,4
	bne	s0,t5,.L4
	j	.L16
	.size	convolution, .-convolution
	.ident	"GCC: (ga138b99646a) 14.0.0 20240103 (experimental)"
	.section	.note.GNU-stack,"",@progbits

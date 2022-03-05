// ------------------------------------------------------------
// ARMv8-A AArch64 - GICv3 CPU interface functions
//
// Copyright (C) Arm Limited, 2019 All rights reserved.
//
// The example code is provided to you as an aid to learning when working
// with Arm-based technology, including but not limited to programming tutorials.
// Arm hereby grants to you, subject to the terms and conditions of this Licence,
// a non-exclusive, non-transferable, non-sub-licensable, free-of-charge licence,
// to use and copy the Software solely for the purpose of demonstration and
// evaluation.
//
// You accept that the Software has not been tested by Arm therefore the Software
// is provided �as is�, without warranty of any kind, express or implied. In no
// event shall the authors or copyright holders be liable for any claim, damages
// or other liability, whether in action or contract, tort or otherwise, arising
// from, out of or in connection with the Software or the use of Software.
//
// ------------------------------------------------------------

.section  .v8_aarch64_gicv3_cpuif,"ax"



// ------------------------------------------------------------

	.global sets3_0_c12_c12_5
  // void sets3_0_c12_c12_5(unsigned int value)
	.type sets3_0_c12_c12_5, @function
sets3_0_c12_c12_5:
  MSR   s3_0_c12_c12_5, x0
  ISB
  RET

   

// ------------------------------------------------------------

	.global gets3_0_c12_c12_5
  // unsigned int gets3_0_c12_c12_5(void)
	.type gets3_0_c12_c12_5, @function
gets3_0_c12_c12_5:
  MRS   x0, s3_0_c12_c12_5
  RET

   

// ------------------------------------------------------------

	.global sets3_4_c12_c9_5
  // void sets3_4_c12_c9_5(unsigned int value)
	.type sets3_4_c12_c9_5, @function
sets3_4_c12_c9_5:
  MSR   s3_4_c12_c9_5, x0
  ISB
  RET

   

// ------------------------------------------------------------

	.global gets3_4_c12_c9_5
  // unsigned int gets3_4_c12_c9_5(void)
	.type gets3_4_c12_c9_5, @function
gets3_4_c12_c9_5:
  MRS   x0, s3_4_c12_c9_5
  RET

   
  
// ------------------------------------------------------------

	.global sets3_6_c12_c12_5
  // void sets3_6_c12_c12_5(unsigned int value)
	.type sets3_6_c12_c12_5, @function
sets3_6_c12_c12_5:
  MSR   s3_6_c12_c12_5, x0
  ISB
  RET

   

// ------------------------------------------------------------

	.global gets3_6_c12_c12_5
  // unsigned int gets3_6_c12_c12_5(void)
	.type gets3_6_c12_c12_5, @function
gets3_6_c12_c12_5:
  MRS   x0, s3_6_c12_c12_5
  RET

   

// ------------------------------------------------------------

	.global enableGroup0Ints
  // void enableGroup0Ints(void)
	.type enableGroup0Ints, @function
enableGroup0Ints:
  MOV   w0, #1
  MSR   s3_0_c12_c12_6, x0
  ISB
  RET

   

// ------------------------------------------------------------

	.global disableGroup0Ints
  // void disableGroup0Ints(void)
	.type disableGroup0Ints, @function
disableGroup0Ints:

  MOV   w0, #0
  MSR   s3_0_c12_c12_6, x0
  ISB
  RET

   

// ------------------------------------------------------------

	.global enableGroup1Ints
  // void enableGroup1Ints((void)//
	.type enableGroup1Ints, @function
enableGroup1Ints:
  MRS   x0, s3_0_c12_c12_7
  ORR   w0, w0, #1
  MSR   s3_0_c12_c12_7, x0
  ISB
  RET

   

// ------------------------------------------------------------

	.global disableGroup1Ints
  // void disableGroup1Ints(void)//
	.type disableGroup1Ints, @function
disableGroup1Ints:
  MOV   w1, #1
  MRS   x0, s3_0_c12_c12_7
  BIC   x0, x0, x1
  MSR   s3_0_c12_c12_7, x0
  ISB
  RET
   
  
// ------------------------------------------------------------

	.global enableNSGroup1Ints
  // void enableNSGroup1Ints(void)
	.type enableNSGroup1Ints, @function
enableNSGroup1Ints:
  MRS   x0, s3_6_c12_c12_7
  ORR   w0, w0, #1
  MSR   s3_6_c12_c12_7, x0
  ISB
  RET

   

// ------------------------------------------------------------

	.global disableNSGroup1Ints
  // void disableNSGroup1Ints(void)
	.type disableNSGroup1Ints, @function
disableNSGroup1Ints:
  MOV   w1, #0x1
  MRS   x0, s3_6_c12_c12_7
  BIC   x0, x0, x1
  MSR   s3_6_c12_c12_7, x0
  ISB
  RET

   

// ------------------------------------------------------------

	.global gets3_6_c12_c12_4
  // unsigned int gets3_6_c12_c12_4(void)//
	.type gets3_6_c12_c12_4, @function
gets3_6_c12_c12_4:
  MRS   x0, s3_6_c12_c12_4
  RET
   

// ------------------------------------------------------------
	.global sets3_6_c12_c12_4
  // void sets3_6_c12_c12_4(unsigned int value)
	.type sets3_6_c12_c12_4, @function
sets3_6_c12_c12_4:
  MSR   s3_6_c12_c12_4, x0
  ISB
  RET

   

// ------------------------------------------------------------

	.global gets3_0_c12_c12_4
  // unsigned int gets3_0_c12_c12_4(void)//
	.type gets3_0_c12_c12_4, @function
gets3_0_c12_c12_4:
  MRS   x0, s3_0_c12_c12_4
  RET
   

// ------------------------------------------------------------

	.global sets3_0_c12_c12_4
  // void sets3_0_c12_c12_4(unsigned int value)
	.type sets3_0_c12_c12_4, @function
sets3_0_c12_c12_4:
  MSR   s3_0_c12_c12_4, x0
  ISB
  RET

   

// ------------------------------------------------------------

	.global readIARGrp0
  // unsigned int readIARGrp0(void)//
	.type readIARGrp0, @function
readIARGrp0:
  MRS   x0, s3_0_c12_c8_0
  RET
   

// ------------------------------------------------------------

	.global writeEOIGrp0
  // void writeEOIGrp0(unsigned int ID)//
	.type writeEOIGrp0, @function
writeEOIGrp0:
  MSR   s3_0_c12_c8_1, x0
  ISB
  RET
   

// ------------------------------------------------------------

	.global writeDIR
  // void writeDIR(unsigned int ID)//
	.type writeDIR, @function
writeDIR:
  MSR   s3_0_c12_c11_1, x0
  ISB
  RET
   
  
// ------------------------------------------------------------

	.global readIARGrp1
  // unsigned int readIARGrp1(void)//
	.type readIARGrp1, @function
readIARGrp1:
  MRS   x0, s3_0_c12_c12_0
  RET


// ------------------------------------------------------------

	.global writeEOIGrp1
  // void writeEOIGrp1(unsigned int ID)//
	.type writeEOIGrp1, @function
writeEOIGrp1:
  MSR   s3_0_c12_c12_1, x0
  DSB   SY
  RET
   
  
// ------------------------------------------------------------

	.global setPriorityMask
  // void setPriorityMask(unsigned int ID)//
	.type setPriorityMask, @function
setPriorityMask:
  MSR   s3_0_c4_c6_0, x0
  RET
   

// ------------------------------------------------------------

	.global getBPR0
  // unsigned int getBPR0(void)//
	.type getBPR0, @function
getBPR0:
  MRS   x0, s3_0_c12_c8_3
  RET
   

// ------------------------------------------------------------

	.global setBPR0
  // void setBPR0(unsigned int INTID)//
	.type setBPR0, @function
setBPR0:
  MSR   s3_0_c12_c8_3, x0
  ISB
  RET
   

// ------------------------------------------------------------

	.global getBPR1
  // unsigned int getBPR1(void)//
	.type getBPR1, @function
getBPR1:
  MRS   x0, s3_0_c12_c12_3
  RET
   

// ------------------------------------------------------------

	.global setBPR1
  // void setBPR1(unsigned int ID)//
	.type setBPR1, @function
setBPR1:
  MSR   s3_0_c12_c12_3, x0
  ISB
  RET
   

// ------------------------------------------------------------

	.global getRunningPriority
  // unsigned int getRunningPriority(void)//
	.type getRunningPriority, @function
getRunningPriority:
  MRS   x0, s3_0_c12_c11_3
  RET
   

// ------------------------------------------------------------
// SGIs
// ------------------------------------------------------------

	.global sendGroup0SGI
  // void sendGroup0SGI(unsigned int ID, unsigned int mode, unsigned target_list)//
	.type sendGroup0SGI, @function
sendGroup0SGI:
  ORR   x0, x0, x1
  ORR   x0, x0, x2
  MSR   s3_0_c12_c11_7, x0
  RET
   
  
// ------------------------------------------------------------

	.global sendGroup1SGI
  // void sendGroup1SGI(unsigned int ID, unsigned int mode, unsigned target_list)//
	.type sendGroup1SGI, @function
sendGroup1SGI:
  ORR   x0, x0, x1
  ORR   x0, x0, x2
  MSR   s3_0_c12_c11_5, x0
  RET
   

// ------------------------------------------------------------

	.global sendOtherGroup1SGI
  // void sendOtherGroup1SGI(unsigned int ID, unsigned int mode, unsigned target_list)//
	.type sendOtherGroup1SGI, @function
sendOtherGroup1SGI:
  ORR   x0, x0, x1
  ORR   x0, x0, x2
  MSR   s3_0_c12_c11_6, x0
  RET
   
    .type getAffinity, "function"
  .cfi_startproc
  .global getAffinity
getAffinity:
  MRS      x0, MPIDR_EL1
  UBFX     x1, x0, #32, #8
  BFI      w0, w1, #24, #8
  RET
  .cfi_endproc


// ------------------------------------------------------------
// End of code
// ------------------------------------------------------------

 
// ------------------------------------------------------------
// End of v8_aarch64_gicv3_cpuif.s
// ------------------------------------------------------------


case 0x00: /**** idl ****/
    Cycles += 2;
    Cycles += 1000;
    break;

case 0x01: /**** ldn r1 ****/
    Cycles += 2;
    D = READ(R[1]);
    break;

case 0x02: /**** ldn r2 ****/
    Cycles += 2;
    D = READ(R[2]);
    break;

case 0x03: /**** ldn r3 ****/
    Cycles += 2;
    D = READ(R[3]);
    break;

case 0x04: /**** ldn r4 ****/
    Cycles += 2;
    D = READ(R[4]);
    break;

case 0x05: /**** ldn r5 ****/
    Cycles += 2;
    D = READ(R[5]);
    break;

case 0x06: /**** ldn r6 ****/
    Cycles += 2;
    D = READ(R[6]);
    break;

case 0x07: /**** ldn r7 ****/
    Cycles += 2;
    D = READ(R[7]);
    break;

case 0x08: /**** ldn r8 ****/
    Cycles += 2;
    D = READ(R[8]);
    break;

case 0x09: /**** ldn r9 ****/
    Cycles += 2;
    D = READ(R[9]);
    break;

case 0x0a: /**** ldn ra ****/
    Cycles += 2;
    D = READ(R[10]);
    break;

case 0x0b: /**** ldn rb ****/
    Cycles += 2;
    D = READ(R[11]);
    break;

case 0x0c: /**** ldn rc ****/
    Cycles += 2;
    D = READ(R[12]);
    break;

case 0x0d: /**** ldn rd ****/
    Cycles += 2;
    D = READ(R[13]);
    break;

case 0x0e: /**** ldn re ****/
    Cycles += 2;
    D = READ(R[14]);
    break;

case 0x0f: /**** ldn rf ****/
    Cycles += 2;
    D = READ(R[15]);
    break;

case 0x10: /**** inc r0 ****/
    Cycles += 2;
    R[0]++;
    break;

case 0x11: /**** inc r1 ****/
    Cycles += 2;
    R[1]++;
    break;

case 0x12: /**** inc r2 ****/
    Cycles += 2;
    R[2]++;
    break;

case 0x13: /**** inc r3 ****/
    Cycles += 2;
    R[3]++;
    break;

case 0x14: /**** inc r4 ****/
    Cycles += 2;
    R[4]++;
    break;

case 0x15: /**** inc r5 ****/
    Cycles += 2;
    R[5]++;
    break;

case 0x16: /**** inc r6 ****/
    Cycles += 2;
    R[6]++;
    break;

case 0x17: /**** inc r7 ****/
    Cycles += 2;
    R[7]++;
    break;

case 0x18: /**** inc r8 ****/
    Cycles += 2;
    R[8]++;
    break;

case 0x19: /**** inc r9 ****/
    Cycles += 2;
    R[9]++;
    break;

case 0x1a: /**** inc ra ****/
    Cycles += 2;
    R[10]++;
    break;

case 0x1b: /**** inc rb ****/
    Cycles += 2;
    R[11]++;
    break;

case 0x1c: /**** inc rc ****/
    Cycles += 2;
    R[12]++;
    break;

case 0x1d: /**** inc rd ****/
    Cycles += 2;
    R[13]++;
    break;

case 0x1e: /**** inc re ****/
    Cycles += 2;
    R[14]++;
    break;

case 0x1f: /**** inc rf ****/
    Cycles += 2;
    R[15]++;
    break;

case 0x20: /**** dec r0 ****/
    Cycles += 2;
    R[0]--;
    break;

case 0x21: /**** dec r1 ****/
    Cycles += 2;
    R[1]--;
    break;

case 0x22: /**** dec r2 ****/
    Cycles += 2;
    R[2]--;
    break;

case 0x23: /**** dec r3 ****/
    Cycles += 2;
    R[3]--;
    break;

case 0x24: /**** dec r4 ****/
    Cycles += 2;
    R[4]--;
    break;

case 0x25: /**** dec r5 ****/
    Cycles += 2;
    R[5]--;
    break;

case 0x26: /**** dec r6 ****/
    Cycles += 2;
    R[6]--;
    break;

case 0x27: /**** dec r7 ****/
    Cycles += 2;
    R[7]--;
    break;

case 0x28: /**** dec r8 ****/
    Cycles += 2;
    R[8]--;
    break;

case 0x29: /**** dec r9 ****/
    Cycles += 2;
    R[9]--;
    break;

case 0x2a: /**** dec ra ****/
    Cycles += 2;
    R[10]--;
    break;

case 0x2b: /**** dec rb ****/
    Cycles += 2;
    R[11]--;
    break;

case 0x2c: /**** dec rc ****/
    Cycles += 2;
    R[12]--;
    break;

case 0x2d: /**** dec rd ****/
    Cycles += 2;
    R[13]--;
    break;

case 0x2e: /**** dec re ****/
    Cycles += 2;
    R[14]--;
    break;

case 0x2f: /**** dec rf ****/
    Cycles += 2;
    R[15]--;
    break;

case 0x30: /**** br .1 ****/
    Cycles += 2;
    BRANCH();
    break;

case 0x31: /**** bq .1 ****/
    Cycles += 2;
    if (Q != 0) BRANCH() else SKIP();
    break;

case 0x32: /**** bz .1 ****/
    Cycles += 2;
    if (D == 0) BRANCH() else SKIP();
    break;

case 0x33: /**** bdf .1 ****/
    Cycles += 2;
    if (DF != 0) BRANCH() else SKIP();
    break;

case 0x34: /**** b1 .1 ****/
    Cycles += 2;
    if (EFLAG1() != 0) BRANCH() else SKIP();
    break;

case 0x35: /**** b2 .1 ****/
    Cycles += 2;
    if (EFLAG2() != 0) BRANCH() else SKIP();
    break;

case 0x36: /**** b3 .1 ****/
    Cycles += 2;
    if (EFLAG3() != 0) BRANCH() else SKIP();
    break;

case 0x37: /**** b4 .1 ****/
    Cycles += 2;
    if (EFLAG4() != 0) BRANCH() else SKIP();
    break;

case 0x38: /**** skp ****/
    Cycles += 2;
    SKIP();
    break;

case 0x39: /**** bnq .1 ****/
    Cycles += 2;
    if (Q == 0) BRANCH() else SKIP();
    break;

case 0x3a: /**** bnz .1 ****/
    Cycles += 2;
    if (D != 0) BRANCH() else SKIP();
    break;

case 0x3b: /**** bnf .1 ****/
    Cycles += 2;
    if (DF == 0) BRANCH() else SKIP();
    break;

case 0x3c: /**** bn1 .1 ****/
    Cycles += 2;
    if (EFLAG1() == 0) BRANCH() else SKIP();
    break;

case 0x3d: /**** bn2 .1 ****/
    Cycles += 2;
    if (EFLAG2() == 0) BRANCH() else SKIP();
    break;

case 0x3e: /**** bn3 .1 ****/
    Cycles += 2;
    if (EFLAG3() == 0) BRANCH() else SKIP();
    break;

case 0x3f: /**** bn4 .1 ****/
    Cycles += 2;
    if (EFLAG4() == 0) BRANCH() else SKIP();
    break;

case 0x40: /**** lda r0 ****/
    Cycles += 2;
    D = READ(R[0]++);
    break;

case 0x41: /**** lda r1 ****/
    Cycles += 2;
    D = READ(R[1]++);
    break;

case 0x42: /**** lda r2 ****/
    Cycles += 2;
    D = READ(R[2]++);
    break;

case 0x43: /**** lda r3 ****/
    Cycles += 2;
    D = READ(R[3]++);
    break;

case 0x44: /**** lda r4 ****/
    Cycles += 2;
    D = READ(R[4]++);
    break;

case 0x45: /**** lda r5 ****/
    Cycles += 2;
    D = READ(R[5]++);
    break;

case 0x46: /**** lda r6 ****/
    Cycles += 2;
    D = READ(R[6]++);
    break;

case 0x47: /**** lda r7 ****/
    Cycles += 2;
    D = READ(R[7]++);
    break;

case 0x48: /**** lda r8 ****/
    Cycles += 2;
    D = READ(R[8]++);
    break;

case 0x49: /**** lda r9 ****/
    Cycles += 2;
    D = READ(R[9]++);
    break;

case 0x4a: /**** lda ra ****/
    Cycles += 2;
    D = READ(R[10]++);
    break;

case 0x4b: /**** lda rb ****/
    Cycles += 2;
    D = READ(R[11]++);
    break;

case 0x4c: /**** lda rc ****/
    Cycles += 2;
    D = READ(R[12]++);
    break;

case 0x4d: /**** lda rd ****/
    Cycles += 2;
    D = READ(R[13]++);
    break;

case 0x4e: /**** lda re ****/
    Cycles += 2;
    D = READ(R[14]++);
    break;

case 0x4f: /**** lda rf ****/
    Cycles += 2;
    D = READ(R[15]++);
    break;

case 0x50: /**** str r0 ****/
    Cycles += 2;
    WRITE(R[0],D);
    break;

case 0x51: /**** str r1 ****/
    Cycles += 2;
    WRITE(R[1],D);
    break;

case 0x52: /**** str r2 ****/
    Cycles += 2;
    WRITE(R[2],D);
    break;

case 0x53: /**** str r3 ****/
    Cycles += 2;
    WRITE(R[3],D);
    break;

case 0x54: /**** str r4 ****/
    Cycles += 2;
    WRITE(R[4],D);
    break;

case 0x55: /**** str r5 ****/
    Cycles += 2;
    WRITE(R[5],D);
    break;

case 0x56: /**** str r6 ****/
    Cycles += 2;
    WRITE(R[6],D);
    break;

case 0x57: /**** str r7 ****/
    Cycles += 2;
    WRITE(R[7],D);
    break;

case 0x58: /**** str r8 ****/
    Cycles += 2;
    WRITE(R[8],D);
    break;

case 0x59: /**** str r9 ****/
    Cycles += 2;
    WRITE(R[9],D);
    break;

case 0x5a: /**** str ra ****/
    Cycles += 2;
    WRITE(R[10],D);
    break;

case 0x5b: /**** str rb ****/
    Cycles += 2;
    WRITE(R[11],D);
    break;

case 0x5c: /**** str rc ****/
    Cycles += 2;
    WRITE(R[12],D);
    break;

case 0x5d: /**** str rd ****/
    Cycles += 2;
    WRITE(R[13],D);
    break;

case 0x5e: /**** str re ****/
    Cycles += 2;
    WRITE(R[14],D);
    break;

case 0x5f: /**** str rf ****/
    Cycles += 2;
    WRITE(R[15],D);
    break;

case 0x60: /**** irx ****/
    Cycles += 2;
    R[X]++;
    break;

case 0x61: /**** out 1 ****/
    Cycles += 2;
    OUTPORT1(READ(R[X]));
    R[X]++;
    break;

case 0x62: /**** out 2 ****/
    Cycles += 2;
    OUTPORT2(READ(R[X]));
    R[X]++;
    break;

case 0x63: /**** out 3 ****/
    Cycles += 2;
    OUTPORT3(READ(R[X]));
    R[X]++;
    break;

case 0x64: /**** out 4 ****/
    Cycles += 2;
    OUTPORT4(READ(R[X]));
    R[X]++;
    break;

case 0x65: /**** out 5 ****/
    Cycles += 2;
    OUTPORT5(READ(R[X]));
    R[X]++;
    break;

case 0x66: /**** out 6 ****/
    Cycles += 2;
    OUTPORT6(READ(R[X]));
    R[X]++;
    break;

case 0x67: /**** out 7 ****/
    Cycles += 2;
    OUTPORT7(READ(R[X]));
    R[X]++;
    break;

case 0x69: /**** inp 1 ****/
    Cycles += 2;
    D = INPORT1();
    WRITE(R[X],D);
    break;

case 0x6a: /**** inp 2 ****/
    Cycles += 2;
    D = INPORT2();
    WRITE(R[X],D);
    break;

case 0x6b: /**** inp 3 ****/
    Cycles += 2;
    D = INPORT3();
    WRITE(R[X],D);
    break;

case 0x6c: /**** inp 4 ****/
    Cycles += 2;
    D = INPORT4();
    WRITE(R[X],D);
    break;

case 0x6d: /**** inp 5 ****/
    Cycles += 2;
    D = INPORT5();
    WRITE(R[X],D);
    break;

case 0x6e: /**** inp 6 ****/
    Cycles += 2;
    D = INPORT6();
    WRITE(R[X],D);
    break;

case 0x6f: /**** inp 7 ****/
    Cycles += 2;
    D = INPORT7();
    WRITE(R[X],D);
    break;

case 0x70: /**** ret ****/
    Cycles += 2;
    RETURN();
    IE = 1;
    break;

case 0x71: /**** dis ****/
    Cycles += 2;
    RETURN();
    IE = 0;
    break;

case 0x72: /**** ldxa ****/
    Cycles += 2;
    D = READ(R[X]++);
    break;

case 0x73: /**** stxd ****/
    Cycles += 2;
    WRITE(R[X]--,D);
    break;

case 0x74: /**** adc ****/
    Cycles += 2;
    ADD(D,READ(R[X]),DF);
    break;

case 0x75: /**** sdb ****/
    Cycles += 2;
    SUB(READ(R[X]),D,DF);
    break;

case 0x76: /**** rshr ****/
    Cycles += 2;
    temp8 = D;
    D = (D >> 1) | (DF << 7);
    DF = temp8 & 1;
    break;

case 0x77: /**** smb ****/
    Cycles += 2;
    SUB(D,READ(R[X]),DF);
    break;

case 0x78: /**** sav ****/
    Cycles += 2;
    WRITE(R[X],T);
    break;

case 0x79: /**** mark ****/
    Cycles += 2;
    T = (X << 4) | P;
    WRITE(R[2],T);
    X = P;
    R[2]--;
    break;

case 0x7a: /**** req ****/
    Cycles += 2;
    OUTPORTQ(Q,0);
    Q = 0;
    break;

case 0x7b: /**** seq ****/
    Cycles += 2;
    OUTPORTQ(Q,1);
    Q = 1;
    break;

case 0x7c: /**** adci .1 ****/
    Cycles += 2;
    ADD(D,FETCH(),DF);
    break;

case 0x7d: /**** sdbi .1 ****/
    Cycles += 2;
    SUB(FETCH(),D,DF);
    break;

case 0x7e: /**** rshl ****/
    Cycles += 2;
    temp8 = D;
    D = (D << 1) | DF;
    DF = temp8 >> 7;
    break;

case 0x7f: /**** smbi .1 ****/
    Cycles += 2;
    SUB(D,FETCH(),DF);
    break;

case 0x80: /**** glo r0 ****/
    Cycles += 2;
    D = R[0];
    break;

case 0x81: /**** glo r1 ****/
    Cycles += 2;
    D = R[1];
    break;

case 0x82: /**** glo r2 ****/
    Cycles += 2;
    D = R[2];
    break;

case 0x83: /**** glo r3 ****/
    Cycles += 2;
    D = R[3];
    break;

case 0x84: /**** glo r4 ****/
    Cycles += 2;
    D = R[4];
    break;

case 0x85: /**** glo r5 ****/
    Cycles += 2;
    D = R[5];
    break;

case 0x86: /**** glo r6 ****/
    Cycles += 2;
    D = R[6];
    break;

case 0x87: /**** glo r7 ****/
    Cycles += 2;
    D = R[7];
    break;

case 0x88: /**** glo r8 ****/
    Cycles += 2;
    D = R[8];
    break;

case 0x89: /**** glo r9 ****/
    Cycles += 2;
    D = R[9];
    break;

case 0x8a: /**** glo ra ****/
    Cycles += 2;
    D = R[10];
    break;

case 0x8b: /**** glo rb ****/
    Cycles += 2;
    D = R[11];
    break;

case 0x8c: /**** glo rc ****/
    Cycles += 2;
    D = R[12];
    break;

case 0x8d: /**** glo rd ****/
    Cycles += 2;
    D = R[13];
    break;

case 0x8e: /**** glo re ****/
    Cycles += 2;
    D = R[14];
    break;

case 0x8f: /**** glo rf ****/
    Cycles += 2;
    D = R[15];
    break;

case 0x90: /**** ghi r0 ****/
    Cycles += 2;
    D = R[0] >> 8;
    break;

case 0x91: /**** ghi r1 ****/
    Cycles += 2;
    D = R[1] >> 8;
    break;

case 0x92: /**** ghi r2 ****/
    Cycles += 2;
    D = R[2] >> 8;
    break;

case 0x93: /**** ghi r3 ****/
    Cycles += 2;
    D = R[3] >> 8;
    break;

case 0x94: /**** ghi r4 ****/
    Cycles += 2;
    D = R[4] >> 8;
    break;

case 0x95: /**** ghi r5 ****/
    Cycles += 2;
    D = R[5] >> 8;
    break;

case 0x96: /**** ghi r6 ****/
    Cycles += 2;
    D = R[6] >> 8;
    break;

case 0x97: /**** ghi r7 ****/
    Cycles += 2;
    D = R[7] >> 8;
    break;

case 0x98: /**** ghi r8 ****/
    Cycles += 2;
    D = R[8] >> 8;
    break;

case 0x99: /**** ghi r9 ****/
    Cycles += 2;
    D = R[9] >> 8;
    break;

case 0x9a: /**** ghi ra ****/
    Cycles += 2;
    D = R[10] >> 8;
    break;

case 0x9b: /**** ghi rb ****/
    Cycles += 2;
    D = R[11] >> 8;
    break;

case 0x9c: /**** ghi rc ****/
    Cycles += 2;
    D = R[12] >> 8;
    break;

case 0x9d: /**** ghi rd ****/
    Cycles += 2;
    D = R[13] >> 8;
    break;

case 0x9e: /**** ghi re ****/
    Cycles += 2;
    D = R[14] >> 8;
    break;

case 0x9f: /**** ghi rf ****/
    Cycles += 2;
    D = R[15] >> 8;
    break;

case 0xa0: /**** plo r0 ****/
    Cycles += 2;
    R[0] = (R[0] & 0xFF00) | D;
    break;

case 0xa1: /**** plo r1 ****/
    Cycles += 2;
    R[1] = (R[1] & 0xFF00) | D;
    break;

case 0xa2: /**** plo r2 ****/
    Cycles += 2;
    R[2] = (R[2] & 0xFF00) | D;
    break;

case 0xa3: /**** plo r3 ****/
    Cycles += 2;
    R[3] = (R[3] & 0xFF00) | D;
    break;

case 0xa4: /**** plo r4 ****/
    Cycles += 2;
    R[4] = (R[4] & 0xFF00) | D;
    break;

case 0xa5: /**** plo r5 ****/
    Cycles += 2;
    R[5] = (R[5] & 0xFF00) | D;
    break;

case 0xa6: /**** plo r6 ****/
    Cycles += 2;
    R[6] = (R[6] & 0xFF00) | D;
    break;

case 0xa7: /**** plo r7 ****/
    Cycles += 2;
    R[7] = (R[7] & 0xFF00) | D;
    break;

case 0xa8: /**** plo r8 ****/
    Cycles += 2;
    R[8] = (R[8] & 0xFF00) | D;
    break;

case 0xa9: /**** plo r9 ****/
    Cycles += 2;
    R[9] = (R[9] & 0xFF00) | D;
    break;

case 0xaa: /**** plo ra ****/
    Cycles += 2;
    R[10] = (R[10] & 0xFF00) | D;
    break;

case 0xab: /**** plo rb ****/
    Cycles += 2;
    R[11] = (R[11] & 0xFF00) | D;
    break;

case 0xac: /**** plo rc ****/
    Cycles += 2;
    R[12] = (R[12] & 0xFF00) | D;
    break;

case 0xad: /**** plo rd ****/
    Cycles += 2;
    R[13] = (R[13] & 0xFF00) | D;
    break;

case 0xae: /**** plo re ****/
    Cycles += 2;
    R[14] = (R[14] & 0xFF00) | D;
    break;

case 0xaf: /**** plo rf ****/
    Cycles += 2;
    R[15] = (R[15] & 0xFF00) | D;
    break;

case 0xb0: /**** phi r0 ****/
    Cycles += 2;
    R[0] = (R[0] & 0x00FF) | (((WORD16)D) << 8);
    break;

case 0xb1: /**** phi r1 ****/
    Cycles += 2;
    R[1] = (R[1] & 0x00FF) | (((WORD16)D) << 8);
    break;

case 0xb2: /**** phi r2 ****/
    Cycles += 2;
    R[2] = (R[2] & 0x00FF) | (((WORD16)D) << 8);
    break;

case 0xb3: /**** phi r3 ****/
    Cycles += 2;
    R[3] = (R[3] & 0x00FF) | (((WORD16)D) << 8);
    break;

case 0xb4: /**** phi r4 ****/
    Cycles += 2;
    R[4] = (R[4] & 0x00FF) | (((WORD16)D) << 8);
    break;

case 0xb5: /**** phi r5 ****/
    Cycles += 2;
    R[5] = (R[5] & 0x00FF) | (((WORD16)D) << 8);
    break;

case 0xb6: /**** phi r6 ****/
    Cycles += 2;
    R[6] = (R[6] & 0x00FF) | (((WORD16)D) << 8);
    break;

case 0xb7: /**** phi r7 ****/
    Cycles += 2;
    R[7] = (R[7] & 0x00FF) | (((WORD16)D) << 8);
    break;

case 0xb8: /**** phi r8 ****/
    Cycles += 2;
    R[8] = (R[8] & 0x00FF) | (((WORD16)D) << 8);
    break;

case 0xb9: /**** phi r9 ****/
    Cycles += 2;
    R[9] = (R[9] & 0x00FF) | (((WORD16)D) << 8);
    break;

case 0xba: /**** phi ra ****/
    Cycles += 2;
    R[10] = (R[10] & 0x00FF) | (((WORD16)D) << 8);
    break;

case 0xbb: /**** phi rb ****/
    Cycles += 2;
    R[11] = (R[11] & 0x00FF) | (((WORD16)D) << 8);
    break;

case 0xbc: /**** phi rc ****/
    Cycles += 2;
    R[12] = (R[12] & 0x00FF) | (((WORD16)D) << 8);
    break;

case 0xbd: /**** phi rd ****/
    Cycles += 2;
    R[13] = (R[13] & 0x00FF) | (((WORD16)D) << 8);
    break;

case 0xbe: /**** phi re ****/
    Cycles += 2;
    R[14] = (R[14] & 0x00FF) | (((WORD16)D) << 8);
    break;

case 0xbf: /**** phi rf ****/
    Cycles += 2;
    R[15] = (R[15] & 0x00FF) | (((WORD16)D) << 8);
    break;

case 0xc0: /**** lbr .2 ****/
    Cycles += 3;
    LBRANCH();
    break;

case 0xc1: /**** lbq .2 ****/
    Cycles += 3;
    if (Q != 0) LBRANCH() else LSKIP();
    break;

case 0xc2: /**** lbz .2 ****/
    Cycles += 3;
    if (D == 0) LBRANCH() else LSKIP();
    break;

case 0xc3: /**** lbdf .2 ****/
    Cycles += 3;
    if (DF != 0) LBRANCH() else LSKIP();
    break;

case 0xc4: /**** nop ****/
    Cycles += 3;
    {};
    break;

case 0xc5: /**** lsnq ****/
    Cycles += 3;
    if (Q == 0) LSKIP();
    break;

case 0xc6: /**** lsnz ****/
    Cycles += 3;
    if (D != 0) LSKIP();
    break;

case 0xc7: /**** lsnf ****/
    Cycles += 3;
    if (DF == 0) LSKIP();
    break;

case 0xc8: /**** lskp ****/
    Cycles += 3;
    LSKIP();
    break;

case 0xc9: /**** lbnq .2 ****/
    Cycles += 3;
    if (Q == 0) LBRANCH() else LSKIP();
    break;

case 0xca: /**** lbnz .2 ****/
    Cycles += 3;
    if (D != 0) LBRANCH() else LSKIP();
    break;

case 0xcb: /**** lbnf .2 ****/
    Cycles += 3;
    if (DF == 0) LBRANCH() else LSKIP();
    break;

case 0xcc: /**** lsie ****/
    Cycles += 3;
    if (IE != 0) LSKIP();
    break;

case 0xcd: /**** lsq ****/
    Cycles += 3;
    if (Q != 0) LSKIP();
    break;

case 0xce: /**** lsz ****/
    Cycles += 3;
    if (D == 0) LSKIP();
    break;

case 0xcf: /**** lsdf ****/
    Cycles += 3;
    if (DF != 0) LSKIP();
    break;

case 0xd0: /**** sep r0 ****/
    Cycles += 2;
    P = 0;
    break;

case 0xd1: /**** sep r1 ****/
    Cycles += 2;
    P = 1;
    break;

case 0xd2: /**** sep r2 ****/
    Cycles += 2;
    P = 2;
    break;

case 0xd3: /**** sep r3 ****/
    Cycles += 2;
    P = 3;
    break;

case 0xd4: /**** sep r4 ****/
    Cycles += 2;
    P = 4;
    break;

case 0xd5: /**** sep r5 ****/
    Cycles += 2;
    P = 5;
    break;

case 0xd6: /**** sep r6 ****/
    Cycles += 2;
    P = 6;
    break;

case 0xd7: /**** sep r7 ****/
    Cycles += 2;
    P = 7;
    break;

case 0xd8: /**** sep r8 ****/
    Cycles += 2;
    P = 8;
    break;

case 0xd9: /**** sep r9 ****/
    Cycles += 2;
    P = 9;
    break;

case 0xda: /**** sep ra ****/
    Cycles += 2;
    P = 10;
    break;

case 0xdb: /**** sep rb ****/
    Cycles += 2;
    P = 11;
    break;

case 0xdc: /**** sep rc ****/
    Cycles += 2;
    P = 12;
    break;

case 0xdd: /**** sep rd ****/
    Cycles += 2;
    P = 13;
    break;

case 0xde: /**** sep re ****/
    Cycles += 2;
    P = 14;
    break;

case 0xdf: /**** sep rf ****/
    Cycles += 2;
    P = 15;
    break;

case 0xe0: /**** sex r0 ****/
    Cycles += 2;
    X = 0;
    break;

case 0xe1: /**** sex r1 ****/
    Cycles += 2;
    X = 1;
    break;

case 0xe2: /**** sex r2 ****/
    Cycles += 2;
    X = 2;
    break;

case 0xe3: /**** sex r3 ****/
    Cycles += 2;
    X = 3;
    break;

case 0xe4: /**** sex r4 ****/
    Cycles += 2;
    X = 4;
    break;

case 0xe5: /**** sex r5 ****/
    Cycles += 2;
    X = 5;
    break;

case 0xe6: /**** sex r6 ****/
    Cycles += 2;
    X = 6;
    break;

case 0xe7: /**** sex r7 ****/
    Cycles += 2;
    X = 7;
    break;

case 0xe8: /**** sex r8 ****/
    Cycles += 2;
    X = 8;
    break;

case 0xe9: /**** sex r9 ****/
    Cycles += 2;
    X = 9;
    break;

case 0xea: /**** sex ra ****/
    Cycles += 2;
    X = 10;
    break;

case 0xeb: /**** sex rb ****/
    Cycles += 2;
    X = 11;
    break;

case 0xec: /**** sex rc ****/
    Cycles += 2;
    X = 12;
    break;

case 0xed: /**** sex rd ****/
    Cycles += 2;
    X = 13;
    break;

case 0xee: /**** sex re ****/
    Cycles += 2;
    X = 14;
    break;

case 0xef: /**** sex rf ****/
    Cycles += 2;
    X = 15;
    break;

case 0xf0: /**** ldx ****/
    Cycles += 2;
    D = READ(R[X]);
    break;

case 0xf1: /**** or ****/
    Cycles += 2;
    D = D | READ(R[X]);
    break;

case 0xf2: /**** and ****/
    Cycles += 2;
    D = D & READ(R[X]);
    break;

case 0xf3: /**** xor ****/
    Cycles += 2;
    D = D ^ READ(R[X]);
    break;

case 0xf4: /**** add ****/
    Cycles += 2;
    ADD(D,READ(R[X]),0);
    break;

case 0xf5: /**** sd ****/
    Cycles += 2;
    SUB(READ(R[X]),D,1);
    break;

case 0xf6: /**** shr ****/
    Cycles += 2;
    DF = D & 1;
    D = D >> 1;
    break;

case 0xf7: /**** sm ****/
    Cycles += 2;
    SUB(D,READ(R[X]),1);
    break;

case 0xf8: /**** ldi .1 ****/
    Cycles += 2;
    D = FETCH();
    break;

case 0xf9: /**** ori .1 ****/
    Cycles += 2;
    D = D | FETCH();
    break;

case 0xfa: /**** ani .1 ****/
    Cycles += 2;
    D = D & FETCH();
    break;

case 0xfb: /**** xri .1 ****/
    Cycles += 2;
    D = D ^ FETCH();
    break;

case 0xfc: /**** adi .1 ****/
    Cycles += 2;
    ADD(D,FETCH(),0);
    break;

case 0xfd: /**** sdi .1 ****/
    Cycles += 2;
    SUB(FETCH(),D,1);
    break;

case 0xfe: /**** shl ****/
    Cycles += 2;
    DF = D >> 7;
    D = D << 1;
    break;

case 0xff: /**** smi .1 ****/
    Cycles += 2;
    SUB(D,FETCH(),1);
    break;


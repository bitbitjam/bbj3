static BYTE8  D,DF,IE,Q,T,P,X,temp8;
static WORD16  R[16],Cycles,temp16;
#define FETCH() READ(R[P]++)
#define RESET()  { Q = 0;IE = 1; X = P = R[0] = 0; DF &= 1; }
#define ADD(n1,n2,df) temp16 = (n1)+(n2)+(df);D = temp16;DF = (temp16 >> 8) & 1
#define SUB(n1,n2,df)  ADD(n1,(n2) ^ 0xFF,df)
#define BRANCH()  { R[P] = (R[P] & 0xFF00) | READ(R[P]); }
#define SKIP()  { R[P]++; }
#define LBRANCH()  { R[P] = (READ(R[P]) << 8) | READ(R[P]+1);Cycles++; }
#define LSKIP()  { R[P] += 2; }
#define INTERRUPT() if (IE != 0) { T = (X << 4) | P; X = 2;P = 1;IE = 0; }
#define RETURN() { temp8 = READ(R[X]);R[X]++;P = temp8 & 0xF;X = temp8 >> 4; }
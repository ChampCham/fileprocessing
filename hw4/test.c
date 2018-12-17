#include<stdio.h>
int getByte(int x, int n){
    return (x >> (n << 3)) & 255;
}

int logicalShift(int x, int n){
    int mask = 1 << 31;
    return (x >> n) & ~((mask >> n)<<1);
}
int bang(int x) {
    int minus_x = ~x+1;
    return ((x | minus_x) >> 31)+1;
}

//int isLessOrEqual(int x, int y) {
  //  int leftBit = 1 << 31;
    //int negLeft = !!(x&leftBit)+~(!!(y&leftBit))+1;
    //printf("%d ",negLeft);
    //return !!((((y+~x+1) >> 31)+1) + negLeft);
// }

int isLessOrEqual(int x, int y) {
    int leftBit = 1 << 31;
    int neg = !!((x&leftBit)^(y&leftBit));
    int negLeft = neg & (x>>31);
    int negRight = neg & (y>>31);
    return ((((y+~x+1) >> 31)+1) | negLeft) & !negRight;
}

int leastBitPos(int x) {
   return x & (~x+ 1);
 }

//int divpwr2(int x, int n) {
//    int leftBit = 1 << 31;
//   int zero = !!n;
//    int dividable = ((x >> (n+~0))&1);
//    int neg = !!(x&leftBit);
//    printf("%d ", dividable-neg);
//   return (x>>n)+((dividable&neg&zero)+(dividable-neg));
//}
int divpwr2(int x, int n) {
//    int leftBit = 1 << 31;
//    leftBit =  ~(leftBit >> (31-n));
//    int mod = x&leftBit;
 //   int divisible = !(mod);
  //  return (x>>n)+(1&!divisible);
   int leftBit = 1 << 31;
   int mod =  x&(~(leftBit >> (31+~n+1)));
   printf("%d ", mod);
   int divisible = !!mod;
   int neg = !!(x&leftBit);
   return (x>>n)+(1&divisible&neg);
}

int isAsciiDigit(int x) {
   return (((x+ ~0x30 +1) >> 31) + 1) & (((0x3a + ~x) >> 31) + 1);
}

int isPositive(int x){
    return ((x+~0+!!(x))>> 31) + 1;
}

int fitsBits(int x, int n){
    int shift = (x << (33 +~n)) >> (33 +~n);
    return !(x + ~shift+1);

}

int bitCount(int x){
        int mask = 1 << 31;
        int all1 = 17+ (17 << 8)+(17 << 16)+(17 << 24);
        int all2 = all1 << 1;
        int all4 = all2 << 1;
        int all8 = all4 << 1;
        int  byte1, byte2, byte3, byte4, byte5, byte6, byte7, byte8;
        int c = x&all1;
        c = c + ((x&all2)>>1);
        c = c + ((x&all4)>>2);
        c = c + (((x&all8)>>3)&~(mask>>2));
        printf("%#x\n", c);
        byte1 = (c>>28)&15;
        byte2 = (c>>24)&15;
        byte3 = (c>>20)&15;
        byte4 = (c>>16)&15;
        byte5 = (c>>12)&15;
        byte6 = (c>>8)&15;
        byte7 = (c>>4)&15;
        byte8 = c&15;
        return (byte1+byte2+byte3+byte4+byte5+byte6+byte7+byte8);
}
int main(){
    //printf("%d\n", ~x +1 );
    //printf("%#x %#x", getByte(0x12345678,2), 0x56);
    //int x = 0x87654321;
    //printf("%#x ", logicalShift(x,0));
    //int x  = (~0) >> 21;
    //printf("%#x\n", x);
    //printf("%#x\n", getByte(x, 1));
    //printf("%#x\n", !0x10);
    //printf("%#x\n", logicalShift(x, 0));
    //printf("%#x\n", logicalShift(x, 4));
    //printf("%#x\n", logicalShift(x, 31));
    //printf("%#x\n", bang(90));
    
    //printf("%#x\n", isLessOrEqual(1,4));
   ///printf("%#x\n", isLessOrEqual(-2147483648, 0));
     //printf("%#x\n", isLessOrEqual(-2147483648, -2147483648));
    //printf("%#x\n", isLessOrEqual(-2147483648,1));
    // printf("%#x\n", isLessOrEqual(-2147483648,2147483647));
    // printf("%#x\n", isLessOrEqual(4, 0));
    // printf("%#x\n", isLessOrEqual(2147483647, -2147483648));
    
    //printf("%#x\n", leastBitPos(100));
    //int c = 0xffffffd;
    //printf("%d %d %d\n", divpwr2(-33,4), c, 0xffffffdf);
    //for (int i = -10; i < 20; i++){
        //printf("%#x %#x %d \n", isAsciiDigit(i), i, i);
    //   printf("%#x %#x %d \n", isPositive(i), i, i);
   // }i
   //printf("%lu\n", ~(-2147483648) + 1);
   //printf("%#x\n", isLessOrEqual(-2147483648,0)); 
   //printf("%#x\n", fitsBits(-4,3));
    //printf("%#x\n", fitsBits(5,3));
    //printf("%#x\n", fitsBits(-6,5));
    //printf("%#x\n", fitsBits(1,2));
        //for (int i = 0; i <= 31; i++){
        //    printf("%#x", logicalShift(x, i))
    // }
        ///printf("%d %#x %d \n", 0xfffffd, -33/16, -33/16);
        //``printf("%#x", )
    //    printf("%d\n", divpwr2(15,1));
    //    printf("%d\n", divpwr2(-33,4));
    //    printf("%#x\n",divpwr2(-2147483648,1));
    //    printf("%#x\n",divpwr2(-2147483647,1));
    //    printf("%#x\n", divpwr2(-1,1));
    //    printf("%#x\n", divpwr2(-2147483646,2));
     //   printf("%#x\n", divpwr2(-2147483647,0));
     //   printf("%#x\n", divpwr2(-2147483648,0));
     //   printf("%#x\n", divpwr2(-2147483647,2));
    //
    //
    //
    //divpwr2(-2147483648[0x80000000],1[0x1])
    //divpwr2(-2147483647[0x80000001],1[0x1]) failed...
//...Gives -1073741824[0xc0000000]. Should be -1073741823[0xc0000001]

    //printf("%d\n", divpwr2(1<<31, 1));
    // printf("%#x\n", (1<<31)+1);
   // printf("%#x\n", -1073741823);
   // printf("%#x\n", 1<<30);
     //  printf("%#x\n", (1<<30) >> 2);
    //printf("%d %d\n", 1<<31, (1<<31) >> 1);
    //printf("%#x\n", fitsBits(5,3));
    //printf("%#x\n", fitsBits(-4,31));
    //printf("%#x\n", isLessOrEqual(-4, 1));



    //printf("%#x\n", -4);
    //printf("%#x\n", fitsBits(5,3));
    // printf("%#x\n", fitsBits(-8,4));
    //printf("%#x\n", fitsBits(-4,3));
    printf("%d\n", bitCount(5));
    printf("%d\n", bitCount(7));
    printf("%d\n", bitCount(0x80000000));
    printf("%d", 0xe0000000);
}

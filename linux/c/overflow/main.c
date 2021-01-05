#include <stdint.h>
#include <stdio.h>

void test(void)
{
    int a = 0x2;
    int b = 0x80800000;
    uint64_t c = 0;
    // * a x b = 0x1 0100 0000, a x b结果仍为 int, 相乘溢出, 有符号溢出
    // * 截断为 0x0100 0000, 扩展为 uint64/int64 时，其最高位为0，扩展位则为0，扩展为
    // * 0x0000 0000 0100 0000
    c = a * b;
    printf("c = %#llx\n", c);

    a = 0x2;
    b = 0xC0800000;
    // * a x b = 0x1 8100 0000, a x b结果仍为 int, 相乘溢出, 有符号溢出
    // * 截断为 0x8100 0000, 扩展为 uint64/int64 时，其最高位为1，扩展位则为1，扩展为
    // * 0xFFFF FFFF 8100 0000
    c = a * b;
    printf("c = %#llx\n", c);

    // * 有符号数与无符号数运算，默认将有符号数看作无符号, 算术运算返回无符号数
    // * 逻辑运算返回 0 或 1
    int d = -1;
    uint32_t e = 20;
    // * 0xFFFF FFFF x 0x14 = 0x13 FFFF FFEC, 无符号溢出, 溢出后的结果为
    // * 溢出数 % (2^(8*sizeof(uint32_t))) = 0x13 FFFF FFEC % (2^32) = 0xFFFF FFEC
    uint32_t f = d * e;
    if (d > e)
        printf("f = %#x\n", f);

    // * 比 int 小的整型（包括short 、unsigned short 、 unsigned char和char）在运算中都要转换成int然后进行运算
    // * 如果是 unsigned 的类型转换成 int/unsigned int 类型，高位补 0
    // * 如果是 signed 的类型转换成 int/unsigned int 类型，如果原来最高位是 1 则补 1 ，如果是 0 则补 0
    char g = -1;
    uint8_t h = 255;
    // * 0xFFFF FFFF + 0x0000 00FF = 0x1 0000 00FE, 0x1 0000 00FE % (2^8) = 0x0000 00FE
    uint8_t i = g + h;
    printf("i = %#x\n", i);
    g = 1;
    // * 0x0000 0001 + 0x0000 00FF = 0x0000 0100
    i = g + h;
    printf("l = %#x\n", i);

    // * 因为二进制小数与十进制小数没有完全一一对应的关系，二进制小数对于十进制小数来说相当于是离散的而不是连续的,
    // * 所以 float 的有效位只有6位，
    float j = 9.87654311;
    float k = 9.87654322;
    if (j == k)
        printf("j == k\n");
    // * 个位，十位不是有效位
    j = 987654321;
    k = 987654322;
    if (j == k)
        printf("j == k\n");
    // * 对于这种数量级相差很大的计算，计算结果会保证高位数有效，数量级小的数相对计算结果显的太小了
    // * 不能按自身6位的精度保持，而是需要按照计算结果的6位精度保持
    j = 987654321;
    k = 987.654322;
    float l = j + k;
    printf("l = %.7f\n", l); // * 987655296.0000000
    // * 浮点数上溢会变为无穷大，下溢会丢失精度
}

int main(void)
{
    test();
    return 0;
}
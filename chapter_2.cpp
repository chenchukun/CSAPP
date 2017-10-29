#include <iostream>
#include <string>
using namespace std;

// 无符号整数表示 B2U(x) = ∑(0, w-1)xi*2^i
// 有符号数整数表示 B2T(x) = -xw-1*2^(w-1) + ∑(0, w-2)xi*2^i
// 大多数计算机使用相同的机器指令执行无符号或者有符号数加法
// 整数类型转换
void testIntegerConvert()
{
    cout << "---------------testIntegerConvert---------------" << endl;
    // 常量默认为有符号数
    int i = -1;
    int j = 0;
    cout << ((i > j)?"-1>0": "-1<0") << endl;

    unsigned int k = 0u;
    // 一个表达式中同时含有有符号数和无符号数时,隐式的将有符号数转为无符号数。
    // 转为无符号数不改变字节序,只是改变对其解释方式。
    cout << ((i > k)?"-1>0": "-1<0") << endl;

    // -1为有符号数,二进制表示为1111..1111,转换有符号数后二进制表示不变,只是解释方式变了。
    unsigned int x = -1;
    cout << "x= " << x << endl;

    // 对于需要扩展的类型转换,根据有无符号数,填充符号位或0
    // 对于有符号数的扩展,扩展位用符号位填充
    short int si = 100;
    int ii = si;
    cout << "ii = " << ii << endl;

    // 对于需要扩展,且需要进行有无符号数转换的类型转换
    // 按照原有类型进行扩展(填充0或填充符号位),之后按照不同的类型进行解释
    short int sii = 0x8000;
    cout << "sii: " << sii << endl;
    cout << "(unsigned short int)sii = " << (unsigned short int)sii << endl;
    unsigned int ui = sii;  // 0xFFFF8000
    cout << "ui = " << ui << endl;

    unsigned short int usi = 0x8000u;
    int iii = usi;   // 0x00008000
    cout << "usi = " << usi << endl;
    cout << "iii = " << iii << endl;

    // 对于需要截短的类型转换,直接截取低字节二进制位
    // 截短,只是简单的截取指定大小的二进制位
    int16_t i16 = 0x8080;
    cout << "i16 = " << i16 << endl;
    int8_t i8 = i16;
    cout << "i8 = " << int(i8) << endl;

    // 溢出
    int y = INT32_MIN * 2;
    cout << "y = " << y << endl;
    unsigned int a = UINT32_MAX - 100000;
    unsigned int b = UINT32_MAX - 200000;
    // 无符号加法当相加后的值太大是发生溢出
    // 判断无符号加法溢出的方法,相加后的值比其中一个值小
    unsigned int c = a + b;
    if (c < a || c < b) {
        cout << "overflow" << endl;
    }

    // 有符号数加法,结果太大或太小是发生溢出
    // 两个负数相加,结果为正,发生负溢出
    short int siii = 0x8001;
    short int ssum = siii + siii;   // 0x0002
    cout << "ssum = " << ssum << endl;
    // 两个正数相加,结果为负,发生正溢出
    siii = 0x7FFF;
    ssum = siii + siii;     // 0xFFFE
    cout << "ssum = " << ssum << endl;

    // 取非
    short int sni = 0x8001;
    cout << "sni = " << sni << endl;
    cout << "-sni = " << -sni << endl;

    unsigned short int usni = 0x0001;
    cout << "uni = " << usni << endl;
    cout << "-uni = " << -usni << endl;
}

// 浮点数
// ---------------------------
// |s|exp     |frac          |
// ---------------------------
// 二进制小数表示法:
//  b = ∑(i=-n, m)2^i*bi 只能精确表示能写成x*2^y(x/2^k)的数,且若给定w位,说能表示的范围非常有限。
// IEEE浮点数:
// 单精度 s(1)exp(8)frac(23)   双精度 s(1)exp(11)frac(52) 扩展精度 s(1)exp(15)frac(63)
// f = (-1)^s*M*2^E   启动s为符号位,决定正负,M通常是一个值在[1.0, 2.0]的小数,E是次方数
void testFloat()
{
    cout << "---------------testFloat---------------" << endl;
    float f = 0.03126 + 0.03127;
    cout << f << endl;
}

// bitXor(x,y)	只用 & 和 ~ 实现 x^y
int bitXor(int x, int y)
{
    return (~x & y) + (x & ~y);
}

void dataLab()
{
    cout << "---------------dataLab---------------" << endl;
    cout << (0xFFFFFFF1 ^ 0xFFFFFFF2) << endl;
    cout << bitXor(0xFFFFFFF1, 0xFFFFFFF2) << endl;
    cout << (56 ^ 78) << endl;
    cout << bitXor(56, 78) << endl;
}

int main() {
    testIntegerConvert();
    testFloat();
    dataLab();
    return 0;
}
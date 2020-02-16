//
// Created by carl- on 2020/2/16.
//

#ifndef MYC_BASECONVERT_H
#define MYC_BASECONVERT_H

/**
 * 进制转换，最大支持64位无符号整数和62进制
 * @param number 要转换的数
 * @param base 进制 2~62
 * @return 字符串（SeqList）
 */
char *baseConvert(unsigned long long number, int base);

#endif //MYC_BASECONVERT_H

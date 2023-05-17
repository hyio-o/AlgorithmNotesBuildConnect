void binary_to_ascii(unsigned int value){
    unsigned int quotient ;

    quotient = value/10;
    if(quotient != 0)
        binary_to_ascii(quotient);
    putchar(value%10 + '0'); //作为char类型的输出，+'0'
}


//
// Created by 陈至宇 on 2023/4/11.
//

#ifndef ALGORITHMNOTESBUILDING_1_1_递归追踪_H
#define ALGORITHMNOTESBUILDING_1_1_递归追踪_H

#endif //ALGORITHMNOTESBUILDING_1_1_递归追踪_H

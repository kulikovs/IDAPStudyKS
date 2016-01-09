//
//  KSHuman.c
//  KSIdapStudy
//
//  Created by KulikovS on 08.01.16.
//  Copyright © 2016 KulikovS. All rights reserved.
//
#include <stdbool.h>
#include <stdlib.h>
#include "KSHuman.h"

struct KSHuman {
    KSHuman *_children[20]; //как работает, пока непонятно
    uint8_t _age;
    bool sexMale;
    char *_name; //как я понимаю, указатель тут нужен для того, чтобы динамически определялся размер строки и была возможность эту строку корректно вернуть.
    bool _married;
};

#pragma mark -
#pragma mark Initializations and Deallocations

KSHuman *KSHumanCreate(void) {  //указатель на функцию - это треш. как работает, зачем - непонятно. Увидел в видео OOP in C - Introduction. Почитал в интернете,                 сломался мозг.
    KSHuman *human = calloc(1, sizeof(KSHuman)); //KSHuman *human - создаем указатель на зарезерв-е calloc место в памяти для этой структуры
    
    return human;  //тут возвращается указатель на структуру или структура? вроде как структура, но у нас же обозначен  "KSHuman *human" указатель
}

void KSHumanDeallocate(KSHuman *human) { //принимаем указатель на созданную структуру human
    free(human); //чистим память
}

#pragma mark -
#pragma mark Accessors

void KSHumanSetAge(KSHuman *human, uint8_t age) {  //приняли указатель на структуру human, приняли uint8, заложили его в строку age созданной структуры  - вроде понятно.
    human->_age = age;
}

uint8_t KSHumanGetAge(KSHuman *human) {
    return human->_age;
}

void KSHumanSetName(KSHuman *human, char name) { //вот, тут иначе... получили указатель на структуру и имя, и оно записывается в указатель. Поэтому тут  (human->_name = &name) перед _name ставлю апперсанд адреса к строке - &. в итоге не могу понять записывается ли значение и вывести его в консоль с printf тоже не получается.
    human->_name = &name;
}
char KSHumanGetName(KSHuman *human) {
    return (char)human->_name;
}

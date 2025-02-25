#ifndef __DATABASE_H__
#define __DATABASE_H__

/* 링크드리스트는 메모리(RAM)상에서만 유지되는 자료구조이기 때문에,
    - 프로그램의 종료 직전 데이터를 파일(DB)로 영구저장
    - 프로그램이 시작 되며 파일(DB)로부터 데이터 읽어옴
*/

#include "linked_list.h"

void save_data(List *list, const char* filename);
void load_data(List *list, const char* filename);

#endif//__DATABASE_H__
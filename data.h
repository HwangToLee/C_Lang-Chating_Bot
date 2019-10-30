#ifndef __DATA_H__
#define __DATA_H__

#include <stdio.h>
#include <Windows.h>									//malloc 등 포함
#include <string.h>										//strcmp 등 포함
#include <stdbool.h>									//bool 등 포함

#define size 200

void input_data(char *buffer, char *name);				//데이터 입력
char* search_data_kw(char *input);						//kw모드 데이터 찾기
char* search_data_chat(char *input);					//채팅모드 데이터 찾기
void print_data(char *output);							//데이터(대답) 프린트
void teach_data(char *input);							//가르치기
void next_line(FILE *fp, int line);						//line만큼 다음 줄로 이동
void log_save(char* input, char* output, char *name);	//log.txt에 저장

#endif
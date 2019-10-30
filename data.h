#ifndef __DATA_H__
#define __DATA_H__

#include <stdio.h>
#include <Windows.h>									//malloc �� ����
#include <string.h>										//strcmp �� ����
#include <stdbool.h>									//bool �� ����

#define size 200

void input_data(char *buffer, char *name);				//������ �Է�
char* search_data_kw(char *input);						//kw��� ������ ã��
char* search_data_chat(char *input);					//ä�ø�� ������ ã��
void print_data(char *output);							//������(���) ����Ʈ
void teach_data(char *input);							//����ġ��
void next_line(FILE *fp, int line);						//line��ŭ ���� �ٷ� �̵�
void log_save(char* input, char* output, char *name);	//log.txt�� ����

#endif
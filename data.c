#include "data.h"

void input_data(char *buffer, char *name) {
	fflush(stdin);												//stdin 초기화
	while (1) {
		printf("%s : ", name);
		fgets(buffer, size, stdin);								//엔터 빼고 문자열 입력 받기
		buffer[strlen(buffer) - 1] = '\0';						//엔터 빼고 문자열 입력 받기
		printf("\n");

		if (strcmp(buffer, ""))									//만약 무언가라도 입력 받았으면 무한반복 끝내기
			break;
		
	}
}

char* search_data_kw(char *input) {
	FILE *fp;
	bool check = false;
	int lines;
	char *buffer = (char *)malloc(sizeof(char)*size);

	if ((fp = fopen("data_kw.txt", "r")) == NULL) return "";	//data_kw.txt파일 못열 때(오류) 대비해서 넣은 코드

	while (!feof(fp)) {
		fscanf(fp, "%d", &lines);								//data_kw.txt는 질문 앞에 숫자가 있음 (3이면 3줄짜리 데이터 출력)
		fgets(buffer, size, fp);
		buffer[strlen(buffer) - 1] = '\0';

		if (strcmp(input, buffer) == 0)							//입력받은 input값과 일치하는 것을 찾으면
			check = true;										//check를 true로 바꿈
		
		if (check == true) {
			fscanf(fp, "%[^_end_]", buffer);					//_end_ 나올때까지 스캔
			fclose(fp);
			return buffer;										//반환
		}
		next_line(fp, lines + 1);								//lines 만큼 넘겨서 질문만 보도록 (답변 안보고)
	}
	fclose(fp);
	return "";													//일치하는 것 없을시 ""반환
}

char* search_data_chat(char *input) {
	FILE *fp;
	bool check = false;
	int i;
	char *buffer = (char *)malloc(sizeof(char)*size);

	if ((fp = fopen("data_chat.txt", "r")) == NULL) return "";	//data_chat.txt파일 못열 때(오류) 대비해서 넣은 코드

	for (i = 0; i < 2; i++) {
		while (!feof(fp)) {
			fgets(buffer, size, fp);
			buffer[strlen(buffer) - 1] = '\0';

			if (i == 0 && strcmp(input, buffer) == 0)			//i = 0 (첫 번째 바퀴) 일 때는 완전히 일치하는 것만 찾음
				check = true;

			if (i == 1 && strlen(buffer) > 3 && strstr(input, buffer) != NULL) {	//i = 1 (두 번째 바퀴) 일 때는 완전히 일치하지 않아도 비슷한게 있다면 찾음
				check = true;
				printf("(추측)\n");								//추측성이라는 것을 명시
			}

			if (check == true) {
				fgets(buffer, size, fp);
				fclose(fp);
				return buffer;
			}
			next_line(fp, 2);
		}
		rewind(fp);												//첫 번째 바퀴에서 두 번째 바퀴로 갈 때 다시 파일 맨 앞부터 읽도록 해줌
	}
	fclose(fp);
	return "";
}

void print_data(char *output) {
	printf("Bot : \n\n");
	printf("%s", output);
	printf("\n-----------------------------\n");
}

void teach_data(char *input) {
	FILE *fp;
	char buffer[size];
	printf("Bot : \n\n제가 모르는 말입니다. 대답을 가르쳐 주세요 (/거절 입력시 거절)\n\n");
	input_data(buffer, "가르치기");
	printf("\n-----------------------------\n");
	if (strcmp(buffer, "/거절") == 0)
		return;
	fp = fopen("data_chat.txt", "a");
	fprintf(fp, "%s\n", input);
	fprintf(fp, "%s\n\n", buffer);
	
	fclose(fp);
}

void next_line(FILE *fp, int line) {
	int i;
	for (i = 0; i < line; i++) {
		while (!feof(fp)){
			if (fgetc(fp) == '\n')
				break;
		}
	}
}

void log_save(char* input, char* output, char *name) {
	FILE *fp;
	fp = fopen("log.txt", "a");
	fprintf(fp, "%s : %s \nBOT : %s\n", name, input, output);
	fclose(fp);
}
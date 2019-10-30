#include "data.h"

int main() {
	int mode;
	char *buffer = (char *)malloc(sizeof(char) * size), *input, *output, *kw;
	char name[20];
	while (1) {

		printf("모드를 선택하세요\n1. kw정보 모드\n2. 채팅봇 모드\n입력(1 또는 2) : ");			//모드 선택
		scanf("%d%*c", &mode);

		if (mode == 1) {
			printf("Bot : \n\nkw정보 모드입니다. \"종료\"입력시 종료됩니다.\n\n");
			strcpy(name, "User");																//kw정보 모드에서는 유저 이름을 User로 고정
			kw = (char *)malloc(sizeof(char) * (strlen(buffer) + 1));
			strcpy(kw, "광운대학교 정보 모드입니다.\n-학교시설 이용시간\n-장학금\n-몰라일단\n\n");	//문자열 kw에 기본적으로 출력할 것 저장
			print_data(kw);																		//kw 출력

			while (1) {
				input_data(buffer, name);
				input = (char *)malloc(sizeof(char) * (strlen(buffer) + 1));					//동적할당
				strcpy(input, buffer);

				if (strcmp("종료", input) == 0) {												//종료 입력받을 시 종료
					printf("사용을 종료합니다.\n");
					break;
				}
		
				strcpy(buffer, search_data_kw(input));											//입력받은 값을 data_kw.txt파일에서 검색
				output = (char *)malloc(sizeof(char) * (strlen(buffer) + 1));
				strcpy(output, buffer);															//output에 저장

				if (strcmp(output, "") == 0) {
					printf("Bot : \n\n잘못된 입력입니다. 처음으로 돌아갑니다.\n\n");				//일치하지 않는 값 입력받을 시 kw 출력
					print_data(kw);
				}
				else {
					log_save(input, output, name);												//제대로 흘러갔다면 log.txt파일에 저장
					print_data(output);															//답 출력
				}

				free(input);
				free(output);
			}
			return 0;
		}
		else if (mode == 2) {
			printf("Bot : \n\n채팅봇 모드입니다. \"종료\"입력시 종료됩니다.\n\n");

			input_data(name, "이름을 입력하세요");												//유저 이름 입력

			while (1) {
				input_data(buffer, name);
				input = (char *)malloc(sizeof(char) * (strlen(buffer) + 1));
				strcpy(input, buffer);

				if (strcmp("종료", input) == 0) {
					printf("사용을 종료합니다.\n");
					break;
				}

				strcpy(buffer, search_data_chat(input));
				output = (char *)malloc(sizeof(char) * (strlen(buffer) + 1));
				strcpy(output, buffer);

				if (strcmp(output, "") == 0)
					teach_data(input);
				else {
					log_save(input, output, name);
					print_data(output);
				}

				free(input);
				free(output);
			}
			return 0;
		}
		printf("모드 선택 오류\n");
	}
}

#include "data.h"

void input_data(char *buffer, char *name) {
	fflush(stdin);												//stdin �ʱ�ȭ
	while (1) {
		printf("%s : ", name);
		fgets(buffer, size, stdin);								//���� ���� ���ڿ� �Է� �ޱ�
		buffer[strlen(buffer) - 1] = '\0';						//���� ���� ���ڿ� �Է� �ޱ�
		printf("\n");

		if (strcmp(buffer, ""))									//���� ���𰡶� �Է� �޾����� ���ѹݺ� ������
			break;
		
	}
}

char* search_data_kw(char *input) {
	FILE *fp;
	bool check = false;
	int lines;
	char *buffer = (char *)malloc(sizeof(char)*size);

	if ((fp = fopen("data_kw.txt", "r")) == NULL) return "";	//data_kw.txt���� ���� ��(����) ����ؼ� ���� �ڵ�

	while (!feof(fp)) {
		fscanf(fp, "%d", &lines);								//data_kw.txt�� ���� �տ� ���ڰ� ���� (3�̸� 3��¥�� ������ ���)
		fgets(buffer, size, fp);
		buffer[strlen(buffer) - 1] = '\0';

		if (strcmp(input, buffer) == 0)							//�Է¹��� input���� ��ġ�ϴ� ���� ã����
			check = true;										//check�� true�� �ٲ�
		
		if (check == true) {
			fscanf(fp, "%[^_end_]", buffer);					//_end_ ���ö����� ��ĵ
			fclose(fp);
			return buffer;										//��ȯ
		}
		next_line(fp, lines + 1);								//lines ��ŭ �Ѱܼ� ������ ������ (�亯 �Ⱥ���)
	}
	fclose(fp);
	return "";													//��ġ�ϴ� �� ������ ""��ȯ
}

char* search_data_chat(char *input) {
	FILE *fp;
	bool check = false;
	int i;
	char *buffer = (char *)malloc(sizeof(char)*size);

	if ((fp = fopen("data_chat.txt", "r")) == NULL) return "";	//data_chat.txt���� ���� ��(����) ����ؼ� ���� �ڵ�

	for (i = 0; i < 2; i++) {
		while (!feof(fp)) {
			fgets(buffer, size, fp);
			buffer[strlen(buffer) - 1] = '\0';

			if (i == 0 && strcmp(input, buffer) == 0)			//i = 0 (ù ��° ����) �� ���� ������ ��ġ�ϴ� �͸� ã��
				check = true;

			if (i == 1 && strlen(buffer) > 3 && strstr(input, buffer) != NULL) {	//i = 1 (�� ��° ����) �� ���� ������ ��ġ���� �ʾƵ� ����Ѱ� �ִٸ� ã��
				check = true;
				printf("(����)\n");								//�������̶�� ���� ���
			}

			if (check == true) {
				fgets(buffer, size, fp);
				fclose(fp);
				return buffer;
			}
			next_line(fp, 2);
		}
		rewind(fp);												//ù ��° �������� �� ��° ������ �� �� �ٽ� ���� �� �պ��� �е��� ����
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
	printf("Bot : \n\n���� �𸣴� ���Դϴ�. ����� ������ �ּ��� (/���� �Է½� ����)\n\n");
	input_data(buffer, "����ġ��");
	printf("\n-----------------------------\n");
	if (strcmp(buffer, "/����") == 0)
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
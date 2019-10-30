#include "data.h"

int main() {
	int mode;
	char *buffer = (char *)malloc(sizeof(char) * size), *input, *output, *kw;
	char name[20];
	while (1) {

		printf("��带 �����ϼ���\n1. kw���� ���\n2. ä�ú� ���\n�Է�(1 �Ǵ� 2) : ");			//��� ����
		scanf("%d%*c", &mode);

		if (mode == 1) {
			printf("Bot : \n\nkw���� ����Դϴ�. \"����\"�Է½� ����˴ϴ�.\n\n");
			strcpy(name, "User");																//kw���� ��忡���� ���� �̸��� User�� ����
			kw = (char *)malloc(sizeof(char) * (strlen(buffer) + 1));
			strcpy(kw, "������б� ���� ����Դϴ�.\n-�б��ü� �̿�ð�\n-���б�\n-�����ϴ�\n\n");	//���ڿ� kw�� �⺻������ ����� �� ����
			print_data(kw);																		//kw ���

			while (1) {
				input_data(buffer, name);
				input = (char *)malloc(sizeof(char) * (strlen(buffer) + 1));					//�����Ҵ�
				strcpy(input, buffer);

				if (strcmp("����", input) == 0) {												//���� �Է¹��� �� ����
					printf("����� �����մϴ�.\n");
					break;
				}
		
				strcpy(buffer, search_data_kw(input));											//�Է¹��� ���� data_kw.txt���Ͽ��� �˻�
				output = (char *)malloc(sizeof(char) * (strlen(buffer) + 1));
				strcpy(output, buffer);															//output�� ����

				if (strcmp(output, "") == 0) {
					printf("Bot : \n\n�߸��� �Է��Դϴ�. ó������ ���ư��ϴ�.\n\n");				//��ġ���� �ʴ� �� �Է¹��� �� kw ���
					print_data(kw);
				}
				else {
					log_save(input, output, name);												//����� �귯���ٸ� log.txt���Ͽ� ����
					print_data(output);															//�� ���
				}

				free(input);
				free(output);
			}
			return 0;
		}
		else if (mode == 2) {
			printf("Bot : \n\nä�ú� ����Դϴ�. \"����\"�Է½� ����˴ϴ�.\n\n");

			input_data(name, "�̸��� �Է��ϼ���");												//���� �̸� �Է�

			while (1) {
				input_data(buffer, name);
				input = (char *)malloc(sizeof(char) * (strlen(buffer) + 1));
				strcpy(input, buffer);

				if (strcmp("����", input) == 0) {
					printf("����� �����մϴ�.\n");
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
		printf("��� ���� ����\n");
	}
}

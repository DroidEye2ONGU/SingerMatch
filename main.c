#include <stdio.h>
#include <stdlib.h>


#define MAXSINGER 100
typedef struct Singer Singer;
struct Singer {
    int status;
    int gradeStatus;
    int ID;
    char name[20];
    float grade[5];
    float averGrade;
    float totalGrade;
} singer[MAXSINGER];

void InsertSingerInfo(void);//¼�������Ϣ
void GiveGrades(void);//��ί���
void RankGrades(void);//�ɼ�����
void FindSinger(void);//���ݲ�ѯ
void AddSinger(void);//��Ӹ���
void SaveFile(void);//д���ļ�
int GetFile(void);//ȡ���ļ�
int GetSingerNum(void);//��õ�ǰ¼��ĸ�������
void ExitSystem(void);//�˳�ϵͳ
void WelcomeMenu(void);//��ӭϵͳ
int MainMenu(void);//���˵�
void SetBackground(void);//���ñ���ɫ
void ClearSc(void);//����
void GetIntoSection(int i);//�������
void Start(void);//��ʼ����


int main() {
    Start();
    return 0;
}

void Start(void) {
    WelcomeMenu();
    system("pause");

    int num = MainMenu();
    printf("%d", num);
    GetIntoSection(num);
}

void SetBackground(void) {
    system("color 1F");
}

void ClearSc(void) {
    system("cls");
}

void WelcomeMenu(void) {
    ClearSc();
    SetBackground();
    printf("\n\n\n");


    printf("*********************************************************\n");
    printf("*********************��ӭʹ�ø��ֱ���ϵͳ****************\n");
    printf("*********************************************************\n");
    printf("*********************************************************\n");
    printf("*********************************************************\n");
    printf("*********************************************************\n");
    printf("*********************************************************\n");
    printf("*********************�����������˵�********************\n");
    printf("*********************************************************\n");


}

int MainMenu(void) {
    ClearSc();
    SetBackground();
    int num = 0;
    printf("***�˵�***\n\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>  1  �����������  \n\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>  2  ��ί���  \n\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>  3  �ɼ����򣨰�ƽ���֣�  \n\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>  4  ���ݲ�ѯ  \n\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>  5  ׷�Ӹ�������  \n\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>  6  д�������ļ�  \n\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>  7  �˳�ϵͳ  \n\n");
    printf("˵����*���״�ʹ�� ��δ�������� ������������ \n");
    scanf("%d", &num);
    return num;
}

void GetIntoSection(int i) {
    int a = i;
    switch (a) {
        case 1:
            InsertSingerInfo();
            break;
        case 2:
            GiveGrades();
            break;
        case 3:
            RankGrades();
            break;
        case 4:
            FindSinger();
            break;
        case 5:
            AddSinger();
            break;
        case 6:
            SaveFile();
            break;
        case 7:
            ExitSystem();
            break;
        default:
            printf("\n!!����ָ����󣡣����������룡");
            system("pause");
            Start();
            break;

    }
}

void InsertSingerInfo(void) {
    ClearSc();
    printf("****************************¼�������Ϣ****************************\n");
    int i = 0;
    int singerNumber = 0;
    while (i == 0) {
        printf("������Ҫ¼��ĸ���������������100�ˣ����س�ȷ�ϣ�");
        scanf("%d", &singerNumber);
        if (singerNumber <= 0 || singerNumber >= 101) {
            printf("\n�޷�¼��ָ������������������,�����������������\n");
            system("pause");
            ClearSc();
        } else {
            i = 1;
        }
    }

    for (i = 0; i < singerNumber; i++) {
        singer[i].status = 1;
        singer[i].gradeStatus = 0;
        printf("\n**��ʼ¼���%d��������Ϣ��\n", i + 1);
        printf("������ѡ�ֱ�ţ�");
        scanf("%d", &singer[i].ID);
        printf("������ѡ������:");
        scanf("%s", singer[i].name);

        if (i == singerNumber - 1) {
            printf("\nȫ������¼����ϣ����������ص�������\n");
            system("pause");
            Start();
        }
        printf("\n��%d��ѡ����Ϣ¼����ϣ���ʣ%d��ѡ����Ҫ��Ҫ¼��\n", i + 1, singerNumber - i - 1);
    }


}//¼�������Ϣ


void GiveGrades(void) {

    ClearSc();
    printf("****************************��ί���****************************");
    int number = GetSingerNum();
    int minStatus = 0, maxStatus = 0;
    int noGradedPosition = 0;
    float max = 0, min = 100, sum = 0.0;

    if (number == 0) {
        printf("\nû�и�����Ϣ¼�룬��������󷵻�\n");
        system("pause");
        Start();
        return;
    }

    for (int k = 0; k < number; ++k) {
        if (singer[k].gradeStatus == 1) {
            noGradedPosition++;
        }

    }

    printf("\n***����%dλѡ����Ҫ����***", number - noGradedPosition);

    for (int i = noGradedPosition; i < number; ++i) {
        printf("\n*��ʼ��%dλ���ֵ����֣�", i + 1);
        for (int j = 0; j < 5; ++j) {
            printf("\n��%dλ��ί���֣�", j + 1);
            scanf("%f", &singer[i].grade[j]);
            singer[i].totalGrade += singer[i].grade[j];
            if (max < singer[i].grade[j])
                max = singer[i].grade[j];
            if (min > singer[i].grade[j])
                min = singer[i].grade[j];
        }
        sum = singer[i].totalGrade;
        singer[i].gradeStatus = 1;


        for (int j = 0; j < 5; j++) {
            if (singer[i].grade[j] == max) {

                if (maxStatus) {
                    continue;
                } else {
                    sum -= singer[i].grade[j];
                    maxStatus = 1;
                }

            }
            if (singer[i].grade[j] == min) {
                if (minStatus) {
                    continue;
                } else {
                    sum -= singer[i].grade[j];
                    minStatus = 1;
                }
            }
        }


        singer[i].averGrade = sum / 3;
    }

    printf("\n\n\n������ϣ������������");
    system("pause");
    Start();

}//��ί���


void RankGrades(void) {

    ClearSc();
    printf("****************************��������****************************");
    Singer tempSinger;
    int num = GetSingerNum();

    if (num == 0) {
        printf("\nû�и�����Ϣ¼�룬��������󷵻�\n");
        system("pause");
        Start();
        return;
    }

    for (int i = 0; i < num - 1; ++i) {
        for (int j = i + 1; j < num; ++j) {
            if (singer[i].averGrade < singer[j].averGrade) {
                tempSinger = singer[j];
                singer[j] = singer[i];
                singer[i] = tempSinger;
            }
        }
    }

    printf("\n\n");
    printf("�������     ������     �����ܷ�     ����ƽ���֣�ȥ����߷ֺ���ͷ֣�");
    for (int i = 0; i < num; ++i) {
        printf("\n   %d         %s      %3.2f        %3.2f", singer[i].ID, singer[i].name, singer[i].totalGrade,
               singer[i].averGrade);
    }
    printf("\n\n����������������Ϣ���ϡ�����\n\n\n");
    system("pause");
    Start();

}//�ɼ�����
void FindSinger(void) {

    ClearSc();
    printf("****************************���ֲ�ѯ****************************");

    int a;
    int num = GetSingerNum();
    int id = 0, t = 0, i;
    struct Singer tempSinger;
    printf("\n\n������Ҫ��ѯ���ֵ���ţ�");
    scanf("%d", &id);

    for (i = 0; i < num; ++i) {
        if (singer[i].ID == id) {
            tempSinger = singer[i];
            printf("\n�ҵ�IDΪ%d�ĸ��֣���Ϣ���¡�����������\n", id);
            printf("�������     ������     �����ܷ�     ����ƽ���֣�ȥ����߷ֺ���ͷ֣�");
            printf("\n   %d         %s      %3.2f        %3.2f", tempSinger.ID, tempSinger.name, tempSinger.totalGrade,
                   tempSinger.averGrade);
            break;
        }
    }
    if (i == num) {
        printf("\n�Բ���û���ҵ���Ӧ��ŵĸ��֣�");
    }

    printf("\n���������밴1�������밴2��");
    scanf("%d", &a);
    switch (a) {
        case 1:
            FindSinger();
            break;
        case 2:
            Start();
            break;
        default:
            break;
    }

}//���ݲ�ѯ


void AddSinger(void) {

    ClearSc();
    printf("****************************���Ӹ�����Ϣ****************************\n");
    int i = 0;
    int singerNumber = 0, singerSum = GetSingerNum();

    if (singerSum == 0) {
        printf("\nĿǰû�и�����Ϣ���棬��ֱ��ȥ��Ӹ���ѡ��¼�������Ϣ����������󷵻ز˵�");
        system("pause");
        Start();
        return;
    }
    while (i == 0) {
        printf("������Ҫ���ӵĸ���������������100�ˣ����س�ȷ�ϣ�");
        scanf("%d", &singerNumber);
        if (singerNumber + singerSum > 100) {
            printf("\n�޷�¼��ָ������������������,�����������������\n");
            system("pause");
            ClearSc();
        } else {
            i = 1;
        }
    }

    for (i = singerSum; i < singerNumber + singerSum; i++) {
        singer[i].status = 1;
        printf("\n**��ʼ¼���%d��������Ϣ��\n", i + 1);
        printf("������ѡ�ֱ�ţ�");
        scanf("%d", &singer[i].ID);
        printf("������ѡ������:");
        scanf("%s", singer[i].name);

        if (i == singerNumber + singerSum - 1) {
            printf("\nȫ������¼����ϣ��뼰ʱΪ��¼���������\n����������ز˵�\n");
            system("pause");
            Start();
            return;
        }
        printf("\n��%d��ѡ����Ϣ¼����ϣ���ʣ%d��ѡ����Ҫ��Ҫ¼��\n", i + 1, singerNumber - i - 1);
    }


}//��Ӹ���


int GetSingerNum(void) {
    int sum = 0, i;
    int sum2 = 0;
    sum2 = GetFile();

    for (i = 0; i < MAXSINGER; ++i) {
        if (singer[i].status == 1) {
            sum++;
        } else {
            break;
        }
    }

    if (sum2 >= sum) {
        return sum2;
    } else {
        return sum;
    }

}

void SaveFile(void) {
    ClearSc();
    printf("****************************���������Ϣ���ļ�****************************");

    int sum, i;
    FILE *fp;
    sum = GetSingerNum();

    if (sum == 0) {
        printf("\nû�и�����Ϣ���棡,��������󷵻ز˵�\n");
        system("pause");
        Start();
    }

    if ((fp = fopen("D://c++/SingerInfo", "wb")) == NULL) {
        printf("\n���ļ�ʧ�ܣ�\n");
        system("pause");
        Start();
    }

    for (i = 0; i < sum; ++i) {
        if (fwrite(&singer[i], sizeof(struct Singer), 1, fp) != 1) {
            printf("\n�ļ�д�����\n");
            system("pause");
            Start();
        }
    }
    fclose(fp);
    printf("\n\n�洢�ɹ�������������ز˵�\n");
    system("pause");
    Start();

}//д���ļ�

int GetFile(void) {
    int sum = 0;
    FILE *fp;

    if ((fp = fopen("D://c++/SingerInfo", "rb")) == NULL) {
        // printf("���ļ�ʧ�ܣ�\n");
        return 0;
    } else {
        do {

            fread(&singer[sum], sizeof(struct Singer), 1, fp);
            sum++;
        } while (feof(fp) == 0);
    }

    fclose(fp);

    return sum - 1;
}//ȡ�ô洢�ļ�


void ExitSystem(void) {

    int a;
    printf("ȷ���˳��밴1�������밴2");
    scanf("%d", &a);
    switch (a) {
        case 1:
            exit(0);
        case 2:
            Start();
            return;
        default:
            break;
    }

}//�˳�ϵͳ

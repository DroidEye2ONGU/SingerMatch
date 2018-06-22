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

void InsertSingerInfo(void);//录入歌手信息
void GiveGrades(void);//评委打分
void RankGrades(void);//成绩排序
void FindSinger(void);//数据查询
void AddSinger(void);//添加歌手
void SaveFile(void);//写入文件
int GetFile(void);//取得文件
int GetSingerNum(void);//获得当前录入的歌手人数
void ExitSystem(void);//退出系统
void WelcomeMenu(void);//欢迎系统
int MainMenu(void);//主菜单
void SetBackground(void);//设置背景色
void ClearSc(void);//清屏
void GetIntoSection(int i);//进入分项
void Start(void);//开始函数


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
    printf("*********************欢迎使用歌手比赛系统****************\n");
    printf("*********************************************************\n");
    printf("*********************************************************\n");
    printf("*********************************************************\n");
    printf("*********************************************************\n");
    printf("*********************************************************\n");
    printf("*********************按任意键进入菜单********************\n");
    printf("*********************************************************\n");


}

int MainMenu(void) {
    ClearSc();
    SetBackground();
    int num = 0;
    printf("***菜单***\n\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>  1  输入歌手数据  \n\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>  2  评委打分  \n\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>  3  成绩排序（按平均分）  \n\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>  4  数据查询  \n\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>  5  追加歌手数据  \n\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>  6  写入数据文件  \n\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>  7  退出系统  \n\n");
    printf("说明：*如首次使用 尚未输入数据 请先输入数据 \n");
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
            printf("\n!!输入指令错误！，请重新输入！");
            system("pause");
            Start();
            break;

    }
}

void InsertSingerInfo(void) {
    ClearSc();
    printf("****************************录入歌手信息****************************\n");
    int i = 0;
    int singerNumber = 0;
    while (i == 0) {
        printf("请输入要录入的歌手人数，不超过100人，按回车确认：");
        scanf("%d", &singerNumber);
        if (singerNumber <= 0 || singerNumber >= 101) {
            printf("\n无法录入指定人数，请重新输入,按任意键后重新输入\n");
            system("pause");
            ClearSc();
        } else {
            i = 1;
        }
    }

    for (i = 0; i < singerNumber; i++) {
        singer[i].status = 1;
        singer[i].gradeStatus = 0;
        printf("\n**开始录入第%d个歌手信息：\n", i + 1);
        printf("请输入选手编号：");
        scanf("%d", &singer[i].ID);
        printf("请输入选手姓名:");
        scanf("%s", singer[i].name);

        if (i == singerNumber - 1) {
            printf("\n全部歌手录入完毕，按任意键后回到主界面\n");
            system("pause");
            Start();
        }
        printf("\n第%d个选手信息录入完毕，还剩%d个选手需要需要录入\n", i + 1, singerNumber - i - 1);
    }


}//录入歌手信息


void GiveGrades(void) {

    ClearSc();
    printf("****************************评委打分****************************");
    int number = GetSingerNum();
    int minStatus = 0, maxStatus = 0;
    int noGradedPosition = 0;
    float max = 0, min = 100, sum = 0.0;

    if (number == 0) {
        printf("\n没有歌手信息录入，按任意键后返回\n");
        system("pause");
        Start();
        return;
    }

    for (int k = 0; k < number; ++k) {
        if (singer[k].gradeStatus == 1) {
            noGradedPosition++;
        }

    }

    printf("\n***共有%d位选手需要评分***", number - noGradedPosition);

    for (int i = noGradedPosition; i < number; ++i) {
        printf("\n*开始第%d位歌手的评分：", i + 1);
        for (int j = 0; j < 5; ++j) {
            printf("\n第%d位评委评分：", j + 1);
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

    printf("\n\n\n评分完毕，按任意键返回");
    system("pause");
    Start();

}//评委打分


void RankGrades(void) {

    ClearSc();
    printf("****************************歌手排名****************************");
    Singer tempSinger;
    int num = GetSingerNum();

    if (num == 0) {
        printf("\n没有歌手信息录入，按任意键后返回\n");
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
    printf("歌手序号     歌手名     歌手总分     歌手平均分（去除最高分和最低分）");
    for (int i = 0; i < num; ++i) {
        printf("\n   %d         %s      %3.2f        %3.2f", singer[i].ID, singer[i].name, singer[i].totalGrade,
               singer[i].averGrade);
    }
    printf("\n\n↑↑↑歌手排名信息如上↑↑↑\n\n\n");
    system("pause");
    Start();

}//成绩排序
void FindSinger(void) {

    ClearSc();
    printf("****************************歌手查询****************************");

    int a;
    int num = GetSingerNum();
    int id = 0, t = 0, i;
    struct Singer tempSinger;
    printf("\n\n请输入要查询歌手的序号：");
    scanf("%d", &id);

    for (i = 0; i < num; ++i) {
        if (singer[i].ID == id) {
            tempSinger = singer[i];
            printf("\n找到ID为%d的歌手！信息如下↓↓↓↓↓↓\n", id);
            printf("歌手序号     歌手名     歌手总分     歌手平均分（去除最高分和最低分）");
            printf("\n   %d         %s      %3.2f        %3.2f", tempSinger.ID, tempSinger.name, tempSinger.totalGrade,
                   tempSinger.averGrade);
            break;
        }
    }
    if (i == num) {
        printf("\n对不起，没有找到对应编号的歌手！");
    }

    printf("\n继续查找请按1，返回请按2：");
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

}//数据查询


void AddSinger(void) {

    ClearSc();
    printf("****************************增加歌手信息****************************\n");
    int i = 0;
    int singerNumber = 0, singerSum = GetSingerNum();

    if (singerSum == 0) {
        printf("\n目前没有歌手信息储存，请直接去添加歌手选项录入歌手信息，按任意键后返回菜单");
        system("pause");
        Start();
        return;
    }
    while (i == 0) {
        printf("请输入要增加的歌手人数，不超过100人，按回车确认：");
        scanf("%d", &singerNumber);
        if (singerNumber + singerSum > 100) {
            printf("\n无法录入指定人数，请重新输入,按任意键后重新输入\n");
            system("pause");
            ClearSc();
        } else {
            i = 1;
        }
    }

    for (i = singerSum; i < singerNumber + singerSum; i++) {
        singer[i].status = 1;
        printf("\n**开始录入第%d个歌手信息：\n", i + 1);
        printf("请输入选手编号：");
        scanf("%d", &singer[i].ID);
        printf("请输入选手姓名:");
        scanf("%s", singer[i].name);

        if (i == singerNumber + singerSum - 1) {
            printf("\n全部歌手录入完毕，请及时为新录入歌手评分\n按任意键返回菜单\n");
            system("pause");
            Start();
            return;
        }
        printf("\n第%d个选手信息录入完毕，还剩%d个选手需要需要录入\n", i + 1, singerNumber - i - 1);
    }


}//添加歌手


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
    printf("****************************保存歌手信息到文件****************************");

    int sum, i;
    FILE *fp;
    sum = GetSingerNum();

    if (sum == 0) {
        printf("\n没有歌手信息保存！,按任意键后返回菜单\n");
        system("pause");
        Start();
    }

    if ((fp = fopen("D://c++/SingerInfo", "wb")) == NULL) {
        printf("\n打开文件失败！\n");
        system("pause");
        Start();
    }

    for (i = 0; i < sum; ++i) {
        if (fwrite(&singer[i], sizeof(struct Singer), 1, fp) != 1) {
            printf("\n文件写入错误！\n");
            system("pause");
            Start();
        }
    }
    fclose(fp);
    printf("\n\n存储成功！按任意键返回菜单\n");
    system("pause");
    Start();

}//写入文件

int GetFile(void) {
    int sum = 0;
    FILE *fp;

    if ((fp = fopen("D://c++/SingerInfo", "rb")) == NULL) {
        // printf("打开文件失败！\n");
        return 0;
    } else {
        do {

            fread(&singer[sum], sizeof(struct Singer), 1, fp);
            sum++;
        } while (feof(fp) == 0);
    }

    fclose(fp);

    return sum - 1;
}//取得存储文件


void ExitSystem(void) {

    int a;
    printf("确认退出请按1，返回请按2");
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

}//退出系统

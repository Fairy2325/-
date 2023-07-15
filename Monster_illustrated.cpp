#include"Monster_illustrated.h"
#include"Monster_kind.h"

//构造函数
Monster_illustrated::Monster_illustrated()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);//读文件

    //如果文件不存在,初始化属性
    if (!ifs.is_open())
    {
        cout << "本地文件不存在" << endl;
        //初始化属性
        this->FileIsEmpty = true;
        this->kind_num = 0;
        this->array = NULL;
        ifs.close();
        return;
    }

    //如果文件存在，数据为空
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        //文件为空
        this->FileIsEmpty = true;
        this->kind_num = 0;
        this->array = NULL;
        ifs.close();
        return;
    }

    //文件存在，数据不为空
    int num = this->get_kindnum();
    //cout << "怪物种类共有" << num << endl;
    this->kind_num = num;
    this->FileIsEmpty = false;
    this->array = new Monster_kind * [this->kind_num];
    this->init();
}

//初始化
void Monster_illustrated::init()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int blood;
    double speed;
    int coin;
    int score;

    int index = 0;

    while (ifs >> id && ifs >> name && ifs >> blood && ifs >> speed && ifs >> coin && ifs >> score)
    {

        Monster_kind* monster = new Monster_kind(id, name, blood, speed, coin, score);

        this->array[index++] = monster;

    }

    ifs.close();

}

//添加怪物
void Monster_illustrated::Add()
{
    cout << "请输入添加怪物数量：" << endl;
    int addNum = 0;//保存用户输入数量
    cin >> addNum;

    if (addNum > 0)
    {
        //计算添加新空间大小
        int newSize = this->kind_num + addNum;

        //开辟新空间
        Monster_kind** newSpace = new Monster_kind * [newSize];

        //将原来空间下数据拷贝到新空间下
        if (this->array != NULL)
        {
            for (int i = 0; i < this->kind_num; i++)
            {
                newSpace[i] = this->array[i];
            }
        }

        //添加新数据
        for (int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int blood;
            double speed;
            int coin;
            int score;

            cout << "请输入第" << i + 1 << "个怪物信息：" << endl;

            cin >> id;
            cin >> name;
            cin >> blood;
            cin >> speed;
            cin >> coin;
            cin >> score;

            Monster_kind* monster = new Monster_kind(id, name, blood, speed, coin, score);

            //将创建的职工指针保存到数组中
            newSpace[this->kind_num + i] = monster;
        }
        //释放原有空间
        delete[] this->array;

        //更改新空间的指向
        this->array = newSpace;

        //更新职工人数
        this->kind_num = newSize;

        //更新职工不为空的标志
        this->FileIsEmpty = false;

        //提示添加成功
        cout << "添加成功" << endl;

        //保存数据到文件中
        this->save();
    }
    else
    {
        cout << "输入有误";
    }

    system("pause");
    system("cls");
}

//统计文件中怪物数量
int Monster_illustrated::get_kindnum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);//打开文件 读

    int id;
    string name;
    int blood;
    double speed;
    int coin;
    int score;

    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> blood && ifs >> speed && ifs >> coin && ifs >> score)
    {
        num++;
    }

    return num;
}

//保存文件
void Monster_illustrated::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);


    //将每个人的数据写入文件中
    for (int i = 0; i < this->kind_num; i++)
    {
        ofs << this->array[i]->m_id << " "
            << this->array[i]->m_name << " "
            << this->array[i]->m_blood << " "
            << this->array[i]->m_speed << " "
            << this->array[i]->m_coin << " "
            << this->array[i]->m_score << endl;

    }
    ofs.close();
}

//展示菜单
void Monster_illustrated::Show_Menu()
{
    cout << "******************************" << endl;
    cout << "*******欢迎使用怪物图鉴********" << endl;
    cout << "********0.退出怪物图鉴********" << endl;
    cout << "********1.增加怪物信息********" << endl;
    cout << "********2.删除怪物信息********" << endl;
    cout << "********3.修改怪物信息********" << endl;
    cout << "********4.清空所有文档********" << endl;
    cout << "******************************" << endl;
    cout << endl;
}

//退出系统
void Monster_illustrated::ExitSystem()
{
    cout << "正在关闭怪物图鉴" << endl;
    system("pause");
    exit(0);
}

//删除怪物
void Monster_illustrated::Delete()
{
    if (this->FileIsEmpty)
    {
        cout << "没有任何怪物被收录！" << endl;
    }
    else
    {
        //按照怪物编编号删除
        cout << "请输入想要删除的怪物编号:" << endl;
        int id = 0;
        cin >> id;

        int index = this->IsExist(id);

        if (index != -1)
        {
            //数据前移
            for (int i = index; i < this->kind_num - 1; i++)
            {
                this->array[i] = this->array[i + 1];
            }

            //更新怪物种类数量
            this->kind_num--;

            //数据同步更新到文件中
            this->save();

            cout << "删除成功！" << endl;
        }
        else
        {
            cout << "删除失败，没有找到该怪物" << endl;
        }

        system("pause");
        system("cls");
    }
}

//判断怪物是否存在
int Monster_illustrated::IsExist(int id)
{
    int index = -1;

    for (int i = 0; i < this->kind_num; i++)
    {
        if (this->array[i]->m_id == id)
        {
            index = i;

            break;
        }
    }

    return index;
}

//修改怪物信息
void Monster_illustrated::Mod_Mon()
{
    if (this->FileIsEmpty)
    {
        cout << "没有任何怪物被收录！" << endl;
    }
    else
    {
        cout << "请输入修改职工的编号:" << endl;
        int id;
        cin >> id;

        int ret = this->IsExist(id);
        if (ret != -1)
        {
            //查找到编号的职工
            delete this->array[ret];

            int newid;
            string newname;
            int newblood;
            double newspeed;
            int newcoin;
            int newscore;

            cout << "查到：" << id << "号职工，请输入新的信息：" << endl;
            cin >> newid;
            cin >> newname;
            cin >> newblood;
            cin >> newspeed;
            cin >> newcoin;
            cin >> newscore;

            Monster_kind* monster = new Monster_kind(newid, newname, newblood, newspeed, newcoin, newscore);

            //更新数据到数组中
            this->array[ret] = monster;

            //保存到文件中
            this->save();

            cout << "修改成功！" << endl;
        }
        else
        {
            cout << "修改失败，没有此编号的怪物！";
        }

        system("pause");
        system("cls");
    }


}

//清空文件
void Monster_illustrated::Clean_File()
{
    cout << "确认清空？" << endl;
    cout << "1、确定" << endl;
    cout << "2、返回" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        //清空文件
        ofstream ofs(FILENAME, ios::trunc);//删除文件后重新创建
        ofs.close();

        if (this->array != NULL)
        {
            //删除堆区的每个怪物对象
            for (int i = 0; i < this->kind_num; i++)
            {
                delete this->array[i];
                this->array[i] = NULL;
            }

            //删除堆区数组指针
            delete[] this->array;
            this->array = NULL;
            this->kind_num = 0;
            this->FileIsEmpty = true;
        }

        cout << "清空成功！" << endl;
    }

    system("pause");
    system("cls");
}

//析构函数
Monster_illustrated::~Monster_illustrated()
{
    if (this->array != NULL)
    {
        for (int i = 0; i < this->kind_num; i++)
        {
            if (this->array[i] != NULL)
            {
                delete this->array[i];
            }
        }
        delete[]this->array;
        this->array = NULL;
    }
}
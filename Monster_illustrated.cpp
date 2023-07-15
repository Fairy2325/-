#include"Monster_illustrated.h"
#include"Monster_kind.h"

//���캯��
Monster_illustrated::Monster_illustrated()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);//���ļ�

    //����ļ�������,��ʼ������
    if (!ifs.is_open())
    {
        cout << "�����ļ�������" << endl;
        //��ʼ������
        this->FileIsEmpty = true;
        this->kind_num = 0;
        this->array = NULL;
        ifs.close();
        return;
    }

    //����ļ����ڣ�����Ϊ��
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        //�ļ�Ϊ��
        this->FileIsEmpty = true;
        this->kind_num = 0;
        this->array = NULL;
        ifs.close();
        return;
    }

    //�ļ����ڣ����ݲ�Ϊ��
    int num = this->get_kindnum();
    //cout << "�������๲��" << num << endl;
    this->kind_num = num;
    this->FileIsEmpty = false;
    this->array = new Monster_kind * [this->kind_num];
    this->init();
}

//��ʼ��
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

//��ӹ���
void Monster_illustrated::Add()
{
    cout << "��������ӹ���������" << endl;
    int addNum = 0;//�����û���������
    cin >> addNum;

    if (addNum > 0)
    {
        //��������¿ռ��С
        int newSize = this->kind_num + addNum;

        //�����¿ռ�
        Monster_kind** newSpace = new Monster_kind * [newSize];

        //��ԭ���ռ������ݿ������¿ռ���
        if (this->array != NULL)
        {
            for (int i = 0; i < this->kind_num; i++)
            {
                newSpace[i] = this->array[i];
            }
        }

        //���������
        for (int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int blood;
            double speed;
            int coin;
            int score;

            cout << "�������" << i + 1 << "��������Ϣ��" << endl;

            cin >> id;
            cin >> name;
            cin >> blood;
            cin >> speed;
            cin >> coin;
            cin >> score;

            Monster_kind* monster = new Monster_kind(id, name, blood, speed, coin, score);

            //��������ְ��ָ�뱣�浽������
            newSpace[this->kind_num + i] = monster;
        }
        //�ͷ�ԭ�пռ�
        delete[] this->array;

        //�����¿ռ��ָ��
        this->array = newSpace;

        //����ְ������
        this->kind_num = newSize;

        //����ְ����Ϊ�յı�־
        this->FileIsEmpty = false;

        //��ʾ��ӳɹ�
        cout << "��ӳɹ�" << endl;

        //�������ݵ��ļ���
        this->save();
    }
    else
    {
        cout << "��������";
    }

    system("pause");
    system("cls");
}

//ͳ���ļ��й�������
int Monster_illustrated::get_kindnum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);//���ļ� ��

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

//�����ļ�
void Monster_illustrated::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);


    //��ÿ���˵�����д���ļ���
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

//չʾ�˵�
void Monster_illustrated::Show_Menu()
{
    cout << "******************************" << endl;
    cout << "*******��ӭʹ�ù���ͼ��********" << endl;
    cout << "********0.�˳�����ͼ��********" << endl;
    cout << "********1.���ӹ�����Ϣ********" << endl;
    cout << "********2.ɾ��������Ϣ********" << endl;
    cout << "********3.�޸Ĺ�����Ϣ********" << endl;
    cout << "********4.��������ĵ�********" << endl;
    cout << "******************************" << endl;
    cout << endl;
}

//�˳�ϵͳ
void Monster_illustrated::ExitSystem()
{
    cout << "���ڹرչ���ͼ��" << endl;
    system("pause");
    exit(0);
}

//ɾ������
void Monster_illustrated::Delete()
{
    if (this->FileIsEmpty)
    {
        cout << "û���κι��ﱻ��¼��" << endl;
    }
    else
    {
        //���չ������ɾ��
        cout << "��������Ҫɾ���Ĺ�����:" << endl;
        int id = 0;
        cin >> id;

        int index = this->IsExist(id);

        if (index != -1)
        {
            //����ǰ��
            for (int i = index; i < this->kind_num - 1; i++)
            {
                this->array[i] = this->array[i + 1];
            }

            //���¹�����������
            this->kind_num--;

            //����ͬ�����µ��ļ���
            this->save();

            cout << "ɾ���ɹ���" << endl;
        }
        else
        {
            cout << "ɾ��ʧ�ܣ�û���ҵ��ù���" << endl;
        }

        system("pause");
        system("cls");
    }
}

//�жϹ����Ƿ����
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

//�޸Ĺ�����Ϣ
void Monster_illustrated::Mod_Mon()
{
    if (this->FileIsEmpty)
    {
        cout << "û���κι��ﱻ��¼��" << endl;
    }
    else
    {
        cout << "�������޸�ְ���ı��:" << endl;
        int id;
        cin >> id;

        int ret = this->IsExist(id);
        if (ret != -1)
        {
            //���ҵ���ŵ�ְ��
            delete this->array[ret];

            int newid;
            string newname;
            int newblood;
            double newspeed;
            int newcoin;
            int newscore;

            cout << "�鵽��" << id << "��ְ�����������µ���Ϣ��" << endl;
            cin >> newid;
            cin >> newname;
            cin >> newblood;
            cin >> newspeed;
            cin >> newcoin;
            cin >> newscore;

            Monster_kind* monster = new Monster_kind(newid, newname, newblood, newspeed, newcoin, newscore);

            //�������ݵ�������
            this->array[ret] = monster;

            //���浽�ļ���
            this->save();

            cout << "�޸ĳɹ���" << endl;
        }
        else
        {
            cout << "�޸�ʧ�ܣ�û�д˱�ŵĹ��";
        }

        system("pause");
        system("cls");
    }


}

//����ļ�
void Monster_illustrated::Clean_File()
{
    cout << "ȷ����գ�" << endl;
    cout << "1��ȷ��" << endl;
    cout << "2������" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        //����ļ�
        ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ������´���
        ofs.close();

        if (this->array != NULL)
        {
            //ɾ��������ÿ���������
            for (int i = 0; i < this->kind_num; i++)
            {
                delete this->array[i];
                this->array[i] = NULL;
            }

            //ɾ����������ָ��
            delete[] this->array;
            this->array = NULL;
            this->kind_num = 0;
            this->FileIsEmpty = true;
        }

        cout << "��ճɹ���" << endl;
    }

    system("pause");
    system("cls");
}

//��������
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
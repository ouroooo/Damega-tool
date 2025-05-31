#include <iostream>
#include <string>
#include <windows.h>
#include <chrono>
#include <thread>
#include <sstream>
#include <iomanip>
#include <map>
#include <cctype>

using namespace std;

// ��������
void clearScreen() {
    system("cls");
}

// �������
void openBrowser(const string& url) {
    ShellExecuteA(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

// URL���뺯��
string urlEncode(const string& value) {
    ostringstream escaped;
    escaped.fill('0');
    escaped << hex;

    for (char c : value) {
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
            continue;
        }
        escaped << uppercase;
        escaped << '%' << setw(2) << int((unsigned char)c);
        escaped << nouppercase;
    }

    return escaped.str();
}

// ��ȡ����
void checkUpdate() {
    string url = "https://ouroooo.github.io/damega";
    openBrowser(url);
    cout << "�Ѵ����ӣ�" << url << endl;
    this_thread::sleep_for(chrono::seconds(3));
    clearScreen();
}

// ��¼����
void loginDamega() {
    string url = "http://14.18.102.167:17001/edei/";
    openBrowser(url);
    cout << "�Ѵ����ӣ�" << url << endl;
    this_thread::sleep_for(chrono::seconds(3));
    clearScreen();
}

// ��ȡ������
void getExamNumber() {
    cout << "ÿ�黨�����ڣ�\n"
            "examNum�ǿ�����\n"
            "examName�Ƕ�Ӧ�Ŀ���\n"
            "����ϸ�Ķ���5���ִ��" << endl;
    this_thread::sleep_for(chrono::seconds(5));
    string url = "http://14.18.102.167:17001/edei/qList!getExamAndGraAndSubData.action";
    openBrowser(url);
    cout << "ok" << endl;
    this_thread::sleep_for(chrono::seconds(3));
    clearScreen();
}

// �������URL
string buildUrl(const string& baseUrl, const map<string, string>& params) {
    stringstream query;
    for (const auto& [key, value] : params) {
        query << "&" << key << "=" << urlEncode(value);
    }
    return baseUrl + query.str();
}

// ����ȫ������
void exportRegionalRank() {
    const string baseUrl = "http://14.18.102.167:17001/edei/g6!g6export.action?&schoolNum=196,199,201,185,190,192,195,198,189,184,180,183,191,182,193,188,187,204,197,200,194,181,186,331,203,206,202,205&classNum=&studentType=0&step=10&mingcistep=100&topStep=&E5step=null&B3mingcistep=null&type=0&c_exam=&rpt_name=A2-ȫ�Ƴɼ�&source=0&isHistory=F&isMoreSchool=T&rate=50&islevelclass=F&expTagType=null&reCalcu=F&fufen=0&subCompose=0&islevel=0&rptTitle=ȥ��ttkx&sch=1&subRank=-1&downRank=0&scoreName=1&shouxuanHide=0&isShowSubCompose=0";
    
    map<string, string> params;
    cout << "exam�ǿ�����\nsNum��������Χ����2000�͵�������2000������\ngradeNum���꼶����09\n";
    
    cout << "������examNum: ";
    getline(cin, params["examNum"]);
    
    cout << "������sNum: ";
    getline(cin, params["sNum"]);
    
    cout << "������gradeNum: ";
    getline(cin, params["gradeNum"]);

    string fullUrl = buildUrl(baseUrl, params);
    openBrowser(fullUrl);
    cout << "�Ѵ����������ת��: " << fullUrl << endl;
    this_thread::sleep_for(chrono::seconds(3));
    clearScreen();
}

//��ȡѧУ����
void getSchoolcode()
{
    cout << "ÿ�������ڣ�\n"
            "id��ѧУ����\n"
            "Name�Ƕ�Ӧ��ѧУ\n"
            "����ϸ�Ķ���5���ִ��" << endl;
    this_thread::sleep_for(chrono::seconds(5));
    string url = "http://14.18.102.167:17001/edei/jsp/main/stasticAction!getAllTeachUnitInfo.action?exam=35&grade=9&subCompose=0&islevel=1&subject=101&level=0&sType=";
    openBrowser(url);
    cout << "ok" << endl;
    this_thread::sleep_for(chrono::seconds(3));
    clearScreen();
}

//��ȡȫУ����
void getSchool()
{
     const string baseUrl = "http://14.18.102.167:17001/edei/g6!g6export.action?&studentType=0&step=10&mingcistep=100&topStep=&E5step=null&B3mingcistep=null&type=0&sNum=6000&c_exam=&rpt_name=A2-%E5%85%A8%E7%A7%91%E6%88%90%E7%BB%A9&source=0&isHistory=F&isMoreSchool=F&rate=50&islevelclass=F&expTagType=null&reCalcu=F&fufen=0&subCompose=0&islevel=0&rptTitle=ȥ��ttkx&sch=&subRank=-1&downRank=0&scoreName=1&shouxuanHide=0&isShowSubCompose=0";
    
    map<string, string> params;
    cout << "exam�ǿ�����\ngradeNum���꼶����09\nschoolNum��ѧУ����";
    
    cout << "������examNum: ";
    getline(cin, params["examNum"]);
    
    cout << "������gradeNum: ";
    getline(cin, params["gradeNum"]);
    
    cout << "������schoolNum: ";
    getline(cin, params["schoolNum"]);

    string fullUrl = buildUrl(baseUrl, params);
    openBrowser(fullUrl);
    cout << "�Ѵ����������ת��: " << fullUrl << endl;
    this_thread::sleep_for(chrono::seconds(3));
    clearScreen();
}
int main() {
    // ���ÿ���̨���ı���
    SetConsoleOutputCP(936);
    
    while (true) {
        cout << "��ӭʹ�ô����ι���\n"
                "������������ϵouroooo@163.com\n"
                "�ϴθ���ʱ��:2025/02/01\n"
                "���߸��µ�ַhttps://ouroooo.github.io/damega\n\n"
                "1.��¼������\n"
                "2.��ȡ������\n"
                "3.��������ȫ������\n"
                "4.��ȡѧУ����\n"
                "5.����ȫУ����\n"
                "6.�����°汾\n"
                "������ѡ�";

        string choice;
        getline(cin, choice);

        if (choice == "1") loginDamega();
        else if (choice == "2") getExamNumber();
        else if (choice == "3") exportRegionalRank();
        else if (choice == "4") getSchoolcode();
        else if (choice == "5") getSchool();
        else if (choice == "6") checkUpdate();
        else clearScreen();
    }

    return 0;
}
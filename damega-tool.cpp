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

// 清屏函数
void clearScreen() {
    system("cls");
}

// 打开浏览器
void openBrowser(const string& url) {
    ShellExecuteA(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

// URL编码函数
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

// 获取更新
void checkUpdate() {
    string url = "https://ouroooo.github.io/damega";
    openBrowser(url);
    cout << "已打开链接：" << url << endl;
    this_thread::sleep_for(chrono::seconds(3));
    clearScreen();
}

// 登录功能
void loginDamega() {
    string url = "http://14.18.102.167:17001/edei/";
    openBrowser(url);
    cout << "已打开链接：" << url << endl;
    this_thread::sleep_for(chrono::seconds(3));
    clearScreen();
}

// 获取考试码
void getExamNumber() {
    cout << "每组花括号内：\n"
            "examNum是考试码\n"
            "examName是对应的考试\n"
            "请仔细阅读，5秒后执行" << endl;
    this_thread::sleep_for(chrono::seconds(5));
    string url = "http://14.18.102.167:17001/edei/qList!getExamAndGraAndSubData.action";
    openBrowser(url);
    cout << "ok" << endl;
    this_thread::sleep_for(chrono::seconds(3));
    clearScreen();
}

// 构造参数URL
string buildUrl(const string& baseUrl, const map<string, string>& params) {
    stringstream query;
    for (const auto& [key, value] : params) {
        query << "&" << key << "=" << urlEncode(value);
    }
    return baseUrl + query.str();
}

// 导出全县排名
void exportRegionalRank() {
    const string baseUrl = "http://14.18.102.167:17001/edei/g6!g6export.action?&schoolNum=196,199,201,185,190,192,195,198,189,184,180,183,191,182,193,188,187,204,197,200,194,181,186,331,203,206,202,205&classNum=&studentType=0&step=10&mingcistep=100&topStep=&E5step=null&B3mingcistep=null&type=0&c_exam=&rpt_name=A2-全科成绩&source=0&isHistory=F&isMoreSchool=T&rate=50&islevelclass=F&expTagType=null&reCalcu=F&fufen=0&subCompose=0&islevel=0&rptTitle=去疾ttkx&sch=1&subRank=-1&downRank=0&scoreName=1&shouxuanHide=0&isShowSubCompose=0";
    
    map<string, string> params;
    cout << "exam是考试码\nsNum是排名范围，如2000就导出到第2000名左右\ngradeNum是年级，如09\n";
    
    cout << "请输入examNum: ";
    getline(cin, params["examNum"]);
    
    cout << "请输入sNum: ";
    getline(cin, params["sNum"]);
    
    cout << "请输入gradeNum: ";
    getline(cin, params["gradeNum"]);

    string fullUrl = buildUrl(baseUrl, params);
    openBrowser(fullUrl);
    cout << "已打开浏览器，跳转到: " << fullUrl << endl;
    this_thread::sleep_for(chrono::seconds(3));
    clearScreen();
}

//获取学校代码
void getSchoolcode()
{
    cout << "每组括号内：\n"
            "id是学校代码\n"
            "Name是对应的学校\n"
            "请仔细阅读，5秒后执行" << endl;
    this_thread::sleep_for(chrono::seconds(5));
    string url = "http://14.18.102.167:17001/edei/jsp/main/stasticAction!getAllTeachUnitInfo.action?exam=35&grade=9&subCompose=0&islevel=1&subject=101&level=0&sType=";
    openBrowser(url);
    cout << "ok" << endl;
    this_thread::sleep_for(chrono::seconds(3));
    clearScreen();
}

//获取全校排名
void getSchool()
{
     const string baseUrl = "http://14.18.102.167:17001/edei/g6!g6export.action?&studentType=0&step=10&mingcistep=100&topStep=&E5step=null&B3mingcistep=null&type=0&sNum=6000&c_exam=&rpt_name=A2-%E5%85%A8%E7%A7%91%E6%88%90%E7%BB%A9&source=0&isHistory=F&isMoreSchool=F&rate=50&islevelclass=F&expTagType=null&reCalcu=F&fufen=0&subCompose=0&islevel=0&rptTitle=去疾ttkx&sch=&subRank=-1&downRank=0&scoreName=1&shouxuanHide=0&isShowSubCompose=0";
    
    map<string, string> params;
    cout << "exam是考试码\ngradeNum是年级，如09\nschoolNum是学校代码";
    
    cout << "请输入examNum: ";
    getline(cin, params["examNum"]);
    
    cout << "请输入gradeNum: ";
    getline(cin, params["gradeNum"]);
    
    cout << "请输入schoolNum: ";
    getline(cin, params["schoolNum"]);

    string fullUrl = buildUrl(baseUrl, params);
    openBrowser(fullUrl);
    cout << "已打开浏览器，跳转到: " << fullUrl << endl;
    this_thread::sleep_for(chrono::seconds(3));
    clearScreen();
}
int main() {
    // 设置控制台中文编码
    SetConsoleOutputCP(936);
    
    while (true) {
        cout << "欢迎使用达美嘉工具\n"
                "如有疑问请联系ouroooo@163.com\n"
                "上次更新时间:2025/02/01\n"
                "工具更新地址https://ouroooo.github.io/damega\n\n"
                "1.登录达美嘉\n"
                "2.获取考试码\n"
                "3.导出初中全县排名\n"
                "4.获取学校代码\n"
                "5.导出全校排名\n"
                "6.查找新版本\n"
                "请输入选项：";

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
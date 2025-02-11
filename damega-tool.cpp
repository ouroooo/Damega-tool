#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <sstream>
#include <map>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

void clearTerminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void openBrowser(const string& url) {
#ifdef _WIN32
    string cmd = "start " + url;
#elif __APPLE__
    string cmd = "open " + url;
#else
    string cmd = "xdg-open " + url;
#endif
    system(cmd.c_str());
}

void newVersion() {
    string url = "https://ouroooo.github.io/damega";
    openBrowser(url);
    cout << "已打开链接：" << url << endl;
    this_thread::sleep_for(chrono::seconds(3));
    clearTerminal();
}

void loginDamega() {
    string url = "http://14.18.102.167:17001/edei/";
    openBrowser(url);
    cout << "已打开链接：" << url << endl;
    this_thread::sleep_for(chrono::seconds(3));
    clearTerminal();
}

void getExamNum() {
    cout << "每组花括号内：\nexamNum是考试码\nexamName是对应的考试" << endl;
    cout << "请仔细阅读，5秒后执行" << endl;
    this_thread::sleep_for(chrono::seconds(5));
    string url = "http://14.18.102.167:17001/edei/qList!getExamAndGraAndSubData.action";
    openBrowser(url);
    cout << "ok" << endl;
    this_thread::sleep_for(chrono::seconds(3));
    clearTerminal();
}

void outputQuanxian(const string& baseUrl, const vector<string>& fixedParams) {
    map<string, string> params;
    for (const auto& param : fixedParams) {
        cout << "exam是考试码\nsNum是排名范围，如2000就导出到第2000名左右\ngradeNum是年级，如09" << endl;
        string value;
        cout << "请输入参数'" << param << "'的值: ";
        getline(cin, value);
        params[param] = value;
    }

    string query;
    for (const auto& [key, value] : params) {
        query += key + "=" + value + "&";
    }
    if (!query.empty()) query.pop_back();

    string fullUrl = baseUrl + "&" + query;
    openBrowser(fullUrl);
    cout << "已打开浏览器，跳转到: " << fullUrl << endl;
}

void getSchoolId() {
    cout << "每组括号内：\nid是学校代码\nName是对应的学校" << endl;
    cout << "请仔细阅读，5秒后执行" << endl;
    this_thread::sleep_for(chrono::seconds(5));
    string url = "http://14.18.102.167:17001/edei/jsp/main/stasticAction!getAllTeachUnitInfo.action?exam=35&grade=9&subCompose=0&islevel=1&subject=101&level=0&sType=";
    openBrowser(url);
    cout << "ok" << endl;
    this_thread::sleep_for(chrono::seconds(3));
    clearTerminal();
}

void outputQuanxiao(const string& baseUrl, const vector<string>& fixedParams) {
    map<string, string> params;
    for (const auto& param : fixedParams) {
        cout << "exam是考试码\ngradeNum是年级，比如09\nschoolNum是学校代码" << endl;
        string value;
        cout << "请输入参数'" << param << "'的值: ";
        getline(cin, value);
        params[param] = value;
    }

    string query;
    for (const auto& [key, value] : params) {
        query += key + "=" + value + "&";
    }
    if (!query.empty()) query.pop_back();

    string fullUrl = baseUrl + "&" + query;
    openBrowser(fullUrl);
    cout << "已打开浏览器，跳转到: " << fullUrl << endl;
}

int main() {
    const vector<string> fixedParams = {"examNum", "sNum", "gradeNum"};
    const vector<string> fixedParams1 = {"examNum", "gradeNum", "schoolNum"};
    const string baseUrl = "http://14.18.102.167:17001/edei/g6!g6export.action?&schoolNum=196,199,201,185,190,192,195,198,189,184,180,183,191,182,193,188,187,204,197,200,194,181,186,331,203,206,202,205&classNum=&studentType=0&step=10&mingcistep=100&topStep=&E5step=null&B3mingcistep=null&type=0&c_exam=&rpt_name=A2-全科成绩&source=0&isHistory=F&isMoreSchool=T&rate=50&islevelclass=F&expTagType=null&reCalcu=F&fufen=0&subCompose=0&islevel=0&rptTitle=去疾ttkx&sch=1&subRank=-1&downRank=0&scoreName=1&shouxuanHide=0&isShowSubCompose=0";
    const string baseUrl1 = "http://14.18.102.167:17001/edei/g6!g6export.action?&studentType=0&step=10&mingcistep=100&topStep=&E5step=null&B3mingcistep=null&type=0&sNum=6000&c_exam=&rpt_name=A2-%E5%85%A8%E7%A7%91%E6%88%90%E7%BB%A9&source=0&isHistory=F&isMoreSchool=F&rate=50&islevelclass=F&expTagType=null&reCalcu=F&fufen=0&subCompose=0&islevel=0&rptTitle=去疾ttkx&sch=&subRank=-1&downRank=0&scoreName=1&shouxuanHide=0&isShowSubCompose=0";

    while (true) {
        cout << "欢迎使用达美嘉工具\n如有疑问请联系ouroooo@163.com\n上次更新时间:2025/02/01\n工具更新地址https://ouroooo.github.io/damega" << endl;
        cout << "1.登录达美嘉\n2.获取考试码\n3.导出初中全县排名\n4.获取学校代码\n5.导出全校排名\n6.查找新版本\n请输入选项：";
        string input;
        getline(cin, input);

        if (input == "1") {
            loginDamega();
        } else if (input == "2") {
            getExamNum();
        } else if (input == "3") {
            outputQuanxian(baseUrl, fixedParams);
            this_thread::sleep_for(chrono::seconds(3));
            clearTerminal();
        } else if (input == "4") {
            getSchoolId();
        } else if (input == "5") {
            outputQuanxiao(baseUrl1, fixedParams1);
            this_thread::sleep_for(chrono::seconds(3));
            clearTerminal();
        } else if (input == "6") {
            newVersion();
        } else {
            clearTerminal();
        }
    }

    return 0;
}
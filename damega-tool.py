import webbrowser
import os
import platform
import time
import urllib.parse
quji=520
def new():
    """获取更新"""
    url = "https://ouroooo.github.io/damega"
    webbrowser.open(url)
    print("已打开链接：", url)
    time.sleep(3)
    clear_terminal()  # 调用函数清理终端屏幕
def clear_terminal():
    if platform.system() == "Windows":
        os.system('cls')
    else:
        os.system('clear')
def login_damega():
    """登录达美嘉"""
    url = "http://14.18.102.167:17001/edei/"
    webbrowser.open(url)
    print("已打开链接：", url)
    time.sleep(3)
    clear_terminal()  # 调用函数清理终端屏幕
def get_examNum():
    """获取考试码"""
    print("每组花括号内：\nexamNum是考试码\nexamName是对应的考试")
    print("请仔细阅读，5秒后执行")
    time.sleep(5)
    url = "http://14.18.102.167:17001/edei/qList!getExamAndGraAndSubData.action"
    webbrowser.open(url)
    print("ok")
    time.sleep(3)
    clear_terminal()  # 调用函数清理终端屏幕
def output_quanxian(url, fixed_params):
    params = {}
    for param_name in fixed_params:
        # 提示用户输入参数值
        print("exam是考试码\nsNum是排名范围，如2000就导出到第2000名左右\ngradeNum是年级，如09")
        param_value = input(f"请输入参数'{param_name}'的值: ")
        params[param_name] = param_value
    
    # 将参数字典转换为查询字符串
    query_string = urllib.parse.urlencode(params)
    
    # 构造完整的URL
    full_url = f"{url}&{query_string}"
    
    # 使用webbrowser打开浏览器并跳转到目标URL
    webbrowser.open(full_url)
    print(f"已打开浏览器，跳转到: {full_url}")

# 示例用法
base_url = "http://14.18.102.167:17001/edei/g6!g6export.action?&schoolNum=196,199,201,185,190,192,195,198,189,184,180,183,191,182,193,188,187,204,197,200,194,181,186,331,203,206,202,205&classNum=&studentType=0&step=10&mingcistep=100&topStep=&E5step=null&B3mingcistep=null&type=0&c_exam=&rpt_name=A2-全科成绩&source=0&isHistory=F&isMoreSchool=T&rate=50&islevelclass=F&expTagType=null&reCalcu=F&fufen=0&subCompose=0&islevel=0&rptTitle=去疾ttkx&sch=1&subRank=-1&downRank=0&scoreName=1&shouxuanHide=0&isShowSubCompose=0"
fixed_params = ["examNum", "sNum", "gradeNum"]  # 固定的参数名列表
def get_schoolid():
    """获取学校代码码"""
    print("每组括号内：\nid是学校代码\nName是对应的学校")
    print("请仔细阅读，5秒后执行")
    time.sleep(5)
    url = "http://14.18.102.167:17001/edei/jsp/main/stasticAction!getAllTeachUnitInfo.action?exam=35&grade=9&subCompose=0&islevel=1&subject=101&level=0&sType="
    webbrowser.open(url)
    print("ok")
    time.sleep(3)
    clear_terminal()  # 调用函数清理终端屏幕
def output_quanxiao(url, fixed_params):
    params1 = {}
    for param_name1 in fixed_params1:
        # 提示用户输入参数值
        print("exam是考试码\ngradeNum是年级，比如09\nschoolNum是学校代码")
        param_value = input(f"请输入参数'{param_name1}'的值: ")
        params1[param_name1] = param_value
    
    # 将参数字典转换为查询字符串
    query_string = urllib.parse.urlencode(params1)
    
    # 构造完整的URL
    full_url = f"{url}&{query_string}"
    
    # 使用webbrowser打开浏览器并跳转到目标URL
    webbrowser.open(full_url)
    print(f"已打开浏览器，跳转到: {full_url}")

# 示例用法
base_url1 = "http://14.18.102.167:17001/edei/g6!g6export.action?&studentType=0&step=10&mingcistep=100&topStep=&E5step=null&B3mingcistep=null&type=0&sNum=6000&c_exam=&rpt_name=A2-%E5%85%A8%E7%A7%91%E6%88%90%E7%BB%A9&source=0&isHistory=F&isMoreSchool=F&rate=50&islevelclass=F&expTagType=null&reCalcu=F&fufen=0&subCompose=0&islevel=0&rptTitle=去疾ttkx&sch=&subRank=-1&downRank=0&scoreName=1&shouxuanHide=0&isShowSubCompose=0"
fixed_params1 = ["examNum", "gradeNum", "schoolNum"]  # 固定的参数名列表
while quji<1314:
      print("欢迎使用达美嘉工具\n如有疑问请联系ouroooo@163.com\n上次更新时间:2025/02/01\n工具更新地址https://ouroooo.github.io/damega")
             # 提示用户输入
      user_input = input("1.登录达美嘉\n2.获取考试码\n3.导出初中全县排名\n4.获取学校代码\n5.导出全校排名\n6.查找新版本\n请输入选项：")
      # 判断用户输入
      if user_input == "1":
        login_damega()
      elif user_input == "2":
        get_examNum()
      elif user_input == "3":
        output_quanxian(base_url, fixed_params)
        time.sleep(3)
        clear_terminal()  # 调用函数清理终端屏幕
      elif user_input == "4":
        get_schoolid()
      elif user_input == "5":
        output_quanxiao(base_url1, fixed_params1)
        time.sleep(3)
        clear_terminal()  # 调用函数清理终端屏幕
      elif user_input == "6":
        new()
      else:
        clear_terminal()  # 调用函数清理终端屏幕

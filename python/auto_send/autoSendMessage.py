import win32gui
import win32con
import win32clipboard
import pymouse
import pykeyboard


# # 发送的消息
# msg = "测试代码"
# # 窗口名字
# name = "LUOWEIBIAO"
# # 将测试消息复制到剪切板中
# win32clipboard.OpenClipboard()
# win32clipboard.EmptyClipboard()
# win32clipboard.SetClipboardData(win32con.CF_UNICODETEXT, msg)
# win32clipboard.CloseClipboard()
# # 获取窗口句柄
# handle = win32gui.FindWindow(None, name)
# win32gui.SetForegroundWindow(handle)
# win32gui.ShowWindow(handle, win32con.SW_SHOWNORMAL)
# rect = win32gui.GetWindowRect(handle)
#
# width = rect[2] - rect[0]
# height = rect[3] - rect[1]
# print(width, height)
#
# mouse = pymouse.PyMouse()
# mouse.click(rect[0] + width // 2, rect[1] + height - 50)
#
# keyboard = pykeyboard.PyKeyboard()
# # keyboard.type_string('我爱你@啊方法fadfafaf## comm a fa')
# keyboard.press_keys([keyboard.control_l_key, 'v'])
# keyboard.press_key(keyboard.enter_key)

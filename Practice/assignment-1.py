import pyautogui
from time import sleep
sleep(1)
N=int(input())
for i in range(0,N+1):
    for j in range(0,i):
        pyautogui.write('#')
    pyautogui.press('enter')   







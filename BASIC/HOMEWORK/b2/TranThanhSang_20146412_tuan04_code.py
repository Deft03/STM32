# Tên : Trần Thanh Sang
# Mssv: 20146412
# Link video minh chứng : https://youtu.be/uvO_ltrA2tc
# Contact: 0349703189

#%% BT1

import package_b1 as pd

class1 = pd.normal_class("tầng 4", "75","105" ,"CLC", "E403")
class1.sign()

print("#####")

class2 = pd.high_class("tầng 5", "25", "75" , 14, "CLC" , "A503")
class2.autoControll()
class2.sign()


#%% BT2

#GUI sử dụng : tkingter
# Cách cài: pip install tk
import tkinter as tk

#Hàm khi nhấn vào
def btnpress(numbers):
    global operator
    operator = operator + str(numbers)
    result.set(operator) ## Đặt result là operator 
#Tạo cửa số mới
root=tk.Tk() #root sẽ là cửa sổ chính
root.title('Bài tập 2-AI')

#tạo biến toán tử
operator=''
# biến kết quả
result = tk.StringVar()
calculation = tk.Label(root,font=('Calibri',16),textvariable = result)
result.set('0')
calculation.config(text='')
calculation.grid(columnspan = 5)

#Hàm lùi về
def back():
    try:
        global operator
        a=result.get()
        a=int(a)
        a=a//10
        a=str(a)
        operator=a
        result.set(operator)
    except:
        pass
#Hàm thực hiện phép tính & in ra kết quả
def evaluate(result):
    try:
        global operator
        data=result.get()
        operator=''
        a=data.replace('x','*')
        a=a.replace('^','**')
        result.set('Answer: '+str(eval(a)))   
    except:
        result.set('Invalid entry')

# Hàm clear cửa sổ
def clear():
    global operator
    operator = ''
    result.set('0')
###
h,w,fgclr,fgclr2,bgclr,bgclr2,fnt=4,8,'Black','Red','Silver','Silver',('Calibri',15)
##khai báo các nút nhấn
B0=tk.Button(root,text='0',height=h,width=w,font=(fnt),fg=fgclr,bg=bgclr,command =lambda: btnpress(0), )
B1=tk.Button(root,text='1',height=h,width=w,font=(fnt),fg=fgclr,bg=bgclr,command =lambda: btnpress(1))
B2=tk.Button(root,text='2',height=h,width=w,font=(fnt),fg=fgclr,bg=bgclr,command =lambda: btnpress(2))
B3=tk.Button(root,text='3',height=h,width=w,font=(fnt),fg=fgclr,bg=bgclr,command =lambda: btnpress(3))
B4=tk.Button(root,text='4',height=h,width=w,font=(fnt),fg=fgclr,bg=bgclr,command =lambda: btnpress(4))
B5=tk.Button(root,text='5',height=h,width=w,font=(fnt),fg=fgclr,bg=bgclr,command =lambda: btnpress(5))
B6=tk.Button(root,text='6',height=h,width=w,font=(fnt),fg=fgclr,bg=bgclr,command =lambda: btnpress(6))
B7=tk.Button(root,text='7',height=h,width=w,font=(fnt),fg=fgclr,bg=bgclr,command =lambda: btnpress(7))
B8=tk.Button(root,text='8',height=h,width=w,font=(fnt),fg=fgclr,bg=bgclr,command =lambda: btnpress(8))
B9=tk.Button(root,text='9',height=h,width=w,font=(fnt),fg=fgclr,bg=bgclr,command =lambda: btnpress(9))

Bresult=tk.Button(root,text='=',height=h,width=w,font=(fnt),fg=fgclr2,bg=bgclr2,command =lambda: evaluate(result))
Bplus=tk.Button(root,text='+',height=h,width=w,font=(fnt),fg=fgclr2,bg=bgclr2,command =lambda: btnpress('+'))
Bminus=tk.Button(root,text='-',height=h,width=w,font=(fnt),fg=fgclr2,bg=bgclr2,command =lambda: btnpress('-'))
Bmul=tk.Button(root,text='x',height=h,width=w,font=(fnt),fg=fgclr2,bg=bgclr2,command =lambda: btnpress('x'))
Bdiv=tk.Button(root,text='/',height=h,width=w,font=(fnt),fg=fgclr2,bg=bgclr2,command =lambda: btnpress('/'))
Bclr=tk.Button(root,text='C',height=h,width=w,font=(fnt),fg=fgclr2,bg=bgclr2,command =lambda: clear())
Bbrs=tk.Button(root,text='(',height=h,width=w,font=(fnt),fg=fgclr2,bg=bgclr2,command =lambda: btnpress('('))
Bbre=tk.Button(root,text=')',height=h,width=w,font=(fnt),fg=fgclr2,bg=bgclr2,command =lambda: btnpress(')'))
Bback=tk.Button(root,text='~',height=h,width=w,font=(fnt),fg=fgclr2,bg=bgclr2,command =lambda: back())
Bpow=tk.Button(root,text='^',height=h,width=w,font=(fnt),fg=fgclr2,bg=bgclr2,command =lambda: btnpress('^'))
# sắp xếp các nút
B1.grid(row=1,column=0)
B2.grid(row=1,column=1)
B3.grid(row=1,column=2)
B4.grid(row=2,column=0)
B5.grid(row=2,column=1)
B6.grid(row=2,column=2)
B7.grid(row=3,column=0)
B8.grid(row=3,column=1)
B9.grid(row=3,column=2)
B0.grid(row=4,column=1,)
Bclr.grid(row=4,column=0)
Bresult.grid(row=4,column=2)
Bplus.grid(row=1,column=3)
Bminus.grid(row=2,column=3)
Bmul.grid(row=3,column=3)
Bdiv.grid(row=4,column=3)
Bback.grid(row=1,column=4)
Bbrs.grid(row=2,column=4)
Bbre.grid(row=3,column=4)
Bpow.grid(row=4,column=4)

root.mainloop()
# %%
# Link video minh chứng : https://youtu.be/uvO_ltrA2tc
#This is module1 of package_demo
#Create : 2 March 2023

#%% Hệ thống quản lý lớp học
from .module2 import *

### lớp đại trà 
class normal_class:
    #floor = ''         # Số tầng 
    #num_table = ''     # Số bàn
    #num_seat = ''      # Số chổ ngồi
    #faculty = ''       # Khoa của lớp
    #key = ''           # Số phòng

    def __init__(self, floor , table, seat, faculty, key):
        self.floor = floor
        self.table = table
        self.seat = seat
        self.faculty = faculty 
        self.key = key
        self.vacant = True  # Kiểm tra lớp còn trống hay là không
        self.checked = False    #Kiểm tra đúng mã lớp hay không
        self.exceed = True      #Kiểm tra số ghế có vượt quá hay chưa
        
    
    #Hàm đăng ký lớp học dành cho giảng viên 
    def sign(self):
        print("Nhập lớp bạn muốn đăng ký:")
        key = input()
        print("Mã lớp là", key)
        print("Nhập số lượng học sinh:")
        seat = input()
        print("Số lượng học sinh là : ",seat)
        
        checkKey(self, key)
        if(self.checked):
            check_numOfSeat(self,seat)
            if self.vacant and self.exceed:
                print("Sign Up Success")
                self.check = False
            else:
                print("Haven't Signed yet!")
        
###lớp chất lượng cao
class high_class(normal_class):
    def __init__(self, floor , table,seat, temperature, faculty, key):
        normal_class.__init__(self, floor , table,seat, faculty,key)
        self.temperature = temperature
        self.controlled = False # Kiểm tra nhiệt độ
        

    # Tự động xử lý khi nhiệt độ mất kiểm soát
    def autoControll(self):
        Control_temp(self)
        if self.controlled:
            print("Auto Controll Activated")
        else:
            print("Auto Controll Deactivated")        

# %%

#This is module2 of package_demo
#Create : 2 March 2023
# Contact Information: 

# Hàm kiểm tra số lượng ghế có phù hợp hay không 
def check_numOfSeat(self, seat):
    #Nếu vượt qua số ghế mặc định thì trả về False
    if(seat > self.seat):
        self.exceed = False
        print("exceed the allowable limit")
    
#Hàm kiểm tra mã lớp đúng hay sai
def checkKey(self, key):
    if key == self.key:
        self.checked = True
        print("Checking....")
    else:
        print("Wrong key:")
        
# Hàm kiểm tra nhiệt độ để tiến hành xử lý
def Control_temp(self):
    tmp= self.temperature
    if(tmp<18 or tmp>30):
        self.controlled = True
        print("Out of controll...WARNING!! ")

    else:
        print("In control.")
        
    


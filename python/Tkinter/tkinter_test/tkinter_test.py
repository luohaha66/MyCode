'''
Created on Jul 22, 2018

@author: Administrator
'''

import tkinter as tk
import base64
import hashlib
import math

class App: 
    def tk1(self, master):
        self.frame = tk.Frame(master)
        self.frame.pack(padx = 10, pady = 10)
        self.butt = tk.Button(self.frame, text = 'ok, make you', fg = 'blue', bg = 'black', command = self.callback)
        self.butt.pack() 
        
    def tk2(self, master):
        self.frame = tk.Frame(master)
        self.frame.pack(padx = 10, pady = 10)
        self.var = tk.StringVar()
        self.var.set('please do more thing! please do more thing!\nplease do more thing! please do more thing!')
        self.label = tk.Label(self.frame, textvariable = self.var, justify = tk.LEFT, padx = 10)
        self.label.pack(side = tk.LEFT)
        
        self.photo = tk.PhotoImage(file = '1.gif')
        self.imLabel = tk.Label(self.frame, image = self.photo)
        self.imLabel.pack(side = tk.RIGHT)
     
    def tk3(self, master):
        self.photo = tk.PhotoImage(file = '1.gif')
        self.label = tk.Label(master, text='come in,don\'t stop', image = self.photo, compound = tk.CENTER)
        self.label.pack()
    
    def tk4(self, master):
        self.tk2(master)
        self.tk1(master)  
    
    def tk5(self, master):
        self.g = ['cjk', 'xq', 'hyl', 'ym', 'sda']
        self.f = []
        for g in self.g:
            self.f.append(tk.IntVar())
            self.c = tk.Checkbutton(master, text=g, variable=self.f[-1])
            self.c.pack(anchor=tk.W)
    
    def tk6(self, master):
        self.g = tk.LabelFrame(master, text='which you love best?', padx = 5, pady = 5)
        self.g.pack(padx = 10, pady = 10)
        self.v = tk.IntVar()
        self.LANGS = [
            ('python', 1),
            ('c', 2),
            ('c++', 3),
            ('java', 4)
            ]
        for (lang, num) in self.LANGS:
            self.r = tk.Radiobutton(self.g, text=lang, variable=self.v, value = num, indicatoron=False).pack(anchor=tk.W, fill=tk.X)
     
    def tk7(self, master):
        self.v = tk.StringVar()
        self.v1 = tk.StringVar()
        self.l = tk.Label(master, text='user').grid(row = 0, column = 0)
        self.l1 = tk.Label(master, text='passwd').grid(row = 1, column = 0)
        self.e = tk.Entry(master, textvariable = self.v)
        self.e.grid(row = 0, column = 1, padx=10, pady=5)
        self.e1 = tk.Entry(master, textvariable = self.v1, show='*')
        self.e1.grid(row = 1, column = 1, padx=10, pady=5)
        self.b = tk.Button(master, text='login', width=10, command=self.show).grid(row = 2, column = 0, sticky=tk.W, padx=10, pady=10)
        self.b = tk.Button(master, text='logout', width=10, command=master.quit).grid(row = 2, column = 1, sticky=tk.E, padx=10, pady=10)
     
    def tk8(self, master):
        self.frame = tk.Frame(master)
        self.frame.pack(padx = 10, pady = 10)
        self.v1 = tk.StringVar()
        self.v2 = tk.StringVar()
        self.v3 = tk.StringVar()
        self.testCMD=master.register(self.test)
        self.e2 = tk.Entry(self.frame, width=10, textvariable=self.v1, validate='key', validatecommand = (self.testCMD, '%P'))
        self.e2.grid(row = 0, column = 0, padx = 10)
        self.l = tk.Label(self.frame, text=' + ').grid(row = 0, column = 1)
        self.e3 = tk.Entry(self.frame, width=10, textvariable=self.v2, validate='key', validatecommand = (self.testCMD, '%P'))
        self.e3.grid(row = 0, column = 2, padx = 10)
        self.l1 = tk.Label(self.frame, text=' = ').grid(row = 0, column = 3)
        self.e4 = tk.Entry(self.frame, width=10, textvariable=self.v3, state='readonly')
        self.e4.grid(row = 0, column = 4, padx = 10)
        self.b = tk.Button(self.frame, text='done', width=10, command=self.count).grid(row = 1, column = 2, padx=10, pady=10)
    
    def tk9(self, master):
        self.s = tk.Scrollbar(master)
        self.s.pack(side = tk.RIGHT, fill=tk.Y)
        self.l = tk.Listbox(master, yscrollcommand=self.s.set)
        self.l.pack()
        for item in range(200):
            self.l.insert(tk.END, item)
        self.s.config(command = self.l.yview)
        self.b = tk.Button(master, text='del', 
                           command=lambda x = self.l : x.delete(tk.ACTIVE) )
        self.b.pack()
    
    def tk10(self, master):
        self.s = tk.Scale(master,from_=0, to=100, tickinterval=5, resolution=10, length = 100)
        self.s.pack()
        self.s1 = tk.Scale(master,from_=0, to=100, orient=tk.HORIZONTAL)
        self.s1.pack()
        self.b = tk.Button(master, text='pos', command= lambda : print(self.s.get(), self.s1.get()))
        self.b.pack()
    
    def tk11(self, master):
        self.t = tk.Text(master, width = 30, height = 5, undo=True, autoseparators=False)
        self.t.pack()
        self.t.insert(tk.INSERT, 'i love you\n')
        self.t.insert(tk.END, 'i hate you')
        self.t.bind('<Key>', lambda event:self.t.edit_separator())
        self.t.tag_add('link', '1.2', '1.6')
        self.t.tag_config('link', foreground='blue', underline=True)
        self.t.tag_bind('link', '<Enter>', lambda event:self.t.config(cursor='arrow'))
        self.t.tag_bind('link', '<Leave>', lambda event:self.t.config(cursor='xterm'))
        self.t.tag_bind('link', '<Button-1>', lambda event:print('event occur'))
        self.sig = hashlib.md5(self.t.get('1.0', tk.END).encode()).digest()
        self.b = tk.Button(self.t, text='check', command=self.commpare)
        self.b.pack()
        self.t.window_create(tk.INSERT, window=self.b)
        self.b1 = tk.Button(master, text='undo', command = lambda : self.t.edit_undo())
        self.b1.pack()
#        self.pos = self.t.search('o', '1.0')
#        print(tuple(map(int, str.split(self.t.index(self.pos), '.'))))
    
    def tk12(self, master):
        self.c = tk.Canvas(master, width=200, height = 100)
        self.c.pack()
        self.l = self.c.create_line(0, 0, 200, 100, fill='red', dash=(3,3))
        self.l1 = self.c.create_line(200, 0, 0, 100, fill='blue', dash=(3,3))
        self.l2 = self.c.create_rectangle(40, 20, 160, 80, fill='black')
        self.l3 = self.c.create_rectangle(65, 35, 135, 65, fill='green')
        self.con = self.c.create_text(100, 50, text='I love you!')
#         self.c.coords(self.l, 0, 25, 200, 25)
#         self.c.itemconfig(self.l2, fill='yellow')
#         self.c.delete(self.l1)

    def tk13(self, master):    
        self.c = tk.Canvas(master, width=200, height = 100)
        self.c.pack()
        self.cen_x = 100
        self.cen_y = 50
        self.r = 50
        points = [
            self.cen_x - int(self.r * math.sin(2 * math.pi / 5)),
            self.cen_y - int(self.r * math.cos(2 * math.pi / 5)),
            self.cen_x + int(self.r * math.sin(2 * math.pi / 5)),
            self.cen_y - int(self.r * math.cos(2 * math.pi / 5)),
            self.cen_x - int(self.r * math.sin(math.pi / 5)),
            self.cen_y + int(self.r * math.cos(math.pi / 5)),
            self.cen_x,
            self.cen_y - self.r,
            self.cen_x + int(self.r * math.sin(math.pi / 5)),
            self.cen_y + int(self.r * math.cos(math.pi / 5)),
            ]
        self.c.create_polygon(points, outline='red', fill='red') 
    
    def tk14(self, master):
        self.c = tk.Canvas(master, width=400, height = 200)
        self.c.pack()
        self.c.bind('<B1-Motion>', self.paint)
    
    def tk15(self, master):
        self.m1 = tk.Menu(master)
        self.m = tk.Menu(self.m1, tearoff=False)
        self.m.add_command(label='open', command= lambda:print('hi'))
        self.m.add_command(label='save', command= master.quit)
        self.m.add_separator()
        self.m.add_command(label='quit', command= master.quit)
        self.m1.add_cascade(label='file', menu=self.m)
        
        self.m2 = tk.Menu(self.m1, tearoff=False)
        self.m2.add_command(label='copy', command= lambda:print('hi'))
        self.m2.add_command(label='cut', command= master.quit)
        self.m2.add_separator()
        self.m2.add_command(label='chose', command= master.quit)
        self.m1.add_cascade(label='edit', menu=self.m2)
        
        self.m3 = tk.Menu(master, tearoff=False)
        self.m3.add_command(label='copy', command= lambda:print('hi'))
        self.m3.add_command(label='cut', command= master.quit)
        self.m3.add_separator()
        self.m3.add_command(label='chose', command= master.quit)
        self.f= tk.Frame(master, width = 512, height = 512)
        self.f.pack()
        self.f.bind('<Button-3>', lambda event:self.m3.post(event.x_root, event.y_root))
        
        self.v = tk.StringVar()
        self.l = ['1', '2', '3', '4', '5']
        self.v.set(self.l[0])
        self.m4 = tk.OptionMenu(master, self.v, *self.l)
        self.m4.pack()
        master.config(menu=self.m1)
        
    def paint(self, event):
        (x1, y1) = ((event.x - 1), (event.y - 1))
        (x2, y2) = ((event.x + 1), (event.y + 1))
        self.c.create_oval(x1, y1, x2, y2, fill='black')
                
    def commpare(self):
        self.sig1 = hashlib.md5(self.t.get('1.0', tk.END).encode()).digest()
        if self.sig1 != self.sig:
            print('changed') 
        else:
            print('not changed')     
          
    def count(self):
        result = int(self.e2.get()) + int(self.e3.get())
        self.v3.set(str(result))
        
    def test(self,content):
        return content.isdigit()
               
    def show(self):
        print('user %s' % self.e.get())
        print('passwd %s' % self.e1.get())
                         
    def callback(self):
        self.var.set('give money and you can')

def base64code():
    ba64 = None
    with open('2.jpg', 'rb') as f:
        data = f.read()
        ba64 = base64.b64encode(data)
    
    with open('3.jpg', 'wb') as f:
        dec = base64.b64decode(ba64)
        f.write(dec)
        
if __name__ == '__main__':
    a = App()
    root = tk.Tk()
    app = a.tk15(root)
    root.mainloop()

    
    
    
    
    
    
    
    
    
    
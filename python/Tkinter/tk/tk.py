'''
Created on Jul 28, 2018

@author: Administrator
'''
import tkinter as tk
from tkinter import messagebox
from tkinter import filedialog
from tkinter import colorchooser

class app():
    def callback(self, event):
        print(event.keysym)
        
    def tk1(self, master):
        self.f = tk.Frame(master, width=200, height=200)
        self.f.bind('<Key>', self.callback)
        self.f.focus_set()
        self.f.pack()
        
    def tk2(self, master):
        self.l = tk.Label(master, text='user')
        self.l.grid(row=0, column = 0, sticky=tk.W)
        self.l1 = tk.Label(master, text='pwd')
        self.l1.grid(row=1, column = 0, sticky=tk.W)
        self.e = tk.Entry(master)
        self.e.grid(row=0, column = 1)
        self.e1 = tk.Entry(master, show='*')
        self.e1.grid(row=1, column = 1)
        self.p = tk.PhotoImage(file='1.gif')
        self.l3 = tk.Label(master, image=self.p)
        self.l3.grid(row = 0, column = 2, rowspan=2, padx=5, pady=5)
        self.b = tk.Button(master, text='log in')
        self.b.grid(row = 2, column = 0, columnspan = 3, pady = 5)
    
    def tk3(self, master):
        self.m = messagebox.askokcancel('launch', 'launch missile')
    
    def tk4(self, master):
        self.b = tk.Button(master, text = 'open', 
                           command=lambda:filedialog.askopenfilename(filetypes=[('PNG', 'png'), ('GIF', 'gif')], defaultextension='.gif'))
        self.b.pack()
    
    def tk5(self, master):
        self.b = tk.Button(master, text = 'color', 
                           command=lambda:print(colorchooser.askcolor()))
        self.b.pack()
                    
if __name__ == '__main__':
    a = app()
    root = tk.Tk()
    app = a.tk5(root)
    root.mainloop()


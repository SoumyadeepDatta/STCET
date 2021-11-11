from tkinter import *
from tkinter import messagebox
root=Tk()

def getvals():
    messagebox.showinfo("Info","Submitted")

root.geometry("400x450")
root.resizable(width=False, height=False)
root.title(string="GUI PROJECT 1")
var=IntVar()
var2=IntVar()

f1=Frame(root,borderwidth=2,relief=GROOVE,pady=2)
f1.grid(row=0,column=3,pady=20)
Label(f1,text="NPTEL STUDENT LOGIN", font="segoeui 15",pady=5).pack()
name=Label(root,text="Username",pady=10)
phone=Label(root,text="Phone",pady=10)

f2=Frame(root,borderwidth=2)
f2.grid(row=4,column=3,pady=4)
radio=Radiobutton(f2,text="Male",padx=10,variable=var,value=1).grid(row=4,column=1,pady=4)
radio=Radiobutton(f2,text="Female",padx=10,variable=var,value=2).grid(row=4,column=2,pady=4)
radio=Radiobutton(f2,text="Others",padx=10,variable=var,value=3).grid(row=4,column=3,pady=4)

gender=Label(root,text="Gender").grid(row=4,column=2,pady=5)
password=Label(root,text="Password",pady=10)

payment=Label(root,text="Payment")

name.grid(row=1,column=2,padx=15)
phone.grid(row=3,column=2,padx=15)
password.grid(row=2,column=2,padx=15)

payment.grid(row=5,column=2,padx=15)

nameval= StringVar()
phoneval= StringVar()
passval= StringVar()

paymentval= StringVar()


nameentry = Entry(root,textvariable=nameval)
phoneentry = Entry(root,textvariable=phoneval)
passentry = Entry(root, show="*",textvariable=passval)



f3=Frame(root,borderwidth=2)
f3.grid(row=5,column=3,pady=4)
radio=Radiobutton(f3,text="Online",padx=10,variable=var2,value=1).grid(row=5,column=1,pady=4)
radio=Radiobutton(f3,text="e-Challan",padx=10,variable=var2,value=2).grid(row=5,column=2,pady=4)







nameentry.grid(row=1, column=3)
phoneentry.grid(row=3, column=3)
passentry.grid(row=2, column=3)





terms=Checkbutton(text="I have accepted Terms and Conditions").grid(row=7, column=3,pady=10)

Button(text="Submit",font="segoeui 12 bold",command=getvals,relief=RAISED).grid(row=8, column=3,pady=15)
Button(text="EXIT",font="segoeui 10 ",command=root.destroy,relief=SUNKEN).grid(row=9, column=3,pady=5)
root.mainloop()

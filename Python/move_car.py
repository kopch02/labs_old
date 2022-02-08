from tkinter import*
from turtle import*

tk=Tk()
canvas = Canvas(tk, width=1000, height=1000)
canvas.pack()

def road():
    canvas.create_rectangle(0, 600, 1000, 400, fill='black')
def lines():
    canvas.create_rectangle(100, 520, 200, 480, fill='white')
    canvas.create_rectangle(300, 520, 400, 480, fill='white')
    canvas.create_rectangle(500, 520, 600, 480, fill='white')
    canvas.create_rectangle(700, 520, 800, 480, fill='white')
def car():
    global car, rk,lk
    car=canvas.create_rectangle(550, 550, 350, 450, fill='yellow')
    rk=canvas.create_oval(550, 560, 470, 500, fill='grey')
    lk=canvas.create_oval(350, 560, 430, 500, fill='grey')   
def move_car(event):
    if event.keysym == 'Up':
        canvas.move(car, 0, -5)
        canvas.move(rk, 0, -5)
        canvas.move(lk, 0, -5)
    elif event.keysym == 'Down':
        canvas.move(car,0,5)
        canvas.move(rk, 0, 5)
        canvas.move(lk, 0, 5)

    elif event.keysym == 'Left':
        canvas.move(car,-5,0)
        canvas.move(rk, -5, 0)
        canvas.move(lk, -5, 0)

    elif event.keysym == 'Right':
        canvas.move(car,5,0)
        canvas.move(rk, 5, 0)
        canvas.move(lk, 5, 0)

road()
lines()
car()

canvas.bind_all('<Up>', move_car)
canvas.bind_all('<Down>', move_car)
canvas.bind_all('<Left>', move_car)
canvas.bind_all('<Right>', move_car)
tk.mainloop()
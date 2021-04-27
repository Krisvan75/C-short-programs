import tkinter as tk
from tkinter import filedialog
from PIL import Image

def getPNG():

    global im1
    import_file_path = filedialog.askopenfilename(filetypes=[('Portable Network Graphics', '*.PNG')])
    im1 = Image.open(import_file_path)

def ConvertToJPG():
    global im1
    export_filePath = filedialog.asksaveasfilename(defaultextension='.jpg')
    im1.save(export_filePath)

root = tk.Tk()
root.title("File Converter")
canvas1 = tk.Canvas(root, width=300, height=250, bg='azure3',relief='raised')

canvas1.pack()

label1 = tk.Label(root, text="PNG to JPG", bg='azure3')
label1.config(font=('helvetica', 20))
canvas1.create_window(150, 60, window=label1)

browseButton_MAT = tk.Button(text = "Import .PNG File", command=getPNG, bg='royalblue',font=('helvetica',12,'bold'))
canvas1.create_window(150,130,window =browseButton_MAT)

saveAsButton_JPG = tk.Button(text="Convert to .jpg", command=ConvertToJPG, bg='royalblue',font=('helvetica',12,'bold'))
canvas1.create_window(150, 180, window=saveAsButton_JPG)

root.mainloop()

b=["игра 1","игра2","игра3","игра 4"]

# вывожу весь список, чтобы посмотреть что в нём
print(b)

#копирую данные, чтобы они не потерялись при замене
s=b[1]      #создал переменную s и внеё сохранил значение 1го элемента списка b
d=b[3]      #создал переменную d и внеё сохранил значение 3го элемента списка b

#меняю их местами
b[1]=d     # в первый элемент спика b записываю информацию которая находится в перемнной d которую создал заранее
b[3]=s     # в последний элемент спика b записываю информацию которая находится в перемнной s которую создал заранее
# вывожу весть список, чтобы посмотреть насколько правильно я всё сделал
print(b)
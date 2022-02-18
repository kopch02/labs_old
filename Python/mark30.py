from random import*
class character(object):
    def __init__(self,name, hp, damage):
        self.name = name
        self.hp = hp
        self.damage = damage      
class player(character):
    def __init__(self, name, hp, damage, xp,lvl):
        super().__init__(name, hp, damage)
        self.name=name
        self.xp = xp
        self.lvl=lvl
    def attack(self,victim):
        victim.hp-=self.damage
        if victim.hp<=0:
            print(victim.name,"повержен")
            if self.xp==100:
                self.xp=0
                self.lvl+=1
                print("повышение тиуровня,уровень",self.lvl)
                self.hp+=30
                self.damage+=30
        else:
            print(victim.name,"теперь имеет",victim.hp,"здоровье")
            print(self.name,"нанес удар:-%s"%self.damage)
class enemy(character):
    def __init__(self,name,hp,damage):
        super().__init__(name,hp,damage)
        
    def attack(self,victim):
        victim.hp-=self.damage
        if victim.hp<=0:
            print(victim.name,"повержен","конец игры")
            quit()
        else:
            print(victim.name,"теперь имеет",victim.hp,"здоровье")
            print(self.name,"нанес удар:-%s"%self.damage)
class_list=["лучник","мечник"]
race_list=["эльф","гном","человек"]
class_type=[]
race_type=[]
def create_person(name,class_type,race_type):
    hp=1
    damage=0
    xp=0
    lvl=1
    if class_type==class_list[0]:
        hp+=5
        damage+=10
        if race_type==race_list[0]:
            hp+=5
            damage+=10
            hp+=3
            damage+=5
        if race_type==race_list[1]:
            hp+=5
            damage+=10
        if race_type==race_list[2]:
            hp+=5
            damage+=10
        return player(name,hp,damage,xp,lvl)
    if class_type==class_list[1]:
        hp+=5
        damage+=10
        if race_type==race_list[0]:
            hp+=5
            damage+=10
        if race_type==race_list[1]:
            hp+=5
            damage+=10
        if race_type==race_list[2]:
            hp+=5
            damage+=10
            hp+=3
            damage+=3
        return player(name,hp,damage,xp,lvl)
        print("ошибка")
def create_monter():
    mn="monster"
    mhp=randint(7,10)*p.lvl
    md=randint(1,3)*p.lvl
    return enemy(mn,mhp,md)
def sol (victim):
    global pr,pc
    print("имя персонажа:",victim.name,"\nздоровье персонажа:",victim.hp,"\nурон персонажа:",victim.damage,"\nуровень персонажа:",victim.lvl,"\nопыт персонажа:",victim.xp,"\nрасса персонажа:",pr,"\nклас персонажа:",pc) 
print("Введите имя:")
pn=input()
print("выберете рассу,доступные:")
for x in race_list:
    print(x)
pr=input()
print("выберете класс,доступные:")
for x in class_list:
    print(x)
pc=input()
p=create_person(pn,pc,pr)
sol(p)
while True:
    monster=create_monter()
    while p.hp>=0 or monster.hp>=0:
        p.attack(monster)
        monster.attack(p)
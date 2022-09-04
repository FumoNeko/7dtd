import sys
import re
import os

sys.stdin.reconfigure(encoding='utf-8')
sys.stdout.reconfigure(encoding='utf-8')

cwd = os.getcwd()

itemsText = open(cwd + "/items.xml", "r")
itemsDump = itemsText.read()
itemsText.close()

#itemName = re.findall(r'(?<=item name=\").*(?=\")', str(itemsDump))
itemName = re.findall(r'item name=\"\w*T\d(\w*)', str(itemsDump))
baseEntityDamage = re.findall(r'(?<=passive_effect name=\"EntityDamage\" operation=\"base_set\" value=\")(\d*\.\d|\d*)', str(itemsDump))
baseBlockDamage = re.findall(r'(?<=passive_effect name=\"BlockDamage\" operation=\"base_set\" value=\")(\d*\.\d|\d*)', str(itemsDump))

#for i in range(1, 68):
#    print(f"Item Name: {itemName[i]}")
#    print(f"Base Entity Damage: {baseEntityDamage[i]}")
#    print(f"Base Block Damage: {baseBlockDamage[i]}")


dump = open(cwd + "/dump.txt", "w")
r = 0

# Melee Weapons
dump.write("----MELEE WEAPONS----" + "\n")
for i in range(0, 38):
    if i == 3:
        r = r + 1
    #dump.write("Item Name: " + itemName[r] + "\n")
    if i == 36:
        dump.write("Flashlight" + "\n")
    elif i == 37:
        dump.write("Torch" + "\n")
    else:
        dump.write(itemName[r] + "\n")
    #dump.write("Base Entity Damage: " + baseEntityDamage[i] + "\n")
    dump.write(baseEntityDamage[i] + "\n")
    #dump.write("Base Block Damage: " + baseBlockDamage[i] + "\n")
    dump.write(baseBlockDamage[i] + "\n")
    r = r + 1
# Robotic Sledge
dump.write("----ROBOTIC TURRETS----" + "\n")

#dump.write("Item Name: " + itemName[65] + "\n")
dump.write("RoboticSledge" + "\n")
#dump.write("Base Entity Damage: " + baseEntityDamage[38] + "\n")
dump.write(baseEntityDamage[38] + "\n")
#dump.write("Base Block Damage: " + baseBlockDamage[38] + "\n")
dump.write(baseBlockDamage[38] + "\n")
dump.close()
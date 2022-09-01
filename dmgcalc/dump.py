import sys
import re
import os

sys.stdin.reconfigure(encoding='utf-8')
sys.stdout.reconfigure(encoding='utf-8')

cwd = os.getcwd()

itemsText = open(cwd + "/items.xml", "r")
itemsDump = itemsText.read()
itemsText.close()

itemName = re.findall(r'(?<=item name=\").*(?=\")', str(itemsDump))
baseEntityDamage = re.findall(r'(?<=passive_effect name=\"EntityDamage\" operation=\"base_set\" value=\")(\d*\.\d|\d*)', str(itemsDump))
baseBlockDamage = re.findall(r'(?<=passive_effect name=\"BlockDamage\" operation=\"base_set\" value=\")(\d*\.\d|\d*)', str(itemsDump))

#for i in range(1, 68):
#    print(f"Item Name: {itemName[i]}")
#    print(f"Base Entity Damage: {baseEntityDamage[i]}")
#    print(f"Base Block Damage: {baseBlockDamage[i]}")


dump = open(cwd + "/dump.txt", "w")
r = 0

for i in range(0, 38):
    if i == 3:
        r = r + 1
    dump.write("Item Name: " + itemName[r] + "\n")
    dump.write("Base Entity Damage: " + baseEntityDamage[i] + "\n")
    dump.write("Base Block Damage: " + baseBlockDamage[i] + "\n")
    r = r + 1

dump.write("Item Name: " + itemName[65] + "\n")
dump.write("Base Entity Damage: " + baseEntityDamage[38] + "\n")
dump.write("Base Block Damage: " + baseBlockDamage[38] + "\n")

dump.close()
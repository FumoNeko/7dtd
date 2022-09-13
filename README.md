# Description
This is a simple damage calculator for 7 days to die Alpha 20.6.
Pre-alpha v0.3 has been released which features a Terminal GUI, all melee weapons, Difficulty, Quality, and Perk Levels for both Entity and Block damage.
Work on a Qt-5 GUI Variant will begin after linux release.

# Todo
<li>Armor needs testing.</li>
<li>Body part damage modifiers need testing.</li>
<li>Recog and other buffs need testing.</li>
<li>Bullet types need testing.</li>
<li>Mod Power needs testing.</li>
<li>Linux testing and Binary Release for Pre-alpha v0.3</li>

<li>Data for each weapon needs to be added.</li>

# Current Paradigm:
((base * [1+qualitymod+perkmod]) * [difficultymod])

Each item in paranthesis is decimal dropped.

Item in brackets as decimals are OK.

i.e.

13.8 * [1+0.5+0.5] * [1.5]

<strong>Wrong:</strong>

(13.8 * [2]) = 27.6 

(27.6 * [1.5]) = 41.4

<strong>Correct:</strong>

(13.8 * [2]) = 27.6 --> 27

(27 * [1.5]) = 40.5 --> 40

# Order of Operations as per the XML file

    1. Entity Class
    2. the item in question including installed mods (if an item is passed in)
    3. held item  including installed mods, if not equal to the item in question
    4. worn items  including installed mods
    5. player progression (skills, perks...)
    6. buffs
    7. bonus damage such as for headshots or attacking specific block materials (see below)
    8. game difficulty modifier
    9. armor reduces damage

# Needs to be understood


What kind of worn items affect damage other than mods? 
Does it mean the +1 perception glasses and stuff?

What does it mean if an item is "passed in"?
does held item mean you can shoot something and then switch 
to another weapon to deal different damage on projectile weapons? 
Why would this be different?

What is Entity Class?
Do different zombies just have different damage modifiers
without respect to armor? Or is it just player vs zombie damage?

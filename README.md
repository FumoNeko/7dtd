# Description
This is a simple damage calculator for 7 days to die Alpha 20.6.

# Todo
<li>
Armor needs testing
Body part damage modifiers need testing
Recog and other buffs need testing
Bullet types need testing
Mod Power needs testing

Data for each weapon needs to be added.
</li>

# Current Paradigm:
(base * [1+qualitymod+perkmod]) * (difficultymod)
each item in paranthesis is decimal dropped.
Item in brackets as decimals are OK.

i.e.
13.8 * [1+0.5+0.5] * (1.5)

<strong>Wrong:</strong>

13.8 * (2) = 27.6 
27.6 * 1.5 = 41.4

<strong>Correct:</strong>

13.8 * 2 = 27.6 --> 27
27 * 1.5 = 40.5 --> 40

Needs to be understood:


What kind of worn items affect damage other than mods? 
Does it mean the +1 perception glasses and stuff?

what does it mean if an item is "passed in"?
does held item mean you can shoot something and then switch 
to another weapon to deal different damage on projectile weapons? 
What? Why would this be different?

Have no idea about entity class.
Do different zombies just have different damage modifiers
without respect to armor? Or is it just player vs zombie damage?